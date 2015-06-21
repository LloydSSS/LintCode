// Lowest Common Ancestor
// http://www.lintcode.com/en/problem/lowest-common-ancestor/
// a:从根节点开始找到两个节点的路径，然后在路径中找最后一个一样的节点
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
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
public:
    /**
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        if (root == NULL || A == NULL || B == NULL) return NULL; 
        vector<TreeNode *> la, lb;
        if (!getpath(root, A, la) || !getpath(root, B, lb)) return NULL;
        TreeNode *ans = NULL;
        vector<TreeNode *>::const_iterator iter1 = la.begin();
        vector<TreeNode *>::const_iterator iter2 = lb.begin();
        while (iter1 != la.end() && iter2 != lb.end()) {
            if (*iter1 == *iter2)
                ans = *iter1;
            else
                break;
            iter1++;
            iter2++;
        }
        return ans;
    }
    
    bool getpath(TreeNode *root, TreeNode *t, vector<TreeNode *> &l) {
        l.push_back(root);
        if (root == t) return true;
        if (root->left != NULL && getpath(root->left, t, l))
            return true;
        if (root->right != NULL && getpath(root->right, t, l))
            return true;
        l.pop_back();
        return false;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}