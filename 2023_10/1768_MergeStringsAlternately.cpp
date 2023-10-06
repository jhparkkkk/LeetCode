#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
    
    string res;
    string::iterator it;
    word1.erase(std::remove_if(word1.begin(), word1.end(), [](unsigned char c) { return std::isspace(c); }), word1.end());
    word2.erase(std::remove_if(word2.begin(), word2.end(), [](unsigned char c) { return std::isspace(c); }), word2.end());

    int size =  word1.size() <= word2.size() ? word1.size() : word2.size();


    for (int i=0, j=0; i<size; i++){
        res.insert(j, 1, word1[i]);
        res.insert(j + 1, 1, word2[i]);
        j +=2;
    }
    string leftover = word1.size() > size ? word1.substr(size, word1.size()) : word2.substr(size, word2.size());
    res.append(leftover);

    return res;
    }
};


int main()
{

    {
        Solution test;
        string word1 = "c a t     ";
        string word2 = "d o    g";

        test.mergeAlternately(word1, word2);
    }

    {
        Solution test;
        string word1 = "c a t a";
        string word2 = "d o g g y";

        test.mergeAlternately(word1, word2);
    }
}


// Example 1:

// Input: word1 = "abc", word2 = "pqr"
// Output: "apbqcr"
// Explanation: The merged string will be merged as so:
// word1:  a   b   c
// word2:    p   q   r
// merged: a p b q c r
// Example 2:

// Input: word1 = "ab", word2 = "pqrs"
// Output: "apbqrs"
// Explanation: Notice that as word2 is longer, "rs" is appended to the end.
// word1:  a   b 
// word2:    p   q   r   s
// merged: a p b q   r   s
// Example 3:

// Input: word1 = "abcd", word2 = "pq"
// Output: "apbqcd"
// Explanation: Notice that as word1 is longer, "cd" is appended to the end.
// word1:  a   b   c   d
// word2:    p   q 
// merged: a p b q c   d
 