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


bool DetectCycle(ListNode *head)
{
    set<ListNode *> set;

    ListNode *node = head;

    set.insert(node);

    while (node != NULL)
    {
        node = node->next;
        if (set.find(node) != set.end())
        {
            return false;
        }
        else
        {

            set.insert(node);
        }
    }
    return true;
}

int main()
{
    ListNode *head = new ListNode(10); // Initialize the head of the linked list

    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);
    head->next->next->next->next = new ListNode(50);
    // head->next->next->next->next->next = head->next->next;

    cout << DetectCycle(head) << endl;
}