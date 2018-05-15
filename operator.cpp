#include<iostream>
using namespace std;

class Foo
{
    public:
        int _id;
        long _data;
        string _str;
    public:
        Foo():_id(0){cout<<"default ctor.this="<<this<<" id="<<_id<<endl;}
        Foo(int i):_id(i){cout<<"ctor.this="<<this<<" id="<<_id<<endl;}
        ~Foo() {cout<<"dtor.this="<<this<<" id="<<_id<<endl;}
        static void* operator new(size_t size);
        static void operator delete(void* pdead,size_t size);
        static void* operator new[](size_t size);
        static void operator delete[](void* pdead,size_t size);
};

void* Foo::operator new(size_t size)
{
    Foo* p = (Foo *)malloc(size);
    cout<<"调用了Foo::operator new"<<endl;
    return p;
}

void Foo::operator delete(void *pdead,size_t size)
{
    cout<<"调用了Foo::operator delete"<<endl;
    free(pdead);
}
void* Foo::operator new[](size_t size)
{
    Foo* p  = (Foo*)malloc(size);
    cout<<"调用了Foo::operator new[]"<<endl;
    return p;
}

void Foo::operator delete[](void *pdead, size_t size)
{
    cout<<"调用了Foo::operator delete[]"<<endl;
    free(pdead);
}


int main()
{
    Foo* pf = new Foo(7);
    Foo* pf1 = new Foo[10];
    delete pf;
    delete[] pf1;
}
