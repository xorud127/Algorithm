#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long m, ans = 2000000000;
long long nums[100000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    sort(nums, nums + n);

    int sec = 0;
    for (int fir = 0; fir < n; fir++)
    {
        while (sec < n && nums[sec] - nums[fir] < m)
        {
            sec++;
        }

        if (nums[sec] - nums[fir] >= m)
            ans = min(ans, nums[sec] - nums[fir]);
    }

    cout << ans;

    return 0;
}
