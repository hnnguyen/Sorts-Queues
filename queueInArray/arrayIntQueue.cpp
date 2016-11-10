//arrayIntQueue.cpp
//Created by Henry Nguyen
//February 26, 2015
//CSCI 2720 HW6
//

#include "arrayIntQueue.h"
#include <stdexcept>
#include <iostream>
#include <stdlib.h>
using namespace std;

queue::queue(){
	f = -1;
	r = -1;
	arr = new int[capacity];
}

queue::queue(int capacity2){
	f = -1;
	r = -1;
	capacity = capacity2;
	arr = new int[capacity];

}

queue::~queue(){
	delete []arr;
}

void queue::push(int value){
	if(n == 0){
		f = 0;
		r = 0;
		arr[r] = value;
		n++;
	}else if(((r+1) % capacity) != f){
		r = (r+1) % capacity;
		arr[r] = value;
		n++;
	}
}

void queue::pop(){
	if(empty()){
		cout << "Queue is empty" << endl;
	}else if(f == r){
		f = r = -1;
		n--;
	}else{
		f = (f+1) % capacity;
		n--;
	}
}

int queue::front(){
	if(n > 0){
		return arr[f];
	}
}

int queue::back(){
	return arr[r];
}

int queue::size(){
	return n;
}

bool queue::empty(){
	if(n == 0){
		return true;
	}else{
		return false;
	}
}

void queue::print(){
	int ftemp = f;
	int ntemp = n;

	while(ntemp > 0){
		cout << arr[ftemp] << " ";
		ftemp = (ftemp + 1) % capacity;
		ntemp--;
	}	
	cout << endl;
}
