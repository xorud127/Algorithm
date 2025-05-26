#include <iostream>
#include <vector>
using namespace std;

long long mod[1001];

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    int n, m, tmp;
    long long sum = 0, ans = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        sum += tmp;
        mod[sum % m]++; // 나머지 값만 저장
        if (sum % m == 0)
            ans++;
    }

    for (int i = 0; i <= m; i++) // 예로 2끼리 구간을 구해야 0되니까까
    {
        ans += mod[i] * (mod[i] - 1) / 2;
    }

    cout << ans;

    return 0;
}
