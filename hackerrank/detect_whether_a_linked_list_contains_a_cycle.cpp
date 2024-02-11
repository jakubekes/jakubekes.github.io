#include <iostream>
#include <limits>
#include <fstream>
#include <string>

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, std::string sep, std::ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

bool has_cycle(SinglyLinkedListNode* head) {

    if (head==NULL) return 0;
    
    SinglyLinkedListNode* keep = head;
    SinglyLinkedListNode* temp;
    
    while(head->next!=NULL)
    {
        head=head->next;
        temp=keep;
        
        while(temp!=head){
           if(head->next==temp)return 1; 
           temp=temp->next;
        }
    }
    
    return 0;
}

int main()
{
    std::ofstream fout(getenv("OUTPUT_PATH"));

    int tests;
    std::cin >> tests;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
        int index;
        std::cin >> index;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        SinglyLinkedList* llist = new SinglyLinkedList();

        int llist_count;
        std::cin >> llist_count;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        for (int i = 0; i < llist_count; i++) {
            int llist_item;
            std::cin >> llist_item;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            llist->insert_node(llist_item);
        }
      
      	SinglyLinkedListNode* extra = new SinglyLinkedListNode(-1);
      	SinglyLinkedListNode* temp = llist->head;
      
      	for (int i = 0; i < llist_count; i++) {
            if (i == index) {
          		extra = temp;
            }
          	
          	if (i != llist_count-1) {
          		temp = temp->next;
            }
        }
      
      	temp->next = extra;

        bool result = has_cycle(llist->head);

        fout << result << "\n";
    }

    fout.close();
	
    return 0;
}