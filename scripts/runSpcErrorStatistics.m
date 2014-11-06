function runSpcErrorStatistics(JOBLIST)

% Add paths
addpath(fullfile('..', 'correlation_algorithms'));
addpath(fullfile('..', 'filtering'));
addpath(fullfile('..', 'jobfiles'));
addpath(fullfile(',,', 'phase_unwrapping'));

% Font size
fSize = 16;

% Count number of jobs
nJobs = length(JOBLIST);

for n = 1 : nJobs

    % Read joblist
    JobFile = JOBLIST(n);

    regionHeight = JobFile.Parameters.RegionHeight;
    regionWidth = JobFile.Parameters.RegionWidth;
    caseName = JobFile.CaseName;
    correlationType = JobFile.CorrelationType;
    imageType = JobFile.ImageType;
    setType = JobFile.SetType;
    startSet = JobFile.Parameters.Sets.Start;
    endSet = JobFile.Parameters.Sets.End;
    imagesPerSet = JobFile.Parameters.Sets.ImagesPerSet;
    phase_unwrapping_algorithm = JobFile.Parameters.Processing.PhaseUnwrappingAlgorithm;

    if JobFile.JobOptions.RepositoryPathIsAbsolute
        Repository = JobFile.Parameters.RepositoryPath;
    else
        % Main code repository
        Repository = fullfile(pwd, '..', '..', '..');
    end

    % Case directory
    caseDir = fullfile(Repository, 'analysis', 'data', imageType, setType, caseName);

    % Image parent directory
    imageParentDirectory = fullfile(caseDir, [num2str(regionHeight) 'x' num2str(regionWidth)], 'raw');

    % Write directory
    dataDir = fullfile(caseDir, [num2str(regionHeight) 'x' num2str(regionWidth)], correlationType);

    % Base names of results files
    dataBase = ['errorAnalysis_' setType '_' correlationType '_h' num2str(regionHeight) '_w' num2str(regionWidth) '_' phase_unwrapping_algorithm '_'];

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
    
    % Initialize error vectors (SPC)
    translation_error_y_spc = zeros(imagesPerSet * nSets, 1);
    translation_error_x_spc = zeros(imagesPerSet * nSets, 1);
    
     % Initialize error vectors (RPC)
    translation_error_y_rpc = zeros(imagesPerSet * nSets, 1);
    translation_error_x_rpc = zeros(imagesPerSet * nSets, 1);
    
    % Loop over all the sets
    for k = 1 : nSets             

        % Indices of the k'th set errors within the larger jobfile error
        % vectors
        set_inds = (k-1) * imagesPerSet + 1 : k * imagesPerSet;
        
        % Path to image parameters
        parameters_path = fullfile(imageParentDirectory,...
        [setType '_h' num2str(regionHeight) '_w' num2str(regionWidth) '_' num2str(setList(k), setFormat)], 'parameters', ...
        ['imageParameters_' setType '_h' num2str(regionHeight) '_w' num2str(regionWidth) '_seg_' num2str(1, imageNumberFormat) '_' num2str(imagesPerSet, imageNumberFormat) '.mat']);                         

        % Load the parameters
        load(parameters_path);
        
        % Specify path to saved file
        data_path = fullfile( dataDir, [ dataBase num2str( setList(k), setFormat ) '.mat' ] ); % Save path
        
        % Load the results file
        load(data_path);
        
        % Calculate translation errors (SPC)
        translation_error_y_spc(set_inds) = TY_SPC - Parameters.TranslationY;
        translation_error_x_spc(set_inds) = TX_SPC - Parameters.TranslationX;
        
        % Calculate translation errors (RPC)
        translation_error_y_rpc(set_inds) = TY_RPC - Parameters.TranslationY;
        translation_error_x_rpc(set_inds) = TX_RPC - Parameters.TranslationX;
    end
    
    % Magnitudes of translation errors
    translation_error_magnitude_spc = sqrt(translation_error_y_spc.^2 + translation_error_x_spc.^2);
    translation_error_magnitude_rpc = sqrt(translation_error_y_rpc.^2 + translation_error_x_rpc.^2);
    
    % Magnitudes of shearing
    shearing_magnitude = sqrt(Parameters.ShearX.^2 + Parameters.ShearY.^2);
    
    % Make cdf plots of the error magnitudes (SPC)
    cdfplot(translation_error_magnitude_spc);
    
    hold on;
    
    % Make cdf plots of the error magnitudes (RPC)
    cdfplot(translation_error_magnitude_rpc);
    
    hold off;
    
    % Format the plots
    h = get(gca, 'children');
    
    % Format the CDF plot line (SPC)
    set(h(2), 'LineStyle', '-');
    set(h(2), 'Color', 'k');
    
    % Format the CDF plot line (RPC)
    set(h(1), 'LineStyle', '--');
    set(h(1), 'Color', 'k');
    
    % Add plot legend
    f = legend('SPC', 'RPC');
    set(f, 'FontSize', fSize);

    % Axis aspect ratio
    axis square
    
    % Axis limits
    ylim([0 1.01]);
    xlim([0 1]);
    
    % Axis labels
    ylabel('Cumulative probability', 'FontSize', fSize);
    xlabel('Translation error magnitude', 'FontSize', fSize);
    
    % Plot title
    title({'CDF of Translation Error Magnitude', ['Max shear: ' num2str(abs(max(max(Parameters.ShearYRange, Parameters.ShearXRange))), '%0.3f') ' ppp']});
    
    % Axis font size
    set(gca, 'FontSize', fSize);
    
    % Save the figure
    print(1, '-depsc', fullfile('~/Desktop', [dataBase '_' num2str(n, '%03.0f')]));
    
    % Save data
    save(fullfile('~/Desktop', [dataBase '_' num2str(n, '%03.0f') '.mat']), 'translation_error_magnitude_spc', 'translation_error_magnitude_rpc');
    
    
end   

end




    
    

