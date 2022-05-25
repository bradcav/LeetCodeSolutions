

bool isMatch(char * s, char * p){
    
    //store positions when there is a *
    char *saveS = NULL;
    char *saveP = NULL;
    
    //while there is still string to match
    while (*s) {
        //if both match, or p is ? then incr both pointers        
        if (*p == *s || *p == '?') {
            p++;
            s++;
            continue;
        }
        
        //if p is *, then save where that * is, and move p along,
        //also save the curr s
        if (*p == '*') {
            saveP = p;
            p++;
            saveS = s;
            continue;
        }
        
        //no matches, but p was '*' last, so move s along until it matches the next p
        if (saveP) {
            p = saveP + 1; //move p to the char after the *
            saveS++;
            s = saveS;  //move along s and saveS
            continue;
        }
        
        return false;   //no match so false 
    }
    
    //for case that p has trailing *
    while (*p == '*') {
        p++;
    }
    

    //if something remains in p here, not a full match, else true
    if (*p) {
        return false;
    } else {
        return true;
    }
    
}