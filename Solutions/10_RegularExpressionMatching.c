
bool dfs(char * s, char * p, int i, int j) {
    bool match;
    //if both i and j are out of bounds, then it's a match
    if (i >= strlen(s) && j >= strlen(p)) {
        return true;
    }
    //otherwise if just j is out of bounds but chars remain in s, return false
    if (j >= strlen(p)) {
        return false;
    }
    
    //is and still in bounds and do the current indexes match?
    match = i < strlen(s) && (s[i] == p[j] || p[j] == '.');
    
    //is there a * after the current char in p? so do we have a choice?
    if (j + 1 < strlen(p) && p[j+1] == '*') {
        //at a star there are two choices: either use char at j or dont
        return (dfs(s, p, i, j+2)                  //dont use star, move j to next char
               || (match && dfs(s, p, i+1, j)));    //use the star, only if the chars already matched
    }
    
    //there was no *, so just check for simple match
    if (match) {
        return dfs(s, p, i+1, j+1);
    }
    
    //no star and chars didnt match, then return false
    return false;
}

bool isMatch(char * s, char * p){    
    //using recursive depth first search
    return dfs(s, p, 0, 0);    
}