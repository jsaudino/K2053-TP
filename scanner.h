#ifndef SCANNER_H_ 
#define SCANNER_H_

enum tokens {
    FDT,
    SEP,
    CAD
};

int get_token(char lexema[]);

#endif