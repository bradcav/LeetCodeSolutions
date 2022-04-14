

int divide(int dividend, int divisor){
    long res = 0;
    //get the sign of return value
    int sign;
    if ((dividend >= 0) == (divisor >=0)) {
        sign = 1;
    } else {
        sign = -1;
    }
    
    
    long a,b;
    
    //abs takes int, will dividend or dividor overflow (eg int_min * -1 == int_max+1)?
    if (dividend == INT_MIN) {
        a = (long)INT_MAX + 1;
    } else {
        a = abs(dividend);
    }
    if (divisor == INT_MIN) {
        b = (long)INT_MAX + 1;
    } else {
        b = abs(divisor);
    }
         
    long mul;    //keep track of number of left shifts
    
    while (a >= b) {
        mul = 0;
        while (a >= (b << 1 << mul)) {
            mul++;      //how many times can we * b by 2 and it fits in a?
        }
        a -= (b << mul);    //reduce a 
        res += ((long)1 << mul);  //b fit in to a 2^mul times so far
    }
    
    //will the result over/underflow an int?
    if (res * sign > INT_MAX) {
        return INT_MAX;
    }
    if (res * sign < INT_MIN) {
        return INT_MIN;
    }
    
    return res * sign;    
}