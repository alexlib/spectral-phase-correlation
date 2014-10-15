function JOBLIST = spc_jobfile()

% Region dimensions
regionHeight = 64;
regionWidth = 64;

DefaultJob.JobOptions.NumberOfProcessors = 2;
DefaultJob.JobOptions.NumberOfDigits = 6;
DefaultJob.JobOptions.RotationRangeType = 'lin';
DefaultJob.JobOptions.RotationAngleUnits = 'rad';


DefaultJob.ImageType = 'synthetic';
DefaultJob.SetType = 'mc';
% DefaultJob.SetType = 'lin';
DefaultJob.CaseName = '2014-10-05_translation_only';
DefaultJob.ProjectRepository = '~/Documents/School/VT/Research/Aether/SPC';

DefaultJob.Parameters.RegionHeight = regionHeight;
DefaultJob.Parameters.RegionWidth = regionWidth;
DefaultJob.Parameters.Sets.Start = 1;
DefaultJob.Parameters.Sets.End = 1;
DefaultJob.Parameters.Sets.ImagesPerSet = 50;

% Case 1
SegmentItem = DefaultJob;
SegmentItem.SetType = 'lin';
SegmentItem.CaseName = '2014-10-05_translation_only_06';
SegmentItem.Parameters.RegionHeight = 64;
SegmentItem.Parameters.RegionWidth = 64;
JOBLIST(1) = SegmentItem;



end








