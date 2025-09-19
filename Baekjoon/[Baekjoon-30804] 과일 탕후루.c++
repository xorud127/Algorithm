#include <iostream>
using namespace std;

int n, flag, ans;
int tang[200001];
int cnt[10];

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> tang[i];

    int left = 0;
    for (int right = 0; right < n; right++)
    {
        if (cnt[tang[right]] == 0)
            flag++;
        cnt[tang[right]]++;

        while (flag > 2)
        {
            cnt[tang[left]]--;
            if (cnt[tang[left]] == 0)
                flag--;
            left++;
        }

        ans = max(ans, right - left + 1);
    }

    cout << ans;

    return 0;
}
