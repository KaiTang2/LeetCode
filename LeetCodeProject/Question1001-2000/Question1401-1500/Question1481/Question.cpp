/*


*/
#include"Question.h"
#include<unordered_map>
#include<algorithm>

int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
    unordered_map<int, int> mp;
    for (auto i : arr)
    {
        ++mp[i];
    }
    vector<pair<int, int>> p(mp.begin(),mp.end());
    sort(p.begin(), p.end(), [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; });
    int res = p.size();
    for (auto i : p)
    {
        if (k <= 0)
        {
            break;
        }
        if (i.second > k)
        {
            ++res;
        }
        --res;
        k -= i.second;
    }
    return res;

}
int main()
{
    /*vector<int> nums = { 4,3,1,1,3,3,2 };
    cout << findLeastNumOfUniqueInts(nums, 3) << endl;*/
    vector<int> nums = { 5,5,4 };
    cout << findLeastNumOfUniqueInts(nums, 1) << endl;
    int pass = getchar();
    return 0;
}