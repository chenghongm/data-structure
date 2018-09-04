//Author: Chenghong Meng
//Assignment 8: Expression PRN Tree

#include <iostream>
#include<vector>
#include<string>
#include<stack>
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


using namespace std;

void getExpression(string&);
float evaluateRPN(vector<char> &,stack<float> &);
void expression_to_RPN(string&,stack<char>,vector<char>&);
ItemType* rpn_to_tree(vector<char>&,StackType&);
void InOrder(ItemType*);
void PreOrder(ItemType*);
void PostOrder(ItemType*);

int main()
{    StackType st;
     stack<char> s;
     ItemType* root;
     stack<float> sf;
     vector<char> rePN;
     string inputChar;
     float result=0.00;
     int choice;
         do
    {   cout<<"-------------------"<<endl;
        cout<<"\t\nStackTypeList:\n"<<endl;
        cout<<"1.GetArithmeticExpression "<<endl;
        cout<<"2.ExpressionToRPN"<<endl;
        cout<<"3.RPNtoBinaryTree"<<endl;
        cout<<"4.EvaluatePRN"<<endl;
        cout<<"5.PrintTreeInOrder"<<endl;
        cout<<"6.PrintTreePreOrder"<<endl;
        cout<<"7.PrintTreePostOrder"<<endl;
        cout<<"8.Exit"<<endl;
        cout<<"Enter your choice : "<<endl;
        cin>>choice;
        switch(choice)
        {
    case 1:
            getExpression(inputChar);
               break;

    case 2:
            expression_to_RPN(inputChar,s,rePN);
            break;
    case 3:
            root=st.rpn_to_tree(rePN,st);
            cout<<"Your tree was built!\n ";
            cout<<"Please print it out as In-/Pre-/Post-Order.!\n";
            break;
    case 4:
            result=evaluateRPN(rePN,sf);
             cout<<"Your RPN result is: "<<result<<endl;
            break;
    case 5:
           root=st.rpn_to_tree(rePN,st);
           st.InOrder(root);
           cout<<endl<<endl;
            break;

    case 6:
           root=st.rpn_to_tree(rePN,st);
           st.PreOrder(root);
           cout<<endl<<endl;
            break;
    case 7:
        root=st.rpn_to_tree(rePN,st);
           st.PostOrder(root);
           cout<<endl<<endl;
            break;
    case 8:
           cout<<"Thanks!"<<endl;
            exit(1);


    default:
            cout<<"Wrong choice!pick 1 through 8, please!"<<endl; break;
        }
    }while(choice !=0);



}

void getExpression(string& inputChar)
{
     cout << "Enter arithmetic Expression:  " << endl;
     getline(cin>>ws, inputChar);
     cout<<"Your input is: \n";
      for(int i=0;i<(int)inputChar.length();i++)
      {
          cout<<inputChar[i]<<" ";
      }
      cout<<endl<<endl;
}
void expression_to_RPN(string& inputChar, stack<char> s, vector<char> &rePN)
{
    s.push('#');

      for(int i=0;i<(int)inputChar.length();i++)
      {
          if(inputChar[i]=='(')
            {s.push(inputChar[i]);}
          else if(inputChar[i]==')')
          {
              while(s.top()!='(')
              {
                  rePN.push_back(s.top());
                  s.pop();
              }
              s.pop();

          }
          else if(inputChar[i]=='*'||inputChar[i]=='/')
          {
              for(int j=s.size();j>0;j--)
            {  if(s.top()=='('||s.top()=='+'||s.top()=='-'||s.top()=='#')
                  {
                      s.push(inputChar[i]); break;
                  }
               else if(s.top()=='*'||s.top()=='/')
               {
                  rePN.push_back(s.top());
                  s.pop();
               }
            }
          }
          else if(inputChar[i]=='+'||inputChar[i]=='-')
          {   for(int j=s.size();j>0;j--)
              {
                  if(s.top()=='('||s.top()=='#')
                   {
                       s.push(inputChar[i]);break;
                   }
                  else
                  {
                     rePN.push_back(s.top());
                    s.pop();

                  }
              }
          }
        else if(inputChar[i] !='\0')
        {  //cout<<"2"<<endl;
          rePN.push_back(inputChar[i]);
        }


      }
      while(!s.empty() && s.top()!='#')
      {
          rePN.push_back(s.top());
          cout<<s.top()<<"  ";
          s.pop();

      }

      cout<<"\nyour RPN is: \n";

       for(int i=0;i<(int)rePN.size();i++)
       {
           cout<<rePN[i]<<" ";
       }
         cout<<endl<<endl;
}
bool isOperator(char elem)
{
    if (elem == '+' || elem == '-' || elem == '*' || elem == '/')

         return true;

    else

        return false;

}
float evaluateRPN(vector<char> &rePN,stack<float> &sf)
{
    float result=0.00;  float digit=0.00,digit1=0.00,digit2=0.00;
   for(int i=0;i<(int)rePN.size();i++)
   {
       if(isdigit(rePN[i]))
       {   digit=(float)rePN[i]-'0';

           sf.push(digit);
       }

       if(isOperator(rePN[i]))
       {
         digit1=sf.top();
         cout<<"digit1 : "<<digit1<<endl;
         sf.pop();
         digit2=sf.top();
          cout<<"digit2 : "<<digit2<<endl;
         sf.pop();
         if(rePN[i]=='+')
         {
             result=digit1 + digit2;
             sf.push(result);
              cout<<"result+ : "<<result<<endl;
         }
         else if(rePN[i]=='-')
         {
             result=digit2 - digit1;
             sf.push(result);
             cout<<"result- : "<<result<<endl;
         }
         else if(rePN[i]=='*')
         {
             result=digit1 * digit2;
             sf.push(result);
             cout<<"result* : "<<result<<endl;
         }
         else if(rePN[i]=='/')
          {
                  if((int)digit1==0)
                  {
                       cout<<"Error!\n"; return -9999;
                  }
                 else
                {
                    result = digit2 / digit1;
                    sf.push(result);
                    cout<<"result / : "<<result<<endl;
                 }
          }
       }

   }
         return result;
}

// construct a binary tree from RPN notation


