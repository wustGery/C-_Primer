#include<iostream>
#include<string>
using namespace std;


class Employee{
    public:
        Employee(){ employ_id=number++;}
        Employee(const string &name)
        {
            employ_id = number++;
            employ_name = name;
        }
        Employee(const Employee &s);
        Employee& operator=(const Employee &rhs);
        void print_employ_info();
    private:
        static int number;
        string employ_name;
        int employ_id;
};

Employee& Employee::operator=(const Employee &rhs)
{
    cout<<"调用了拷贝赋值函数"<<endl;
    employ_name = rhs.employ_name;
    return *this;
}

Employee::Employee(const Employee &s)
{
    cout<<"调用了拷贝构造函数"<<endl;
    employ_id = number++;
    employ_name = s.employ_name;
}


void Employee::print_employ_info()
{
    cout<<"职工姓名 "<<employ_name<<endl<<"职工id "<<employ_id<<endl;
}

int Employee::number=0;

int main()
{

    Employee a;
    a.print_employ_info();
    Employee b("Gery");
    b.print_employ_info();
    Employee c = b;
    c.print_employ_info();
    Employee d("Kiwi");
    c = d;
    c.print_employ_info();
    return 0;
}
