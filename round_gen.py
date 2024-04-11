from PIL import Image
import numpy as np
import math
import matplotlib.pyplot as plt

IMG_SIZE = 25
IMAGE_NAME = "original-apple.png"

img = Image.open(IMAGE_NAME)
img = img.convert("L")
img = img.resize((IMG_SIZE,IMG_SIZE))
img = np.array(img)/255
img = img>0.5
plt.imshow(img)
plt.show()
print(img)
round_img = []

for i in range(720):
    cimg = 0
    for j in range(9,2,-1):
        #print(j-3)
        #print(img[50+round(50*j/9*math.sin(i/720 * math.pi / 180))][50+round(50*j/9*math.cos(i/720 * math.pi / 180))])
        #print(math.sin(i/2 * math.pi / 180.0))
        #print(img[1][50+round(50*j/9*math.cos(i/2 * math.pi / 180.0))])
        cimg += img[int((IMG_SIZE-1)/2)+int(IMG_SIZE/2*j/9*math.cos(i/2 * math.pi / 180.0))][int((IMG_SIZE-1)/2)-int(IMG_SIZE/2*j/9*math.sin(i/2 * math.pi / 180.0))]<<(j-3)

    #print(cimg)
    round_img.append(cimg)
print(round_img)





