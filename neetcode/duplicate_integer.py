
from typing import List

class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        seen = set()
        for num in nums:
            if num in seen:
                return True
            seen.add(num)
        return False

li: List[int] = [1, 2, 3, 3, 4]
obj = Solution()
print(obj.hasDuplicate(li))
