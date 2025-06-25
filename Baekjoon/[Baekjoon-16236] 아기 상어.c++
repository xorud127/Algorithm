#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int sea[21][21], visit[21][21];
vector<pair<int, int>> shark;
int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};
int ans = 0, size_shark = 2, cnt = 0;

bool bfs(int n)
{
    queue<pair<int, int>> q;
    vector<pair<int, pair<int, int>>> fish;
    q.push({shark.front().first, shark.front().second});
    visit[shark.front().second][shark.front().first] = 1;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int next_x = x + dx[i];
            int next_y = y + dy[i];

            if (visit[next_y][next_x] == 0 && next_x >= 0 && next_y >= 0 && next_x < n && next_y < n)
            {
                if (size_shark < sea[next_y][next_x])
                    continue;

                q.push({next_x, next_y});
                visit[next_y][next_x] = visit[y][x] + 1;

                if (sea[next_y][next_x] != 0 && sea[next_y][next_x] < size_shark)
                {
                    fish.push_back({visit[next_y][next_x], {next_y, next_x}});
                }
            }
        }
    }

    if (fish.empty())
        return 0;
    else
    {
        sort(fish.begin(), fish.end());
        int y = fish.front().second.first;
        int x = fish.front().second.second;

        ans += fish.front().first - 1;
        sea[y][x] = 0;
        shark.pop_back();
        shark.push_back({x, y});
        return 1;
    }

    return 0;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> sea[i][j];
            if (sea[i][j] == 9)
            {
                shark.push_back({j, i});
                sea[i][j] = 0;
            }
        }
    }

    while (bfs(n))
    {
        cnt++;
        if (cnt == size_shark)
        {
            cnt = 0;
            size_shark++;
        }

        memset(visit, 0, sizeof(visit));
    }

    cout << ans;

    return 0;
}
