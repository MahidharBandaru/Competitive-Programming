#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

//-----------------------TRIE-START---------------------------------------------
const lli size = 10;
struct tnode
{
    tnode *child[size];
    lli isword;
};

tnode* makenode()
{
    tnode *temp = new tnode;
    for(int i = 0; i<size; i++)
    {
        temp->child[i] = NULL;
    }
    temp->isword = 0;
    return temp;
}

void insert(tnode *root, string s)
{
    tnode *temp = root;
    for(int i = 0; i<s.size(); i++)
    {
        lli key = s[i]-'a';
        if(temp->child[key] == NULL)
        {
            temp->child[key] = makenode();
        }
        temp = temp->child[key];
    }
    temp->isword = 1;
}

lli search(tnode *root,string s)
{
    tnode *temp = root;
    for(int i = 0; i<s.size(); i++)
    {
        lli key = s[i]-'a';
        if(temp->child[key] == NULL)
        {
            return 0;
        }
        temp = temp->child[key];
    }
    return temp->isword;
}

int main()
{
    tnode *root = makenode();
    insert(root,"Shobhit");
    insert(root,"Varada");
    insert(root,"Mahidhar");
    cout << search(root,"Shobhit") << " " << search(root,"Tourist") << " " << search(root,"Varada") << endl;
}

//------------------------TRIE-END----------------------------------------------
