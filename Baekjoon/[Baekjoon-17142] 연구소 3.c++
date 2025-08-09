#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, ans = 987654321;
int map[50][50];
int visit[50][50];
vector<pair<int, int>> v;
vector<int> choice;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs()
{
    queue<pair<int, int>> q;
    int mx = 0;

    for (int i = 0; i < choice.size(); i++)
    {
        visit[v[choice[i]].second][v[choice[i]].first] = 0;
        q.push({v[choice[i]].first, v[choice[i]].second});
    }

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        int val = visit[y][x];
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx_x = x + dx[i];
            int nx_y = y + dy[i];

            if (nx_x >= 0 && nx_x < n && nx_y >= 0 && nx_y < n && map[nx_y][nx_x] != 1)
            {
                if (visit[nx_y][nx_x] == -1)
                {
                    if (map[nx_y][nx_x] == 0)
                    {
                        visit[nx_y][nx_x] = val + 1;
                        q.push({nx_x, nx_y});
                        mx = max(mx, val + 1);
                    }
                    else if (map[nx_y][nx_x] == 2)
                    {
                        visit[nx_y][nx_x] = val + 1;
                        q.push({nx_x, nx_y});
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visit[i][j] == -1 && map[i][j] == 0)
                return;
        }
    }

    ans = min(ans, mx);
}

void dfs(int idx, int cnt)
{
    if (cnt == m)
    {
        memset(visit, -1, sizeof(visit));

        bfs();

        return;
    }

    for (int i = idx; i < v.size(); i++)
    {
        choice.push_back(i);
        dfs(i + 1, cnt + 1);
        choice.pop_back();
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 2)
                v.push_back({j, i});
        }
    }

    dfs(0, 0);

    if (ans == 987654321)
        cout << -1;
    else
        cout << ans;

    return 0;
}
