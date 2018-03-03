// Generated by transforming |cwd:///work-in-progress/2.7.2-bisonified.y| on 2016-11-23 at 15:46:56 +0000
%{
      #include <iostream>
      #include <string>
      #include <map>
      #include <cmath>
      #include <cstring>
      #include "ast.h"
      #include "SymTabManager.h"
	
	extern int yylex (void);
	extern char *yytext;
	void yyerror (const char *);
	

       PoolOfNodes& pool = PoolOfNodes::getInstance();
	//Node* currentsuite;
	//Node* mainsuite;
  SymTabManager& stm = SymTabManager::getInstance();

%}

%union {
  Node* node;
  int intNumber;
  long double fltNumber;
  char *id;
  std::vector<Node*>* vectorNode;
}

// 83 tokens, in alphabetical order:
%token  AMPERSAND AND AS ASSERT AT BACKQUOTE BAR BREAK CIRCUMFLEX
%token  CLASS COLON COMMA CONTINUE DEDENT DEF DEL DOT 
%token  DOUBLESTAR  ELIF ELSE ENDMARKER
%token EQUAL EXCEPT EXEC FINALLY FOR FROM GLOBAL   
%token IF IMPORT  INDENT  LAMBDA LBRACE   
%token LPAR LSQB  NEWLINE NOT NUMBER
%token OR PASS   PRINT RAISE RBRACE RETURN
%token   RPAR RSQB SEMI    
%token STRING  TRY  WHILE WITH YIELD


%type<node>  expr_stmt small_stmt print_stmt 

%type<node> test testlist exprlist 
%type<node> atom power factor term arith_expr shift_expr and_expr xor_expr expr comparison not_test and_test or_test opt_IF_ELSE 

%type<node> star_EQUAL star_EQUAL_R

%type<node> opt_yield_test pick_yield_expr_testlist_comp  yield_expr testlist_comp
%type<node> pick_yield_expr_testlist
%type<node> star_SEMI_small_stmt simple_stmt stmt compound_stmt suite pick_NEWLINE_stmt star_NEWLINE_stmt funcdef  file_input return_stmt flow_stmt if_stmt
%type<vectorNode> plus_stmt opt_test star_COMMA_test 

%type<intNumber> pick_unop pick_multop pick_PLUS_MINUS augassign comp_op pick_LEFTSHIFT_RIGHTSHIFT   star_trailer trailer

%token<intNumber>  MINUS PLUS TILDE       STAR SLASH PERCENT DOUBLESLASH     LEFTSHIFT  RIGHTSHIFT       

%token<intNumber>  PLUSEQUAL MINEQUAL STAREQUAL SLASHEQUAL PERCENTEQUAL AMPEREQUAL  GRLT GREATEREQUAL LESSEQUAL NOTEQUAL EQEQUAL LESS GREATER IS IN
%token<intNumber> VBAREQUAL CIRCUMFLEXEQUAL LEFTSHIFTEQUAL RIGHTSHIFTEQUAL DOUBLESTAREQUAL DOUBLESLASHEQUAL 

%token<id> NAME
%token<intNumber> INT
%token<fltNumber> FLOAT




%start start

%locations

%%

start
	: file_input
	{
	  //$1->eval();
	}
	;
file_input // Used in: start
	: star_NEWLINE_stmt ENDMARKER
	{
    // SHALL NOT DO ANYTHING!!!
	}
	;
pick_NEWLINE_stmt // Used in: star_NEWLINE_stmt
	: NEWLINE {$$=nullptr;//std::cout<< "the newline"<<std::endl;}
}
	| stmt
    {
      //std::cout<< "the eval()"<<std::endl;
      $1->eval();
      //catch(std::string str)
        // { std::cout<< <<std::endl;}
    }
	;
star_NEWLINE_stmt // Used in: file_input, star_NEWLINE_stmt
	: star_NEWLINE_stmt pick_NEWLINE_stmt 
	{ //if ($2!=nullptr)
	  //(*(dynamic_cast<SuiteNode*>(mainsuite)->returnASTTab())).push_back($2);
	  {$$=$2;}
	}
	| %empty {$$=nullptr;}
	;
decorator // Used in: decorators
	: AT dotted_name LPAR opt_arglist RPAR NEWLINE
	| AT dotted_name NEWLINE
	;
opt_arglist // Used in: decorator, trailer
	: arglist
	| %empty
	;
decorators // Used in: decorators, decorated
	: decorators decorator
	| decorator
	;
decorated // Used in: compound_stmt
	: decorators classdef
	| decorators funcdef
	;
funcdef // Used in: decorated, compound_stmt
	: DEF NAME parameters COLON suite
	{
          $$=new FuncDefNode($2,dynamic_cast<SuiteNode*>($5));
          pool.add($$);
          delete [] $2;
	  //std::cout<<"in parse.y function ast build"<<std::endl;
	  
	  //add parameter into symboltable {std::cout<<"function ast build start"<<std::endl;} 
	  // funcNode astpointer point at ast of suit ast;{suit will call symboltable creat the symboltable.} 
	  //funcNode symboltable pointer point at symboltable manager  
	}
	;
parameters // Used in: funcdef
	: LPAR varargslist RPAR
	| LPAR RPAR
	;
varargslist // Used in: parameters, old_lambdef, lambdef
	: star_fpdef_COMMA pick_STAR_DOUBLESTAR
	| star_fpdef_COMMA fpdef opt_EQUAL_test opt_COMMA
	;
opt_EQUAL_test // Used in: varargslist, star_fpdef_COMMA
	: EQUAL test
	| %empty
	;
star_fpdef_COMMA // Used in: varargslist, star_fpdef_COMMA
	: star_fpdef_COMMA fpdef opt_EQUAL_test COMMA
	| %empty
	;
opt_DOUBLESTAR_NAME // Used in: pick_STAR_DOUBLESTAR
	: COMMA DOUBLESTAR NAME
	| %empty
	;
pick_STAR_DOUBLESTAR // Used in: varargslist
	: STAR NAME opt_DOUBLESTAR_NAME
	| DOUBLESTAR NAME
	;
opt_COMMA // Used in: varargslist, opt_test, opt_test_2, testlist_safe, listmaker, testlist_comp, pick_for_test_test, pick_for_test, pick_argument
	: COMMA
	| %empty
	;
fpdef // Used in: varargslist, star_fpdef_COMMA, fplist, star_fpdef_notest
	: NAME
	| LPAR fplist RPAR
	;
fplist // Used in: fpdef
	: fpdef star_fpdef_notest COMMA
	| fpdef star_fpdef_notest
	;
star_fpdef_notest // Used in: fplist, star_fpdef_notest
	: star_fpdef_notest COMMA fpdef
	| %empty
	;
stmt // Used in: pick_NEWLINE_stmt, plus_stmt
	: simple_stmt{$$=$1;}
	| compound_stmt{$$=$1;}
	;
simple_stmt // Used in: stmt, suite
	: small_stmt star_SEMI_small_stmt SEMI NEWLINE
          {
           $$=$1;

          }
	| small_stmt star_SEMI_small_stmt NEWLINE
	  {$$=$1;

          }
	;
star_SEMI_small_stmt // Used in: simple_stmt, star_SEMI_small_stmt
	: star_SEMI_small_stmt SEMI small_stmt
	{$$=$3;}
	| %empty{$$=nullptr;}
	;
small_stmt // Used in: simple_stmt, star_SEMI_small_stmt
	: expr_stmt{$$=$1;}
	| print_stmt{$$=$1;}
	| del_stmt{$$=nullptr;}
	| pass_stmt{$$=nullptr;}
	| flow_stmt{$$=$1;}
	| import_stmt{$$=nullptr;}
	| global_stmt{$$=nullptr;}
	| exec_stmt{$$=nullptr;}
	| assert_stmt{$$=nullptr;}
	;
expr_stmt // Used in: small_stmt
	: testlist augassign pick_yield_expr_testlist
        {// do augassign to $1.
            //int x=$2;
	    switch($2)
		{
                  case(PLUSEQUAL):   
				  {Node* temp = new AddBinaryNode($1, $3);pool.add(temp);$$=new AsgBinaryNode($1, temp); pool.add($$); } 
                    break;//$1 is a variable check if it was declared.

                  case(MINEQUAL): 
{Node* temp = new SubBinaryNode($1, $3);  pool.add(temp);$$=new AsgBinaryNode($1, temp); pool.add($$);} 
                    break;
                  case(STAREQUAL):   
{Node* temp = new MulBinaryNode($1, $3);  pool.add(temp);$$=new AsgBinaryNode($1, temp); pool.add($$);} 
                    break;
                  case(SLASHEQUAL): 
{Node* temp = new DivBinaryNode($1, $3);  pool.add(temp);$$=new AsgBinaryNode($1, temp); pool.add($$);} 
                    break;
                  case(PERCENTEQUAL):
{Node* temp = new PercentBinaryNode($1, $3); pool.add(temp);$$=new AsgBinaryNode($1, temp); pool.add($$);} 
                    break;
                  case(AMPEREQUAL):
{Node* temp= new AMPERSANDNode($1, $3); pool.add(temp);$$=new AsgBinaryNode($1, temp); pool.add($$);}   
                    break;
                  case(VBAREQUAL):
{Node* temp= new BarNode($1, $3); pool.add(temp);$1=new AsgBinaryNode($1, temp); pool.add($$);}   
                    break;
                  case(CIRCUMFLEXEQUAL): 
{Node* temp= new CIRCUMFLEXNode($1, $3); pool.add(temp);$$=new AsgBinaryNode($1, temp); pool.add($$);}   
                    break;
                  case(LEFTSHIFTEQUAL):  
{Node* temp= new LeftShiftNode($1, $3); pool.add(temp);$$=new AsgBinaryNode($1, temp); pool.add($$);}   
                    break;
                  case(RIGHTSHIFTEQUAL): 
{Node* temp= new RightShiftNode($1, $3); pool.add(temp);$$=new AsgBinaryNode($1, temp); pool.add($$);} 
                    break;
                  case(DOUBLESTAREQUAL): 
{Node* temp= new PowerBinaryNode($1, $3);pool.add(temp);$$=new AsgBinaryNode($1, temp); pool.add($$);} 
                    break; 
                  case(DOUBLESLASHEQUAL):
{Node* temp = new DoubleSlaBinaryNode($1, $3);pool.add(temp);$$=new AsgBinaryNode($1, temp); pool.add($$);} 
                    break;
		
		  default:break;
		}

          }  
	| testlist star_EQUAL
          { // assign the value for left testlist
            if ($2!=nullptr)         
            {
             $$= new AsgBinaryNode($1, $2);
             //($1)->eval()->print();
             pool.add($$);}
            else
            {$$=$1;//if($1){($1)->eval()->print();}
            //else{std::cout<<"NameError: name \'"<<dynamic_cast<IdentNode*>$1->getIdent()<<"\' is not defined"<<std::endl; }
			}
          }
	;


pick_yield_expr_testlist // Used in: expr_stmt, star_EQUAL
	: yield_expr
	| testlist{$$=$1;}
	;
star_EQUAL // Used in: expr_stmt, star_EQUAL
	:star_EQUAL_R
         {
           /* //Node* lhs = new IdentNode($1); 
            if($1==NULL)
                { $$=$3;}
            else
            {   
            const_cast<Node*>(dynamic_cast<AsgBinaryNode*>($1)->getRight())=new AsgBinaryNode(const_cast<Node*>(dynamic_cast<AsgBinaryNode*>($1)->getRight()), $3);
            $$=$1;
            }*/
      $$=$1;
          }

	;
star_EQUAL_R
        : EQUAL pick_yield_expr_testlist star_EQUAL_R
	{
          if($3!=nullptr)
		{$$=new AsgBinaryNode($2, $3);
                pool.add($$);}
	  else
            $$=$2;
	}
        | %empty
         {$$=nullptr;
	 }
        ;

augassign // Used in: expr_stmt
	: PLUSEQUAL{$$=PLUSEQUAL;}
	| MINEQUAL{$$=MINEQUAL;}
	| STAREQUAL{$$=STAREQUAL;}
	| SLASHEQUAL{$$=SLASHEQUAL;}
	| PERCENTEQUAL{$$=PERCENTEQUAL;}
	| AMPEREQUAL{$$=AMPEREQUAL;}
	| VBAREQUAL{$$=VBAREQUAL;}
	| CIRCUMFLEXEQUAL{$$=CIRCUMFLEXEQUAL;}
	| LEFTSHIFTEQUAL{$$=LEFTSHIFTEQUAL;}
	| RIGHTSHIFTEQUAL{$$=RIGHTSHIFTEQUAL;}
	| DOUBLESTAREQUAL{$$=DOUBLESTAREQUAL;}
	| DOUBLESLASHEQUAL{$$=DOUBLESLASHEQUAL;}
	;
print_stmt // Used in: small_stmt
	: PRINT opt_test
	{//$$=$2;//$2->eval()->print();
	  $$=new PrintNode($2);
          pool.add($$);
	}
	| PRINT RIGHTSHIFT test opt_test_2{ $$=nullptr;}
	;
star_COMMA_test // Used in: star_COMMA_test, opt_test, listmaker, testlist_comp, testlist, pick_for_test
	: star_COMMA_test COMMA test
    {
      if($1) {
        $1 -> push_back($3);
      }
      else {
        $$ = new std::vector<Node*>();
        $$ -> push_back($3);
      }
    }
	| %empty{$$=nullptr;}
	;
opt_test // Used in: print_stmt
	: test star_COMMA_test opt_COMMA
    {
      if($2) {
        $2 -> insert($2->begin(), $1);
        $$ = $2;
      }
      else {
        $$ = new std::vector<Node*>();
        $$ -> push_back($1);
      }
    }
	| %empty{$$=nullptr;}
	;
plus_COMMA_test // Used in: plus_COMMA_test, opt_test_2
	: plus_COMMA_test COMMA test
	| COMMA test
	;
opt_test_2 // Used in: print_stmt
	: plus_COMMA_test opt_COMMA
	| %empty
	;
del_stmt // Used in: small_stmt
	: DEL exprlist
	;
pass_stmt // Used in: small_stmt
	: PASS
	;
flow_stmt // Used in: small_stmt
	: break_stmt{$$=nullptr;}
	| continue_stmt{$$=nullptr;}
	| return_stmt{$$=$1;}
	| raise_stmt{$$=nullptr;}
	| yield_stmt{$$=nullptr;}
	;
break_stmt // Used in: flow_stmt
	: BREAK
	;
continue_stmt // Used in: flow_stmt
	: CONTINUE
	;
return_stmt // Used in: flow_stmt
	: RETURN testlist
        {
           $$=new ReturnNode($2);
           std::cout<<"creat ruturn node"<<std::endl;
           pool.add($$);
        }
	| RETURN
        {
           NONELiteral* none = new NONELiteral();
           pool.add(none);
           $$=new ReturnNode(none);
           pool.add($$);
        }
	;
yield_stmt // Used in: flow_stmt
	: yield_expr
	;
raise_stmt // Used in: flow_stmt
	: RAISE test opt_test_3
	| RAISE
	;
opt_COMMA_test // Used in: opt_test_3, exec_stmt
	: COMMA test
	| %empty
	;
opt_test_3 // Used in: raise_stmt
	: COMMA test opt_COMMA_test
	| %empty
	;
import_stmt // Used in: small_stmt
	: import_name
	| import_from
	;
import_name // Used in: import_stmt
	: IMPORT dotted_as_names
	;
import_from // Used in: import_stmt
	: FROM pick_dotted_name IMPORT pick_STAR_import
	;
pick_dotted_name // Used in: import_from
	: star_DOT dotted_name
	| star_DOT DOT
	;
pick_STAR_import // Used in: import_from
	: STAR
	| LPAR import_as_names RPAR
	| import_as_names
	;
import_as_name // Used in: import_as_names, star_COMMA_import_as_name
	: NAME AS NAME
	| NAME
	;
dotted_as_name // Used in: dotted_as_names
	: dotted_name AS NAME
	| dotted_name
	;
import_as_names // Used in: pick_STAR_import
	: import_as_name star_COMMA_import_as_name COMMA
	| import_as_name star_COMMA_import_as_name
	;
star_COMMA_import_as_name // Used in: import_as_names, star_COMMA_import_as_name
	: star_COMMA_import_as_name COMMA import_as_name
	| %empty
	;
dotted_as_names // Used in: import_name, dotted_as_names
	: dotted_as_name
	| dotted_as_names COMMA dotted_as_name
	;
dotted_name // Used in: decorator, pick_dotted_name, dotted_as_name, dotted_name
	: NAME
	| dotted_name DOT NAME
	;
global_stmt // Used in: small_stmt
	: GLOBAL NAME star_COMMA_NAME
	;
star_COMMA_NAME // Used in: global_stmt, star_COMMA_NAME
	: star_COMMA_NAME COMMA NAME
	| %empty
	;
exec_stmt // Used in: small_stmt
	: EXEC expr IN test opt_COMMA_test
	| EXEC expr
	;
assert_stmt // Used in: small_stmt
	: ASSERT test COMMA test
	| ASSERT test
	;
compound_stmt // Used in: stmt
	: if_stmt{$$=$1;}
	| while_stmt{$$=nullptr;}
	| for_stmt{$$=nullptr;}
	| try_stmt{$$=nullptr;}
	| with_stmt{$$=nullptr;}
	| funcdef{$$=$1;}
	| classdef{$$=nullptr;}
	| decorated{$$=nullptr;}
	;
if_stmt // Used in: compound_stmt
	: IF test COLON suite star_ELIF ELSE COLON suite
        {
           $$=new IfNode($2,$4,$8);
           pool.add($$);
        }
	| IF test COLON suite star_ELIF
        {
           $$=new IfNode($2,$4);
           pool.add($$);
        }
	;
star_ELIF // Used in: if_stmt, star_ELIF
	: star_ELIF ELIF test COLON suite
	| %empty
	;
while_stmt // Used in: compound_stmt
	: WHILE test COLON suite ELSE COLON suite
	| WHILE test COLON suite
	;
for_stmt // Used in: compound_stmt
	: FOR exprlist IN testlist COLON suite ELSE COLON suite
	| FOR exprlist IN testlist COLON suite
	;
try_stmt // Used in: compound_stmt
	: TRY COLON suite plus_except opt_ELSE opt_FINALLY
	| TRY COLON suite FINALLY COLON suite
	;
plus_except // Used in: try_stmt, plus_except
	: plus_except except_clause COLON suite
	| except_clause COLON suite
	;
opt_ELSE // Used in: try_stmt
	: ELSE COLON suite
	| %empty
	;
opt_FINALLY // Used in: try_stmt
	: FINALLY COLON suite
	| %empty
	;
with_stmt // Used in: compound_stmt
	: WITH with_item star_COMMA_with_item COLON suite
	;
star_COMMA_with_item // Used in: with_stmt, star_COMMA_with_item
	: star_COMMA_with_item COMMA with_item
	| %empty
	;
with_item // Used in: with_stmt, star_COMMA_with_item
	: test AS expr
	| test
	;
except_clause // Used in: plus_except
	: EXCEPT test opt_AS_COMMA
	| EXCEPT
	;
pick_AS_COMMA // Used in: opt_AS_COMMA
	: AS
	| COMMA
	;
opt_AS_COMMA // Used in: except_clause
	: pick_AS_COMMA test
	| %empty
	;
suite // Used in: funcdef, if_stmt, star_ELIF, while_stmt, for_stmt, try_stmt, plus_except, opt_ELSE, opt_FINALLY, with_stmt, classdef
	: simple_stmt
	{
	  $$= new SuiteNode($1);
          pool.add($$);
	}
	| NEWLINE INDENT plus_stmt DEDENT
	{
	  $$= new SuiteNode($3);
    delete $3;
          pool.add($$);
	}
	;
plus_stmt // Used in: suite, plus_stmt
	: plus_stmt stmt
	    {
	      $$ = $1;
	      $$ -> push_back($2);
	    }
	| stmt
	{
	  $$ = new std::vector<Node*>(); $$ -> push_back($1); 
          // have a try if we need pool.add($$);
	}
	;
testlist_safe // Used in: list_for
	: old_test plus_COMMA_old_test opt_COMMA
	| old_test
	;
plus_COMMA_old_test // Used in: testlist_safe, plus_COMMA_old_test
	: plus_COMMA_old_test COMMA old_test
	| COMMA old_test
	;
old_test // Used in: testlist_safe, plus_COMMA_old_test, old_lambdef, list_if, comp_if
	: or_test
	| old_lambdef
	;
old_lambdef // Used in: old_test
	: LAMBDA varargslist COLON old_test
	| LAMBDA COLON old_test
	;
test // Used in: opt_EQUAL_test, print_stmt, star_COMMA_test, opt_test, plus_COMMA_test, raise_stmt, opt_COMMA_test, opt_test_3, exec_stmt, assert_stmt, if_stmt, star_ELIF, while_stmt, with_item, except_clause, opt_AS_COMMA, opt_IF_ELSE, listmaker, testlist_comp, lambdef, subscript, opt_test_only, sliceop, testlist, dictorsetmaker, star_test_COLON_test, opt_DOUBLESTAR_test, pick_argument, argument, testlist1
	: or_test opt_IF_ELSE
	  { 
          $$=$1;//I just have the or_test part.
          }
	| lambdef
	{$$=nullptr;//do nothing with lambdef
        }
	;
opt_IF_ELSE // Used in: test
	: IF or_test ELSE test
        {$$=$4;//I don't know this kind of grammer so I haven't deal with this kind of grammer 
        }
	| %empty{$$=nullptr;}
	;
or_test // Used in: old_test, test, opt_IF_ELSE, or_test, comp_for
	: and_test{$$=$1;}
	| or_test OR and_test
	;
and_test // Used in: or_test, and_test
	: not_test{$$=$1;}
	| and_test AND not_test
	;
not_test // Used in: and_test, not_test
	: NOT not_test{$$=nullptr;/*do nothing with not*/}
	| comparison{$$=$1;}
	;
comparison // Used in: not_test, comparison
	: expr{$$=$1;}
	| comparison comp_op expr
          {
           switch ($2)
		   {
		      case (LESS):
			  {$$= new LesserBinaryNode($1,$3); pool.add($$);break;}
			  case (GREATER):
			  {$$= new BiggerBinaryNode($1,$3);pool.add($$);break;}
			  case (EQEQUAL):
			  {$$= new EqEqBinaryNode($1,$3);pool.add($$);break;}
			  case (GREATEREQUAL):
			  {$$= new BgEqBinaryNode($1,$3);pool.add($$);break;}
			  case (LESSEQUAL):
			  {$$= new LsEqBinaryNode($1,$3);pool.add($$);break;} 
			  default:{$$=nullptr;break;}
		   }
	      
          }
	;
comp_op // Used in: comparison
	: LESS{$$=LESS; }
	| GREATER{$$=GREATER; }
	| EQEQUAL{$$= EQEQUAL; }
	| GREATEREQUAL{$$= GREATEREQUAL; }
	| LESSEQUAL{$$= LESSEQUAL; }
	| GRLT{$$= GRLT; }
	| NOTEQUAL{$$= NOTEQUAL; }
	| IN{$$= IN ; }
	| NOT IN{$$= IN; }
	| IS{$$= IS; }
	| IS NOT{$$= IS; }
	;
expr // Used in: exec_stmt, with_item, comparison, expr, exprlist, star_COMMA_expr
	: xor_expr{$$=$1;}
	| expr BAR xor_expr
          {$$ = new BarNode($1, $3); 
          //std::cout<<"|called"<<std::endl;
                             pool.add($$);}
	;
xor_expr // Used in: expr, xor_expr
	: and_expr{$$=$1;}
	| xor_expr CIRCUMFLEX and_expr
          {$$ = new CIRCUMFLEXNode($1, $3); 
          //std::cout<<"^called"<<std::endl;
                             pool.add($$);}
	;
and_expr // Used in: xor_expr, and_expr
	: shift_expr{$$=$1;}
	| and_expr AMPERSAND shift_expr
          {$$ = new AMPERSANDNode($1, $3); 
           //std::cout<<"&called"<<std::endl;
                             pool.add($$);}
	;
shift_expr // Used in: and_expr, shift_expr
	: arith_expr{$$=$1;}
	| shift_expr pick_LEFTSHIFT_RIGHTSHIFT arith_expr
          {
            if ($2==LEFTSHIFT)
            {$$ = new LeftShiftNode($1, $3); 
                             pool.add($$);}
            else 
            {
               if ($2==RIGHTSHIFT)
               {$$ = new RightShiftNode($1, $3); 
                             pool.add($$);}
   
             } 
          }
	;
pick_LEFTSHIFT_RIGHTSHIFT // Used in: shift_expr 56 bytes in 2 blocks

	: LEFTSHIFT{$$=LEFTSHIFT;}
	| RIGHTSHIFT{$$=RIGHTSHIFT;}
	;
arith_expr // Used in: shift_expr, arith_expr
	: term{$$=$1;}
	| arith_expr pick_PLUS_MINUS term
          {
            if ($2==PLUS)
            {$$ = new AddBinaryNode($1, $3); 
                             pool.add($$);}
            else 
            {
               if ($2==MINUS)
               {$$ = new SubBinaryNode($1, $3); 
                             pool.add($$);}
   
             } 
          }
	;
pick_PLUS_MINUS // Used in: arith_expr
	: PLUS{$$=PLUS;}
	| MINUS{$$=MINUS;}
	;
term // Used in: arith_expr, term
	: factor{$$=$1;}
	| term pick_multop factor
          {
           if($2==STAR)
             { $$ = new MulBinaryNode($1, $3); 
                             pool.add($$);}
           if($2==SLASH)
             {$$ = new DivBinaryNode($1, $3); 
                             pool.add($$); 
             }

           if($2==DOUBLESLASH)
             {$$ = new DoubleSlaBinaryNode($1, $3); 
                             pool.add($$); 
             }

           if($2==PERCENT)
             {$$ = new PercentBinaryNode($1, $3); 
                             pool.add($$); 
             }           

          }
	;
pick_multop // Used in: term
	: STAR{$$= STAR;}
	| SLASH{$$= SLASH;}
	| PERCENT{$$= PERCENT;}
	| DOUBLESLASH{$$= DOUBLESLASH;}
	;
factor // Used in: term, factor, power
	: pick_unop factor
          {//0+-x
            if ($1==PLUS)
            {$$=$2;}
            else 
            { if($1==MINUS)
              {IntLiteral* temp0=new IntLiteral(0);
              $$ = new SubBinaryNode(temp0, $2); 
              pool.add($$);
              pool.add(temp0);}
              else
              {$$= new TildeUnaryNode($2);pool.add($$);}
   
             } 
          }
	| power{$$=$1;}
	;

pick_unop // Used in: factor
	: PLUS{$$ = PLUS;}
	| MINUS{$$= MINUS;}
	| TILDE{$$=TILDE;}
	;
power // Used in: factor
	: atom star_trailer DOUBLESTAR factor 
          {// left the a[1][2]**4
           $$ = new PowerBinaryNode($1, $4); 
           pool.add($$);
          }
	| atom star_trailer
    {//$$=$1; 
      if($2){
			  $$=new FuncCallNode(static_cast<IdentNode*>($1) -> getIdent());
                          std::cout<<"new a functon call node"<<std::endl;
			  pool.add($$);
      }  
    }
	;
star_trailer // Used in: power, star_trailer
	: star_trailer trailer{$$=$2;}
	| %empty
      {$$=0;}
	;
atom // Used in: power
	: LPAR opt_yield_test RPAR{$$=$2;}
	| LSQB opt_listmaker RSQB {$$=NULL;}
	| LBRACE opt_dictorsetmaker RBRACE {$$=NULL;}
	| BACKQUOTE testlist1 BACKQUOTE {$$=NULL;}
	| NAME{  std::string tempb=$1;
                 if(tempb=="True")
                    {
                      $$ = new BoolLiteral(1);         
                      delete [] $1;
                      pool.add($$);
                    }
                 else 
                   if(tempb=="False")
                    {
                      $$ = new BoolLiteral(0);         
                      delete [] $1;
                      pool.add($$);
                    }
                   else
                    {
                    $$ = new IdentNode($1);         
                     delete [] $1;
                     pool.add($$);
                     //std::cout<<"variable"<<std::endl;
                    }
              }
        | INT{
               $$ = new IntLiteral($1);        
               pool.add($$);
             }
        | FLOAT{
               $$ = new FloatLiteral($1);        
               pool.add($$);
               }
	| NUMBER{$$=nullptr;/*do nothing with other number*/}
	| plus_STRING {$$=NULL;}
	;
pick_yield_expr_testlist_comp // Used in: opt_yield_test
	: yield_expr{$$=$1;}
	| testlist_comp{$$=$1;}
	;
opt_yield_test // Used in: atom
	: pick_yield_expr_testlist_comp{$$=$1;}
	| %empty{$$=NULL;}
	;
opt_listmaker // Used in: atom
	: listmaker
	| %empty
	;
opt_dictorsetmaker // Used in: atom
	: dictorsetmaker
	| %empty
	;
plus_STRING // Used in: atom, plus_STRING
	: plus_STRING STRING
	| STRING
	;
listmaker // Used in: opt_listmaker
	: test list_for
	| test star_COMMA_test opt_COMMA
	;
testlist_comp // Used in: pick_yield_expr_testlist_comp
	: test comp_for
          {//leave the comp, just keep test in() 
           $$=$1;
          }
	| test star_COMMA_test opt_COMMA
          {//leave the (a,b,c), just keep test in() 
           $$=$1;
          }
	;
lambdef // Used in: test
	: LAMBDA varargslist COLON test
	| LAMBDA COLON test
	;
trailer // Used in: star_trailer
	: LPAR opt_arglist RPAR{$$=1;}
	| LSQB subscriptlist RSQB{$$=1;}
	| DOT NAME{$$=1;}
	;
subscriptlist // Used in: trailer
	: subscript star_COMMA_subscript COMMA
	| subscript star_COMMA_subscript
	;
star_COMMA_subscript // Used in: subscriptlist, star_COMMA_subscript
	: star_COMMA_subscript COMMA subscript
	| %empty
	;
subscript // Used in: subscriptlist, star_COMMA_subscript
	: DOT DOT DOT
	| test
	| opt_test_only COLON opt_test_only opt_sliceop
	;
opt_test_only // Used in: subscript
	: test
	| %empty
	;
opt_sliceop // Used in: subscript
	: sliceop
	| %empty
	;
sliceop // Used in: opt_sliceop
	: COLON test
	| COLON
	;
exprlist // Used in: del_stmt, for_stmt, list_for, comp_for
	: expr star_COMMA_expr COMMA
        {$$ = $1;}
	| expr star_COMMA_expr
        {$$ = $1;}
	;
star_COMMA_expr // Used in: exprlist, star_COMMA_expr
	: star_COMMA_expr COMMA expr
	| %empty
	;
testlist // Used in: expr_stmt, pick_yield_expr_testlist, return_stmt, for_stmt, opt_testlist, yield_expr
	: test star_COMMA_test COMMA{$$=$1;}
	| test star_COMMA_test{$$=$1;}
	;
dictorsetmaker // Used in: opt_dictorsetmaker
	: test COLON test pick_for_test_test
	| test pick_for_test
	;
star_test_COLON_test // Used in: star_test_COLON_test, pick_for_test_test
	: star_test_COLON_test COMMA test COLON test
	| %empty
	;
pick_for_test_test // Used in: dictorsetmaker
	: comp_for
	| star_test_COLON_test opt_COMMA
	;
pick_for_test // Used in: dictorsetmaker
	: comp_for
	| star_COMMA_test opt_COMMA
	;
classdef // Used in: decorated, compound_stmt
	: CLASS NAME LPAR opt_testlist RPAR COLON suite
	| CLASS NAME COLON suite
	;
opt_testlist // Used in: classdef
	: testlist
	| %empty
	;
arglist // Used in: opt_arglist
	: star_argument_COMMA pick_argument
	;
star_argument_COMMA // Used in: arglist, star_argument_COMMA
	: star_argument_COMMA argument COMMA
	| %empty
	;
star_COMMA_argument // Used in: star_COMMA_argument, pick_argument
	: star_COMMA_argument COMMA argument
	| %empty
	;
opt_DOUBLESTAR_test // Used in: pick_argument
	: COMMA DOUBLESTAR test
	| %empty
	;
pick_argument // Used in: arglist
	: argument opt_COMMA
	| STAR test star_COMMA_argument opt_DOUBLESTAR_test
	| DOUBLESTAR test
	;
argument // Used in: star_argument_COMMA, star_COMMA_argument, pick_argument
	: test opt_comp_for
	| test EQUAL test
	;
opt_comp_for // Used in: argument
	: comp_for
	| %empty
	;
list_iter // Used in: list_for, list_if
	: list_for
	| list_if
	;
list_for // Used in: listmaker, list_iter
	: FOR exprlist IN testlist_safe list_iter
	| FOR exprlist IN testlist_safe
	;
list_if // Used in: list_iter
	: IF old_test list_iter
	| IF old_test
	;
comp_iter // Used in: comp_for, comp_if
	: comp_for
	| comp_if
	;
comp_for // Used in: testlist_comp, pick_for_test_test, pick_for_test, opt_comp_for, comp_iter
	: FOR exprlist IN or_test comp_iter
	| FOR exprlist IN or_test
	;
comp_if // Used in: comp_iter
	: IF old_test comp_iter
	| IF old_test
	;
testlist1 // Used in: atom, testlist1
	: test
	| testlist1 COMMA test
	;
yield_expr // Used in: pick_yield_expr_testlist, yield_stmt, pick_yield_expr_testlist_comp
	: YIELD testlist{$$=$2;}
	| YIELD {$$=NULL;}
	;
star_DOT // Used in: pick_dotted_name, star_DOT
	: star_DOT DOT
	| %empty
	;

%%

#include <stdio.h>
void yyerror (const char *s)
{
    if(yylloc.first_line > 0)	{
        fprintf (stderr, "%d.%d-%d.%d:", yylloc.first_line, yylloc.first_column,
	                                     yylloc.last_line,  yylloc.last_column);
    }
    fprintf(stderr, " %s with [%s]\n", s, yytext);
}
