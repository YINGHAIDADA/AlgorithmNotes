

def countGoodSubstrings(s):
    left, right = 0, 0
    count_zero, count_good = 0, 0

    while right < len(s):
        if s[right] == '0':
            count_zero += 1
        else:
            count_good += 1

        while count_good < count_zero:
            if s[left] == '0':
                count_zero -= 1
            else:
                count_good -= 1
            left += 1

        count_good += count_zero
        right += 1

    return count_good

s = input()
result = countGoodSubstrings(s)
print(result)
