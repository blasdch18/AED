#ifndef LISTAENLAZADA_H_INCLUDED
#define LISTAENLAZADA_H_INCLUDED

template <class T>
struct nodo
{
    nodo(T x)
    {
        data = x;
        next = 0;
    }
    T data;
    nodo<T> *next;
};

template<class T>
class lista
{
    public:
         nodo<T> * head;
        int count;
        lista()
        {
            head  = 0;
            count = 0;
        }
        ~lista()
        {
//            nodo<T> *q = head;
//            for (nodo<T> *t = head; q; t=q)
//            {
//                q = t->next;
//                delete t;
//            }
//            head = 0;
        }

        bool Find(T x, nodo<T> **&p)
        {
            p = &head;
            while ((*p) && (x > (*p)->data))
            {
                //cout<<"Existe: "<<(*p)<<endl;
                p = &((*p)->next);
            }
            return *p && (*p)->data == x;
        }

        bool Fin_no_order(T x, nodo<T> **&p){
            p = &head;
            while ((*p))
            {
                //cout<<"Existe: "<<(*p)<<endl;
                p = &((*p)->next);
            }
            return *p && (*p)->data == x;
        }

        bool Insert_no_order(T x){

            nodo <T> **p;
            if (Fin_no_order(x, p))
            {
                    return 0;
            }
            nodo <T> *w;

            w = new nodo<T>(x);///creamos al nodo con el dato
            w->next = *p;///el next del nuevo dato apuntara a su antes

            *p = w;///el p apuntara al nuevo dato

            //cout<< "\t direccion=" << &((*p)->data)<<endl;
            count++;
            return 1;
        }
        bool Insert(T x)
        {

            nodo <T> **p;
            if (Find(x, p))
                {
                    return 0;
                }
            nodo <T> *w;

            w = new nodo<T>(x);///creamos al nodo con el dato
            w->next = *p;///el next del nuevo dato apuntara a su antes

            *p = w;///el p apuntara al nuevo dato

            //cout<< "\t direccion=" << &((*p)->data)<<endl;
            count++;
            return 1;
        }
        bool borrado(T x)
        {
            nodo <T> **p;
            if (Find(x, p)){
                nodo<T> *t=*p;
                *p = (*p)->next;
                delete t;
                return 1;
            }
        }

        bool borrado_no_order(T x)
        {
            nodo <T> **p;
            if (Fin_no_order(x, p)){
                nodo<T> *t=*p;
                *p = (*p)->next;
                delete t;
                return 1;
            }
        }

        void aniadir_lista(lista<T> x){
            nodo<T> *p;
            for (p = x.head; p; p = p->next)
            {
                this->Insert(p->data);
            }
        }

        friend ostream& operator<<(ostream& os, const lista& target){
            nodo<T> *p;
            int elemt = 1;
            for (p = target.head; p; p = p->next)
            {
                os << "Elem " << elemt << "=" << p->data << "\n";
                elemt++;
            }
            return os;
        }

        void print()
        {
            nodo<T> *p;
            int elemt = 1;
            for (p = head; p; p = p->next)
            {
                cout << "Elem " << elemt << "=" << p->data << "\t direccion=" << &(p->data) << endl;
                elemt++;
            }
        }
};

#endif // LISTAENLAZADA_H_INCLUDED
