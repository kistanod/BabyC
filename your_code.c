#include "your_code.h"
#include <stdlib.h>
#include <stdio.h>


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

ASTNode* CreateDeclarationListNode(ASTNode* declaration, ASTNode* declarationList) {

        declaration->next = declarationList;
        return declaration;
        
}
ASTNode* CreateAssignmentNode(char* ident, ASTNode* expr) {
        ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
        node->type = ASTNODE_ASSIGN;
        node->name = ident;
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


void AddDeclaration(char* name) {
}

// Commented out in this assignment 
/*void GenerateILOC(ASTNode* node);
{

}*/

