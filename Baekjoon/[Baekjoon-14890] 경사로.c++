#include <iostream>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int map1[101][101], map2[101][101];
int ans;

void pass(int n, int l, int road[][101])
{
    for (int i = 0; i < n; i++)
    {
        bool slope[101] = {0};
        bool flag = 1;

        // 높이차 2 이상
        for (int j = 0; j < n - 1; j++)
        {
            if (abs(road[i][j] - road[i][j + 1]) > 1)
            {
                flag = 0;
                break;
            }
            // 경사로를 위에서 아래로
            if (road[i][j] == road[i][j + 1] + 1)
            {
                int cur = road[i][j + 1];
                for (int k = j + 1; k < j + l + 1; k++)
                {
                    if (k >= n || road[i][k] != cur)
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag)
                {
                    for (int k = j + 1; k < j + 1 + l; k++)
                        slope[k] = 1;
                }
                else
                    break;
            }

            // 경사를 아래서 위로
            if (road[i][j] == road[i][j + 1] - 1)
            {
                int cur = road[i][j];
                for (int k = j; k > j - l; k--)
                {
                    if (k < 0 || road[i][k] != cur || slope[k] == 1)
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag)
                {
                    for (int k = j; k > j - l; k--)
                        slope[k] = 1;
                }
                else
                    break;
            }
        }
        if (flag)
            ans++;
    }
}

int main()
{
    int n, l;
    cin >> n >> l;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> map1[i][j];
            map2[j][i] = map1[i][j];
        }

    pass(n, l, map1);
    pass(n, l, map2);

    cout << ans;

    return 0;
}
