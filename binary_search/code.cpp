#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include <unordered_map>

int peakIndexElement(vector<int> &nums)
{
    int n = nums.size();

    int st = 0;
    int end = n - 1;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (nums[mid - 1] <= nums[mid] && nums[mid] >= nums[mid + 1])
        {
            return nums[mid];
        }
        else if (nums[mid] > nums[mid + 1])
        {
            end = mid - 1;
        }
        else if (nums[mid] > nums[mid - 1])
        {
            st = mid + 1;
        }
    }

    return -1;
}

int main()
{

    vector<int> nums = {2, 6, 9, 10, 3, 1, 1, 2, 3, 9, 10};
    // cout << peakIndexElement(nums) << endl;

    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }

    for (auto &it : mp)
    {
        cout << it.first << " : " << it.second << endl;
    }

    return 0;
}