#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};
int computeLenghtIterative(ListNode *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}
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

ListNode *GetKthNodePoint(ListNode *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    ListNode *node = head;
    ListNode *nodekx = head;
    for (int i = 0; i < k; i++)
    {
        nodekx = nodekx->next;
    }

    while (nodekx != NULL && nodekx->next != NULL)
    {
        node = node->next;
        nodekx = nodekx->next;
    }

    return node;
}

int main()
{
    ListNode *head = NULL; // Initialize the head of the linked list

    // insertAtHead(head, 60);
    insertAtHead(head, 50);
    insertAtHead(head, 40);
    insertAtHead(head, 30);
    insertAtHead(head, 20);
    insertAtHead(head, 10);

    printLinkedList(head); // 10 -> 20 -> 30 -> 40 -> 50 -> NULL

    ListNode *mid = GetKthNodePoint(head, 1);

    if (mid != NULL)
    {
        cout << mid->val << endl;
    }
    else
    {
        cout << "Empty Linked list" << endl;
    }
}