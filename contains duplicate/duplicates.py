class Solution(object):
    def containsDuplicate(self, nums):
        nums.sort()
        for index in range(1, len(nums)):
            if (nums[index] == nums[index - 1]):
                return True
        return False

print(Solution().containsDuplicate([9,2,3,4,5,6,10,8]))