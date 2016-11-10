//Created by Henry Nguyen
//April 8, 2015
//CSCI 2720
//HW#9
//Quick sort with Hoare and Lomuto partition
//
#include <iostream>
#include <stdio.h>
using namespace std;

int hoare(int A[], int p, int r){
	int x = A[p]; //x = pivot
	int i = p;
	int j = r;
	while(true){
		while(A[j] > x){
			j--;
		}
		while(A[i] < x){
			i++;
		}
		if( i < j){
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}else{
			return j;
		}
	}
}

int lomuto(int A[], int p, int r){
	int x = A[r]; //x = pivot
	int i = p;
	for(int j = p; j <= r - 1; j++){
		if(A[j] <= x){
			int temp = A[j];
			A[j] = A[i];
			A[i] = temp;
			i++;		
}
	}
	int temp = A[i];
	A[i] = A[r];
	A[r] = temp;
	return i;
}

void hoare_sort(int A[], int p, int r){
	if(p < r){
		int q = hoare(A, p, r);
		hoare_sort(A, p, q - 1);
		hoare_sort(A, q + 1, r);
	}
}

void lomuto_sort(int A[], int p, int r){
	if(p < r){
		int q = lomuto(A, p, r);
		lomuto_sort(A, p, q - 1);
		lomuto_sort(A, q + 1, r);
	}
}

void hoareTester(int A[]){
	int p = 0;
	int r = 2;
	cout << "The array is: ";
	for(int i = 0; i <= 2; i++){
		cout << A[i];	
	}
	cout << endl;
	hoare_sort(A, p, r);
	cout << "After Hoare's partition the array is now: ";
	for(int i = 0; i <= 2; i++){
		cout << A[i];
	}
	cout << endl;
}

void lomutoTester(int A[]){
	int p = 0;
	int r = 2;
	cout << "The array is: ";
	for(int i = 0; i <= 2; i++){
		cout << A[i];
	}
	cout << endl;
	lomuto_sort(A, p, r);
	cout << "After Lomuto's partition the array is now: ";
	for(int i = 0; i <= 2; i++){
		cout << A[i];
	}
	cout << endl;
}
int main(){
	int arr[] = {1, 2, 3};
	int arr1[] = {1, 3, 2};
	int arr2[] = {2, 1, 3};
	int arr3[] = {2, 3, 1};
	int arr4[] = {3, 1, 2};
	int arr5[] = {3, 2, 1};
	int ar[] = {1, 2, 3};
	int ar1[] = {1, 3, 2};
	int ar2[] = {2, 1, 3};
	int ar3[] = {2, 3, 1};
	int ar4[] = {3, 1, 2};
	int ar5[] = {3, 2, 1};
	hoareTester(arr);
	hoareTester(arr1);
	hoareTester(arr2);
	hoareTester(arr3);
	hoareTester(arr4);
	hoareTester(arr5);
	lomutoTester(ar);
	lomutoTester(ar1);
	lomutoTester(ar2);
	lomutoTester(ar3);
	lomutoTester(ar4);
	lomutoTester(ar5);

}
