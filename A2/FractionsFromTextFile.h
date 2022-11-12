#ifndef FractionsFromTextFile_H
#define FractionsFromTextFile_H
#define INPUT_FILE "input.txt"
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
#include <iomanip>  
using namespace std;
int gcd(int a, int b);
class Fraction
{
private:
	int num;
	int den;
public:
	Fraction();
	Fraction(int a, int b);
	float Decimal();
	int Percentage();
	friend bool readToFractionArr(vector<Fraction>& fArr, int& capacity);
	friend ostream& operator << (ostream& os, const Fraction& p);
	void print();
	Fraction lowestTerm();
};
bool readToFractionArr(vector<Fraction>& fArr, int& capacity);
ostream& operator << (ostream& os, const Fraction& p);

void menu(vector<Fraction>& fArr, int& capacity);
#endif // !FractionsFromTextFile_h


