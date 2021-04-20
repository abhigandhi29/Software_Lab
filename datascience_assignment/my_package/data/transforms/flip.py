#19CS10031
#Abhishek Gandhi
#Data Science Assignment QS2

#Imports
from PIL import Image
import numpy as np

class FlipImage(object):
    '''
        Flips the image.
    '''

    def __init__(self, flip_type='horizontal'):
        '''
            Arguments:
            flip_type: 'horizontal' or 'vertical' Default: 'horizontal'
        '''
        self.type = flip_type
        

        
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
        if self.type == 'horizontal':
            return image1.transpose(Image.FLIP_LEFT_RIGHT) 
        return image1.transpose(Image.FLIP_TOP_BOTTOM)
       

       