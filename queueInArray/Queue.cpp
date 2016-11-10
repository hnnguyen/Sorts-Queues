//Created By Henry Nguyen
//February 11, 2015
//hnnguyen@uga.edu
//CSCI 2720
//hw4 Poblem #3
//

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <list>
using namespace std;

struct node{
	
	int data;
	struct node* next;
};

node* head = new node;
node* tail = new node;

void  enqueue(int value){	
	node* temp = new node;
	temp->data = value;
	temp->next = 0;
	if(head == 0){
		head = temp;
	}else{
		tail->next = temp;
	} 	
	tail = temp;
}

void dequeue(){
	if(head == NULL){
		return;
	}
	if(head == tail){
		head = tail = NULL;
	}else{
		head = head->next;
	}	
}

int main(){
	node* temp = new node;
	node* temp1 = new node;
	node* temp2 = new node;
	temp = tail;
	temp1 = tail;
	temp2 = tail;
	
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);

	for(int i = 0; i < 5; i++){
		if(temp->data != 0){
			cout << temp->data << endl;
		}
		temp = temp->next;
	}
	dequeue();
	dequeue();
	for(int i = 0; i < 5; i++){
		if(temp1->data != 0){
			cout << temp1->data << endl;
		}
		temp1 = temp1->next;
	}

}