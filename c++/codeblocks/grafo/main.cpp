#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <time.h>
#include <ctime>
#include <stdlib.h>

#define max_vert 20
#define INF 1<<30

using namespace std;

template<class G>
class nodo
{
public:
    typedef typename G::N N;
    typedef typename G::Edge Edge;
    nodo(N x)
    {
        data=x;
    }
    N data;
    vector<Edge*> nodo_edges;              //guarda aristas
};

template<class G>
class Edge
{
public:
    typedef typename G::E E;
    typedef typename G::Node Node;
    Edge(E x,Node* a,Node* b){
        data=x;
        edge_nodo[0]=a;
        edge_nodo[1]=b;
    }
    E data;
    Node* edge_nodo[2];//0 es entran y 1 salen
};

template<class n,class e>
class Grafo
{
public:
    typedef  Grafo<n,e> Self;
    typedef  nodo<Self> Node;
    typedef  Edge<Self> Edge;
    typedef  n N;
    typedef  e E;

    E matriz_adyacencias[410][410];
    vector<Node*> nodos;
    vector<Edge*> edges_s;

    bool insertar_nodo(N x)
    {
        Node* temp=new Node(x);
        nodos.push_back(temp);
        return 1;
    }

    bool insertar_edge(E x,N a,N b)
    {
        Node *Na,*Nb;
        for(int i =0; i<nodos.size();i++)
        {
            if(nodos[i]->data == a)
                {
                    Na = nodos[i];
                }
            if(nodos[i]->data == b)
                {
                    Nb = nodos[i];
                }
        }
        Edge* temp= new Edge(x , Na , Nb);
        Na->nodo_edges.push_back(temp);
        Nb->nodo_edges.push_back(temp);
        edges_s.push_back(temp);
        return 1;
    }

    E conexion_nodos(N a,N b)
    {
        for(int i=0;i<edges_s.size();i++)
        {
            if(edges_s[i]->edge_nodo[0]->data == a && edges_s[i]->edge_nodo[1]->data == b)
            {
                return edges_s[i]->data;
            }
        }
        return 0;
    }

    void matriz_adyacencia()
    {
        for(int i=0;i<nodos.size();i++)
        {
            for(int j=0;j<nodos.size();j++)
            {
                matriz_adyacencias[i][j]=conexion_nodos( nodos[i]->data , nodos[j]->data );
                cout<<matriz_adyacencias[i][j]<<" ";
            }
            cout<<endl;
        }
        return;
    }

    Grafo convertir_matriz_grafo()
    {
        Grafo matriz_grafo;
        for(int i=0;i<nodos.size();i++)
        {
            matriz_grafo.insertar_nodo(nodos[i]->data);
        }
        for(int i=0;i<nodos.size();i++)
        {
            for(int j=0;j<nodos.size();j++)
            {
                if(matriz_adyacencias[i][j]!=0)
                {
                    matriz_grafo.insertar_edge(matriz_adyacencias[i][j] , nodos[i]->data , nodos[j]->data);
                }
            }
        }
        return matriz_grafo;
    }

    void imprimir()
    {
        cout<<"Nodos----=> ";
        for(int i=0;i<nodos.size();i++)
        {
            cout<<nodos[i]->data<<"° ";
        }
        cout<<endl<<endl;
        cout<<"Aristas--=> ";

        for(int i=0;i<edges_s.size();i++)
        {
            cout<<edges_s[i]->data<<"  ";
        }

        cout<<endl<<endl;
        cout<<"Links :"<<endl;

        for(int i =0;i<edges_s.size();i++)
        {
            cout<<edges_s[i]->data<<" ~ "<<edges_s[i]->edge_nodo[0]->data<<" -> "<<edges_s[i]->edge_nodo[1]->data<<endl;
        }
    }

    struct cmp {
        bool operator() ( const pair< N, E >  &a , const pair< N, E >  &b ) {
            return a.second > b.second;
        }
    };

    int distancia[ max_vert ] ;
    bool visitado [ max_vert ] ;
    priority_queue < pair< N,E > , vector < pair <N,E> > , cmp > Q ;
    int num_vertices ;
    int previo [ max_vert ];

    void print( int destino )
    {
        if( previo[ destino ] != -1 )
        {
            print( previo[ destino ] );
        }
        cout<<destino<<" ";
    }

    void a_star ( int inicial )
    {
        for( int i = 0 ; i <= nodos.size() ; ++i ){
            distancia[ i ] = INF;  //inicializamos todas las distancias con valor infinito
            visitado[ i ] = 0; //no visitados
            previo[ i ] = -1;
        }
        pair< N , E > vnodo( inicial , 0 ) ;

        Q.push(vnodo );
        distancia[ inicial ] = 0;
        int actual , adyacente , peso;
        while( !Q.empty() ){
            actual = Q.top().first;
            Q.pop();
            if(!visitado[ actual ] )  {

                visitado[ actual ] = 1;

                ///numero edges que salen del nodo
                int cont=0;
                for(int i =0;i<nodos.size();i++)
                {
                    if(conexion_nodos(actual,nodos[i]->data)) cont++;
                    // cout<<actual<<" "<<m_nodes[i]->m_data<<" "<<conexion_nodos(actual,m_nodes[i]->m_data)<<endl;
                }

                for( int i = 0 ; i < nodos.size() ; ++i ){
                    if(conexion_nodos(actual,nodos[i]->data))
                    {
                        adyacente = nodos[i]->data;   //id del vertice adyacente
                        peso = conexion_nodos(actual,nodos[i]->data);       //peso de la arista que une actual con adyacente ( actual , adyacente )
                        if( !visitado[ adyacente ] ){        //si el vertice adyacente no fue visitado
                            //Si la distancia del origen al vertice actual + peso de su arista es menor a la distancia del origen al vertice adyacente
                            if( distancia[ actual ] + peso < distancia[ adyacente ] ){
                                distancia[ adyacente ] = distancia[ actual ] + peso;  //relajamos el vertice actualizando la distancia
                                previo[ adyacente ] = actual;                         //a su vez actualizamos el vertice previo
                                Q.push( pair< N , E > ( adyacente , distancia[ adyacente ] ) ); //agregamos adyacente a la cola de prioridad
                            }
                        }}
                }
            }}



        cout<< "Distancias mas cortas iniciando en vertice: "<< inicial<<endl;
        for( int i = 1 ; i <= nodos.size() ; ++i ){
            cout<<"Vertice "<<i<<" distancia mas corta = "<< distancia[ i ] <<endl;
        }

        cout<<("**************Impresion de camino mas corto**************")<<endl;
        cout<<("Ingrese vertice destino: ");
        int destino;
        cin>>destino;
        print( destino );
        cout<<endl;
    }



    /////hacer dijstrack
    /// hacer tabla hush
    /// matriz esparza
};

int main()
{
    srand(time(NULL));
    Grafo<int,int> grafo_1;

    grafo_1.insertar_nodo(0);
    grafo_1.insertar_nodo(1);
    grafo_1.insertar_nodo(2);
    grafo_1.insertar_nodo(3);
    grafo_1.insertar_nodo(4);
    grafo_1.insertar_nodo(5);
    grafo_1.insertar_nodo(6);
    grafo_1.insertar_nodo(7);
    grafo_1.insertar_nodo(8);
    grafo_1.insertar_nodo(9);

    grafo_1.insertar_edge(3,0,4);
    grafo_1.insertar_edge(2,4,9);
    grafo_1.insertar_edge(5,2,9);
    grafo_1.insertar_edge(1,9,1);
    grafo_1.insertar_edge(2,1,3);
    grafo_1.insertar_edge(4,1,6);
    grafo_1.insertar_edge(1,6,7);
    grafo_1.insertar_edge(2,8,6);
    grafo_1.insertar_edge(1,7,8);
    grafo_1.insertar_edge(2,5,7);
    /*
    grafo_1.insertar_edge(1,1,8);
    grafo_1.insertar_edge(1,1,9);
    grafo_1.insertar_edge(1,3,10);
    grafo_1.insertar_edge(2,2,6);
    grafo_1.insertar_edge(1,3,8);
    grafo_1.insertar_edge(1,3,9);
    grafo_1.insertar_edge(1,3,7);
    grafo_1.insertar_edge(2,1,7);
    grafo_1.insertar_edge(1,3,11);
    grafo_1.insertar_edge(1,3,4);
    grafo_1.insertar_edge(1,3,9);*/
    int mapa = 15;
    int k=1;
/*
    for(int i=0 ; i < mapa ; i++)
    {
            grafo_1.insertar_nodo(k);
            k++;
    }
    for(int i=0 ; i < mapa ; i++)
    {
        for(int j=0 ; j <mapa ; j++)
        {
            int a=1+rand()%mapa;
            int b=1+rand()%mapa;
            int c=1+rand()%mapa;
            //cout<<a<<"+"<<b<<"+"<<c<<"+"<<endl;
            grafo_1.insertar_edge(a,b,c);
        }
    }*/

    /*
    grafo_1.insertar_edge(2,2,4);
    grafo_1.insertar_edge(2,3,4);
    grafo_1.insertar_edge(3,1,3);
    grafo_1.insertar_edge(1,2,3);
*/  cout<<"GRAFO"<<endl;
    grafo_1.imprimir();
    cout<<endl;

    grafo_1.matriz_adyacencia();
    cout<<endl;
    //Grafo<int,int> grafo_2;

    //grafo_2 = grafo_1.convertir_matriz_grafo();
    //grafo_2.imprimir();

    int  inicial;

    cout<<">>>>>>>>>>>>Vertice inicial: ";
    cin>>inicial;
    grafo_1.a_star( inicial );

    grafo_1.print(inicial);
    //grafo_1.
    return 0;

}
