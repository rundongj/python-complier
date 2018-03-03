#include <iostream>
#include <typeinfo>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include "ast.h"
#include "SymTabManager.h"
#include "symbolTable.h"
#include <typeinfo>
#include <sstream>

const Node* TildeUnaryNode::eval() { 
  const Literal* val = dynamic_cast<const Literal*>((this->getNode())->eval());
  return (~(*val));
}




const Node* IdentNode::eval() { 
  return ((SymTabManager::getInstance().getCurrentSymbolTable())-> getValue(ident));

}


AsgBinaryNode::AsgBinaryNode(Node* left, Node* right) : 
  BinaryNode(left, right) { 
}


const Node* AsgBinaryNode::eval() { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* res = dynamic_cast<const Literal*>(right->eval());
  
  
  const std::string n = dynamic_cast<IdentNode*>(left)->getIdent();

  SymTabManager::getInstance().getCurrentSymbolTable()-> setValue(n, const_cast<Literal*>(res));
  return res;
}

const Node* PowerBinaryNode::eval() { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = dynamic_cast<const Literal*>(left->eval());
  const Literal* y = dynamic_cast<const Literal*>(right->eval());
  return ((*x).power(*y));
}

const Node* AddBinaryNode::eval() { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = dynamic_cast<const Literal*>(left->eval());
  const Literal* y = dynamic_cast<const Literal*>(right->eval());
  return (*x+*y);
}

const Node* SubBinaryNode::eval() { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = dynamic_cast<const Literal*>(left->eval());
  const Literal* y = dynamic_cast<const Literal*>(right->eval());
  return ((*x)-(*y));
}

const Node* MulBinaryNode::eval() { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = dynamic_cast<const Literal*>(left->eval());
  const Literal* y = dynamic_cast<const Literal*>(right->eval());
  return ((*x)*(*y));
}


const Node* DoubleSlaBinaryNode::eval() { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = dynamic_cast<const Literal*>(left->eval());
  const Literal* y = dynamic_cast<const Literal*>(right->eval());
  return ((*x).DoubleSla(*y));
}



const Node* DivBinaryNode::eval() { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = dynamic_cast<const Literal*>(left->eval());
  const Literal* y = dynamic_cast<const Literal*>(right->eval());
  return ((*x)/(*y));
}



const Node* PercentBinaryNode::eval() { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = dynamic_cast<const Literal*>(left->eval());
  const Literal* y = dynamic_cast<const Literal*>(right->eval());
  return ((*x)%(*y));
}



const Node* LeftShiftNode::eval() { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = dynamic_cast<const Literal*>(left->eval());
  const Literal* y = dynamic_cast<const Literal*>(right->eval());
  return ((*x)<<(*y));
}


const Node* RightShiftNode::eval() { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = dynamic_cast<const Literal*>(left->eval());
  const Literal* y = dynamic_cast<const Literal*>(right->eval());
  return ((*x)>>(*y));
}


const Node* BarNode::eval() { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = dynamic_cast<const Literal*>(left->eval());
  const Literal* y = dynamic_cast<const Literal*>(right->eval());
  return ((*x)|(*y));
}


const Node* CIRCUMFLEXNode::eval() { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = dynamic_cast<const Literal*>(left->eval());
  const Literal* y = dynamic_cast<const Literal*>(right->eval());
  return ((*x)^(*y));
}


const Node* AMPERSANDNode::eval() { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = dynamic_cast<const Literal*>(left->eval());
  const Literal* y = dynamic_cast<const Literal*>(right->eval());
  return ((*x)&(*y));
}

/**********************************************
BiggerBinaryNode
LesserBinaryNode
BgEqBinaryNode
LsEqBinaryNode
EqEqBinaryNode
*********************************************/

const Node* BiggerBinaryNode::eval() { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = dynamic_cast<const Literal*>(left->eval());
  const Literal* y = dynamic_cast<const Literal*>(right->eval());
  return ((*x)>(*y));
}

const Node* LesserBinaryNode::eval() { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = dynamic_cast<const Literal*>(left->eval());
  const Literal* y = dynamic_cast<const Literal*>(right->eval());
  return ((*x)<(*y));
}

const Node* BgEqBinaryNode::eval() { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = dynamic_cast<const Literal*>(left->eval());
  const Literal* y = dynamic_cast<const Literal*>(right->eval());
  return ((*x)>=(*y));
}

const Node* LsEqBinaryNode::eval() { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = dynamic_cast<const Literal*>(left->eval());
  const Literal* y = dynamic_cast<const Literal*>(right->eval());
  return ((*x)<=(*y));
}

const Node* EqEqBinaryNode::eval() { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = dynamic_cast<const Literal*>(left->eval());
  const Literal* y = dynamic_cast<const Literal*>(right->eval());
  return ((*x)==(*y));
}

/**********************************************/
//function eval parts
/**********************************************/


/**********************************************/
// funcdefnoed symbol table save the parameters and static varible
/**********************************************/

FuncDefNode::FuncDefNode(std::string name, SuiteNode* suite ):funcname(name),mysuite(suite)
{
  __symbolTable = new SymbolTable(name);
  SymTabManager::getInstance().addtable(funcname, __symbolTable);

  /**********************************************/
  //std::cout<< funcname<<"function def init"<<std::endl;
  /**********************************************/
}
FuncDefNode::FuncDefNode(std::string name, SuiteNode* suite, std::vector<Node*>& paras):funcname(name),mysuite(suite),defParameters(paras){
  __symbolTable = new SymbolTable(name);
  SymTabManager::getInstance().addtable(funcname, __symbolTable);

}


FuncDefNode::~FuncDefNode() { 
	delete __symbolTable; 
	//delete defParameters;
	}


/**********************************************/
//when define add the function parameters static table to the manager
/**********************************************/

const Node* FuncDefNode::eval() {
  /*******************************************************/
   //std::cout<<funcname<<" funcdef node eval called, add  this node to table and new table"<<std::endl;
  /*******************************************************/
  SymTabManager::getInstance().getCurrentSymbolTable()->setValue(funcname, this);
  __symbolTable -> setUplayerST(SymTabManager::getInstance().getCurrentSymbolTable());
  //mysuite->setSuiteName(funcname);
  return this;
}

std::string   FuncDefNode::GetCallCountName(){
	std::stringstream s;
	s<<callcount;
	return s.str();
}









/******************************************************************************************/
//run the suit's AST table, (the run environment has been setted to the function table)
/*****************************************************************************************/

const Node* SuiteNode::eval() {
  std::vector<std::string> IDNotInLocalUsed;
  for (auto it : suiteASTTab){
    FuncCallNode* call = dynamic_cast<FuncCallNode*>(it);
    if(call) {
      FuncCallNode* new_funcCall = new FuncCallNode(*call);
      PoolOfNodes::getInstance().add(new_funcCall);
      const Node* res = new_funcCall -> eval();
      if(res)
        {
          return res;
        }

      continue;
    }

    IfNode* ifNode = dynamic_cast<IfNode*>(it);
    if(ifNode) {
      const Node* res = ifNode -> eval();
      if(res)
        return res;
      continue;
    }


    ReturnNode* RNode= dynamic_cast<ReturnNode*>(it);
    if (RNode)
    {
      std::cout<<"return caled in suite eval()"<<std::endl;
      return (RNode->eval());
    }
    /*************************************************************/
    //preprocessing
    /*************************************************************
    IdentNode* ID=dynamic_cast<IdentNode*>(it);
    if(ID)
    {
    	std::string identID=ID->getIdent();
    	if(SymTabManager::getInstance().getCurrentSymbolTable()->getValue(identID)==nullptr \
    		&& (std::find(IDNotInLocalUsed.begin(),IDNotInLocalUsed.end(),identID))==IDNotInLocalUsed.end() )//not find
    		{
    			IDNotInLocalUsed.push_back(identID);
    			std::cout<<"first"<<std::endl;
    		}//if not in local symbol table, and first time be used
    }
    //if the assign is not the first time we use the ident,
    // which means we used the uplayer variable, and assign it value. this is wrong
    AsgBinaryNode* asg=dynamic_cast<AsgBinaryNode*>(it);
    if(asg)
    {
       std::string asgID =dynamic_cast<IdentNode*>(asg->getLeft())->getIdent();
       if (SymTabManager::getInstance().getCurrentSymbolTable()->getValue(asgID)==nullptr\
       && std::find(IDNotInLocalUsed.begin(),IDNotInLocalUsed.end(),asgID)!=IDNotInLocalUsed.end())//if find and the first using is not assign.
       	{ 
       		std::cout<<"assign"<<std::endl;
       		throw ("can't assingn value to this variable");
       	}
    }

    *************************************************************/



    it->eval();
  }
  return nullptr;
}


//const Node* SuiteNode::eval()
//{
//  std::vector<Node*>::const_iterator it = suiteASTTab.begin();
//  while(it != suiteASTTab.end()) {
//  	//if (dynamic_cast<FuncDefNode>(*it)
//    (*it) -> eval();
//    it++;
//  }
//  return nullptr;
//}




/**********************************************/
//when call the eval we need first set the nowtable

//then we can new a local table and use the function 
//parameter static table initial this local table 
//(this is functioncall scope like f(1))


//change the environment to local and run 
// /**********************************************/
 FuncCallNode::~FuncCallNode() {if(symbolTable) delete symbolTable;}

const Node* FuncCallNode::eval() {
  symbolTable = new SymbolTable(*SymTabManager::getInstance().findTable(funcname));
  symbolTable -> setSymTabName(funcname);
  /***************************************************************/
  //symbolTable -> print();
  //std::cout << "current " << symbolTable -> getSymbolTableName() << std::endl;
  //std::cout << "current " << funcname << " father " << symbolTable->getUpName() << std::endl;
  /***************************************************************/
  SymTabManager::getInstance().setnowtable(funcname);
  /***************************************************************/
  //PoolOfNodes::getInstance().addSymbolTable(symbolTable);
 
  Node* s = symbolTable -> getValue(funcname);
  /*************************************************************/
  //std::cout << typeid(*s).name() << std::endl;
  /***************************************************************/
  FuncDefNode* func = dynamic_cast<FuncDefNode*>(s);
  if(func) {
    /***************************************************************/
    //std::cout << "get father: " << symbolTable->getUpName() << std::endl;
    /***************************************************************/
    std::cout <<"funccall eval()"<<std::endl;
    const Node* res = func -> returnSuite() -> eval();
    SymTabManager::getInstance().setnowtable(symbolTable->getUpName());
    return res;
  }
  else {
    std::cout << "wrong way" <<  std::endl;

  }
  return nullptr;
}

    /***************************************************************/
    /***************************************************************/


// const Node* FuncCallNode::eval(){
// 	  /**************************************************************/
//      //std::cout<<funcname<<" funccall eval called"<<std::endl; 
//      //std::cout<<"ask for funcTab from manager"<<std::endl;
//      /**************************************************************/
//      //SymbolTable* st = SymTabManager::getInstance().getCurrentSymbolTable();
//  //std::cout << "current " << st -> getSymbolTableName() << std::endl;
//  //std::cout << "current " << funcname << " father " << st->getUpName() << std::endl;

//      Node* tempDefFuncNode = SymTabManager::getInstance().getCurrentSymbolTable()->getValue(funcname);
//      std::string funccount;
//      if(dynamic_cast<FuncDefNode*>(tempDefFuncNode))
//      {
//      	dynamic_cast<FuncDefNode*>(tempDefFuncNode)->FuncCallCountPlus();
//        funccount=dynamic_cast<FuncDefNode*>(tempDefFuncNode)->GetCallCountName();
//      }

//      symbolTable = SymTabManager::getInstance().findTable(funcname);

//      if(symbolTable) {
//      	/**************************************************************/
//      	std::cout<<"get funcdef SymTab  new a local table"<<std::endl;
//      	/**************************************************************/
//        symbolTable = new SymbolTable(*symbolTable);
//        symbolTable->setSymTabName(funcname+funccount);// 
//        symbolTable -> setUplayerST(SymTabManager::getInstance().getCurrentSymbolTable());
//        symbolTable -> setSymTabName(funcname+funccount);

//        /*******************************************************************************/
//        //add this local copy table to this table manager and add this node to current table 
//        *************************************************************************
//        SymTabManager::getInstance().addtable(funcname+funccount,symbolTable);
//        SymTabManager::getInstance().getCurrentSymbolTable()->setValue(funcname+funccount, this);

//        //SymTabManager::getInstance(),setnowtable(funcname+funccount);//
//        ///////recursion do it latter

//      }
//      Node* func = symbolTable -> getValue(funcname);// we just have one suite node for every function
//      if(func) {
//      	/**************************************************************/
//      	std::cout<<"set the scope to loacal copy table "<<(funcname)<<std::endl;
//      	/**************************************************************/
//        SymTabManager::getInstance().setnowtable(funcname+funccount);
//        FuncDefNode* funcDef = dynamic_cast<FuncDefNode*>(func);
//        SuiteNode* suite = funcDef -> returnSuite();
//        suite -> eval();
//      }
//      else
//        throw "Func did not exit";
//      /**************************************************************/
//      //std::cout << symbolTable -> getUpName() << std::endl;
//      //std::cout<<"func eval end then go up to:"<<symbolTable -> getUpName()<<std::endl;
//      /**************************************************************/
//      SymTabManager::getInstance().setnowtable(symbolTable -> getUpName());
//      //for the static we nede write a add function and add the changed varible to the table.
//      //and the delete this function's symbol table to save the memory

//      //when we end this function we will return to upper layer
//      //SymTabManager::getInstance().setnowtable("main");
//      return nullptr;
// }



 /**********************************************/
 // use the literal's eval
 /**********************************************/
 const Node* PrintNode::eval()
{
  if (PrNode) {
    for(auto it : *PrNode) {

      //std::cout << PrNode -> size() << std::endl;
      if(it)
        it -> eval() -> print();
    }
  }
  return nullptr;
}

/***************************************************************************/


 const Node* ReturnNode::eval(){
 	//dynamic_cast<FuncDefNode*>()
 	std::cout << "return node eval()"<< std::endl;
    return returnNode -> eval();
  }

 /***************************************************************************/

/***************************************************************************/


 const Node* IfNode::eval(){
  if(static_cast<const BoolLiteral*>(Tnode->eval())->getbool())
  {
    //std::cout<<"return if"<<typeid(Inode).name() <<std::endl;
    return Inode->eval();
  }
  else
  {
    if(Enode)
    {
      //std::cout<<"return else"<< std::endl;
      return Enode->eval();
    }
    else
    {
      //std::cout<<"return nothing"<< std::endl;
      return nullptr;
    }
  }
 }





