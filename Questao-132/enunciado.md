# 132. Palindrome Partitioning II

**Solved**  
**Difficulty:** Hard  

## Description  

Given a string `s`, partition `s` such that every **substring** of the partition is a **palindrome**.

Return the minimum cuts needed for a palindrome partitioning of `s`.

## Example 1  

**Input:**  
```text
s = "aab"
```
**Output:**  
```text
1
```
**Explanation:**  
```text
The palindrome partitioning ["aa","b"] could be produced using 1 cut.
```

## Example 2  

**Input:**  
```text
s = "a"
```
**Output:**  
```text
0
```

## Example 3  

**Input:**  
```text
s = "ab"
```
**Output:**  
```text
1
```

## Constraints  

- `1 <= s.length <= 2000`  
- `s` consists of lowercase English letters only.
