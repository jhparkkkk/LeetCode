#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        // get max value in candies[]
        int maxCandies = *max_element(candies.begin(), candies.end());
        // init bool array to false
        vector<bool> res(candies.size(), false); 
        for (int i=0; i < candies.size(); i++){
            // set to true if candies with extra candies is
            // larger or equal the max value
            if (candies[i] + extraCandies >= maxCandies)
                res[i] = true;
        }

        return res;
    }
};

int main()
{
    {
        Solution test;
        vector<int> candies = {2, 3, 5, 1, 3};
        int extraCandies = 3;
        test.kidsWithCandies(candies, extraCandies);
    }
}