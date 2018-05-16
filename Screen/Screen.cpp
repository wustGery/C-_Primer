#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

class Screen
{
public:
    Screen(int x):i(x){};
    int get() {return i;}
    static void* operator new(size_t);
    static void operator delete(void*,size_t);
private:
    Screen* next;
    static Screen* freeStore;
    static const int  screenChunk;
private:
    int i;
};


Screen* Screen::freeStore = 0 ;
const int  Screen::screenChunk = 24;


static void* Screen::operator new(size_t size)
{
    Screen *p;
    if(!freeStore)
    {
        cout<<"第一次分配内存"<<endl;
        size_t size = screenChunk*size;
        freeStore = p = reinterpret_cast<Screen*>(new char(size));
        for(;p!=&freeStore[screenChunk-1];p++)
            p->next = p+1;
        p->next = 0;
    }
    p = freeStore;
    freeStore = p->next;
    return p;
}


static void Screen::operator delete(void* pdead,size_t size)
{
    cout<<"调用了operator delete函数"<<endl;
    //将delete object插回free list前端
    (static_cast<Screen*>(pdead))->next = freeStore;
    freeStore = static_cast<Screen*>(pdead);
}


int main()
{
    cout<< sizeof(Screen)<<endl;
   // cout<< sizeof(int)<<endl;
    //cout<< sizeof(Screen*)<<endl;
    size_t const N =5;
    Screen* p[N];
    for(int i=0;i<N;i++)  p[i] = new Screen(i);
    for(int i=0;i<N;i++)  cout<<p[i]<<endl;
    for(int i=0;i<N;i++)  delete p[i];
    return 0;
}
