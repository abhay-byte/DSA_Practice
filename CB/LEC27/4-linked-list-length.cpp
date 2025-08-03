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

int computeLenghtRecursive(ListNode *head)
{
    //base case: 
    //if the list is empty, return 0
    if (head == NULL)
        return 0; 

    // Recursive case: 
    //count the current node and recurse for the next node
    int val = computeLenghtRecursive(head->next); 

    return 1 + val; // Count the current node and recurse for the next node
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
    
    cout << computeLenghtIterative(head) << endl;
    cout << computeLenghtRecursive(head) << endl; // Print the length of the linked list
}