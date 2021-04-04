#include"Question801.h"
int minSwap(vector<int>& A, vector<int>& B) {
    int res = 0;
    vector<vector<int>> dp(A.size(), vector<int>(2, 0));
    dp[0][0] = 0;
    dp[0][1] = 1;
    for (int i = 1; i < A.size(); i++)
    {
        if (A[i - 1] < A[i] && B[i - 1] < B[i]) {
            if (A[i - 1] < B[i] && B[i - 1] < A[i]) {//任意交换或者不交换，取最优值
                dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);
                dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
            }
            else {
                dp[i][0] = dp[i - 1][0];//不交换，则上个位置也不能交换
                dp[i][1] = dp[i - 1][1] + 1; //交换，则上个位置也必须交换
            }
        }
        else {
            dp[i][0] = dp[i - 1][1];// 不交换，则上个位置必须交换
            dp[i][1] = dp[i - 1][0] + 1;// 交换，则上个位置不能交换
        }
    }
    return min(dp[A.size() - 1][0], dp[A.size() - 1][1]);
}

int main()
{
    /*
    

    */
    vector<int>A = {0,3,5,8,9};
    vector<int>B = {2,1,4,6,9};
    cout << minSwap(A, B)<<endl;
    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}