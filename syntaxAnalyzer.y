%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    #include "hashtbl.h"

    extern FILE *yyin;
    extern int yylex();
    extern char *yytext;

    HASHTBL * hashtbl;

    extern int lineNum;

    void yyerror(const char *message); 


    int errorCount = 0;
    int errorTypeFlag = 0; // 0: Token Error (YYTEXT) || 1: String Error (STRBUF)
    int scope = 0;
%}

%union {
    int integer;
    double real;
    char character;
    char *str;
}


%define parse.error verbose


%token T_EOF    0   "EOF"

%token <str>    T_PROGRAM    "program"
%token <str>    T_CONST      "const"
%token <str>    T_TYPE       "type"
%token <str>    T_ARRAY      "array"
%token <str>    T_LIST       "list"
%token <str>    T_SET        "set"
%token <str>    T_OF         "of"
%token <str>    T_RECORD     "record"
%token <str>    T_VAR        "var"
%token <str>    T_FUNCTION   "function"
%token <str>    T_PROCEDURE  "procedure"
%token <str>    T_INTEGER    "integer"
%token <str>    T_REAL       "real"
%token <str>    T_BOOLEAN    "boolean"
%token <str>    T_CHAR       "char"
%token <str>    T_FORWARD    "forward"
%token <str>    T_LENGTH     "length"
%token <str>    T_NEW        "new"
%token <str>    T_BEGIN      "begin"
%token <str>    T_END        "end"
%token <str>    T_IF         "if"
%token <str>    T_THEN       "then"
%token <str>    T_ELSE       "else"
%token <str>    T_WHILE      "while"
%token <str>    T_DO         "do"
%token <str>    T_CASE       "case"
%token <str>    T_OTHERWISE  "otherwise"
%token <str>    T_FOR        "for"
%token <str>    T_TO         "to"
%token <str>    T_DOWNTO     "downto"
%token <str>    T_WITH       "with"
%token <str>    T_READ       "read"
%token <str>    T_WRITE      "write"

%token T_RELOP       "> or >= or < or <= or <>"
%token T_ADDOP       "+ or -"
%token T_OROP        "||"
%token T_MULDIVANDOP "* or / or DIV or MOD or AND"
%token T_NOTOP       "NOT"
%token T_INOP        "IN"
%token T_LPAREN      "("
%token T_RPAREN      ")"
%token T_SEMI        ";"
%token T_DOT         "."
%token T_COMMA       ","
%token T_EQU         "="
%token T_COLON       ":"
%token T_LBRACK      "["
%token T_RBRACK      "]"
%token T_ASSIGN      ":="
%token T_DOTDOT      ".."

%token <str>        T_ID         "IDENTIFIER"

%token <integer>    T_ICONST     "ICONST"
%token <real>       T_RCONST     "RCONST"
%token <character>  T_BCONST     "BCONST"
%token <character>  T_CCONST     "CCONST"

%token T_LISTFUNC   "list function"

%token T_STRING     "string"


%type <str> program header declarations constdefs constant_defs expression variable expressions constant setlistexpression typedefs type_defs type_def dims limits limit sign typename standard_type fields field identifiers vardefs variable_defs subprograms subprogram sub_header formal_parameters parameter_list pass comp_statement statements statement assignment if_statement if_tail case_statement cases single_case label_list label case_tail while_statement for_statement iter_space with_statement subprogram_call io_statement read_list read_item write_list write_item


// %left       T_COMMA
// %right      T_ASSIGN
// %left       T_EQUOP
// %nonassoc   T_RELOP
// %nonassoc   T_INOP
// %left       T_OROP T_ADDOP
// %left       T_MULDIVANDOP
// %right      T_TYPE
// %left       T_DOT T_DOTDOT T_LBRACK T_RBRACK T_LPAREN T_RPAREN

// %left   T_COMMA
// %right  T_ASSIGN
// %left   T_OROP 
// %right  T_NOTOP
// %left   T_RELOP T_INOP T_EQU
// %left   T_MULDIVANDOP
// %right  T_TYPE
// %left   T_DOT T_DOTDOT T_LBRACK T_RBRACK T_LPAREN T_RPAREN


// %nonassoc LOWER_THAN_ELSE
// %nonassoc T_ELSE

%left T_OROP
%left T_ADDOP
%left T_MULDIVANDOP
%right T_NOTOP
%nonassoc T_RELOP T_EQU
%nonassoc LOWER_THAN_ELSE

%%

program: 
    header declarations subprograms comp_statement T_DOT
    ;

header:
    T_PROGRAM T_ID T_SEMI                                   { hashtbl_insert(hashtbl, $2, NULL, scope); }
    ;
declarations:
    constdefs typedefs vardefs
    ;
constdefs: 
    T_CONST constant_defs T_SEMI
    | %empty                                                { }
    ;

constant_defs:
    constant_defs T_SEMI T_ID T_EQU expression              { hashtbl_insert(hashtbl, $3, NULL, scope); }
    | T_ID T_EQU expression                                 { hashtbl_insert(hashtbl, $1, NULL, scope); }
    ;

expression:
    expression T_RELOP expression
    | expression T_EQU expression
    | expression T_INOP expression
    | expression T_OROP expression
    | expression T_ADDOP expression
    | expression T_MULDIVANDOP expression
    | expression error expression                           { yyerror("Invalid operation!"); yyerrok; }
    | T_ADDOP expression
    | T_NOTOP expression
    | variable
    | T_ID T_LPAREN expressions T_RPAREN                    { hashtbl_insert(hashtbl, $1, NULL, scope); }
    | T_LENGTH T_LPAREN expression T_RPAREN
    | T_NEW T_LPAREN expression T_RPAREN
    | constant
    | T_LPAREN expression T_RPAREN
    | setlistexpression
    ;

variable:
    T_ID                                                    { hashtbl_insert(hashtbl, $1, NULL, scope); }
    | variable T_DOT T_ID                                   { hashtbl_insert(hashtbl, $3, NULL, scope); }
    | variable T_LBRACK expressions T_RBRACK
    | T_LISTFUNC T_LPAREN expression T_RPAREN
    | T_LISTFUNC T_LPAREN expression error                  { yyerror("Missing '('!"); yyerrok; }
    ;

expressions:
    expressions T_COMMA expression
    | expression
    ;

constant:
    T_ICONST
    | T_RCONST
    | T_BCONST
    | T_CCONST
    ;

setlistexpression:
    T_LBRACK expressions T_RBRACK
    | T_LBRACK T_RBRACK
    ;

typedefs:
    T_TYPE type_defs T_SEMI
    | T_TYPE type_defs error                              { yyerror("Missing ';'!"); yyerrok; }
    | %empty                                                { }
    ;

type_defs:
    type_defs T_SEMI T_ID T_EQU type_def                    { hashtbl_insert(hashtbl, $3, NULL, scope); }
    | T_ID T_EQU type_def                                   { hashtbl_insert(hashtbl, $1, NULL, scope); }
    ;

type_def:
    T_ARRAY T_LBRACK dims T_RBRACK T_OF typename
    | T_LIST T_OF typename
    | T_SET T_OF typename
    | T_RECORD fields T_END
    | limit T_DOTDOT limit
    ;

dims:
    dims T_COMMA limits
    | limits
    ;

limits:
    limit T_DOTDOT limit
    | T_ID                                                  { hashtbl_insert(hashtbl, $1, NULL, scope); }
    ;

limit:
    sign T_ICONST
    | T_CCONST
    | T_BCONST
    | T_ADDOP T_ID                                          { hashtbl_insert(hashtbl, $2, NULL, scope); }
    | T_ID                                                  { hashtbl_insert(hashtbl, $1, NULL, scope); }
    ;  

sign:
    T_ADDOP
    | %empty                                                { }
    ;

typename:
    standard_type
    | T_ID                                                  { hashtbl_insert(hashtbl, $1, NULL, scope); }
    ;

standard_type:
    T_INTEGER
    | T_REAL
    | T_BOOLEAN
    | T_CHAR
    ;

fields: 
    fields T_SEMI field
    | field
    ;

field:
    identifiers T_COLON typename
    ;

identifiers:
    identifiers T_COMMA T_ID                                { hashtbl_insert(hashtbl, $3, NULL, scope); }
    | T_ID                                                  { hashtbl_insert(hashtbl, $1, NULL, scope); }
    ;

vardefs:
    T_VAR variable_defs T_SEMI
    | %empty                                                { }
    ;

variable_defs:
    variable_defs T_SEMI identifiers T_COLON typename
    | identifiers T_COLON typename
    ;

subprograms:
    subprograms subprogram T_SEMI
    | %empty                                                { }
    ;

subprogram:
    sub_header T_SEMI T_FORWARD
    | sub_header T_SEMI declarations subprograms comp_statement
    ;

sub_header:
    T_FUNCTION T_ID formal_parameters T_COLON standard_type { hashtbl_insert(hashtbl, $2, NULL, scope); }
    | T_FUNCTION T_ID formal_parameters T_COLON T_LIST      { hashtbl_insert(hashtbl, $2, NULL, scope); }
    | T_PROCEDURE T_ID formal_parameters                    { hashtbl_insert(hashtbl, $2, NULL, scope); }
    | T_FUNCTION T_ID                                       { hashtbl_insert(hashtbl, $2, NULL, scope); }
    ;

formal_parameters:
    T_LPAREN parameter_list T_RPAREN
    | %empty                                                { }
    ;

parameter_list:
    parameter_list T_SEMI pass identifiers T_COLON typename
    | pass identifiers T_COLON typename
    ;

pass:
    T_VAR
    | %empty                                                { }
    ;

comp_statement:
    T_BEGIN statements T_END
    ;

statements:
    statements T_SEMI statement
    | statement
    ;

statement:
    assignment
    | if_statement
    | case_statement
    | while_statement
    | for_statement
    | with_statement
    | subprogram_call
    | io_statement
    | comp_statement
    | %empty                                                { }
    ;

assignment:
    variable T_ASSIGN expression
    | variable T_ASSIGN T_STRING
    ;

if_statement:
    T_IF expression T_THEN statement if_tail
    | T_IF expression error statement if_tail                 { yyerror("Missing 'THEN' statement!"); yyerrok; }
    ;

if_tail:
    T_ELSE statement
    | %empty %prec LOWER_THAN_ELSE                          { }
    ;

case_statement:
    T_CASE expression T_OF cases case_tail T_END
    ;

cases: 
    cases T_SEMI single_case
    | single_case
    ;

single_case:
    label_list T_COLON statement
    | %empty                                                { }
    ;

label_list:
    label_list T_COMMA label
    | label
    ;

label:
    sign constant
    | sign T_ID                                             { hashtbl_insert(hashtbl, $2, NULL, scope); }
    ;

case_tail:
    T_SEMI T_OTHERWISE T_COLON statement
    | %empty                                                { }
    ;

while_statement:
    T_WHILE expression T_DO statement
    | T_WHILE expression error statement                    { yyerror("Missing 'DO' statement!"); yyerrok; }
    ;

for_statement:
    T_FOR T_ID T_ASSIGN iter_space T_DO statement           { hashtbl_insert(hashtbl, $2, NULL, scope); }
    ;

iter_space:
    expression T_TO expression
    | expression T_DOWNTO expression
    ;

with_statement:
    T_WITH variable T_DO statement
    ;

subprogram_call:
    T_ID                                                    { hashtbl_insert(hashtbl, $1, NULL, scope); }
    | T_ID T_LPAREN expressions T_RPAREN                    { hashtbl_insert(hashtbl, $1, NULL, scope); }
    ;

io_statement:
    T_READ T_LPAREN read_list T_RPAREN
    | T_WRITE T_LPAREN write_list T_RPAREN
    ;

read_list:
    read_list T_COMMA read_item
    | read_item
    ;

read_item:
    variable
    ;

write_list:
    write_list T_COMMA write_item
    | write_item
    ;

write_item:
    expression
    | T_STRING
    ;


%%

int main(int argc, char *argv[]) {
    int token;

    if(!(hashtbl = hashtbl_create(10, NULL))) {
        puts("Error, failed to initialize hashtable!");
        exit(1);
    }

    if(argc > 1) {
        yyin = fopen(argv[1], "r");
        if(yyin == NULL) {
            perror("Error opening file");
            return -1;
        }
    }

    yyparse();

    fclose(yyin);
    hashtbl_destroy(hashtbl);

    return 0;
}

// void yyerror(const char * message) {
//     errorCount++;

//     // if(errorTypeFlag == 0) {
//     printf("Error at line %d caused by %s: %s\n", lineNum, yytext, message);
//     // }

//     // errorTypeFlag = 0;

//     if(errorCount == 5) {
//         printf("Too many errors! Exitting...\n"); 
//         exit(1);
//     }
// }




void yyerror(const char *message)
{
    errorCount++;
    
    if(errorTypeFlag==0){
        printf("-> ERROR at line %d caused by %s : %s\n", lineNum, yytext, message);
    }else if(errorTypeFlag==1){
        *str_buf_ptr = '\0'; // String or Comment Error. Cleanup old chars stored in buffer.
        printf("-> ERROR at line %d near \"%s\": %s\n", lineno, str_buf, message);
    }

    errorTypeFlag = 0; // Reset errorTypeFlag to default.
    
    if(MAX_ERRORS <= 0) return;
    
    if(error_count == MAX_ERRORS){
        printf("Max errors (%d) detected. ABORTING...\n", MAX_ERRORS);
        exit(-1);
    }
}