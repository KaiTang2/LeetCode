/*


*/
#include"Question.h"
bool judgeSquareSum(int c) {
    long l = 0;
    long r = (int)sqrt(c);
    while (l <= r)
    {
        long sum = l * l + r * r;
        if (sum == c)
        {
            return true;
        }
        else if (sum > c)
        {
            --r;
        }
        else
        {
            ++l;
        }
    }
    return false;
}
int main()
{
    cout << judgeSquareSum(1) << endl;
    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}