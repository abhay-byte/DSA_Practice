#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class minHeap
{
    vector<int> v;
    void heapify(int i)
    {
        //fies the property of heap at the node corr, to idx i
        int minIdx = i;

        int leftChildIdx = 2 * i + 1;
        if(v.size() > leftChildIdx && v[leftChildIdx] < v[minIdx])
        {
            minIdx = leftChildIdx;
        }

        int rightChildIdx = 2 * i + 2;
        if(v.size() > rightChildIdx && v[rightChildIdx] < v[minIdx])
        {
            minIdx = rightChildIdx;
        }

        if(minIdx != i)
        {
            //base case is automatic taken
            swap(v[i],v[minIdx]);
            heapify(minIdx);
        }


    }

public:
    //time: O(logn), height of tree
    void push(int val)
    {
        v.push_back(val);
        int childIdx  = v.size() - 1;
        int parentIdx = childIdx % 2 == 0 ? childIdx / 2 - 1 : childIdx / 2;
        while(childIdx != 0 && v[childIdx] < v[parentIdx])
        {
            swap(v[childIdx], v[parentIdx]);
            childIdx = parentIdx;
            parentIdx = childIdx % 2 == 0 ? childIdx / 2 - 1 : childIdx / 2;
        }
    }

    void pop()
    {
        //assume heap is non empty
        swap(v[0], v[v.size() - 1]); // const
        v.pop_back(); //const
        heapify(0); //logn
    }

    int top()
    {
        //assume heap is non empty
        return v[0];
    }

    int size()
    {
        return v.size();
    }

    bool empty()
    {   
        return v.empty();
    }

};

int main()
{
    minHeap m;

    m.push(9);
    m.push(7);
    m.push(8);
    m.push(5);
    m.push(4);
    m.push(6);
    m.push(3);
    m.push(2);
    m.push(1);

    cout << m.size() << endl;

    while(!m.empty())
    {
        cout << m.top() << " ";
        m.pop();
    }

    cout << endl;
    cout << m.size() << endl;
}