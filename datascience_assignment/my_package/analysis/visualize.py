#19CS10031
#Abhishek Gandhi
#Data Science Assignment QS2

#Imports
import numpy as np
from PIL import Image, ImageDraw, ImageFont

def plot_boxes(image, pred_boxes, pred_class, pred_score, outputs): # Write the required arguments

  
  # The function should plot the predicted boxes on the images and save them.
  # Tip: keep the dimensions of the output image less than 800 to avoid RAM crashes.
  
  selectIndice = []
  if len(pred_boxes) <= 5:
    selectIndice = [x for x in range(len(pred_boxes))]
  else:
    #not required but using it just for checking purposes
    predScore = pred_score.copy()
    predScore.sort(reverse=True)
    for i in range(5):
      #sorting top 5 if thy are not sorted just to make sure
      selectIndice.append(pred_score.index(predScore[i]))

  if isinstance(image,np.ndarray):
    image = image.transpose((1, 2, 0))
    img = Image.fromarray((image*255).astype(np.uint8))
  else:
    img = image.copy()
  imgDraw = ImageDraw.Draw(img)
  font = ImageFont.load_default()

  #Drawing rectangles
  for i in selectIndice:
    imgDraw.rectangle(pred_boxes[i], outline=(255, 0, 0), fill= None)

  #drawing text => prediction   
  for i in selectIndice:
      (y, _), (_, x) = pred_boxes[i]
      imgDraw.text((y, x-12), pred_class[i], font=font, fill=(255, 0, 0))
  img.save(outputs)

  #returning image for use in analysis part
  return img

  