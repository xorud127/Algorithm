#include <iostream>
#include <string>
using namespace std;

int dp[4001][4001];
int mx;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;

    for (int i = 1; i <= a.length(); i++)
    {
        for (int j = 1; j <= b.length(); j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
                dp[i][j] = 0;
            mx = max(mx, dp[i][j]);
        }
    }

    cout << mx;

    return 0;
}
