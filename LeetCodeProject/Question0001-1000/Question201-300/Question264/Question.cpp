/*


*/
#include"Question.h"
int nthUglyNumber(int n) {
    int cur = 1;
    vector<int> dp(n + 1);
    dp[1] = 1;
    int p2 = 1, p3 = 1, p5 = 1;
    for (int i = 2; i <= n; i++)
    {
        int num2 = dp[p2] * 2;
        int num3 = dp[p3] * 3;
        int num5 = dp[p5] * 5;
        dp[i] = min(min(num2, num3), num5);
        if (num2 == dp[i])
        {
            p2++;
        }
        if (num3 == dp[i])
        {
            p3++;
        }
        if (num5 == dp[i])
        {
            p5++;
        }
    }
    return dp[n];
}
int main()
{
    cout << nthUglyNumber(11) << endl;
    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}