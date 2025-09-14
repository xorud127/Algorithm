#include <iostream>
using namespace std;

int t, w, ans;
int nums[1001];
int dp[31][1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t >> w;
    for (int i = 1; i <= t; i++)
        cin >> nums[i];

    for (int i = 1; i <= t; i++)
    {
        if (nums[i] == 1)
            dp[0][i] = dp[0][i - 1] + 1;
        else
            dp[0][i] = dp[0][i - 1];
    }

    for (int i = 1; i <= w; i++)
    {
        int tmp = i % 2 + 1;

        for (int j = i; j <= t; j++)
        {
            if (nums[j] == tmp)
                dp[i][j] = max(dp[i - 1][j - 1], dp[i][j - 1]) + 1;
            else
                dp[i][j] = max(dp[i - 1][j - 1], dp[i][j - 1]);
        }
    }

    for (int i = 0; i <= w; i++)
        ans = max(ans, dp[i][t]);

    cout << ans;

    return 0;
}
