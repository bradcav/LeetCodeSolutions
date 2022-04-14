

int strStr(char * haystack, char * needle){ 
    
    int hsLen = strlen(haystack);
    int nLen = strlen(needle);
    
    //edge case - needle is empty
    if (nLen == 0) {
        return 0;
    }
            
    for (int i = 0; i < hsLen - nLen + 1; i++) {
        for (int j = 0; j < nLen; j++) {
            if (needle[j] != haystack[i+j]) {
                break;
            }
            
            if (j == nLen - 1) {
                return i;
            }
        }
    }
    return -1;  
}