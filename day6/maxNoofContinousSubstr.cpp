#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public: 
    int maxNoOfContigiousRepetition(string short_s, string long_s) {
        if(short_s.length() == 0 || long_s.length() == 0) {
            return 0;
        }
        int m = short_s.length();
        int n= long_s.length();
        int maxReps = 0;
        int currReps = 0;
        int i=0;
        while(i <= n-m) {
            cout<<long_s.substr(i,m)<<endl;
            if(long_s.substr(i,m) == short_s) {
                currReps++;
                maxReps = max(maxReps,currReps);
                i+=m;
            } else {
                currReps = 0;
                i++;
            }
        }
        return maxReps;
    }

};

int main() {
    Solution sol;
    string short_s;
    string long_s;
    cin>>short_s;
    cin>>long_s;
    cout<<sol.maxNoOfContigiousRepetition(short_s, long_s)<<endl;
    return 0;
}