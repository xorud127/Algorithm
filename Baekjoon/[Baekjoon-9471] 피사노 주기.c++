#include <iostream>
using namespace std;

int picano(int m)
{
    int m1 = 1, m2 = 1, cnt = 1, tmp;
    while (m1 != 0 || m2 != 1)
    {
        cnt++;

        tmp = (m1 + m2) % m;
        m1 = m2;
        m2 = tmp;
    }
    return cnt;
}

int main()
{
    ios_base ::sync_with_stdio(0);
    int n, m, idx;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> idx >> m;
        cout << i + 1 << " " << picano(m) << "\n";
    }

    return 0;
}
