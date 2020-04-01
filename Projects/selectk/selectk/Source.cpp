#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <ctime>

#define tam1 100000

using namespace std;
void partition_(vector <int> &A, int &p, vector<int> &L, int &val, vector <int> &R)
{
	for (int i = 0; i<A.size(); i++)
	{
		if (i == p) {}
		else if (A[i] <= A[p]) { L.push_back(A[i]); }
		else if (A[i] > A[p]) { R.push_back(A[i]); }
	}
	val = A[p];
}

int select_k(vector <int> &A, int k)
{
	//srand(time(NULL));
	int p;
	vector <int> L, R;

	if (A.size() == 1)
	{
		return A[0];
	}
	p = rand() % (A.size());
	int val;
	partition_(A, p, L, val, R);

	if (L.size() == k) { return A[val]; }
	else if (L.size()>k) { select_k(L, k); }
	else if (L.size()<k) { return select_k(R, k - L.size() - 1); }
}


vector<int> Merge(vector <int> A, vector <int> B);

vector<int> mergeSort(vector <int> &A)
{
	if (A.size() <= 1)
	{
		return A;
	}
	int temp = A.size() / 2;

	vector<int> left(A.begin(), A.begin() + temp);
	vector<int> right(A.begin() + temp, A.end());

	return Merge(mergeSort(left), mergeSort(right));
}

vector<int> Merge(vector <int> A, vector <int> B)
{
	vector <int> resultado;
	while (!A.empty() && !B.empty())
	{

		if (A[0] < B[0])
		{

			resultado.push_back(A[0]);
			A.erase(A.begin());
		}
		else
		{
			resultado.push_back(B[0]);
			B.erase(B.begin());
		}
	}
	resultado.insert(resultado.end(), A.begin(), A.end());
	resultado.insert(resultado.end(), B.begin(), B.end());
	return resultado;
}

int naive_select_k(vector <int> &A, int k)
{
	mergeSort(A);
	return A[k];
}

int main()
{
	clock_t t0, t1;

	srand(time(NULL));
	vector <int> A;
	vector <int> B;
	vector <int> C;
	vector <int> D;
	//B,C,D=A;

	for (int i = 0; i<tam1; i++)
	{
		A.push_back(rand());
	}
	// Imprimir Lista
	/*
	for(int i=0 ; i<tam1 ; i++)
	{
	cout<<A[i]<< " " ;
	}*/
	cout << endl;
	t0 = clock();
	cout << select_k(A, 6);
	t1 = clock();

	double time = (double(t1 - t0) / CLOCKS_PER_SEC);
	cout << endl << "Execution Time: " << time / CLOCKS_PER_SEC << endl;

	cout << endl;
	t0 = clock();
	//cout<<naive_select_k(B,rand()%A.size());
	t1 = clock();

	time = (double(t1 - t0) / CLOCKS_PER_SEC);
	cout << endl << "Execution Time: " << time / CLOCKS_PER_SEC << endl;
	//cout<<naive_select_k(A,6);

}