#include <iostream>
using namespace std;

template <typename T>
class ListNode
{
public:
    T val;
    ListNode *next;

    ListNode(T x) : val(x), next(NULL) {}
};

template <typename T>
class Stack
{
    ListNode<T> *head = NULL;
    ListNode<T> *topNode = NULL;
    int count = 0;  // track number of elements

public:
    void push(T val)
    {
        // Instead of inserting at tail, we insert at head for O(1) push/pop
        ListNode<T> *node = new ListNode<T>(val);
        node->next = head;
        head = node;
        topNode = node; // head is always top
        count++;
    }

    void pop()
    {
        if (head != NULL)
        {
            ListNode<T> *temp = head;
            head = head->next;
            delete temp;
            count--;
            if (head != NULL)
                topNode = head;
            else
                topNode = NULL;
        }
        else
        {
            cout << "Stack is empty, cannot pop." << endl;
        }
    }

    int size()
    {
        return count;
    }

    T top()
    {
        if (topNode != NULL)
            return topNode->val;
        throw runtime_error("Stack is empty. No top element.");
    }

    bool empty()
    {
        return count == 0;
    }
};

int main()
{
    Stack<int> s;

    cout << "size: " << s.size() << endl;
    cout << "isEmpty ? " << s.empty() << endl;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    while (!s.empty())
    {
        cout << "size: " << s.size() << endl;
        cout << "top: " << s.top() << endl;
        cout << "isEmpty ? " << s.empty() << endl;
        s.pop();
    }
}
