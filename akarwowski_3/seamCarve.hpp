// Alex Karwowski
// Algorithms
// Project 3
// 4/27/20

#ifndef INCLUDE_READFILE_HPP
#define INCLUDE_READFILE_HPP

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

void getEnergy(int**, int**, int, int);
void cumVEnergy(int**, int**, int, int);
void cumHEnergy(int**, int**, int, int);
void vSeam(int**, int**, int, int);
void hSeam(int**, int**, int, int);
void writeFile(int**, int, int, std::string);

#endif
