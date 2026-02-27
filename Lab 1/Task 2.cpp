#include <iostream>
using namespace std;

class Employee
{
public:
    virtual void calculateSalary() = 0;
};

class FullTimeEmployee : public Employee
{
    string name;
    float salary;
public:
    FullTimeEmployee(string n, float s)
    {
        name = n;
        salary = s;
    }

    void calculateSalary()
    {
        cout << "Full Time employee:" << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }
};

class PartTimeEmployee : public Employee
{
    string name;
    int hw;
    int hr;
public:
    PartTimeEmployee(string n, float h, float r)
    {
        name = n;
        hw = h;
        hr = r;
    }

    void calculateSalary()
    {
        float total = hw * hr;
        cout << "Part Time employee:" << endl;
        cout <<  "Name: " << name << endl;
        cout << "Salary: " << total << endl;
    }
};

int main()
{
    FullTimeEmployee e1("Hamid", 1000);
    PartTimeEmployee e2("Hussain", 12, 100);
    e1.calculateSalary();
    e2.calculateSalary();

    return 0;
}