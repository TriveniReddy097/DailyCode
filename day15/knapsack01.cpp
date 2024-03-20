#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int f(int index, int W, vector<int> &wt, vector<int> &val){
        //f(ind,W) --> not take then 0+f(ind-1, W); if take check wt[ind]<=W then take then val[ind]+f(ind-1, W-wt[ind])
        if(index == 0) { //base case
            if(wt[0]<=W) return val[0];
            return 0;
        }
        int notTake = f(index-1, W, wt, val);
        int take = INT_MIN;
        if(wt[index]<=W){
            take = val[index] + f(index-1, W-wt[index], wt, val);
        }
        return max(take, notTake);
    };

    int knapsack(vector<int> wt, vector<int> val, int n, int W) {
        // return f(n-1, W, wt,val); recursion method gives TLE  as T.C is O(2^n)
        vector<vector<int>> dp(n, vector<int>(W+1, 0)); //Dp method T.C is O(nxW)
        vector<int> prev(W+1, 0);

        for(int w=wt[0];w<=W;w++) {
            // dp[0][w] = val[0];
            prev[w] = val[0];
        }

        for(int ind=1;ind<n;ind++) {
            for(int w=W;w>=0;w--) {
                int notTake = prev[W];
                int take = INT_MIN;
                if(wt[ind]<=w){
                    take = val[ind]+prev[W-wt[ind]];
                }
                prev[W]=max(take, notTake);
            }
        }
        return prev[W];
        // for (int ind=1;ind<n;ind++) {
        //     for(int w = 0;w<=W;w++) {
        //         int notTake = dp[ind-1][w];
        //         int take = INT_MIN;
        //         if(wt[ind]<=w){
        //             take = val[ind]+dp[ind-1][w-wt[ind]];
        //         }
        //         dp[ind][w]=max(take, notTake);
        //     }
        // }
        // return dp[n-1][W];
    };
};

int main() {
    Solution sol;
    vector<int> wt;
    vector<int> val;
    int n;
    cout<<"enter no of items "<<endl;
    cin>>n;
    int W;
    cout<<"enter wt of knapsack "<<endl;
    cin>>W;
    cout<<"enter wts of items "<<endl;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        wt.push_back(x);
    }
    cout<<"enter vals of items "<<endl;
    for(int i=0;i<n;i++) {
        int y;
        cin>>y;
        val.push_back(y);
    }
    int res = sol.knapsack(wt, val, n, W);
    cout<<"result is "<<res;
    return 0;
}