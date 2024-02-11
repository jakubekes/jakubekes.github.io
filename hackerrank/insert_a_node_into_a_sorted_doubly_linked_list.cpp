#include <iostream>
#include <limits>
#include <fstream>
#include <string>

class DoublyLinkedListNode {
    public:
        int data;
        DoublyLinkedListNode *next;
        DoublyLinkedListNode *prev;

        DoublyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class DoublyLinkedList {
    public:
        DoublyLinkedListNode *head;
        DoublyLinkedListNode *tail;

        DoublyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            DoublyLinkedListNode* node = new DoublyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
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

DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    
    DoublyLinkedListNode* temp = llist;
    DoublyLinkedListNode* newnode = new DoublyLinkedListNode(data);
    newnode->data=data;
    
    if (llist==NULL){
        return llist;
    } else if(llist->data>data){
        newnode->next=llist;
        newnode->prev=NULL;
        llist->prev=newnode;
        return newnode;
    } else {
       
        while(temp!=NULL){
            
            if(temp->data>data){
                newnode->next=temp;
                temp=temp->prev;
                temp->next=newnode;
                newnode->prev=temp;
                return llist;
            }
            if (temp->next!=NULL) {
                temp=temp->next;
            }else{
                temp->next=newnode;
                return llist;
            }
        }
    } 
	
 return llist;
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

        int data;
        std::cin >> data;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        DoublyLinkedListNode* llist1 = sortedInsert(llist->head, data);

        print_doubly_linked_list(llist1, " ", fout);
        fout << "\n";

        free_doubly_linked_list(llist1);
    }

    fout.close();

    return 0;
}