#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

//49. 字母异位词分组

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        vector<vector<string>> res;

        for(const auto& str : strs)
        {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            hash[tmp].push_back(str);
        }
        for(const auto& it : hash)
            res.push_back(it.second);
        return res;
    }
};

int main()
{
    Solution sul;
    vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
    auto res = sul.groupAnagrams(strs);
    return 0;
}