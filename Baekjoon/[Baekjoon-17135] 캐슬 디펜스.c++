#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, d, mxkill;
int map[16][16];
int map2[16][16];
vector<int> pos;

int dist(int x, int y, int xx, int yy)
{
    return abs(x - xx) + abs(y - yy);
}

void dfs(int idx, int cnt)
{
    if (cnt == 3)
    { // map copy
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                map2[i][j] = map[i][j];

        int kill = 0;

        for (int i = 0; i < n; i++)
        {
            vector<pair<int, int>> e_kill;
            vector<pair<int, int>> tmp;
            for (int col : pos)
            {
                for (int j = 0; j < n; j++)
                {
                    for (int k = 0; k < m; k++)
                    {
                        if (map2[j][k] == 1 && dist(col, n, k, j) <= d)
                            tmp.push_back({k, j});
                    }
                }

                if (tmp.empty())
                    continue;

                sort(tmp.begin(), tmp.end(),
                     [&](const pair<int, int> &A, const pair<int, int> &B)
                     {
                         int da = dist(col, n, A.first, A.second);
                         int db = dist(col, n, B.first, B.second);
                         if (da != db)
                             return da < db;
                         return A.first < B.first;
                     });
                e_kill.push_back(tmp.front());
                tmp.clear();
            }

            for (auto [x, y] : e_kill)
            {
                if (map2[y][x] == 1)
                {
                    map2[y][x] = 0;
                    ++kill;
                }
            }

            // move enemy
            for (int j = n - 1; j > 0; j--)
            {
                for (int k = 0; k < m; k++)
                {
                    map2[j][k] = map2[j - 1][k];
                }
            }
            for (int k = 0; k < m; k++)
                map2[0][k] = 0;
        }

        mxkill = max(mxkill, kill);
        return;
    }

    for (int i = idx; i < m; i++)
    {
        pos.push_back(i);
        dfs(i + 1, cnt + 1);
        pos.pop_back();
    }
}

int main()
{
    cin >> n >> m >> d;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    dfs(0, 0);

    cout << mxkill;

    return 0;
}
