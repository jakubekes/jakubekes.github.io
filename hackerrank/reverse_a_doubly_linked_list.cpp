#include <iostream>
#include <limits>
#include <fstream>
#include <string>

class DoublyLinkedListNode {
	public:
		int data;
		DoublyLinkedListNode* next;
		DoublyLinkedListNode* prev;

		DoublyLinkedListNode(int node_data) {
			this->data = node_data;
			this->next = nullptr;
			this->prev = nullptr;
		}
};

class DoublyLinkedList {
	public:
		DoublyLinkedListNode* head;
		DoublyLinkedListNode* tail;

		DoublyLinkedList() {
			this->head = nullptr;
			this->tail = nullptr;
		}

		void insert_node(int node_data) {
			DoublyLinkedListNode* node = new DoublyLinkedListNode(node_data);

			if (!this->head) {
				this->head = node;
			}
			else {
				this->tail->next = node;
				node->prev = this->tail;
			}

			this->tail = node;
		}
};

void print_doubly_linked_list(DoublyLinkedListNode* node, std::string sep, std::ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_doubly_linked_list(DoublyLinkedListNode* node) {
    while (node) {
        DoublyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {

    if (llist == NULL || llist->next == NULL)return llist;

    DoublyLinkedListNode* temp;
    temp = llist->next;
    llist->next = NULL;
    llist->prev = temp;
    llist = llist->prev;

    while (llist != NULL) {
        temp = llist->next;
        llist->next = llist->prev;
        llist->prev = temp;
        temp = llist;
        llist = llist->prev;
    }

    return temp;
}

int main()
{
    std::ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    std::cin >> t;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        DoublyLinkedList* llist = new DoublyLinkedList();

        int llist_count;
        std::cin >> llist_count;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        for (int i = 0; i < llist_count; i++) {
            int llist_item;
            std::cin >> llist_item;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            llist->insert_node(llist_item);
        }

        DoublyLinkedListNode* llist1 = reverse(llist->head);

        print_doubly_linked_list(llist1, " ", fout);
        fout << "\n";

        free_doubly_linked_list(llist1);
    }

    fout.close();

    return 0;
}