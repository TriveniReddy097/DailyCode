#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

bool sortBySecondValue(const pair<char,int>& a, const pair<char, int>& b){
    return a.second > b.second; 
};

class Solution {
public:
    // bool sortBySecondValue(const pair<char,int>& a, const pair<char, int>& b){
    //     return a.second > b.second; 
    // }; //defining here will throw error : non static function used
    string characterFreqSort(string s){
        unordered_map<char,int> mp;
        for(auto c:s){
            mp[c]++;
        }
        vector<pair<char, int>> vec(mp.begin(), mp.end());
        sort(vec.begin(), vec.end(), sortBySecondValue);
        string res;
        for(auto c: vec){
            while(c.second>0){
                res+=c.first;
                c.second--;
            }
        }
        // auto comp = [&] (char a, char b) { //[&] is indicating that it takes reference of values
        //     if(mp[a] == mp[b]){
        //         return a>b;
        //     }
        //     return mp[a]>mp[b];
        // };
        // sort(s.begin(),s.end(),comp);
        return res;
    }
};

int main() {
    Solution sol;
    string s;
    cout<<"enter your string: "<<endl;
    cin>>s;
    cout<<"input string: "<<s<<endl;
    cout<<"output string: "<<sol.characterFreqSort(s);
    return 0;
}