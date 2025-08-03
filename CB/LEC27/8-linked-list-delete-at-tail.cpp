#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

void insertAtHead(ListNode *&head, int value)
{
    ListNode *n = new ListNode(value);
    n->next = head; // Point the new node to the current head
    head = n;       // Update the head to the new node
}

void printLinkedList(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl; // Indicate the end of the list
}

void deleteAtHead(ListNode*& head)
{
    if(head==NULL)
    {
        cout << "Empty Linked List";
        return;
    }
    ListNode* temp = head;
    head = head->next;
    delete(temp);
    
}

// time: O(n)
// space: O(1)

void deleteAtTail(ListNode*& head)
{
    if(head==NULL)
    {
        cout << "Empty Linked List" << endl;
        return;
    }

    if(head->next == NULL)
    {
        cout<< "linked list has one node only" << endl;
        deleteAtHead(head);
        return;
    }

    ListNode* prev = NULL;
    ListNode* cur = head;

    while(cur->next!=NULL)
    {
        prev = cur;
        cur = cur->next;
    }
    prev->next = NULL;
    delete(cur);
}

int main()
{
    ListNode *head = NULL; // Initialize the head of the linked list

    insertAtHead(head, 50);
    // insertAtHead(head, 40);
    // insertAtHead(head, 30);
    // insertAtHead(head, 20);
    // insertAtHead(head, 10);

    printLinkedList(head); // 10 -> 20 -> 30 -> 40 -> 50 -> NULL

    deleteAtTail(head);

    printLinkedList(head);

    deleteAtTail(head);

    printLinkedList(head);
}