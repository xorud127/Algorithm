#include <iostream>
#include <vector>
using namespace std;

int num[100001], visit[100001];
int cnt;

void dfs(int x)
{
    visit[x] = 1;
    int nx = num[x];

    if (visit[nx] == 0)
    {
        dfs(nx);
    }
    else if (visit[nx] == 1)
    {
        for (int i = nx; i != x; i = num[i])
        {
            cnt++;
        }
        cnt++;
    }
    visit[x] = 2;
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            visit[i] = 0;
            cin >> num[i];
        }

        cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (visit[i] == 0)
                dfs(i);
        }
        cout << n - cnt << "\n";
    }

    return 0;
}
