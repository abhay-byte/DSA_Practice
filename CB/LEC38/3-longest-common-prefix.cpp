#include <iostream>
#include <unordered_map>
using namespace std;

class node
{
public:
    char ch;
    bool terminal;
    int freq;
    unordered_map<char, node *> childMap;

    node(char ch)
    {
        this->ch = ch;
        this->terminal = false;
        this->freq = 0;
    }
};

class trie
{
    node *root;

public:
    trie()
    {
        root = new node('#');
    }

    void insert(string str)
    {
        node *cur = root;
        for (char ch : str)
        {
            if (cur->childMap.find(ch) == cur->childMap.end())
            {
                // cur node doesnt have a child node with the value ch
                cur->childMap[ch] = new node(ch);
            }
            cur = cur->childMap[ch];
            cur->freq++;
        }
        cur->terminal = true;
    }

    // time: O(len(str))
    string longestCommonPrefix(string word,int n)
    {
        string ans;
        node *cur = root;

        for (char ch : word)
        {
            cur = cur->childMap[ch];
            if (cur->freq != n)
            {
                break;
            }
            ans += ch;
        }
        return "";
    }
};

int main()
{
    string words[] = {"fly", "flying", "floor", "flys"};

    trie t;
    for (string word : words)
    {
        t.insert(word);
    }

    cout << "Longest Common Prefix: " << t.longestCommonPrefix(words[0], 3) << endl;

    return 0;
}