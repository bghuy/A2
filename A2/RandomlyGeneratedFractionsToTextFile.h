#ifndef RandomlyGeneratedFractionsToTextFile_H
#define RandomlyGeneratedFractionsToTextFile_H
#define OUTPUT_FILE "output.txt"
#include<iostream>
#include<fstream>
#include<time.h>
using namespace std;
pair<int, int> randomFraction(const int& lower,const int &upper);
bool readRandomFractionsToFile(const pair<int, int> a[], int& capcity, int lower1, int upper1, int lower2, int upper2);
void menu(int lower1, int upper1, int lower2, int upper2);
#endif // !RandomlyGeneratedFractionsToTextFile_H


