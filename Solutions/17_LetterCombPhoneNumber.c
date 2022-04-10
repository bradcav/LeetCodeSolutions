char **map;

void backtrack(char **result, char *digits, int currIdx, char *tmp, int *numResults) {
    //break case - currIdx has gone past num of digits
    if (currIdx == strlen(digits)) {
        tmp[currIdx] = '\0';            //set null termination
        result[(*numResults)] = malloc((strlen(tmp)+1) * sizeof(char)); //make space for the tmp in result
        
        strcpy(result[(*numResults)], tmp);       //copy tmp to result
        (*numResults)++;
        return;
    }
    
    //string is not done yet, go through all possible next chars
    for (int i = 0; i < strlen(map[digits[currIdx] - '0']); i++) {
        //set the current char into temp
        tmp[currIdx] = map[digits[currIdx] - '0'][i];
        backtrack(result, digits, currIdx+1, tmp, numResults);
    }    
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** letterCombinations(char * digits, int* returnSize){
    
    char **result = NULL;
    int numResults = 0;
    
    //special case, no digits
    if (strlen(digits) == 0) {
        *returnSize = 0;
        return result;
    }
    
    //make a map of digits to the corresponding chars
    map = malloc(10 * sizeof(char*));
    map[0] = "";
    map[1] = "";
    map[2] = "abc";
    map[3] = "def";
    map[4] = "ghi";
    map[5] = "jkl";
    map[6] = "mno";
    map[7] = "pqrs";
    map[8] = "tuv";
    map[9] = "wxyz";
    
    //get size of result array
    int strLen = strlen(digits) + 1;    //each solution will have num of digits + 1 for null
    //how many solutions?
    int numSolutions = 1;
    for (int i = 0; i < strlen(digits); i++) {
        numSolutions *= strlen(map[digits[i] - '0']);
    }
    
    //allocate needed mem for result
    result = malloc(numSolutions * sizeof(char*));
    
    //create a temp string used for building the substrings
    char tmp[strLen+1];  
    
    backtrack(result, digits, 0, tmp, &numResults);
    
    *returnSize = numResults;   
    return result;   
}