#pragma once

//  Declarations for a calculator that builds an AST
//  and a graphical representation of the AST.
//  by Brian Malloy

#include <iostream>
#include <string>
#include <map>
#include "literal.h"
#include <sstream>

class SymbolTable;
class SuiteNode;

extern void yyerror(const char*);
extern void yyerror(const char*, const char);

class IdentNode : public Node {
public:
  IdentNode(const std::string id) : Node(), ident(id) { } 
  virtual ~IdentNode() {}
  const std::string getIdent() const { return ident; }
  virtual const Node* eval() ;
private:
  std::string ident;
};

class BinaryNode : public Node {
public:
  BinaryNode(Node* l, Node* r) : Node(), left(l), right(r) {}
  virtual const Node* eval() = 0;
  Node* getLeft()  const { return left; }
  Node* getRight() const { return right; }
  BinaryNode(const BinaryNode&) = delete;
  BinaryNode& operator=(const BinaryNode&) = delete;
protected:
  Node *left;
  Node *right;
};

class UnaryNode : public Node {
public:
  UnaryNode(Node* nod) : Node(),node(nod) { }
  virtual const Node* eval() =0;
  Node* getNode() const { return node; }
  UnaryNode(const UnaryNode&) = delete;
  UnaryNode & operator=(const UnaryNode&) = delete;
protected:
  Node * node; 
};




class TildeUnaryNode : public UnaryNode {
public:
  TildeUnaryNode(Node* node):UnaryNode(node){};
  virtual const Node* eval() ;
};


class AsgBinaryNode : public BinaryNode {
public:
  AsgBinaryNode(Node* left, Node* right);
  virtual const Node* eval() ;
};


class PowerBinaryNode : public BinaryNode {
public:
  PowerBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Node* eval() ;
};

class AddBinaryNode : public BinaryNode {
public:
  AddBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Node* eval() ;
};

class SubBinaryNode : public BinaryNode {
public:
  SubBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Node* eval();
};

class MulBinaryNode : public BinaryNode {
public:
  MulBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Node* eval();
};

class DoubleSlaBinaryNode : public BinaryNode {
public:
  DoubleSlaBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Node* eval();
};

class DivBinaryNode : public BinaryNode {
public:
  DivBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Node* eval();
};

class PercentBinaryNode : public BinaryNode {
public:
  PercentBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Node* eval();
};

class LeftShiftNode : public BinaryNode {
public:
  LeftShiftNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Node* eval();
};

class RightShiftNode : public BinaryNode {
public:
  RightShiftNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Node* eval();
};

class BarNode : public BinaryNode {
public:
  BarNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Node* eval();
};


class CIRCUMFLEXNode : public BinaryNode {
public:
  CIRCUMFLEXNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Node* eval();
};


class AMPERSANDNode : public BinaryNode {
public:
  AMPERSANDNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Node* eval();
};


/*******************************/

class BiggerBinaryNode : public BinaryNode {
public:
  BiggerBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Node* eval();
};

class LesserBinaryNode : public BinaryNode {
public:
  LesserBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Node* eval();
};

class BgEqBinaryNode : public BinaryNode {
public:
  BgEqBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Node* eval();
};

class LsEqBinaryNode : public BinaryNode {
public:
  LsEqBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Node* eval();
};

class EqEqBinaryNode : public BinaryNode {
public:
  EqEqBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Node* eval();
};

/***********************************/
//  the nodes needed for the function 
/***********************************/
/***********************************/
/***********************************/



/***********************************/
// printnode need be used into the function 

/***********************************/

class PrintNode: public Node{
public:
PrintNode(std::vector<Node*>* n):PrNode(n){}
PrintNode& operator=(const PrintNode&)=delete;
PrintNode(const PrintNode&)=delete;
~PrintNode() { delete PrNode; }

virtual const Node* eval();
private:
std::vector<Node*>* PrNode;
};


/********************************************************/
//in funcdefnode we creat the new function node 
//and add it into the the current symbol table
//when we define the node
//the define function symboltable is used for static verables and parameters 
/********************************************************/

class FuncDefNode : public Node {
public:
  FuncDefNode(std::string name,SuiteNode* suite,std::vector<Node*>& paras);
  FuncDefNode(std::string name,SuiteNode* suite);

  FuncDefNode(const FuncDefNode&)=delete;
  ~FuncDefNode();
  FuncDefNode& operator=(const FuncDefNode&)=delete;

  std::string getName() { return funcname; }
  SuiteNode* returnSuite() const { return mysuite; }
  void FuncCallCountPlus(){callcount++;}
  std::string GetCallCountName();

  //void setDefParameters(Node*){defParameters.push_back(Node *); }
  std::vector<Node*> getDefParameters(){return defParameters;}
  virtual const Node* eval();

private:
  std::string funcname;
  SymbolTable* __symbolTable;
  SuiteNode* mysuite;
  std::vector<Node*> defParameters;
  int callcount=0;
};
/********************************************************/
//parameter node
/********************************************************/







/********************************************************/
//when function called it will run it's suite AST
// and have it's symboltable
//it will be down in the eval() function.
/********************************************************/
class FuncCallNode: public Node{
  public:
    FuncCallNode(std::string name):funcname(name){}
    FuncCallNode(std::string name,std::vector<Node*>& (paras) ):funcname(name),callParameters(paras){}

    ~FuncCallNode();

    //void setCallParameters(Node*){callParameters.push_back(Node *); }
    std::vector<Node*>& getCallParameters(){return callParameters;}

    virtual const Node* eval();
  private:
    std::string funcname;
    SymbolTable* symbolTable = nullptr;
    std::vector<Node*> callParameters;


} ;

/********************************************************/
//suite node will have it's own AST nodes table 
//and it will belown's to a function node 
/********************************************************/
class SuiteNode : public Node {
public:

  SuiteNode(std::vector<Node*>* suite) : suiteASTTab(*suite) {  }
  SuiteNode(Node* node) { 
    suiteASTTab.push_back(node);
  }
  //~SuiteNode() { delete suiteASTTab; }

  std::vector<Node*>* returnASTTab(){return &suiteASTTab; }
  // return the asttab for a global variable and pass to the plus_stmt 
  void setSuiteName(std::string name){suitname=name;}

  virtual const Node* eval();
private: 
  std::vector<Node*> suiteASTTab;
  std::string suitname;//when reduce to func we can decide that;
};
/***********************************/

/***************************************************/
//return node 
/***************************************************/
class ReturnNode: public Node{
public:
  ReturnNode(Node* node):returnNode(node){}
  ReturnNode();
  //virtual ~ReturnNode() { delete returnNode; }
  virtual const Node* eval();
private:
  Node* returnNode;
};


class IfNode: public Node{
public:
   IfNode(Node* test, Node * ifsuite, Node* elsesuite):Tnode(test),Inode(ifsuite),Enode(elsesuite){}
   IfNode(Node* test, Node * ifsuite):Tnode(test),Inode(ifsuite){}
   virtual const Node* eval();
private:
   Node * Tnode;
   Node * Inode;
   Node * Enode;
};

