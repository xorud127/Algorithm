#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int cnt;

void picano()
{
    int n1 = 1, n2 = 1, tmp;
    cnt = 1;
    v.push_back(0);
    v.push_back(1);

    while (n1 != 0 || n2 != 1)
    {
        cnt++;

        tmp = (n1 + n2) % 1000000;
        n1 = n2;
        n2 = tmp;

        v.push_back(n1);
    }
    v.pop_back();
}

int main()
{
    long long n;
    cin >> n;

    picano();

    cout << v[n % cnt];

    return 0;
}
