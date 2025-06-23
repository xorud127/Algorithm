#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int food[10][10];
int ground[10][10];
deque<int> tree[10][10];
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> food[i][j];
            ground[i][j] = 5;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        tree[x - 1][y - 1].push_front(z);
    }

    while (k-- > 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int cnt = 0;

                for (int l = 0; l < tree[i][j].size(); l++)
                {
                    if (ground[i][j] >= tree[i][j][l])
                    {
                        ground[i][j] -= tree[i][j][l];
                        tree[i][j][l]++;
                    }
                    else
                        cnt++;
                }

                for (int l = 0; l < cnt; l++)
                {
                    int tmp = tree[i][j].back();
                    tree[i][j].pop_back();
                    ground[i][j] += tmp / 2;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int l = 0; l < tree[i][j].size(); l++)
                {
                    if (tree[i][j][l] % 5 == 0)
                    {
                        for (int m = 0; m < 8; m++)
                        {
                            int next_x = j + dx[m];
                            int next_y = i + dy[m];

                            if (next_x >= 0 && next_y >= 0 && next_x < n && next_y < n)
                            {
                                tree[next_y][next_x].push_front(1);
                            }
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                ground[i][j] += food[i][j];
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans += tree[i][j].size();
        }
    }
    cout << ans;

    return 0;
}
