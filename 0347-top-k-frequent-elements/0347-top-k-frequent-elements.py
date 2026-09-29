class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        groups={}
        for num in nums:
            
            if num not in groups:
                groups[num]=0
            groups[num]+=1
        sorted_nums=sorted(groups,key=groups.get,reverse=True)
        return sorted_nums[:k]

