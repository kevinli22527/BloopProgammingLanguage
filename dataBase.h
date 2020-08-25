//
// Created by kevin on 4/30/2020.
//

#ifndef PROJECT8_DATABASE_H
#define PROJECT8_DATABASE_H
#include <vector>
#include <string>
#include <cstdint>
using namespace std;
class dataBase {
    class variableEntry{
    public:
        string varName;
        int32_t varValue;
        variableEntry* left;
        variableEntry* right;
        variableEntry* parent;

        variableEntry(string &s, int32_t value){
            varName = s;
            varValue = value;
            left = nullptr;
            right = nullptr;
            parent = nullptr;
        }
        ~variableEntry(){
            delete left;
            delete right;
        }
    };
    variableEntry* root;
public:
    void addNewVariable(string &name, int32_t value){
        variableEntry* newbie = new variableEntry(name, value);
        variableEntry* current = root;
        variableEntry* parent = nullptr;
        if(root == nullptr)
        {
            root = newbie;
            root->parent = parent;
            return;
        }
        while(current != nullptr){
            if(name.compare(current->varName) == 0){
                current->varValue = value; //overwrite
                delete newbie;
                return;
            }
            else if(name.compare(current->varName) < 0){
                parent = current;
                current = current->left;
            }
            else
            {
                parent = current;
                current = current->right;
            }
        }
        if(name.compare(parent->varName) < 0){
            parent->left = newbie;
            newbie->parent = parent;
        }
        else
        {
            parent->right = newbie;
            newbie->parent = parent;
        }
    }

    dataBase() {
        root = nullptr;
    }
    bool doesItExist(string &variableName){
        variableEntry* current = root;
        while(current != nullptr){
            if(variableName.compare(current->varName) == 0)
            {
                return true;
            }
            else if(variableName.compare(current->varName) < 0)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        return false;
    }

    int32_t retrieveValue(string &variableName){
        variableEntry* current = root;
        while(current != nullptr){
            if(variableName.compare(current->varName) == 0)
            {
                return current->varValue;
            }
            else if(variableName.compare(current->varName) < 0)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
    }
    ~dataBase(){
        delete root;
    }
};


#endif //PROJECT8_DATABASE_H
