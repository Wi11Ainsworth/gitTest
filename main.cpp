#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;
const int SIZE = 19;


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