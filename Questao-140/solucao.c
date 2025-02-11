#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_LEN 20

typedef struct {
    char **sentences;
    int size;
    int capacity;
} SentenceList;

void addSentence(SentenceList *list, char *sentence) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->sentences = realloc(list->sentences, list->capacity * sizeof(char *));
    }
    list->sentences[list->size++] = strdup(sentence);
}

bool inDictionary(char *word, char **wordDict, int wordDictSize) {
    for (int i = 0; i < wordDictSize; i++) {
        if (strcmp(word, wordDict[i]) == 0) {
            return true;
        }
    }
    return false;
}

void backtrack(char *s, int start, char **wordDict, int wordDictSize, char *current, SentenceList *result) {
    if (s[start] == '\0') {
        addSentence(result, current);
        return;
    }
    
    char word[MAX_LEN + 1];
    int len = strlen(current);
    
    for (int end = start; s[end] != '\0'; end++) {
        strncpy(word, s + start, end - start + 1);
        word[end - start + 1] = '\0';
        
        if (inDictionary(word, wordDict, wordDictSize)) {
            char newCurrent[105];
            strcpy(newCurrent, current);
            if (len > 0) {
                strcat(newCurrent, " ");
            }
            strcat(newCurrent, word);
            backtrack(s, end + 1, wordDict, wordDictSize, newCurrent, result);
        }
    }
}

char** wordBreak(char* s, char** wordDict, int wordDictSize, int* returnSize) {
    SentenceList result;
    result.size = 0;
    result.capacity = 10;
    result.sentences = malloc(result.capacity * sizeof(char *));
    
    char current[105] = "";
    backtrack(s, 0, wordDict, wordDictSize, current, &result);
    
    *returnSize = result.size;
    return result.sentences;
}
