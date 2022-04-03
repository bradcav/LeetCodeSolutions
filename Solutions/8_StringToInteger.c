

int myAtoi(char * s){
    int64_t res = 0;
    int sign = 1;
    int len = strlen(s);
    
    int i = 0;
    //ignore whitespace
    while (i < len && s[i] == ' ') {
        i++;
    }
    //get sign
    if (i < len && s[i] == '-') {
        sign = -1;
        i++;
    }
    else if (i < len && s[i] == '+') {
        i++;
    }   
    
    while (i < len) {     
        if (s[i] >= '0' && s[i] <= '9') {
            //we are in numbers                      
            res *= 10;
            res += (s[i] - '0');    //add that digit
            
            //is res an overflow for 32 bit signed?
            if (sign == -1 && res*sign < INT_MIN) {
                return INT_MIN;
            }
            if (sign == 1 && res > INT_MAX) {
                return INT_MAX;
            }
            
            i++;        
        } else {
            break;
        }    
    }
    
    //make sure the sign is correct
    res *= sign;       
    return res;
}