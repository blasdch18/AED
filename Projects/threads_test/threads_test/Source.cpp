#include <iostream>
#include <thread>

using namespace std;
void foo()
{
	cout <<"1"<<endl;
}
void bar(int x)
{
	cout << x << endl;
}
int main()
{
	std::thread first(foo);
	
	std::thread second(bar, 8);
	first.join();
	second.join();
	system("pause");
	return 0;

}