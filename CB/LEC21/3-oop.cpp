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
            cout << "\nParamaterized Constructor" << endl;
            namePtr = new string;
            *namePtr = name;
            this->age = age;
            this->gender = gender;
            this->credits = credits;
        }

        void print()
        {
            cout << *namePtr << endl;
            cout << age << endl;
            cout << gender << endl;
            cout << credits << endl;
        }
        
        ~customer(){ //tilde, only one destructor, used to free memory, when obj goes out of scope
            cout << "Object destroyed" << endl;
            delete namePtr;
        }
        int operator+(customer c)
        {
            return age + c.age;
        }


        int operator*(customer c)
        {
            return age * c.age;
        }
};

void add(customer& c) // customer obj is by defualt pass by value.
{
    c.age++;
}

//why anyone create non member operator overloading ??

int main()
{
    customer c1("Abhay Raj",22,'M',26); //parameterazied constructor will be invoked
    customer c2("ABC",21,'M',1000); //parameterazied constructor will be invoked

    cout << (c1.operator*c2) << endl; // c1.operator + c2
    
}