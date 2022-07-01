double divideAndConquer(double x, unsigned n) {
    double tmp;
    //base case: x is 0
    if (x == 0.0) {
        return 0.0;
    }
    
    //base case: n is 0
    if (n == 0) {
        return 1.0;
    }    
    
    tmp = divideAndConquer(x, n / 2);
    tmp *= tmp;
    
    //if n here was odd, need to multiply by x again since it was lost in the integer division
    if (n % 2 == 1) {
        return x * tmp;
    } else {
        return tmp;
    }
}


double myPow(double x, int n){
    double res = 1.0;
    unsigned nAbs;
    
    //use absolute of n to do the calculation
    //check if n is mininum int
    if (n == INT_MIN) {
        nAbs = INT_MAX + 1;
    } else {
        nAbs = abs(n);
    }   
    
    //recursive divide and conquer 
    res = divideAndConquer(x, nAbs);
    
    //was n negative?
    if (n < 0) {
        return 1 / res;
    } 
    return res;
}