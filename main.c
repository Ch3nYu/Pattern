#include <stdio.h>
#include <string.h>
#include <Windows.h>

char* ReplaceAll ( char* str, const char* from, const char* to ) {
    size_t fromLen = strlen ( from );
    size_t toLen = strlen ( to );
    char* result = ( char* ) malloc ( strlen ( str ) * sizeof ( char ) );

    size_t i = 0;
    while ( *str ) {
        if ( strstr ( str, from ) == str ) {
            strcpy ( &result [ i ], to );
            i += toLen;
            str += fromLen;
        }
        else {
            result [ i++ ] = *str++;
        }
    }
    result [ i ] = '\0';
    return result;
}

int main ( ) {
    printf ( "Pattern:\n" );
    char st [ 100 ];

    scanf ( "%99[^\n]%*c", st );

    if ( !strcmp ( st, "" ) )
        main ( );

    char searchpattern [ 100 ];
    char mask [ 100 ];

    system ( "cls" );

    if ( strstr ( st, "\\x" ) ) {
        char* temp = ReplaceAll ( st, "\\x", " " );
        temp = ReplaceAll ( temp, "00", "?" );
        strcpy ( searchpattern, temp + 1 );
        printf ( "%s\n", searchpattern );
        free ( temp );
    }
    else {
        char* token;
        token = strtok ( st, " " );
        while ( token != NULL ) {
            strcat ( searchpattern, "\\x" );
            if ( strstr ( token, "?" ) ) {
                strcat ( searchpattern, "00" );
                strcat ( mask, "?" );
            }
            else {
                strcat ( searchpattern, token );
                strcat ( mask, "x" );
            }
            token = strtok ( NULL, " " );
        }
        printf ( "%s %s\n", searchpattern, mask );
    }

    main ( );
    return 0;
}