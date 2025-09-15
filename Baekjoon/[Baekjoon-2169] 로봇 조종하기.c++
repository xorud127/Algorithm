#include <iostream>
#include <queue>
using namespace std;

int n, m;
int dx[3] = {-1, 0, 1};
int dy[3] = {0, 1, 0};
int nums[1001][1001], dp[1001][1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> nums[i][j];
        }
    }

    dp[0][0] = nums[0][0];
    for (int i = 1; i < m; i++)
    {
        dp[0][i] = dp[0][i - 1] + nums[0][i];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dp[i][j] = dp[i - 1][j] + nums[i][j];

            int tmp = nums[i][j];
            for (int k = j - 1; k >= 0; k--)
            {
                tmp += nums[i][k];
                dp[i][j] = max(dp[i][j], dp[i - 1][k] + tmp);
            }
            tmp = nums[i][j];
            for (int k = j + 1; k < m; k++)
            {
                tmp += nums[i][k];
                dp[i][j] = max(dp[i][j], dp[i - 1][k] + tmp);
            }
        }
    }

    cout << dp[n - 1][m - 1];

    return 0;
}
