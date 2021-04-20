#19CS10031
#Abhishek Gandhi
#Data Science Assignment QS2

#Imports
from my_package.model import ObjectDetectionModel
from my_package.data import Dataset
from my_package.analysis import plot_boxes
from my_package.data import FlipImage, RescaleImage, BlurImage, CropImage, RotateImage
from matplotlib import pyplot as plt
import numpy as np
import inflect
import json

def experiment(annotation_file, detector, transforms, outputs, RollNumberLastDigit = 1):
    '''
        Function to perform the desired experiments

        Arguments:
        annotation_file: Path to annotation file
        detector: The object detector
        transforms: List of transformation classes
        outputs: path of the output folder to store the images
    '''

    #Create the instance of the dataset.
    dataset = Dataset(annotation_file=annotation_file, transforms=None)
    p = inflect.engine()
    predictions = []
    analysis_result = []
    #Iterate over all data items.
    print("starting predictions:")
    for i in range(len(dataset)):
        pred = dict()
        image_dict = dataset[i]
        #Get the predictions from the detector.
        pred_boxes, pred_class, pred_score = detector(image_dict["image"])
        
        # Draw the boxes on the image and save them.
        box = []
        for j in range(min(len(pred_class),5)):
            box.append(str([pred_class[j],pred_boxes[j]]))
        print("Saving",p.ordinal(i),"prediction")
        pred["image"] = 'output'+str(i)
        pred["boxes"] = box
        predictions.append(pred)
        plot_boxes(image_dict["image"], pred_boxes, pred_class, pred_score, outputs+"allfiles/output"+str(i)+'.jpg')
    #saving results in a json file
    with open(outputs+'allfiles/predictions.json', 'w') as f:
        json.dump(predictions, f)

    print("Starting analysis for",p.ordinal(RollNumberLastDigit),"image")
    # Do the required analysis experiments.

    #normal analysis
    imageDict = dataset[RollNumberLastDigit]
    pred_boxes, pred_class, pred_score = detector(imageDict["image"])
    img = plot_boxes(imageDict["image"], pred_boxes, pred_class, pred_score, outputs+"picanalysis/normaloutput{}.jpg".format(RollNumberLastDigit))
    plt.subplot(3, 3, 1)
    plt.imshow(img)
    pred = dict()
    box = []
    for j in range(min(len(pred_class),5)):
        box.append(str([pred_class[j],pred_boxes[j]]))
    pred['image']="normaloutput{}.jpg".format(RollNumberLastDigit)
    pred['boxes']=box
    analysis_result.append(pred)
    print("Normal analysis completed")

    #flipped analysis
    flipDataset = Dataset(annotation_file=annotation_file,transforms=[transforms[0]()])
    flipDict = flipDataset[RollNumberLastDigit]
    pred_boxes, pred_class, pred_score = detector(flipDict["image"])
    flipimg = plot_boxes(flipDict["image"], pred_boxes, pred_class, pred_score, outputs+"picanalysis/flipoutput{}.jpg".format(RollNumberLastDigit))
    plt.subplot(3, 3, 2)
    plt.imshow(flipimg)
    pred = dict()
    box = []
    for j in range(min(len(pred_class),5)):
        box.append(str([pred_class[j],pred_boxes[j]]))
    pred['image']="flipoutput{}.jpg".format(RollNumberLastDigit)
    pred['boxes']=box
    analysis_result.append(pred)
    print("Flliped analysis completed")

    #blur analysis
    BlurDataset = Dataset(annotation_file=annotation_file,transforms=[transforms[1](2)])
    blurDict = BlurDataset[RollNumberLastDigit]
    pred_boxes, pred_class, pred_score = detector(blurDict["image"])
    blurimg = plot_boxes(blurDict["image"], pred_boxes, pred_class, pred_score, outputs+"picanalysis/bluroutput{}.jpg".format(RollNumberLastDigit))
    plt.subplot(3, 3, 3)
    plt.imshow(blurimg)
    pred = dict()
    box = []
    for j in range(min(len(pred_class),5)):
        box.append(str([pred_class[j],pred_boxes[j]]))
    pred['image']="bluroutput{}.jpg".format(RollNumberLastDigit)
    pred['boxes']=box
    analysis_result.append(pred)
    print("Blurred analysis completed")
    
    #rotate 90 right
    rotate90Dataset = Dataset(annotation_file=annotation_file,transforms=[transforms[2](-90)])
    rotate90Dict = rotate90Dataset[RollNumberLastDigit]
    pred_boxes, pred_class, pred_score = detector(rotate90Dict["image"])
    rotate90img = plot_boxes(rotate90Dict["image"], pred_boxes, pred_class, pred_score, outputs+"picanalysis/rotate90output{}.jpg".format(RollNumberLastDigit))
    plt.subplot(3, 3, 4)
    plt.imshow(rotate90img)
    pred = dict()
    box = []
    for j in range(min(len(pred_class),5)):
        box.append(str([pred_class[j],pred_boxes[j]]))
    pred['image']="rotate90output{}.jpg".format(RollNumberLastDigit)
    pred['boxes']=box
    analysis_result.append(pred)
    print("Analysis for 90 degree rotation completed")

    #rotate 45 left
    rotate45Dataset = Dataset(annotation_file=annotation_file,transforms=[transforms[2](45)])
    rotate45Dict = rotate45Dataset[RollNumberLastDigit]
    pred_boxes, pred_class, pred_score = detector(rotate45Dict["image"])
    rotate45img = plot_boxes(rotate45Dict["image"], pred_boxes, pred_class, pred_score, outputs+"picanalysis/rotate45output{}.jpg".format(RollNumberLastDigit))
    plt.subplot(3, 3, 5)
    plt.imshow(rotate45img)
    pred = dict()
    box = []
    for j in range(min(len(pred_class),5)):
        box.append(str([pred_class[j],pred_boxes[j]]))
    pred['image']="rotate45output{}.jpg".format(RollNumberLastDigit)
    pred['boxes']=box
    analysis_result.append(pred)
    print("analysis for 45 degree rotation completed")

    #rescale 2x
    rescale2Dataset = Dataset(annotation_file=annotation_file, transforms=[transforms[3](int(2*min(dataset[RollNumberLastDigit]["image"].shape[2], dataset[RollNumberLastDigit]["image"].shape[1])))])
    rescale2Dict = rescale2Dataset[RollNumberLastDigit]
    pred_boxes, pred_class, pred_score = detector(rescale2Dict["image"])
    rescale2img = plot_boxes(rescale2Dict["image"], pred_boxes, pred_class, pred_score, outputs+"picanalysis/rescale2output{}.jpg".format(RollNumberLastDigit))
    plt.subplot(3, 3, 6)
    plt.imshow(rescale2img)
    pred = dict()
    box = []
    for j in range(min(len(pred_class),5)):
        box.append(str([pred_class[j],pred_boxes[j]]))
    pred['image']="rescale2output{}.jpg".format(RollNumberLastDigit)
    pred['boxes']=box
    analysis_result.append(pred)
    print("Analysis for 2x rescaling completed")

    #rescale 1/2x
    rescale12Dataset = Dataset(annotation_file=annotation_file, transforms=[transforms[3](int(0.5*min(dataset[RollNumberLastDigit]["image"].shape[2], dataset[RollNumberLastDigit]["image"].shape[1])))])
    rescale12Dict = rescale12Dataset[RollNumberLastDigit]
    pred_boxes, pred_class, pred_score = detector(rescale12Dict["image"])
    rescale12img = plot_boxes(rescale12Dict["image"], pred_boxes, pred_class, pred_score, outputs+"picanalysis/rescale12output{}.jpg".format(RollNumberLastDigit))
    plt.subplot(3, 3, 7)
    plt.imshow(rescale12img)
    pred = dict()
    box = []
    for j in range(min(len(pred_class),5)):
        box.append(str([pred_class[j],pred_boxes[j]]))
    pred['image']="rescale12output{}.jpg".format(RollNumberLastDigit)
    pred['boxes']=box
    analysis_result.append(pred)
    print("Analysis for (1/2)x rescaling completed")   

    plt.savefig(outputs + 'picanalysis/plots.png')
    plt.show()

    #saving analysis results in a json file
    with open(outputs+'picanalysis/analysis.json', 'w') as f:
        json.dump(analysis_result, f)


def main():
    detector = ObjectDetectionModel()
    experiment('./data/annotations.jsonl', detector, [FlipImage, BlurImage, RotateImage, RescaleImage],'./outputs/') # Sample arguments to call experiment()



if __name__ == '__main__':
    main()