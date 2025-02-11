# 140. Word Break II

**Difficulty:** Hard  
**Topics:** Dynamic Programming, Backtracking  

## Problem Statement

Given a string `s` and a dictionary of strings `wordDict`, add spaces in `s` to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

## Examples

### Example 1:
**Input:**  
```text
s = "catsanddog" , wordDict = ["cat","cats","and","sand","dog"]
```

**Output:**  
```text
["cats and dog","cat sand dog"]
```

### Example 2:
**Input:**  
```text
s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
```

**Output:**  
```text
["pine apple pen apple","pineapple pen apple","pine applepen apple"]
```

**Explanation:** 
```text
Note that you are allowed to reuse a dictionary word.
```

### Example 3:
**Input:**  
```text
s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
```

**Output:**  
```text
[]
```

## Constraints

- `1 <= s.length <= 20`
- `1 <= wordDict.length <= 1000`
- `1 <= wordDict[i].length <= 10`
- `s and wordDict[i] consist of only lowercase English letters.`
- `All the strings of wordDict are unique.`
- `Input is generated in a way that the length of the answer doesn't exceed 10⁵`
