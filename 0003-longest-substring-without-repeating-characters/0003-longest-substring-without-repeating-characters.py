class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ans=""
        max_len=0
        for char in s:
            if char in ans:
                ans=ans[ans.index(char)+1:]

            ans+=char
                
            if max_len<len(ans):
                max_len=len(ans)
        return max_len