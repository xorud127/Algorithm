#include <iostream>
#include <string>
using namespace std;

int dp[5001];

int main()
{
    string str;
    cin >> str;

    dp[0] = 1;
    if (str[0] == '0')
    {
        cout << 0;
        return 0;
    }
    dp[1] = 1;

    for (int i = 2; i <= str.length(); i++)
    {
        int fir = str[i - 2] - '0', sec = str[i - 1] - '0';

        if (sec > 0)
            dp[i] = (dp[i] + dp[i - 1]) % 1000000;
        if (fir * 10 + sec <= 26 && fir != 0)
            dp[i] = (dp[i] + dp[i - 2]) % 1000000;
    }

    cout << dp[str.length()];

    return 0;
}
