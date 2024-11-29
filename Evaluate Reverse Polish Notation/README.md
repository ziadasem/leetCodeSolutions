## 150.  Evaluate Reverse Polish Notation

Medium

You are given an array of strings  `tokens`  that represents an arithmetic expression in a  [Reverse Polish Notation](http://en.wikipedia.org/wiki/Reverse_Polish_notation).

Evaluate the expression. Return  _an integer that represents the value of the expression_.

**Note**  that:

-   The valid operators are  `'+'`,  `'-'`,  `'*'`, and  `'/'`.
-   Each operand may be an integer or another expression.
-   The division between two integers always  **truncates toward zero**.
-   There will not be any division by zero.
-   The input represents a valid arithmetic expression in a reverse polish notation.
-   The answer and all the intermediate calculations can be represented in a  **32-bit**  integer.

**Example 1:**

**Input:** tokens = ["2","1","+","3","*"]
**Output:** 9
**Explanation:** ((2 + 1) * 3) = 9

**Example 2:**

**Input:** tokens = ["4","13","5","/","+"]
**Output:** 6
**Explanation:** (4 + (13 / 5)) = 6

**Example 3:**

**Input:** tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
**Output:** 22
**Explanation:** ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22

**Constraints:**

-   `1 <= tokens.length <= 104`
-   `tokens[i]`  is either an operator:  `"+"`,  `"-"`,  `"*"`, or  `"/"`, or an integer in the range  `[-200, 200]`.

Accepted 1,222,664 Submissions 2,295,541

## Success

[Details](https://leetcode.com/submissions/detail/1466127258/)

Runtime: **0 ms**, faster than  **100.00%  of  C++**  online submissions for  Evaluate Reverse Polish Notation.

Memory Usage: **17 MB,** less than  **14.68%  of  C++**  online submissions for  Evaluate Reverse Polish Notation.
