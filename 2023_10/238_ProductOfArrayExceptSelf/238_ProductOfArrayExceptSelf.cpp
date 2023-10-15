#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

class Solution {
public:
   vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size());
        prefix[0] = nums[0];
        for (int i=1; i<nums.size();i++){
            prefix[i] = prefix[i - 1] * nums[i];
        }

        cout << "prefix: ";
        for (int i=0; i< prefix.size(); i++)
            cout << prefix[i] << ' '; 
        cout << "\n";

        vector<int> suffix(nums.size());
        suffix[suffix.size() - 1] = nums[nums.size() - 1];
        for (int i = suffix.size() -2; i>=0; i--){
            suffix[i] = suffix[i+1] * nums[i];
        }

        cout << "suffix: ";
        for (int i=0; i< suffix.size(); i++)
            cout << suffix[i] << ' '; 
        cout << "\n";

        vector<int> res(nums.size());

        for(int i=0; i<res.size(); i++){
            int pref = i == 0 ? 1 : prefix[i - 1];
            int suf = i == res.size() - 1? 1 : suffix[i + 1];
            res[i] = pref * suf;
        }


        return res;
    }

};

int main()
{

    {
        Solution test;
        vector<int> nums = {1,2,3,4};
        vector<int> res = test.productExceptSelf(nums);
        cout << "result: ";
        for (int i=0; i< res.size(); i++)
            cout << res[i] << ' ';
    }

}