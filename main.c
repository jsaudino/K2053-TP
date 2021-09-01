#include "scanner.h"
#include <stdio.h>

int main() {

    char lexema[20];
    int token;

    do {
        token = get_token(lexema);

        switch (token)
        {
            case FDT:
                printf( "Fin De Texto\n" );
                break;
            case SEP:
                printf( "Separador: %s\n", lexema);
                break;
            case CAD:
                printf( "Cadena: %s\n", lexema);
                break;
            default:
                break;
        }
    } while ( token!= FDT );

    return 0;
}