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

    void levelOrder(Node * root) {
        std::stack<Node*>st, level_st;
        Node* temp;
		
        if (root!=NULL){
            st.push(root);
            std::cout<<root->data<<" ";
        }
        
        while (!st.empty()){         
            while (!st.empty()){
                temp=st.top();                
                if(temp->right!=NULL)level_st.push(temp->right);
                if(temp->left!=NULL)level_st.push(temp->left);
                st.pop();
            }
            
            while (!level_st.empty()){
				st.push(level_st.top());
				std::cout<<level_st.top()->data<<" ";
				level_st.pop();
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
  
	myTree.levelOrder(root);
    return 0;
}