// Find the Town Judge
// In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

// If the town judge exists, then:

// The town judge trusts nobody.
// Everybody (except for the town judge) trusts the town judge.
// There is exactly one person that satisfies properties 1 and 2.
// You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi. If a trust relationship does not exist in trust array, then such a trust relationship does not exist.

// Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size() < n-1){ //no of edges less than n-1
            return -1;
        }
        vector<int> count(n + 1, 0);
        for (auto& t : trust)
            count[t[0]]--, count[t[1]]++;
        for (int i = 1; i <= n; ++i) {
            if (count[i] == n - 1) return i;
        }
        return -1;
        // vector<int> outDegree(n+1);
        // vector<int> inDegree(n+1);
        // for(auto relation : trust) {
        //     outDegree[relation[0]]++;
        //     inDegree[relation[1]]++;
        // }
        // for(int i=1;i<=n;i++){
        //     if(inDegree[i] == n-1 && outDegree[i] == 0){
        //         return i;
        //     }
        // }
        // return -1;
    }
};

int main() {
    Solution sol;
    
}
