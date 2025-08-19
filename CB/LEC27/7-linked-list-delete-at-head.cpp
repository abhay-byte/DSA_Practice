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

// time: O(n)
// space: O(1)

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

int main()
{
    ListNode *head = NULL; // Initialize the head of the linked list

    insertAtHead(head, 50);
    insertAtHead(head, 40);
    insertAtHead(head, 30);
    insertAtHead(head, 20);
    insertAtHead(head, 10);

    printLinkedList(head); // 10 -> 20 -> 30 -> 40 -> 50 -> NULL

    deleteAtHead(head);

    printLinkedList(head);

    deleteAtHead(head);

    printLinkedList(head);
}