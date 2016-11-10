//Created by Henry Nguyen
//Apirl 17, 2015
//CSCI 2720
//HW#10
//Class containing all sort methods for main.cpp
#include <iostream>
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

void quickSort_hoare(int A[], int p, int r){
  if(p < r){
    int q = hoare(A, p, r);
    quickSort_hoare(A, p, q - 1);
    quickSort_hoare(A, q + 1, r);
  }
}

void quickSort_lomuto(int A[], int p, int r){
  if(p < r){
    int q = lomuto(A, p, r);
    quickSort_lomuto(A, p, q - 1);
    quickSort_lomuto(A, q + 1, r);
  }
}

bool isAscending(int A[], int SIZE){
  for(int i = 0; i < SIZE; i++){
    if(A[i] <= A[i+1]){
      return true;
    }else{
      return false;
    }
  }
}

void print(int A[], int SIZE){
  for(int i = 0; i < SIZE; i++){
    cout << A[i] << " "; 
  }
}

void merge(int A[], int start, int mid, int end){
  int i, j, k;
  int n1 = mid - start + 1;
  int n2 =  end - mid;
 
  int templ[n1], tempr[n2]; //temp arrays
 
  //Copy data to temp arrays 
  for(i = 0; i < n1; i++){
    templ[i] = A[start + i];
  }
  for(j = 0; j < n2; j++){
    tempr[j] = A[mid + 1 + j];
  }

  i = 0;
  j = 0;
  k = start;

  //Merge the two arrays back into A[]
  while (i < n1 && j < n2){
    if (templ[i] <= tempr[j]){
      A[k] = templ[i];
      i++;
    }else{
      A[k] = tempr[j];
      j++;
    }
    k++;
  }
  while (i < n1){
    A[k] = templ[i];
    i++;   
    k++;
  }
  while (j < n2){
    A[k] = tempr[j];
    j++;
    k++;
  }
}

void mergeSort(int A[], int start, int end){
    if (start < end){
        int mid = start + (end-start)/2; 
        mergeSort(A, start, mid);
        mergeSort(A, mid+1, end);
        merge(A, start, mid, end);
    }
}

void bubbleSort(int A[], int SIZE){
  int tmp;
  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE - i; j++){
      if(A[j] > A[j+1]){
        tmp = A[j];
        A[j] = A[j+1];
        A[j+1] = tmp;
      }
    }
  }
}

void countsort(int* A, int SIZE, int* B, int shift){
  int C[0x100] = {0};
  int tuple;
  for(int i = 0; i < SIZE; i++){
    tuple = (A[i] >> shift) & 0xFF;
    C[tuple]++;
  }
  for(int j = 1; j < 0x100; j++){
    C[j] = C[j] + C[j-1];
  }
  for(int i = SIZE-1; i >= 0; i--){
    tuple = (A[i] >> shift) & 0xFF;
    B[C[tuple]-1] = A[i];
    C[tuple]--;
  }
}

void radixSort(int* A, int SIZE){
  int* B = new int[SIZE];
  for(int shift = 0; shift <32; shift += 8){
    if(shift == 0 || shift == 16){
      countsort(A, SIZE, B, shift);
    }else{
      countsort(B, SIZE, A, shift);
    }
  }
  delete[] B;
}



 