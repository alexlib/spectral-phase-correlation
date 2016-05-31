import scipy.io as sio
import numpy as np
import os.path
import pdb


# File directory
data_repo = '/Volumes/aether_b/Projects/APC/analysis/data/synthetic/mc'

# Case names
case_name = 'piv_test_running_ensemble_q_50.0_ul_min';

# Data directory
data_dir = os.path.join(data_repo, case_name, '128x128', 'apc');

# Data base name
# data_base_name = 