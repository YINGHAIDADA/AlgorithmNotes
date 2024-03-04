import numpy as np
class Solution:
    def createTu(self, edges, n):
        tu = np.zeros((n+1,n+1),dtype=int)
        for edge in edges:
            tu[min(edge)][max(edge)] = 1
        return tu

    def findMinroad(self, tu, points):
        return
    def minEasyroad(self, tu, points):
        res = None

        return res


n = 4
q = 2
edges = [[1,2],[1,3],[1,4]]
points = [
    [1,2,3],
    [2,3,4]
]

tu = Solution().createTu(edges,n)
ret = 0
print(ret)

