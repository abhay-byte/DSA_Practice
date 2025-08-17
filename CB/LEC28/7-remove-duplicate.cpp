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

ListNode *RemoveDuplicate(ListNode *head)
{
    if (!head || !head->next) // empty or single-node list
        return head;

    ListNode *prev = head;
    ListNode *cur = head->next;

    while (cur != nullptr)
    {
        if (cur->val != prev->val)
        {
            prev->next = cur;
            prev = cur;
        }
        cur = cur->next;
    }

    prev->next = nullptr;
    return head;
}


class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head || !head->next) // empty or single-node list
            return head;

        ListNode *prev = head;
        ListNode *cur = head->next;

        while (cur != nullptr)
        {
            if (cur->val != prev->val)
            {
                prev->next = cur;
                prev = cur;
            }
            cur = cur->next;
        }

        prev->next = nullptr;
        return head;
    }
};

int main()
{
    ListNode *head = NULL;
    insertAtHead(head, 50);
    insertAtHead(head, 50);
    insertAtHead(head, 30);
    insertAtHead(head, 30);
    insertAtHead(head, 10);
    insertAtHead(head, 10);
    insertAtHead(head, 10);

    printLinkedList(head);

    head = RemoveDuplicate(head);

    printLinkedList(head);
}