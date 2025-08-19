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
	ListNode* slow = head;
	ListNode* fast = head;

	while (fast != NULL and fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			// you've found a cycle
			return true;
		}
	}

	// no cycle found
	return false;

}

int main()
{
    ListNode *head = new ListNode(10); // Initialize the head of the linked list

    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);
    head->next->next->next->next = new ListNode(50);
    //head->next->next->next->next->next = head->next->next;

    cout << DetectCycle(head) << endl;
}