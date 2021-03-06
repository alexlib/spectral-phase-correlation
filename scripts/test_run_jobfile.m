function test_run_jobfile(JOBLIST)

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
    
    % Read processing parameters common to all correlation types.
    skipExistingSets = JobFile.JobOptions.SkipExistingSets;
    regionHeight = JobFile.Parameters.RegionHeight;
    regionWidth = JobFile.Parameters.RegionWidth;
    caseName = JobFile.CaseName;
    imageType = JobFile.ImageType;
    setType = JobFile.SetType;
    startSet = JobFile.Parameters.Sets.Start;
    endSet = JobFile.Parameters.Sets.End;
    images_per_set = JobFile.Parameters.Sets.ImagesPerSet;
    
    % Correlation method
    % Valid methods: scc, rpc, gcc, spc, fmc
    correlation_type = lower(JobFile.CorrelationType);
    
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
    
    % Construct the path to the repository
    if JobFile.JobOptions.RepositoryPathIsAbsolute
        Repository = JobFile.Parameters.RepositoryPath;
    else
        % Main code repository
        Repository = fullfile(pwd, '..', '..', '..', '..');
    end

    % Case directory
    caseDir = fullfile(Repository, 'analysis', 'data', imageType,setType, caseName);

    % Base names of image sets
    setBase = [setType '_h' num2str(regionHeight) '_w' num2str(regionWidth) '_'];
    
    % Image parent directory
    imageParentDirectory = fullfile(caseDir, [num2str(regionHeight) 'x' num2str(regionWidth)], 'raw');

    % Write directory
    writeDir = fullfile(caseDir, [num2str(regionHeight) 'x' num2str(regionWidth)], correlation_type);

    % Make the write directory if it doesn't exist
    if ~exist(writeDir, 'dir')
        mkdir(writeDir)
    end

    % Flag specifying whether the job is SCC
    isScc = ~isempty(regexpi(correlation_type, 'scc'));
    
    % Flag specifying whether the job is RPC
    isRpc = ~isempty(regexpi(correlation_type, 'rpc'));
    
    % Flag specifying whether the job is GCC
    isGcc = ~isempty(regexpi(correlation_type, 'gcc'));
    
    % Flag specifying whether the job is SPC
    isSpc = ~isempty(regexpi(correlation_type, 'spc'));
    
    % Flag specifying whether the job is FMC
    isFmc = ~isempty(regexpi(correlation_type, 'fmc'));
    
    % Base names of results files
    if isSpc
        
        % Processing parameters specific to SPC
        phase_unwrapping_algorithm = JobFile.Parameters.Processing.PhaseUnwrappingAlgorithm;
        phase_filter_list = JobFile.Parameters.Processing.PhaseFilterList;
        spc_plane_fit_weight_type = JobFile.Parameters.Processing.WeightedSpcPlaneFitMethod;
        
        % Base name of the saved file (SPC)
        saveBase = [...
            'errorAnalysis_' setType ...
            '_' correlation_type ...
            '_h' num2str(regionHeight)...
            '_w' num2str(regionWidth) ...
            '_unwrap_' lower(phase_unwrapping_algorithm)...
            '_filt_'];
        
        % Append the list of phase filters to the save name
        if isempty(phase_filter_list)
            saveBase = strcat(saveBase, 'none_');
        else
            for k = 1 : length(phase_filter_list)
               saveBase = strcat(saveBase, [lower(phase_filter_list{k}) '_']); 
            end            
        end
        
        % Append weighted plane weights
        if isempty(spc_plane_fit_weight_type)
            saveBase = strcat(saveBase, 'weights_none_');
        else
            saveBase = strcat(saveBase, ['weights_', lower(spc_plane_fit_weight_type) '_']);
        end
        
    else
        
        % Base name of the saved file (non-SPC)
        saveBase = [...
            'errorAnalysis_' setType ...
            '_' correlation_type ...
            '_h' num2str(regionHeight) ...
            '_w' num2str(regionWidth) '_'];
    end
    
    % Extract parameters specific to RPC
    if isRpc
        
    end
    

    % Loop over all the sets
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
            switch lower(correlation_type)
                case 'spc'
                    % % Perform analysis % %
                    MonteCarloParams.PhaseUnwrappingAlgorithm = phase_unwrapping_algorithm;
                    spcErrorAnalysisMonteCarlo(MonteCarloParams);
                case 'rpc'
                    rpcErrorAnalysisMonteCarlo(MonteCarloParams);
                case 'scc'
                    sccErrorAnalysisMonteCarlo(MonteCarloParams);
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




    
    

