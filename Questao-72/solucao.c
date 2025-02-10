#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MIN3(a, b, c) (MIN(a, MIN(b, c)))

int minDistance(char *word1, char *word2) {
    int m = strlen(word1);
    int n = strlen(word2);
    
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                dp[i][j] = j;  // Inserir todos os caracteres de word2
            } else if (j == 0) {
                dp[i][j] = i;  // Remover todos os caracteres de word1
            } else if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];  // Nenhuma operação necessária
            } else {
                dp[i][j] = 1 + MIN3(dp[i - 1][j],    // Remover
                                    dp[i][j - 1],    // Inserir
                                    dp[i - 1][j - 1] // Substituir
                                   );
            }
        }
    }

    return dp[m][n];
}