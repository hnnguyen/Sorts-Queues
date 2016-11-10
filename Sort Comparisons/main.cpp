#include <iostream>
#include <cstdlib> //RAND_MAX
#include <ctime> //clock
#include <algorithm> //sort
#include "sortMethods.cpp" //class containing all sort methods
using namespace std;

int main(){
  //RAND_MAX = 2147483647
  const int SIZE = 1000000;
  int *arrQH = new int[SIZE]; //arrQH is the array for quick sort using Hoare's partition.
  int *arrQL = new int[SIZE]; //arrQL is the array for quick sort using Lomuto's partition.
  int *arrB = new int[SIZE]; //arrB is the array for bubble sort
  int *arrS = new int[SIZE]; //System provide sorting library
  int *arrM = new int[SIZE]; //merge sort
  int *arrR = new int[SIZE]; //radix sort

  for (int i = 0; i < SIZE; i++){
    arrR[i] = arrM[i] = arrS[i] = arrQL[i] = arrQH[i] = rand();
    //arrB[i] = rand();
  }

  long start = clock();
  quickSort_hoare(arrQH, 0, SIZE-1);
  long end = clock();
  if (isAscending(arrQH, SIZE))
    cout << "quick sort using Hoare's partition: " << (end - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;
  //print(arrQH, SIZE);

  start = clock();
  quickSort_lomuto(arrQL, 0, SIZE-1);
  end = clock();
  if (isAscending(arrQL, SIZE))
    cout << "quick sort using Lomuto's partition: " << (end - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;
  //print(arrQL, SIZE);

  /*
  start = clock();
  bubbleSort(arrB, SIZE-1);
  end = clock();
  if (isAscending(arrB, SIZE))
    cout << "bubble sort: " << (end - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;
  //print(arrB, SIZE);
  */

  start = clock();
  mergeSort(arrM, 0, SIZE-1);
  end = clock();
  if (isAscending(arrM, SIZE))
     cout << "merge sort: " << (end - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;
  //print(arrM, SIZE);

  start = clock();
  std::sort(arrS, arrS + SIZE); //sort provided by c++
  end = clock();
  cout << "system provided sort: " << (end - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;
  //print(arrS, SIZE);

  start = clock();
  radixSort(arrR, SIZE);
  end = clock();
  if (isAscending(arrR, SIZE))
    cout << "radix sort: " << (end - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;
  //print(arrR, SIZE);
  
 }
