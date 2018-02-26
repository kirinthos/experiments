// http://stackoverflow.com/questions/37493026/why-doesnt-this-code-compile-with-clang-but-with-gcc

#include <iostream>

template <typename Function, typename... Args>
auto Call(Function func, Args&&... args) -> typename std::result_of<Function(Args&&...)>::type
{
    return func(std::forward<Args>(args)...);
}

template <typename T, typename... Args>
T (*Log( T (*FuncPtr)(Args...) ))(Args...)
{
    return FuncPtr;
}

int main()
{
    auto r = Log(Call<int(int), int>)([](int x){
        return x*10;
    }, 10);
    std::cerr << r << std::endl;
}
