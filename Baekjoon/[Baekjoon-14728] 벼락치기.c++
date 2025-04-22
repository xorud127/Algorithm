#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> study;
int dp[101][10001];

int main()
{
    int n, t;
    cin >> n >> t;

    for (int i = 0; i < n; i++)
    {
        int k, s;
        cin >> k >> s;
        study.push_back({k, s});
    }

    for (int i = 0; i < n; i++)
    {
        int score = study[i].second, time = study[i].first;
        for (int j = 1; j <= t; j++)
        {
            if (j - time >= 0)
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - time] + score);
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        }
    }

    cout << dp[n][t];

    return 0;
}
