#ifndef AVLSTACK_H_INCLUDED
#define AVLSTACK_H_INCLUDED

using namespace std;
template<class T>
class CNodeStack{
    public:
        T m_data;
        CNodeStack<T> *m_sig;
        CNodeStack(T x)
        {
             m_data = x;
             m_sig = NULL;
        }
};

template<class T>
class CStack
{
    public:
        CNodeStack<T> *head;
        CStack(){head = NULL;}

        bool buscar(T x, CNodeStack<T> ** &p)
        {
            for(p = &head;!!*p && (*p)->m_data!=x ;p=&(*p)->m_sig);
            return !!*p && (*p)->m_data == x;
        }

        bool push( T x)
        {
            CNodeStack<T> **p;
            if(buscar(x,p)) return 0;
            CNodeStack<T> *n = new CNodeStack<T>(x);
            n->m_sig=head;
            head = n;
            return 1;
        }


        T pop()
        {
            if(!head) return NULL;
            T retorned;
            retorned = head->m_data;
            CNodeStack<T> *d=head;
            head = head->m_sig;
            delete d;
            return retorned;
        }

        void imprimir()
        {
            for(CNodeStack<T> *p = head;!!p;p=p->m_sig)
                cout << p->m_data << " ";
            cout << endl;
        }


        ~CStack()
        {
            CNodeStack<T> *p;
            while(head)
            {
                p=head;
                head=head->m_sig;
                delete p;
            }

        }
};

#endif // AVLSTACK_H_INCLUDED
