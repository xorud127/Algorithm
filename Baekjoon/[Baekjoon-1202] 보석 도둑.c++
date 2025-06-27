#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

pair<int, int> info[300001];
int bag[300001];
priority_queue<int> pq;
long long ans;

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    int n, k, idx = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int m, v;
        cin >> m >> v;
        info[i] = {m, v};
    }
    for (int i = 0; i < k; i++)
    {
        cin >> bag[i];
    }

    sort(info, info + n);
    sort(bag, bag + k);

    for (int i = 0; i < k; i++)
    {
        while (idx < n && info[idx].first <= bag[i])
        {
            pq.push(info[idx].second);
            idx++;
        }

        if (pq.empty())
            continue;
        ans += pq.top();
        pq.pop();
    }

    cout << ans;

    return 0;
}
