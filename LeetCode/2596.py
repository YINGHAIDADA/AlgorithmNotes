from typing import *

class Solution:
    def checkValidGrid(self, grid: List[List[int]]) -> bool:
      res = None
      n = len(grid)
      pos = [[0] * 2 for i in range(n*n)]


      if grid[0][0] != 0:
         return False
      for i in range(n):
         for j in range(n):
            pos[grid[i][j]][0] = i
            pos[grid[i][j]][1] = j

      for i in range(1,n*n):
         if abs(pos[i][0]-pos[i-1][0]) * abs(pos[i][1]-pos[i-1][1]) !=2:
            return False
      return True



# grid = [[0,11,16,5,20],
#         [17,4,19,10,15],
#         [12,1,8,21,6],
#         [3,18,23,14,9],
#         [24,13,2,7,22]]
grid = [[0,3,6],[5,8,1],[2,7,4]]

ret = Solution().checkValidGrid(grid)
print(ret)


