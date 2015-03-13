function runSpcJobFileMc(JOBLIST)

% Add paths
addpath(fullfile('..', 'correlation_algorithms'));
addpath(fullfile('..', 'filtering'));
addpath(fullfile('..', 'jobfiles'));
addpath(fullfile('..', 'phase_unwrapping'));
addpath(fullfile('..', 'phase_unwrapping', 'PhaseUnwrapping2D'));

% Add external libraries:
% 2D weighted least squares
addpath(fullfile('..', 'correlation_algorithms', 'polyfitweighted2'));

% 1D weighted least squares
addpath(fullfile('..', 'correlation_algorithms', 'polyfit3'));

% Count number of jobs
nJobs = length(JOBLIST);

for n = 1 : nJobs

    % Read joblist
    JobFile = JOBLIST(n);

    % Read processing parameters
    phase_unwrapping_algorithm = JobFile.Parameters.Processing.PhaseUnwrappingAlgorithm;
    skipExistingSets = JobFile.JobOptions.SkipExistingSets;
    regionHeight = JobFile.Parameters.RegionHeight;
    regionWidth = JobFile.Parameters.RegionWidth;
    caseName = JobFile.CaseName;
    correlation_type = JobFile.CorrelationType;
    imageType = JobFile.ImageType;
    setType = JobFile.SetType;
    startSet = JobFile.Parameters.Sets.Start;
    endSet = JobFile.Parameters.Sets.End;
    images_per_set = JobFile.Parameters.Sets.ImagesPerSet;

    if JobFile.JobOptions.RepositoryPathIsAbsolute
        Repository = JobFile.Parameters.RepositoryPath;
    else
        % Main code repository
        Repository = fullfile(pwd, '..', '..', '..', '..');
    end

    % Case directory
    caseDir = fullfile(Repository, 'analysis', 'data', imageType,setType, caseName);

    % Image parent directory
    imageParentDirectory = fullfile(caseDir, [num2str(regionHeight) 'x' num2str(regionWidth)], 'raw');

    % Write directory
    writeDir = fullfile(caseDir, [num2str(regionHeight) 'x' num2str(regionWidth)], correlation_type);

    % Make the write directory if it doesn't exist
    if ~exist(writeDir, 'dir')
        mkdir(writeDir)
    end

    % Base names of image sets
    setBase = [setType '_h' num2str(regionHeight) '_w' num2str(regionWidth) '_'];

    % Base names of results files
    saveBase = ['errorAnalysis_' setType '_' correlation_type '_h' num2str(regionHeight) '_w' num2str(regionWidth) '_' lower(phase_unwrapping_algorithm) '_'];

    % Number of digits in the set names
    setDigits = 5;
    % Numbering format tag for image sets
    setFormat = ['%0' num2str(setDigits) '.0f'];

    % Number of digits in image names
    imageDigits = 6;
    imageNumberFormat = ['%0' num2str(imageDigits) '.0f'];

    % List of set numbers
    setList = startSet : endSet;
    nSets = length(setList);

    for k = 1 : nSets             

        % Print message
        fprintf(1, ['Analyzing set ' ...
             correlation_type ' ' caseName ' ' setBase num2str(setList(k), setFormat) ' (' num2str(k)...
             ' of ' num2str(nSets) ')... ']); % Display status

         % Specify directory containing images
        image_dir = fullfile( imageParentDirectory, [ setBase num2str( setList(k), setFormat ) ], 'raw' ); % Image directory

        % Path to the raw image file
        image_file_path = fullfile(image_dir, ['raw_image_matrix_' setType '_h' num2str(regionHeight) '_w' num2str(regionWidth) '_seg_' num2str(1, imageNumberFormat) '_' num2str(images_per_set, imageNumberFormat) '.mat'] );

         % Path to image parameters
        parameters_path = fullfile(imageParentDirectory,...
                [setType '_h' num2str(regionHeight) '_w' num2str(regionWidth) '_' num2str(setList(k), setFormat)], 'parameters', ...
                ['imageParameters_' setType '_h' num2str(regionHeight) '_w' num2str(regionWidth) '_seg_' num2str(1, imageNumberFormat) '_' num2str(images_per_set, imageNumberFormat) '.mat']);                         

         % Specify path to saved file
         save_path = fullfile( writeDir, [ saveBase num2str( setList(k), setFormat ) '.mat' ] ); % Save path

            % Perform analysis on the image set if "skip existing sets" isn't
            % selected or if the set results don't exist.
        if (~skipExistingSets) || (skipExistingSets && ~exist(save_path, 'file'))

            % Read case parameters
            MonteCarloParams.JobFile = JobFile;
            MonteCarloParams.Save_Path = save_path;
            MonteCarloParams.Image_File_Path = image_file_path;
            MonteCarloParams.Image_Parameters_path = parameters_path;

            % Start set timer.
            setTic = tic;

            % Choose among correlation types.
            switch correlation_type
                case 'spc'
                    % % Perform analysis % %
                    MonteCarloParams.PhaseUnwrappingAlgorithm = phase_unwrapping_algorithm;
                    spcErrorAnalysisMonteCarlo(MonteCarloParams);
                case 'rpc'
                    rpcErrorAnalysisMonteCarlo(MonteCarloParams);
            end

            % Display elapsed time.
            setTime = toc(setTic);
            fprintf(1, 'Analyzed %d images in %0.2f sec\n', images_per_set, setTime);
        else
            % Inform user that the k'th set is being skipped.
            disp(['Skipping set ' num2str(setList(k))]); 
        end
    end

end % End if  

end




    
    

