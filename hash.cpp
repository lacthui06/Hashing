#include <bits/stdc++.h>
using namespace std;
struct Node 
{
   int key;
   Node *next;
   Node(int v)
   : key(v), next(NULL){}
};
class hashMapChain
{
private:
   int M;
   Node **table;
   int hashing(int M, int key)
   {
      return (M == 0) ? 0 : (key % M);
   }
public:
   hashMapChain(int m = 10) : M(m)
   {
      table = new Node *[m];
      for (int i = 0; i < m; i++)
         table[i] = NULL;
   }
   bool insert(int val)
   {
      int pos = hashing (M, val);
      for (Node *p = table[pos]; p != NULL; p= p->next)
         if (p->key == val) return false;
      Node *n = new Node (val);
      n->next = table[pos];
      table[pos] = n;
      return true;
   }
   void display()
   {
      for (int i = 0; i < M; i++)
      {
         cout<<i <<" : ";
         for (Node *p = table[i]; p != NULL; p= p->next)
            cout<<p->key<< " -> ";
         cout<<"Null\n";
      }
   }
   bool search(int val)
   {
      int pos = hashing (M, val);
      for (Node *p = table[pos]; p != NULL; p = p->next)
      {
         if (p->key == val) return true;
      }
      return false;
   }
};
class hashMapLinear
{
private:
   int M;
   vector <int> table;
   int hashing(int M, int key)
   {
      return (M == 0) ? 0 : (key % M);
   }
public:
   hashMapLinear(int m = 10) : M(m)
   {
      table.resize(m);
      for (int i = 0; i < m; i++)
         table[i] = 0;
   }
   bool insert(int val)
   {
      int start = hashing (M, val);
      int pos = start;
      for (int  i = 0; i < M; i++)
      {
         if (table[pos] == val) return false;
         else if (table[pos] != 0) 
            pos = (start + i) % M;
         else 
         {
            table[pos] = val;
            return true;
         }
      }
      return false;
   }
   void display()
   {
      for (int i = 0; i < M; i++)  cout<<i <<" : "<<table[i]<<endl;
   }
   bool search(int val)
   {
      for (int i = 0; i < M; i++)
      {
         if(table[i] == val) return true;
      }
      return false;
   }
};
class hashMapQuadratic
{
private:
   int M;
   vector <int> table;
   int hashing(int M, int key)
   {
      return (M == 0) ? 0 : (key % M);
   }
public:
   hashMapQuadratic(int m = 10) : M(m)
   {
      table.resize(m);
      for (int i = 0; i < m; i++)
         table[i] = 0;
   }
   bool insert(int val)
   {
      int start = hashing (M, val);
      for (int i = 0; i < M; i++)
      {
         int pos = (start + i * i) % M;
         if (table[pos] == 0)
         {
            table[pos] = val;
            return true;
         }
         else if (table[pos] == val) return false;
      }
      return false;
   }
   void display()
   {
      for (int i = 0; i < M; i++)  cout<<i <<" : "<<table[i]<<endl;
   }
   bool search(int val)
   {
      for (int i = 0; i < M; i++)
      {
         if(table[i] == val) return true;
      }
      return false;
   }
};
int main()
{
   hashMapChain hm(11);
   hm.insert(10);
   hm.insert(22);
   hm.insert(31);
   hm.insert(4);
   hm.insert(15);
   hm.insert(28);
   hm.insert(17);
   hm.insert(88);
   hm.insert(59);
   cout<<"Nhap phan tu tim kiem: "; int n; cin>> n;
   bool found = hm.search(n);
   if (found) cout<<n << " exist in table\n";
   else cout<<n<<" doesn't exist\n";
   hm.display();
}