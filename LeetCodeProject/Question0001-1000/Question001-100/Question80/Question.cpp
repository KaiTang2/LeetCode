#include"Question.h"
int removeDuplicates(vector<int>& nums,unsigned int k) {//通用解法
    unsigned int res = 0;
    for (auto num : nums)
    {
        if (res < k || nums[res - k] != num)
        {
            nums[res] = num;
            ++res;
        }
    }
    return res;
}
int removeDuplicates(vector<int>& nums) {
    int size = nums.size();
    if (size <= 2)
    {
        return size;
    }
    unsigned int left = 2, right = 2;
    while (right < size)
    {
        if (nums[right] != nums[left - 2])
        {
            nums[left] = nums[right];
            ++left;
        }
        ++right;
    }
    return left;
}
int main()
{
    /*
    

    */

    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}