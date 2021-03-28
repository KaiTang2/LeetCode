#include"Question59.h"
vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>> result(n,vector<int>(n));
	int current = 1;
	int max = n * n;
	int left = 0, right = n - 1, top = 0, bottom = n - 1;
	while (left <= right && top <= bottom)
	{
		for (int i = left; i <= right; i++)
		{
			result[top][i] = current;
			++current;
		}
		for (int i = top+1; i <= bottom; i++)
		{
			result[i][right] = current;
			++current;
		}
		if (left < right && top < bottom)
		{
			for (int i = right-1; i > left; i--)
			{
				result[bottom][i] = current;
				++current;
			}
			for (int i = bottom; i >top; i--)
			{
				result[i][left] = current;
				++current;
			}
		}
		left++;
		right--;
		top++;
		bottom--;
	}
	return result;
}
vector<vector<int>> generateMatrix2(int n) {
	vector<vector<int>> result(n, vector<int>(n));
	int current = 1;
	int max = n * n;
	int left = 0, right = n - 1, top = 0, bottom = n - 1;
	while (current <= max)
	{
		for (int i = left; i <= right; i++)
		{
			result[top][i] = current++;
		}
		top++;
		for (int i = top; i <= bottom; i++)
		{
			result[i][right] = current++;
		}
		right--;
		for (int i = right; i >= left; i--)
		{
			result[bottom][i] = current++;
		}
		bottom--;
		for (int i = bottom; i >= top; i--)
		{
			result[i][left] = current++;
		}
		left++;

	}
	return result;
}
int main()
{
	/*
	给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
	输入：n = 3
	输出：[[1,2,3],[8,9,4],[7,6,5]]
	*/
	int num = 6;
	vector<vector<int>> res = generateMatrix2(num);
	cout.setf(ios::left);
	int spaceSize = ((num / 10) + 1) * 2;
	for each (auto var in res)
	{
		for each (auto va in var)
		{
			cout.width(spaceSize);
			cout << va << " ";
		}
		cout << endl;
	}
	cout << "Press any key to exit" << endl;
	int pass = getchar();
	return 0;
}