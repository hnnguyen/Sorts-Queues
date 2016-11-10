//Created By Henry Nguyen
//February 3, 2015
//CSCI HW#3 Problem 1: Bubble sort

#include <iostream> 
using namespace std;

void bubbleSort(int arr[], int size);


void bubbleSort(int arr[], int size) {
	int i, j, tmp;
	for(i = 0; i < (size - 1); i++){
		for(j = 0; j < size - i - 1; j++){
			if(arr[j] > arr[j+1]){
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
}

int main(){
	int array[] = {5, 3, 6, 1, 2, 7, 4, 0, 9, 8};
	bubbleSort(array, 10);
	for(int i = 0; i < 10; i++){
		cout << array[i] << endl;
	}
}
