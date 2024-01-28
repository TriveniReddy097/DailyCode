#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int subArraySum(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int,int> map;
        map.insert({0,1});
        //using prefix sum method
        vector<int>prefix(nums.size());
        prefix[0] = nums[0];
        for(int i=1;i<nums.size();i++) {
            prefix[i] = nums[i] + prefix[i-1];
        }
        for(int i=0;i<prefix.size();i++) {
            if(map.find(prefix[i]-k) != map.end()) {
                count += map[prefix[i] - k];
            }
            map[prefix[i]]++;
        }
        return count;
        //brute forace: 
        // for(int i=0;i<nums.size();i++) {
        //     int sum = 0;
        //     if(nums[i] == k) count++;
        //     for(int j=i+1;j<nums.size();j++) {
        //         sum = sum + nums[j];
        //         if(nums[i]+sum == k) {
        //             count++;
        //         }
        //     }
        // }
        // return count;
        
    }
};

int main() {
    Solution sol;
    int n;
    int k;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        nums.push_back(x);
    }
    cout<<"enter target value: "<<endl;
    cin>>k;
    cout<<"No of sub array that sum to target: "<<sol.subArraySum(nums, k);
    return 0;
}

// Example 1:

// Input: nums = [1,1,1], k = 2
// Output: 2
// Example 2:

// Input: nums = [1,2,3], k = 3
// Output: 2