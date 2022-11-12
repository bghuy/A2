#include "FractionsFromTextFile.h"
int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
Fraction::Fraction() {
	num = 1;
	den = 1;
}
Fraction::Fraction(int a, int b) {
	num = a;
	if (b!=0)
	{
		den = b;
		return;
	}
	den = 1;
}
float Fraction::Decimal() {
	if (den != 0)
	{
		return (float)num / den;
	}
	return num;
}
int Fraction::Percentage() {
	return Decimal() * 100;
}
bool readToFractionArr(vector<Fraction>& fArr, int& capacity) {
	stringstream ss;
	string temp;
	fstream fi;
	fi.open(INPUT_FILE, ios::in);
	if (fi.is_open()) {
		capacity = 0;
		while (getline(fi,temp))
		{
			ss.clear();
			ss << temp;
			++capacity;
			Fraction p;
			for (int i = 0; i < 2; i++)
			{
				getline(ss, temp, '/');
				if (i==0)
				{
					p.num = stoi(temp);
				}
				else
				{
					p.den = stoi(temp);
				}
			}
			fArr.push_back(p);
		}
		fi.close();
		return 1;
		
	}
	else
	{
		fi.close();
		return 0;
	}

}
ostream& operator << (ostream& os, const Fraction& p) {
	os << p.num;
	if (p.den!=1)
	{
		os <<"/" << p.den;
	}
	return os;
}
void Fraction::print() {
	cout << num << "/" << den;
}
Fraction Fraction::lowestTerm() {
	int temp = gcd(num, den);
	return Fraction(num / temp, den / temp);
}
void menu(vector<Fraction>& fArr, int& capacity) {
	cout << "Working with fraction arrays from text files\n";
	cout << "Reading data from input.txt.\n";
	int check= readToFractionArr(fArr, capacity);
	if (check==0)
	{
		return;
	}
	cout << "Expected to find " << capacity << " fraction";
	if (capacity>=2)
	{
		cout << "s";
	}
	cout << ".\n";
	cout << "Found " << fArr.size() << " fraction";
	if (fArr.size() >= 2)
	{
		cout << "s";
	}
	cout << ": ";
	for (int i = 0; i < fArr.size(); i++)
	{
		fArr[i].print();
		if (i!=fArr.size()-1)
		{
			cout << ", ";
		}
	}
	cout << endl;
	cout << "Lowest term: ";
	for (int i = 0; i < fArr.size(); i++)
	{
		Fraction b = fArr[i].lowestTerm();
		cout << b;
		if (i != fArr.size() - 1)
		{
			cout << ", ";
		}
	}
	cout << endl;
	cout << "Decimal: ";
	for (int i = 0; i < fArr.size(); i++)
	{
		cout << setprecision(2)<<fixed << fArr[i].Decimal();
		if (i != fArr.size() - 1)
		{
			cout << ", ";
		}
	}
	cout << endl;
	cout << "Percentage: ";
	for (int i = 0; i < fArr.size(); i++)
	{
		cout << fArr[i].Percentage()<<"%";
		if (i != fArr.size() - 1)
		{
			cout << ", ";
		}
	}
	cout << endl;
	cout << "Program is exiting. Press enter to quit...";
	cin.get();
}
