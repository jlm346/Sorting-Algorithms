#include <iostream>

using namespace std;

template<typename T>
void displayArray(T * arr, int size);

template<typename T>
void merge(T * arr, int start, int split, int end)
{
	T * tempArr = new T[end-start];
	int idx1=start, idx2=split, idx=0;
	while (idx1<split && idx2<end) {
		if (arr[idx1] < arr[idx2]) 
			tempArr[idx++] = arr[idx1++];
		else
			tempArr[idx++] = arr[idx2++];
	}
	while (idx1 < split)
		tempArr[idx++] = arr[idx1++];
	while (idx2 < end)
		tempArr[idx++] = arr[idx2++];
	for (int i=0; i<end-start; i++)
		arr[start+i] = tempArr[i];
	delete[] tempArr;
}

template<typename T>
void mergesortAux(T * arr, int start, int end)
{
	if (end-start > 1) {
		int mid = (start + end) / 2;
		mergesortAux(arr, start, mid);
		mergesortAux(arr, mid, end);
		merge(arr, start, mid, end);
	}
}

template<typename T>
void mergesort(T * arr, int size)
{
	mergesortAux(arr, 0, size);
}

int main()
{
	const int SIZE = 20;
	int numbers[SIZE];
	for (int i=0; i<SIZE; i++)
		numbers[i] = rand() % 100;

	displayArray(numbers, SIZE);
	mergesort(numbers, SIZE);
	displayArray(numbers, SIZE);

	system("PAUSE");
	return 0;
}

template<typename T>
void displayArray(T * arr, int size)
{
	for (int i=0; i<size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

