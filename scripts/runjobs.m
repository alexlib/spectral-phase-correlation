function JobList = runjobs(job_num);

% Load the job list
JobList = spcJobList_mc;

% if nargin < 1
%     runMonteCarloCorrelationJobFile(JobList);
% else
%     runMonteCarloCorrelationJobFile(JobList(job_num));
% end
    
if nargin < 1
    runSpcJobFileMc(JobList);
else
    runSpcJobFileMc(JobList(job_num));
end


end