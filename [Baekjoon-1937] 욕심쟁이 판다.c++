#include <iostream>
#include <vector>
using namespace std;

int nums[500][500], dp[500][500], visit[500][500];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int mx;

void dfs(int n, int x, int y, int cnt)
{
    int x_next, y_next;

    for (int i = 0; i < 4; i++)
    {
        x_next = dx[i] + x;
        y_next = dy[i] + y;
        if (x_next < 0 || y_next < 0 || x_next >= n || y_next >= n)
            continue;

        if (nums[y][x] < nums[y_next][x_next])
        {
            if (visit[y_next][x_next] == 1)
            {
                dp[y][x] = max(dp[y][x], dp[y_next][x_next] + 1);
            }
            else
            {
                dfs(n, x_next, y_next, cnt + 1);
                dp[y][x] = max(dp[y][x], dp[y_next][x_next] + 1);
            }
        }
    }
    visit[y][x] = 1;
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> nums[i][j];
            dp[i][j] = 1;
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            dfs(n, j, i, 0);
            mx = max(mx, dp[i][j]);
        }

    cout << mx;

    return 0;
}
