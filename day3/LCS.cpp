#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length()+1, vector<int>(text2.length()+1,0));
        for(int i=1;i<=text1.length();i++) {
            for(int j=1;j<=text2.length();j++) {
                if(text1[i-1] == text2[j-1]) {
                    dp[i][j] = 1+dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[text1.length()][text2.length()];
    }

    int LCM(string text1, string text2, int i,int j) {
        if(i<0 || j<0) {
            return 0;
        }
        if(text1[i] == text2[j]) {
            return 1+LCM(text1, text2,i-1,j-1);
        } else {
            return max(LCM(text1, text2,i-1,j), LCM(text1, text2,i,j-1));
        }
    }
};

int main() {
    Solution sol;
    string s1;
    string s2;
    cin>>s1;
    cin>>s2;
    cout<<"Longest Common Subsequence is: "<<sol.longestCommonSubsequence(s1, s2)<<endl; // DP approach
    cout<<"Longest Common Subsequence is: "<<sol.LCM(s1, s2, s1.length()-1, s2.length()-1); //time limit exceeded if length of strings is more
    return 0;
}