#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

// Função para verificar se uma substring é um palíndromo
bool isPalindrome(char *s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

// Função para calcular o número mínimo de cortes
int minCut(char *s) {
    int n = strlen(s);
    int dp[n];
    bool palindrome[n][n];
    
    // Inicializa a matriz palindrome
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            palindrome[i][j] = false;
        }
    }
    
    // Preenche a matriz palindrome
    for (int end = 0; end < n; end++) {
        for (int start = 0; start <= end; start++) {
            if (s[start] == s[end] && (end - start <= 2 || palindrome[start + 1][end - 1])) {
                palindrome[start][end] = true;
            }
        }
    }
    
    // Calcula o número mínimo de cortes usando DP
    for (int i = 0; i < n; i++) {
        if (palindrome[0][i]) {
            dp[i] = 0;
        } else {
            dp[i] = INT_MAX;
            for (int j = 0; j < i; j++) {
                if (palindrome[j + 1][i] && dp[j] + 1 < dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
    }
    
    return dp[n - 1];
}
