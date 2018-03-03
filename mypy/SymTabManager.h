#ifndef SYMTABMANAGER__H
#define SYMTABMANAGER__H

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include "symbolTable.h"
/****************************************************/
// every function will ask the table manager
// to get their symboltable
// the 
/****************************************************/
class Literal;

class SymTabManager {
public:
  static   SymTabManager& getInstance();
  ~SymTabManager();
  void     addtable(std::string tablename, SymbolTable*);
  void     setnowtable(const std::string funcname);
  //void     setnowtable(SymbolTable* funcCalltable);   
  SymbolTable* findTable(const std::string funcname);
  SymbolTable* getCurrentSymbolTable();
private:
  std::string nowtablename;
  SymbolTable* currentTable=nullptr;
  std::map<std::string, SymbolTable*> managertable;
  SymTabManager();
};

#endif
