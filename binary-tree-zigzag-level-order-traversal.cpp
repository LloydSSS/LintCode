#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <sstream>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
using namespace std;


// Definition of TreeNode:
class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: A list of lists of integer include 
     *          the zigzag level order traversal of its nodes' values 
     */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > retv;
        if (root == NULL) return retv;
        
        queue<pair<TreeNode *, int> > qu;
        qu.push(make_pair(root, 0));
        while (!qu.empty()) {
            pair<TreeNode *, int> pr = qu.front();
            qu.pop();
            TreeNode *p = pr.first;
            int d = pr.second;
            if (d == retv.size())
                retv.push_back(vector<int>());
            retv[d].push_back(p->val);
            if (p->left)
                qu.push(make_pair(p->left, d+1));
            if (p->right)
                qu.push(make_pair(p->right, d+1));
        }
        for (int i = 1; i < retv.size(); i+=2) {
            reverse(retv[i].begin(), retv[i].end());
        }
        return retv;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
