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

		void inOrder(Node *root) {
		   
			std::stack<Node*>st;        

			while(root!=NULL || !st.empty()){
				if(root!=NULL){
					if(root->left==NULL){
						std::cout<<root->data<<" ";
						root=root->right;
						if(root==NULL && !st.empty()){
							root=st.top();
							st.pop();
							std::cout<<root->data<<" ";
							root=root->right;
						}
					} else {
						st.push(root);
						root=root->left;
					}
									
				} else {
					root=st.top();
					st.pop();
					std::cout<<root->data<<" ";
					root=root->right;		
				}
			}
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
  
	myTree.inOrder(root);
    return 0;
}