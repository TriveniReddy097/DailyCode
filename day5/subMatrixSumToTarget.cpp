#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n= matrix[0].size();
        vector<vector<int>> ps(m+1, vector<int>(n+1,0));

        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++) {
                ps[i][j] = ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1] + matrix[i-1][j-1];
            }
        }
        int count = 0, currSum;
        unordered_map<int,int> h;
        for(int r1 = 1; r1<=m; r1++) {
            for(int r2=r1; r2<=m;r2++) {
                h.clear();
                h[0] = 1; //sum of empty matrix is equal to 0
                for(int c=1;c<=n;c++) {
                    currSum = ps[r2][c] - ps[r1-1][c];
                    count += h[currSum-target];
                    h[currSum] += 1;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    return 0;
}