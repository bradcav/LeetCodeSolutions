

char * longestCommonPrefix(char ** strs, int strsSize) {
    //special cases - only one item in strs
    if (strsSize == 1) {
        return strs[0];
    }
    
    bool match;
    char c;     //char to find
    
    //get the longest string first
    int longestLen = 0;
    int indexLongest = 0;
    for (int i = 0; i < strsSize; i++) {
        if (strlen(strs[i]) > longestLen) {
            longestLen = strlen(strs[i]);
            indexLongest = i;
        }
    } 

    //max len of result is len of longest, allow space for null termination    
    char *result = (char*)calloc(longestLen + 1, sizeof(char));
    
    //iterate char index up to i of longest string
    for (int i = 0; i < longestLen; i++) {
        //start each iteration assuming a match
        match = true;
        //set the char we are looking for (char i of the longest string)
        c = strs[indexLongest][i];
        //check if there is a string without this char
        for (int j = 0; j < strsSize; j++) {
            //skip string if it is our longest
            if (j == indexLongest) {
                continue;
            }
            //if a string is out of bounds, then no match
            if (i >= strlen(strs[j])) {
                match = false;
            }
            //check if all other strings match
            else if (strs[j][i] != c) {
                match = false;
            }
        }
        
        //if there was a match, add it to result and carry on, otherwise we are done
        if (match) {
            result[i] = c;
        } else {
            break;
        }
    }
    
    return result;
}