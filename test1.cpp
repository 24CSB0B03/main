#include<iostream>
#include<stack>
using namespace std;

struct btnode{
    char data;
    btnode *lc;
    btnode *rc;
};

void create(btnode *&T)
{
    char x;
    cin>>x;
    if(x=='#') return;
    T=new btnode;
    T->data=x;
    create(T->lc);
    create(T->rc);
}

void preorder(btnode *T)
{
    stack<btnode*>s,s1;
    while(T)
    {
        cout<<T->data;
        s.push(T->rc);
        
          T=T->lc;
        if(!T)
        {
            if(s.empty()) break;
            T=s.top();
            s1.push(T);
            s.pop();
        }
        
       
    }
}

int main()
{
    btnode *BT;
    create(BT);
    preorder(BT);
    return 0;
}