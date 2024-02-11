#include <iostream>
#include <vector>
#include <map>
#include <stack>

class Node {
	public:
		int data;
		Node* left;
		Node* right;
		Node(int d) {
			data = d;
			left = NULL;
			right = NULL;
		}
};

class Solution {
	public:
		Node* insert(Node* root, int data) {
			if (root == NULL) {
				return new Node(data);
			}
			else {
				Node* cur;
				if (data <= root->data) {
					cur = insert(root->left, data);
					root->left = cur;
				}
				else {
					cur = insert(root->right, data);
					root->right = cur;
				}
				return root;
			}
		}

		void topView(Node* root) {
			std::vector<int> temp_int, temp2_int;
			std::vector<Node*> temp_node, temp2_node;
			std::map <int, Node*> my_map;
			int check;
			std::stack<Node*>st, level_st;
			Node* temp;

			if (root != NULL) {
				st.push(root);
				temp_int.push_back(0);
				temp_node.push_back(root);
				my_map.insert({ 0,root });
			}

			while (!st.empty()) {

				while (!st.empty()) {
					temp = st.top();
					if (temp->right != NULL) {
						level_st.push(temp->right);
						temp2_int.push_back(temp_int[temp_int.size() - 1] + 1);
						temp2_node.push_back(temp->right);
					}
					if (temp->left != NULL) {
						level_st.push(temp->left);
						temp2_int.push_back(temp_int[temp_int.size() - 1] - 1);
						temp2_node.push_back(temp->left);
					}
					st.pop();
					temp_int.pop_back();
					temp_node.pop_back();
				}

				while (!level_st.empty()) {
					st.push(level_st.top());
					level_st.pop();
				}

				for (int i = temp2_int.size() - 1; i >= 0; i--) {
					temp_int.push_back(temp2_int[i]);
					temp_node.push_back(temp2_node[i]);
				}

				while (!temp2_int.empty()) {
					check = 0;
					for (auto it = my_map.cbegin(); it != my_map.cend(); ++it) {
						if (it->first == temp2_int[temp2_int.size() - 1]) {
							check = 1;
							break;
						}
					}

					if (check == 0) {
						my_map.insert({ temp2_int[temp2_int.size() - 1],temp2_node[temp2_node.size() - 1] });
					}

					temp2_int.pop_back();
					temp2_node.pop_back();
				}
			}

			for (auto it = my_map.cbegin(); it != my_map.cend(); ++it) {
				std::cout << it->second->data << " ";
			}
		}
}; //End of Solution

int main() {

	Solution myTree;
	Node* root = NULL;

	int t;
	int data;

	std::cin >> t;

	while (t-- > 0) {
		std::cin >> data;
		root = myTree.insert(root, data);
	}

	myTree.topView(root);
	return 0;
}