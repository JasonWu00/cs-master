# Name:  Ze Hong Wu (Jason)
# Email: zehong.wu17@myhunter.cuny.edu
# Date:  October 12, 2020
# Take a screenshot of your neighborhood and box it in with 50% brightness.

import matplotlib.pyplot as plt
import numpy as np

image = plt.imread("hc6-allerton.png")

horizontal = image.shape[0]
vertical = image.shape[1]

image2 = image.copy()

thirdOfHori = int(horizontal / 4)
negHori = -1 * thirdOfHori
thirdOfVert = int(vertical / 4)
negVert = -1 * thirdOfVert

print("Vertical dimensions: ", vertical)
print("Horizontal dimensions: ", horizontal)
print("One third of vertical: ", thirdOfVert)
print("One third of horizontal: ", thirdOfHori)

image2[:thirdOfHori, :, 0:3] *= 0.5
image2[negHori:, :, 0:3] *= 0.5
image2[thirdOfHori:negHori, :thirdOfVert, 0:3] *= 0.5
image2[thirdOfHori:negHori, negVert:, 0:3] *= 0.5

plt.imsave("framedMap.png", image2)
