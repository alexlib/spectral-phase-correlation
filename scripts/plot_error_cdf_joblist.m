function plot_error_cdf_joblist(JOBLIST)

% Plot font size.
fSize = 14;

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
    if isSpc % Processing parameters specific to SPC
        
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
        
        % Legend entry for this case
        legend_entries{n} = ['SPC ' phase_unwrapping_algorithm];
        
        % Append the filter names
        for k = 1 : length(phase_filter_list)
            legend_entries{n} = cat(2, legend_entries{n}, [' ' phase_filter_list{k}]);
        end
        
        % Append the weight to the legend name
        legend_entries{n} = cat(2, legend_entries{n}, [', weights: ' spc_plane_fit_weight_type]);
           
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
        
         % Read the true Z translation
         TZ_TRUE = Parameters.Translation.Z;
         
         % Calculate the error of each component of the disp. estimate
         tx_err = TX_EST - TX_TRUE;
         ty_err = TY_EST - TY_TRUE;
         
         plot_save_name_tx = strcat(saveBase, 'tx_error');
         plot_save_name_ty = strcat(saveBase, 'ty_error');
         
         figure(2);
         plot(TX_TRUE, tx_err, '.k');
         ylim(0.05 * [-1, 1]);
         xlim(10 * [-1, 1]);
         grid on;
         axis square;
         xlabel('True X displacement (pixels)', 'FontSize', fSize);
         ylabel('Displacement error (pixels)', 'FontSize', fSize);
         title({'Horizontal (x) displacement error', legend_entries{n}}, 'FontSize', fSize);
         set(gca, 'FontSize', fSize);
         set(gcf, 'color', 'white');
         print(2, '-dpng', fullfile('~/Desktop/plots', ...
             [plot_save_name_tx '.png']));
         
         figure(3);
         plot(TY_TRUE, ty_err, '.k');
         ylim(0.05 * [-1, 1]);
         xlim(10 * [-1, 1]);
         grid on;
         axis square;
         xlabel('True Y displacement (pixels)', 'FontSize', fSize);
         ylabel('Displacement error (pixels)', 'FontSize', fSize);
         title({'Vertical (y) displacement error', legend_entries{n}}, 'FontSize', fSize);
         set(gca, 'FontSize', fSize);
         set(gcf, 'color', 'white');
         print(3, '-dpng', fullfile('~/Desktop/plots', ...
             [plot_save_name_ty '.png']));
        
         % Calculate the magnitude of the error.
         tx_err_mag = sqrt(tx_err.^2 + ty_err.^2);
         
         % Create a CDF plot of the error magnitude
         figure(1);
         p = cdfplot(tx_err_mag);
         set(p, 'linewidth', 2);
         
         % Make lines dashed if there are more than seven
         % of them.
         if n > 7
             set(p, 'linestyle', '--');
         end
         
         % Hold the plot
         hold on;
        
    end

end % End if  Job

% Release the plot hold.
hold off;

% Legend
L = legend(legend_entries);
set(L, 'FontSize', 10);
set(L, 'location', 'SouthEast');
axis square

% Plot limits
xlim([0, 0.1]);
ylim([0, 1.0]);

tx_mag_max = max(abs(TX_TRUE));
ty_mag_max = max(abs(TY_TRUE));
tz_mag_max = max(abs(TZ_TRUE));

% Label plot
title({'CDF of displacement error for different', ...
    ['processing schemes, ' num2str(regionHeight) 'x' ...
    num2str(regionWidth) ' regions'], ...
    ['|T_x| < ' num2str(tx_mag_max, '%0.0f') ' pix, ' ...
    '|T_y| < ' num2str(ty_mag_max, '%0.0f') ' pix, ' ...
    '|T_z| < ' num2str(tz_mag_max, '%0.0f') ' pix']}, 'FontSize', ...
    fSize, 'interpreter', 'tex');
xlabel('Translation error magnitude (pix)', 'FontSize', fSize);
ylabel('Cumulative probability', 'FontSize', fSize);

% Set plot axes font size.
set(gca, 'fontsize', fSize);

end




    
    

