/**
 * @brief Solution class for calculating maximum profit from stock transactions
 * 
 * This class implements an algorithm to find the maximum profit that can be achieved
 * by buying and selling stocks. The approach uses a single pass through the array
 * to track the minimum buying price and maximum possible profit.
 */
class Solution {
public:
    /**
     * @brief Calculates the maximum profit from a single stock transaction
     * 
     * The algorithm works by keeping track of the minimum price seen so far (buyprice)
     * and calculating the profit if we sell at each current price. It updates the
     * maximum profit whenever a higher profit is found.
     * 
     * @param prices Vector containing stock prices for consecutive days
     * @return int Maximum profit achievable (0 if no profit is possible)
     * 
     * Time Complexity: O(n) - Single pass through the array
     * Space Complexity: O(1) - Only using constant extra space
     * 
     * Example:
     * Input: [7,1,5,3,6,4]
     * Output: 5 (Buy at price 1, sell at price 6)
     * 
     * Input: [7,6,4,3,1]
     * Output: 0 (No profit possible)
     */
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // Initialize buyprice to the first day's price
        int buyprice = prices[0];
        // Initialize maximum profit to 0 (no transaction)
        int maxprofit = 0;
        // Iterate through all days to find optimal buy/sell points
        for(int i = 0; i < n; i++){
            // Update the minimum buying price if current price is lower
            if(buyprice > prices[i]){
                buyprice = prices[i];
            }
            // Calculate profit if we sell at current price and update maximum profit
            maxprofit = max(maxprofit, prices[i] - buyprice);
        }
        return maxprofit;
    }
};
