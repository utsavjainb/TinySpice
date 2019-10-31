enum type_kind {undefined_type, integer_type, boolean_type};


struct type_pair {
     char *name;
     type_kind type;

     type_pair(char *n, type_kind t) {
        name = n;
        type = t;
     }
};

struct List_Node {
     type_pair *info;
     List_Node *next;

     List_Node ( char *name, type_kind type, List_Node *t) {
          info = new type_pair(name, type);
          next = t;
     }
     List_Node(List_Node *t) { // useful for the scope markers
          info = 0;
          next = t;
     }
};

typedef List_Node *List;
 
     
class table {
     List head; // the rep. for a table is a linked list of type_pairs
  public:
     void enter_symbol (const char *name, type_kind type);
     type_kind find_symbol (char *name);
     void enter_scope();
     void exit_scope();
     void print_table();
     table() { // constructor for a table
        head = 0;
        enter_symbol("integer", integer_type);
        enter_symbol("boolean", boolean_type);
        enter_symbol("true", boolean_type);
        enter_symbol("false", boolean_type);
        //print_table();
     }
};



class Matrix{
     int **mat;
     public:
          int ROW;
          int COL;
          Matrix(int rows, int cols){
               ROW = rows;
               COL = cols;
               mat = new int *[rows];
               if (mat) {               
                    for (int i = 0; i < rows; i++) {
                         mat[i] = new int [cols];
                         //assert(mat[i]);           
                    }
               }
          }

          void insert(int r, int c, int val);
          void print();
};



type_kind type_check(int op, type_kind left, type_kind right);
 
