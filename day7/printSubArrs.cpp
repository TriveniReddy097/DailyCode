#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int lowLen = to_string(low).length();
        int highLen = to_string(high).length();
        int windowSize = lowLen;
        vector<int> res;
        string digits = "123456789";
        while(windowSize <= highLen) {
            for(int i=0;i<9;i++ ) {
                string str = digits.substr(i,windowSize);
                if(str.length() == windowSize && low <= stoi(str) && stoi(str) <= high) {
                    res.push_back(stoi(str));
                } 
            }
            windowSize++;
        }
        return res;
    }
};

int main() {
    Solution sol;
    int low;
    int high;
    cin>>low;
    cin>>high;
    vector<int> res = sol.sequentialDigits(low, high);
    for(auto elem: res){
        cout<<elem<<endl;
    }
    return 0;

}