#include <iostream>
#include <set>

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

//time: O(m+n) 
//space: O(1)

ListNode *MergeSortedLinkedList(ListNode *head1, ListNode *head2)
{
    ListNode *dummy = new ListNode(0);
    ListNode *temp = dummy;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->val < head2->val)
        {
            temp->next = head1;
            temp = temp->next;
            head1 = head1->next;
        }
        else
        {
            temp->next = head2;
            temp = temp->next;
            head2 = head2->next;
        }
    }

    if (head1 != NULL)
    {
        temp->next = head1;
    }

    if (head2 != NULL)
    {
        temp->next = head2;
    }

    return dummy->next;
}

int main()
{
    ListNode *head1 = NULL;
    insertAtHead(head1, 50);
    insertAtHead(head1, 30);
    insertAtHead(head1, 10);

    printLinkedList(head1);

    ListNode *head2 = NULL;
    insertAtHead(head2, 60);
    insertAtHead(head2, 40);
    insertAtHead(head2, 20);

    printLinkedList(head2);

    ListNode *head = MergeSortedLinkedList(head1, head2);

    printLinkedList(head);
}