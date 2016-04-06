function JOBLIST = spcJobList_mc()

DefaultJob.JobOptions.ParallelProcessing = 1;
DefaultJob.JobOptions.NumberOfDigits = 6;
DefaultJob.JobOptions.BooleanGenerateParticleImages = false;
DefaultJob.JobOptions.BooleanRunAnalysis = true;
DefaultJob.JobOptions.FlipYTranslation = false;
DefaultJob.JobOptions.SkipExistingSets = false;
DefaultJob.JobOptions.RepositoryPathIsAbsolute = 1;
DefaultJob.JobOptions.DoAffineTransform = 0;
DefaultJob.JobOptions.ZeroMeanRegions = 1;
DefaultJob.JobOptions.RunCompiled = 1;
DefaultJob.JobOptions.SuppressMessages = 1;

DefaultJob.ImageType = 'synthetic';
DefaultJob.SetType = 'lin';
DefaultJob.CaseName = 'piv_test_micro_diffusion';
DefaultJob.CorrelationType = 'spc';
DefaultJob.Parameters.RegionHeight = 128;
DefaultJob.Parameters.RegionWidth = 128;
DefaultJob.Parameters.Sets.Start = 1;
DefaultJob.Parameters.Sets.End = 1;
DefaultJob.Parameters.Sets.ImagesPerSet = 1000;

DefaultJob.Parameters.Images.Start = 1;
DefaultJob.Parameters.Images.End = 1000;
DefaultJob.Parameters.Images.Skip = 1;

DefaultJob.Parameters.RepositoryPath =  '~/Desktop/piv_test_images';
DefaultJob.Parameters.Processing.SpatialWindowFraction = [0.5 0.5];
DefaultJob.Parameters.Processing.SpatialWindowType = 'fraction';
DefaultJob.Parameters.Processing.SpatialRPCDiameter = 2.8;
DefaultJob.Parameters.Processing.PhaseFilterAlgorithm = 'MEAN';
DefaultJob.Parameters.Processing.PhaseUnwrappingAlgorithm = 'GOLDSTEIN';
DefaultJob.Parameters.Processing.WeightedSpcPlaneFitMethod = 'rpc';
DefaultJob.Parameters.Processing.PeakFitMethod = '3_point';
DefaultJob.Parameters.Processing.FilterCutoff = 15;
DefaultJob.Parameters.Processing.EnsembleLength = 10;

DefaultJob.Parameters.Processing.APC.KernelRadius   = 5;

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
SegmentItem.Parameters.Processing.SpatialWindowFraction = 0.5 * [1 1];
SegmentItem.Parameters.Processing.PhaseUnwrappingAlgorithm = 'Goldstein';
JOBLIST(1) = SegmentItem;

% JOB 1
SegmentItem = DefaultJob;
SegmentItem.CorrelationType = 'rpc';
SegmentItem.JobOptions.ZeroMeanRegions = 1;
SegmentItem.Parameters.Processing.SpatialWindowFraction = 0.5 * [1 1];
JOBLIST(end + 1) = SegmentItem;

% JOB 2
SegmentItem = DefaultJob;
SegmentItem.CorrelationType = 'scc';
SegmentItem.Parameters.Processing.SpatialWindowFraction = 0.5 * [1 1];
JOBLIST(end + 1) = SegmentItem;




end







