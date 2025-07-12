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
            cout << "\nParamaterized Constructor" << endl;
            this->name = name;
            this->age = age;
            this->gender = gender;
            this->credits = credits;
        }

        void print()
        {
            cout << name << endl;
            cout << age << endl;
            cout << gender << endl;
            cout << credits << endl;
        }
        
        ~customer(){ //tilde, only one destructor, used to free memory, when obj goes out of scope
            cout << "Object destroyed" << endl;
        }
};

void add(customer& c) // customer obj is by defualt pass by value.
{
    c.age++;
}

void print(customer c) // customer obj is by defualt pass by value.
{
    cout << c.name << endl;
    cout << c.age << endl;
    cout << c.gender << endl;
    cout << c.credits << endl;
}

void printC(const customer& c) // customer obj is by defualt pass by value.
{
    cout << c.name << endl;
    cout << c.age << endl;
    cout << c.gender << endl;
    cout << c.credits << endl;
}

int main()
{
    customer c1("Abhay Raj",22,'M',26); //parameterazied constructor will be invoked
    customer c2;
    // c1.name = "Abhay Raj";
    // c1.age = 22;
    // c1.gender = 'M';
    // c1.credits = 26;

    printC(c1); //explicitly passed

    add(c1);

    c1.print(); //implicitly passed
    
}