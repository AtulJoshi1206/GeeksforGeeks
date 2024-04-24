#User function Template for python3
from bisect import bisect_right
class Solution:
    def countElements(self, a, b, n, query, q):
        # code here
        ans = []
        b.sort()  
        for s in query:
            index = bisect_right(b, a[s])  # Find the index of first element greater than a[s]
            ans.append(index)
        return ans


#{ 
 # Driver Code Starts
#Initial Template for Python 3

t = int(input())
for _ in range(0, t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    q = int(input())
    query = []
    ob = Solution()
    for i in range(q):
        query.append(int(input()))
    ans = ob.countElements(a, b, n, query, q)
    for i in range(q):
        print(ans[i])

# } Driver Code Ends