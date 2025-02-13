
#include <iostream>
using namespace std;

struct btnode 
{
    char data;
    btnode *lc = NULL;
    btnode *rc = NULL;
};

int findindex(char c, char inOrder[], int end) 
{
    for(int i = 0; i < end; i++) 
    {
        if(inOrder[i] == c) return i;
    }
    return -1;
}

btnode *createTree(char postOrder[], char inOrder[], int start1, int &end1,int start2, int end2)
{
    if (start1 <= end1 || start2 > end2) return NULL;
    
    btnode *root = new btnode;
    int c = findindex(postOrder[end1], inOrder, end2 + 1);
    root->data = postOrder[end1];
    end1--;

    root->lc = createTree(postOrder, inOrder, start1, end1, start2, c - 1);
    root->rc = createTree(postOrder, inOrder, start1, end1, c + 1, end2);
    return root;
}

void print(btnode *T)
{
    if (T == NULL)
    {
        cout<<'#';
        return;
    }
    cout << T->data;
    print(T->lc);
    print(T->rc);
}

int main()
{
    char postOrder[100], inOrder[100];
    int i = 0, j = 0;
    
    while (cin >> postOrder[i] && postOrder[i] != '#') i++;
    while (cin >> inOrder[j] && inOrder[j] != '#') j++;

    btnode *BT = NULL;
    int start1 = 0;
    BT = createTree(postOrder, inOrder, start1, i, 0, j - 1);
    
    print(BT);
    return 0;
}
