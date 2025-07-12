#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class customer{
    public:
        string name;
        int age;
        char gender;
        double credits;

        customer()
        {
            cout << "\nI am inside the default constructor" << endl;
        }

        customer(string name, int age, char gender, double credits)
        {  
            cout << "\nParamaterized Constructor" << "\n";
            this->name = name;
            this->age = age;
            this->gender = gender;
            this->credits = credits;
        }

        void print()
        {
            cout << name << "\n";
            cout << age << "\n";
            cout << gender << "\n";
            cout << credits << "\n";
            cout << "\n";
        }
        
        ~customer(){ //tilde, only one destructor, used to free memory, when obj goes out of scope
            cout << "Object destroyed" << "\n";
        }
};

void add(customer& c) // customer obj is by defualt pass by value.
{
    c.age++;
}

bool ageCmp(customer a, customer b)
{
    if(a.age > b.age)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

int main()
{
    vector<customer> v1;

    v1.push_back(customer("Abc",100,'M',20));
    v1.push_back(customer("efg",50,'M',20));
    v1.push_back(customer("hij",65,'M',20));
    v1.push_back(customer("lpm",110,'M',20));

    sort(v1.begin(),v1.end(),ageCmp);

    for(customer obj: v1)
    {
        obj.print();
    }


    
}
