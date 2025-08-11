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

void RemoveCycle(ListNode *head)
{ //assuming linked list having >= 2 nodes
    ListNode *slow = head;
    ListNode *fast = head;

    while (true)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
        {
            break;
        }
    }
    ListNode *prev = head;
    while (prev->next != fast)
    {
        prev = prev->next;
    }

    slow = head;

    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
        prev = prev->next;
    }

    prev->next = NULL;
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
int main()
{
    ListNode *head = new ListNode(10); // Initialize the head of the linked list

    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);
    head->next->next->next->next = new ListNode(50);
    head->next->next->next->next->next = head->next->next;

    RemoveCycle(head);

    printLinkedList(head);
}