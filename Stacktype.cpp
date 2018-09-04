#include"Stacktype.h"
#include <iostream>
#include<vector>
#include<string>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>




using namespace std;

StackType::StackType()
{
    top= -1;

}
bool StackType::isEmpty() const
{
    return (top==-1);
}

bool StackType::isFull()
{
    return(top==MAX_ITEMS-1);
}
void StackType::push(ItemType *newItem)
{
    if(isFull())
        throw FullStack();

    top++;

   items[top]=newItem;

}
void StackType::pop()
{
    if(isEmpty())
        throw EmptyStack();
    top--;
}
ItemType* StackType::getTop()
{
    if(isEmpty())
        throw EmptyStack();

    return (items[top]);
}
int StackType::gettop()
{
    return top;
}
ItemType* StackType::ItemTypeNode(char c)
{
   ItemType *node = new ItemType;
     node->left = NULL;
     node->right = NULL;
     node->elem = c;
     top++;
     return node;
}
bool StackType::isOperator(char elem)
{
    if (elem == '+' || elem == '-' || elem == '*' || elem == '/')

         return true;

    else

        return false;

}
ItemType* StackType::rpn_to_tree(vector<char> &rePN,StackType &st)
{
   ItemType*  newNode,*newNode1,*newNode2;
   cout<<endl;
   for(int i=0;i<(int)rePN.size();i++)
   {
       if( !isOperator(rePN[i]))
       {
           newNode=st.ItemTypeNode(rePN[i]);

           st.push(newNode);

       }
        else
       {
           newNode=st.ItemTypeNode(rePN[i]);

           newNode1=st.getTop();
           st.pop();
           newNode2=st.getTop();
           st.pop();


          newNode->right=newNode1;
          newNode->left=newNode2;

          st.push(newNode);

       }
       newNode=st.getTop();
       st.pop();
   }

     return newNode;
}

void StackType::InOrder(ItemType* newNode)
{
    if(newNode)
       {
        InOrder(newNode->left);
        cout<<newNode->elem;
        InOrder(newNode->right);
       }
}
void StackType::PreOrder(ItemType* newNode)
{

       if(newNode)
       {
           cout<<newNode->elem;
        PreOrder(newNode->left);
        PreOrder(newNode->right);
       }

}
void StackType::PostOrder(ItemType* newNode)
{
    if(newNode)
    {  PostOrder(newNode->left);
       PostOrder(newNode->right);
        cout<<newNode->elem;
    }
}












