
class Solution:
    def findReplaceString(self, s: str, indexes, sources, targets) -> str:
        flag = False
        off = 0
        for i in range(len(indexes)):
            if flag:
                flag = False
                continue
            if i+1 ==len(indexes):
                if s[indexes[i]+off:].index(sources[i]) == 0:
                    s = s.replace(sources[i],targets[i],1)
                    off+=(len(targets[i])-len(sources[i]))
            else:
                if indexes[i+1]< indexes[i]+len(sources[i]):
                    flag = True
                    continue
                else:
                    if s[indexes[i]+off:].index(sources[i]) == 0:
                        s = s.replace(sources[i],targets[i],1)
                        off+=(len(targets[i])-len(sources[i]))

ret = Solution().findReplaceString("vmokgggqzp",[3,5,1],["kg","ggq","mo"], ["s","so","bfr"])