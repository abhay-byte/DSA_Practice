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

int main()
{
    customer* cptr1 = new customer("Abhay Raj",22,'M',26); //parameterazied constructor will be invoked
    cptr1->print();

    customer* cptr2 = new customer(); //parameterazied constructor will be invoked
    cptr2->name = "abc";
    cptr2->age = 42;
    cptr2->gender = 'F';
    cptr2->credits = 20;
 
    cptr2->print();
    
}
