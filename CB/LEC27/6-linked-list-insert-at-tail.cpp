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

ListNode *getTailNode(ListNode *head)
{
    while (head->next != NULL)
    {
        head = head->next;
    }
    return head;
}

void insertAtTail(ListNode *&head, int val)
{
    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }
    ListNode *n = new ListNode(val);
    ListNode *tail = getTailNode(head);
    tail->next = n;
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

    insertAtTail(head, 60);
    printLinkedList(head);
}