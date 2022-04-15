
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findSubstring(char * s, char ** words, int wordsSize, int* returnSize){
      
    int wordLen = strlen(words[0]);
    
    int *result = malloc(strlen(s) * sizeof(int));
    *returnSize = 0;
    
    //case: wordLen * wordsSize < s.len; no possible solutions
    int subStrLen = wordLen * wordsSize;
    if (subStrLen > strlen(s)) {
        *returnSize = 0;
        return result;
    }
    
    int used[wordsSize];
    
    int i, j, k;
    
    //iterate each char in s
    for (i = 0; i < strlen(s) - subStrLen + 1; i++) {
        //clear used array
        memset(used, 0, wordsSize * sizeof(int));
        
        //slide window over s, of size and step wordLen
        int sPointer = i;
        for (j = 0; j < wordsSize; j++) {
            //is current subString of s in words?
            for (k = 0; k < wordsSize; k++) {                 
                //words match
                if (used[k] == 0 & strncmp(words[k], &s[sPointer], wordLen) == 0) {  
                    used[k] = 1;
                    break;     
                }          
            }
            //if k reached the end then there was no match
            if (k == wordsSize) {
                break;
            }
            sPointer += wordLen;        
        }
        
        //if j reaches wordsSize then the loop wasnt left early, there is a match
        if (j == wordsSize) {
            result[(*returnSize)++] = i;                   
        }     
    }     
    return result;  
}