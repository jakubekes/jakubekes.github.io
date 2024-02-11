#include <iostream>
#include <stack>

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
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }
               return root;
           }
        }

		void preOrder(Node *root) {
			
			Node* temp;
			std::stack<Node*>st;        
					
			while (root!=NULL){
				std::cout<<root->data<<" ";
				if(root->left==NULL) {
					root=root->right;
				} else {
					temp=root->left;
					root=root->right;
					while(temp!=NULL || !st.empty()){
						if(temp->left!=NULL){
							if(temp->right!=NULL) st.push(temp->right);
							std::cout<<temp->data<<" ";               
							temp=temp->left;                       
						}else {
							std::cout<<temp->data<<" ";
							temp=temp->right;
						  
							if (temp==NULL && !st.empty()){
									temp=st.top();
									st.pop();
							}        
						}
					}  
				}
			}
		}
}; //End of Solution

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