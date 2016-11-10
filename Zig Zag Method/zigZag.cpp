//Created by Henry Nguyen
//April 8, 2015
//CSCI 2720
//HW#9
//Zigzag method
//
#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;

struct TreeNode{	//creates node
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

void zigZag(struct TreeNode* root){
	stack<struct TreeNode*> curr, next;		//creates stack of nodes
	bool iter = true;
	curr.push(root);
	while(!curr.empty()){
		TreeNode* currNode = curr.top();
		curr.pop();
		if(currNode){
			cout << currNode->val << " ";
			if(iter){
				next.push(currNode->left);
				next.push(currNode->right);
			}else{
				next.push(currNode->right);
				next.push(currNode->left);
			}
		}
		if(curr.empty()){
			cout << endl;
			iter = !iter;
			stack<struct TreeNode*> temp;
			temp = curr; //swap curr & next
			curr = next;
			next = temp;
		}
	}
}

int main(){
	struct TreeNode* head = new struct TreeNode(3);
	head->left = new TreeNode(9);
	head->right = new TreeNode(20);
	struct TreeNode* temp = head->right;
	temp->left = new struct TreeNode(15);
	temp->right = new struct TreeNode(7);
	zigZag(head);
	
	struct TreeNode* head2 = new struct TreeNode(1);
	head2->left = new TreeNode(2);
	head2->right = new TreeNode(3);
	struct TreeNode* temp2 = head2->left;
	temp2->left = new struct TreeNode(4);
	temp2->right = new struct TreeNode(5);
	zigZag(head2);

	struct TreeNode* head3 = new struct TreeNode(1);
	head3->left = new TreeNode(2);
	head3->right = new TreeNode(3);
	struct TreeNode* temp3 = head3->left;
	struct TreeNode* temp4 = head3->right;
	temp3->left = new struct TreeNode(4);
	temp4->right = new struct TreeNode(5);
	zigZag(head3);

	
}