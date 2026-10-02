class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:
        arr=sorted(nums)
        count=1
        longest=1
        if not arr:
            return 0
        for i in range(len(arr)-1):
            if arr[i]+1==arr[i+1]:
                count+=1
                longest=max(longest,count)
            elif arr[i]==arr[i+1]:
                continue
            else:
                count=1

                
        return longest