function JOBLIST = spcJobList_mc()

DefaultJob.JobOptions.ParallelProcessing = false;
DefaultJob.JobOptions.NumberOfDigits = 6;
DefaultJob.JobOptions.BooleanGenerateParticleImages = false;
DefaultJob.JobOptions.BooleanRunAnalysis = true;
DefaultJob.JobOptions.FlipYTranslation = false;
DefaultJob.JobOptions.SkipExistingSets = false;
DefaultJob.JobOptions.RepositoryPathIsAbsolute = true;
DefaultJob.JobOptions.DoAffineTransform = 0;
DefaultJob.JobOptions.ZeroMeanRegions = true;
DefaultJob.JobOptions.RunCompiled = true;
DefaultJob.JobOptions.SuppressMessages = false;
DefaultJob.JobOptions.MakePlots = false;

% Output file base name
DefaultJob.Filepaths.Output.BaseName = 'piv_test_';

DefaultJob.ImageType = 'synthetic';
DefaultJob.SetType = 'mc';
DefaultJob.CaseName = 'piv_test_running_ensmeble_q_0.50_ul_min';
DefaultJob.CorrelationType = 'spc';
DefaultJob.Parameters.RegionHeight = 64;
DefaultJob.Parameters.RegionWidth = 64;
DefaultJob.Parameters.Sets.Start = 1;
DefaultJob.Parameters.Sets.End = 1;
DefaultJob.Parameters.Sets.ImagesPerSet = 100;

DefaultJob.Parameters.Images.Start = 1;
DefaultJob.Parameters.Images.End = 1;
DefaultJob.Parameters.Images.Skip = 1;

DefaultJob.Parameters.RepositoryPath =  '~/Desktop/piv_test_images';
DefaultJob.Parameters.Processing.SpatialWindowFraction = [0.4 0.4];
DefaultJob.Parameters.Processing.SpatialWindowType = 'fraction';
DefaultJob.Parameters.Processing.SpatialRPCDiameter = 2.8;
DefaultJob.Parameters.Processing.PhaseFilterAlgorithm = 'MEAN';
DefaultJob.Parameters.Processing.PhaseUnwrappingAlgorithm = 'GOLDSTEIN';
DefaultJob.Parameters.Processing.WeightedSpcPlaneFitMethod = 'rpc';
DefaultJob.Parameters.Processing.PeakFitMethod = '3_point';
DefaultJob.Parameters.Processing.FilterCutoff = 15;
DefaultJob.Parameters.Processing.Ensemble.Length = 1;
DefaultJob.Parameters.Processing.Ensemble.Method = 'Complex';

DefaultJob.Parameters.Processing.APC.KernelRadius = 5;

% DefaultJob.Parameters.Processing.PhaseUnwrappingAlgorithm = 'SVD';

% This is the mean of the additive gaussian white noise
% as a fraction of the maximum image intensity
DefaultJob.Parameters.Processing.Noise.Mean = 0.00;

% This is the 99.5% confidence interval of the noise
% as a fraction of the maximum image intensity.
DefaultJob.Parameters.Processing.Noise.Std = 0.00;

% JOB 3
SegmentItem = DefaultJob;
SegmentItem.CorrelationType = 'apc';
SegmentItem.Parameters.Processing.SpatialWindowFraction = 0.4 * [1 1];
SegmentItem.Parameters.Processing.PhaseUnwrappingAlgorithm = 'Goldstein';
JOBLIST(1) = SegmentItem;


% 
% % JOB 1
% SegmentItem = DefaultJob;
% SegmentItem.CorrelationType = 'rpc';
% SegmentItem.JobOptions.ZeroMeanRegions = 1;
% SegmentItem.Parameters.Processing.SpatialWindowFraction = 0.5 * [1 1];
% JOBLIST(end + 1) = SegmentItem;
% 
% % JOB 2
% SegmentItem = DefaultJob;
% SegmentItem.CorrelationType = 'scc';
% SegmentItem.Parameters.Processing.SpatialWindowFraction = 0.5 * [1 1];
% JOBLIST(end + 1) = SegmentItem;




end







