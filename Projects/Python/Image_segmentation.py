import os
import sys
import random
import math
import numpy as np
import skimage.io
import matplotlib
import matplotlib.pyplot as plt

# Fetching the root directory
ROOT_DIR = os.path.abspath("../")

import warnings
warnings.filterwarnings("ignore")

# Importing Mask RCNN 
sys.path.append(ROOT_DIR)  # To find local version of the library
from mrcnn import utils
import mrcnn.model as modellib
from mrcnn import visualize

# Heading to the coco directory
sys.path.append(os.path.join(ROOT_DIR, "samples/coco/"))  
#importing coco.py
import coco
%matplotlib inline
# Directory to save logs and trained model
MODEL_DIR = os.path.join(ROOT_DIR, "logs")

# Local path to trained weights file
COCO_MODEL_PATH = os.path.join('', "mask_rcnn_coco.h5")

# Directory of images to run detection on
DIR_IMAGE = os.path.join(ROOT_DIR, "images")
class InferenceConfig(coco.CocoConfig):
    # Setting batch size equal to 1 since we'll be running inference on
    # one image at a time. Batch size = GPU_COUNT * IMAGES_PER_GPU
    GPU_COUNT = 1
    IMAGES_PER_GPU = 1

config = InferenceConfig()
config.display()
# Create model objects in inference mode.
model = modellib.MaskRCNN(mode="inference", model_dir='mask_rcnn_coco.hy', config=config)

# Load weights trained on MS-COCO
model.load_weights('mask_rcnn_coco.h5', by_name=True)
image = skimage.io.imread('../images/4410436637_7b0ca36ee7_z.jpg')

# original image
plt.figure(figsize=(12,10))

skimage.io.imshow(image)
# Run detection
results = model.detect([image], verbose=1)
# Visualize results
r = results[0]
visualize.display_instances(image, r['rois'], r['masks'], r['class_ids'], 
mask = r['masks']
mask = mask.astype(int)
mask.shape
                            
