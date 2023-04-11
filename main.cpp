#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;
const int SIZE = 19;


int getMinimumIndex(int matrix[SIZE], int size) {
	int currentMinimum = 0;
	for (int i = 0; i < size; i++) {
		if (matrix[i] < matrix[currentMinimum]) {
			currentMinimum = i;
		}
	}
	return currentMinimum;
}

void changeArray(int (&matrix)[SIZE][SIZE], int size, int rowToPaste, int rowToCopy) {
	rowToPaste--;
	rowToCopy--;
	for (int i = 0; i < size; i++) {
		matrix[rowToPaste][i] = matrix[rowToCopy][i];
	}
}
int getSum(int matrix[][SIZE], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (((i + j) >= (size - 1))&&(matrix[i][j] < 0)) {
				sum += matrix[i][j];
			}
		}
	}
	return sum;
}

int main(int argc, char** argv) {
	srand(time(NULL));
	int matrix[SIZE][SIZE];
	createArray(matrix, SIZE);
	showArray(matrix, SIZE);
	cout<<"Summs of elems after min element:\n";
	for (int i = 0; i < SIZE; i++) {
		int currentMinimumIndex = getMinimumIndex(matrix[i], SIZE);
		int currentSum = 0;
		for (int j = currentMinimumIndex; j < SIZE; j++) {
			currentSum += matrix[i][j];
		}
		cout<<i+1<<": "<<currentSum<<"\n";
	}
	int rowToCopy,rowToPaste;
	cout<<"Enter a row of matrix to copy data: ";
	cin>>rowToCopy;
	cout<<"Enter a row of matrix to paste data: ";
	cin>>rowToPaste;
	changeArray(matrix,SIZE,rowToPaste,rowToCopy);
	showArray(matrix,SIZE);
	cout<<"Sum of necessary elements: "<<getSum(matrix,SIZE);
}