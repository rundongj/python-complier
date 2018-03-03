#include <map>
#include <algorithm>
#include <typeinfo>
#include "symbolTable.h"
#include "literal.h"
#include <string.h>
/*SymbolTable& SymbolTable::getInstance() {
  static SymbolTable instance;
  return instance;
}*/

SymbolTable::SymbolTable(const SymbolTable& _symbolTable) {
  tablename = _symbolTable.tablename;
  uplayerST = _symbolTable.uplayerST;
  table = _symbolTable.table;
}

std::string SymbolTable::getUpName() { 
  if(tablename == "main")
    return "main";
  else {
    return uplayerST -> tablename; 
  }
}

Node* SymbolTable::getValue(const std::string& name) const {
  std::map<std::string, Node*>::const_iterator it = table.find(name);
  if ( it == table.end() ) {
    SymbolTable* tmp = uplayerST;
    while(tmp) {
      std::map<std::string, Node*>::const_iterator it = tmp->table.find(name);
      if ( it == tmp -> table.end() ) {
        tmp = tmp -> uplayerST;
      }
      else
        return it->second;
    }
    if(!tmp)
      throw "Can't find the varible";
    return nullptr;


  }
  else
    return it->second;
}

//Node* SymbolTable::getValue(const std::string& name) const {
//  /**********************************************************/
//  SymbolTable* parents = const_cast<SymbolTable*>(this);
//  while(parents) {
//    std::map<std::string, Node*>::const_iterator it = parents -> table.find(name);
//    if ( it == table.end() ) {
//      /*********************************************************/
//      //std::cout << " in symble table:"<<parents->getSymbolTableName()<< "getvalue can't find" << std::endl;
//      /*********************************************************/
//
//      parents = parents -> uplayerST;
//      /*********************************************************/
//      //std::cout << " go upper to:"<<parents->getSymbolTableName() << std::endl;
//      /*********************************************************/
//    }
//    else {
//      //it -> second -> eval() -> print();
//      /*****************************************************************/
//      //std::cout <<"symble table get the Value and type is: "<<typeid(*(it->second)).name() << std::endl;
//      /*****************************************************************/
//      return it->second;
//    }
//  }
//  /*********************************************************/
//  std::cout << "symTab can't find then return" << std::endl;
//  /*********************************************************/
//  return nullptr;
//   /*********************************************************/
//}

void SymbolTable::print() {
  SymbolTable* tmp = this;
  while(tmp) {
    std::cout << " name: " << tmp -> tablename;
    tmp = tmp -> uplayerST;
  }
  std::cout << std::endl;

}

void SymbolTable::setUplayerST(SymbolTable* symbolTable) {
  uplayerST = symbolTable;
}

void SymbolTable::setValue(const std::string& name, Node* val) {
/**********************************************/ 
 //std::cout << "currrent table set value:"<< name << std::endl;
/**********************************************/
  table[name]=val;
}

