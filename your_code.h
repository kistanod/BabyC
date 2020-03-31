#ifndef YOUR_CODE_H
#define YOUR_CODE_H


typedef enum{ASTNODE_ARITH_OP, ASTNODE_LOGIC_OP, ASTNODE_COMPARE, ASTNODE_ASSIGN, ASTNODE_IDENT, ASTNODE_NUM, ASTNODE_IF, ASTNODE_WHILE} ASTNodeType;

// Define all operation types (add, mult, etc) here.
typedef enum{ADD_OP, MULT_OP, SUB_OP, DIV_OP, OR_OP, AND_OP} ASTOp; 

typedef enum{LE_OP, GE_OP, EQ_OP, NE_OP, L_OP, M_OP} COMPOp;




typedef struct ASTNode ASTNode;

struct ASTNode {
	ASTNodeType type; 
    ASTOp op; // The actual operation (add, mult, etc)
    COMPOp comparison;
	int num;  //Need to store the actual value for number nodes
	char* name; //Need to store the actual variable name for ident nodesz
    
	ASTNode* left; // Left child
	ASTNode* right; // Right child
    int tableLocation;
	
	// The following pointer is just a suggestion; you don't have to use it if you have a better design.
	ASTNode* next; // a pointer used to link statement nodes together in a statement list

	// Depending on your implementation, you may need to add other fields to this struct 

};
typedef struct DataItem DataItem;

struct DataItem {
   int data;  
   char* key;
};

// Add functions to create the different kinds of ASTNodes 
// These functions are called by the code embedded in the grammar.
// Here are some samples:  
ASTNode* CreateNumNode(int num);
ASTNode* CreateIdentNode(char* name);
ASTNode* CreateStatementListNode(ASTNode* statement, ASTNode* statementList);

// the canonical expression

ASTNode* CreateAssignmentNode(ASTNode* identNode, ASTNode* expr);
ASTNode* CreateAddNode(ASTNode* item1, ASTNode* item2);
ASTNode* CreateSubtractNode(ASTNode* item1, ASTNode* item2);
ASTNode* CreateMultNode(ASTNode* item1, ASTNode* item2);
ASTNode* CreateDivideNode(ASTNode* item1, ASTNode* item2);


// the condition declaration
ASTNode* CreateWhileNode(ASTNode* condition, ASTNode* StatementList);
ASTNode* CreateORNode(ASTNode* item1, ASTNode* item2);
ASTNode* CreateANDNode(ASTNode* item1, ASTNode* item2);
ASTNode* CreateCompareNode(ASTNode* expr1, COMPOp comparison, ASTNode* expr2);

// Need a function to add a declaration to your symbol table
void AddDeclaration(char* name);

// This is the function that generates ILOC code after the construction of the AST
//void GenerateILOC(ASTNode* node);
#endif
