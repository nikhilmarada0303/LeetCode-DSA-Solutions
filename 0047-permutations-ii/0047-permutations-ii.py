class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        res = set()
        visited = [0]*n
        def f(li):
            if len(li)==n:
                res.add(tuple(li))
            for i in range(n):
                if not visited[i]:
                    visited[i]=1
                    f(li + [nums[i]])
                    visited[i] = 0
        f([])
        return res
                    
                    