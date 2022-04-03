char * longestPalindrome(char * s){
    
    int l, r;   //left and right pointers in s
    int longest = 0;
    
    int subStart, subEnd;   //index of start and end of longest palindrome
    
    //start with each char as middle of sub string
    for (int i = 0; i < strlen(s); i++) {
        //expand from i either side while the edges are the same
        //check odd lengths substrings
        l = r = i;  //left and right start at i
        while (l >= 0 && r < strlen(s) && s[r] == s[l]) {
            //update longest?
            if (r - l + 1 > longest) {
                longest = r - l + 1;
                subStart = l;
                subEnd = r;
            }
            l--;
            r++;          
        }   
        
        //check even length substrings
        l = i;
        r = i + 1;  //left and right are now 2 different chars
        while (l >= 0 && r < strlen(s) && s[r] == s[l]) {
            if (r - l + 1 > longest) {
                longest = r - l + 1;
                subStart = l;
                subEnd = r;
            }
            l--;
            r++;    
        }
    }
    
    //use start and end to return final substring
    char result[longest+1];
    
    int j = 0;
    for (int i = subStart; i < subEnd + 1; i++) {
        result[j] = s[i];
        j++;
    }
    result[j] = '\0';
    
    char *pResult = result; 
    return pResult;    
}