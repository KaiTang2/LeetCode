#include"Question1317.h"
bool hasZero(int n)
{
    while (n > 0)
    {
        if (n % 10 == 0)
        {
            return true;
        }
        n /= 10;
    }
    return false;
}
vector<int> getNoZeroIntegers(int n) {
    for (int i = 1; i < n / 2 + 1; i++)
    {
        if (hasZero(i) || hasZero(n - i))
        {
            continue;
        }
        else
        {
            return { i,n - i };
        }
    }
    return { 0,0 };
}
vector<int> getNoZeroIntegers1(int n)
{
    int A = 0, B = 0, num = n, i = 1;
    while (num != 1 && num != 0)
    {
        int temp = 0, back = 0;
        if (num % 10 == 1 || num % 10 == 0) //尾数为1,0，有退位
        {
            back = 1;
            A += i * 9;
        }
        else
            A += i * ((num % 10) - 1);
        i *= 10;
        num /= 10;
        num -= back;
    }
    B = n - A;
    return { A, B };
}

int main()
{
    /*
    如果存在多个有效解决方案，你可以返回其中任意一个。
示例 1：
输入：n = 2
输出：[1,1]
解释：A = 1, B = 1. A + B = n 并且 A 和 B 的十进制表示形式都不包含任何 0 。
示例 2：
输入：n = 11
输出：[2,9]
示例 3：
输入：n = 10000
输出：[1,9999]
示例 4：
输入：n = 69
输出：[1,68]
示例 5：
输入：n = 1010
输出：[11,999]
提示：
2 <= n <= 10^4
    */
    vector<int>res = getNoZeroIntegers1(7);
    for (auto i : res)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}