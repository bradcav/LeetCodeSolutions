bool isPalindrome(int x){
    //no negative nums are a palidrome
    if (x < 0) {
        return false;
    }
    
    //all single digits are true
    if (x < 10) {
        return true;
    }
    
    int64_t reversed = 0;
    int input = x;  //save x
    
    while (x) {
        reversed *= 10;
        reversed += x % 10;
        x /= 10;
    }
    
    if (reversed == input) {
        return true;
    } else {
        return false;
    }
}