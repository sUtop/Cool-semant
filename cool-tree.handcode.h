//
// The following include files must come first.

#ifndef COOL_TREE_HANDCODE_H
#define COOL_TREE_HANDCODE_H

#include <iostream>
#include "tree.h"
#include "cool.h"
#include "stringtab.h"
#include "symtab.h"
#define yylineno curr_lineno;
extern int yylineno;

inline Boolean copy_Boolean(Boolean b) {
    return b;
}

inline void assert_Boolean(Boolean) {
}

inline void dump_Boolean(ostream& stream, int padding, Boolean b) {
    stream << pad(padding) << (int) b << "\n";
}

void dump_Symbol(ostream& stream, int padding, Symbol b);
void assert_Symbol(Symbol b);
Symbol copy_Symbol(Symbol b);

class Program_class;
typedef Program_class *Program;
class Class__class;
typedef Class__class *Class_;
class Feature_class;
typedef Feature_class *Feature;
class Formal_class;
typedef Formal_class *Formal;
class Expression_class;
typedef Expression_class *Expression;
class Case_class;
typedef Case_class *Case;
class Environment;
typedef SymbolTable<Symbol, Class__class> class_list_type;
typedef SymbolTable<Symbol, tree_node> attr_list_type;
typedef SymbolTable<Symbol, tree_node> method_list_type;


typedef list_node<Class_> Classes_class;
typedef Classes_class *Classes;
typedef list_node<Feature> Features_class;
typedef Features_class *Features;
typedef list_node<Formal> Formals_class;
typedef Formals_class *Formals;
typedef list_node<Expression> Expressions_class;
typedef Expressions_class *Expressions;
typedef list_node<Case> Cases_class;
typedef Cases_class *Cases;

#define SEMANT_VIRTUAL_FUNCT \
virtual void semant(class_list_type*,attr_list_type*,method_list_type*) = 0;

#define SEMANT_FUNCT \
void semant(class_list_type*,attr_list_type*,method_list_type*); 

#define Program_EXTRAS                          \
virtual void semant() = 0;			\
virtual void dump_with_types(ostream&, int) = 0; 

#define program_EXTRAS                          \
void semant();     				\
void dump_with_types(ostream&, int);            

#define Class__EXTRAS                   \
SEMANT_VIRTUAL_FUNCT			\
virtual Symbol get_filename() = 0;      \
virtual Symbol get_parent() = 0;        \
virtual void dump_with_types(ostream&,int) = 0;   \
virtual attr_list_type *get_attr() = 0;  \
virtual method_list_type *get_methods() = 0;


#define class__EXTRAS                                 \
SEMANT_FUNCT    				\
Symbol get_filename() { return filename; }             \
void dump_with_types(ostream&,int);                    


#define Feature_EXTRAS                                        \
virtual Symbol get_name() = 0;                  \
virtual Symbol get_type() = 0;                  \
SEMANT_VIRTUAL_FUNCT			\
virtual void dump_with_types(ostream&,int) = 0; 


#define Feature_SHARED_EXTRAS                                       \
Symbol get_name() {return name;}                \
Symbol get_type() {return type;}                \
SEMANT_FUNCT     				\
void dump_with_types(ostream&,int);    


#define Formal_EXTRAS                              \
SEMANT_VIRTUAL_FUNCT			\
virtual void dump_with_types(ostream&,int) = 0;


#define formal_EXTRAS                           \
SEMANT_FUNCT     				\
void dump_with_types(ostream&,int);             \
Symbol get_name() {return name;};               \
Symbol get_type() {return type_decl;}


#define Case_EXTRAS                             \
SEMANT_VIRTUAL_FUNCT			\
virtual void dump_with_types(ostream& ,int) = 0;


#define branch_EXTRAS                                   \
Symbol get_type();                             \
SEMANT_FUNCT     				\
void dump_with_types(ostream& ,int);


#define Expression_EXTRAS                    \
Symbol type;                                 \
virtual Symbol get_type();                           \
Expression set_type(Symbol s) { type = s; return this; } \
virtual void dump_with_types(ostream&,int) = 0;  \
void dump_type(ostream&, int);               \
SEMANT_VIRTUAL_FUNCT			\
Expression_class() { type = (Symbol) NULL; }

#define Expression_SHARED_EXTRAS           \
SEMANT_FUNCT     				\
Symbol get_type() {return type;};                          \
void dump_with_types(ostream&,int); 

#endif
