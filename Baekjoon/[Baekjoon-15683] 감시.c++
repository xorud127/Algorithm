#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int room[8][8];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<int> dir[6] = {{}, {0}, {0, 2}, {0, 3}, {0, 2, 3}, {0, 1, 2, 3}};
vector<pair<int, int>> cctv;
int ans = 987654321;

void dfs(int n, int m, int mx, int cnt)
{
    int tmp = 0;
    if (cnt == mx)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (room[i][j] == 0)
                    tmp++;
            }
        }

        ans = min(ans, tmp);
        return;
    }

    queue<pair<int, int>> q;
    int x_now = cctv[cnt].first;
    int y_now = cctv[cnt].second;
    int now = room[y_now][x_now];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < dir[now].size(); j++)
        {
            int turn = (i + dir[now][j]) % 4;

            int x_next = dx[turn] + x_now;
            int y_next = dy[turn] + y_now;

            while (x_next >= 0 && y_next >= 0 && x_next < m && y_next < n)
            {
                if (room[y_next][x_next] == 6)
                    break;
                else if (room[y_next][x_next] == 0)
                {
                    room[y_next][x_next] = 7;
                    q.push({x_next, y_next});
                }

                x_next += dx[turn];
                y_next += dy[turn];
            }
        }

        dfs(n, m, mx, cnt + 1);

        while (!q.empty())
        {
            int y_tmp = q.front().second;
            int x_tmp = q.front().first;
            q.pop();

            room[y_tmp][x_tmp] = 0;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> room[i][j];
            if (room[i][j] != 0 && room[i][j] != 6)
                cctv.push_back({j, i});
        }
    }

    dfs(n, m, cctv.size(), 0);

    cout << ans;

    return 0;
}
