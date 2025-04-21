#include <iostream>
using namespace std;

int ball[31], weight[31];
int dp[31][15001];
int sum;

int main()
{
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> weight[i];
        sum += weight[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> ball[i];
    }

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (dp[i - 1][j])
            {
                dp[i][j] = 1;
                dp[i][j + weight[i]] = 1;
                dp[i][abs(j - weight[i])] = 1; // 추 반대쪽
            }
        }
    }

    for (int i = 1; i <= m; i++)
    {
        if (ball[i] > sum) // ball크기가 더 큼큼
            cout << "N ";
        else if (dp[n][ball[i]])
            cout << "Y ";
        else
            cout << "N ";
    }

    return 0;
}
