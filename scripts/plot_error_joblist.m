function plot_error_joblist(JOBLIST)

% Plot font size.
fSize = 14;

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

% Initialize the legend entry array
legend_entries = cell(1, 1);


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
    
    % Weighted fit option
    weightedFitMethod = lower(JobFile.Parameters. ...
        Processing.WeightedSpcPlaneFitMethod);
    
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
        phase_unwrapping_algorithm = lower(JobFile.Parameters.Processing.PhaseUnwrappingAlgorithm);
        filter_list = lower(JobFile.Parameters.Processing.PhaseFilterList);
        
        % Base name of the saved file (SPC)
        saveBase = [...
            'errorAnalysis_' setType ...
            '_' correlation_type ...
            '_h' num2str(regionHeight)...
            '_w' num2str(regionWidth) ...
            '_unwrap_' phase_unwrapping_algorithm...
            '_filt_'];
        
        % Append all the filter names to the filename
        for k = 1 : length(filter_list)
            saveBase = cat(2, saveBase, [filter_list{k} '_']);
        end
        
        % Append the plane weight method
        saveBase = cat(2, saveBase, ['weights_' weightedFitMethod '_']);
        
        % Legend entry for this case
        legend_entries{n} = ['SPC ' phase_unwrapping_algorithm];
        
        % Append the filter names
        for k = 1 : length(filter_list)
            legend_entries{n} = cat(2, legend_entries{n}, [' ' filter_list{k}]);
        end
        
        % Append the weight to the legend name
        legend_entries{n} = cat(2, legend_entries{n}, [', weights: ' weightedFitMethod]);
           
    else
        
        % Base name of the saved file (non-SPC)
        saveBase = [...
            'errorAnalysis_' setType ...
            '_' correlation_type ...
            '_h' num2str(regionHeight) ...
            '_w' num2str(regionWidth) '_'];
        
        legend_entries{n} = upper(correlation_type);
        
    end
  
    % Loop over all the sets
    for k = 1 : nSets             

        % Print message
        fprintf(1, ['Analyzing set ' ...
             correlation_type ' ' caseName ' ' setBase num2str(setList(k), setFormat) ' (' num2str(k)...
             ' of ' num2str(nSets) ')... \n']); % Display status

         % Path to image parameters
        parameters_path = fullfile(imageParentDirectory,...
                [setType '_h' num2str(regionHeight) '_w' num2str(regionWidth) '_' num2str(setList(k), setFormat)], 'parameters', ...
                ['imageParameters_' setType '_h' num2str(regionHeight) '_w' num2str(regionWidth) '_seg_' num2str(1, imageNumberFormat) '_' num2str(images_per_set, imageNumberFormat) '.mat']);                         

         % Specify path to saved file
         results_path = fullfile( writeDir, [ saveBase num2str( setList(k), setFormat ) '.mat' ] ); % Save path
        
         % Load the parameters path
         load(parameters_path);
         
         % Load the results path
         load(results_path);
         
         % Particle diameter standard deviation
         particle_diameter_std_dev = Parameters.ParticleDiameterStd;
         
         % Calculate the error of each component of the disp. estimate
         tx_err = TX_EST - TX_TRUE;
         ty_err = TY_EST - TY_TRUE;
         
         % Calculate the magnitude of the error.
         tx_err_mag = sqrt(tx_err.^2 + ty_err.^2);
         
         % Create a CDF plot of the error magnitude
         p = plot(particle_diameter_std_dev, tx_err_mag, 'o');
         
         set(p, 'markersize', 5);
         
         if n > 7
             set(p, 'linestyle', '--');
         end
         
         % Hold the plot
         hold on;
        
    end

end % End if  

hold off;

L = legend(legend_entries);
set(L, 'FontSize', 10);
set(L, 'location', 'NorthWest');
axis square

% xlim([0, 0.1]);
% ylim([0 1]);

title({'CDF of displacement error for different', ...
    ['processing schemes, ' num2str(regionHeight) 'x' ...
    num2str(regionWidth) ' regions'], ...
    '|T_x| and |T_y| < 5 pix'}, 'FontSize', fSize);
xlabel('Translation error magnitude (pix)', 'FontSize', fSize);
ylabel('Cumulative probability', 'FontSize', fSize);

set(gca, 'fontsize', fSize);

end




    
    

