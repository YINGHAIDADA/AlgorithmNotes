'''
讨厌鬼有n个帖子。第i个帖了的点赞数为ai点踩数为b;。你可以选择任意个帖了组合起来
组合帖子的点赞数和点踩数为所有被组合帖子点赞数和点踩数之和。已知一个帖子的点赞数为X，点踩数为y，则该帖子的吸引度为 |x-y|
讨厌鬼需要选择若千个帖了组合起来，便得这个组合帖子的吸引度尽可能大。
请你告诉他这个吸引度最大是多少?
'''

def xiYindu(n, good, bad):
    
    xiyin = [good[i]-bad[i] for i in range(n)]

    zheng = sum([xiyin[i] for i in range(n) if xiyin[i]>=0])
    fu = sum([xiyin[i] for i in range(n) if xiyin[i]<0])
    return max(zheng,-fu)

# n = int(input())
# good = list(map(int, input().split()))
# bad = list(map(int, input().split()))

n = 4
good = [8,2,1,9]
bad = [2,1,3,4]

print(xiYindu(n,good,bad))