//Radix Sort implementation NOT written by me, Josh. I just found it and thought it was really cool.
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

template<typename T>
void displayVector(vector<T> vect);

void radixSortLSD(vector<int> & vect)
{
	const int BASE = 10;
	int worth = 1;
	vector<int> bins[BASE];
	int largest = vect[0];
	for (size_t i=1; i<vect.size(); i++) {
		if (vect[i] > largest)
			largest = vect[i];
	}
	int numDigits = static_cast<int>(log10(static_cast<double>(largest))) + 1;
	for (int i=0; i<numDigits; i++) 
	{
		// clear out the bins
		for (int i=0; i<BASE; i++)
			bins[i].clear();
		// sort data into bins according to digit
		for (size_t i = 0; i<vect.size(); i++)
			bins[(vect[i]/worth)%worth].push_back(vect[i]);
		
		// collect data from bins in order
		int vect_idx = 0;
		for (int bin_idx = 0; bin_idx < BASE; bin_idx++) {
			for (size_t i=0; i<bins[bin_idx].size(); i++) 
				vect[vect_idx++] = bins[bin_idx][i];
		}
		
		// next position is worth base times as much
		worth = worth * BASE;
	}
}

int main()
{
	vector<int> numbers;
	for (int i=0; i<10; i++)
		numbers.push_back(rand() % 1000);

	displayVector(numbers);
	radixSortLSD(numbers);
	displayVector(numbers);

	return 0;
}

template<typename T>
void displayVector(vector<T> vect)
{
	for (int i=0; i<(int)vect.size(); i++)
		cout << vect[i] << " ";
	cout << endl;
}

