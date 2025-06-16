#include <iostream>
#include <vector>
using namespace std;

int ladder[31][11];
int ans = 987654321;

bool check(int n, int h)
{
    for (int i = 1; i <= n; i++)
    {
        int tmp = i;
        for (int j = 1; j <= h; j++)
        {
            if (tmp + 1 <= n && ladder[j][tmp] == 1)
                tmp++;
            else if (tmp - 1 > 0 && ladder[j][tmp - 1] == 1)
                tmp--;
        }

        if (tmp != i)
            return false;
    }
    return true;
}

void dfs(int n, int h, int cnt, int y)
{
    if (cnt >= ans)
        return;
    if (check(n, h))
    {
        ans = cnt;
        return;
    }
    if (cnt == 3)
        return;

    for (int i = y; i <= h; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (ladder[i][j] == 0 && ladder[i][j - 1] == 0 && ladder[i][j + 1] == 0)
            {
                ladder[i][j] = 1;
                dfs(n, h, cnt + 1, i);
                ladder[i][j] = 0;
            }
        }
    }
}

int main()
{
    int n, m, h;
    cin >> n >> m >> h;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        ladder[a][b] = 1;
    }

    dfs(n, h, 0, 1);

    cout << (ans > 3 ? -1 : ans) << '\n';

    return 0;
}
