#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cost[21];
int dp[10001];

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, m;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> cost[i];
        cin >> m;

        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = cost[i]; j <= m; j++)
            {
                dp[j] += dp[j - cost[i]];
            }
        }

        cout << dp[m] << "\n";

        for (int i = 1; i <= m; i++)
            dp[i] = 0;
    }

    return 0;
}
