#include"Question88.h"
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int size = nums1.size() - 1;
    if (m + n < size) { return; }
    while (m > 0 && n > 0)
    {
        if (nums1[m - 1] > nums2[n - 1])
        {
            nums1[size] = nums1[m - 1];
            nums1[m - 1] = 0;
            m--;
        }
        else
        {
            nums1[size] = nums2[n-1];
            n--;
        }
        size--;
    }
    if (m == 0)
    {
        while (size >= 0)
        {
            nums1[size] = nums2[n-1];
            size--;
            n--;
        }
    }
    for (int i = 0, j = 5; i < 3; i++)
    {

    }
}
int main()
{
    /*
    

    */
    vector<int> num1 = { 1,2,3,0,0,0 };
    vector<int> num2 = { 2,5,6 };
    merge(num1, 3, num2, 3);
    for (auto i : num1)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}