'''

核心思想为求解排序过后数组, k能满足多少个 从小到大的元素 使得他们尽可能接近

'''

class Solution:
    def maxProduct(self, nums, k):
        MOD = 10**9 + 7
        nums.sort()
        lens = len(nums)
        result = 1
        i=lens-1

        while i>0:
            if k >= (nums[i]*(i+1)-sum(nums[:i+1])):
                shang = int((k+sum(nums[:i+1]))/(i+1))
                yu = (k+sum(nums[:i+1])) - shang*(i+1)
                if yu == 0:
                    result = result * shang**(i+1)
                else:
                    result = result * ((shang+1)**yu) * (shang**(i+1-yu))
                break
            else:
                result*=nums[i]
                i-=1
                
        return result%MOD

# 示例用法
nums = [0,3]
k = 5
result = Solution().maxProduct(nums, k)
print(result)  # 输出：60
