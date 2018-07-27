//# data-structure
//threaded weighted Binary search tree
//Author :Chenghong Meng (parts of pseudocode came from prof.Keith Tookey)

#include <iostream>
#include<string>
#include<fstream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

class ItemType{
   private:  //declare class private members;
       string firstName;
       string lastName;
       string phone;
   public:
     ItemType(){};
     void InitialItem(string,string,string);
     string makelower(const string&);
     void SetFirstName(string fn){firstName = fn;};
     void SetLastName(string ln){lastName = ln;};
     string GetFirstName(void){return firstName;};
     string GetLastName(void){return lastName;};
     string GetFullName(void);
     string GetPhone(void){return phone;};
     void PrintItem(ofstream&) const;


};

void ItemType::InitialItem(string fn,string ln,string p)
{
    firstName = fn;
    lastName = ln;
    phone = p;
}
string ItemType::makelower(const string &np)
{
    int i;
    string temp(np);
    for(i=0;i<(int)np.length();i++)
    {
        temp[i]=tolower(np[i]);
    }
    return temp;
}
string ItemType::GetFullName()
{
    string fullName =  lastName + firstName ;
         return fullName;
}

void ItemType::PrintItem(ofstream& out) const
{
       out<<lastName<<","<<firstName<<endl;
       out<<phone<<endl;
       cout<<endl;
       cout<<lastName<<","<<firstName<<endl;
       cout<<phone<<endl;



}
struct TreeNode
{
  ItemType info;
  TreeNode *leftlink;
  TreeNode *rightlink;
  bool left_threaded;// mark if left link is thread or not;
  bool right_threaded;//mark if right link is thread or not;

};


 class ThreadedWBT
 {
private:
    double Alpha;

 public:

     TreeNode *TreeHead;
     vector<TreeNode*> vItem;
     ThreadedWBT();

    TreeNode* createNewNode(ItemType);
    bool isEmptyTree();
    int Bigness(TreeNode*);
    int weight(TreeNode*);
    bool heavyRight(TreeNode*);
    bool heavyLeft(TreeNode*);

    TreeNode* SingleRotationLeft(TreeNode*);
    TreeNode* SingleRotationRight(TreeNode*);
    TreeNode* DoubleRotationLeft(TreeNode*);
    TreeNode* DoubleRotationRight(TreeNode*);
    TreeNode* Rebalance(TreeNode*);
    void InsertNode(ItemType);
    bool isLeftChild(ItemType);
    TreeNode* FindParent(TreeNode*);
    TreeNode* InOrdPred(TreeNode*);
    TreeNode* InOrdSucc(TreeNode*);
    TreeNode* FindFirstInOrd(TreeNode*);
    TreeNode* FindLastInOrd(TreeNode*);
    void ListInOrdIterative(TreeNode*,ofstream &);
    void LookUpInOrdIterative(TreeNode*,string);
    char MarchUpItemIterative(TreeNode* ,string);
    TreeNode* choiceItem(TreeNode*,string );
    void RemoveNode(string);
    void writeBinaryTree(TreeNode *,ofstream&);
    void DisplayInOrder(TreeNode*);
    void ReadIteminfo(ifstream&);
    void WriteIteminfoToFile(TreeNode*);


};

ThreadedWBT::ThreadedWBT()
{
    ItemType item;
                               //initialize head node is the largest one;
    string firstName = "ZZZZZZZZZZZZZ";
    string lastName = "ZZZZZZZZZZZZZZ";
    string  phone ="9999999999999";
    item.InitialItem(firstName,lastName,phone);
    TreeHead = createNewNode(item);
    TreeHead->right_threaded = false;  //set head node right link not threaded
    TreeHead ->left_threaded = true;   //set head node left link threaded
    TreeHead->leftlink = TreeHead;
    TreeHead->rightlink = TreeHead;    // two children point to itself;
    }


 int ThreadedWBT:: Bigness(TreeNode* root)
 {
     if(root==TreeHead) return 0;
     else
        return weight(root);
 }
int ThreadedWBT::weight(TreeNode*root) //count the number of the nodes of root
{
       if( root->left_threaded && root->right_threaded)
       {
          return 1;
       }
       else if (root->left_threaded)
       {
           return weight(root->rightlink)+1;
       }
      else if(root->right_threaded)
        { 
          return weight(root->leftlink)+1;
        }
       else
       {
           return weight(root->leftlink)+ weight(root->rightlink)+1;
       }


}
bool ThreadedWBT::heavyRight(TreeNode* root)
{   Alpha= 0.237;

    if(root==TreeHead) return false;
    
    else if (Bigness(root->leftlink)< Alpha*Bigness(root))
    {
        return true;
    }

    else
    {
        return false;
    }


}
bool ThreadedWBT::heavyLeft(TreeNode* root)
{   Alpha = 0.237;
    if(root==TreeHead) return false;
    else if (Bigness(root->rightlink)< Alpha*Bigness(root))
      {
          return true;
      }
    else
    {
        return false;
    }


}
TreeNode* ThreadedWBT::Rebalance(TreeNode*root)
{
 
    if(root==TreeHead)
    {   
        return root;
    }
    else if(heavyRight(root))
    {
        if(heavyLeft(root->rightlink))
          {
             root =  DoubleRotationLeft(root);
            
             return root;
          }
        else

            { 
               root =  SingleRotationLeft(root);
               return root;
            }
    }
    else if(heavyLeft(root))
    { 

        if(heavyRight(root->leftlink))
        { 

            root =   DoubleRotationRight(root);
            return root;
        }

        else
            { 
               root =   SingleRotationRight(root);
               return root;
            }
    }
    else
       {
          
            return root;
       }
}
TreeNode* ThreadedWBT::SingleRotationLeft(TreeNode* root)
{
    TreeNode *Top, *Pivot, *Orphan;
    Top = root;
    Pivot = root->rightlink;
     
     if(Pivot->left_threaded)
     {    
          Pivot->leftlink = Top;
          Pivot->left_threaded = false;
          Top->rightlink = Pivot;
          Top->right_threaded = true;
          root = Pivot;
          
          return root;
     }
     else
     {

        Orphan = Pivot->leftlink;
        Top->rightlink = Orphan;
        Pivot->leftlink = Top;
        root = Pivot;

        return root;

     }




}
TreeNode* ThreadedWBT::SingleRotationRight(TreeNode* root)
{
    TreeNode *Top, *Pivot, *Orphan;
    Top = root;
    Pivot = root->leftlink;
    
    if(Pivot->right_threaded)
    {
        Pivot->rightlink = Top;
        Pivot->right_threaded = false;
        Top->leftlink = Pivot;
        Top->left_threaded = true;
        root = Pivot;
        
        return root;

    }
    else
    {
       Orphan = Pivot->rightlink;
       Top->leftlink = Orphan;
       Pivot->rightlink = Top;
       root = Pivot;
       
       return root;

    }

}

TreeNode* ThreadedWBT::DoubleRotationLeft(TreeNode* root)
{
    root->rightlink = SingleRotationRight(root->rightlink);
               root = SingleRotationLeft(root);
    return root;
}
TreeNode* ThreadedWBT::DoubleRotationRight(TreeNode* root)
{
    root->leftlink = SingleRotationLeft(root->leftlink);
              root = SingleRotationRight(root);
    return root;
}
TreeNode*  ThreadedWBT:: createNewNode(ItemType item)
{
        TreeNode* itemNode = new TreeNode;
        itemNode->info = item;
        itemNode->leftlink = NULL;
        itemNode->rightlink = NULL;

        return itemNode;
}

void ThreadedWBT::InsertNode(ItemType item)
{
    TreeNode* follow, *find, *parent;

        follow = TreeHead;
        find = TreeHead->leftlink;
        string str_item = item.makelower(item.GetFullName());

        while(find!=TreeHead)
        {
             string str_find = find->info.makelower(find->info.GetFullName());
             
            if(str_item < str_find)
            {
                follow = find;
                if(find->left_threaded) break;
                find = find ->leftlink;

            }
            else
            {
                 follow = find;
                 if(find->right_threaded) break;
                 find = find->rightlink;

             }

         }

            parent = follow;
            string  str_parent = parent->info.makelower(parent->info.GetFullName());
            TreeNode* newNode = createNewNode(item);
            newNode->left_threaded = newNode->right_threaded = true;

            if(str_item<str_parent)  //insert to left side;
               {
                   newNode->rightlink = parent;
                   newNode->leftlink = parent ->leftlink;
                   parent->leftlink = newNode;
                   parent ->left_threaded = false;

               }


            else   // insert to right side;
            {
                newNode->rightlink = parent ->rightlink;
                newNode ->leftlink = parent;
                parent->rightlink = newNode;
                parent ->right_threaded = false;

            }


       // before rebalancing the tree, check the size of root;
         if(weight(TreeHead->leftlink)>=5)
           {
               TreeHead->leftlink = Rebalance(TreeHead->leftlink);

           }
}

TreeNode* ThreadedWBT::FindParent(TreeNode* root)
{
  TreeNode* Find;

  if(root==TreeHead->leftlink)   //if the tree has only one Node, its parent is the tree head;
  {
     return TreeHead;
  }
 else//else, there are 4 case to discuss;
  {
     if(isLeftChild(root->info))   //1.if this node is left child;
   {
      if(root->right_threaded)   //and,2. if it is right_threaded or not;
      {
          Find = InOrdSucc(root);
          return Find;
      }
      else
      {
          Find = root->rightlink;
          while(!root->right_threaded)
          {
              Find = Find->rightlink;
          }
          return Find;
      }

  }
  else    //3.if this node is right child;
  {
      if(root->left_threaded)   //and,4. if it is left_threaded or not;
      {
          Find = InOrdPred(root);
          return Find;
      }
      else
      {
          Find = root->leftlink;
          while(!root->left_threaded)
          {
              Find =  Find->leftlink;
          }
          return Find;
      }
   }
 }

}

//if there are many items with "partialName" were found, choose one of them to delete
TreeNode* ThreadedWBT::choiceItem(TreeNode* root,string partialName)
{     TreeNode* returnNode;          int selection;

         cout<<"\nWhich one you really want? \n Please select digit: ";
         cout<<endl;

         //display all items with "partialName"
        for(int i=0;i<(int)vItem.size();i++)
        {
            cout<<i<<"->"<<vItem[i]->info.GetLastName()<<","<<vItem[i]->info.GetFirstName()<<endl;

        }
        cin>>selection;
        for(int i=0;i<(int)vItem.size();i++)    //choose one of items with "partialName" to delete
        {
           if(selection==i)
           {
            returnNode= vItem[i];
             break;
           }
        }
         return returnNode;

}
bool ThreadedWBT::isLeftChild(ItemType item)
{  
    TreeNode* find, *parent;
    string str_find, str_parent, str_item;
    find = TreeHead->leftlink;
    parent = TreeHead;
 
    str_item = item.makelower(item.GetFullName());
    str_find = find->info.makelower(find->info.GetFullName());

     while( str_item != str_find )
        { 
            if(str_item< str_find)
               {
                 
                   if( find ->left_threaded) break;
                   parent = find;
                   find = find->leftlink;
                   str_find = find->info.makelower(find->info.GetFullName());
               }
            else if(str_item> str_find)
               { 
                   if( find ->right_threaded) break;
                   parent = find;
                   find = find->rightlink;
                   str_find = find->info.makelower(find->info.GetFullName());
               }
        }


         str_parent = parent->info.makelower(parent->info.GetFullName());

        if(str_item<str_parent)
                 {
                   return true;
                 }

              else
                 {
                   return false;
                 }

}
void ThreadedWBT::RemoveNode(string partialName)
{
        TreeNode*  find, *parent, *substitute, *fosterparent,* find_pre,*find_suc ;
        ofstream out;
        find = TreeHead->leftlink;
        substitute =NULL; fosterparent = NULL;
        parent = TreeHead;
        char yOn = MarchUpItemIterative( TreeHead,partialName);    //if item found, 'y' was return;
     if(yOn=='y')   //item found!
     {

         TreeNode* returnNode= choiceItem(TreeHead,partialName);
         string str_item = returnNode->info.makelower(returnNode->info.GetFullName());
         string str_find = find->info.makelower(find->info.GetFullName());

         while( str_item != str_find )
        {
            if(str_item< str_find)
               {   if( find ->left_threaded) break;
                   parent = find;
                   find = find->leftlink;
                   str_find = find->info.makelower(find->info.GetFullName());
               }
            else if(str_item> str_find)
               {
                   if( find ->right_threaded) break;
                   parent = find;
                   find = find->rightlink;
                   str_find = find->info.makelower(find->info.GetFullName());
               }
        }

        if( find ==TreeHead)
        {
            cout<< "Sorry! No Found Item!"<<endl;

            return ;
        }
        else
        {
            cout<<"Are you sure to remove it? y/n\n";
            char yORn;
            cin>>yORn;
          if(yORn=='y')
           {    bool isLeftChild;
                string str_parent = parent->info.makelower(parent->info.GetFullName());

              if(str_item<str_parent)
                 {

                     isLeftChild = true;
                 }

              else
                 {
                     isLeftChild = false;
                 }

            //both threaded;"find" has no children;
             if(find->left_threaded && find->right_threaded)
           {
            
              if(isLeftChild)
              {
                  parent->leftlink = find->leftlink;
                  parent->left_threaded = true;
                  free(find);

              }
              else  //find is right child without children;
                { 
                   parent->rightlink = find->rightlink;
                   parent->right_threaded = true;
                   free(find);                 

                }
           }
           // find is right threaded; has left child;
           else if(find->right_threaded)
           { 
              if(isLeftChild)//find is left child having left child;
              {  
                  parent->leftlink = find->leftlink;
                  find_pre = InOrdPred(find);
                  find_pre->rightlink = find->rightlink;
                  free(find);

              }

              else//find is right child having left child;
              {  
                  parent->rightlink = find->leftlink;
                  find_pre = InOrdPred(find);
                  find_pre->rightlink = find->rightlink;
                  free(find);
              }


            }
            //"find" has right children;
           else if(find->left_threaded)
            {
              
              if(isLeftChild) //find is left child having right child;
               { 
                   parent->leftlink = find->rightlink;
                   find->rightlink->leftlink = find->leftlink;
                   free(find);

               }
              else  //find is right child having right child;
              { 
                   parent->rightlink = find ->rightlink;
                   find->rightlink->leftlink = find->leftlink;
                   free(find);

              }
            }
            // "find" have two children;
            else
            { 
                if(isLeftChild)
                { 

                    if(find->leftlink->right_threaded)//find's left child without right child;
                    {  
                       parent->leftlink = find->leftlink;
                       find->leftlink->rightlink = find->rightlink;
                       find->leftlink->right_threaded = false;
                       find_suc = InOrdSucc(find);
                       find_suc->leftlink = find->leftlink;
                       free(find);

                    }
                    else
                    { 
                        find_pre = InOrdPred(find);
                        TreeNode*find_pre_pre = InOrdPred(find_pre);

                        if(find_pre->left_threaded)
                        {  
                            find->info = find_pre->info;
                            find_pre_pre->rightlink = find;
                            find_pre_pre->right_threaded = true;
                            free(find_pre);

                        }
                        else
                        {  
                            TreeNode* find_pre_pre = InOrdPred(find_pre);
                            TreeNode* find_pre_parent = FindParent(find_pre);                     
                            find->info = find_pre->info;
                            find_pre_parent->rightlink = find_pre->leftlink;
                            find_pre_pre->rightlink = find_pre ->rightlink;
                            free(find_pre);

                        }
                    }
                }
                else    //find has two children and it is right child;
                { 
                    if(find->rightlink->left_threaded)
                    { 
                        find_pre = InOrdPred(find);
                        find->rightlink->leftlink = find->leftlink;
                        find->rightlink->left_threaded = false;
                        parent->rightlink = find->rightlink;
                        find_pre->rightlink = parent->rightlink;
                        free(find);

                    }
                    else
                    {  
                         if(find->leftlink->right_threaded)//find's left child without right child;
                       { 
                        parent->leftlink = find->leftlink;
                        find->leftlink->rightlink = find->rightlink;
                        find->leftlink->right_threaded = false;
                        find_suc = InOrdSucc(find);
                        find_suc->leftlink = find->leftlink;
                        free(find);
                       }
                      else
                       {
                           find_pre = InOrdPred(find);
                           TreeNode*find_pre_parent = FindParent(find_pre);

                           if(find_pre->left_threaded)
                           {
                            find->info = find_pre->info;
                            find_pre_parent->rightlink = find;
                            find_pre_parent->right_threaded = true;
                            free(find_pre);

                            }
                           else
                          { 
                            TreeNode* find_pre_pre = InOrdPred(find_pre);
                            find->info = find_pre->info;
                            find_pre_parent->rightlink = find_pre->leftlink;
                            find_pre_pre->rightlink = find_pre ->rightlink;
                            free(find_pre);
                           }
                       }
                    }
                }

       }
       vItem.clear();
      
         if(weight(TreeHead->leftlink)>=4)
             TreeHead->leftlink = Rebalance(TreeHead->leftlink);
         cout<<"\nItem was deleted!"<<endl;
         cout<<"\n  Tree List  \n";
         cout<<"------------------";
         WriteIteminfoToFile(TreeHead);
       }

        else
       {
          vItem.clear();
           return ;
       }
    }
 }
}
bool ThreadedWBT::isEmptyTree()
{
        TreeNode* find = TreeHead->leftlink;
        if(find->left_threaded && find->right_threaded)
            return true;
        else
            return false;
}


TreeNode* ThreadedWBT::InOrdPred(TreeNode* root)
{  TreeNode* Pred;

    if(root->left_threaded)
        return root->leftlink;
    else
        Pred = root->leftlink;
        while(! Pred->right_threaded)
        Pred = Pred->rightlink;
        return Pred;

}
TreeNode* ThreadedWBT::InOrdSucc(TreeNode* root)
{   TreeNode* Pred;

    if(root->right_threaded)
    return root->rightlink;

    else
        Pred = root->rightlink;
    while(! Pred->left_threaded)
        Pred = Pred->leftlink;
    return Pred;

}
TreeNode* ThreadedWBT::FindFirstInOrd(TreeNode* root)
{
    TreeNode* First = root;
    while(!First->left_threaded)
        First = First->leftlink;
    return First;

}
TreeNode* ThreadedWBT::FindLastInOrd(TreeNode* root)
{
    TreeNode* Last = root;
    while(!Last->right_threaded)
        Last = Last->rightlink;
    return Last;

}
void ThreadedWBT::ListInOrdIterative(TreeNode* root,ofstream &out)
{
     TreeNode* p = root->leftlink;
  TreeNode* First = FindFirstInOrd(p);
  TreeNode* Last = FindLastInOrd(p);
  TreeNode* Node = First;

  Node->info.PrintItem(out);
  cout<<"weight is: "<<weight(First)<<endl;;
  while(Node != Last)
  {
      Node = InOrdSucc(Node);
      Node->info.PrintItem(out);
       cout<<"weight is: "<<weight(Node)<<endl;
  }

}
char ThreadedWBT::MarchUpItemIterative(TreeNode* root,string partialName)
{     ItemType item; ofstream out;    int num;

   int pre = (int)vItem.size();
     TreeNode* p = root->leftlink;

    TreeNode* First = FindFirstInOrd(p);
    TreeNode* Last = FindLastInOrd(p);
    TreeNode* Node = First;
    if(Node->info.makelower(Node->info.GetFullName()).find(item.makelower(partialName)) !=string::npos)
       {
           Node->info.PrintItem(out);
          vItem.push_back(Node);
       }

    while(Node!=Last)
      {
          Node = InOrdSucc(Node);
          if(Node->info.makelower(Node->info.GetFullName()).find(item.makelower(partialName)) !=string::npos)
         {

             Node->info.PrintItem(out);
            vItem.push_back(Node);
         }

      }
    int post = (int)vItem.size();

    num = post-pre;


   if(num==0)
    {
       cout<<"\nNone!"<<endl;
       return 'n';
    }
    else
        return 'y';

}
void ThreadedWBT::LookUpInOrdIterative(TreeNode* root,string partialName)
{  ItemType item; ofstream out;    int flag=0;
     TreeNode* p = root->leftlink;

    TreeNode* First = FindFirstInOrd(p);
    TreeNode* Last = FindLastInOrd(p);
    TreeNode* Node = First;
    if(Node->info.makelower(Node->info.GetFullName()).find(item.makelower(partialName)) !=string::npos)
       {  flag++;
           Node->info.PrintItem(out);

       }

    while(Node!=Last)
      {
          Node = InOrdSucc(Node);
          if(Node->info.makelower(Node->info.GetFullName()).find(item.makelower(partialName)) !=string::npos)
         {
            flag++;
             Node->info.PrintItem(out);
         }

      }

   if(flag==0)
    {
        cout<<"\nNone!"<<endl;

    }




}
void ThreadedWBT::WriteIteminfoToFile(TreeNode * root)
    {
        ofstream out("tree9out.txt");
        if(out.is_open())
        {

         ListInOrdIterative(root,out);

       }
        out.close();

    }
void ThreadedWBT::writeBinaryTree(TreeNode * root,ofstream& out)
{
  if(root!=TreeHead)
    {
     writeBinaryTree(root->leftlink,out);

        root->info.PrintItem(out);

    writeBinaryTree(root->rightlink,out);
   
  }
}



void ThreadedWBT::ReadIteminfo(ifstream& in)
{     in.open("tree9out.txt");

      string firstName;
      string lastName;
      string phone;
      ItemType item;
    if(in.is_open())
   {  cout<<"Ready to read!\n";
    for(;;)
    {
        getline(in>>ws,firstName,',');
        getline(in>>ws,lastName,'\n');
        getline(in>>ws,phone,'\n');
        if(in.good())
       {
        item.InitialItem(firstName,lastName,phone);
        InsertNode(item);
       }
        else if(in.eof()) break;
        else
       {
        in.clear();
           string temp;
           getline(in,temp);
           cout<<temp<<"--"<<"what happen to this .txt?"<<endl;
       }
     }
   }
   in.close();
}
void ThreadedWBT::DisplayInOrder(TreeNode* Node )
{ ofstream out;
      if(Node ->left_threaded && Node->right_threaded)
      {  
         Node->info.PrintItem(out);
         cout<<"--\nWeight is:  "<<weight(Node)<<endl;
          return ;
      }
      else if(Node->left_threaded)
    {
       DisplayInOrder(Node->rightlink);

    }
    else if(Node->right_threaded)
    {
       
         DisplayInOrder(Node->leftlink);
    }

     Node->info.PrintItem(out);
    cout<<"--\nWeight is:  "<<weight(Node)<<endl;

}


int main()
{    int count=0;
     int choice;
     string fn,ln,p,partialName;
     ItemType item;
     ofstream out;
     ifstream in;
     char yOrn;
     ThreadedWBT wbt;
     TreeNode* root,*n,*n_parent;
     TreeNode* header = wbt.TreeHead;



    do
    {   cout<<"-------------------"<<endl;
        cout<<"\t\nThreadedWBT List:\n"<<endl;
        cout<<"1.InsertItem"<<endl;
        cout<<"2.ReadItemFromFile"<<endl;
        cout<<"3.ListItem"<<endl;
        cout<<"4.LookupItem"<<endl;
        cout<<"5.FindParentItem"<<endl;
        cout<<"6.DeleteItem"<<endl;
        cout<<"7.Quit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
    case 1:
              cout<<"Enter the item first name : \n";
              getline(cin>>ws,fn,'\n');
              cout<<"Enter the item last name : \n";
              getline(cin>>ws,ln,'\n');
              cout<<"Enter the item phone:\n";
              cin>>p;
              item.InitialItem(fn,ln,p);
              wbt.InsertNode(item);

              wbt.WriteIteminfoToFile(header);// every data type_in then output file;
            
              cout<<endl;
              break;
    case 2:      //read data from file, and insert to tree
              wbt.ReadIteminfo(in) ;

              cout<<"Done! Please list them out!"<<endl;
              break;

    case 3:

             if(wbt.isEmptyTree())
             cout<<"Empty Tree!"<<endl;
             cout<<"\n  Tree List  \n";
             cout<<"-----------------\n";
             wbt.ListInOrdIterative(wbt.TreeHead,out);
             break;

    case 4:
             cout<<"Enter the item you would like to get:\n";
             getline(cin>>ws,partialName,'\n');

            cout<<"Item with  ( "<<partialName<<" ) are:  "<< endl;
             wbt.LookUpInOrdIterative(wbt.TreeHead, partialName);

             cout<<endl;
             break;
    case 5:
             cout<<"Enter the item you would like to get:\n";
             getline(cin>>ws,partialName,'\n');
             yOrn = wbt.MarchUpItemIterative(wbt.TreeHead,partialName);
             if(yOrn =='y')
             {
                 n=wbt.choiceItem(wbt.TreeHead, partialName);
             }
            cout<<"Your parent is : "<<endl;
             n_parent = wbt.FindParent(n);
            n_parent->info.PrintItem(out);
            wbt.vItem.clear();
            break;

    case 6:
             cout<<"Enter the item you would like to delete: \n";
             getline(cin>>ws,partialName,'\n');
             wbt.RemoveNode(partialName);
             break;

   case 7:
             cout<<"Thanks!"<<endl;
             exit(1);
             break;
    default:
            cout<<"Wrong choice!pick 1 through 6, please!"<<endl; break;
        }
    }while(choice !=0);
     return 0;

}
