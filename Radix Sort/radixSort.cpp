//Created by Henry Nguyen
//April 8, 2015
//CSCI 2720
//HW#9
//Radix Sort
//
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

void printArr(string arr[], int n){ //n = size of arr
	for(int i = 0; i < n; i++){
		if(i < n - 1){
			cout << arr[i] << " ";
		}else{
			cout << arr[i] << endl;
		}
	}
}

void radixSort(string arr[], int n){ //n = size of arr
	for(int i = n-1; i >= 0; i--){
		vector<vector<string > > vec(256, vector<string>(0, ""));
		for(int j = 0; j < n; j++){  //j = index of arr
			string str = arr[j];
			char digit = str[i];
			int digi = digit;
			vec[digi].push_back(arr[j]);
		} 

		int dataIdarr = 0;

		for(int qIndearr = 0; qIndearr < 256; qIndearr++){
			while(!vec[qIndearr].empty()){
				arr[dataIdarr] = vec[qIndearr][0];
				vec[qIndearr][0]= move(vec[qIndearr].back());
				vec[qIndearr].pop_back();
				dataIdarr++;
			}
		}
	}
}

int main(){

	string words[] = { 
		"cow", "dog", "sea", "rug", "row", "mob", "box", "tab", 
    	"bar", "ear", "tar", "dig", "big", "tea", "now", "fox"
  	}; 

	int arrSize = (sizeof(words) / sizeof(words[0])); //arrSize = the length of array
	printArr(words, arrSize);	//prints original array
	radixSort(words, arrSize);
	printArr(words, arrSize);	//prints sorted array
	
	//return EXIT_SUCCESS;
} 
