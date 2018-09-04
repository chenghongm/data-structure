#ifndef STACKTYPE_H_INCLUDED
#define STACKTYPE_H_INCLUDED
#include<vector>
#include"Stacktype.h"
#include<iostream>
using namespace std;
const int MAX_ITEMS=25;

 class FullStack{};
 class EmptyStack{};

struct ItemType{

   char elem;
  ItemType *left;
  ItemType *right;

};

 class StackType
 {
 private:
    int top;
    ItemType * items[MAX_ITEMS];

 public:
    StackType();
    int gettop();
    bool isFull();
    bool isEmpty() const;
    void push(ItemType*);
    void pop();
    ItemType* getTop();
    bool isOperator(char);
    ItemType* ItemTypeNode(char);
    ItemType* rpn_to_tree(vector<char>&,StackType &);
    void InOrder(ItemType* );
    void PreOrder(ItemType* );
    void PostOrder(ItemType* );


};

#endif // STACKTYPE_H_INCLUDED
