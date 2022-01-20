#include<memory>
#include<iostream>
using namespace std;

struct S {
    S() { cout << "make an S\n"; }
    ~S() { cout << "destroy an S\n"; }
    S(const S&) { cout << "copy initialize an S\n"; }
    S& operator=(const S&) { cout << "copy assign an S\n"; }
};
S* f()
{
    return new S;   // who is responsible for deleting this S?
};
unique_ptr<S> g()
{
    return make_unique<S>();    // explicitly transfer responsibility for deleting this S
}
S* test_leak()
{
    cout << "start main\n";
    S* p = f();
    cout << "after f() before g()\n";
    //  S* q = g(); // this error would be caught by the compiler
    unique_ptr<S> q = g();//return of q in this function gives segmentaion fault in main
    cout << "exit main\n";
    // leaks *p
    // implicitly deletes *q
    p;
}
int main(){
    auto t=test_leak();
    if(t!= nullptr){
        cout<<"t is not null"<<endl;
        delete t;
    }
    return 0;
}