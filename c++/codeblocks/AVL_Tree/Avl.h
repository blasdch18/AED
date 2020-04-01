#ifndef AVL_H
#define AVL_H
#include "Node.h"
#include <stack>
#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;
template<class T>
class Avl
{
    public:
    typedef Node<T>     Nod;

        Avl();
        Nod* root;
        bool find(T,Nod**&p,stack<Nod*>&);
        bool add(T);
        bool erase(T);
        void show();
        void print(Nod*);
        void rota_simple(Nod**&,bool);
        void rota_double(Nod**&,bool);
        int set_high(Nod*, vector<Nod*> &pth);
        void copy(vector<Nod*>& v, stack<Nod*> p);
        bool v_find(vector<Nod*>& v, Nod* p);
        void print2();
        void print3(Nod*&,int);
        void draw();
        void draw(Nod*);
        virtual ~Avl();
    protected:
    private:
};


template<class T>
Avl<T>::Avl()
{
    root=NULL;
}

template<class T>
bool Avl<T>::find(T dat,Nod** &p,stack<Nod*>& path){
    p=&root;


    while(*p){
        if((*p)->get_data()==dat)
            return true;
        path.push(*p);
        //cout<<"pila "<<path.top()->get_data()<<endl;
        p=&((*p)->sons[dat>(*p)->get_data()]);

    }
    //cout<<endl;
    //path.push(*p);
    return false;
}



template<class T>
void Avl<T>::rota_simple(Nod**& p,bool left){
    Nod* q=(*p)->sons[!left];
    (*p)->sons[!left]=q->sons[left];
    q->sons[left] = (*p);
    if(*p == root)
        root = q;
}

template<class T>
void Avl<T>::rota_double(Nod**& p,bool left){
    Nod** q = &((*p)->sons[!left]);
    Nod* r = (*q)->sons[left];
    rota_simple(q,!left);
    (*p)->sons[!left] = r;
    rota_simple(p,left);
}

template<class T>
bool Avl<T>::v_find(vector<Nod*>& v, Nod* p){
    if (p==NULL)
        return false;
    for(int i=0; i<v.size(); i++){
        if(v[i] == p)
            return true;
    }
    return false;
}

template<class T>
int Avl<T>::set_high(Nod* p, vector<Nod*>& pth ){
    //cout <<"'adfad'" <<p->get_data() << " " << p->get_high() << endl;
    if (p==NULL)
        return -1;
    int a,b;
    if (v_find(pth,p->sons[0]))
        a = set_high(p->sons[0],pth);
    else
        a = p->sons[0]? p->sons[0]->get_high():-1;

    if (v_find(pth,p->sons[1]))
        b = set_high(p->sons[1],pth);
    else
        b = p->sons[1]? p->sons[1]->get_high():-1;

    p->set_highN(max(a,b) +1);
    return max(a,b) +1;
}

template<class T>
void Avl<T>::copy(vector<Nod*> & v, stack<Nod*> p ){
    v.clear();
    while(p.size() > 0){
        v.push_back(p.top());
        p.pop();
    }
    return;
}

template<class T>
bool Avl<T>::add(T dat){
    Nod**p=&root;
    stack<Nod*> path;

    if(find(dat,p,path)){
        return false;
    }
    else{
        Nod* q=new Nod(dat);
        (*p)=q;
        vector<Nod*> path2;
        path.push(q);
        copy(path2,path);
        set_high(root,path2);

        //cout<<"pila "<<path.size()<<endl;

        while(path.size()>0){
            //cout<<"pila "<<path.size()<<endl;
            //path.pop();
            Nod* j=path.top();

            //cout<< j->get_high() << endl;
            if((j->sons[0]&&j->sons[1]&& abs(j->sons[0]->get_high() - j->sons[1]->get_high())==2) || (j->sons[0] && !j->sons[1] && j->get_high()==2) ||(j->sons[1] && !j->sons[0] && j->get_high()==2)  ){
                cout<<"desvalance"<<endl;
                Nod** jp= &j;
                bool a = j->sons[0]? (j->sons[1] && max(j->sons[0]->get_high(),j->sons[1]->get_high())==j->sons[1]->get_high()?1:0) : 1;
                Nod* js = j->sons[a];
                bool b = js->sons[0]? (js->sons[1] && max(js->sons[0]->get_high(),js->sons[1]->get_high())==js->sons[1]->get_high()?1:0) : 1;

                if(!a && !b)
                    rota_simple(jp,true);
                if(a && b)
                    rota_simple(jp,false);
                if(!a && b)
                    rota_double(jp,true);
                if(a && !b)
                    rota_double(jp,false);

                if(path.size() > 1){
                    path.pop();
                    path.top() -> sons[a] = js;
                    path.push(j);
                }

                set_high(root,path2);
            }
            path.pop();
        }
       // cout<<(*p)->get_high()<<"A: "<<"  D:"<<(*p)->get_data()<<endl;
        return true;
    }
}

template<class T>
void Avl<T>::print2(){
    print3(root,0);
}

template<class T>
void Avl<T>:: print3(Nod*&parent,int level){
    if(parent){
        print3(parent->sons[1],level+1);
        for(int i=0;i<level; i++)
            cout<<"   ";
        cout<<parent->get_data()<<endl;
        print3(parent->sons[0],level+1);
    }
}

template<class T>
void Avl<T>::draw(Nod* tmp)
{

	if(tmp)
	{
	   cout<<tmp->get_data()<<"->  ";
	   for (int i=0; i<2;i++){
	     if (tmp->sons[i]){
	        cout<<tmp->sons[i]->get_data()<<",";
	     }
	   }
	   cout<<endl;
	   draw(tmp->sons[0]);

	   draw(tmp->sons[1]);
	}

}


template<class T>
void Avl<T>::draw(){
    draw(root);
}

template<class T>
void Avl<T>::print(Nod* p){
    if(!p)
        return;
    if(p->sons[0])
        print(p->sons[0]);

    cout<<p->get_data()<< " ";

    if(p->sons[1])
        print(p->sons[1]);
}

template<class T>
void Avl<T>::show(){
    Nod*p;
    p=root;
    cout << "raiz: " << root->get_data() << endl;
    print(p);
    cout<<endl;
}

template<class T>
Avl<T>::~Avl()
{
    //dtor
}


#endif // AVL_H
