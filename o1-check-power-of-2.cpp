// http://www.lintcode.com/en/problem/o1-check-power-of-2/
// 注意非正数的处理

#include "lintcode.h"

class Solution {
public:
    /*
     * @param n: An integer
     * @return: True or false
     */
    bool checkPowerOf2(int n) {
        if (n <= 0) return false;
        cout << (n&(n-1)) << endl;
        return (n&(n-1)) == 0;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	cout << sol.checkPowerOf2(4) << endl;
	return 0;
}
