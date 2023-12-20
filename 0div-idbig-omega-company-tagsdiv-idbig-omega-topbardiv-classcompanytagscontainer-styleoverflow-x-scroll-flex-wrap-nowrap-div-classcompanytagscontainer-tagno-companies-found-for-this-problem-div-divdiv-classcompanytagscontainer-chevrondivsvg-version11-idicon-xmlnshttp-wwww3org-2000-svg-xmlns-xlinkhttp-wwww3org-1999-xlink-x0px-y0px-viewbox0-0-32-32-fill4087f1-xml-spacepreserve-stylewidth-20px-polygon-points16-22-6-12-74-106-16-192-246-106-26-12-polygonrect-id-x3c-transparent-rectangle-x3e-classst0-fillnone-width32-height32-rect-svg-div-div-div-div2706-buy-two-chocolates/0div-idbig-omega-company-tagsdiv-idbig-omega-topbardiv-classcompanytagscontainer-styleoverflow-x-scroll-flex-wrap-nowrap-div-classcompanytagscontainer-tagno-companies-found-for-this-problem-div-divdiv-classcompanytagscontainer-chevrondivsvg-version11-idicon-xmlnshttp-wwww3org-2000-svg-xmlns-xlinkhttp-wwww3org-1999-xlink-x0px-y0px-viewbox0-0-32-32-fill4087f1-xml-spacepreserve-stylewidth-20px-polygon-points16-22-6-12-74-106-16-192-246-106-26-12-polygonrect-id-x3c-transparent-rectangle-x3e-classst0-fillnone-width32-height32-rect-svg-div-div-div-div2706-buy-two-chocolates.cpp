class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        int price = prices[0] + prices[1];
        int leftOver = money - price;
        if(leftOver < 0) return money;
        return leftOver;
    }
};
