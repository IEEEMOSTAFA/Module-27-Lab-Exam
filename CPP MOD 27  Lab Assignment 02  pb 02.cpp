
#include<bits/stdc++.h>

using namespace std;
template<class T>
class node
{
public:
    T data;
    node* nxt;
};
template<class T>
class singlyLinkedList
{
public:
    node<T> * head;
    int sz;
    singlyLinkedList()
    {
        head = NULL;
        sz=0;
    }

    //Creates a new node with data = value and nxt= NULL
    node<T>* CreateNewNode(T value)
    {
        node<T> *newnode = new node<T>;
        newnode->data = value;
        newnode->nxt = NULL;
        return newnode;
    }

    // Insert new value at Head
    void InsertAtHead(T value)
    {
        sz++;
        node<T> *a = CreateNewNode(value);
        if(head == NULL)
        {
            head = a;
            return;
        }
        //If head is not NULL
        a->nxt = head;
        head = a;
    }

    //Prints the linked list
    void Traverse()
    {
        node<T>* a = head;
        while(a!= NULL)
        {
            cout<<a->data<<" ";
            a = a->nxt;
        }
        cout<<"\n";
    }


    int getSize()
    {

        return sz;



    }


    void DeleteAtHead()
    {
        if(head == NULL)
        {
            return;
        }
        sz--;
        node<T> *a = head;
        head = a->nxt;
        delete a;
    }




};
template<class T>
class Stack{

    public:
singlyLinkedList<T> dl;
Stack()
{

}
T  top()
{
    if(dl.getSize()==0)
    {
        cout<<"Stack is empty \n";
       T a;
       return a;
    }
    return dl.head->data;
}
void push(T val)
{
    dl.InsertAtHead(val);
}
T pop()
{
    if(dl.getSize()==0)
    {
        cout<<"Stack is empty !  \n";
        return -1;
    }
    dl.DeleteAtHead();
}
};

int main()
{
   Stack<double>st;
st.push(3.5);
st.push(3.6);
st.push(7.8);
cout<<st.top()<<"\n";
st.pop();
cout<<st.top()<<"\n";
st.pop();
cout<<st.top()<<"\n";
st.pop();
cout<<st.top()<<"\n";

Stack<char>st2;
st2.push('a');
st2.push('g');
st2.push('u');
cout<<st2.top()<<"\n";
st2.pop();
cout<<st2.top()<<"\n";
st2.pop();
cout<<st2.top()<<"\n";
st2.pop();
cout<<st2.top()<<"\n";
return 0;
}

