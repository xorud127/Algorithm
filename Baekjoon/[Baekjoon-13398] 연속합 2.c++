#include <iostream>
using namespace std;

int nums[100001];
int dp[100001][2];
int n, mx;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> nums[i];

    dp[1][0] = nums[1];
    dp[1][1] = 0;
    mx = nums[1];

    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = max(dp[i - 1][0] + nums[i], nums[i]);
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + nums[i]);

        mx = max(mx, max(dp[i][0], dp[i][1]));
    }

    cout << mx;

    return 0;
}
