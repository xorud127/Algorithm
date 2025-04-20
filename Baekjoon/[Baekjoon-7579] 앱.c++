#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cost[101], bite[101];
int dp[101][10001];
int sum;

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> bite[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
        sum += cost[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j - cost[i] >= 0)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + bite[i]);
            }
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }

    for (int i = 0; i <= sum; i++)
    {
        if (dp[n][i] >= m)
        {
            cout << i;
            break;
        }
    }

    return 0;
}
