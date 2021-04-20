#19CS10031
#Abhishek Gandhi
#Data Science Assignment QS2

#Imports
import random
import numpy as np
from PIL import Image


class CropImage(object):
    '''
        Performs either random cropping or center cropping.
    '''

    def __init__(self, shape, crop_type='center'):
        '''
            Arguments:
            shape: output shape of the crop (h, w)
            crop_type: center crop or random crop. Default: center
        '''
        self.crop_type=crop_type
        self.shape=shape
        self.subtract = [0,0]

    def __call__(self, image):
        
        '''
            Arguments:
            image (numpy array or PIL image)

            Returns:
            image (numpy array or PIL image)
        '''

        if isinstance(image,np.ndarray):
            image1 = Image.fromarray(image)
        else : 
            image1 = image.copy()
        width,height = image1.size
        shape = None
        if self.crop_type=='center':
            self.subtract = [width/2-self.shape[1]/2,height/2-self.shape[0]/2]
            shape=((width-self.shape[1])/2,(height-self.shape[0])/2,(width+self.shape[1])/2,(height+self.shape[0])/2)
        else:
            width = (width-self.shape[1])/2 +random.random()%(self.shape[1])
            height = (height-self.shape[0])/2 + random.random()%(self.shape[0])
            self.subtract = [width/2-self.shape[1]/2,height/2-self.shape[0]/2]
            shape=((width-self.shape[1])/2,(height-self.shape[0])/2,(width+self.shape[1])/2,(height+self.shape[0])/2)
        return image1.crop(shape)

        

 