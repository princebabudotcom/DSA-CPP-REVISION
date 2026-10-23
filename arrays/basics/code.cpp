#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
 * Reverse Arrray
 * Maximum subarray
 * majority element -> Hash Map
 * Compute X^n
 * stock buy and sell stock
 * container with most water
 */

void printArray(vector<int> &nums)
{
    for (int n : nums)
    {
        cout << n << " ";
    }
    cout << endl;
}

void reverseArray(vector<int> &nums)
{
    int st = 0, end = nums.size() - 1;

    while (st < end)
    {
        swap(nums[st], nums[end]);
        st++;
        end--;
    }
}

int maxSubArray(vector<int> &nums)
{
    int n = nums.size() - 1;
    int maxSum = INT8_MIN;
    int sum = 0;

    // using brute force
    // for(int i = 0 ; i <= n ; i++){
    //     int sum = 0;
    //     for(int j = i ; j <= n ; j++){
    //         sum += nums[j];
    //         maxSum = max(maxSum , sum);
    //     }
    // }

    // optimal solution

    for (int i = 0; i <= n; i++)
    {

        sum += nums[i];
        maxSum = max(sum, maxSum);
        if (sum < 0)
        {
            maxSum = 0;
        }
    }
    return maxSum;
}

int majorityElement(vector<int> &nums)
{
    int n = nums.size();
    // unordered_map<int, int> mp;

    // for (int n : nums)
    // {
    //     mp[n]++;
    // }

    // for (auto &it : mp)
    // {
    //     if (it.second > n / 2)
    //     {
    //         return it.first;
    //     }
    // }

    // optimal solution
    sort(nums.begin(), nums.end());
    int freq = 0;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] == nums[i - 1])
        {
            freq++;
        }

        if (freq > n / 2)
        {
            return nums[i];
        }
    }

    return -1;
}

double xPn(double x, int n)
{
    long long binNum = n;
    double ans = 1.0;

    if (binNum < 0)
    {
        x = 1.0 / x;
        binNum = -binNum;
    }

    while (binNum > 0)
    {

        if (binNum % 2 == 1)
        {
            ans = ans * x;
        }

        binNum /= 2;
        x *= x;
    }

    return ans;
}

int main()
{

    vector<int> revArray = {1, 2, 3, 4, 5};
    reverseArray(revArray);
    printArray(revArray);

    // 1. max subArray sum
    vector<int> maxArray = {5, 4, -1, 7, 8};
    cout << "Max SubArrays : " << maxSubArray(maxArray) << endl;

    // 2. majority element
    vector<int> majoArray = {2, 2, 1, 1, 1};
    cout << majorityElement(majoArray) << endl;

    // 3. compute X^n
    cout << xPn(5.0, -2) << endl;

    return 0;
}