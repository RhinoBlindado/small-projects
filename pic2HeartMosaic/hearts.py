#   ESPAÑOL
#       Titulo: Pic to Heart
#       Fecha: 11/11/2020
#       Autor: Valentino Lugli
#       Version: 0.01
#       Descripción: WIP
#       Uso: WIP

#   ENGLISH
#       Title: Pic to Heart
#       Date: 11/11/2020
#       Author: Valentino Lugli
#       Version: 0.01
#       Description: WIP
#       Usage: WIP

# Libraries
#   To load the image
from PIL import Image

#   To convert the image to an array.
from numpy import asarray



# Functions
def nearestColor(hexVal,hearts):
    

    minDiff = 0xffffff
    for i in hearts:
        if abs(i - int(hexVal, 16)) < minDiff:
            selection = i
            minDiff = abs(i - int(hexVal, 16))
    
    return selection



# Main Code

#imgName = '1.png'
imgName = input()

#       Red,                    Orange
hearts={0xff0000 : "\U00002764",0xFF8000 : "\U0001F9E1" ,
#       Yellow,                 Green,
        0xFFFF00 : "\U0001F49B",0x00ff00 : "\U0001F49A" ,
#       Blue,                   Purple,
        0x0000ff : "\U0001F499",0xFF00FF : "\U0001F49C",
#       Brown,                  Black,
        0x804000 : "\U0001F90E",0x000000 : "\U0001F5A4",
#       White
        0xffffff : "\U0001F90D"}

imgArray = asarray(Image.open(imgName))

for i in range(imgArray.shape[0]):
    for j in range(imgArray.shape[1]):
        hexVal = '0x%02x%02x%02x' % (imgArray[i][j][0], imgArray[i][j][1], imgArray[i][j][2])
        out = nearestColor(hexVal,hearts)
        print(hearts[out], end="")
    print("")

