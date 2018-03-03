#ifndef SYMBOLTABLE__H
#define SYMBOLTABLE__H
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include "node.h"


/**************************************************************************/
// creat symbol table to store the varibles and functions in the run environment
/**************************************************************************/

class SymbolTable{
  public:
    SymbolTable() {}
    SymbolTable(const std::string funcname): tablename(funcname)
      {//std::cout<<"new symboltabe build" <<std::endl;}
      }
    SymbolTable(const SymbolTable&);
    void setUplayerST(SymbolTable*);
    SymbolTable& operator=(const SymbolTable&)=delete;
    std::string getUpName();
    void print();

    void     setValue(const std::string& name, Node* val);
    Node* getValue(const std::string& name) const;
    std::string getSymbolTableName(){return tablename;}
    void setSymTabName(std::string name){tablename=name;}
  private:
    std::string tablename="main"; // which function's table (char* id)name
    SymbolTable * uplayerST = nullptr;
    std::map<std::string, Node*> table;

};

#endif
