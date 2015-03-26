function JOBLIST = spcJobList_mc()

DefaultJob.JobOptions.ParallelProcessing = 1;
DefaultJob.JobOptions.NumberOfDigits = 6;
DefaultJob.JobOptions.BooleanGenerateParticleImages = false;
DefaultJob.JobOptions.BooleanRunAnalysis = true;
DefaultJob.JobOptions.FlipYTranslation = false;
DefaultJob.JobOptions.SkipExistingSets = false;
DefaultJob.JobOptions.RepositoryPathIsAbsolute = 1;
DefaultJob.JobOptions.DoAffineTransform = 0;
DefaultJob.JobOptions.ZeroMeanRegions = 0;
DefaultJob.JobOptions.RunCompiled = 1;
DefaultJob.JobOptions.SuppressMessages = 1;

DefaultJob.ImageType = 'synthetic';
DefaultJob.SetType = 'mc';
DefaultJob.CaseName = '2015-03-26_spc_test';
DefaultJob.CorrelationType = 'spc';
DefaultJob.Parameters.RegionHeight = 64;
DefaultJob.Parameters.RegionWidth = 64;
DefaultJob.Parameters.Sets.Start = 1;
DefaultJob.Parameters.Sets.End = 1;
DefaultJob.Parameters.Sets.ImagesPerSet = 10000;

DefaultJob.Parameters.Images.Start = 1;
DefaultJob.Parameters.Images.End = 10000;
DefaultJob.Parameters.Images.Skip = 1;

DefaultJob.Parameters.RepositoryPath =  '~/Desktop/spc_test';
DefaultJob.Parameters.Processing.SpatialWindowFraction = [0.5 0.5];
DefaultJob.Parameters.Processing.SpatialWindowType = 'fraction';
DefaultJob.Parameters.Processing.SpatialRPCDiameter = 2.8;
DefaultJob.Parameters.Processing.PhaseFilterAlgorithm = 'MEAN';
DefaultJob.Parameters.Processing.PhaseUnwrappingAlgorithm = 'GOLDSTEIN';
% DefaultJob.Parameters.Processing.PhaseUnwrappingAlgorithm = 'SVD';

% This is the mean of the additive gaussian white noise
% as a fraction of the maximum image intensity
DefaultJob.Parameters.Processing.Noise.Mean = 0.00;

% This is the 99.5% confidence interval of the noise
% as a fraction of the maximum image intensity.
DefaultJob.Parameters.Processing.Noise.Std = 0.00;

% JOB 1
SegmentItem = DefaultJob;
% SegmentItem.CaseName = '2015-03-20_spc_test_subpixel';
SegmentItem.CorrelationType = 'SCC';
SegmentItem.JobOptions.ZeroMeanRegions = 1;
SegmentItem.Parameters.RegionHeight = 64;
SegmentItem.Parameters.RegionWidth = 64;
SegmentItem.Parameters.Processing.SpatialWindowFraction = 0.50 * [1 1];
JOBLIST(1) = SegmentItem;

% JOB 2
SegmentItem = DefaultJob;
% SegmentItem.CaseName = '2015-03-20_spc_test';
SegmentItem.CorrelationType = 'RPC';
SegmentItem.JobOptions.ZeroMeanRegions = 1;
SegmentItem.Parameters.RegionHeight = 64;
SegmentItem.Parameters.RegionWidth = 64;
SegmentItem.Parameters.Processing.SpatialWindowFraction = 0.50 * [1 1];
JOBLIST(end + 1) = SegmentItem;

% JOB 3
SegmentItem = DefaultJob;
% SegmentItem.CaseName = '2015-03-20_spc_test';
SegmentItem.CorrelationType = 'SPC';
SegmentItem.Parameters.RegionHeight = 64;
SegmentItem.Parameters.RegionWidth = 64;
SegmentItem.Parameters.Processing.SpatialWindowFraction = 0.50 * [1 1];
SegmentItem.Parameters.Processing.PhaseUnwrappingAlgorithm = 'Goldstein';
SegmentItem.Parameters.Processing.PhaseFilterAlgorithm = 'None';
SegmentItem.Parameters.Processing.PhaseFilterList = {'None'};
SegmentItem.Parameters.Processing.KernelSizeList = {[]};
JOBLIST(end + 1) = SegmentItem;

% JOB 4
SegmentItem = DefaultJob;
% SegmentItem.CaseName = '2015-03-20_spc_test';
SegmentItem.CorrelationType = 'SPC';
SegmentItem.Parameters.RegionHeight = 64;
SegmentItem.Parameters.RegionWidth = 64;
SegmentItem.Parameters.Processing.SpatialWindowFraction = 0.50 * [1 1];
SegmentItem.Parameters.Processing.PhaseUnwrappingAlgorithm = 'Goldstein';
SegmentItem.Parameters.Processing.PhaseFilterList = {'Mean'};
SegmentItem.Parameters.Processing.KernelSizeList = {[5, 5]};
JOBLIST(end + 1) = SegmentItem;

% JOB 5
SegmentItem = DefaultJob;
% SegmentItem.CaseName = '2015-03-20_spc_test';
SegmentItem.CorrelationType = 'SPC';
SegmentItem.Parameters.RegionHeight = 64;
SegmentItem.Parameters.RegionWidth = 64;
SegmentItem.Parameters.Processing.SpatialWindowFraction = 0.50 * [1 1];
SegmentItem.Parameters.Processing.PhaseUnwrappingAlgorithm = 'Goldstein';
SegmentItem.Parameters.Processing.PhaseFilterList = {'SVD'};
SegmentItem.Parameters.Processing.KernelSizeList = {[]};
JOBLIST(end + 1) = SegmentItem;


% JOB 6
SegmentItem = DefaultJob;
% SegmentItem.CaseName = '2015-03-20_spc_test';
SegmentItem.CorrelationType = 'SPC';
SegmentItem.Parameters.RegionHeight = 64;
SegmentItem.Parameters.RegionWidth = 64;
SegmentItem.Parameters.Processing.SpatialWindowFraction = 0.50 * [1 1];
SegmentItem.Parameters.Processing.PhaseUnwrappingAlgorithm = 'Goldstein';
SegmentItem.Parameters.Processing.PhaseFilterList = {'mean', 'SVD'};
SegmentItem.Parameters.Processing.KernelSizeList = {[5, 5], []};

JOBLIST(end + 1) = SegmentItem;

% JOB 7
SegmentItem = DefaultJob;
% SegmentItem.CaseName = '2015-03-20_spc_test';
SegmentItem.CorrelationType = 'SPC';
SegmentItem.Parameters.RegionHeight = 64;
SegmentItem.Parameters.RegionWidth = 64;
SegmentItem.Parameters.Processing.SpatialWindowFraction = 0.50 * [1 1];
SegmentItem.Parameters.Processing.PhaseUnwrappingAlgorithm = 'Goldstein';
SegmentItem.Parameters.Processing.PhaseFilterList = {'SVD', 'mean'};
SegmentItem.Parameters.Processing.KernelSizeList = {[], [5, 5]};
JOBLIST(end + 1) = SegmentItem;

% JOB 8
SegmentItem = DefaultJob;
% SegmentItem.CaseName = '2015-03-20_spc_test';
SegmentItem.CorrelationType = 'SPC';
SegmentItem.Parameters.RegionHeight = 64;
SegmentItem.Parameters.RegionWidth = 64;
SegmentItem.Parameters.Processing.SpatialWindowFraction = 0.50 * [1 1];
SegmentItem.Parameters.Processing.PhaseUnwrappingAlgorithm = 'Goldstein';
SegmentItem.Parameters.Processing.PhaseFilterList = {'median'};
SegmentItem.Parameters.Processing.KernelSizeList = {[5, 5]};
JOBLIST(end + 1) = SegmentItem;

% JOB 9
SegmentItem = DefaultJob;
% SegmentItem.CaseName = '2015-03-20_spc_test';
SegmentItem.CorrelationType = 'SPC';
SegmentItem.Parameters.RegionHeight = 64;
SegmentItem.Parameters.RegionWidth = 64;
SegmentItem.Parameters.Processing.SpatialWindowFraction = 0.50 * [1 1];
SegmentItem.Parameters.Processing.PhaseUnwrappingAlgorithm = 'Goldstein';
SegmentItem.Parameters.Processing.PhaseFilterList = {'svd', 'median'};
SegmentItem.Parameters.Processing.KernelSizeList = {[], [5, 5]};
JOBLIST(end + 1) = SegmentItem;

% JOB 10
SegmentItem = DefaultJob;
% SegmentItem.CaseName = '2015-03-20_spc_test';
SegmentItem.CorrelationType = 'SPC';
SegmentItem.Parameters.RegionHeight = 64;
SegmentItem.Parameters.RegionWidth = 64;
SegmentItem.Parameters.Processing.SpatialWindowFraction = 0.50 * [1 1];
SegmentItem.Parameters.Processing.PhaseUnwrappingAlgorithm = 'Goldstein';
SegmentItem.Parameters.Processing.PhaseFilterList = {'median', 'svd'};
SegmentItem.Parameters.Processing.KernelSizeList = {[5, 5], []};
JOBLIST(end + 1) = SegmentItem;


end







