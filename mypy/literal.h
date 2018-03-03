#include "node.h"
#include <cmath>
#include "poolOfNodes.h"
#include <iomanip>
#include <sstream>
#include <string>

class Literal : public Node {
public:
  virtual ~Literal() {}

  virtual const Literal* power(const Literal& rhs) const =0;
  virtual const Literal* oppower(long double) const =0;
  virtual const Literal* oppower(int) const =0;


  virtual const Literal* operator+(const Literal& rhs) const =0;
  virtual const Literal* opPlus(long double) const =0;
  virtual const Literal* opPlus(int) const =0;

  virtual const Literal* operator*(const Literal& rhs) const =0;
  virtual const Literal* opMult(long double) const =0;
  virtual const Literal* opMult(int) const =0;

  virtual const Literal* operator-(const Literal& rhs) const =0;
  virtual const Literal* opSubt(long double) const =0;
  virtual const Literal* opSubt(int) const =0;

  virtual const Literal* operator/(const Literal& rhs) const =0;
  virtual const Literal* opDiv(long double) const =0;
  virtual const Literal* opDiv(int) const =0;

  virtual const Literal* operator%(const Literal& rhs) const =0;
  virtual const Literal* opPer(long double) const =0;
  virtual const Literal* opPer(int) const =0;


  virtual const Literal* DoubleSla(const Literal& rhs) const =0;
  virtual const Literal* opdoublesla(long double) const =0;
  virtual const Literal* opdoublesla(int) const =0;

  virtual const Literal* operator>>(const Literal& rhs) const =0;
  virtual const Literal* opRS(long double) const =0;
  virtual const Literal* opRS(int) const =0;

  virtual const Literal* operator<<(const Literal& rhs) const =0;
  virtual const Literal* opLS(long double) const =0;
  virtual const Literal* opLS(int) const =0;

  virtual const Literal* operator~() const =0;

  virtual const Literal* operator|(const Literal& rhs) const =0;
  virtual const Literal* opBar(long double) const =0;
  virtual const Literal* opBar(int) const =0;

  virtual const Literal* operator^(const Literal& rhs) const =0;
  virtual const Literal* opCir(long double) const =0;
  virtual const Literal* opCir(int) const =0;

  virtual const Literal* operator&(const Literal& rhs) const =0;
  virtual const Literal* opAmp(long double) const =0;
  virtual const Literal* opAmp(int) const =0;


  /*virtual const Literal* opCir(bool lhs) const;


  virtual const Literal* opAmp(bool lhs) const ;


  virtual const Literal* opBar(bool lhs) const;


  virtual const Literal* opRS(bool lhs) const ;


  virtual const Literal* opLS(bool lhs) const ;*/
/**********************************************
BiggerBinaryNode
LesserBinaryNode
BgEqBinaryNode
LsEqBinaryNode
EqEqBinaryNode
*********************************************/
  virtual const Literal* operator>(const Literal& rhs) const =0;
  virtual const Literal* opBig(long double) const =0;
  virtual const Literal* opBig(int) const =0;


  virtual const Literal* operator<(const Literal& rhs) const =0;
  virtual const Literal* opLes(long double) const =0;
  virtual const Literal* opLes(int) const =0;

  virtual const Literal* operator>=(const Literal& rhs) const =0;
  virtual const Literal* opBgEq(long double) const =0;
  virtual const Literal* opBgEq(int) const =0;


  virtual const Literal* operator<=(const Literal& rhs) const =0;
  virtual const Literal* opLeEq(long double) const =0;
  virtual const Literal* opLeEq(int) const =0;


  virtual const Literal* operator==(const Literal& rhs) const =0;
  virtual const Literal* opEqEq(long double) const =0;
  virtual const Literal* opEqEq(int) const =0;



  virtual  char gettype()const=0;

  virtual const Literal* eval() = 0;
  virtual void print() const { 
    std::cout << "No Way" << std::endl; 
  }
};



class FloatLiteral: public Literal {
public:
  FloatLiteral(long double _val): val(_val) {}

  virtual const Literal* power(const Literal& rhs) const  {
    return rhs.oppower(val);
  }
  virtual const Literal* oppower(long double lhs) const  {
    const Literal* node = new FloatLiteral(std::pow(lhs,val));
    PoolOfNodes::getInstance().add(node);
    return node; 
  }
  virtual const Literal* oppower(int lhs) const  {
    const Literal* node = new FloatLiteral(std::pow(lhs,val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator+(const Literal& rhs) const  {
    return rhs.opPlus(val);
  }
  virtual const Literal* opPlus(long double lhs) const  {
    const Literal* node = new FloatLiteral(lhs + val);
    PoolOfNodes::getInstance().add(node);
    return node; 
  }
  virtual const Literal* opPlus(int lhs) const  {
    const Literal* node = new FloatLiteral(lhs + val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator-(const Literal& rhs) const  {
    return rhs.opSubt(val);
  }
  virtual const Literal* opSubt(long double lhs) const  {
    const Literal* node = new FloatLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opSubt(int lhs) const  {
    const Literal* node = new FloatLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator*(const Literal& rhs) const  {
    return rhs.opMult(val);
  }
  virtual const Literal* opMult(long double lhs) const  {
    const Literal* node = new FloatLiteral(lhs * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opMult(int lhs) const  {
    const Literal* node = new FloatLiteral(static_cast<long double>(lhs) * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* DoubleSla(const Literal& rhs) const  {
    return rhs.opdoublesla(val);
  }
  virtual const Literal* opdoublesla(long double lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    auto funcrounddown= [=](long double lhs, long double val)->long double{
        long double x=0;
        if(( x=(lhs/val))<0){
          if(std::fmod(x,1.0)!=0){
            return ((int)(x-1));

          }
          else{
            return((int)x);

          }
        } 
        return((int)(lhs/val));
     };
    long double x=(funcrounddown(lhs , val));
    const Literal* node = new FloatLiteral(x);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opdoublesla(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    auto funcrounddown= [=](int lhs, long double  val)->long double{
        long double x=0;
        if(( x=(lhs/val))<0){
          if(std::fmod(x,1.0)!=0){
            return ((int)(x-1));

          }
          else{
            return((int)x);

          }
        } 
        //std::cout <<lhs<< val <<lhs/val<<" 9.5"<<(int)(9.5)<<std::endl;
        return((int)(lhs/val));

     };
     
    long double x=(funcrounddown(lhs , val));
    const Literal* node = new FloatLiteral(x);
    PoolOfNodes::getInstance().add(node);
    return node;
  }


  virtual const Literal* operator/(const Literal& rhs) const  {
    return rhs.opDiv(val);
  }
  virtual const Literal* opDiv(long double lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(lhs / val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opDiv(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(lhs / val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator%(const Literal& rhs) const  {
    return rhs.opPer(val);
  }
  virtual const Literal* opPer(long double lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(std::fmod((std::fmod(lhs , val)+val),val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opPer(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(std::fmod((std::fmod(lhs , val)+val),val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }


  virtual const Literal* operator <<(const Literal& rhs) const  {
    return rhs.opLS(val);
  }
  virtual const Literal* opLS(long double ) const  {
    std::cout<<"TypeError: unsupported operand type(s) for <<: \'float\' and \'float\'"<<std::endl;
    return nullptr;
  }
 
  virtual const Literal* opLS(int ) const  {
    std::cout<<"TypeError: unsupported operand type(s) for <<: \'int\' and \'float\'"<<std::endl;
    return nullptr;
  }


  virtual const Literal* operator >>(const Literal& rhs) const  {
    return rhs.opRS(val);
  }
  virtual const Literal* opRS(long double ) const  {
    std::cout<<"TypeError: unsupported operand type(s) for >>: \'float\' and \'float\'"<<std::endl;
    return nullptr;
  }
 
  virtual const Literal* opRS(int ) const  {
    std::cout<<"TypeError: unsupported operand type(s) for >>: \'int\' and \'float\'"<<std::endl;
    return nullptr;
  }
  virtual const Literal* operator ~() const  {
    std::cout<<"TypeError: bad operand type for unary ~: 'float'"<<std::endl;
    return nullptr;
  }


  virtual const Literal* operator |(const Literal& rhs) const  {
    return rhs.opBar(val);
  }
  virtual const Literal* opBar(long double ) const  {
    std::cout<<"TypeError: unsupported operand type(s) for |: \'float\' and \'float\'"<<std::endl;
    return nullptr;
  }

  virtual const Literal* opBar(int ) const  {
    std::cout<<"TypeError: unsupported operand type(s) for |: \'int\' and \'float\'"<<std::endl;
    return nullptr;
  }
   

  virtual const Literal* operator &(const Literal& rhs) const  {
    return rhs.opAmp(val);
  }
  virtual const Literal* opAmp(long double ) const  {
    std::cout<<"TypeError: unsupported operand type(s) for &: \'float\' and \'float\'"<<std::endl;
    return nullptr;
  }

  virtual const Literal* opAmp(int ) const  {
    std::cout<<"TypeError: unsupported operand type(s) for &: \'int\' and \'float\'"<<std::endl;
    return nullptr;
  }


    virtual const Literal* operator ^(const Literal& rhs) const  {
    return rhs.opCir(val);
  }
  virtual const Literal* opCir(long double ) const  {
    std::cout<<"TypeError: unsupported operand type(s) for ^: \'float\' and \'float\'"<<std::endl;
    return nullptr;
  }

  virtual const Literal* opCir(int ) const  {
    std::cout<<"TypeError: unsupported operand type(s) for ^: \'int\' and \'float\'"<<std::endl;
    return nullptr;
  }
    /*virtual const Literal* opCir(bool lhs) const  {
    std::cout<<"TypeError: unsupported operand type(s) for ^: \'bool\' and \'float\'"<<std::endl;
    return nullptr;
  }


  virtual const Literal* opAmp(bool lhs) const  {
    std::cout<<"TypeError: unsupported operand type(s) for &: \'bool\' and \'float\'"<<std::endl;
    return nullptr;
  }

  virtual const Literal* opBar(bool lhs) const  {
    std::cout<<"TypeError: unsupported operand type(s) for |: \'bool\' and \'float\'"<<std::endl;
    return nullptr;
  }

  virtual const Literal* opRS(bool lhs) const  {
    std::cout<<"TypeError: unsupported operand type(s) for >>: \'bool\' and \'float\'"<<std::endl;
    return nullptr;
  }

  virtual const Literal* opLS(bool lhs) const  {
    std::cout<<"TypeError: unsupported operand type(s) for <<: \'bool\' and \'float\'"<<std::endl;
    return nullptr;
  }*/


 /*virtual const Literal* opLS(bool lhs,bool lhs1) const  {
    std::cout<<"TypeError: unsupported operand type(s) for <<: \'bool\' and \'float\'"<<std::endl;
    return nullptr;
  }
  virtual const Literal* opRS(bool lhs,bool lhs1) const  {
    std::cout<<"TypeError: unsupported operand type(s) for >>: \'bool\' and \'float\'"<<std::endl;
    return nullptr;
  }

  virtual const Literal* opBar(bool lhs,bool lhs1) const  {
    std::cout<<"TypeError: unsupported operand type(s) for |: \'bool\' and \'float\'"<<std::endl;
    return nullptr;
  }
  virtual const Literal* opAmp(bool lhs,bool lhs1) const  {
    std::cout<<"TypeError: unsupported operand type(s) for &: \'bool\' and \'float\'"<<std::endl;
    return nullptr;
  }
  virtual const Literal* opCir(bool lhs,bool lhs1) const  {
    std::cout<<"TypeError: unsupported operand type(s) for ^: \'bool\' and \'float\'"<<std::endl;
    return nullptr;
  }*/
  virtual const Literal* operator>(const Literal& rhs) const ;
  virtual const Literal* opBig(long double) const ;
  virtual const Literal* opBig(int) const ;


  virtual const Literal* operator<(const Literal& rhs) const ;
  virtual const Literal* opLes(long double) const ;
  virtual const Literal* opLes(int) const ;

  virtual const Literal* operator>=(const Literal& rhs) const ;
  virtual const Literal* opBgEq(long double) const ;
  virtual const Literal* opBgEq(int) const ;


  virtual const Literal* operator<=(const Literal& rhs) const ;
  virtual const Literal* opLeEq(long double) const ;
  virtual const Literal* opLeEq(int) const ;


  virtual const Literal* operator==(const Literal& rhs) const ;
  virtual const Literal* opEqEq(long double) const ;
  virtual const Literal* opEqEq(int) const ;


  /*virtual const Literal* operator>(const Literal& rhs) const  {
    return rhs.opBig(val);
  }
  virtual const Literal* opBig(long double lhs) const  {
    const Literal* node = new BoolLiteral(lhs>val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opBig(int lhs) const  {
    const Literal* node = new BoolLiteral(lhs>val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator<(const Literal& rhs) const  {
    return rhs.opBig(val);
  }
  virtual const Literal* opLes(long double lhs) const  {
    const Literal* node = new BoolLiteral(lhs<val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opLes(int lhs) const  {
    const Literal* node = new BoolLiteral(lhs<val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator>=(const Literal& rhs) const  {
    return rhs.opBig(val);
  }
  virtual const Literal* opBgEq(long double lhs) const  {
    const Literal* node = new BoolLiteral(lhs>=val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opBgEq(int lhs) const  {
    const Literal* node = new BoolLiteral(lhs>=val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator<=(const Literal& rhs) const  {
    return rhs.opBig(val);
  }
  virtual const Literal* opLeEq(long double lhs) const  {
    const Literal* node = new BoolLiteral(lhs<=val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opLeEq(int lhs) const  {
    const Literal* node = new BoolLiteral(lhs<=val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }


  virtual const Literal* operator==(const Literal& rhs) const  {
    return rhs.opBig(val);
  }
  virtual const Literal* opEqEq(long double lhs) const  {
    const Literal* node = new BoolLiteral(lhs>val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opEqEq(int lhs) const  {
    const Literal* node = new BoolLiteral(lhs>val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }*/



  virtual const Literal* eval() { return this; }
  virtual void print() const { 
    //std::cout /*<< "FLOAT: " <<setiosflags(std::ios::fixed)<<std::setw(16)*/<< std::setprecision(15)<<val; 
    //if (std::fmod(val,1.0)<0.0000000000000001){std::cout/*<<setiosflags(std::ios::fixed)*/<<std::setw(2)<<val;}
    //else std::cout /*<< resetiosflags(std::ios::fixed)<*/<<std::setprecision(15)<<val;
    std::stringstream out;
    std::string fstr;
    out<<std::setprecision(12)<<val;
    fstr=out.str();
    std::cout<< std::setprecision(12)<<val;
    //std::cout<<fstr;
    //std::string x="89986.97114489987";
    //std::cout<<"  find . "<<(int)fstr.find('.')<<std::endl;
    if(((int)fstr.find('.'))==-1)
      std::cout<<".0";
    std::cout<< std::endl;
  }

char gettype()const {return 'f';}
private:
  long double val;
};








class IntLiteral: public Literal {
public:
 IntLiteral(int _val): val(_val) {}

  virtual const Literal* power(const Literal& rhs) const  {
    return rhs.oppower(val);
  }
  virtual const Literal* oppower(long double lhs) const  {
    const Literal* node = new FloatLiteral(std::pow(lhs, static_cast<long double>(val)));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* oppower(int lhs) const  {
    const Literal* node = new IntLiteral(static_cast<int>(std::pow(lhs, val)));
    PoolOfNodes::getInstance().add(node);
    return node;
  }


  virtual const Literal* operator+(const Literal& rhs) const  {
    return rhs.opPlus(val);
  }
  virtual const Literal* opPlus(long double lhs) const  {
    const Literal* node = new FloatLiteral(static_cast<long double>(val) + lhs);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opPlus(int lhs) const  {
    const Literal* node = new IntLiteral(lhs + val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator-(const Literal& rhs) const  {
    return rhs.opSubt(val);
  }
  virtual const Literal* opSubt(long double lhs) const  {
    const Literal* node = new FloatLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opSubt(int lhs) const  {
    const Literal* node = new IntLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator*(const Literal& rhs) const  {
    return rhs.opMult(val);
  }
  virtual const Literal* opMult(long double lhs) const  {
    const Literal* node = new FloatLiteral(lhs * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opMult(int lhs) const  {
    const Literal* node = new IntLiteral(lhs * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }


  virtual const Literal* DoubleSla(const Literal& rhs) const  {
    return rhs.opdoublesla(val);
  }
  virtual const Literal* opdoublesla(long double lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
      auto funcrounddown= [=](long double lhs, int val)->long double{
        long double x;
        if(( x=(lhs/val))<0){
          if(std::fmod(x,1.0)!=0){
            return ((int)(x-1));

          }
          else{
            return((int)x);

          }
        } 
        return((int)(lhs/val));
     };
    
    const Literal* node = new FloatLiteral(1.0*funcrounddown(lhs,val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opdoublesla(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
 
      auto funcrounddown= [=](int lhs, int val)->int{
        long double x;
        if(( x=(lhs/(long double)val))<0){
          if(std::fmod(x,1.0)!=0){
            return ((int)(x-1));

          }
          else{
            return((int)x);

          }
        } 
        return((int)(lhs/val));
     };
    const Literal* node = new IntLiteral((int)funcrounddown(lhs,val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }


  virtual const Literal* operator/(const Literal& rhs) const  {
    return rhs.opDiv(val);
  }
  virtual const Literal* opDiv(long double lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(lhs / val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opDiv(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
     auto funcrounddown= [=](int lhs, int val)->int{
        long double x;
        if(( x=(lhs/(long double)val))<0){
          if(std::fmod(x,1.0)!=0){
            return ((int)(x-1));

          }
          else{
            return((int)x);

          }
        } 
        return(lhs/val);
     };
    
    const Literal* node = new IntLiteral(funcrounddown(lhs,val));

    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator%(const Literal& rhs) const  {
    return rhs.opPer(val);
  }
  virtual const Literal* opPer(long double lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(std::fmod((std::fmod(lhs , val)+val),val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opPer(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new IntLiteral((lhs % val+val)%val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator <<(const Literal& rhs) const  {
    return rhs.opLS(val);
  }
  virtual const Literal* opLS(long double ) const  {
    std::cout<<"TypeError: unsupported operand type(s) for <<: \'float\' and \'int\'"<<std::endl;
    return nullptr;
  }
  virtual const Literal* opLS(int lhs) const  {
    if(val>0){
    const Literal* node = new IntLiteral(lhs << val);
    PoolOfNodes::getInstance().add(node);
    return node;}
    else{
      std::cout<<"ValueError: negative shift count"<<std::endl;
      return nullptr;
    }
  }

  virtual const Literal* operator >>(const Literal& rhs) const  {
    return rhs.opRS(val);
  }
  virtual const Literal* opRS(long double ) const  {
    std::cout<<"TypeError: unsupported operand type(s) for >>: \'float\' and \'int\'"<<std::endl;
    return nullptr;
  }
  virtual const Literal* opRS(int lhs) const  {
    if(val>0){
    const Literal* node = new IntLiteral(lhs >> val);
    PoolOfNodes::getInstance().add(node);
    return node;}
    else{
      std::cout<<"ValueError: negative shift count"<<std::endl;
      return nullptr;
    }
    
  }

  virtual const Literal* operator ~() const  {
    const Literal* node = new IntLiteral(~val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }


  virtual const Literal* operator |(const Literal& rhs) const  {
    return rhs.opBar(val);
  }
  virtual const Literal* opBar(long double ) const  {
    std::cout<<"TypeError: unsupported operand type(s) for <|: \'float\' and \'int\'"<<std::endl;
    return nullptr;
  }
  virtual const Literal* opBar(int lhs) const  {
    //std::cout<<lhs<<"|"<<val<<std::endl;
    const Literal* node = new IntLiteral(lhs | val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator &(const Literal& rhs) const  {
    return rhs.opAmp(val);
  }
  virtual const Literal* opAmp(long double ) const  {
    std::cout<<"TypeError: unsupported operand type(s) for &: \'float\' and \'int\'"<<std::endl;
    return nullptr;
  }
  virtual const Literal* opAmp(int lhs) const  {
    //std::cout<<lhs<<"&"<<val<<std::endl;

    const Literal* node = new IntLiteral(lhs & val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

    virtual const Literal* operator ^(const Literal& rhs) const  {
    return rhs.opCir(val);
  }
  virtual const Literal* opCir(long double ) const  {
    std::cout<<"TypeError: unsupported operand type(s) for ^: \'float\' and \'int\'"<<std::endl;
    return nullptr;
  }
  virtual const Literal* opCir(int lhs) const  {

    //std::cout<<lhs<<"^"<<val<<std::endl;
    const Literal* node = new IntLiteral(lhs ^ val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator>(const Literal& rhs) const ;
  virtual const Literal* opBig(long double) const ;
  virtual const Literal* opBig(int) const ;


  virtual const Literal* operator<(const Literal& rhs) const ;
  virtual const Literal* opLes(long double) const ;
  virtual const Literal* opLes(int) const ;

  virtual const Literal* operator>=(const Literal& rhs) const ;
  virtual const Literal* opBgEq(long double) const ;
  virtual const Literal* opBgEq(int) const ;


  virtual const Literal* operator<=(const Literal& rhs) const ;
  virtual const Literal* opLeEq(long double) const ;
  virtual const Literal* opLeEq(int) const ;


  virtual const Literal* operator==(const Literal& rhs) const ;
  virtual const Literal* opEqEq(long double) const ;
  virtual const Literal* opEqEq(int) const ;


 /* virtual const Literal* operator>(const Literal& rhs) const  {
    return rhs.opBig(val);
  }
  virtual const Literal* opBig(long double lhs) const  {
    const Literal* node = new BoolLiteral(lhs>val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opBig(int lhs) const  {
    const Literal* node = new BoolLiteral(lhs>val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator<(const Literal& rhs) const  {
    return rhs.opBig(val);
  }
  virtual const Literal* opLes(long double lhs) const  {
    const Literal* node = new BoolLiteral(lhs<val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opLes(int lhs) const  {
    const Literal* node = new BoolLiteral(lhs<val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator>=(const Literal& rhs) const  {
    return rhs.opBig(val);
  }
  virtual const Literal* opBgEq(long double lhs) const  {
    const Literal* node = new BoolLiteral(lhs>=val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opBgEq(int lhs) const  {
    const Literal* node = new BoolLiteral(lhs>=val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator<=(const Literal& rhs) const  {
    return rhs.opBig(val);
  }
  virtual const Literal* opLeEq(long double lhs) const  {
    const Literal* node = new BoolLiteral(lhs<=val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opLeEq(int lhs) const  {
    const Literal* node = new BoolLiteral(lhs<=val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }


  virtual const Literal* operator==(const Literal& rhs) const  {
    return rhs.opBig(val);
  }
  virtual const Literal* opEqEq(long double lhs) const  {
    const Literal* node = new BoolLiteral(lhs>val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opEqEq(int lhs) const  {
    const Literal* node = new BoolLiteral(lhs>val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }*/




  virtual const Literal* eval() { return this; }
  virtual void print() const { 
    std::cout /*<< "INT: "*/ << val << std::endl;
  }

  int getval()const {return val;}
  char gettype()const{return 'i';}

protected:
  int val;
};



class BoolLiteral: public IntLiteral {
public:
  BoolLiteral(bool _val): IntLiteral(_val){}
  virtual const Literal* eval() { return this; }



  virtual char gettype()const{return 'b';}

  virtual const Literal* operator ^(const Literal& rhs) const  {
    //std::cout<<"this is bool"<<std::endl;
    /*if(rhs.gettype()=='f')
    return rhs.opCir((bool)val,(bool)val);//since in c++ bool and int type can't be seperate by the compiler so we have to do this
    else */
    return rhs.opCir((bool)val);

  }
  virtual const Literal* opCir(long double ) const  {
    std::cout<<"TypeError: unsupported operand type(s) for ^: \'float\' and \'bool\'"<<std::endl;
    return nullptr;
  }

  virtual const Literal* operator &(const Literal& rhs) const  {
    /*std::cout<<"this is bool"<<std::endl;
    if(rhs.gettype()=='f')
    return rhs.opAmp((bool)val,(bool)val);
    else*/
    return rhs.opAmp((bool)val);
  }
  virtual const Literal* opAmp(long double ) const  {
    std::cout<<"TypeError: unsupported operand type(s) for &: \'float\' and \'bool\'"<<std::endl;
    return nullptr;
  }


  virtual const Literal* operator |(const Literal& rhs) const  {
    /*std::cout<<"this is bool"<<std::endl;
    if(rhs.gettype()=='f')
    return rhs.opBar((bool)val,(bool)val);
    else*/
    return rhs.opBar((bool)val); 
  }
  virtual const Literal* opBar(long double) const  {
    std::cout<<"TypeError: unsupported operand type(s) for |: \'float\' and \'bool\'"<<std::endl;
    return nullptr;
  }

  virtual const Literal* operator >>(const Literal& rhs) const  {
    /*std::cout<<"this is bool"<<std::endl;
    if(rhs.gettype()=='f')
    return rhs.opRS((bool)(val),(bool)val);
    else*/
    return rhs.opRS((bool)(val));
  }
    virtual const Literal* opRS(long double ) const  {
    std::cout<<"TypeError: unsupported operand type(s) for >>: \'float\' and \'bool\'"<<std::endl;
    return nullptr;
  }

  virtual const Literal* operator <<(const Literal& rhs) const  {
    /*std::cout<<"this is bool"<<std::endl;
    if(rhs.gettype()=='f')
    return rhs.opLS((bool)val,(bool)val);
    else*/
    return rhs.opLS((bool)val);
  }
    virtual const Literal* opLS(long double ) const  {
    std::cout<<"TypeError: unsupported operand type(s) for <<: \'float\' and \'bool\'"<<std::endl;
    return nullptr;
  }
    bool getbool()const{return (bool)val;}
    
    virtual void print() const { 
    if (IntLiteral::getval())
      std::cout << "True"<< std::endl;
    else
      std::cout << "False"<< std::endl;
    }
  //private:
   //bool val;



};

/****************************************************************************/
//just functions in this node
/****************************************************************************/
class NONELiteral : public Literal {
public:
  NONELiteral(){}
  virtual ~NONELiteral(){}

  virtual const Literal* power(const Literal& ) const {return nullptr;}
  virtual const Literal* oppower(long double) const {return nullptr;}
  virtual const Literal* oppower(int) const {return nullptr;}


  virtual const Literal* operator+(const Literal& ) const {return nullptr;}
  virtual const Literal* opPlus(long double) const {return nullptr;}
  virtual const Literal* opPlus(int) const {return nullptr;}

  virtual const Literal* operator*(const Literal& ) const {return nullptr;}
  virtual const Literal* opMult(long double) const {return nullptr;}
  virtual const Literal* opMult(int) const {return nullptr;}

  virtual const Literal* operator-(const Literal& ) const {return nullptr;}
  virtual const Literal* opSubt(long double) const {return nullptr;}
  virtual const Literal* opSubt(int) const {return nullptr;}

  virtual const Literal* operator/(const Literal& ) const {return nullptr;}
  virtual const Literal* opDiv(long double) const {return nullptr;}
  virtual const Literal* opDiv(int) const {return nullptr;}

  virtual const Literal* operator%(const Literal& ) const {return nullptr;}
  virtual const Literal* opPer(long double) const {return nullptr;}
  virtual const Literal* opPer(int) const {return nullptr;}


  virtual const Literal* DoubleSla(const Literal& ) const {return nullptr;}
  virtual const Literal* opdoublesla(long double) const {return nullptr;}
  virtual const Literal* opdoublesla(int) const {return nullptr;}

  virtual const Literal* operator>>(const Literal& ) const {return nullptr;}
  virtual const Literal* opRS(long double) const {return nullptr;}
  virtual const Literal* opRS(int) const {return nullptr;}

  virtual const Literal* operator<<(const Literal& ) const {return nullptr;}
  virtual const Literal* opLS(long double) const {return nullptr;}
  virtual const Literal* opLS(int) const {return nullptr;}

  virtual const Literal* operator~() const {return nullptr;}

  virtual const Literal* operator|(const Literal& ) const {return nullptr;}
  virtual const Literal* opBar(long double) const {return nullptr;}
  virtual const Literal* opBar(int) const {return nullptr;}

  virtual const Literal* operator^(const Literal& ) const {return nullptr;}
  virtual const Literal* opCir(long double) const {return nullptr;}
  virtual const Literal* opCir(int) const {return nullptr;}

  virtual const Literal* operator&(const Literal& ) const {return nullptr;}
  virtual const Literal* opAmp(long double) const {return nullptr;}
  virtual const Literal* opAmp(int) const {return nullptr;}


  virtual const Literal* operator>(const Literal& ) const {return nullptr;}
  virtual const Literal* opBig(long double) const {return nullptr;}
  virtual const Literal* opBig(int) const {return nullptr;}


  virtual const Literal* operator<(const Literal& ) const {return nullptr;}
  virtual const Literal* opLes(long double) const {return nullptr;}
  virtual const Literal* opLes(int) const {return nullptr;}

  virtual const Literal* operator>=(const Literal& ) const {return nullptr;}
  virtual const Literal* opBgEq(long double) const {return nullptr;}
  virtual const Literal* opBgEq(int) const {return nullptr;}


  virtual const Literal* operator<=(const Literal& ) const {return nullptr;}
  virtual const Literal* opLeEq(long double) const {return nullptr;}
  virtual const Literal* opLeEq(int) const {return nullptr;}


  virtual const Literal* operator==(const Literal& ) const {return nullptr;}
  virtual const Literal* opEqEq(long double) const {return nullptr;}
  virtual const Literal* opEqEq(int) const {return nullptr;}



  virtual  char gettype()const{return 'N';};

  virtual const Literal* eval(){return  this;}

  virtual void print() const { 
    std::cout << "No Way" << std::endl; 
  }
};
