function JobList = runjobs(job_num);

% Get repository path
repo_path = getpath('spectral-phase-correlation');

% Add paths
addpath(fullfile(repo_path, 'correlation_algorithms'));
addpath(fullfile(repo_path, 'phase_unwrapping'));
addpath(fullfile(repo_path, 'filtering'));
addpath(fullfile(repo_path, 'jobfiles'));
addpath(fullfile(repo_path, 'scripts'));


% Load the job list
JobList = spcJobList_mc;

if nargin < 1
    runMonteCarloCorrelationJobFile(JobList);
else
    runMonteCarloCorrelationJobFile(JobList(job_num));
end
    
% if nargin < 1
%     runSpcJobFileMc(JobList);
% else
%     runSpcJobFileMc(JobList(job_num));
% end


end