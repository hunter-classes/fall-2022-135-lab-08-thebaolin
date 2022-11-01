#include <iostream>
#include "funcs.h"
#include "imageio.h"
#include <string>
#include <cmath>

using namespace std;

void task_A(string input){
    int img[MAX_H][MAX_W];
    int h, w;
    readImage(input, img, h, w);

    int output[MAX_H][MAX_W];

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            output[i][j] = 255 - img[i][j];
        }
    }

    writeImage("taskA.pgm", output, h , w);
}

void task_B(string input){
    int img[MAX_H][MAX_W];
    int h, w;
    readImage(input, img, h, w);

    int output[MAX_H][MAX_W];

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(j >= w/2)
                output[i][j] = (255 - img[i][j]);
            else
                output[i][j] = img[i][j];
        }
    }

    writeImage("taskB.pgm", output, h, w);
}

void task_C(string input){
    int img[MAX_H][MAX_W];
    int h, w;
    readImage(input, img, h, w);

    int output[MAX_H][MAX_W];

    for(int row = 0; row < h; row++) {
        for(int col = 0; col < w; col++) {
            if((row > (.25 * h)) && (row < (.75 * h)) && (col > (.25 * w)) && (col < (.75 * w))) 
                output[row][col] = 255;
            else 
                output[row][col] = img[row][col];
        
        }
    }

    writeImage("taskC.pgm", output , h, w);
}

void task_D(string input){
    
    int img[MAX_H][MAX_W];
    int h, w;
    readImage(input, img, h, w);

    int output[MAX_H][MAX_W];

    for(int row = 0; row < h; row++) {
        for(int col = 0; col < w; col++) {

            if((row > (.25 * h)) && (row < (.75 * h)) && (col > (.25 * w)) && (col < (.75 * w))) 
                output[row][col] = 255;
            else 
                output[row][col] = img[row][col];
    
            if((row > ((.25 * h) + 1)) && (row < ((.75 * h)) - 1) && (col > ((.25 * w)) + 1) && (col < ((.75 * w) - 1))) 
                output[row][col] = img[row][col];
        }
    }

  writeImage("taskD.pgm", output , h, w);
}

void task_E(string input){

    int img[MAX_H][MAX_W];
	int h, w;
	readImage(input, img, h, w);

    int output[MAX_H][MAX_W];

	for (int row = 0; row < h;	row++) {
		for (int col = 0; col < w; col++) {
			output[row * 2][col * 2] = img[row][col];
			output[row * 2][col * 2 + 1] = img[row][col];
			output[row * 2 + 1][col * 2] = img[row][col];
			output[row * 2 + 1][col * 2 + 1] = img[row][col];
		}
	}
	h *= 2;
	w*= 2;

	writeImage("taskE.pgm", output, h, w);
}

void task_F(string input){
    int img[MAX_H][MAX_W];
	int h, w;
	readImage(input, img, h, w);

    int output[MAX_H][MAX_W];

    for(int row = 0; row < h; row+=2) {
        for(int col = 0; col < w; col+=2) {
            int numerator = img[row][col] + img[row+1][col+1] + img[row][col+1] + img[row+1][col];
            int avg = round(numerator/4);

            output[row][col] = avg;
            output[row][col+1] = avg;
            output[row+1][col] = avg;
            output[row+1][col+1] = avg;
        }
    }
  writeImage("taskF.pgm", output, h, w);
}