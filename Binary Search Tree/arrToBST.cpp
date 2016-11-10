//Created by Henry Nguyen
//April 8, 2015
//CSCI 2720
//HW#9
//Sorted array to BST method
//
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

struct TreeNode* arrToBST(int arr[], int head, int tail){
	int mid;
	if(head > tail){
		return NULL;
	}
	if((tail-head)%2 == 0){
		mid = head + (tail-head)/2; 
	}else{
		mid = head + (tail-head)/2+1;
	}
	struct TreeNode* root = new struct TreeNode(arr[mid]);
	root->left = arrToBST(arr, head, mid-1);
	root->right = arrToBST(arr, mid+1, tail);
	return root;
}

void preOrder(struct TreeNode* node){ //prints BST in pre-order 
	if(node == NULL){
		return;
	}
	cout << node->val << " ";
	preOrder(node->left);
	preOrder(node->right);
}

int main(){
	int arr[] = {1, 2, 3, 4};
	int arrSize = (sizeof(arr) / sizeof(arr[0])); //arrSize = length of array
	struct TreeNode* root = arrToBST(arr, 0, arrSize-1);
	cout << "Sorted array is: ";
	for(int i = 0; i <= arrSize-1; i++){
		cout << arr[i] << " "; 
	}
	cout << endl;
	cout << "Binary search tree in pre-order: ";
	preOrder(root);
	cout << endl;
	return 0;
}