#include "scanner.h"
#include <stdio.h>
#include <ctype.h>

int get_token(char lexema[]) {
    char current_char=' ';
    int token_index = 0;
    int token_type = -1;


    // si el token index avanzó, significa que se guardaron caracteres
    // esto sucede sólo en el caso de coma o cadena (se setea el token type como CAD)
    while( token_type < 0 ) {
        current_char = getchar();

        //si es un espacio
        if ( isspace(current_char) ) {
            if (token_index == 0) {
                continue;
            } else {
                token_type = CAD;
            } 
        }

        // si es EOF
        else if (current_char < 0) {
            if (token_index == 0) {
                token_type = FDT;
            } else {
                ungetc(current_char, stdin); 
                token_type = CAD;
            } 
        }

        // si es una coma
        else if (current_char == ',') {
            if (token_index == 0) {
                token_type = SEP;
                lexema[token_index]=current_char;
                token_index++;
            } else {
                ungetc(current_char, stdin); 
                token_type = CAD;
            }

        // si es un caracter
        } else {
            lexema[token_index]=current_char;
            token_index++;
        }
    }

    lexema[token_index]='\0';

    return token_type;
}