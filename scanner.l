

A [_a-z]
N [_0-9]
AN [_a-z0-9]
%{
    #include "declare.tab.h"
    #include <iostream>
    using namespace std;
    int Line = 1;
%}
%option noyywrap
%option nounput
%%
declare            return Declare;
begin              return Begin;
end                return End;
:=                 return Assign;
and                return And;
not                return Not;
[-+*/()<:;]        return yytext[0];
{N}+         yylval.st = strdup(yytext); return Integer_literal;
[R|G]{1}{N}+           yylval.st = strdup(yytext); return resistorID;
I{N}+           yylval.st = strdup(yytext); return currentID;
[ \t]              { }
--.*               { }
\n                 Line++;
.                  cout << "Line " << Line << ": lexical error `" << yytext[0] << "'\n";
