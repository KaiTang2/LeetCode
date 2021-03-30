#include"Question74.h"
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int left = 0, right = m * n - 1;
    while (left <= right)
    {
        int middle = (left + right) / 2;
        int x = matrix[middle / n][middle % n];
        if (x < target)
        {
            left = middle + 1;
        }
        else if (x > target)
        {
            right = middle - 1;
        }
        else
        {
            return true;
        }
    }
    return false;
}
int main()
{
    /*
    编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。
输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
输出：true
输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
输出：false
m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104

    */
    vector<vector<int>> vec = { {1,3,5,7} ,{10,11,16,20},{23,30,34,60} };
    cout << searchMatrix(vec, 3) << endl;
    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}