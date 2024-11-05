#include <iomanip>
#include <iostream>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low,	const int High);
void Input(int** a, const int rowCount, const int colCount);
void Print(int** a, const int rowCount, const int colCount);
bool Part1_CountColsWithZero(int** a, const int rowCount, const int colCount, int& count, bool& result);
void rowSeria(int** a, const int rowCount, const int colCount, int& longestRow, int& maxLength);

int main()
{
	srand((unsigned)time(NULL));

	int low = -45;
	int high = 24;

	int rowCount, colCount;

	cout << "rowCount= "; cin >> rowCount;
	cout << "colCount= "; cin >> colCount;

	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];

	Create(a, rowCount, colCount, low, high);
	Input(a, rowCount, colCount);
	Print(a, rowCount, colCount);

	int count = 0;
	bool result = false;

	Part1_CountColsWithZero(a, rowCount, colCount, count, result);

	if (result)
		cout << "count = " << count << endl;
	else
		cout << "there are no zero elements" << endl;
	cout << endl;

	int longestRow = -1;
	int maxLength = 0;

	rowSeria(a, rowCount, colCount, longestRow, maxLength);

	if (longestRow != -1) {
		cout << "count= " << longestRow;
	}
	else {
		cout << "no line" << endl;
	}

	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;

	return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int low, const int high)
{
	for(int i = 0; i < rowCount; i++)
		for(int j = 0; j < colCount; j++) 
			a[i][j] = low + rand() % (high - low + 1);
}
void Input(int** a, const int rowCount, const int colCount)
{
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			cout << "a[" << i << "][" << j << "] = "; cin >> a[i][j];
		}
		cout << endl;

	}
}
void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
bool Part1_CountColsWithZero(int** a, const int rowCount, const int colCount, int& count, bool& result) 
{

	for (int j = 0; j < colCount; j++) {
		bool hasZero = false;

		for (int i = 0; i < rowCount; i++) {
			if (a[i][j] == 0) {
				hasZero = true;
				break;
			}
		}

		if (hasZero) {
			result = true;
			count++;
		}
	}
	return result;
}

void rowSeria(int** a, const int rowCount, const int colCount, int& longestRow, int& maxLength)
{
	for (int i = 0; i < rowCount; i++)
	{
		int currentLength = 1;
		int currentValue = a[i][0];

		for (int j = 1; j < colCount; j++) {
			if (a[i][j] == currentValue) {
				currentValue = a[i][0];
			}
			else {
				if (currentValue > maxLength) {
					maxLength = currentLength;
					longestRow = i;
				}
				currentValue = a[i][j];
				currentLength = 1;
			}
		}
		if (currentLength > maxLength) {
			maxLength = currentLength;
			longestRow = i;
		}
	}
}