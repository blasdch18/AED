#include <iostream>
#include <vector>
#include <thread>
using namespace std;

int Partition(int *num, int izq, int der)
{
	int p = izq;
	for (int i = p + 1; i <= der; ++i)
	{
		if (num[i] < num[p])
		{
			swap(num[i], num[p]);
			if (i != p + 1)
			{
				swap(num[i], num[p + 1]);
			}
			p = p + 1;
		}
	}

	return p;
}
void QuickSort(int *num, int izq, int der)
{
	if (izq >= der) return;
	thread th1;
	thread th2;
	int p = Partition(num, izq, der);
	th1 = thread(QuickSort, num, izq, p - 1);
	th2 = thread(QuickSort, num, p + 1, der);
	th1.join();
	th2.join();
}

int main()
{
	int a[100];////unsorted array
	for (int j = 0; j<100; j++)
	{
		a[j] = rand() % 1000;
		cout << a[j] << " ";
	}

	cout << "x";
	int i = 0;
	thread th;


	th = thread(QuickSort, a, 0, (sizeof(a) / 4));
	th.join();
	cout << endl << endl;

	for (int i = 1; i <= (sizeof(a) / 4); i++) {
		cout << a[i]<<" ";
	}

	getchar();
	return 0;

}

