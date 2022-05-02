

char *multiply(char *num1, char *num2){
    //special case: if either num is 0, return 0
    if (strcmp(num1, "0") == 0 | strcmp(num2, "0") == 0) {
        return "0";
    }
    
    int len1 = strlen(num1);
    int len2 = strlen(num2);    
    int maxLen = len1 + len2;   //reuslt cant use more than this many unit places
    
    int *res = calloc(maxLen, sizeof(int));
    //build the number backwards
    int digit;
    //nested loop of nums going backwards
    for(int i = 0; i < len1; i++) {
        for(int j = 0; j < len2; j++) {
            digit = (num1[len1 - i - 1] - '0') * (num2[len2 - j - 1] - '0');
      
            //which unit does the result go in? make sure carry is handled
            res[i + j] += digit; //add the value in the right position
            res[i + j + 1] += res[i + j] / 10;    //if res[i+j] carries
            res[i + j] = res[i + j] % 10;   //carry has been handles so just lower place digit
            
        }
    }
    
    //reverse list and convert to str
    char *strRes = calloc(maxLen + 1, sizeof(char));

    //skip any leading zeros
    int start = maxLen - 1;
    while(start > 0 & res[start] == 0) {
        start--;
    }    
    
    //reverse and convert
    for (int i = 0; i <= start; i++) {
        strRes[i] = res[start - i] + '0';
    }
    
    return strRes;
}