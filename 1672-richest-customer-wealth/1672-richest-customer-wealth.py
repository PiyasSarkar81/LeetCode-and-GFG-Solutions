class Solution(object):
    def maximumWealth(self, accounts):
        """
        :type accounts: List[List[int]]
        :rtype: int
        """
        maxMoney = 0
        for i in range(len(accounts)):
            moneyOfi = sum(accounts[i])
            maxMoney = max(maxMoney,moneyOfi)
        return maxMoney