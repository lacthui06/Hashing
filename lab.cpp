#include <bits/stdc++.h>
using namespace std;
struct Node
{
   string name, id, gmail;
   Node *next;
   Node(string _name = "", string _id = "", string _gmail = "")
       : name(_name), id(_id), gmail(_gmail), next(NULL) {}
};

struct Word
{
   string name, id, gmail;
   Word(string _name = "", string _id = "", string _gmail = "")
       : name(_name), gmail(_gmail), id(_id) {}
};

// =============== CHAINING PROB =====================
class hashMapChain
{
private:
   int M;
   Node **table;
   int hashing(int M, string _name)
   {
      if (M == 0) return 0;
      int sum = 0;
      for (auto ch : _name)
         sum += ch;
      return sum % M;
   }
public:
   hashMapChain(int m = 10) : M(m)
   {
      table = new Node *[m];
      for (int i = 0; i < m; i++)
         table[i] = NULL;
   }
   bool insert(string _name, string _id, string _gmail)
   {
      int pos = hashing(M, _name);
      for (int i = 0; i < M; i++)
      {
         for (Node *p = table[i]; p != NULL; p= p->next)
         {
            if (p->id == _id) return false;
         }
      }
      Node *n = new Node(_name, _id, _gmail);
      n->next = table[pos];
      table[pos] = n; 
      return true;
   }
   void display()
   {
      for (int i = 0; i < M; i++)
      {
         cout << i << " : ";
         for (Node *p = table[i]; p != NULL; p = p->next)
            cout << p->name <<" : "<<p->id <<" : "<< p->gmail << " -> ";
         cout << "Null\n";
      }
   }
   void search(string _name)
   {
      int pos = hashing(M, _name);
      for (Node *p = table[pos]; p != NULL; p = p->next)
      {
         if (p->name == _name)
            cout << p->name << " : " << p->id << " : " << p->gmail<< endl;
      }
   }
};

// =============== LINEAR PROB =====================
class hashMapLinear
{
private:
   int M;
   vector <Word> table;
   int hashing(int M, string _name)
   {
      if (M == 0)
         return 0;
      int sum = 0;
      for (auto ch : _name)
         sum += ch;
      return sum % M;
   }
public:
   hashMapLinear(int m = 10) : M(m)
   {
      table.resize(m);
   }
   bool insert(string _name, string _id, string _gmail)
   {
      for (int i = 0; i < M; i++)
      {
         if (table[i].id == _id) return false;
      }
      int pos = hashing(M, _name);
      for (int i = 0; i < M; i++)
      {
         pos = (pos + i) % M;
         if (table[pos].id == "")
         {
            table[pos] = Word(_name, _id, _gmail);
            return true;
         }
      }
      return false;
   }

   void display()
   {
      for (int i = 0; i < M; i++)
      {
         if (table[i].id == "")
            cout << i << " : [empty]\n";
         else
            cout << i << " : " << table[i].name
            << " : " << table[i].id <<" : "<<table[i].gmail << "\n";
      }
   }
   bool search(string _name)
   {
      int start = hashing(M, _name);
      for (int i = 0; i < M; i++)
      {
         int pos = (start + i) % M;
         if (table[pos].id == "")
            return false;
         if (table[pos].name == _name)
         {
            cout << pos << " : "
                 << table[pos].name << " : "
                 << table[pos].id << " : "
                 << table[pos].gmail << "\n";
            return true;
         }
      }
      return false;
   }
};

// =============== QUADRATIC PROB =====================
class hashMapQuadratic
{
private:
   int M;
   vector <Word> table;
   int hashing(int M, string _name)
   {
      if (M == 0)
         return 0;
      int sum = 0;
      for (auto ch : _name)
         sum += ch;
      return sum % M;
   }
public:
   hashMapQuadratic(int m = 10) : M(m)
   {
      table.resize(m);
   }
   bool insert(string _name, string _id, string _gmail)
   {
      for (int i = 0; i < M; i++)
      {
         if (table[i].id == _id) return false;
      }
      int pos = hashing(M, _name);
      for (int i = 0; i < M; i++)
      {
         pos = (pos + i * i) % M;
         if (table[pos].id == "")
         {
            table[pos] = Word(_name, _id, _gmail);
            return true;
         }
      }
      return false;
   }
   void display()
   {
      for (int i = 0; i < M; i++)
      {
         if (table[i].id == "")
            cout << i << " : [empty]\n";
         else
            cout << i << " : " << table[i].name << " : " << table[i].id <<" : "<<table[i].gmail<< "\n";
      }
   }
   bool search(string _name)
   {
      int start = hashing(M, _name);
      for (int i = 0; i < M; i++)
      {
         int pos = (start + i) % M;
         if (table[pos].id == "")
            return false;
         if (table[pos].name == _name)
         {
            cout << pos << " : "
                 << table[pos].name << " : "
                 << table[pos].id << " : "
                 << table[pos].gmail << "\n";
            return true;
         }
      }
      return false;
   }
};

int main()
{
   hashMapQuadratic hm;
   hm.insert("Anh Lac", "001", "thui@gmail.com");
   hm.insert("Kiet Pham", "002", "do@gmail.com");
   hm.insert("Ahn Lca", "003", "tron@gmail.com");
   hm.insert("Khanh Linh", "004", "chum@gmail.com");

   cout << " === HASH TABLE ===\n";
   hm.display();

   cout << "Insert duplicate id (Dang Khoi - 002) -> "
        << (hm.insert("Dang Khoi", "002", "tiu@gmail.com") ? "OK\n" : "FAILED (duplicate id)\n");
}