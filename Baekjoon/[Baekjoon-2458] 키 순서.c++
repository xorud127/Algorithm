#include <iostream>
#include <vector>
using namespace std;

int inf = 987654321;
int nums[501][501];

void floyd(int n)
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (nums[i][j] > nums[i][k] + nums[k][j])
                    nums[i][j] = nums[i][k] + nums[k][j];
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            nums[i][j] = inf;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        nums[a][b] = 1;
    }

    floyd(n);

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if (nums[i][j] != inf || nums[j][i] != inf)
                cnt++;
        }
        if (cnt == n - 1)
            ans++;
    }
    cout << ans;

    return 0;
}
