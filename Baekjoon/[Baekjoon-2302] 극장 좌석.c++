#include <iostream>
#include <vector>
using namespace std;

int n, m, ans = 1;
int dp[41];
vector<int> vvip;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int tmp;
        cin >> tmp;
        vvip.push_back(tmp);
    }

    dp[0] = 1, dp[1] = 1, dp[2] = 2;
    for (int i = 3; i <= 40; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int flag = 0;
    for (auto i : vvip)
    {
        ans *= dp[i - flag - 1];
        flag = i;
    }
    ans *= dp[n - flag];

    cout << ans;

    return 0;
}
