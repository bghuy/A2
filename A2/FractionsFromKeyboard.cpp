#include"FractionsFromKeyboard.h"
int typeOfError(string input, int lowerBound, int upperBound) {
	if (input.length() == 0) return 1;
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] < '0' || input[i]>'9') return 2;
	}
	if (stoi(input) < lowerBound || stoi(input) > upperBound) return 3;
	return 4;
}
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
	if (b != 0)
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
		while (getline(fi, temp))
		{
			ss.clear();
			ss << temp;
			++capacity;
			Fraction p;
			for (int i = 0; i < 2; i++)
			{
				getline(ss, temp, '/');
				if (i == 0)
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
	if (p.den != 1)
	{
		os << "/" << p.den;
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
	cout << "Working with fraction arrays from keyboard\n";
	cout << "Getting fractions from the keyboard\n";
	
	string buffer;
	while (true)
	{
		cout << "Please enter an integer in the range of [5, 10]:";
		getline(cin, buffer);
		int error = typeOfError(buffer, 5, 10);
		if (error == 1)
		{
			cout << "Error: Input string cannot be empty.\n";
		}
		else if (error == 2)
		{
			cout << "Error: Invalid input format.\n";
		}
		else if (error == 3)
		{
			cout << "Error: The integer must be in the range of [5, 10]\n";
		}
		else
		{
			break;
		}
	}
	capacity = stoi(buffer);
	
	for (int i = 0; i < capacity; i++)
	{
		int error = 4;
		do
		{

			string g;
			cout << "enter fraction["<<i<<"]: ";
			getline(cin, g);
			stringstream ss;
			ss << g;
			Fraction b;
			for (int j = 0; j < 2; j++)
			{
				
				string temp;
				getline(ss, temp, '/');
				error = typeOfError(temp, 10, 100);
				if (error == 1)
				{
					cout << "Error: Input num or den cannot be empty.\n";
					break;
				}
				else if (error == 2)
				{
					cout << "Error: Invalid input format.\n";
					break;
				}
				else if (error == 3)
				{
					cout << "Error: The integer must be in the range of [10, 100]\n";
					break;
				}
				else
				{
					if (j == 0)
					{
						b.num = stoi(temp);
					}
					else
					{
						b.den = stoi(temp);
					}
					error = 4;
				}
			}
			if (error==4)
			{
				fArr.push_back(b);
			}
		} while (error < 4);
	}
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
		cout << setprecision(2) << fixed << fArr[i].Decimal();
		if (i != fArr.size() - 1)
		{
			cout << ", ";
		}
	}
	cout << endl;
	cout << "Percentage: ";
	for (int i = 0; i < fArr.size(); i++)
	{
		cout << fArr[i].Percentage() << "%";
		if (i != fArr.size() - 1)
		{
			cout << ", ";
		}
	}
	cout << endl;
	cout << "Program is exiting. Press enter to quit...";
	cin.get();

}
