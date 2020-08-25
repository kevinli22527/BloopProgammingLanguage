//
// Created by kevin on 4/30/2020.
//
#ifndef PROJECT8_EXPRESSIONTREE_H
#define PROJECT8_EXPRESSIONTREE_H
#include <cstdint>
#include <vector>
#include <string>
using namespace std;
class ExpressionTree {
    class Node {
        bool isOperator;
        bool isBinaryOp;
        int32_t value;
        string operation;
        Node* op1;
        Node* op2;
    public:
        Node(string letters, Node* left, Node* right, bool isBinary){
            operation = letters;
            isOperator = true;
            isBinaryOp = isBinary;
            value = 0;
            op1 = left;
            op2 = right;
        }
        Node(int32_t number){
            isOperator = false;
            isBinaryOp = false;
            value = number;
            operation = "NULL";
            op1 = nullptr;
            op2 = nullptr;
        }
        ~Node(){
            delete op1;
            delete op2;
        }
        int32_t evaluate(void){
            if(isOperator == true)
            {
                if(isBinaryOp == true)
                {
                    int num1 = op1->evaluate();
                    int num2 = op2->evaluate();
                    if(operation == "+")
                    {
                        return num1 + num2;
                    }
                    else if(operation == "-")
                    {
                        return num1 - num2;
                    }
                    else if(operation == "*")
                    {
                        return num1 * num2;
                    }
                    else if(operation == "/")
                    {
                        return num1 / num2;
                    }
                    else if(operation == "%")
                    {
                        return num1 % num2;
                    }
                    else if(operation == "&&")
                    {
                        if(num1 > 0 && num2 > 0)
                        {
                            return 1;
                        }
                        else
                        {
                            return 0;
                        }
                    }else if(operation == "||")
                    {
                        if(num1 > 0 || num2 > 0)
                        {
                            return 1;
                        }
                        else
                        {
                            return 0;
                        }
                    }
                    else if(operation == "<")
                    {
                        if(num1 < num2)
                        {
                            return 1;
                        }
                        else
                        {
                            return 0;
                        }
                    }
                    else if(operation == ">")
                    {
                        if(num1 > num2)
                        {
                            return 1;
                        }
                        else
                        {
                            return 0;
                        }
                    }
                    else if(operation == "==")
                    {
                        if(num1 == num2)
                        {
                            return 1;
                        }
                        else
                        {
                            return 0;
                        }
                    }
                    else if(operation == "<=")
                    {
                        if(num1 <= num2)
                        {
                            return 1;
                        }
                        else
                        {
                            return 0;
                        }
                    }
                    else if(operation == ">=")
                    {
                        if(num1 >= num2)
                        {
                            return 1;
                        }
                        else
                        {
                            return 0;
                        }
                    }
                    else if(operation == "!=")
                    {
                        if(num1 != num2)
                        {
                            return 1;
                        }
                        else
                        {
                            return 0;
                        }
                    }
                }
                else
                {
                    int32_t num1 = op1->evaluate();
                    if(operation == "~")
                    {
                        return ~num1 + 1;
                    }
                    else if(operation == "!")
                    {
                        if(num1 != 0)
                        {
                            return 0;
                        }
                        else
                        {
                            return 1;
                        }
                    }
                }
            }
            else
            {
                return value;
            }
        }
    };
    Node* root;
public:
    ExpressionTree(vector<string> &expression){
        root = constructTree(expression);
    }
    Node* constructTree(vector<string> &expression){
        if(expression.size() == 0)
        {
            return nullptr;
        }
        string token = expression[0];
        expression.erase(expression.begin());
        if(token == "+" || token == "-" || token == "*" || token == "/" || token == "%" || token == "<" || token == ">"
        || token == "&&" || token == "||" || token == "==" || token == "!="
        || token == "<=" || token == ">="){
            Node* left = constructTree(expression);
            Node* right = constructTree(expression);
            return new Node(token, left, right, true);
        }
        else if(token == "!" || token == "~"){
            Node* left = constructTree(expression);
            Node* right = nullptr;
            return new Node(token, left, right, false);
        }
        else
        {
            return new Node(stoi(token));
        }
    }
    int32_t evaluateTree(void){
        if(root == nullptr){
            return 0;
        }
        else
        {
            return root->evaluate();
        }
    }
    ~ExpressionTree(){
        delete root;
    }
};


#endif //PROJECT8_EXPRESSIONTREE_H
