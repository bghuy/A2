#include "RandomlyGeneratedFractionsToTextFile.h"
pair<int, int> randomFraction(const int& lower, const int& upper){
	pair<int, int> a;
	a.first = (rand() % (upper - lower + 1)) + lower;
	a.second= (rand() % (upper - lower + 1)) + lower;
	return a;
}
bool readRandomFractionsToFile(const pair<int, int> a[], int& capcity, int lower1, int upper1, int lower2, int upper2) {
	fstream fi;
	fi.open(OUTPUT_FILE, ios::out);
	if (fi.is_open())
	{
		for (int i = 0; i < capcity; i++)
		{
			fi << a[i].first << "/" << a[i].second << endl;
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
void menu(int lower1, int upper1, int lower2, int upper2) {
	srand(time(0));
	int capacity= (rand() % (upper1 - lower1 + 1)) + lower1;
	pair<int, int>* a = new pair<int, int>[capacity];
	for (int i = 0; i < capacity; i++)
	{
		a[i] = randomFraction(lower2, upper2);
	}
	readRandomFractionsToFile(a,capacity, 5, 10, 10, 100);
	cout << "Working with randomly generated fractions\n";
	cout << "Generating "<<capacity<<" fraction";
	if (capacity>=2)
	{
		cout << "s";
	}
	cout << ": ";
	for (int i = 0; i < capacity; i++)
	{
		cout << a[i].first << "/" << a[i].second;
		if (i!=capacity-1)
		{
			cout << ", ";
		}
	}
	cout << endl;
	cout << "Writing all " << capacity << " integer";
	if (capacity>=2)
	{
		cout << "s";
	}
	cout << " into output.txt file.\n";
	cout << "Program is exiting. Press enter to quit...";
	cin.get();
}