#include <iostream>
#include <algorithm>
using namespace std;

int nums[200];
int dp[200];
int mx;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;

        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                if (dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    mx = max(mx, dp[i]);
                }
            }
        }
    }

    cout << n - mx;

    return 0;
}
