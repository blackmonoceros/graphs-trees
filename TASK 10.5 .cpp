ZADANIE 10.5

// funkcion itself


Link maximum(Link root){
    if(root==nullptr){
       return nullptr;
    }
    Link aktualny=root;
    while(aktualny->right!=nullptr){
       aktualny=aktualny->right;
    }
    return aktualny;
}



//Funkcion in code.


#include <iostream>
using namespace std;

typedef int Item;

struct Node{
    Item info;
    Node *left,*right;
    Node(Item x){
        info=x;  
        left=nullptr;
        right=nullptr;
    }
};

typedef Node* Link;

void insert(Link &root, Item x){
    if(root==nullptr)
    {
        root=new Node(x);
    }
    else if (x<root->info){
       insert(root->left,x);
    }
    else
    {
       insert(root->right,x);
    }
}
void inOrder(Link root){
    if(root!=nullptr){
        inOrder(root->left);
        cout<<root->info<< " ";
        inOrder(root->right);
    }
}
Link minimum(Link root){
    if(root==nullptr){
       return nullptr;
    }
    Link aktualny=root;
    while(aktualny->left!=nullptr){
        aktualny=aktualny->left;
    }
    return aktualny;
}
Link maximum(Link root){
    if(root==nullptr){
       return nullptr;
    }
    Link aktualny=root;
    while(aktualny->right!=nullptr){
       aktualny=aktualny->right;
    }
    return aktualny;
}
int main() {
    Link root=nullptr;
    insert(root, 5);
    insert(root, 6);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 9);
    insert(root, 3);
    inOrder(root);
    cout<<endl;

    Link minNode=minimum(root);
    if(minNode!=nullptr){
       cout<<"Wartosc minimalna w drzewie: "<<minNode->info<<endl;
    }else
    {
       cout<<"Brak elementow."<<endl;
    }
    
    Link maxNode = maximum(root);
    if (maxNode!=nullptr){
       cout<<"Wartosc maksymalna w drzewie: "<<maxNode->info<<endl;
    }else 
    {
       cout<<"Brak elementow."<<endl;
    }
    return 0;
}
