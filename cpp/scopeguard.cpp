

#include <atomic>
#include <iostream>
#include <cstdlib>

using namespace std;

template<typename F, typename A>
class ScopeGuard
{
public:
    atomic<bool> _exited;
    F _f;
    A _a;
    
    ScopeGuard(F f, A a)
        : _exited(false), _f(f), _a(a)
    {
        cout << "Scope Created." << endl;
    }

    virtual ~ScopeGuard()
    {
        cout << "Scope Destruct." << endl;
        if (!_exited)
        {
            _exited.store(true);
            cout << "Scope calling exit function" << endl;
            _f(_a);
        }
    }
};

void inc(int& a)
{
    a++;
}

int main()
{
    int n = 1024;
    char* buffer = (char*)malloc(sizeof(char) * n);
    buffer[0] = 'a';
    buffer[1] = '\0';

    ScopeGuard<decltype(free), decltype(buffer)> guard(free, buffer);
    int a = 0;
    cout << "a: " << a << endl;
    {
        ScopeGuard<decltype(inc), int> g2(inc, a);
        cout << "a: " << a << endl;
    }
    cout << "a: " << a << endl;
    inc(a);
    cout << "a: " << a << endl;

    return 0;
}

