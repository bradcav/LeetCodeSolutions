//method using a stack
int longestValidParentheses(char * s){
    
    if (strlen(s) <= 1) {
        return 0;
    }
    
    //stack to check valid and store index of last invalid posistion
    int *stack = malloc((1 + strlen(s)) * sizeof(int));
    int sp = 0;     //stack pointer
    
    //add -1 to stack for case where longest valid starts from the start of s
    stack[sp++] = -1;
    
    int res = 0;    //max result
    
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(') {
            stack[sp++] = i;
        } else {
            sp--;
            //if sp is at 0 now, we had a close without a matching open, so invalid
            if (sp == 0) {
                stack[sp++] = i;    //store position of last invalid char
            } else {
                //otherwise i is part of a valid string, of len i - top of stack
                if (i - stack[sp - 1] > res) {
                    res = i - stack[sp - 1];
                }
            }
        }
    } 
    free(stack);
    return res;   
}


/* WORKS BUT TOO SLOW - kind of brute force
int longestValidParentheses(char * s){
    
    //special case, len of 0 or 1 cannot be valid
    if (strlen(s) <= 1) {
        return 0;
    }
    
    int res = 0;
    int nOpen;
    int nClosed;
    
    //sliding window
    int left = 0;
    int right;
    while (left < strlen(s) - 1) {
        //can't be valid if left is ")"
        if (s[left] == ')') {
            left++;
            continue;
        }
        //we got to an open bracket
        nOpen = 1;
        nClosed = 0;
        
        //start right pointer after left
        right = left + 1;
        while (right < strlen(s) && nOpen >= nClosed) {
            //count the bracket at right
            if (s[right] == '(') {
                //never valid - move right along
                nOpen++;
                right++;
                continue;
            } else if (s[right] == ')') {
                nClosed++;
                
                //is it valid?
                if (nOpen == nClosed) {
                    //update result?
                    if (right - left + 1 > res) {
                        res = right - left + 1;
                    }
                }
                
                //did nClosed go above nOpen? can skip left to one past right
                if (nClosed > nOpen) {
                    left = right;
                    break;
                }
                
                right++;
            }
            
        }
        
        //move left pointer along to start ater right
        left++;
    }
        
    return res;
}
*/