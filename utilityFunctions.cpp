//
// Created by kevin on 4/30/2020.
//
#include <cstdint>
#include "Parse.h"
#include <vector>
#include <string>
#include "dataBase.h"
using namespace std;
int8_t strCmp(const char* s1, const char* s2)
{
    while(*s1){
        if(*s2 == 0)
        {
            return 1;
        }
        else if(*s1 != *s2){
            if(*s1 < *s2)
            {
                return -1;
            }
            else
            {
                return 1;
            }
        }
        s1++;
        s2++;
    }
    if(*s2 == 0)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}
vector<string> getExpression(dataBase &data){
    string token;
    string valueString;
    vector<string> expression;
    string next = peek_next_token();
    do{
        if(next_token_type == NAME)
        {
            read_next_token();
            token = next_token();
            int32_t value = data.retrieveValue(token);
            valueString = to_string(value);
            expression.push_back(valueString);
            next = peek_next_token();
        }
        else
        {
            read_next_token();
            token = next_token();
            expression.push_back(token);
            next = peek_next_token();
        }
    } while((next_token_type == NUMBER || next_token_type == SYMBOL || next_token_type == NAME) && next != "//"
    && next != "var" && next !="output" && next != "text" && next != "set");

    return expression;
}
