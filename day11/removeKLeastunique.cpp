#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(auto n:arr){
            mp[n]++;
        }
        vector<int> freq;
        for(auto it : mp){
            freq.push_back(it.second);
        }
        sort(freq.begin(), freq.end());
        int count = 0;
        int ans = 0;
        for(int i=0;i<freq.size();i++){
           count += freq[i];
           if(count > k){
                ans = freq.size() - i;
                break;

           }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int n;
    cin>>n;
    vector<int> arr;
    cout<<"enter array values"<<endl;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int k;
    cout<<"enter K value: "<<endl;
    cin>>k;
    cout<<"no of remaining unique elements: "<<sol.findLeastNumOfUniqueInts(arr, k);
    return 0;
}