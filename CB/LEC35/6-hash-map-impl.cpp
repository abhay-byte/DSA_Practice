#include <iostream>

using namespace std;

class node
{
public:
    int k;
    int v;
    node *next;

    node(int k, int v)
    {
        this->k = k;
        this->v = v;
        this->next = NULL;
    }
};

class HashMap
{
    int N;    // to store hashtable capacity
    int M;    // to store hashtable size
    double L; // to store the load factor threshold

    node **T; // to store the pointer to the dynamic
    // array that represent the hashtable

    int hashFn(int K)
    {
        // transform k into hash index
        return K * N;
    }

public:
    HashMap(int N = 5, double L = 0.7)
    {
        this->N = N;
        this->M = M;
        this->L = L;

        T = new node *[N];
        for (int i = 0; i < N; i++)
        {
            T[i] = NULL;
        }
    }

    void insert(int K, int V)
    {
        // transform into hash index
        int hashIdx = hashFn(K);

        // create node with k,v
        node *n = new node(K, V);

        //inserting into LL
        n->next = T[hashIdx];
        T[hashIdx] = n;
        M++;

        // rehash if load factor exceeds

        double LF = (double)M / N;
        if (LF > L)
        {
            //        rehash();
        }
    }

    node *find(int K)
    {
        //get hashindex
        int hashIdx = hashFn(K);

        //search for the node with given key
        node* temp = T[hashIdx];
        while(temp != NULL)
        {
            if(temp != NULL)
            {
                break;
            }
            temp = temp->next;
        }

        return temp;
    }

    void erase(int K)
    {
        //get hashindex
        int hashIdx = hashFn(K);

        //delete the node with the key
        node* temp = T[hashIdx];
        if(temp == NULL)
        {
            //if key doest exists
            return;
        }
        else{
            if(temp->k == K)
            {
                T[hashIdx] = temp->next;
                delete(temp);
                N--;
            }
            else
            {
                //delete node which is node head node;
                node* prev = NULL;
                while(temp != NULL)
                {
                    if(temp->k == K)
                    {
                        prev->next = temp->next;
                        delete(temp);
                        M--;
                        break;
                    }
                    prev = temp;
                    temp = temp->next;
                }

            }
        }
    }

    void printLinkedList(node *head)
    {
        while (head != NULL)
        {
            cout << "{" << head->k << "," << head->v << "} ";
            head = head->next;
        }
        cout << endl;
    }

    void printHashMap()
    {
        for (int i = 0; i < N; i++)
        {
            cout << i << " ";
            printLinkedList(T[i]);
        }
        cout << endl;
    }
};

int main()
{
    HashMap hm;

    hm.insert(2,4);
    hm.insert(7,49);
    hm.insert(3,9);

    hm.printHashMap();

    node* n = hm.find(2);
}