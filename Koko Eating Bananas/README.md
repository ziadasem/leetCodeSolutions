## 875.  Koko Eating Bananas

Medium

Koko loves to eat bananas. There are  `n`  piles of bananas, the  `ith`  pile has  `piles[i]`  bananas. The guards have gone and will come back in  `h`  hours.

Koko can decide her bananas-per-hour eating speed of  `k`. Each hour, she chooses some pile of bananas and eats  `k`  bananas from that pile. If the pile has less than  `k`  bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return  _the minimum integer_  `k`  _such that she can eat all the bananas within_  `h`  _hours_.

**Example 1:**

**Input:** piles = [3,6,7,11], h = 8
**Output:** 4

**Example 2:**

**Input:** piles = [30,11,23,4,20], h = 5
**Output:** 30

**Example 3:**

**Input:** piles = [30,11,23,4,20], h = 6
**Output:** 23

**Constraints:**

-   `1 <= piles.length <= 104`
-   `piles.length <= h <= 109`
-   `1 <= piles[i] <= 109`

Accepted 893,861 Submissions 1,835,674

## Success

[Details](https://leetcode.com/submissions/detail/1484162511/)

Runtime: **5 ms, faster than  84.64%**  of  C++  online submissions for  Koko Eating Bananas.

Memory Usage: 22.8 MB, less than  **32.91%  of  C++**  online submissions for  Koko Eating Bananas.