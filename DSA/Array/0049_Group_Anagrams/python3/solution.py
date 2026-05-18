# 0049. Group Anagrams
# Difficulty : Medium
# Tags       : array, hash-table, string, sorting
# Solved on  : 2026-05-16
# Attempt    : #1
# LeetCode   : https://leetcode.com/problems/group-anagrams/

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagram = [[0 for _ in range(27)] for _ in range(len(strs))]
        anadist = {}
        for i,x in enumerate(strs):
            for _,v in enumerate(x):
                j = int(ord(v))-int(ord('a'))
                anagram[i][j]+=1
                #print(f"x={x},v={v}")
            anadist[x] = anagram[i]
        keypair = {}
        for key,val in anadist.items():
            t = tuple(val)
            if t in keypair:
                keypair[t].append(key)
            else:
                keypair[t] = [key]

        result = []
        for key,val in keypair.items():
            result.append(val)
        for x in result:
            add = []
            for y in x:
                t = strs.count(y)
                if t > 1:
                    add.extend([y] * (t-1))
            if len(add) > 0:
                x.extend(add)
        return result
        