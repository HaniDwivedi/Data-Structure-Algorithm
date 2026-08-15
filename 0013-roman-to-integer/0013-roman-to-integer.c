int romanToInt(char* s) {
    int len = strlen(s);
    int num = 0, I = 1, V = 5, X = 10, L = 50, D = 500, M = 1000, C = 100;

    for (int i = 0; i < len; i++) {
        if (s[i] == 'I' && s[i + 1] == 'V' || s[i] == 'I' && s[i + 1] == 'X' || s[i] == 'I' && s[i + 1] =='C') {
            num -= 1;
        } else if (s[i] == 'I')
            num += 1;

        if (s[i] == 'V') {
            num += 5;
        }
       if (s[i] == 'X' && s[i + 1] == 'L' ||s[i] == 'X' &&  s[i + 1] == 'C' ||s[i] == 'X' &&  s[i + 1] =='D' ||s[i] == 'X' &&  s[i + 1] =='M' ) {
            num -= 10;
        }
        else if (s[i] == 'X')
            num += 10;
        if (s[i] == 'L') {
            num += 50;
        }
        if (s[i] == 'C' && s[i + 1] == 'D' || s[i] == 'C' && s[i + 1] =='M' ) {
            num -= 100;
        }
        else if (s[i] == 'C')
            num += 100;
        if (s[i] == 'D') {
            num += 500;
        }
        if (s[i] == 'M') {
            num += 1000;
        }
           
       }   return num;
    } 