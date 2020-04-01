#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

mutex io_mutex;

void F1(char c, int n)
{
	double sum = 0;
	for (long i = 0; i < 10; ++i)
	{
		io_mutex.lock();		
		printf("%c", c);
		//sum += 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1;
		io_mutex.unlock();
	}
}

int main()
{
	int i = 0, nThreads = thread::hardware_concurrency();
	vector<thread> ths(nThreads);

	for (i = 0; i < nThreads; i++)
		ths[i] = thread(F1, char('a' + i), 0);

	for (i = 0; i < nThreads; i++)
		ths[i].join();

	getchar();
	return 0;
}
