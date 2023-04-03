#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    void    displayData(vector<int> vec)
    {
        for (int i=0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << "\n";
    }

    int numRescueBoats(vector<int>& people, int limit)
    {
        // sort in ascending order
        sort(people.begin(), people.end());
        // find first occurence of limit 
        auto it = find(people.begin(), people.end(), limit);
        // get distance 
        int count = distance(it, people.end());
        int i = 0;
        int j = people.size() - count - 1;
        while (i <= j)
        {

            if (people[i] + people[j] <= limit)
            {
                count++;
                i++;
            }
            else
                count++;
            j--;
        }
        cout << count << "\n";
        return count;
    }
};

int main()
{
    {
        vector<int> people = {1, 2};
        int limit = 3;
        Solution test;
        assert(test.numRescueBoats(people, limit) == 1);
    }

    {
        vector<int> people = {3,2,2,1};
        int limit = 3;
        Solution test;
        assert(test.numRescueBoats(people, limit) == 3);

    }
    {
        vector<int> people = {3,5,3,4};
        int limit = 5;
        Solution test;
        assert(test.numRescueBoats(people, limit) == 4);
    }

    {
        vector<int> people = {2, 4};
        int limit = 5;
        Solution test;
        assert(test.numRescueBoats(people, limit) == 2);
    }

    {
        vector<int> people = {5,1,4,2};
        int limit = 6;
        Solution test;
        assert(test.numRescueBoats(people, limit) == 2);
    }
    return 0;
}