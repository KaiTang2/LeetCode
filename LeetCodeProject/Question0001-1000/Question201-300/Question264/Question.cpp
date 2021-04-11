﻿/*
给你一个整数 n ，请你找出并返回第 n 个 丑数 。

丑数 就是只包含质因数 2、3 和/或 5 的正整数。

示例 1：

输入：n = 10
输出：12
解释：[1, 2, 3, 4, 5, 6, 8, 9, 10, 12] 是由前 10 个丑数组成的序列。
示例 2：
输入：n = 1
输出：1
解释：1 通常被视为丑数。
 
提示：

1 <= n <= 1690
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ugly-number-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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