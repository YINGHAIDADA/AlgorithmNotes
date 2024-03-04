
class Solution:
    def circularGameLosers(self, n: int, k: int):
        player = [0] * n
        player[0] = 1
        flag = True
        p = 0
        off = k
        while flag:
            p+=off
            off+=k
            if player[p%n] == 1:
                flag = False
            else:
                player[p%n] = 1
        
        res = [index for index, i in enumerate(player) if i == 0]
        return res+1

ret = Solution().circularGameLosers(5,2)