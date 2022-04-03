int lengthOfLongestSubstring(char * s){
    //use an array to store which chars have been seen - 128 possible ascii chars
    int charSet[128] = {0};
    //keep track of start and finish of substring
    int left = 0;
    int right;
    int longest = 0;
    
    for (right = 0; s[right]; right++) {
        //push left pointer along until no duplicates in current substring
        while(charSet[s[right]] == 1) {
            charSet[s[left]] = 0;  //remove left char from substring
            left++;                    //incr left pointer
        }
        //update longest?
        if (right - left + 1 > longest) {
            longest = right - left + 1;
        }
        
        //add right char to set
        charSet[s[right]] = 1;
    }     
    return longest;
}