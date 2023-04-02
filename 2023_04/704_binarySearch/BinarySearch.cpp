#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

class Solution {
public:

    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() -1;
        while (low <= high)
        {
            int mid = low + (high -low) * 0.5 ;
            if (target == nums[mid])
                return mid;
            else if (target > nums[mid])
                low = mid + 1;
            else
                high = mid -1;
        }
        return -1;  
    }
};

int main ()
{
    vector<int> nums = {2};
    Solution test;
    std::cout << test.search(nums, 2);
}