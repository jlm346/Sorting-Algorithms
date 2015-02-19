#include <iostream>

using namespace std;

template <typename T>
int split(T x[], int first, int last) {
	T pivot = x[first];
	int left = first,
		right = last;
	while (left < right) {
		while(pivot < x[right])
			right--;
		while(left < right && x[left] <= pivot)
			left++;
		if (left < right) {
			T temp = x[left];
			x[left] = x[right];
			x[right] = temp;
		}
	}
	int pos = right;
	x[first] = x[pos];
	x[pos] = pivot;
	return pos;
}

template<typename T>
void quicksortAux(T x[], int first, int last) {
	if (last > first) {
		int pivotPos = split(x, first, last);
		quicksortAux(x, first, pivotPos-1);
		quicksortAux(x, pivotPos+1, last);
	}
}

template<typename T>
void quicksort(T x[], int size) {
	quicksortAux(x, 0, size-1);
}

int main() {
	const int SIZE = 20;
	int numArray[SIZE];
	for (int i=0; i<SIZE; i++)
		numArray[i] = rand() % 100;

	cout << "Before sort: ";
	for (int i=0; i<SIZE; i++)
		cout << numArray[i] << " ";
	cout << endl;

	quicksort(numArray, SIZE);

	cout << "After sort: ";
	for (int i=0; i<SIZE; i++)
		cout << numArray[i] << " ";
	cout << endl;
}