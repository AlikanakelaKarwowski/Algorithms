// Alex Karwowski
// Algorithms
// Project 3
// 4/27/20


#include "seamCarve.hpp"

void getEnergy(int** grayScaleValue, int** eArray, int rows, int col) {
    //loops through rows
    for(int i=0; i<rows; i++) {
        for(int j=0; j<col; j++) {
            //up and left
            if(i==0 && j==0) {
                //only do right and down
                eArray[i][j] = (abs((grayScaleValue[i][j])-(grayScaleValue[i+1][j])) +
                                   abs((grayScaleValue[i][j])-(grayScaleValue[i][j+1])));

            }
            //up and right
            else if((i==0) && (j==(col-1))){
                //only do left and down
                eArray[i][j] = (abs((grayScaleValue[i][j])-(grayScaleValue[i][j-1])) +
                                   abs((grayScaleValue[i][j])-(grayScaleValue[i+1][j])));
            }
            //down and left
            else if((i==(rows-1)) && (j==0)) {
                //only do up and right
                eArray[i][j] = (abs((grayScaleValue[i][j])-(grayScaleValue[i-1][j])) +
                                   abs((grayScaleValue[i][j])-(grayScaleValue[i][j+1])));
            }
            //down and right
            else if((i==(rows-1)) && (j==(col-1))){
                //only do up and left
                eArray[i][j] = (abs((grayScaleValue[i][j])-(grayScaleValue[i-1][j])) +
                                   abs((grayScaleValue[i][j])-(grayScaleValue[i][j-1])));
            }
            //for top row
            else if(i==0) {
                //right, left and bottom
                eArray[i][j] = (abs((grayScaleValue[i][j])-(grayScaleValue[i][j+1])) +
                                   abs((grayScaleValue[i][j])-(grayScaleValue[i][j-1])) +
                                   abs((grayScaleValue[i][j])-(grayScaleValue[i+1][j])));
            }
            //for bottom row
            else if(i==(rows-1)){
                //top, left and right
                eArray[i][j] = (abs((grayScaleValue[i][j])-(grayScaleValue[i][j+1])) +
                                   abs((grayScaleValue[i][j])-(grayScaleValue[i][j-1])) +
                                   abs((grayScaleValue[i][j])-(grayScaleValue[i-1][j])));
            }
            //for first column
            else if(j==0) {
                //right, top and bottom
                eArray[i][j] = (abs((grayScaleValue[i][j])-(grayScaleValue[i][j+1])) +
                                   abs((grayScaleValue[i][j])-(grayScaleValue[i-1][j])) +
                                   abs((grayScaleValue[i][j])-(grayScaleValue[i+1][j])));
            }
            else if(j==(col-1)){
                //left, top and bottom
                eArray[i][j] = (abs((grayScaleValue[i][j])-(grayScaleValue[i][j-1])) +
                                   abs((grayScaleValue[i][j])-(grayScaleValue[i+1][j])) +
                                   abs((grayScaleValue[i][j])-(grayScaleValue[i-1][j])));
            } else {
                eArray[i][j] = (abs((grayScaleValue[i][j])-(grayScaleValue[i-1][j])) +
                                   abs((grayScaleValue[i][j])-(grayScaleValue[i+1][j])) +
                                   abs((grayScaleValue[i][j])-(grayScaleValue[i][j-1])) +
                                   abs((grayScaleValue[i][j])-(grayScaleValue[i][j+1])));
            }
        }
    }
}

void cumVEnergy(int** eArray, int** ceArray, int rows, int col) {
    //loop through the rows
    for(int i=0; i<rows; i++) {
        //loop through the col
        for(int j=0; j<col; j++) {
            //do this only for the first row
            if(i==0){
                //copy over values
                ceArray[i][j] = eArray[i][j];
            } else {
                //first column
                if(j==0) {
                    //ignore out of bounds
                    ceArray[i][j] = eArray[i][j] + std::min(ceArray[i-1][j], ceArray[i-1][j+1]);
                } else if(j==(col-1)) {
                    //ignore out of bounds
                    ceArray[i][j] = eArray[i][j] + std::min(ceArray[i-1][j-1], ceArray[i-1][j]);
                } else {
                    //find the min energy to add to the running total
                    ceArray[i][j] = eArray[i][j] + std::min(std::min(ceArray[i-1][j-1], ceArray[i-1][j]), ceArray[i-1][j+1]);
                }
            }
        }
    }
}

void cumHEnergy(int** eArray, int** ceArray, int rows, int col) {
    //loop through the col
    for(int j=0; j<col; j++) {
        //loop through the rows
        for(int i=0; i<rows; i++) {
            //do this only for the first column
            if(j==0){
                //copy over values
                ceArray[i][j] = eArray[i][j];
            } else {
                //top row
                if(i==0) {
                    //ignore out of bounds
                    ceArray[i][j] = eArray[i][j] + std::min(ceArray[i][j-1], ceArray[i+1][j-1]);
                } else if(i==(rows-1)) {
                    //ignore out of bounds
                    ceArray[i][j] = eArray[i][j] + std::min(ceArray[i][j-1], ceArray[i-1][j-1]);
                } else {
                    //find the min energy to add to the running total
                    ceArray[i][j] = eArray[i][j] + std::min(std::min(ceArray[i-1][j-1], ceArray[i][j-1]), ceArray[i+1][j-1]);
                }
            }
        }
    }
}

void vSeam(int** grayScaleValue, int** ceArray, int rows, int col) {
    int mIndex = 0;
    //set minimum to the first element in the last row
    int min = ceArray[rows-1][mIndex];

    //loop through last row and find index of the minimum
    for(int j=0; j<col; j++) {
        if(ceArray[rows-1][j] <= min) {
            mIndex = j;
            min = ceArray[rows-1][j];
        }
    }

    //delete element and shift
    for(int it = mIndex; it < (col-1);it++){
        //copy the left element of the last row
        grayScaleValue[rows-1][it] = grayScaleValue[rows-1][it+1];
    }

    //loop through remaining rows
    for(int i=(rows-2); i>=0;i--){
        //base case for edge rows
        if(mIndex==0){
            //check the minium of directly above or to the right
            if(ceArray[i][mIndex] < ceArray[i][mIndex+1]){
                //return above
                mIndex = mIndex;
            } else if(ceArray[i][mIndex+1] < ceArray[i][mIndex]){
                //return right
                mIndex = mIndex+1;
            }
        }
        // right edge
        else if(mIndex==(col-1)){
            //only check the minium of directly above or to the right
            if(ceArray[i][mIndex] < ceArray[i][mIndex-1]){
                //return above
                mIndex = mIndex;
            } else if(ceArray[i][mIndex-1] < ceArray[i][mIndex]){
                //return left
                mIndex = mIndex-1;
            }
        }
        //not first or last column case
        // find min of above left and right
        else {
            // check middle as min
            if((ceArray[i][mIndex] < ceArray[i][mIndex-1]) && (ceArray[i][mIndex] < ceArray[i][mIndex+1])){
                //return middle
                mIndex = mIndex;
            } // check the right as min
            else if((ceArray[i][mIndex+1] < ceArray[i][mIndex]) && (ceArray[i][mIndex+1] < ceArray[i][mIndex-1])){
                //return right
                mIndex = mIndex+1;
            } // check left as min
            else if((ceArray[i][mIndex-1] < ceArray[i][mIndex]) && (ceArray[i][mIndex-1] < ceArray[i][mIndex+1])){
                //return left
                mIndex = mIndex-1;
            } // if both left and right are equal and less than middle
            else if((ceArray[i][mIndex-1] < ceArray[i][mIndex]) && (ceArray[i][mIndex+1] < ceArray[i][mIndex]) && (ceArray[i][mIndex+1] == ceArray[i][mIndex-1])){
                // by default return the left
                mIndex = mIndex-1;
            }
        }

        // delete mIndex value and shift all the values over
        for(int it = mIndex; it < (col-1);it++){
            //copy over the left element
            grayScaleValue[i][it] = grayScaleValue[i][it+1];
        }
    }
}

void hSeam(int** grayScaleValue, int** ceArray, int rows, int col) {
    int mIndex = col-1;
    int min = 99999999;

    //loop through last col and find index of the minimum
    for(int i=0; i<rows; i++) {
        if(ceArray[i][col-1] < min) {
            mIndex = i;
            min = ceArray[i][col-1];
        }
    }

    for(int it = mIndex; it < (rows-1);it++){
        //copy the left element of the last row
        grayScaleValue[it][col-1] = grayScaleValue[it+1][col-1];
    }

    //loop through the remaining col
    for(int j=(col-2); j>=0;j--){
        //base case for first or last row
        //first row
        if(mIndex==0){
            //only check the minium of directly left and to the bottom
            //check left as min
            if(ceArray[mIndex][j] < ceArray[mIndex+1][j]){
                //return left
                mIndex = mIndex;
            } else if(ceArray[mIndex+1][j] < ceArray[mIndex][j]){
                //return bottom
                mIndex = mIndex+1;
            }
        }
        // right
        else if(mIndex==(rows-1)){
            //check left as min
            if(ceArray[mIndex][j] < ceArray[mIndex-1][j]){
                //return left
                mIndex = mIndex;
            } else if(ceArray[mIndex-1][j] < ceArray[mIndex][j]){
                //return top
                mIndex = mIndex-1;
            }
        }
        //not first or last row
        // find min of top left and bottom
        else {
            // check middle as min
            if((ceArray[mIndex][j] < ceArray[mIndex-1][j]) && (ceArray[mIndex][j] < ceArray[mIndex+1][j])){
                //return left
                mIndex = mIndex;
            } // check the top as min
            else if((ceArray[mIndex-1][j] < ceArray[mIndex][j]) && (ceArray[mIndex-1][j] < ceArray[mIndex+1][j])){
                //return top
                mIndex = mIndex-1;
            } // check bottom as min
            else if((ceArray[mIndex+1][j] < ceArray[mIndex][j]) && (ceArray[mIndex+1][j] < ceArray[mIndex-1][j])){
                //return bottom
                mIndex = mIndex+1;
            }
            // if both top and bottom are equal and less than left
            else if((ceArray[mIndex+1][j] < ceArray[mIndex][j]) && (ceArray[mIndex-1][j] < ceArray[mIndex][j]) && (ceArray[mIndex+1][j] == ceArray[mIndex-1][j])){
                // by default return the top
                mIndex = mIndex-1;
            }
        }
        // delete mIndex value and shift
        for(int it = mIndex; it < (rows-1);it++){
            //copy over the left element
            grayScaleValue[it][j] = grayScaleValue[it+1][j];
        }
    }
}

//Writes the seam carved image to a .pgm file for viewing
void writeFile(int** array, int rows, int col, std::string outFileName) {
    std::ofstream outFile;
    outFileName.append("_processed.pgm");
    outFile.open(outFileName.c_str());
    if (!outFile.is_open()) {
        std::cout << "Can't open output file"  << outFileName << std::endl;
        return;
    }

    // write the header of the pgm file
    outFile << "P2\n" << "#Output file for " << outFileName << "\n" << col << " " << rows << "\n255\n";

    //writes the contents of the array to a .pgm file for viewing
    for(int i=0; i<rows; i++) {
        //loops through rows and col
        for(int j=0; j<col-1; j++) {
            outFile << array[i][j] << " ";
        }
        //last column case appends new line
        outFile << array[i][col-1] << std::endl;
    }
    outFile.close();
 }
