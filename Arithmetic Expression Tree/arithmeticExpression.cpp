//
// Created by Cristina Lawson on 2019-04-29.
//

#include <iostream>
#include <stack>
#include <fstream>
#include <sstream>
using namespace std;

#include "arithmeticExpression.h"


arithmeticExpression::arithmeticExpression(const string &infix) {
    root = nullptr;
    infixExpression = infix;
}

void arithmeticExpression::buildTree() {
    infixExpression = infix_to_postfix();

    stack<TreeNode*> tStack;
    char letter = 'a';
    char cLetter;

    for (unsigned i = 0; i < infixExpression.size(); ++i) {
        cLetter = infixExpression.at(i);
        if (cLetter == '+' || cLetter == '-' || cLetter == '*' || cLetter == '/') {
            TreeNode* tNode = new TreeNode(cLetter, letter);
            tNode ->right = tStack.top();
            tStack.pop();
            tNode->left = tStack.top();
            tStack.pop();
            tStack.push(tNode);
            ++letter;
        }
        else {
            TreeNode* tNode = new TreeNode(cLetter, letter);
            ++letter;
            tStack.push(tNode);
        }
    }
    root = tStack.top();
    tStack.pop();
}

void arithmeticExpression::infix() {
    return infix(root);
}

void arithmeticExpression::prefix() {
    return prefix(root);
}

void arithmeticExpression::postfix() {
    return postfix(root);
}

void arithmeticExpression::infix(TreeNode *node) {
    if (node == 0) {
        return;
    }

    if (node->left != 0 && node->right != 0) {
        cout << "(";
    }

    infix(node->left);
    cout << node->data;
    infix(node->right);

    if (node->left != 0 && node->right != 0) {
        cout << ")";
    }
}

void arithmeticExpression::prefix(TreeNode *node) {
    if (node == 0) {
        return;
    }

    cout << node->data;
    prefix(node->left);
    prefix(node->right);
}

void arithmeticExpression::postfix(TreeNode *node) {
    if (node == 0) {
        return;
    }

    postfix(node->left);
    postfix(node->right);
    cout << node->data;
}

void arithmeticExpression::visualizeTree(ofstream &out, TreeNode *node) {

}

int arithmeticExpression::priority(char op){
    int priority = 0;
    if(op == '('){
        priority =  3;
    }
    else if(op == '*' || op == '/'){
        priority = 2;
    }
    else if(op == '+' || op == '-'){
        priority = 1;
    }
    return priority;
}

string arithmeticExpression::infix_to_postfix(){
    stack<char> s;
    ostringstream oss;
    char c;
    for(unsigned i = 0; i< infixExpression.size();++i){
        c = infixExpression.at(i);
        if(c == ' '){
            continue;
        }
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
            if( c == '('){
                s.push(c);
            }
            else if(c == ')'){
                while(s.top() != '('){
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority(c) <= priority(s.top())){
                    if(s.top() == '('){
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else{ //c is an operand
            oss << c;
        }
    }
    while(!s.empty()){
        oss << s.top();
        s.pop();
    }
    return oss.str();
}

void arithmeticExpression::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error opening "<< outputFilename<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}