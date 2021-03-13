//https://leetcode.com/problems/fibonacci-number/
#include <iostream>
#include <unordered_map>
using namespace std;

int fib(int n)
{
    if (n==0)
        return 0;
    if (n==1)
        return 1;

    unordered_map<int,int> lookup;
    lookup[0]=0;
    lookup[1]=1;

    for(int i=2;i<=n;++i){
        lookup[i]=lookup[i-1]+lookup[i-2];
    }
    return lookup[n];
}

int fib_recursive(int n) {
    if (n==0)
        return 0;
    if (n==1)
        return 1;
    return fib(n-1)+fib(n-2);
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
