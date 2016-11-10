//Created By Henry Nguyen
//Februaary 11, 2015
//hnnguyen@uga.edu
//CSCI 2720 HW #4
//Problem 2
//
#include<stdio.h>
#include<stdlib.h>
using namespace std;

/*Node for list*/
struct node{
	
	int data;
	struct node* next;
};

void moveNode(struct node** des, struct node** src);

/* Merging sorted lists method */
struct node* sortMerge(struct node* a, struct node* b){
	
	struct node temp;
	struct node* end = &temp;

	temp.next = NULL;
	while(1){
		if(a == NULL){
			end->next = b;
			break;
		}else if( b == NULL){
			end->next = a;
			break;
		}
		if(a->data <= b->data){
			moveNode(&(end->next), &a);
		}else{
			moveNode(&(end->next), &b);
		}
		end = end->next;
	}
	return(temp.next);
}
/*Moves the nodes to correct order*/
void moveNode(struct node** des, struct node** src){
	
	struct node* newNode = *src;
	*src = newNode->next;
	newNode->next = *des;
	*des = newNode;
}
/* Push Method to add to list*/
void push(struct node** headRef, int newValue){
	
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	newNode->data = newValue;
	newNode->next = (*headRef);
	(*headRef) = newNode;
}
/* Method to print the list*/
void printList(struct node *head){
	
	struct node *temp = head;
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

int main(){
	struct node* head = NULL;
	struct node* l1 = NULL;
	struct node* l2 = NULL;
	
	push(&l1, 3);
	push(&l1, 2);
	push(&l1, 1);

	push(&l2, 6);
	push(&l2, 5);
	push(&l2, 4);
	printList(l1);
	printf("\n");
	printList(l2);
	printf("\n");
	head = sortMerge(l1, l2);
	printList(head);
	printf("\n");
}
