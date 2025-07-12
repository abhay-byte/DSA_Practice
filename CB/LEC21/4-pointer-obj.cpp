#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class customer{
    public:
        string* namePtr;
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
            namePtr = new string;
            *namePtr = name;
            this->age = age;
            this->gender = gender;
            this->credits = credits;
        }

        void print()
        {
            cout << *namePtr << "\n";
            cout << age << "\n";
            cout << gender << "\n";
            cout << credits << "\n";
            cout << "\n";
        }
        
        ~customer(){ //tilde, only one destructor, used to free memory, when obj goes out of scope
            cout << "Object destroyed" << "\n";
            delete namePtr;
        }
};

void add(customer& c) // customer obj is by defualt pass by value.
{
    c.age++;
}

int main()
{
    customer c1("Abhay Raj",22,'M',26); //parameterazied constructor will be invoked

    cout << &c1 << endl; 

    customer* cptr = &c1; //8B by deafult
    
    cout << "Customer Age:-" << (*cptr).age << "\n";
    
    (*cptr).print(); // first dereference then dot operator.
    cptr->print(); // more easy appoarch

    
}
