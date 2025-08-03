#include<iostream>

using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

int main()
{
    ListNode* n = new ListNode(10);

    cout << n->val << endl;

    if(n->next == nullptr) {
        cout << "Next node is null" << endl;
    } else {
        cout << "Next node value: " << n->next->val << endl;
    }
}