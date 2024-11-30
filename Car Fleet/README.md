## 853. Car Fleet

**Output:**  1

**Explanation:**

There is only one car, hence there is only one fleet.

**Example 3:**

**Input:**  target = 100, position = [0,2,4], speed = [4,2,1]

**Output:**  1

**Explanation:**

-   The cars starting at 0 (speed 4) and 2 (speed 2) become a fleet, meeting each other at 4. The car starting at 4 (speed 1) travels to 5.
-   Then, the fleet at 4 (speed 2) and the car at position 5 (speed 1) become one fleet, meeting each other at 6. The fleet moves at speed 1 until it reaches  `target`.

## Success

[Details](https://leetcode.com/submissions/detail/1466168605/)

Runtime: 23 ms, faster than  **98.23%**  of  C++  online submissions for  Car Fleet.

Memory Usage: 78.1 MB, less than  **92.47%**  of  C++  online submissions for  Car Fleet.