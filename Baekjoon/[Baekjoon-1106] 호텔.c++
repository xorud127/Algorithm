#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> hotel;
int dp[10001];

int main()
{
    int c, n;
    cin >> c >> n;

    for (int i = 1; i <= n; i++)
    {
        int cost, people;
        cin >> cost >> people;
        hotel.push_back({cost, people});
    }

    for (int i = 0; i <= 10000; i++)
        dp[i] = 987654321;
    dp[0] = 0;

    for (int i = 0; i < n; i++)
    {
        int cost = hotel[i].first, people = hotel[i].second;
        for (int j = people; j <= 10000; j++)
        {
            dp[j] = min(dp[j], dp[j - people] + cost);
        }
    }

    int ans = 987654321;
    for (int i = c; i <= 10000; i++)
    {
        ans = min(ans, dp[i]);
    }
    cout << ans;

    return 0;
}
