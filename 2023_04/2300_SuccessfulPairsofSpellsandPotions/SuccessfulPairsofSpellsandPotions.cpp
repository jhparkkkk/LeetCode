#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

class Solution {
public:
    void    displayData(vector<int> vec)
    {
        for (int i=0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << "\n";
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int> res;
        // sort potions in ascending order
        sort(potions.begin(), potions.end());
        // for each spell
        for (int i = 0; i < n; i++) {
            int left = 0;
            int right = m - 1;
            // find min value in potions 
            while (left <= right) {
                int mid = left + (right - left) / 2;
                long long product = static_cast<long long>(spells[i]) * static_cast<long long>(potions[mid]);
                if (product >= success)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            res.push_back(m - left);
        }
        return res;
    }
};


int main()
{
    {
        vector<int> spells = {5,1,3};
        vector<int> potions = {1,2,3,4,5};
        int success = 7;
        Solution test;
        test.successfulPairs(spells, potions, success);
    }

    {
        vector<int> spells = {3,1,2};
        vector<int> potions = {8,5,8};
        int success = 16;
        Solution test;
        test.successfulPairs(spells, potions, success);
    }
}