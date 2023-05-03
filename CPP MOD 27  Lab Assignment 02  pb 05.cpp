//Use to the implement of  builtin Function:::::::::::
#include<bits/stdc++.h>
using namespace std;
template<class T>
class node{
public:
    T data;
    node<T>*prv;
    node<T>*nxt;

};
template<class T>

class Deque{
public:
    node<T>*head;
    node<T>*tail;
    int sz;


    Deque()
    {
        head=NULL;
        tail=NULL;
        sz=0;
    }
    node<T>*CreateNewNode(T value)
    {
        node<T>*newnode=new node<T>;
        newnode->data=value;
        newnode->nxt=NULL;
        newnode->prv=NULL;
        return newnode;
    }
    //push_back()  ___________O(1)
    void push_back(T value)
    {
        node<T>*newnode=CreateNewNode(value);
        if(sz==0)
        {
            head=newnode;
            tail=newnode;
            sz++;
            return;
        }
        tail->nxt=newnode;
        newnode->prv=tail;
        tail=newnode;
        sz++;
    }
    //push_front______________ O(1)
    void push_front(T value)
    {
        node<T>*newnode =CreateNewNode(value);
        if(sz==0)
        {
            head =newnode;
            tail=newnode;
            sz++;
            return;
        }
        head->prv=newnode;
        newnode->nxt=head;
        head =newnode;
        sz++;
    }
    //popback  O(1)
    void pop_back()
    {
        if(sz==0)
        {
            cout<<" Deque is empty \n ";
            return;
        }
        if(sz==1)
        {
            delete tail;
            head=NULL;
            tail=NULL;
            sz--;
            return;

        }
        node<T>*a =tail;
        tail=tail->prv;
        delete a;
        tail->nxt=NULL;
        sz--;

    }
    // pop_front O(1)

    void pop_front()
    {
        if(sz==0)
        {
            cout<<"Deque is empty \n ";
            return;
        }
        if(sz==1)
        {
            delete tail;
            head=NULL;
            tail=NULL;
            sz--;
            return;
        }
        node<T>*a =head;
        head=head->nxt;
        delete a;
        head->prv=NULL;
        sz--;
    }
    T front()
    {
        if(sz==0)
        {
            cout<<"Deque is empty \n";
            return -1;
        }
        return head->data;


    }
    T back()
    {
        if(sz==0)
        {
            cout<<"Deque is empty \n ";
            return -1;
        }
        return tail->data;
    }

};
int main()
{
//Deque d;
Deque<int>d;
d.push_back(5);
d.push_back(10);
d.push_back(15);
                      //[5,10,15]
cout<<"Back : "  << d.back() <<" Front : " << d.front() <<"\n";

d.push_front(20);

cout<<"Back : " << d.back() <<" Front : " << d.front() <<"\n";


d.pop_front();

cout<<"Back :" << d.back() <<" Front : " << d.front() <<"\n";

d.pop_back();
cout<<"Back :" << d.back() <<" Front : " << d.front() <<"\n";



cout<<"Template based Deque Implementation------"<<endl;

Deque<char>d2;
d2.push_back('a');
d2.push_back('b');
d2.push_back('c');

cout<<d2.front()<<"\n";
d2.pop_front();

cout<<d2.front()<<"\n";
d2.pop_front();

cout<<d2.front()<<"\n";
d2.pop_front();

return 0;
}

