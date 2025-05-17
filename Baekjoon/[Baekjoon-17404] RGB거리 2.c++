#include <iostream>
using namespace std;

int color[1001][3], dp[1001][3];
int ans = 987654321;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> color[i][0] >> color[i][1] >> color[i][2];
    }

    for (int start = 0; start <= 2; start++)
    {
        for (int i = 0; i <= 2; i++)
        {
            if (i == start)
                dp[1][i] = color[1][i];
            else
                dp[1][i] = 987654321;
        }

        for (int i = 2; i <= n; i++)
        {
            dp[i][0] = color[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] = color[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = color[i][2] + min(dp[i - 1][1], dp[i - 1][0]);
        }

        for (int i = 0; i <= 2; i++)
        {
            if (i == start)
                continue;
            ans = min(ans, dp[n][i]);
        }
    }

    cout << ans;

    return 0;
}
