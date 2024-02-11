#include <iostream>

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
		void preOrder(Node *root) {
			
			if( root == NULL ) return;
		  
			std::cout << root->data << " ";
			
			preOrder(root->left);
			preOrder(root->right);
		}

		Node * insert(Node * root, int data) {
			Node* n = new Node(data);
			if(root==NULL) return n;
			Node* temp=root;
			
			while(temp!=n){
				if(data<temp->data && temp->left!=NULL){
					temp=temp->left;
				} else if (data>temp->data && temp->right!=NULL){
					 temp=temp->right;
				} else if (data<temp->data && temp->left==NULL){
					temp->left=n;
					temp=temp->left;
				} else if (data>temp->data && temp->right==NULL){
					temp->right=n;
					temp=temp->right;
				}
			}
			return root;
		}
};

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  	
    myTree.preOrder(root);
  
    return 0;
}