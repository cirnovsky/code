class Solution:
    def maxTotalValue(self, value: list[int], decay: list[int], m: int) -> int:
        MOD=10**9+7
        n = len(value)
        lo, hi = 0, max(value)
        mn=0
        def check(low):
            total=0
            for i in range(n):
                if value[i]>=low:
                    total+=(value[i]-low)//decay[i]+1
            return total
        while lo<=hi:
            mid=(lo+hi)//2
            if check(mid)>=m:
                print(mid, check(mid))
                mn=mid
                lo=mid+1
            else:
                hi=mid-1
        total=0
        res=0
        mn+=1
        for i in range(n):
            if value[i]>=mn:
                c=(value[i]-mn)//decay[i]+1
                if c+total<=m:
                    total+=c
                    # series
                    first=value[i]
                    last=value[i]-(c-1)*decay[i]
                    res+=c*(first+last)//2
                    res%=MOD
        mn-=1
        return (res+mn*(m-total))%MOD

sol=Solution
print(sol.maxTotalValue(None,[9,10,7],[1,2,8],7))
