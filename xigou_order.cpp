
#include<iostream>
using namespace std;

class A
{
private:
    int a;
public:
    A(int aa)
    {
        cout<<"������A�Ĺ��캯��"<<endl;
        a = aa;
    }
    virtual ~A(){cout<<"������A����������"<<endl;}
};


class B:public A
{
private:
    int b;
public:
    B(int aa,int bb):A(aa)
    {
        cout<<"������B�Ĺ��캯��"<<endl;
        b = bb;
    }
    ~B() {cout<<"������B����������"<<endl;}
};

int main()
{
    A(1);
    B(1,2);
    return 0;
}
