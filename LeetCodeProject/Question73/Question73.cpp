#include "Question73.h"

void setZeroes(vector<vector<int>>& matrix) {
    bool flag = false;
    int m = matrix.size();
    int n = matrix[0].size();
    for (auto  i = 0; i < m; i++)
    {
        if(matrix[i][0] == 0)
        {
            flag = true;
        }
        for (auto j = 1; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }

        }
    }
    for (int i = m-1; i >= 0; i--)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }

        }
        if (flag)
        {
            matrix[i][0] = 0;
        }

    }
}

int main()
{
    /*
    给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。

进阶：

一个直观的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
你能想出一个仅使用常量空间的解决方案吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/set-matrix-zeroes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
    输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
输出：[[1,0,1],[0,0,0],[1,0,1]]

输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]]

    */
    vector<vector<int>> matrix = { {1, 1, 1},{1, 0, 1},{1, 1, 1} };

    for each (auto var1 in matrix)
    {
        for each (auto var2 in var1)
        {
            cout << var2 << ' ';
        }
        cout << endl;
    }
    cout << "-----------------------------" << endl;
    setZeroes(matrix);
    cout << endl;
    for each (auto var1 in matrix)
    {
        for each (auto var2 in var1)
        {
            cout << var2 << ' ';
        }
        cout << endl;
    }

	int pass = getchar();
	return 0;
}