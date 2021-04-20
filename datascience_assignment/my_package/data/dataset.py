#19CS10031
#Abhishek Gandhi
#Data Science Assignment QS2

#Imports
from PIL import Image, ImageFilter  
import numpy as np
from .transforms import BlurImage,RescaleImage,RotateImage,FlipImage,CropImage
import json


class Dataset(object):
    '''
        A class for the dataset that will return data items as per the given index
    '''

    def __init__(self, annotation_file, transforms = None):
        '''
            Arguments:
            annotation_file: path to the annotation file
            transforms: list of transforms (class instances)
                        For instance, [<class 'RandomCrop'>, <class 'Rotate'>]
        '''
        self.file = annotation_file
        self.transforms = transforms
        self.jsonl_file = []
        with open(self.file, 'r') as annotationFile:
            datasetJson = list(annotationFile)
        #reading jsonl file
        for jsonl_file in datasetJson:
            self.jsonl_file.append(json.loads(jsonl_file))
        

    def __len__(self):
        '''
            return the number of data points in the dataset
        '''
        #returns length of dataset = length of list containing entire dataset
        return len(self.jsonl_file)

        

    def __getitem__(self, idx):
        '''
            return the dataset element for the index: "idx"
            Arguments:
                idx: index of the data element.

            Returns: A dictionary with:
                image: image (in the form of a numpy array) (shape: (3, H, W))
                gt_bboxes: N X 5 array where N is the number of bounding boxes, each 
                            consisting of [class, x1, y1, x2, y2]
                            x1 and x2 lie between 0 and width of the image,
                            y1 and y2 lie between 0 and height of the image.

            You need to do the following, 
            1. Extract the correct annotation using the idx provided.
            2. Read the image and convert it into a numpy array (wont be necessary
                with some libraries). The shape of the array would be (3, H, W).
            3. Scale the values in the array to be with [0, 1].
            4. Create a dictonary with both the image and annotations
            4. Perform the desired transformations.
            5. Return the transformed image and annotations as specified.
        '''
        dataset = dict()
        image = Image.open(self.file[:self.file.find('annotations.jsonl')]+self.jsonl_file[idx]["img_fn"])
        
        #print(image.shape)
        boxes = self.jsonl_file[idx]["bboxes"]
        gt_bbooxes = []
        for i in boxes:
            gt_bbooxes.append([i["category_id"],i['bbox'][0],i['bbox'][1],i['bbox'][2],i['bbox'][3]])
        #dataset[image] = gt_bbooxes

        if self.transforms !=None:
            for i in self.transforms:
                image = i(image)
                width, height = image.size
                #changing coordinates after applying tranformation
                if isinstance(i,BlurImage):
                    continue
                if isinstance(i,RescaleImage):
                    for j in range(len(gt_bbooxes)):
                        gt_bbooxes[j]=[gt_bbooxes[j][0],int(gt_bbooxes[j][1]/i.factors[0]),int(gt_bbooxes[j][2]/i.factors[1]),int(gt_bbooxes[j][3]/i.factors[0]),int(gt_bbooxes[j][4]/i.factors[1])]

                if isinstance(i,FlipImage):
                    for j in range(len(gt_bbooxes)):
                        if i.type == 'horizontal':
                            gt_bbooxes[j]=[gt_bbooxes[j][0],width-gt_bbooxes[j][3],gt_bbooxes[j][2],width-gt_bbooxes[j][1],gt_bbooxes[j][4]]
                        else:
                            gt_bbooxes[j]=[gt_bbooxes[j][0],gt_bbooxes[j][1],height-gt_bbooxes[j][4],gt_bbooxes[j][3],height-gt_bbooxes[j][2]]

                if isinstance(i,RotateImage):
                    for j in range(len(gt_bbooxes)):
                        gt_bbooxes[j]=[gt_bbooxes[j][0],\
                            int(width/2-(width/2-gt_bbooxes[j][1])*np.cos(i.degree*np.pi/180)-(height/2-gt_bbooxes[j][2])*np.sin(i.degree*np.pi/180)),\
                            int(height/2-(height/2-gt_bbooxes[j][2])*np.cos(i.degree*np.pi/180)-(width/2-gt_bbooxes[j][3])*np.sin(i.degree*np.pi/180)),\
                            int(width/2-(width/2-gt_bbooxes[j][3])*np.cos(i.degree*np.pi/180)-(height/2-gt_bbooxes[j][4])*np.sin(i.degree*np.pi/180)),\
                            int(height/2-(height/2-gt_bbooxes[j][4])*np.cos(i.degree*np.pi/180)-(width/2-gt_bbooxes[j][1])*np.sin(i.degree*np.pi/180))]

                if isinstance(i,CropImage):
                    for j in range(len(gt_bbooxes)):
                        gt_bbooxes[j]=[gt_bbooxes[j][0],gt_bbooxes[j][1]-i.subtract[0],gt_bbooxes[j][2]-i.subtract[1],gt_bbooxes[j][3]-i.subtract[0],gt_bbooxes[j][4]-i.subtract[1]]
        #converting imagein required numpy array form
        image = np.asarray(image)
        image = image.transpose((2,0,1))
        image = image/255
        #print(image.shape)
        dataset["image"] = image
        dataset["gt_bboxes"]=gt_bbooxes
        return dataset




        