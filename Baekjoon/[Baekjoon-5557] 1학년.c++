#include <iostream>
using namespace std;

int n;
int nums[100];
long long dp[101][21];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    dp[0][nums[0]]++;

    for (int i = 1; i < n - 1; i++)
    {
        int val = nums[i];
        for (int j = 0; j <= 20; j++)
        {
            if (j - val >= 0 && dp[i - 1][j] != 0)
                dp[i][j - val] += dp[i - 1][j];
            if (j + val <= 20 && dp[i - 1][j] != 0)
                dp[i][j + val] += dp[i - 1][j];
        }
    }

    cout << dp[n - 2][nums[n - 1]];

    return 0;
}
