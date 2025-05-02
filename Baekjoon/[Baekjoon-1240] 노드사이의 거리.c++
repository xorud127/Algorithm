#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> v[1001];
int visit[1001];
int ans;

void dfs(int s, int e, int d)
{
    if (s == e)
    {
        ans = d;
        return;
    }

    for (int i = 0; i < v[s].size(); i++)
    {
        int next = v[s][i].first;
        int dis = v[s][i].second + d;

        if (visit[next] == 0)
        {
            visit[next] = 1;
            dfs(next, e, dis);
            visit[next] = 0;
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        ans = 0;

        visit[a] = 1;
        dfs(a, b, 0);
        cout << ans << "\n";

        for (int i = 1; i <= n; i++)
            visit[i] = 0;
    }

    return 0;
}
