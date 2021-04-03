#include"1610.h"
#include<map>
int maxAliveYear(vector<int>& birth, vector<int>& death) {
    int n = birth.size();
    vector<int> data(102, 0);
    for (int i = 0; i < n; i++)
    {
        data[birth[i] - 1900] += 1;
        data[death[i] - 1899] -= 1;
    }
    int max = 0, year = 0, sum = 0;
    for (int i = 0; i <= 100; i++)
    {
        sum += data[i];
        if (max < sum)
        {
            max = sum;
            year = i;
        }
    }
    return year + 1900;
}
int maxAliveYear1(vector<int>& birth, vector<int>& death) {
    int n = birth.size();
    map<int, int> data;
    for (int i = 0; i < n; i++)
    {
        data[birth[i] - 1900] += 1;
        data[death[i] - 1899] -= 1;
    }
    n = 0;
    int year = 0, sum = 0;
    for (auto i = data.begin(); i != data.end(); i++)
    {
        sum += i->second;
        if (n < sum)
        {
            n = sum;
            year = i->first;
        }
    }
    return year + 1900;
}
int main()
{
    /*
    
    [1972,1908,1915,1957,1960,1948,1912,1903,1949,1977,1900,1957,1934,1929,1913,1902,1903,1901]
[1997,1932,1963,1997,1983,2000,1926,1962,1955,1997,1998,1989,1992,1975,1940,1903,1983,1969]
    */
    vector<int> birth = { 1972,1908,1915,1957,1960,1948,1912,1903,1949,1977,1900,1957,1934,1929,1913,1902,1903,1901 };
    vector<int> death = { 1997,1932,1963,1997,1983,2000,1926,1962,1955,1997,1998,1989,1992,1975,1940,1903,1983,1969 };
    cout << maxAliveYear(birth, death) << endl;
    cout << maxAliveYear1(birth, death) << endl;
    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}