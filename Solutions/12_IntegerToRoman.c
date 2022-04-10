

char * intToRoman(int num){
    char *result = (char*)calloc(18, sizeof(char));    
    int i = 0;  //index for string result
    
    while (num >= 1000) {
        result[i] = 'M';
        i++;
        num -= 1000;
    }  
    while (num >= 900) {
        result[i] = 'C';
        i++;
        result[i] = 'M';
        i++;
        num -= 900;
    }
    while (num >= 500) {
        result[i] = 'D';
        i++;
        num -= 500;
    }
    while (num >= 400) {
        result[i] = 'C';
        i++;
        result[i] = 'D';
        i++;
        num -= 400;
    }
    while (num >= 100) {
        result[i] = 'C';
        i++;
        num -= 100;
    }
    while (num >= 90) {
        result[i] = 'X';
        i++;
        result[i] = 'C';
        i++;
        num -= 90;
    }
    while (num >= 50) {
        result[i] = 'L';
        i++;
        num -= 50;
    }
    while (num >= 40) {
        result[i] = 'X';
        i++;
        result[i] = 'L';
        i++;
        num -= 40;
    }
    while (num >= 10) {
        result[i] = 'X';
        i++;
        num -= 10;
    }
    while (num >= 9) {
        result[i] = 'I';
        i++;
        result[i] = 'X';
        i++;
        num -= 9;
    }
    while (num >= 5) {
        result[i] = 'V';
        i++;
        num -= 5;
    }
     while (num >= 4) {
        result[i] = 'I';
        i++;
        result[i] = 'V';
        i++;
        num -= 4;
    }
    while (num >= 1) {
        result[i] = 'I';
        i++;
        num -= 1;
    }
    
    return result;
    
}