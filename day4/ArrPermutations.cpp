#include<iostream>
#include<vector>

using namespace std;

class Permutations {
public:
    void findPermutations(vector<int>& nums, vector<int>& ds,vector<vector<int>> &ans, vector<int>& freq) {
        if(ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++) {
            if(!freq[i]) {
                freq[i] = true;
                ds.push_back(nums[i]);
                findPermutations(nums, ds, ans, freq);
                ds.pop_back();
                freq[i] = 0;
            }
        }
    }
};

int main() {
    Permutations sol;
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        nums.push_back(x);
    }
    vector<int> ds;
    vector<vector<int>> ans;
    vector<int> freq(nums.size(),0);
    sol.findPermutations(nums, ds, ans, freq);
    for(auto permute: ans) {
        for(auto each:permute) {
            cout<<each;
        }
        cout<<endl;
    }
    return 0;
}
