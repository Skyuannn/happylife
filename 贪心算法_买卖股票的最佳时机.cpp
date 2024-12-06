#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int ans = 0;
        int lowprice = prices[0];
        for (int i = 0; i < prices.size(); i++) {
            ans = max(ans, prices[i] - lowprice);
            lowprice = min(lowprice, prices[i]);
        }
        return ans;
    }
};

int main() {
    vector<int> prices{7, 6, 4, 3, 1};
    Solution S;
    int result = S.maxProfit(prices);
    cout << "result:" << result << endl;
    return 0;
}