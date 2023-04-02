#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

class Solution {
public:
    void     add() {
        if (_record.size() > 1)
        {
            int v1 = _record[_record.size() - 1];
            int v2 = _record[_record.size() -2];
            _record.push_back(v1 + v2);
        }
        
    }

    void     multiplyByTwo() {
        if (!_record.empty())
            _record.push_back(_record.back() * 2);
    }
    void    cancel()
    {
        if (!_record.empty())
            _record.pop_back();
    }

    int calPoints(vector<string>& operations) {
        for (int i=0; i < operations.size(); i++)
        {
            char* p;
            const char * c = operations[i].c_str();
            long converted = strtol(c, &p, 10);
            // if conversion failed check for oeprators
            if (*p) {
                if (*p == 'C')
                    cancel();
                else if (*p == 'D')
                    multiplyByTwo();
                else if (*p == '+')
                    add();
            }
            // else get operand
            else {
                _record.push_back(converted);
            }
        }

        int res = 0; 
        for (int i=0; i < _record.size(); i++)
            res += _record[i];

        std::cout << "res: " << res << '\n';
        return (res);
    }

private:
    vector<int> _record;

};



int main()
{

    {
        Solution test;
        vector<string> ops = {"5","2","C","D","+"};
        test.calPoints(ops);
    }

    {
        Solution test;
        vector<string> ops = {"5","-2","4","C","D","9","+","+"};
        test.calPoints(ops);
    }
    
    {
        Solution test;
        vector<string> ops = {"1","C"};
        test.calPoints(ops);
    }



}