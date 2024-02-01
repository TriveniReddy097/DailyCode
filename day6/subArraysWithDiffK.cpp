#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        if(nums.size() < 3 || nums.size()%3 != 0) {
            return {};
        }
        vector<vector<int>> ans(nums.size()/3,vector<int>(3));
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i=i+3){
            if(nums[i+2]-nums[i] > k){
                return {};
            }
            ans[i/3] =  {nums[i], nums[i+1],nums[i+2]};
        }
        cout<<"result array: ";
        for(auto each: ans){
            for(auto elm:each) {
                cout<<elm<<" ";
            }
            cout<<endl;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int n;
    cout<<"enter size of array: ";
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int k;
    cout<<"enter value of K: ";
    cin>>k;
    sol.divideArray(arr, k);
    return 0;

}