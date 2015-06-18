#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
#include <sstream>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
using namespace std;

class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> tran;
        dfs (candidates, tran, 0, target);
        return ans;
    }

    vector<vector<int> > ans;
    void dfs(vector<int> &candidates, vector<int> &tran, int i, int target) {
        if (target == 0) {
            ans.push_back(tran);
        }
        for (int j = i; j < candidates.size() && candidates[j] <= target; j++) {
            tran.push_back(candidates[j]);
            dfs(candidates, tran, j, target-candidates[j]);
            tran.pop_back();
        }
    }
};



int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
