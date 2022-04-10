int getValue(char c) {
    switch (c) {
        case 'M': {
            return 1000;
        }
        case 'D': {
            return 500;
        }
        case 'C': {
            return 100;
        }
        case 'L': {
            return 50;
        }
        case 'X': {
            return 10;
        }
        case 'V': {
            return 5;
        }
        case 'I': {
            return 1;
        }
        default:
            return 0;
    }
}

int romanToInt(char * s){
    int result = 0;
    
    for (int i = 0; i < strlen(s); i++) {
        //is the current char smaller than the next? then it is negative
        if (i + 1 < strlen(s) && getValue(s[i]) < getValue(s[i+1])) {
            result -= getValue(s[i]);
        } else {
            result += getValue(s[i]);
        }
    }
    return result;   
}






