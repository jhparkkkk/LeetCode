#include <vector>
#include <iostream>
#include <iterator>
#include <set>
using namespace std;

class Solution {
public:
    void    displayData(set<char> a)
    {
        for (auto& str : a) {
        std::cout << str << ' ';
        }
    }
    int partitionString(string s) {
        int count = 1;
        set<char> set;
        for (int i = 0; i < s.size(); i++)
        {
            std::set<char>::iterator search = set.find(s[i]);
            if (search != set.end())
            {
                count++;
                set.clear();
                set.insert(s[i]);
            }
            else
                set.insert(s[i]);
            
        }
        return count; 
    }
};

int main()
{
    string s = "ssssss";
    Solution test;
    test.partitionString(s);
    return 0;
}