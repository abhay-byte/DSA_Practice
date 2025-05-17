#include<vector>
#include<iostream>
#include<set>
using namespace std;

class Solution {
    public:

        long long calculateScore(vector<string>& instructions, vector<int>& values) {
            
            long long val = 0;
            long index = 0;
            set<int> visited_index;
            visited_index.insert(0);
            bool loop = true;

            while(loop)
            {
                try{
                    if (index < 0 || index >= instructions.size()) {
                        break;
                    }

                        if(instructions[index] == "add")
                        {
                            val += values[index];
                            index++;
                        }
                        else if (instructions[index] == "jump")
                        {
                            int temp = values[index];
                            index += temp;
                        }

                        if(visited_index.insert(index).second == false)
                        {
                            break;
                        }
                    
                }
                catch (exception e)
                {
                    break;
                }


            }
            return val;

        }
    };