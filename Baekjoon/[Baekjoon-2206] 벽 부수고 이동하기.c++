#include <iostream>
#include <queue>
#include <string>
using namespace std;

int world[1000][1000], dp[1000][1000][2];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs(int n, int m)
{
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 1});
    dp[0][0][1] = 1;

    while (!q.empty())
    {
        int x_now = q.front().first.first;
        int y_now = q.front().first.second;
        int chance = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int x_next = x_now + dx[i];
            int y_next = y_now + dy[i];

            if (x_next >= 0 && x_next < m && y_next >= 0 && y_next < n)
            {
                if (chance == 1)
                {
                    int val = dp[y_now][x_now][1];
                    if (world[y_next][x_next] == 1)
                    {
                        if (dp[y_next][x_next][0] == 0 || dp[y_next][x_next][0] > val + 1)
                        {
                            dp[y_next][x_next][0] = val + 1;
                            q.push({{x_next, y_next}, 0});
                        }
                    }
                    else
                    {
                        if (dp[y_next][x_next][1] == 0 || dp[y_next][x_next][1] > val + 1)
                        {
                            dp[y_next][x_next][1] = val + 1;
                            q.push({{x_next, y_next}, 1});
                        }
                    }
                }
                else
                {
                    int val = dp[y_now][x_now][0];
                    if (world[y_next][x_next] == 0)
                    {
                        if (dp[y_next][x_next][0] == 0 || dp[y_next][x_next][0] > val + 1)
                        {
                            dp[y_next][x_next][0] = val + 1;
                            q.push({{x_next, y_next}, 0});
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < m; j++)
        {
            world[i][j] = tmp[j] - '0';
        }
    }

    bfs(n, m);

    int res1 = dp[n - 1][m - 1][0];
    int res2 = dp[n - 1][m - 1][1];
    if (res1 == 0 && res2 == 0)
        cout << -1;
    else if (res1 == 0)
        cout << res2;
    else if (res2 == 0)
        cout << res1;
    else
        cout << min(res1, res2);

    return 0;
}
