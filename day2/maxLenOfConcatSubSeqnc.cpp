#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxLength(vector<string>& arr) {
        // Brute force using for loop:
        // vector<string> res {""};
        // int maxLen = 0;
        // for(string word : arr) { //each string in array of strings
        //     int resLength = res.size(); //cal the length of result arr to iterate over it
        //     for(int i=0;i<resLength;i++) {
        //         string newRes = res[i]+word;
        //         unordered_set<char> newResSet(newRes.begin(), newRes.end());
        //         if(newRes.length() == newResSet.size()) {
        //             res.push_back(newRes);
        //             maxLen = max(maxLen, (int)newRes.length());
        //         }
        //     }
        // }
        // return maxLen;

        unordered_map<char, int> resMap;
        string uniqueChars;
        int res = backTracking(arr, 0, resMap);
        return res;
    }

private: 
    int backTracking(vector<string>& arr, int pos, unordered_map<char, int>& resMap) {
        for(auto ch: resMap) {
            if(ch.second > 1) {
                return 0;
            }
        }
        int best = resMap.size();
        for(int i=pos;i<arr.size();i++) {
            string word = arr[i];
            string currentUniqueChars;
            for(auto c: word) {
                    resMap[c]++;
                    currentUniqueChars = currentUniqueChars + c;
            }

            best = max(best, backTracking(arr, i+1, resMap));

            for(char& c:word) {
                if(resMap[c] == 1) {
                    resMap.erase(c);
                } else {
                    resMap[c]--;
                }
            }
        }
        return best;
    }
};

int main () {
    Solution sol;
    int n;
    cout<<"Enter size of array"<<endl;
    cin>>n;
    vector<string> arr;
    for(int i=0;i<n;i++) {
        string s;
        cin>>s;
        arr.push_back(s);
    }
    cout<<"max length of subsequence formed by concatenating string with unique characters: "<<sol.maxLength(arr)<<endl;
    return 0;
}