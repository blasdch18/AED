#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

enum Color{black,red};

// ************************************ Function Object
template<class T>
struct Greater
{
    bool operator () (T a , T b)
    {
        return a>b;
    }
};

template<class T>
struct Less
{
    bool operator () (T a , T b)
    {
        return a<b;
    }
};

template<class T>
struct TraitLess
{
    typedef T type;
    typedef Less<type> cmp;
};


//************************************   Nodo RB
template <class T>
struct nodo
{
    Color color;
    T data;
    nodo (T n);
    nodo<T>* leaf[2];

    //Others Functions
    T GetData();
    Color GetColor();
};

template <class T>
nodo<T>::nodo(T n)
{
    data=n;
    leaf[0]=0;
    leaf[1]=0;
    color=red;
}

template<class T>
T nodo<T>::GetData()
{
    return data;
}

template<class T>
Color nodo<T>::GetColor()
{
    return color;
}


// ********************************************   arbol_RB
template <class Tr>
class arbol_RB{
public:
    typedef typename Tr::type T;
    typedef typename Tr::cmp C;
    typedef nodo<T> Node;

    Node* root_;
    C cmp_;

    arbol_RB();

    void RotationDir(bool d, Node** u);
    bool GetColor(Node * p);
    void UpdateColor(Node **p, Node ** u);
    void SimpleRotation(Node** p,bool dir);
    void DoubleRotation(Node** p,bool dir);
    bool Find(T n, Node ** &p, stack<Node **> &stack);
    bool Insert(T n);
    void DestroyTree(Node *&p);
    void RPrint(Node *p);
    void PrintTree();
    void amplitud();
    void printRoot();
};

template<class Tr>
arbol_RB<Tr>::arbol_RB(){
    root_=0;
}

template<class Tr>
bool arbol_RB<Tr>::GetColor(Node *p){
    if(p){
        return p->GetColor();
    }
    return 0;
}

template<class Tr>
void arbol_RB<Tr>::DestroyTree(Node *&p){
    if (!!p) {
        DestroyTree(p->leaf[0]);
        DestroyTree(p->leaf[1]);
        delete p;
    }
}

template<class Tr>
void arbol_RB<Tr>::RotationDir(bool d, Node **u){
    bool d_r=GetColor((*u)->leaf[d]->leaf[!d])>GetColor((*u)->leaf[d]->leaf[d]);
    if (d_r) {
        DoubleRotation(u, d);
    }
    else{
        SimpleRotation(u, d);
    }
}

template<class Tr>
void arbol_RB<Tr>::UpdateColor(Node **p, Node **u){
    int dir=GetColor((*u)->leaf[0])-GetColor((*u)->leaf[1]);
    if (dir==0) {
        if ((*u)->leaf[0]== *p) {
            dir=1;
        }
        else{
            dir=-1;
        }
    }
    bool v=GetColor((*p)->leaf[0])||GetColor((*p)->leaf[1]);
    if (dir==1 && v) {
        RotationDir(0, u);
    }
    if(dir==-1 && v){
        RotationDir(1, u);
    }
    if (root_->color) {
        root_->color = black;
    }
    return;
}

template<class Tr>
void arbol_RB<Tr>::SimpleRotation(Node **p, bool dir){
    Node * tmp = *p;
    *p=(*p)->leaf[dir];
    tmp->leaf[dir]=(*p)->leaf[!dir];
    (*p)->leaf[!dir]=tmp;
    if (!!(*p)->leaf[dir]) {
        (*p)->leaf[dir]->color = black;
    }
    else if (!!(*p)->leaf[!dir]) {
        (*p)->leaf[!dir]->color=black;
    }
}

template<class Tr>
void arbol_RB<Tr>::DoubleRotation(Node **p, bool dir){
    SimpleRotation(&(*p)->leaf[dir], !dir);
    SimpleRotation(p,dir);
}

template<class Tr>
bool arbol_RB<Tr>::Find(T n, Node **&p, stack<Node **> &stack){
    p=&root_;
    while( *p && n!=(*p)->data ){
        stack.push(p);
        p=&(*p)->leaf[cmp_((*p)->data,n)];
    }
    return (*p) && n==(*p)->data;
}

template<class Tr>
bool arbol_RB<Tr>::Insert(T n){
    Node **p;
    stack <Node**> stack;
    if (Find(n,p,stack)) {
        return 0;
    }
    *p=new Node(n);
    if ((root_)->color) {
        root_->color=black;
    }
    while (!stack.empty()) {
        if ((* stack.top())->color == red) {
            Node **tmp = stack.top();
            stack.pop();
            UpdateColor(tmp, stack.top());
        }
        else{
            stack.pop();
        }
    }
    return 1;
}

template<class Tr>
void arbol_RB<Tr>::RPrint(Node *p){
    if(!p) return;
    RPrint(p->leaf[0]);
    cout<<p->data<<"°"<<p->color<<"->";
    RPrint(p->leaf[1]);
}
template<class Tr>
void arbol_RB<Tr>::PrintTree(){
    RPrint(root_);
}
template<class Tr>
void arbol_RB<Tr>:: amplitud (){
    queue<Node*>cola;
    Node *p=root_;
    cola.push(p);
    while (!cola.empty()) {
        p=cola.front();
        cola.pop();
        cout<<p->data<<"°"<<p->color<<"->";
        if (p->leaf[0]!=0) cola.push(p->leaf[0]);
        if (p->leaf[1]!=0) cola.push(p->leaf[1]);
    }
}
template <class Tr>
void arbol_RB<Tr>:: printRoot(){
    Node*p=root_;
    cout<<p->data;
}


int main()
{
    cout << "Hello world!" << endl;


    arbol_RB< TraitLess<int> >a;
    for(int i=1;i<11;i++){
        a.Insert(i);
    }

    a.PrintTree();cout<<endl;
    cout<<"pruebas para el arbol"<<endl;
//    nodo<int>b;
//    b=a.root_;
    a.amplitud();
    cout<<endl;
    a.printRoot();
    return 0;

    return 0;
}
