

bool isValid(char * s){
    
    //use an array as a stack, if bracket is opening bracket then psuh to stack, if closing and matches top of stack,
    //then pop stack, else add bracket to stack.
    //at the end, stack should be empty is string is valid
    
    char *stack = (char*)malloc(strlen(s) * sizeof(char));
    int sp = 0;     //stack pointer
    char c;
    
    for (int i = 0; i < strlen(s); i++) {
        c = s[i];
        //if stack is empty, add the char and go to next char
        if (sp == 0) {
            stack[sp] = c;
            sp++;
            continue;
        }
        switch (c) 
        {
            case '(':
            case '[':
            case '{':
            {
                stack[sp] = c;
                sp++;
                break;
            }  
                
            case ')':
            {
                if (stack[sp-1] == '(') {
                    sp--;
                } else {
                    stack[sp] = c;
                    sp++;
                }
                break;
            }
                
            case ']':
            {
                if (stack[sp-1] == '[') {
                    sp--;
                } else {
                    stack[sp] = c;
                    sp++;
                }
                break;
            }
                
            case '}':
            {
                if (stack[sp-1] == '{') {
                    sp--;
                } else {
                    stack[sp] = c;
                    sp++;
                }
                break;
            }        
        }
    }   
    if (sp == 0) {
        return true;
    } else {
        return false;
    }    
}