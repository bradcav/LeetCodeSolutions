#define N 4500
char tmp[N];

void generate(char *say, int *n) {
    //break when n is 1
    if (*n == 1) {
       return;
    }
    
    //reset tmp pointer and tmp
    int tmpPtr = 0;
    memset(tmp, 0, N * sizeof(char));
    
    int len = strlen(say);
    int ch; //current char index
    int co; //count of that char
    
    ch = co = 0;
    
    //move counter along until out of bounds
    while (co < len) {
        if (say[ch] == say[co]) {    
            co++;
        } else {    
            tmp[tmpPtr++] = co - ch + '0';  //the count
            tmp[tmpPtr++] = say[ch];        //the char
            ch = co;        //move char to the next different char
        }
    }
    
    tmp[tmpPtr++] = co - ch + '0';   
    tmp[tmpPtr++] = say[ch];
    //recursive call on new string, n-1
    (*n)--;
    char *newString[N];
    strncpy(newString, tmp, N);
    generate(newString, n);   
}


char *countAndSay(int n){
    char *say = "1";
    if (n == 1) {
        return say;
    }
    generate(say, &n);  
    return tmp;
}