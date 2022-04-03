int reverse(int x){
    
    int new = 0; 
    
    while (x) {
        //add smallest digit of x to new
        new += x % 10;
        //right shift x
        x /= 10;    
        //make space for next digit if needed
        if (x) {
            //will new overflow?
            if (new > INT_MAX / 10 || new < INT_MIN / 10) {
               return 0; 
            }           
            new *= 10;
        }        
    } 
    return new;
}