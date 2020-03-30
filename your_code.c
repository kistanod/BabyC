#include "your_code.h"
#include <stdlib.h>
#include <stdio.h>

#define TABLE_SIZE 100

DataItem* symbolTable[TABLE_SIZE];

/* found on stack overflow, some simple hash function */
unsigned int hashFunction(char* str) {
    unsigned int hash = 5381;
    int c;
    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return hash % TABLE_SIZE;
}

ASTNode* CreateNumNode(int num) {
	ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
	node->type = ASTNODE_NUM; 
	node->num = num;
	return node;
}


ASTNode* CreateIdentNode(char* name) {

    unsigned int hashResult = hashFunction(name);

    if(symbolTable[hashResult] != NULL) {
        ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
	    node->type = ASTNODE_IDENT;
	    node->name = name;
        node->tableLocation = hashResult;
	    return node;
    } else {
        printf("ERROR: varible %s not declared!", name);
        exit(1);
    }

	
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

    unsigned int hashResult = hashFunction(name);
    symbolTable[hashResult] = (DataItem*)malloc(sizeof(DataItem));
    symbolTable[hashResult]->key = name;

}



// Commented out in this assignment 
/* void GenerateILOC(ASTNode* node); {

} */

