%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>
    #include "syntaxAnalyzer.tab.h"
    
    FILE* fp;
    int lexicalErrors = 0;
    int lineNum = 1;
    char filename[1024];

    void errorHandler();
    void printToken(int tokenID);
    void printNumber(int tokenID);
    int str2Int(char *str);
    double convert2Double(const char *number);

    char str_buf[256];    
    char* str_buf_ptr;
%}


%x STRING
%x INLINE_COMMENTS
%x MULTILINE_COMMENTS


%option noyywrap
%option case-insensitive
%option yylineno

/* Αναγνωριστικά */

ID      [_]*[a-zA-Z][a-zA-Z0-9]*([_][a-zA-Z0-9]+)*

/* Απλές σταθερές */

LISTFUNC    [C](([A][D]*)|[D]+)[R]
ICONST      [0]|[1-9][0-9]*|0H[1-9A-F][0-9A-F]*|0B[1][0-1]*
FCONST      ([0]|[1-9][0-9]*)?"."([0]|(0*[1-9]0*)+)("E"("+"|"-")?[1-9][0-9]*)?|[1-9][0-9]*"E"("+"|"-")?[1-9][0-9]*|"0H"([1-9A-F][0-9A-F]*)?"."([0]|(0*[1-9A-F]0*)+)|"0B"([1][0-1]*)?"."([0]|(0*[1]0*)+)


/* Αναπαριστά όλους τους ASCII χαρακτήρες από 32 - 126. */
CCONST      ("'"[ -~]"'")


%%

"typedef"       { printToken(T_TYPEDEF); return T_TYPEDEF; }
"char"          { printToken(T_CHAR); return T_CHAR; }
"int"           { printToken(T_INT); return T_INT; }
"float"         { printToken(T_FLOAT); return T_FLOAT; }
"const"         { printToken(T_CONST); return T_CONST; }
"union"         { printToken(T_UNION); return T_UNION; }
"class"         { printToken(T_CLASS); return T_CLASS; }
"private"       { printToken(T_PRIVATE); return T_PRIVATE; }
"protected"     { printToken(T_PROTECTED); return T_PROTECTED; }
"public"        { printToken(T_PUBLIC); return T_PUBLIC; }
"static"        { printToken(T_STATIC); return T_STATIC; }
"void"          { printToken(T_VOID); return T_VOID; }
"list"          { printToken(T_LIST); return T_LIST; }
"continue"      { printToken(T_CONTINUE); return T_CONTINUE; }
"break"         { printToken(T_BREAK); return T_BREAK; }
"this"          { printToken(T_THIS); return T_THIS; }
"if"            { printToken(T_IF); return T_IF; }
"else"          { printToken(T_ELSE); return T_ELSE; }
"while"         { printToken(T_WHILE); return T_WHILE; }
"for"           { printToken(T_FOR); return T_FOR; }
"return"        { printToken(T_RETURN); return T_RETURN; }
"length"        { printToken(T_LENGTH); return T_LENGTH; }
"new"           { printToken(T_NEW); return T_NEW; }
"cin"           { printToken(T_CIN); return T_CIN; }
"cout"          { printToken(T_COUT); return T_COUT; }
"main"          { printToken(T_MAIN); return T_MAIN; }




\"                          { BEGIN(STRING); str_buf_ptr = str_buf;}
<STRING>\"                  { BEGIN(INITIAL); *str_buf_ptr = '\0'; yylval.str = strdup(str_buf); printf("Found string: '%s', id: %d, line: %d\n", str_buf, T_STRING, yylineno); return T_STRING; }
<STRING>\\n                 { *str_buf_ptr++ = '\n'; }
<STRING>\\f                 { *str_buf_ptr++ = '\f'; }
<STRING>\\t                 { *str_buf_ptr++ = '\t'; }
<STRING>\\r                 { *str_buf_ptr++ = '\r'; }
<STRING>\\b                 { *str_buf_ptr++ = '\b'; }
<STRING>\\v                 { *str_buf_ptr++ = '\v'; }
<STRING>\\\\                { *str_buf_ptr++ = '\\'; }
<STRING>\\\"                { *str_buf_ptr++ = '"'; }
<STRING>[^\\"\n]+           { char *yptr = yytext; while ( *yptr ) *str_buf_ptr++ = *yptr++; }
<STRING>[\n]                { lineNum++; }





"/*"                            { BEGIN(MULTILINE_COMMENTS); }
<MULTILINE_COMMENTS>"*/"        { BEGIN(INITIAL); }
<MULTILINE_COMMENTS>[^*\n]+     { ; }
<MULTILINE_COMMENTS>"*"         { ; }
<MULTILINE_COMMENTS>[\n]        { lineNum++; }

"//"                            { BEGIN(INLINE_COMMENTS); }
<INLINE_COMMENTS>[\n]           { BEGIN(INITIAL); lineNum++; } 
<INLINE_COMMENTS>[^\n]+         { ; }


"||"                { printToken(T_OROP); yylval.str = strdup(yytext); return T_OROP; }
"&&"                { printToken(T_ANDOP); yylval.str = strdup(yytext); return T_ANDOP; }
"=="|"!="           { printToken(T_EQUOP); yylval.str = strdup(yytext); return T_EQUOP; }
">"|">="|"<"|"<="   { printToken(T_RELOP); yylval.str = strdup(yytext); return T_RELOP; }
"+"|"-"             { printToken(T_ADDOP); yylval.str = strdup(yytext); return T_ADDOP; }
"*"|"/"|"%"         { printToken(T_MULOP); yylval.str = strdup(yytext); return T_MULOP; }
"!"                 { printToken(T_NOTOP); yylval.str = strdup(yytext); return T_NOTOP; }
"++"|"--"           { printToken(T_INCDEC); yylval.str = strdup(yytext); return T_INCDEC; }
"sizeof"            { printToken(T_SIZEOP); yylval.str = strdup(yytext); return T_SIZEOP; }


"("             { printToken(T_LPAREN); yylval.str = strdup(yytext); return T_LPAREN; }
")"             { printToken(T_RPAREN); yylval.str = strdup(yytext); return T_RPAREN; }
";"             { printToken(T_SEMI); yylval.str = strdup(yytext); return T_SEMI; }
"."             { printToken(T_DOT); yylval.str = strdup(yytext); return T_DOT; }
","             { printToken(T_COMMA); yylval.str = strdup(yytext); return T_COMMA; }
"="             { printToken(T_ASSIGN); yylval.str = strdup(yytext); return T_ASSIGN; }
":"             { printToken(T_COLON); yylval.str = strdup(yytext); return T_COLON; }
"["             { printToken(T_LBRACK); yylval.str = strdup(yytext); return T_LBRACK; }
"]"             { printToken(T_RBRACK); yylval.str = strdup(yytext); return T_RBRACK; }
"&"             { printToken(T_REFER); yylval.str = strdup(yytext); return T_REFER; }
"{"             { printToken(T_LBRACE); yylval.str = strdup(yytext); return T_LBRACE; }
"}"             { printToken(T_RBRACE); yylval.str = strdup(yytext); return T_RBRACE; }
"::"            { printToken(T_METH); yylval.str = strdup(yytext); return T_METH; }
">>"            { printToken(T_INP); yylval.str = strdup(yytext); return T_INP; }
"<<"            { printToken(T_OUT); yylval.str = strdup(yytext); return T_OUT; }


{LISTFUNC}      { printToken(T_LISTFUNC); yylval.str = strdup(yytext); return T_LISTFUNC; }
{ICONST}        { printNumber(T_ICONST); yylval.integer = str2Int(yytext); return T_ICONST; }
{FCONST}        { printNumber(T_FCONST); yylval.real = convert2Double(yytext); return T_FCONST; }
{CCONST}        { printToken(T_CCONST); yylval.str = strdup(yytext); return T_CCONST; }

" "             { }

[\n]            { lineNum++; }

\'\\n\'         { return T_CCONST; }

\'\\f\'         { return T_CCONST; }

\'\\t\'         { return T_CCONST; }

\'\\r\'         { return T_CCONST; }

\'\\b\'         { return T_CCONST; }

\'\\v\'         { return T_CCONST; }


{ID}            { printToken(T_ID); yylval.str = strdup(yytext); return T_ID; }

<<EOF>>         { printf("Found token: '%s', id: %d, line: %d\n", "EOF", T_EOF, yylineno); return T_EOF; }


.               { lexicalErrors++; }

%%


void printToken(int tokenID) {
    printf("Found token: '%s', id: %d, line: %d\n", yytext, tokenID, yylineno);
}


void printNumber(int tokenID) {
    int number, base;

    base = 10;
    if(strncmp(yytext, "0H", 2) == 0) {
        base = 16;
        number = (int) strtol(&yytext[2], NULL, base); // Μετατροπή δεκαεξαδικού αριθμού σε δεκαδικό ακέραιο.
    } else if(strncmp(yytext, "0B", 2) == 0) {
        base = 2;
        number = (int) strtol(&yytext[2], NULL, base); // Μετατροπή δυαδικού αριθμού σε δεκαδικό ακέραιο.
    } 
    else number = (int) strtol(yytext, NULL, base);

    printf("Found number: '%d', from base: %d, id: %d, line: %d\n", number, base, tokenID, yylineno);
}


// Μετατροπή αριθμών σε ακέραιους δεκαδικούς.
int str2Int(char *str) {
    // Μετατροπή δεκαεξαδικού αριθμού σε δεκαδικό ακέραιο.
    if(strncmp(str, "0H", 2) == 0) {
        return (int) strtol(&str[2], NULL, 16);
    }

    // Μετατροπή δυαδικού αριθμού σε δεκαδικό ακέραιο.
    if(strncmp(str, "0B", 2) == 0) {
        return (int) strtol(&str[2], NULL, 2);
    }

    return (int) strtol(str, NULL, 10);
}

double convertFractionalPart(const char *fraction, int base) {
    double result = 0.0;
    int len = strlen(fraction);

    // Μετατρέπουμε κάθε ψηφίο, ανάλογα με τη βάση του, σε δεκαδικό και επιστρέφουμε το αποτέλεσμα.
    for (int i = 0; i < len; i++) {
        if (fraction[i] >= '0' && fraction[i] <= '9') {
            result += (fraction[i] - '0') / pow(base, i + 1);
        } else if (fraction[i] >= 'A' && fraction[i] <= 'F') {
            result += (10 + fraction[i] - 'A') / pow(base, i + 1);
        } else if (fraction[i] >= 'a' && fraction[i] <= 'f') {
            result += (10 + fraction[i] - 'a') / pow(base, i + 1);
        }
    }
    
    return result;
}

double convertExponentialPart(const char *str) {
    return strtod(str, NULL); // Μετατρέπουμε τον εκθετικό αριθμό σε double.
}

double convert2Double(const char *number) {
    char *endPtr;
    double result = 0.0;

    // Ελέγχουμε τον τύπο του αριθμού και το μετατρέπουμε σε double.
    if (strncmp(number, "0H", 2) == 0) {
        // Δεκαεξαδικός.
        result = strtod(number + 2, &endPtr);
    } else if (strncmp(number, "0B", 2) == 0) {
        // Δυαδικός.
        result = strtoul(number + 2, &endPtr, 2);
    } else {
        // Δεκαδικός.
        result = strtod(number, &endPtr);
    }

    // Διαχειριζόμαστε το κλασματικό μέρος.
    if (*endPtr == '.') {
        result += convertFractionalPart(endPtr + 1, (*number == '0' && *(number + 1) == 'X') ? 16 : 10); // Μετατρέπουμε το κλασματικό μέρος, ανάλογα με τη βάση του, σε δεκαδικό.
        endPtr = strchr(endPtr + 1, 'E'); // Παίρνουμε το κλασματικό μέρος, μέχρι να βρούμε το εκθετικό.
    }

    // Μετατρέπουμε τον εκθετικό σε double και το προσαρμόζουμε στο αποτέλεσμα που έχουμε.
    if (endPtr && *endPtr == 'E') {
        result *= pow(10, convertExponentialPart(endPtr + 1));
    }

    return result;
}
