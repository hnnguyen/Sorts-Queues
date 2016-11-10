//Created By Henry Nguyen
//Februaary 11, 2015
//hnnguyen@uga.edu
//CSCI 2720 HW #4
//Problem 1
//
#include<stdio.h>
#include<stdlib.h>
using namespace std;

/* Node for list*/
struct node{
	
	int data;
	struct node* next;
};
/* Reverse Method for Problem 1 */
void Reverse(struct node** headRef){

	struct node* prev = NULL;
	struct node* current = *headRef;
	struct node* next;
	while(current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*headRef = prev;
}

/* Push Method: adds newValue to the list */
void push(struct node** headRef, int newValue){
	
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	newNode->data = newValue;
	newNode->next = (*headRef);
	(*headRef) = newNode;
}

/* Print Method: Prints the list*/
void printList(struct node *head){
	
	struct node *temp = head;
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

int main(){
	struct node* head = NULL;
	
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);
	printList(head);
	Reverse(&head);
	printf("\n");
	printList(head);
	printf("\n");
}
