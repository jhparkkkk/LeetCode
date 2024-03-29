#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) {
            return true;
        }
        for (int i = 0; i < flowerbed.size(); i++) {
            if(flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)){
                flowerbed[i] =1;
                n--;
            }
            if (n == 0)
                return true;
        }
        return false;
    }
};

int main()
{

    {
        Solution test;
        vector<int> flowerbed = {1,0,0,0,0,1};
        int n = 2;
        cout << test.canPlaceFlowers(flowerbed, n);
    }

}
