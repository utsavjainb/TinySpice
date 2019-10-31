%token Declare Begin End
%token Assign /* th is is for the lexeme ":=" */
%left And
%nonassoc '<'
%left '+'
%left '*'
%left Not
%token Identifier Integer_literal
%token resistorID currentID

%{
    #include <iostream>
    #include <Eigen/Dense>
    #include <Eigen/LU> 
    #include <fstream>
    using Eigen::MatrixXd;  
    using Eigen::VectorXd;
    extern int Line;
    #define yyerror(s) cout << "ERROR " << Line << ": " s "\n"
    extern int yylex();
    #include "symtab.h"
    extern char* yytext;
    #include <string.h>
    using namespace std;
    //table *symtable = new table();
    Matrix * matrix = new Matrix(4,4);
    MatrixXd rmat(4,4);
    VectorXd ivec(4);

%}

%union {
    char *st;
}

%type<st> Identifier Integer_literal resistorID currentID

%%



start_sym:
    resistor_list
    current_list
    End
        { 
        //matrix->print();
        cout << "Resist: " << endl;
        cout << rmat << endl;
        cout << rmat.inverse() << endl;
        cout << "Currents: " << endl;
        cout << ivec << endl;
        cout << "Result: " << endl;
        cout << rmat.inverse()*ivec << endl;
        }
;

resistor_list:
        resistor_list
        resistor
    |   resistor
;

resistor:
        resistorID Integer_literal Integer_literal Integer_literal{
            {
                cout << $1 << " " << $2 << " " << $3 << " " << $4 << endl;
                int i = (atoi)$2 - 1;
                int j = (atoi)$3 - 1;
                
                float val;

                if($1[0] == 'R'){
                    val =  (1 / float((atoi)$4) );
                }

                else {
                    val =  float((atoi)$4);
                }
                
                //cout << "val: " << val << endl;

                
                if (i != -1 && j != -1){
                    rmat(i,i) += val;
                    rmat(j,j) +=  val;
                    rmat(i, j) += -1 * val;
                    rmat(j, i) += -1 * val;
                }

                else if (j == -1){
                    rmat(i,i) += val;
                }

                else if (i == -1) {
                    rmat(j, j) += val;
                }
            }
        }
;

current_list:
        current_list
        current
    |   current
;


current:
        currentID Integer_literal Integer_literal Integer_literal
        {
            cout << $1 << " " << $2 << " " << $3 << " " << $4 << endl;
            int out = (atoi)$2 - 1;
            int into = (atoi)$3 - 1;
            float val = float(atoi($4));
        
            if (out >= 0){
                ivec(out) += -1 * val;
            }
            
            if (into >= 0){
                ivec(into) += val;

            }

        }
;


