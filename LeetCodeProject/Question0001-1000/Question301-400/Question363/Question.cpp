/*
给你一个 m x n 的矩阵 matrix 和一个整数 k ，找出并返回矩阵内部矩形区域的不超过 k 的最大数值和。

题目数据保证总会存在一个数值和不超过 k 的矩形区域。

 

示例 1：


输入：matrix = [[1,0,1],[0,-2,3]], k = 2
输出：2
解释：蓝色边框圈出来的矩形区域 [[0, 1], [-2, 3]] 的数值和是 2，且 2 是不超过 k 的最大数字（k = 2）。
示例 2：

输入：matrix = [[2,2,-1]], k = 3
输出：3
 

提示：

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-100 <= matrix[i][j] <= 100
-105 <= k <= 105
 


*/
#include"Question.h"
int sum[110][110];
int maxSumSubmatrix(vector<vector<int>>& mat, int k) {
    int m = mat.size(), n = mat[0].size();
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + mat[i - 1][j - 1];
        }
    }
    int ans = INT_MIN;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            for (int l = i; l <= m; l++) {
                for (int r = j; r <= n; r++) {
                    int cur = sum[l][r] - sum[i - 1][r] - sum[l][j - 1] + sum[i - 1][j - 1];
                    if (cur <= k) {
                        ans = max(ans, cur);
                    }
                }
            }
        }
    }
    return ans;
}
int main()
{
    vector < vector<int>> nums = { {2,2,-1} };
    cout << maxSumSubmatrix(nums, 0) << endl;
    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}