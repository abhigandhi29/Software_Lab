#19CS10031
#Abhishek Gandhi
#Data Science Assignment QS2

#Imports
from PIL import Image
import numpy as np

class RotateImage(object):
    '''
        Rotates the image about the centre of the image.
    '''

    def __init__(self, degrees):
        '''
            Arguments:
            degrees: rotation degree.
        '''
        self.degree = degrees
        

    def __call__(self, sample):
        
        '''
            Arguments:
            image (numpy array or PIL image)


            Returns:
            image (numpy array or PIL image)
        '''

        if isinstance(sample,np.ndarray):
            image1 = Image.fromarray(sample)
        else : 
            image1 = sample.copy()
        return image1.rotate(self.degree)