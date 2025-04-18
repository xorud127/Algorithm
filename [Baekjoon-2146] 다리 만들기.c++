#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int m[100][100], visit[100][100], land[100][100];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int ans = 987654321;

void makeLand(int n, int x, int y, int cnt)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    land[y][x] = cnt;
    visit[y][x] = 1;

    while (!q.empty())
    {
        int x_now = q.front().first;
        int y_now = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int x_next = x_now + dx[i];
            int y_next = y_now + dy[i];

            if (x_next >= 0 && x_next < n && y_next >= 0 && y_next < n && visit[y_next][x_next] == 0)
            {
                if (m[y_next][x_next] == 1)
                {
                    q.push({x_next, y_next});
                    land[y_next][x_next] = cnt;
                    visit[y_next][x_next] = 1;
                }
            }
        }
    }
}

void bfs(int n, int cnt)
{
    int val[100][100];
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            val[i][j] = 0;
            if (land[i][j] == cnt)
            {
                q.push({j, i});
            }
        }
    }

    while (!q.empty())
    {
        int x_now = q.front().first;
        int y_now = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int x_next = x_now + dx[i];
            int y_next = y_now + dy[i];

            if (x_next >= 0 && x_next < n && y_next >= 0 && y_next < n)
            {
                if (m[y_next][x_next] == 0)
                {
                    if (val[y_next][x_next] == 0)
                    {
                        val[y_next][x_next] = val[y_now][x_now] + 1;
                        q.push({x_next, y_next});
                    }
                }
                else
                {
                    if (land[y_next][x_next] != cnt)
                    {
                        ans = min(ans, val[y_now][x_now]);
                        return;
                    }
                }
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
        }
    }

    int cnt = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visit[i][j] == 1 || m[i][j] == 0)
                continue;

            makeLand(n, j, i, cnt);
            cnt++;
        }
    }

    for (int i = 1; i < cnt; i++)
    {
        bfs(n, i);
    }

    cout << ans;

    return 0;
}
