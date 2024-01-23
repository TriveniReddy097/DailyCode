#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int> mp;
        int repeatingNum = -1;
        for(int i=0;i<nums.size();i++) {
            if(mp.find(nums[i]) == mp.end()) {
                mp[nums[i]] = i+1;
            } else {
                repeatingNum = nums[i];
            }
        }
        int missingNumber = -1;
        for (int i = 1; i <= nums.size(); i++) {
            if (mp.find(i) == mp.end()) {
                missingNumber = i;
                break;
            }
        }
        return {repeatingNum,missingNumber};
    }
};

int main () {
    Solution sol;
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        nums.push_back(x);
    }
    vector<int> res;
    res = sol.findErrorNums(nums);
    for(auto const x:res){
        cout<<x<<" ";
    }
}