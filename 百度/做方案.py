'''
小红正在做一个计划，她先写了份初版方案，但是领导不太满意，让小红改一改。
改着改着，小红就改了 16 版方案，然后领导说，还是用初版方案吧，现在小红非常的...
小红组内有 n 个人，大家合作完成了一个初版方案，初始时大家的愤怒值都是0
但是领导对方案并不满意，共需要修改m 次方案，每次修改会先让第l到第r个人的愤怒值加 1，
然后再修改方案.组内每个人都有一个愤怒闻值 a，一目第，次修改时有人愤怒值大于愤怒闻值，
他就会去找领导对线，直接将最终的方案定为第么-1方案，并且接下来方案都不需要再修改了
小红想知道，最终会使用第几版方案初版方案被认为是第 0 版方案
'''

def zuoFangan(n,m, a, lr):
    res = 0
    fenNu = [0]*n
    for i in range(m):
        for j in range(lr[i][0],lr[i][1]):
            if fenNu[j]+1==a[j]:
                res=i
                return res
    
    return m

# n, m = map(int, input().split())
# a = list(map(int, input().split()))
# lr = []
# for _ in range(m):
#     lr.append(list(map(int, input().split())))

n=2
m=3
a = [2,2]
lr=[[1,1],[1,2],[2,2]]

print(zuoFangan(n,m,a,lr))