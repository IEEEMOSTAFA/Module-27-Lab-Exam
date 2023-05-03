#include<bits/stdc++.h>
using namespace std;
template<class T>

class Queue{
public:
    T *a;
    int array_cap;
    int l,r;
    int sz;
Queue()
{
    a=new T[1];
    array_cap=1;
    l=0;
    r=-1;
    sz=0;
}
void remove_circular()
{
    if(l>r)
    {

    T *tmp=new T [array_cap];
    int idx=0;
    for(int i=l;i<array_cap;i++)
    {
        tmp[i]=a[i];
        idx++;
    }
    for(int i=0;i<=r;i++)
    {
        tmp[i]=a[i];
        idx++;
    }
    swap(tmp,a);
    l=0;
    r=array_cap-1;
    delete []tmp;
}


}
void increase_size()
{
    remove_circular();
    T *tmp=new T [array_cap];
    for(int i=0;i<array_cap;i++)
        tmp[i]=a[i];
    swap(tmp,a);
    array_cap=array_cap*2;
    delete []tmp;
}
void enqueue(T value)
{
    if(sz==array_cap)
    {
        increase_size();
    }
    r++;
    if(r==array_cap)
    {
        r=0;
    }
    a[r]=value;
    sz++;
}
void dequeue()
{
    if(l==array_cap)
    {
        l=0;
    }
    l++;
    sz--;
}
T front()
{
    if(sz==0)
    {
        cout<<"Queue is empty \n ";
        return -1;
    }
    return a[l];
}
int size()
{
    return sz;
}

};
int main()
{
    //Queue q;
    Queue<int>q;
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    cout<<" Q size :   "<<q.size()<<"\n";
    cout<<q.front()<<" \n";
    q.dequeue();
    cout<<q.front()<<"\n";
    q.dequeue();
    cout<<q.front()<<"\n";
    q.dequeue();
    cout<<" Q size :   "<<q.size()<<"\n";


    cout<<"Template Checking By Any Data Type "<<"\n";

Queue<char>q2;
q2.enqueue('a');
q2.enqueue('b');
q2.enqueue('c');
cout<<" Q size :   "<<q2.size()<<"\n";
cout<<q2.front()<<" \n";
q2.dequeue();
cout<<q2.front()<<"\n";
q2.dequeue();
cout<<q2.front()<<"\n";
q2.dequeue();
cout<<" Q size :   "<<q2.size()<<"\n";
}


