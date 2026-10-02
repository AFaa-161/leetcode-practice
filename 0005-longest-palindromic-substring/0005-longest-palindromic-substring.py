class Solution:
    def longestPalindrome(self, s: str) -> str:
        ans=""
        def expand(left,right):
            nonlocal ans
            while left>=0 and right<len(s) and s[left]==s[right]:
                left-=1
                right+=1
            
            pal=s[left+1:right]
            if len(pal)>len(ans):
                ans=pal
        for i in range(len(s)):
            expand(i,i)
            expand(i,i+1)
        return ans