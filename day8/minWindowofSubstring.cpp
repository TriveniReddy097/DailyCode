#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t){
        if(s == "" || t == "") return "";
        if(s.length() < t.length()) return "";
        int minLength = INT_MAX;
        int minLeft = 0;
        int left = 0;
        int right;
        int count = 0;
        unordered_map<char,int> mps;
        unordered_map<char,int> mpt;

        for(auto e : t){
            mpt[e]++;
        }

        for(right = 0;right<s.length();right++){
            if(mpt[s[right]] == 0) continue; //if character is not present in t
            mps[s[right]]++;
            if(mps[s[right]]<=mpt[s[right]]) count++;
            if(count == t.length()){
                while(mps[s[left]] == 0 || mps[s[left]]>mpt[s[left]]) {
                    if(mps[s[left]] != 0) mps[s[left]]--;
                    left++;
                }

                if(right-left+1 < minLength){
                    minLength = right - left +1;
                    minLeft = left;
                }
            }
        }
        if(minLength == INT_MAX) return ""; //all characters of t are not present in s
        return s.substr(minLeft, minLength);
    }
};

int main() {
    Solution sol;
    string s;
    string t;
    cout<<"Enter string s: ";
    cin>>s;
    cout<<"Enter string t: ";
    cin>>t;
    cout<<sol.minWindow(s,t);
    return 0;
}