//Author: Ze Hong Wu
//Course: CSCI 135
//Instructor: Tong Yi
//Assignment: Lab 8f

/*
  Description:
    The program reads a PGM image from the file "inImage.pgm",
    and outputs a modified image to "outImage.pgm"
*/


#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>

using namespace std;

const int MAX_H = 512;
const int MAX_W = 512;

// Reads a PGM file.
// Notice that: height and width are passed by reference!
void readImage(int image[MAX_H][MAX_W], int &height, int &width) {
	char c;
	int x;
	ifstream instr;
	instr.open("inImage.pgm");
  if (instr.fail()) {
		cout << "Unable to read file\n";
		exit(1);
	}

	// read the header P2
	instr >> c;
	assert(c == 'P');
	instr >> c;
	assert(c == '2');

	// skip the comments (if any)
	while ((instr>>ws).peek() == '#') {
		instr.ignore(4096, '\n');
	}

	instr >> width;
	instr >> height;

	assert(width <= MAX_W);
	assert(height <= MAX_H);
	int max;
	instr >> max;
	assert(max == 255);

	for (int row = 0; row < height; row++)
		for (int col = 0; col < width; col++)
			instr >> image[row][col];
	instr.close();
	return;
}


// Writes a PGM file
// Need to provide the array data and the image dimensions
void writeImage(int image[MAX_H][MAX_W], int height, int width) {
	ofstream ostr;
	ostr.open("outImage.pgm");
	if (ostr.fail()) {
		cout << "Unable to write file\n";
		exit(1);
	}

	// print the header
	ostr << "P2" << endl;
	// width, height
	ostr << width << ' ';
	ostr << height << endl;
	ostr << 255 << endl;

	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			assert(image[row][col] < 256);
			assert(image[row][col] >= 0);
			ostr << image[row][col] << ' ';
			ostr << endl;
		}
	}
	ostr.close();
	return;
}

void invertImage(int image[MAX_H][MAX_W], int height, int width) {
  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      image[row][col] = abs(255 - image[row][col]);
    }
  }
}

void invertHalfImage(int image[MAX_H][MAX_W], int height, int width) {
  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      if (col > width / 2) {
        image[row][col] = abs(255 - image[row][col]);
      }
    }
  }
}

void drawBox(int image[MAX_H][MAX_W], int height, int width) {
  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      if (col > width / 4 && col < width * 3/4 && row > height / 4 && row < height * 3/4) {
        image[row][col] = 255;
      }
    }
  }
}

void drawFrame(int image[MAX_H][MAX_W], int height, int width) {
  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      if ((col > width / 4 && col < width * 3/4) && (row == height / 4 || row == height * 3/4)) {
        image[row][col] = 255;
      }
      if ((col == width / 4 || col == width * 3/4) && (row > height / 4 && row < height * 3/4)) {
        image[row][col] = 255;
      }
    }
  }
}

void scaleUp(int original[MAX_H][MAX_W], int output[MAX_H][MAX_W], int height, int width) {
  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width ; col++) {
      output[row*2][col*2] = original[row][col];
      output[row*2+1][col*2] = original[row][col];
      output[row*2][col*2+1] = original[row][col];
      output[row*2+1][col*2+1] = original[row][col];
    }
  }
}

void debugPrint(int array[MAX_H][MAX_W], int height, int width) {
  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      cout << array[row][col] << " ";
    }
    cout << endl;
  }
}

void pixelate(int original[MAX_H][MAX_W], int output[MAX_H][MAX_W], int height, int width) {
  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width ; col++) {
      //for every 2x2 area to average, we will remember the upper left point
      //it will always have even coordinates
      //for every point in output, look to the corresponding upper left point
      //and the other three points to find an average
      int refCol = col - (col % 2);
      int refRow = row - (row % 2);
      //refCol and refRow are the coordinates of the upper left point
      int avg = (original[refRow][refCol] + original[refRow][refCol+1]
              + original[refRow+1][refCol] + original[refRow+1][refCol+1]) / 4;
      //debug purposes
      //cout << "Avg is: " << avg << endl;
      output[row][col] = avg;
    }
  }
}

//Self reminders
//image[xcor][ycor]
//row and col represents the nth row or column

int main() {

	int img[MAX_H][MAX_W];
	int h, w;

	readImage(img, h, w); // read it from the file "inImage.pgm"
	// h and w were passed by reference and
	// now contain the dimensions of the picture
	// and the 2-dimesional array img contains the image data

	// Now we can manipulate the image the way we like
	// for example we copy its contents into a new array
  int pixelated[MAX_H][MAX_W];
  pixelate(img, pixelated, h, w);
  /*
  debugPrint(img, h, w);
  cout << "Initial image" << endl;
  int doubleSize[MAX_H][MAX_W];

  scaleUp(img, doubleSize, h, w);
  debugPrint(doubleSize, h*2, w*2);
  cout << "Double sized" << endl;
  */

  //debugPrint(pixelated, h*2, w*2);
  //cout << "Pixelated" << endl;

	int out[MAX_H][MAX_W];

	for(int row = 0; row < h; row++) {
		for(int col = 0; col < w; col++) {
			out[row][col] = pixelated[row][col];
		}
	}

	// and save this new image to file "outImage.pgm"
	writeImage(out, h, w);

}
