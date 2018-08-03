
#include<iostream>
using namespace std;

class A
{
private:
    int a;
public:
    A(int aa)
    {
        cout<<"调用了A的构造函数"<<endl;
        a = aa;
    }
    virtual ~A(){cout<<"调用了A的析构函数"<<endl;}
};


class B:public A
{
private:
    int b;
public:
    B(int aa,int bb):A(aa)
    {
        cout<<"调用了B的构造函数"<<endl;
        b = bb;
    }
    ~B() {cout<<"调用了B的析构函数"<<endl;}
};

int main()
{
    A(1);
    B(1,2);
    return 0;
}
