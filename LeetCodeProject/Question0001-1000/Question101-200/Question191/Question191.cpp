#include"Question191.h"
int hammingWeight(uint32_t n) {
    int ret = 0;
    while (n != 0)
    {
        n = n & (n - 1);
        ret++;
    }
    return ret;
}
int main()
{
    /*
    编写一个函数，输入是一个无符号整数（以二进制串的形式），返回其二进制表达式中数字位数为 '1' 的个数（也被称为汉明重量）。
    */
    uint32_t k = 6;
    cout << hammingWeight(k) << endl;
    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}