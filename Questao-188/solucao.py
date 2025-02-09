class Solution(object):
    def maxProfit(self, k, prices):
        """
        :type k: int
        :type prices: List[int]
        :rtype: int
        """
        if not prices or k == 0:
            return 0
        
        tamanho = len(prices)
        if k >= tamanho // 2:
            lucro = 0
            for i in range(1, tamanho):
                if prices[i] > prices[i - 1]:
                    lucro += prices[i] - prices[i - 1]
            return lucro
        
        dp = [[0] * (tamanho) for _ in range(k + 1)]
        
        for transacao in range(1, k + 1):
            max_diferenca = -prices[0]
            for dia in range(1, tamanho):
                dp[transacao][dia] = max(dp[transacao][dia - 1], prices[dia] + max_diferenca)
                max_diferenca = max(max_diferenca, dp[transacao - 1][dia] - prices[dia])
        
        return dp[k][tamanho - 1]