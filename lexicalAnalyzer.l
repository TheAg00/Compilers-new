%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>
    #include "syntaxAnalyzer.tab.h"
    // #include "tokens.h"

    #define FLEX_DEBUG 0

    FILE* fp;
    int errorCounter = 0;
    int lineNum = 1;
    char filename[1024];

    void errorHandler();
    void printToken(int tokenID);
    int str2Int(char *str);
    double convert2Double(const char *number);
    char * TwoCharactersChar(char *str);
    void printNumber(int tokenID);
    
%}

%x COMMENTS
%x STRING

%option noyywrap
%option case-insensitive
%option yylineno
              
/* Αναγνωριστικά */

IDENTIFIER  [_]?[a-zA-Z]([_]*[a-zA-Z0-9]+)*

/* Απλές σταθερές */

ICONST      [0]|[1-9][0-9]*|0X[1-9A-F][0-9A-F]*|0B[1][0-1]*
RCONST      ([0]|[1-9][0-9]*)?"."([0]|(0*[1-9]0*)+)("E"("+"|"-")?[1-9][0-9]*)?|[1-9][0-9]*"E"("+"|"-")?[1-9][0-9]*|"0X"([1-9A-F][0-9A-F]*)?"."([0]|(0*[1-9A-F]0*)+)|"0B"([1][0-1]*)?"."([0]|(0*[1]0*)+)
BCONST      "true"|"false"
CCONST      ("'"[ -~]"'")
LISTFUNC    [C]([A][D]*|[D]+)[R]


%%

"program"       { printToken(T_PROGRAM); return T_PROGRAM; }
"const"         { printToken(T_CONST); return T_CONST; }
"type"          { printToken(T_TYPE); return T_TYPE; }
"array"         { printToken(T_ARRAY); return T_ARRAY; }
"list"          { printToken(T_LIST); return T_LIST; }
"set"           { printToken(T_SET); return T_SET; }
"of"            { printToken(T_OF); return T_OF; }
"record"        { printToken(T_RECORD); return T_RECORD; }
"var"           { printToken(T_VAR); return T_VAR; }
"function"      { printToken(T_FUNCTION); return T_FUNCTION; }
"procedure"     { printToken(T_PROCEDURE); return T_PROCEDURE; }
"integer"       { printToken(T_INTEGER); return T_INTEGER; }
"real"          { printToken(T_REAL); return T_REAL; }
"boolean"       { printToken(T_BOOLEAN); return T_BOOLEAN; }
"char"          { printToken(T_CHAR); return T_CHAR; }
"forward"       { printToken(T_FORWARD); return T_FORWARD; }
"length"        { printToken(T_LENGTH); return T_LENGTH; }
"new"           { printToken(T_NEW); return T_NEW; }
"begin"         { printToken(T_BEGIN); return T_BEGIN; }
"end"           { printToken(T_END); return T_END; }
"if"            { printToken(T_IF); return T_IF; }
"then"          { printToken(T_THEN); return T_THEN; }
"else"          { printToken(T_ELSE); return T_ELSE; }
"while"         { printToken(T_WHILE); return T_WHILE; }
"do"            { printToken(T_DO); return T_DO; }
"case"          { printToken(T_CASE); return T_CASE; }
"otherwise"     { printToken(T_OTHERWISE); return T_OTHERWISE; }
"for"           { printToken(T_FOR); return T_FOR; }
"to"            { printToken(T_TO); return T_TO; }
"downto"        { printToken(T_DOWNTO); return T_DOWNTO; }
"with"          { printToken(T_WITH); return T_WITH; }
"read"          { printToken(T_READ); return T_READ; }
"write"         { printToken(T_WRITE); return T_WRITE; }


\"                  { BEGIN(STRING); memset(yylval.str, 0, 4096); }
<STRING>\\\n        { lineNum++; }
<STRING>\\\\        { yylval.str = strdup(yytext); }
<STRING>\n          { lineNum++; }
<STRING>[^\\"\n]+   { yylval.str = strdup(yytext);  } // Κάνουμε append ένα γράμμα τη φορά, για να πάρουμε ολόκληρο το string.
<STRING>\"          { BEGIN(INITIAL); printf("Found string: %s\n", yylval.str); return T_STRING; }


"{"                 { BEGIN(COMMENTS); }
<COMMENTS>"}"       { BEGIN(INITIAL); }
<COMMENTS>\n        { lineNum++; }
<COMMENTS>[^\n]+    { ; }



">"|">="|"<"|"<="|"<>"      { printToken(T_RELOP); yylval.str = strdup(yytext); return T_RELOP; }
"+"|"-"                     { printToken(T_ADDOP); yylval.str = strdup(yytext); return T_ADDOP; }
"OR"                        { printToken(T_OROP); yylval.str = strdup(yytext); return T_OROP; }
"*"|"/"|"DIV"|"MOD"|"AND"   { printToken(T_MULDIVANDOP); yylval.str = strdup(yytext); return T_MULDIVANDOP; }
"NOT"                       { printToken(T_NOTOP); yylval.str = strdup(yytext); return T_NOTOP; }
"IN"                        { printToken(T_INOP); yylval.str = strdup(yytext); return T_INOP;}


"("             { printToken(T_LPAREN); yylval.str = strdup(yytext); return T_LPAREN; }
")"             { printToken(T_RPAREN); yylval.str = strdup(yytext); return T_RPAREN; }
";"             { printToken(T_SEMI); yylval.str = strdup(yytext); return T_SEMI; }
"."             { printToken(T_DOT); yylval.str = strdup(yytext); return T_DOT;}
","             { printToken(T_COMMA); yylval.str = strdup(yytext); return T_COMMA;}
"="             { printToken(T_EQU); yylval.str = strdup(yytext); return T_EQU;}
":"             { printToken(T_COLON); yylval.str = strdup(yytext); return T_COLON;}
"["             { printToken(T_LBRACK); yylval.str = strdup(yytext); return T_LBRACK;}
"]"             { printToken(T_RBRACK); yylval.str = strdup(yytext); return T_RBRACK;}
":="            { printToken(T_ASSIGN); yylval.str = strdup(yytext); return T_ASSIGN;}
".."            { printToken(T_DOTDOT); yylval.str = strdup(yytext); return T_DOTDOT;}


{IDENTIFIER}    { printToken(T_ID); yylval.str = strdup(yytext); return T_ID; }
{ICONST}        { printNumber(T_ICONST); yylval.integer = str2Int(yytext); return T_ICONST; }
{RCONST}        { printNumber(T_RCONST); yylval.real = convert2Double(yytext); return T_RCONST; }
{BCONST}        { printToken(T_BCONST); yylval.str = TwoCharactersChar(yytext); return T_BCONST;}
{CCONST}        { printToken(T_CCONST); yylval.str = strdup(yytext); return T_CCONST; }
{LISTFUNC}      { printToken(T_LISTFUNC); yylval.str = TwoCharactersChar(yytext); return T_LISTFUNC; }


" "             { }


[\f\t\r\b\v]
[\n]            { lineNum++; }


<<EOF>> { printToken(T_EOF); return T_EOF; }


.       { errorCounter++; errorHandler(); }

%%



void errorHandler() {
    printf("Error #%d found at line %d.\n", errorCounter, lineNum);  

    // Ανοίγω το αρχείο κώδικα
    FILE *fp1 = fopen(filename, "r");

    int i = 1;
    char lineText[4096];

    // Διαβάζω lineNum γραμμές ώστε να υπάρχει στο lineText η γραμμή στην οποία έγινε το σφάλμα.
    while (i <= lineNum)
    {
        memset(lineText, 0, 4096);     // Διαγράφει ό,τι χαρακτήρες είχε lineText.
        fgets(lineText,  4096, fp1);   // Διαβάζει την επομένη γραμμή από το αρχείο και την αποθηκεύει στο lineText.
        i++;
    }

    // Το lineText περιέχει τη γραμμή στην οποία έχει γίνει λεκτικό σφάλμα.
    printf("Error in line: %s\n", lineText);
    fclose(fp1);

    // Αν έχουμε δύο λεκτικά σφάλματα, τερματίζουμε το πρόγραμμα.
    if (errorCounter == 2) {
        printf("Too many errors! Exitting...\n"); 
        exit(1);
    }

    yyless(1);
}

void printToken(int tokenID) {
    printf("Found token: '%s', id: %d, line: %d\n", yytext, tokenID, yylineno);
}

void printNumber(int tokenID) {
    int number;

    if(strncmp(yytext, "0X", 2) == 0) number = (int) strtol(&yytext[2], NULL, 16); // Μετατροπή δεκαεξαδικού αριθμού σε δεκαδικό ακέραιο.
    else if(strncmp(yytext, "0B", 2) == 0) number = (int) strtol(&yytext[2], NULL, 2); // Μετατροπή δυαδικού αριθμού σε δεκαδικό ακέραιο.
    else number = (int) strtol(yytext, NULL, 10);

    printf("Found number: '%d', id: %d, line: %d\n", number, tokenID, yylineno);
}

// Μετατροπή αριθμών σε ακέραιους δεκαδικούς.
int str2Int(char *str) {
    // Μετατροπή δεκαεξαδικού αριθμού σε δεκαδικό ακέραιο.
    if(strncmp(str, "0X", 2) == 0) {
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
    if (strncmp(number, "0X", 2) == 0) {
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


char * TwoCharactersChar(char *str) {
    // Αν ο χρήστης έδωσε ένα χαρακτήρα, τότε απλά τον επιστρέφουμε.
    if(strlen(str) != 2) return strdup(str);

    // Αν έχουμε ειδικό χαρακτήρα που παριστάνονται με το '\', τον επιστρέφουμε στην κατάλληλη μορφή.
    if (strcmp(str, "\\n") == 0) return strdup("\n");
    if (strcmp(str, "\\t") == 0) return strdup("\t");
    if (strcmp(str, "\\r") == 0) return strdup("\r");
    if (strcmp(str, "\\f") == 0) return strdup("\f");
    if (strcmp(str, "\\b") == 0) return strdup("\b");
    if (strcmp(str, "\\v") == 0) return strdup("\v");


    // Αν έχουμε '\', χωρίς να είναι ειδικός χαρακτήρας, τότε αφαιρούμε το '\'.
    char *result = (char *)malloc(2);

    // Επιστρέφουμε NULL, αν υπήρξε πρόβλημα κατά τη δέσμευση μνήμης.
    if (!result) return NULL;

    result[0] = str[1];
    result[1] = '\0';

    return result;
}