#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int nums[101], visit[101];
vector<int> ans;

void dfs(int n, int x)
{
    int nx = nums[x];
    visit[x] = 1;

    if (visit[nx] == 0)
    {
        dfs(n, nx);
    }
    else if (visit[nx] == 1)
    {
        for (int i = nx; i != x; i = nums[i])
        {
            ans.push_back(i);
            visit[i] = 2;
        }
        ans.push_back(x);
    }
    visit[x] = 2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> nums[i];

    for (int i = 1; i <= n; i++)
    {
        if (visit[i] == 0)
            dfs(n, i);
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << "\n";

    return 0;
}
