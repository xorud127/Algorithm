#include <iostream>
using namespace std;

int n, d, k, c, cnt, ans;
int sushi[30002];
int visit[3001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> d >> k >> c;

    for (int i = 0; i < n; i++)
        cin >> sushi[i];

    for (int i = 0; i < k; i++)
    {
        if (visit[sushi[i]] == 0)
            cnt++;
        visit[sushi[i]]++;
    }
    if (visit[c] == 0)
        ans = cnt + 1;
    else
        ans = cnt;

    for (int i = k; i < n + k; i++)
    {
        int ad = i % n, rm = (i - k) % n;
        visit[sushi[rm]]--;
        if (visit[sushi[rm]] == 0)
            cnt--;
        if (visit[sushi[ad]] == 0)
            cnt++;
        visit[sushi[ad]]++;

        if (visit[c] == 0)
            ans = max(ans, cnt + 1);
        else
            ans = max(ans, cnt);
    }

    cout << ans;

    return 0;
}
