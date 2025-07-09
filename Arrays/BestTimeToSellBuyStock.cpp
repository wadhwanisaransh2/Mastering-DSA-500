#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> bestbuy(n);
        int maxprofit = 0;
        int profit = 0;
        bestbuy[0] = INT_MAX;

        for (int i = 1; i < n; i++) {
            bestbuy[i] = min(bestbuy[i - 1], prices[i - 1]);
            profit = prices[i] - bestbuy[i];
            maxprofit = max(maxprofit, profit);
        }

        if (maxprofit < 0) return 0;
        return maxprofit;
    }
};

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution obj;
    int result = obj.maxProfit(prices);
    cout << "Maximum Profit: " << result << endl;
    return 0;
}
