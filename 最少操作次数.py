'''
游游拿到了一个数组，她每次操作可以使得一个元素加1，另一个元素减1。游游希望最终数组的每个元素大小都在[l,r]范围内，她想知道自己最少多少次操作可以达成目标?
输入描述：第一行输入一个正整数t，代表用例的组数。
对于每组用例:
第一行输入三个正整数n,l,r。
第二行输入n个正整数a_i，代表游游拿到的数组。
1<t< 1000
2<n < 200000
1<l<r<10^9
1< a_i < 10^9
保证所有的n的总和不超过200000
'''
def min_operations_to_range(arr, l, r):
    n = len(arr)
    sum_arr = sum(arr)
    min_val = min(arr)
    max_val = max(arr)
    
    if min_val >= l and max_val <= r:
        return 0
    
    if sum_arr< n*l or sum_arr > n*r:
        return -1
    operations = 0
    
    while min_val < l or max_val > r:
        if min_val < l:
            x = arr.index(min_val)
            y = arr.index(max_val)
            arr[x] += 1
            arr[y] -= 1
            min_val += 1
            max_val -= 1
            operations += 1
        elif max_val > r:
            x = arr.index(min_val)
            y = arr.index(max_val)
            arr[x] += 1
            arr[y] -= 1
            min_val += 1
            max_val -= 1
            operations += 1
    
    return operations

t = int(input())
for _ in range(t):
    n, l, r = map(int, input().split())
    arr = list(map(int, input().split()))
    result = min_operations_to_range(arr, l, r)
    if result == -1:
        print(-1)
    else:
        print(result)

