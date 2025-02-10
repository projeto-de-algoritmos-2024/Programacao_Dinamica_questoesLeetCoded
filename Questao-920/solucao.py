class Solution(object):
    def numMusicPlaylists(self, n, goal, k):
        """
        :type n: int
        :type goal: int
        :type k: int
        :rtype: int
        """
        MOD = 10**9 + 7
        dp = [[0] * (goal + 1) for _ in range(n + 1)]
        dp[0][0] = 1
        
        for musicas in range(1, n + 1):
            for tamanho in range(1, goal + 1):
                dp[musicas][tamanho] = (dp[musicas - 1][tamanho - 1] * (n - (musicas - 1))) % MOD
                if musicas > k:
                    dp[musicas][tamanho] = (dp[musicas][tamanho] + dp[musicas][tamanho - 1] * (musicas - k)) % MOD
        
        return dp[n][goal]