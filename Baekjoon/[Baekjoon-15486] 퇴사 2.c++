#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> v;
int dp[1500002];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int t, p;
        cin >> t >> p;
        v.push_back({t, p});
    }

    for (int i = 1; i <= n; i++)
    {
        int t = v[i - 1].first, p = v[i - 1].second;

        dp[i] = max(dp[i], dp[i - 1]);
        if (i + t <= n + 1)
        {
            dp[i + t] = max(dp[i + t], dp[i] + p);
        }
    }

    dp[n + 1] = max(dp[n], dp[n + 1]);
    cout << dp[n + 1];

    return 0;
}
