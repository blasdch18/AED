#include <iostream>

using namespace std;

void func1(int a)
{
   cout<<a<<endl;
}

void func2(int a)
{
   cout<<a+2<<endl;
}

void func(void (*pf)(int), int a)
{
    pf(a);
}
int main()
{
    cout << "Hello world!" << endl;
    func(func1,5);
    func(func2,8);
    return 0;
}
