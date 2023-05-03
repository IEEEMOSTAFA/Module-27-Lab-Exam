//Use to the implement of  builtin Function:::::::::::
#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node*prv;
    node*nxt;

};
class Deque{
public:
    node*head;
    node*tail;
    int sz;


    Deque()
    {
        head=NULL;
        tail=NULL;
        sz=0;
    }
    node*CreateNewNode(int value)
    {
        node*newnode=new node;
        newnode->data=value;
        newnode->nxt=NULL;
        newnode->prv=NULL;
        return newnode;
    }
    //push_back()  ___________O(1)
    void push_back(int value)
    {
        node*newnode=CreateNewNode(value);
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
    void push_front(int value)
    {
        node*newnode =CreateNewNode(value);
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
        node*a =tail;
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
        node*a =head;
        head=head->nxt;
        delete a;
        head->prv=NULL;
        sz--;
    }
    int front()
    {
        if(sz==0)
        {
            cout<<"Deque is empty \n";
            return -1;
        }
        return head->data;


    }
    int back()
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
Deque d;
string s;
cin>>s;
for(int i=0;i<s.size();i++)
{
    d.push_back(s[i]);
}
int sz =s.size();
int loop =sz/2;
for(int i=1;i<=loop;i++)
{
    if(d.back()==d.front())
    {
        d.pop_back();
        d.pop_front();
    }
    else
    {
        cout<<"No";
        return 0;
    }
}
cout<<"Yes";
return 0;
}

