#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

#define max_vert 20
#define INF 1<<30


using namespace std;

template<class G>
class c_Node
{
public:
	typedef typename G::N N;
	typedef typename G::Edge Edge;
	c_Node(N x)
	{
		m_data = x;
	}

	N m_data;
	vector<Edge*> m_edges;//guardar aristas que entran y salen
};

template<class G>
class c_Edge
{
public:
	typedef typename G::E E;
	typedef typename G::Node Node;
	c_Edge(E x, Node* a, Node* b) {
		m_data = x;
		m_node[0] = a;
		m_node[1] = b;
	}


	E m_data;
	Node* m_node[2];//0 es entran y 1 salen
};

template<class n, class e>
class Grafo
{
public:
	typedef  Grafo<n, e> Self;
	typedef  c_Node<Self> Node;
	typedef  c_Edge<Self> Edge;
	typedef  n N;
	typedef  e E;

	vector<Node*> m_nodes;
	vector<Edge*> m_gedges;
	E m_ady[5][5];
	int g_size;



	struct cmp {
		bool operator() (const pair< N, E >  &a, const pair< N, E >  &b) {
			return a.second > b.second;
		}
	};

	bool insert_node(N x)
	{
		Node* temp = new Node(x);
		m_nodes.push_back(temp);
		return 1;
	}

	bool insert_edge(E x, N a, N b)
	{
		Node *Na, *Nb;
		for (int i = 0; i<m_nodes.size(); i++)
		{

			if (m_nodes[i]->m_data == a)
				Na = m_nodes[i];
			if (m_nodes[i]->m_data == b)
				Nb = m_nodes[i];

		}
		Edge* temp = new Edge(x, Na, Nb);
		Na->m_edges.push_back(temp);
		Nb->m_edges.push_back(temp);
		m_gedges.push_back(temp);
		return 1;
	}
	bool erase_edge(E x, N a, N b)
	{
		Node *Na, *Nb;
		for (int i = 0; i<m_nodes.size(); i++)
		{
			if (m_nodes[i]->m_data == a)Na = m_nodes[i];
			if (m_nodes[i]->m_data == b)Nb = m_nodes[i];
		}
		Edge* borrar;//borrar las conexiones de las aristas con los demas nodos
		for (int i = 0; i<m_nodes.size(); i++)
		{
			for (int j = 0; j<m_nodes[i]->m_edges.size(); j++)
			{
				if (m_nodes[i]->m_edges[j].m_data == x && m_nodes[i]->m_edges[j].m_node[0] == Na && m_nodes[i]->m_edges[j].m_node[1] == Nb)
				{
					m_nodes[i]->m_edges.erase(m_nodes[i]->m_edges.begin() + j);
				}
			}
		}
		for (int i = 0; i<m_gedges.size(); i++)
		{
			if (m_gedges[i].m_data == x && m_gedges[i].m_node[0] == Na && m_gedges[1].m_node[1] == Nb)
			{
				borrar = m_gedges[i];
				m_gedges.erase(m_gedges.begin() + i);
				delete borrar;
			}
		}
		return 1;

	}
	bool erase_node(N x)
	{
		Node* borrar;
		for (int i = 0; i<m_nodes.size(); i++)
		{
			if (m_nodes[i].m_data == x)
			{
				borrar = m_nodes[i];
				for (int j = 0; j<m_nodes[i].m_edges.size(); j++)
				{
					erase_edge(m_nodes[i].m_edges[j].m_data, m_nodes[i].m_edges[j].m_node[0].m_data, m_nodes[i].m_edges[j].m_node[1].m_data);
				}
				m_nodes.erase(m_nodes.begin() + i);
				delete borrar;
			}
		}
		return 1;

	}

	void imprimir()
	{
		cout << "Nodos" << endl;
		for (int i = 0; i<m_nodes.size(); i++)
		{
			cout << m_nodes[i]->m_data << endl;
		}
		cout << endl;

		cout << "Aristas" << endl;
		for (int i = 0; i<m_gedges.size(); i++)
		{
			cout << m_gedges[i]->m_data << endl;
		}


		cout << endl;

		cout << "conexiones" << endl;

		for (int i = 0; i<m_gedges.size(); i++)
		{
			cout << m_gedges[i]->m_data << " De " << m_gedges[i]->m_node[0]->m_data << " a " << m_gedges[i]->m_node[1]->m_data << endl;
		}
	}
	E conexion_nodos(N a, N b)
	{
		for (int x = 0; x<m_gedges.size(); x++)
		{

			if (m_gedges[x]->m_node[0]->m_data == a && m_gedges[x]->m_node[1]->m_data == b)
			{
				return m_gedges[x]->m_data;
			}

		}
		return 0;
	}


	void matriz_adyacencia()
	{
		for (int i = 0; i<m_nodes.size(); i++)
		{
			for (int j = 0; j<m_nodes.size(); j++)
			{
				m_ady[i][j] = conexion_nodos(m_nodes[i]->m_data, m_nodes[j]->m_data);
				cout << m_ady[i][j] << " ";
			}
			cout << endl;
		}
		return;
	}

	Grafo convertir_matriz_grafo()
	{
		Grafo m_graf;
		for (int i = 0; i<m_nodes.size(); i++)
		{
			m_graf.insert_node(m_nodes[i]->m_data);
		}
		for (int i = 0; i<m_nodes.size(); i++)
		{

			for (int j = 0; j<m_nodes.size(); j++)
			{
				if (m_ady[i][j] != 0)
				{
					m_graf.insert_edge(m_ady[i][j], m_nodes[i]->m_data, m_nodes[j]->m_data);


				}
			}
		}
		return m_graf;

	}

	int distancia[max_vert];
	bool visitado[max_vert];
	priority_queue< pair< N, E >, vector<pair< N, E > >, cmp > Q; //priority queue propia del c++, usamos el comparador definido para que el de menor valor este en el tope
	int V;                     //numero de vertices
	int previo[max_vert];         //para la impresion de caminos

								  //Impresion del camino mas corto desde el vertice inicial y final ingresados
	void print(int destino) {
		if (previo[destino] != -1)    //si aun poseo un vertice previo
			print(previo[destino]);
		cout << destino << endl;//recursivamente sigo explorando
								//terminada la recursion imprimo los vertices recorridos
	}

	void dijkstra(int inicial) {
		for (int i = 0; i <= m_nodes.size(); ++i) {
			distancia[i] = INF;  //inicializamos todas las distancias con valor infinito
			visitado[i] = 0; //no visitados
			previo[i] = -1;
		}
		pair< N, E > vnodo(inicial, 0);

		Q.push(vnodo);
		distancia[inicial] = 0;
		int actual, adyacente, peso;
		while (!Q.empty()) {
			actual = Q.top().first;
			Q.pop();
			if (!visitado[actual]) {

				visitado[actual] = 1;

				///numero edges que salen del nodo
				int cont = 0;
				for (int i = 0; i<m_nodes.size(); i++)
				{
					if (conexion_nodos(actual, m_nodes[i]->m_data)) cont++;
					// cout<<actual<<" "<<m_nodes[i]->m_data<<" "<<conexion_nodos(actual,m_nodes[i]->m_data)<<endl;
				}



				for (int i = 0; i < m_nodes.size(); ++i) {
					if (conexion_nodos(actual, m_nodes[i]->m_data))
					{
						adyacente = m_nodes[i]->m_data;   //id del vertice adyacente
						peso = conexion_nodos(actual, m_nodes[i]->m_data);       //peso de la arista que une actual con adyacente ( actual , adyacente )
						if (!visitado[adyacente]) {        //si el vertice adyacente no fue visitado
														   //Si la distancia del origen al vertice actual + peso de su arista es menor a la distancia del origen al vertice adyacente
							if (distancia[actual] + peso < distancia[adyacente]) {
								distancia[adyacente] = distancia[actual] + peso;  //relajamos el vertice actualizando la distancia
								previo[adyacente] = actual;                         //a su vez actualizamos el vertice previo
								Q.push(pair< N, E >(adyacente, distancia[adyacente])); //agregamos adyacente a la cola de prioridad
							}
						}
					}
				}
			}
		}



		cout << "Distancias mas cortas iniciando en vertice: " << inicial << endl;
		for (int i = 1; i <= m_nodes.size(); ++i) {
			cout << "Vertice " << i << " distancia mas corta = " << distancia[i] << endl;
		}

		cout << ("**************Impresion de camino mas corto**************") << endl;
		cout << ("Ingrese vertice destino: ");
		int destino;
		cin >> destino;
		print(destino);
		cout << endl;
	}



	/////hacer dijstrack
	/// hacer tabla hush
	/// matriz esparza
};



int main()
{
	Grafo<int, int> grafito;
	grafito.insert_node(1);
	grafito.insert_node(2);
	grafito.insert_node(3);
	grafito.insert_node(4);
	grafito.insert_node(5);
	grafito.insert_edge(1, 1, 2);
	grafito.insert_edge(2, 2, 4);
	grafito.insert_edge(2, 3, 4);
	grafito.insert_edge(3, 1, 3);
	grafito.insert_edge(4, 5, 4);
	grafito.insert_edge(2, 1, 5);
	grafito.insert_edge(1, 2, 3);
	grafito.insert_edge(1, 5, 3);



	grafito.imprimir();
	cout << endl;

	grafito.matriz_adyacencia();

	Grafo<int, int> m_graf;
	m_graf = grafito.convertir_matriz_grafo();
	m_graf.imprimir();

	int  inicial;

	cout << "Ingrese el vertice inicial: ";
	cin >> inicial;
	grafito.dijkstra(inicial);
	return 0;
}