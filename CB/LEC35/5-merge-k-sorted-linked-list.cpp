#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
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

class ListNodeComp
{
public:
    bool operator()(ListNode *a, ListNode *b)
    {
        // return false if you want to give more priority to b than a;
        if (a->val < b->val)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};

ListNode *mergeKSortedLinkedLists(const vector<ListNode *> &v)
{
    priority_queue<ListNode *, vector<ListNode *>, ListNodeComp> minHeap(v.begin(), v.end());

    ListNode *dummy = new ListNode(0);
    ListNode *temp = dummy;

    while(!minHeap.empty())
    {
        ListNode* minNode = minHeap.top();
        minHeap.pop();
        temp->next = minNode;
        temp = temp->next;
        if(minNode->next != NULL)
        {
            minHeap.push(minNode->next);
        }
    }

    return dummy->next;
}

int main()
{
    ListNode *head1 = NULL;

    insertAtHead(head1, 70);
    insertAtHead(head1, 40);
    insertAtHead(head1, 10);

    printLinkedList(head1);

    ListNode *head2 = NULL;

    insertAtHead(head2, 80);
    insertAtHead(head2, 50);
    insertAtHead(head2, 20);

    printLinkedList(head2);

    ListNode *head3 = NULL;

    insertAtHead(head3, 90);
    insertAtHead(head3, 60);
    insertAtHead(head3, 30);

    printLinkedList(head3);

    vector<ListNode *> v = {head1,
                            head2,
                            head3};

    ListNode *head = mergeKSortedLinkedLists(v);

    printLinkedList(head);
}