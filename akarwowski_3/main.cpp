// Alex Karwowski
// Algorithms
// Project 3
// 4/27/20

#include "seamCarve.hpp"

//main function takes multiple arguments
int main(int argc, char** argv) {
    if (argc != 4) {
        std::cout << "Invalid number of arguments. \nShould be ./a.out file.pgm vertSeams horizSeams" << std::endl;
    }
    int vSeams = atoi(argv[2]);
    int hSeams = atoi(argv[3]);
    std::string filename;
    filename = argv[1];
    std::string outFilename = filename.substr(0, filename.size()-4);

    int rows = 0, col = 0, greyScaleMax = 255;
    std::ifstream pgm(filename.c_str());
    std::stringstream ss;
    std::string input = "";

    getline(pgm,input);
    getline(pgm,input);
    ss << pgm.rdbuf();
    ss >> col >> rows;
    ss >> greyScaleMax;

    // GreyScale Array used to store the greyscale values of the original image
    int** grayScaleValue = new int*[rows];
    for (int i=0; i<rows; ++i) {
        grayScaleValue[i] = new int [col];
    }

    //Populate grayScaleValue with pgm values
    for(int r = 0; r < rows; r++) {
        for (int c = 0; c < col; c++) {
            ss >> grayScaleValue[r][c];
        }
    }

    // close input file for efficiency
    pgm.close();

    //Carry our the vertical seam operation while vSeams is greater than zero
    for(int i=0; i < vSeams; i++) {
        //create new array to store energy in
        int** eArray = new int*[rows];
        for (int i=0; i<rows; i++) {
            eArray[i] = new int[col];
        }

        //Used to store the cumulative minimum energy for vertical seams
        int** ceArray = new int*[rows];
        for (int j=0; j<rows; j++) {
            ceArray[j] = new int[col];
        }

        //calculate the energy array
        getEnergy(grayScaleValue, eArray, rows, col);
        //calculate the cumulative vertical energies
        cumVEnergy(eArray, ceArray, rows, col);
        //flag positions of values to be deleted
        vSeam(grayScaleValue, ceArray, rows, col);
        //decrement the column number
        col--;

        //delete memory associated with ceArray and eArray
        for (int k=0; k<rows; k++) {
           delete[] ceArray[k];
           delete[] eArray[k];
        }
        delete[]ceArray;
        delete[]eArray;
    }

    //Carry out the horizontal seam operations while hSeams is greater than zero
    for(int i=0; i < hSeams; i++) {
        //create new array to store energy in
        int** eArray = new int*[rows];
        for (int i=0; i<rows; ++i) {
            eArray[i] = new int[col];
        }

        //Used to store the cumulative minimum energy for vertical seams
        int** ceArray = new int*[rows];
        for (int j=0; j<rows; ++j) {
            ceArray[j] = new int[col];
        }

        //calculate the energy array
        getEnergy(grayScaleValue, eArray, rows, col);
        //calculate the cumulative horizontal energies
        cumHEnergy(eArray, ceArray, rows, col);
        //flag positions of values to be deleted
        hSeam(grayScaleValue, ceArray, rows, col);
        //decrement the row number
        rows--;

        //delete memory associated with ceArray and eArray
        for (int k=0; k<rows; k++) {
           delete[] ceArray[k];
           delete[] eArray[k];
        }
        delete[]ceArray;
        delete[]eArray;
    }

    //write grayScaleValue to a file
    writeFile(grayScaleValue, rows, col, outFilename);

    //delete memory associated with grayScaleValue
    for (int k=0; k<rows; k++) {
           delete[] grayScaleValue[k];
    }
    delete[]grayScaleValue;

    return 0;
}
