#include <vector>
#include <iostream>
#include <iterator>
#include <string>
#include <numeric>
using namespace std;

class Solution {
public:
int calculateGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

    string gcdOfStrings(string str1, string str2) {

        
    if (str1 + str2 != str2 + str1)
        return "";
    
    // Calculate the length of the largest common substring using GCD
    int gcdLength = calculateGCD(str1.length(), str2.length());
    std::cout << "gcd length is:" << gcdLength << "\n";
    // Return the largest common substring
    return str1.substr(0, gcdLength);
    
    
    }
    
};

int main()
{

    {
        Solution test;
        string str1 = "ABCABC";
        string str2 = "ABC";
        std::cout << test.gcdOfStrings(str1, str2);
    }
{
        Solution test;
        string str1 = "ABAB";
        string str2 = "ABABAB";
        std::cout << test.gcdOfStrings(str1, str2);
    }



}