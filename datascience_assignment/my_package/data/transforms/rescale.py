#19CS10031
#Abhishek Gandhi
#Data Science Assignment QS2

#Imports
from PIL import Image
import numpy as np

class RescaleImage(object):
    '''
        Rescales the image to a given size.
    '''

    def __init__(self, output_size):
        '''
            Arguments:
            output_size (tuple or int): Desired output size. If tuple, output is
            matched to output_size. If int, smaller of image edges is matched
            to output_size keeping aspect ratio the same.
        '''
        self.output_size = output_size
        self.factors=[0,0]
 

    def __call__(self, image):
        '''
            Arguments:
            image (numpy array or PIL image)

            Returns:
            image (numpy array or PIL image)

            Note: You do not need to resize the bounding boxes. ONLY RESIZE THE IMAGE.
        '''
        if isinstance(image,np.ndarray):
            image1 = Image.fromarray(image)
        else : 
            image1 = image.copy()
        if isinstance(self.output_size,tuple):
            self.output_size = (int(self.output_size[0]),int(self.output_size[1]))
            self.factors=[image1.size[0]/self.output_size[0],image1.size[1]/self.output_size[1]]
            return image1.resize(self.output_size)
        width, height = image1.size
        size =  None
        if width < height:
            size  =  (int(self.output_size),int(height*self.output_size/width))
        else:
            size = (int(self.output_size*width/height),int(self.output_size))
        self.factors=[image1.size[0]/size[0],image1.size[1]/size[1]]
        return image1.resize(size)
