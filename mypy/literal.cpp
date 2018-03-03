#include "literal.h"

  const Literal* FloatLiteral::operator>(const Literal& rhs) const  {
    return rhs.opBig(val);
  }
   const Literal* FloatLiteral::opBig(long double lhs) const  {
    const Literal* node = new BoolLiteral(lhs>val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
   const Literal* FloatLiteral::opBig(int lhs) const  {
    const Literal* node = new BoolLiteral(lhs>val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

   const Literal* FloatLiteral::operator<(const Literal& rhs) const  {
    return rhs.opLes(val);
  }
   const Literal* FloatLiteral::opLes(long double lhs) const  {
    const Literal* node = new BoolLiteral(lhs<val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
   const Literal* FloatLiteral::opLes(int lhs) const  {
    const Literal* node = new BoolLiteral(lhs<val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

   const Literal* FloatLiteral::operator>=(const Literal& rhs) const  {
    return rhs.opBgEq(val);
  }
   const Literal* FloatLiteral::opBgEq(long double lhs) const  {
    const Literal* node = new BoolLiteral(lhs>=val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
   const Literal* FloatLiteral::opBgEq(int lhs) const  {
    const Literal* node = new BoolLiteral(lhs>=val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

   const Literal* FloatLiteral::operator<=(const Literal& rhs) const  {
    return rhs.opLeEq(val);
  }
   const Literal* FloatLiteral::opLeEq(long double lhs) const  {
    const Literal* node = new BoolLiteral(lhs<=val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
   const Literal* FloatLiteral::opLeEq(int lhs) const  {
    const Literal* node = new BoolLiteral(lhs<=val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
   const Literal* FloatLiteral::operator==(const Literal& rhs) const  {
    return rhs.opEqEq(val);
  }
   const Literal* FloatLiteral::opEqEq(long double lhs) const  {
    const Literal* node = new BoolLiteral(lhs==val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
   const Literal* FloatLiteral::opEqEq(int lhs) const  {
    const Literal* node = new BoolLiteral(lhs==val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }




   const Literal* IntLiteral::operator>(const Literal& rhs) const  {
    return rhs.opBig(val);
  }
   const Literal* IntLiteral::opBig(long double lhs) const  {
    const Literal* node = new BoolLiteral(lhs>val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
   const Literal* IntLiteral::opBig(int lhs) const  {
    const Literal* node = new BoolLiteral(lhs>val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

   const Literal* IntLiteral::operator<(const Literal& rhs) const  {
   	//std::cout<<"call rhs<int"<<std::endl;
    return rhs.opLes(val);
  }
   const Literal* IntLiteral::opLes(long double lhs) const  {
    const Literal* node = new BoolLiteral(lhs<val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
   const Literal* IntLiteral::opLes(int lhs) const  {
   	//std::cout<<"int<int"<<(lhs<val)<<std::endl;
    const Literal* node = new BoolLiteral(lhs<val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

   const Literal* IntLiteral::operator>=(const Literal& rhs) const  {
    return rhs.opBgEq(val);
  }
   const Literal* IntLiteral::opBgEq(long double lhs) const  {
    const Literal* node = new BoolLiteral(lhs>=val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
   const Literal* IntLiteral::opBgEq(int lhs) const  {
    const Literal* node = new BoolLiteral(lhs>=val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

   const Literal* IntLiteral::operator<=(const Literal& rhs) const  {
    return rhs.opLeEq(val);
  }
   const Literal* IntLiteral::opLeEq(long double lhs) const  {
    const Literal* node = new BoolLiteral(lhs<=val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
   const Literal* IntLiteral::opLeEq(int lhs) const  {
    const Literal* node = new BoolLiteral(lhs<=val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }


   const Literal* IntLiteral::operator==(const Literal& rhs) const  {
    return rhs.opEqEq(val);
  }
   const Literal* IntLiteral::opEqEq(long double lhs) const  {
    const Literal* node = new BoolLiteral(lhs==val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
   const Literal* IntLiteral::opEqEq(int lhs) const  {
    const Literal* node = new BoolLiteral(lhs==val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
