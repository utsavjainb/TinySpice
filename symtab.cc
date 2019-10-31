/*
ICS 142A Homework 4
Name: Utsav Jain
ID: 86175231
*/
#include "symtab.h"
#include <string.h>
#include <iostream>
using namespace std;


void table::enter_symbol (const char *name, type_kind type) {
    List_Node *temp = new List_Node( (char *) name, type, head);  //typecase const char * to char *
    head = temp;
}


type_kind table::find_symbol (char *name) { // looks for node in list with matching naem and returns type
    List_Node *rover = head;
    while(rover != NULL) {
        if(strcmp(rover->info->name,name) == 0) {
            return rover->info->type;
        }
        rover = rover->next;
    }
    return undefined_type;
}

void table::enter_scope() { //adds Node to list with name mark
    cout << "Entering Scope..." << endl;
    char *marker = "mark";
    enter_symbol(marker, undefined_type);
}

void table::print_table() {
    List_Node *rover = head;
    cout << "printing table.." << endl;
    while(rover != NULL) {
        cout << rover->info->name << ": " << rover->info->type << endl;
        rover = rover->next;
    }
    cout << "endings table.." << endl;

}

void table::exit_scope() { //deletes nodes until marking node which denotes start of scope
    cout << "---" << endl;
    while (head->info->name != "mark"){
        List_Node *rover = head;
        string typestr;
        switch(rover->info->type) {
            case 1:
                typestr = "integer";
            case 2:
                typestr = "boolean";
        }
        cout << rover->info->name << ":" << typestr << endl;
        head = head->next;
        delete rover;
    }
    List_Node *rover = head;
    head = head->next;
    delete rover;
    cout << "---" << endl;
    cout << "Exiting Scope..." << endl;
}


void Matrix::insert(int r, int c, int val){
    mat[r][c] += val;
}

void Matrix::print(){
    for(int i = 0 ;i < ROW; i++){
        for(int j = 0; j < COL; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

type_kind type_check(int op, type_kind left, type_kind right) {
    
    // < operator
    if (op == 60 ) {
        if (left != right) {
            cout << "ERROR: < operator invalid operand type" << endl;  
            return undefined_type;         
        }
        else {
            return boolean_type;
        }
    }

    else if (op == 42) {
        if (left != integer_type || right != integer_type) {
            cout << "ERROR: + operator has invalid operands" << endl;
            return undefined_type;
        }
        else {
            return integer_type;
        }
    }
    
    else if (op == 43) {
        if (left != integer_type || right != integer_type) {
            cout << "ERROR: * operator has invalid operands" << endl;
            return undefined_type;
        }
        else {
            return integer_type;
        }
    }

    //AND
    else if (op == 888) {
        if (left != boolean_type || right != boolean_type ) {
            cout << "ERROR: Invlaid operand for AND operator" << endl;
            return undefined_type;
        }
        else {
            return boolean_type;
        }
    }

    //NOT
    else if (op == 889) {
        if (right != boolean_type) {
            cout << "ERROR: Invlaid operand for NOT operator" << endl;
            return undefined_type;
        }
        else {
            return boolean_type;
        }
    } 

    //put
    else if (op == 900){
        if (right != boolean_type || right != integer_type){
            cout << "ERROR: Invlaid operand for put operator" << endl;
            return undefined_type;
        }
        else {
            return right;
        }
    }

    else if (op == 901){
        if (right != boolean_type || right != integer_type){
            cout << "ERROR: Invalid operand for get operator" << endl;
            return undefined_type;
        }
        else {
            return right;
        }
    }
}



