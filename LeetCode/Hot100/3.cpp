#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <unordered_map>

using namespace std;

//3. 无重复字符的最长子串
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int n = s.length();
        std::unordered_map<char, int> charMap;
        int maxLength = 0;
        int left = 0, right = 0;

        while (right < n) {
            char c = s[right];
            if (charMap.find(c) != charMap.end() && charMap[c] >= left) {
                left = charMap[c] + 1;
            }
            charMap[c] = right;
            maxLength = std::max(maxLength, right - left + 1);
            ++right;
        }

        return maxLength;
    }
};

int main()
{
    Solution sul;
    string s = "abcabcbb";
    auto res =sul.lengthOfLongestSubstring(s);
    return 0;
}