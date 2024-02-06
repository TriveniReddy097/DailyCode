#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> strs) {
        unordered_map<string, vector<string>> anagramGrps;
        for(auto s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            if(anagramGrps.find(key) == anagramGrps.end()) {
                anagramGrps[key] = {s};
            } else {
                anagramGrps[key].push_back(s);
            }
        }
        vector<vector<string>> result;
        for(auto group:anagramGrps){
            result.push_back(group.second);
        }
        return result;
    };
};

int main() {
    Solution sol;
    int n;
    cin>>n;
    vector<string> str;
    for(int i=0;i<n;i++)
    {   
        string s;
        cin>>s;
        str.push_back(s);
    }
    vector<vector<string>> res;
    res = sol.groupAnagrams(str);
    cout<<"===================="<<"output: "<<endl;
    for(auto each : res) {
        for(auto e : each) {
            cout<<e<<" ";
        }
        cout<<endl;
    }
    return 0;
}