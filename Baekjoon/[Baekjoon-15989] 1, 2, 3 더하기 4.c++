#include <iostream>
using namespace std;

int dp[10001][3];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    dp[1][0] = 1;
    dp[2][0] = 1, dp[2][1] = 1;
    dp[3][0] = 2, dp[3][2] = 1;

    for (int i = 4; i <= 10000; i++)
    {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
        dp[i][1] = dp[i - 2][1] + dp[i - 2][2];
        dp[i][2] = dp[i - 3][2];
    }

    // 0 1 2 3 4 5 6 7 8 9  10
    // 0 1 1 2 3 4 5 7 8 10 12
    // 0 0 1 0 1 1 1 1 2 1  2
    // 0 0 0 1 0 0 1 0 0 1  0

    while (t-- > 0)
    {
        int n;
        cin >> n;

        cout << dp[n][0] + dp[n][1] + dp[n][2] << "\n";
    }

    return 0;
}
