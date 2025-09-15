#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

long long n, p, q;
unordered_map<long long, long long> um;

long long re(long long x)
{
    long long tmp;

    if (um.find(x) != um.end())
        return um[x];

    tmp = re(x / p) + re(x / q);
    um[x] = tmp;

    return um[x];
}

int main()
{
    cin >> n >> p >> q;

    um.insert({0, 1});

    cout << re(n);

    return 0;
}
