#include "your_code.h"
#include <stdlib.h>
#include <stdio.h>

#define TABLE_SIZE 1000


// Write the implementations of the functions that do the real work here

ASTNode* CreateNumNode(int num) {
	ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
	node->type = ASTNODE_NUM; 
	node->num = num;
	return node;
}


ASTNode* CreateIdentNode(char* name) {
	ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
	node->type = ASTNODE_IDENT;
	node->name = name;
	return node;
}

// Take a statement node and a statement list node and connect them together
// to form a bigger statement list node (add the statement to the statement list).
// Return a pointer to the bigger list that resulted from this linking
ASTNode* CreateStatementListNode(ASTNode* statement, ASTNode* statementList) {
	statement->next = statementList;
	return statement;
}
ASTNode* CreateAssignmentNode(ASTNode* identNode, ASTNode* expr) {
	
	ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
	node->type = ASTNODE_ASSIGN;
	node->left = identNode;
	node->right = expr;
	return node;
}
ASTNode* CreateAddNode(ASTNode* item1, ASTNode* item2) {
	ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
	node->type = ASTNODE_ARITH_OP;
	node->op = ADD_OP;
	node->left = item1;
	node->right = item2;
	return node;
}
ASTNode* CreateSubtractNode(ASTNode* item1, ASTNode* item2) {
	ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
	node->type = ASTNODE_ARITH_OP;
	node->op = SUB_OP;
	node->left = item1;
	node->right = item2;
	return node;
	
}
ASTNode* CreateMultNode(ASTNode* item1, ASTNode* item2) {
	ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
	node->type = ASTNODE_ARITH_OP;
	node->op = MULT_OP;
	node->left = item1;
	node->right = item2;
	return node;
	
}
ASTNode* CreateDivideNode(ASTNode* item1, ASTNode* item2) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
	node->type = ASTNODE_ARITH_OP;
	node->op = DIV_OP;
	node->left = item1;
	node->right = item2;
	return node;
}

ASTNode* CreateWhileNode(ASTNode* condition, ASTNode* StatementList) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = ASTNODE_WHILE;
    node->left = condition;
    node-> right = StatementList;
    return node;
}


void AddDeclaration(char* name) {

}

/* found on stack overflow, some simple hash function*/
unsigned int hash(char* str) {
    unsigned int hash = 5381;
	int c;

	while (c = *str++)
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return hash % TABLE_SIZE;
}

// Commented out in this assignment 
/*void GenerateILOC(ASTNode* node); {

}*/

