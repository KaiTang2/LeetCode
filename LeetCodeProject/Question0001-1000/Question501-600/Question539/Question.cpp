/*
给定一个 24 小时制（小时:分钟 "HH:MM"）的时间列表，找出列表中任意两个时间的最小时间差并以分钟数表示。

 

示例 1：

输入：timePoints = ["23:59","00:00"]
输出：1
示例 2：

输入：timePoints = ["00:00","23:59","00:00"]
输出：0
 

提示：

2 <= timePoints <= 2 * 104
timePoints[i] 格式为 "HH:MM"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-time-difference
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
#include"Question.h"
#include<algorithm>
int ToMin(string& s)
{
    return (s[0] - '0') * 600 + (s[1] - '0') * 60 + (s[3] - '0') * 10 + (s[4] - '0');
}
int findMinDifference(vector<string>& timePoints) {
    sort(timePoints.begin(), timePoints.end());
    int res = INT_MAX;
    for (int i = 0; i < timePoints.size() - 1; i++)
    {
        res = min(res, ToMin(timePoints[i + 1]) - ToMin(timePoints[i]));
    }
    res = min(res, 1440 - ToMin(timePoints[timePoints.size() - 1]) + ToMin(timePoints[0]));
    return res;
}
int main()
{
    vector<string> timePoints = { "00:00","23:59","00:00" };
    cout << findMinDifference(timePoints) << endl;
    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}