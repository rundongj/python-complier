#include <map>
#include <algorithm>
#include "SymTabManager.h"
#include "literal.h"

SymTabManager& SymTabManager::getInstance() {
  /***************************************************/
  //std::cout<<"table manager getinstance" <<std::endl;
  /***************************************************/
  static SymTabManager instance;
  return instance;
}

SymTabManager::SymTabManager() :nowtablename("main") {
  managertable["main"] = new SymbolTable();
  nowtablename = "main";
}
SymTabManager::~SymTabManager() {
  delete managertable.find("main")->second;
  //for(auto it : managertable) {
  //  delete it.second;
  //}
}
void  SymTabManager::addtable(const std::string funcname, SymbolTable* symbolTable)
{
  managertable[funcname] = symbolTable;

}


void   newtable(std::string tablename, SymbolTable*);

SymbolTable* SymTabManager::findTable(std::string funcname)
{
  std::map<std::string, SymbolTable*>::iterator it = managertable.find(funcname);
  if(it != managertable.end())
    return it -> second;
  else 
    return nullptr;
}

// void     SymTabManager::setnowtable(SymbolTable* funcCalltable){
//   currentTable=funcCalltable;

// }

void  SymTabManager::setnowtable(const std::string funcname)
{
	nowtablename=funcname;
  std::map<std::string, SymbolTable*>::iterator it = managertable.find(nowtablename);
  /*************************************************/
  //std::cout <<"now scope is:"<< nowtablename << std::endl;
  /**************************************************/
  if(it != managertable.end())
    currentTable= it -> second;
  else 
    throw "can't find table by name";
  return ;
}


SymbolTable* SymTabManager::getCurrentSymbolTable() {
  return currentTable;

}
