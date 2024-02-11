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

		void postOrder(Node *root) {

			std::stack <Node*> st;
			std::stack <Node*> st_left;
			Node* temp;
			
			while (root!=NULL){
				st.push(root);
				if(root->left!=NULL)st_left.push(root->left);
				root=root->right;
			}
			
			temp=st_left.top();
			st_left.pop();
			
			while(!st_left.empty() || temp!=NULL) {
				st.push(temp);
				if(temp->left!=NULL) st_left.push(temp->left);
				temp=temp->right;

				if(temp==NULL && !st_left.empty()){
					temp=st_left.top();
					st_left.pop();
				}
			}

			while(!st.empty()) {
				std::cout << st.top()->data << " ";
				st.pop();
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
  
	myTree.postOrder(root);
    return 0;
}