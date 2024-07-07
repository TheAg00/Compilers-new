%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    #include "hashtbl.h"

    extern int lineno;

    extern FILE *yyin;
    extern int yylex();
    extern char *yytext;

    extern void yyterminate();

    HASHTBL * hashtbl;

    extern int lineNum;

    void yyerror(const char *message);

    int syntaxErrors = 0;
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


%token  T_EOF   0           "EOF"

%token <str>    T_TYPEDEF   "typedef"
%token <str>    T_CHAR      "char"
%token <str>    T_INT       "int"
%token <str>    T_FLOAT     "float"
%token <str>    T_CONST     "const"
%token <str>    T_UNION     "union"
%token <str>    T_CLASS     "class"
%token <str>    T_PRIVATE   "private"
%token <str>    T_PROTECTED "protected"
%token <str>    T_PUBLIC    "public"
%token <str>    T_STATIC    "static"
%token <str>    T_VOID      "void"
%token <str>    T_LIST      "list"
%token <str>    T_CONTINUE  "continue"
%token <str>    T_BREAK     "break"
%token <str>    T_THIS      "this"
%token <str>    T_IF        "if"
%token <str>    T_ELSE      "else"
%token <str>    T_WHILE     "while"
%token <str>    T_FOR       "for"
%token <str>    T_RETURN    "return"
%token <str>    T_LENGTH    "length"
%token <str>    T_NEW       "new"
%token <str>    T_CIN       "cin"
%token <str>    T_COUT      "cout"
%token <str>    T_MAIN      "main"

%token <str>    T_OROP      "||"
%token <str>    T_ANDOP     "&&"
%token <str>    T_EQUOP     "== or !="
%token <str>    T_RELOP     "> or >= or < or <="
%token <str>    T_ADDOP     "+ or -"
%token <str>    T_MULOP     "* or / or %"
%token <str>    T_NOTOP     "!"
%token <str>    T_INCDEC    "++ or --"
%token <str>    T_SIZEOP    "sizeof"
%token <str>    T_LPAREN    "("
%token <str>    T_RPAREN    ")"
%token <str>    T_SEMI      ";"
%token <str>    T_DOT       "."
%token <str>    T_COMMA     ","
%token <str>    T_ASSIGN    "="
%token <str>    T_COLON     ":"
%token <str>    T_LBRACK    "["
%token <str>    T_RBRACK    "]"
%token <str>    T_REFER     "&"
%token <str>    T_LBRACE    "{"
%token <str>    T_RBRACE    "}"
%token <str>    T_METH      "::"
%token <str>    T_INP       ">>"
%token <str>    T_OUT       "<<"

%token <str>    T_ID        "IDENTIFIER"

%token <str>    T_ICONST     "ICONST"
%token <str>    T_FCONST     "FCONST"
%token <str>    T_CCONST     "CCONST"

%token <str>    T_LISTFUNC  "list function"

%token <str>    T_STRING    "string"

%type <str> program global_declarations global_declaration typedef_declaration typename standard_type listspec dims dim const_declaration constdefs constdef init_value expression variable
%type <str> general_expression assignment expression_list constant listexpression init_values class_declaration class_body parent members_methods access member_or_method member
%type <str> var_declaration variabledefs variabledef anonymous_union union_body fields field method short_func_declaration short_par_func_header func_header_start parameter_types
%type <str> pass_list_dims nopar_func_header union_declaration global_var_declaration init_variabledefs init_variabledef initializer func_declaration full_func_declaration full_par_func_header
%type <str> class_func_header_start func_class parameter_list pass_variabledef nopar_class_func_header decl_statements declarations decltype statements statement expression_statement
%type <str> if_statement if_tail while_statement for_statement optexpr return_statement io_statement in_list in_item out_list out_item comp_statement main_function main_header


%left       T_COMMA
%right      T_ASSIGN
%left       T_OROP
%left       T_ANDOP
%nonassoc   T_NOTOP
%left       T_EQUOP
%left       T_RELOP
%left       T_ADDOP
%left       T_MULOP
%nonassoc   T_SIZEOP
%left       T_INCDEC T_LPAREN T_RPAREN T_LBRACK T_RBRACK T_DOT

%nonassoc LOWER_THAN_ELSE
%nonassoc T_ELSE

%start program

%%

program:
    global_declarations main_function
    ;

global_declarations:
    global_declarations global_declaration
    | %empty    { }
    ;

global_declaration:
    typedef_declaration
    | const_declaration
    | class_declaration
    | union_declaration
    | global_var_declaration
    | func_declaration
    ;

typedef_declaration:
    T_TYPEDEF typename listspec T_ID dims T_SEMI                    { hashtbl_insert(hashtbl, $4, NULL, scope); }
    ;

typename:
    standard_type
    | T_ID                                                          { hashtbl_insert(hashtbl, $1, NULL, scope); }
    ;

standard_type:
    T_CHAR
    | T_INT
    | T_FLOAT
    | T_VOID
    ;

listspec:
    T_LIST 
    | %empty    { }
    ;

dims:
    dims dim
    | %empty    { }
    ;

dim:
    T_LBRACK T_ICONST T_RBRACK
    | T_LBRACK T_RBRACK
    ;

const_declaration:
    T_CONST typename constdefs T_SEMI
    ;

constdefs:
    constdefs T_COMMA constdef
    | constdef
    ;

constdef:
    T_ID dims T_ASSIGN init_value                                   { hashtbl_insert(hashtbl, $1, NULL, scope); }
    ;

init_value:
    expression
    | T_LBRACE init_values T_RBRACE
    | T_STRING
    ;

expression:
    expression T_OROP expression
    | expression T_ANDOP expression
    | expression T_EQUOP expression
    | expression T_RELOP expression
    | expression T_ADDOP expression
    | expression T_MULOP expression
    | T_NOTOP expression
    | T_ADDOP expression
    | T_SIZEOP expression
    | T_INCDEC
    | variable T_INCDEC
    | variable
    | variable T_LPAREN expression_list T_RPAREN
    | T_LENGTH T_LPAREN general_expression T_RPAREN
    | T_NEW T_LPAREN general_expression T_RPAREN
    | constant
    | T_LPAREN general_expression T_RPAREN
    | T_LPAREN standard_type T_RPAREN
    | listexpression
    ;

variable:
    variable T_LBRACK general_expression T_RBRACK
    | variable T_DOT T_ID                                           { hashtbl_insert(hashtbl, $3, NULL, scope); }
    | T_LISTFUNC T_LPAREN general_expression T_RPAREN
    | decltype T_ID                                                 { hashtbl_insert(hashtbl, $2, NULL, scope); }
    | T_THIS
    ;

general_expression:
    general_expression T_COMMA general_expression
    | assignment
    ;

assignment:
    variable T_ASSIGN assignment
    | variable T_ASSIGN T_STRING
    | expression
    ;

expression_list:
    general_expression
    | %empty    { }
    ;

constant:
    T_CCONST
    | T_ICONST
    | T_FCONST
    ;

listexpression:
    T_LBRACK expression_list T_RBRACK
    ;

init_values:
    init_values T_COMMA init_value
    | init_value
    ;

class_declaration:
    T_CLASS T_ID                                                    { hashtbl_insert(hashtbl, $2, NULL, scope); scope++;}
        class_body                                                  { hashtbl_get(hashtbl, scope); scope--; }
        T_SEMI                                                     
    ;

class_body:
    parent T_LBRACE members_methods T_RBRACE            
    ;

parent:
    T_COLON T_ID                                                    { hashtbl_insert(hashtbl, $2, NULL, scope); }
    | %empty    { }
    ;

members_methods:
    members_methods access member_or_method
    | access member_or_method
    ;

access:
    T_PRIVATE T_COLON
    | T_PRIVATE error                                               { yyerror("Error! Missing ':'"); yyerrok; }
    | T_PROTECTED T_COLON
    | T_PUBLIC T_COLON
    | %empty    { }
    ;

member_or_method:
    member
    | method
    ;

member:
    var_declaration
    | anonymous_union
    ;

var_declaration:
    typename variabledefs T_SEMI                                                
    ;

variabledefs:
    variabledefs T_COMMA variabledef              
    | variabledef
    ;

variabledef:
    T_LIST T_ID dims                                                { hashtbl_insert(hashtbl, $2, NULL, scope); }
    | T_ID dims                                                     { hashtbl_insert(hashtbl, $1, NULL, scope); }
    ;

anonymous_union:
    T_UNION                                                         { scope++; }
        union_body                                                  { hashtbl_get(hashtbl, scope); scope--;  }
        T_SEMI                                                      
    ;

union_body:
    T_LBRACE fields T_RBRACE
    | T_LBRACE fields error                                         { yyerror("Error! Missing '}'"); yyerrok; }
    ;

fields:
    fields field
    | field
    ;

field:
    var_declaration
    ;

method:
    short_func_declaration
    ;

short_func_declaration:
    short_par_func_header T_SEMI                                    { hashtbl_get(hashtbl, scope); scope--; }
    | nopar_func_header T_SEMI                                      { hashtbl_get(hashtbl, scope); scope--; }
    ;

short_par_func_header:
    func_header_start T_LPAREN parameter_types T_RPAREN                 
    ;  

func_header_start:
    typename T_ID                                                   { hashtbl_insert(hashtbl, $2, NULL, scope); scope++; }
    | T_LIST T_ID                                                   { hashtbl_insert(hashtbl, $2, NULL, scope); }
    ;

parameter_types:
    parameter_types T_COMMA typename pass_list_dims
    | typename pass_list_dims                                                                                                               
    ;

pass_list_dims:
    listspec dims
    | T_REFER
    ;

nopar_func_header:
    func_header_start T_LPAREN T_RPAREN
    ;

union_declaration:
    T_UNION T_ID                                                    { hashtbl_insert(hashtbl, $2, NULL, scope); scope++; }  
        union_body                                                  { hashtbl_get(hashtbl, scope); scope--; }
        T_SEMI                                                       
    ;

global_var_declaration:
    typename init_variabledefs T_SEMI
    ;

init_variabledefs:
    init_variabledefs T_COMMA init_variabledef
    | init_variabledef
    ;

init_variabledef:
    variabledef initializer
    ;

initializer:
    T_ASSIGN init_value
    | %empty    { }
    ;

func_declaration:
    short_func_declaration
    | full_func_declaration
    ;

full_func_declaration:
    full_par_func_header T_LBRACE decl_statements T_RBRACE          { hashtbl_get(hashtbl, scope); scope--; }
    | nopar_class_func_header T_LBRACE decl_statements T_RBRACE     { hashtbl_get(hashtbl, scope); scope--; }
    | nopar_func_header T_LBRACE decl_statements T_RBRACE           { hashtbl_get(hashtbl, scope); scope--; }
    ;

full_par_func_header:
    class_func_header_start T_LPAREN parameter_list T_RPAREN
    | func_header_start T_LPAREN parameter_list T_RPAREN
    ;

class_func_header_start:
    typename func_class T_ID                                        { hashtbl_insert(hashtbl, $3, NULL, scope); scope++; }
    | T_LIST func_class T_ID                                        { hashtbl_insert(hashtbl, $3, NULL, scope); scope++; }
    ;

func_class:
    T_ID T_METH                                                     { hashtbl_insert(hashtbl, $1, NULL, scope); }
    ;

parameter_list:
    parameter_list T_COMMA typename pass_variabledef
    | typename pass_variabledef
    ;

pass_variabledef:
    variabledef
    | T_REFER T_ID                                                    { hashtbl_insert(hashtbl, $2, NULL, scope); }
    ;

nopar_class_func_header:
    class_func_header_start T_LPAREN T_RPAREN
    ;

decl_statements:
    declarations statements
    | declarations
    | statements
    | %empty    { }
    ;

declarations:
    declarations decltype typename variabledefs T_SEMI
    | decltype typename variabledefs T_SEMI
    ;

decltype:
    T_STATIC
    | %empty    { }
    ;

statements:
    statements statement
    | statement
    ;

statement:
    expression_statement
    | if_statement 
    | while_statement
    | for_statement
    | return_statement
    | io_statement
    | comp_statement
    | T_CONTINUE T_SEMI
    | T_BREAK T_SEMI
    | T_SEMI
    ;

expression_statement:
    general_expression T_SEMI
    | general_expression error                                      { yyerror("Error! Missing ';'"); yyerrok; }
    ;

if_statement:
    T_IF T_LPAREN                                                   { scope++; }
        general_expression T_RPAREN statement                       { hashtbl_get(hashtbl, scope); scope--; }
        if_tail                                                     
    | T_IF error general_expression T_RPAREN statement if_tail      { yyerror("Error! Missing '('"); yyerrok; }
    ;

if_tail:
    T_ELSE                                                          { scope++; }
        statement                                                   { hashtbl_get(hashtbl, scope); scope--; }
    | %empty %prec LOWER_THAN_ELSE   { }
    ;

while_statement:
    T_WHILE T_LPAREN                                                { scope++; }
        general_expression T_RPAREN statement                       { hashtbl_get(hashtbl, scope); scope--; }
    ;

for_statement:
    T_FOR T_LPAREN                                                  { scope++; }
        optexpr T_SEMI optexpr T_SEMI optexpr T_RPAREN statement    { hashtbl_get(hashtbl, scope); scope--; }
    ;

optexpr:
    general_expression
    | %empty    { }
    ;

return_statement:
    T_RETURN optexpr T_SEMI
    ;

io_statement:
    T_CIN T_INP in_list T_SEMI
    | T_COUT T_OUT out_list T_SEMI
    ;

in_list:
    in_list T_INP in_item
    | in_item
    ;

in_item:
    variable
    ;

out_list:
    out_list T_OUT out_item
    | out_item
    ;

out_item:
    general_expression
    | T_STRING
    ;

comp_statement:
    T_LBRACE decl_statements T_RBRACE
    ;

main_function:
    main_header
        T_LBRACE decl_statements T_RBRACE                           { hashtbl_get(hashtbl, scope);  scope--; }
    ;

main_header:
    T_INT T_MAIN T_LPAREN T_RPAREN                                  { scope++; }
    ;

%%


int main(int argc, char *argv[]) {

    if(!(hashtbl = hashtbl_create(10, NULL))) {
        puts("Error, failed to initialize hashtable!\n");
        exit(EXIT_FAILURE);
    }

    if(argc > 1) {
        yyin = fopen(argv[1], "r");
        if(yyin == NULL) {
            perror("Error opening file!\n");
            return -1;
        }
    }

    yyparse();

    hashtbl_get(hashtbl, scope);

    hashtbl_destroy(hashtbl);
    fclose(yyin);

    if(syntaxErrors > 0){
        printf("Syntax Analysis failed due to %d errors\n", syntaxErrors);
    }else{
        printf("Syntax Analysis completed successfully.\n");
    }

    return 0;
}

void yyerror(const char * message) {
    syntaxErrors++;

    printf("Error at line %d caused by %s: %s\n", lineNum, yytext, message);

    if(syntaxErrors == MAX_ERRORS) {
        printf("Too many errors! Exitting...\n"); 
        exit(1);
    }
}