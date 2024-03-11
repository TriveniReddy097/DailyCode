
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        // unordered_map<int, int> mp;
        // for (int num : nums1) {
        //     mp[num]++;
        // }
        // for (int num : nums2) {
        //     if (mp[num] > 0) {
        //         return num;
        //     }
        // }
        int i = 0;
        int j = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();
        while(i<n1 && j<n2) {
            if(nums1[i] == nums2[j]){
                return nums1[i];
            } else if(nums1[i]<nums2[j]){
                i++;
            } else {
                j++;
            }
        }
        return -1;
    }
};

int main() {
    int n1;
    cin>>n1;
    int n2;
    cin>>n2;
    vector<int> nums1;
    vector<int> nums2;
    for(int i=0;i<n1;i++){
        int x;
        cin>>x;
        nums1.push_back(x);
    }
    for(int i=0;i<n2;i++){
        int x;
        cin>>x;
        nums2.push_back(x);
    }
    Solution sol;
    cout<<"Minimum common value of 2 arrays is: "<<endl;
    cout<<sol.getCommon(nums1, nums2);
    return 0;
}