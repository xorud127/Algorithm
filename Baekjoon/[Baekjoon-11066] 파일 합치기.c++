#include <iostream>
using namespace std;

int dp[501][501], file[501], sum[501];

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            cin >> file[i];
            sum[i] = sum[i - 1] + file[i];
        }

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dp[i][j] = 0;

        for (int len = 2; len <= n; len++)
        {
            for (int i = 1; i <= n - len + 1; i++)
            {
                int j = i + len - 1;
                dp[i][j] = 987654321;

                for (int k = i; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
                }
            }
        }
        cout << dp[1][n] << "\n";
    }

    return 0;
}
