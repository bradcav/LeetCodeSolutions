# using python because this one is a big pain in C. 
# no reason to make life more difficut than it needs to be.

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        res = {}    #dict/hashmap. Map tuple of char counts to a list of anagrams.
                    #all strings with the same char counts are anagrams
            
        for s in strs:
            charCount = [0] * 26    #limited to a-z chars
            
            #count the chars
            for c in s:
                #a maps to 0, b maps to 1 etc...
                charCount[ord(c) - ord('a')] += 1
            
            #keys of dict must be a tuple, not list
            if tuple(charCount) in res:
                res[tuple(charCount)].append(s)
            else:
                res[tuple(charCount)] = [s]
                
        return res.values()
            
            
        