#include <iostream>
#include <future>

using namespace std;

std::mutex mu;
std::condition_variable cond;

int factorial(std::future<int>& f){
    int res=1;

    int n= f.get();
    for(int i=n ; i>1; i--){
        res *=i;
    }
    cout <<"Result is :" << res << endl;
    return res;
    //x=res;
}

int main()
{
    int x;
    //std:: thread t1(factorial , 4 ,std::ref(x));
    //std::future<int> fu= std:: async(std::launch::async | std::launch::deferred, factorial, 4);
    std::promise<int>p;
    std::future<int> f= p.get_future();

    std::future<int> fu= std::async(std::launch::async, factorial,std::ref(f));

    // do something else
    std::this_thread::sleep_for(chrono::milliseconds(20));
    p.set_value(4);

    x= fu.get();
    cout <<"Get from child : " << x << endl;
    //t1.join();
    return 0;
}
