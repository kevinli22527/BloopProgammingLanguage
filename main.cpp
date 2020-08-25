//
// Created by kevin on 4/29/2020.
//
#include "Parse.h"
#include <cstdint>
#include <iostream>
#include "utilityFunctions.h"
#include <string>
#include <vector>
#include "ExpressionTree.h"
#include "dataBase.h"
using namespace std;
void runBlip(){
    string token;
    dataBase variableData;
    while(next_token_type != END) {
        read_next_token();
        token = next_token();
        switch(next_token_type){
            case NAME:
                if(token == "text")
                {
                    read_next_token();
                    token = next_token();
                    cout << token;
                }
                else if(token == "output")
                {
                    vector<string> expression = getExpression(variableData);
                    ExpressionTree express(expression);
                    int32_t result = express.evaluateTree();
                    string resultString = to_string(result);
                    cout << resultString;
                }
                else if(token == "var")
                {
                    string name;
                    read_next_token();
                    name = next_token();
                    vector<string> expression = getExpression(variableData);
                    ExpressionTree express(expression);
                    int32_t result = express.evaluateTree();
                    if(variableData.doesItExist(name) == true){
                        cout << "variable " << name << " incorrectly re-initialized" << endl;
                        variableData.addNewVariable(name, result);
                    }
                    else
                    {
                        variableData.addNewVariable(name, result);
                    }
                }
                else if(token == "set")
                {
                    string name;
                    read_next_token();
                    name = next_token();
                    vector<string> expression = getExpression(variableData);
                    ExpressionTree express(expression);
                    int32_t result = express.evaluateTree();
                    if(variableData.doesItExist(name) == false)
                    {
                        cout << "variable " << name << " not declared" << endl;
                        variableData.addNewVariable(name, result);
                    }
                    else
                    {
                        variableData.addNewVariable(name, result);
                    }
                }
                break;
            case NUMBER:
                break;
            case SYMBOL:
                if(token == "//")
                {
                    skip_line();
                }
                break;
            default:
                break;
        }
    }
}
int main(){
    set_input("test1.blip");
    runBlip();
}

