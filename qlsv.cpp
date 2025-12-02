#include "student.h"
int hashing(string name, int n)
{
   if (n == 0) return 0;
   int h = 0;
   for (char c : name)
      h += c;
   return h % n;
}
void initHashChain(int n, vector<Student> &studentList, vector<list<Student>> &hashtab)
{
   hashtab.assign(n, list<Student>());
   for (auto st : studentList)
   {
      int pos = hashing(st.getName(), n);
      hashtab[pos].push_back(st);
   }
}
void initHashLi(int n, vector <Student> &studentList)
{
   vector <Student> temp = studentList;
   studentList.assign(n, Student());
   for (auto st : temp)
   {
      int pos = hashing (st.getName(), n);
      while (!studentList[pos].getName().empty())
         pos = (pos + 1) % n;
      studentList[pos] = st;
   }
}
void initHashQuadratic(int n, vector <Student> &studentList)
{
   vector <Student> temp = studentList;
   studentList.assign(n, Student());
   for (auto st : temp)
   {
      int h = hashing (st.getName(), n);
      for (int i = 0; i < n; i++)
      {
         int pos = (h + i * i) % n;
         if (studentList[pos].getName().empty())
         {
            studentList[pos] = st;
            break;
         }
      }
   }
}
int search(vector<Student> studentList, string name)
{
   int pos = hashing(name, studentList.size());
   int start = pos;
   while (!studentList[pos].getName().empty())
   {
      if (studentList[pos].getName() == name)
         return pos;
      pos = (pos + 1) % studentList.size();
      if (pos == start) break;
   }
   return -1;
}
int main()
{
   int n;
   cout<<"Enter number of student: "; cin>> n;
   // hashtab linear
   vector <Student> studentList;
   Student s;
   s.inp(n, studentList);
   cout<<"\nHash table";
   s.print(studentList);

   string findName;
   cout<<"\nEnter name student u wanna find: ";
   cin.ignore();
   getline(cin, findName);

   // hashtab chaining voi 1 linkedList voi moi gia tri
   vector <list<Student>> hashTable;
   int found = search(studentList, findName);
   if (found != -1)
      cout<<"Information of student\n"<<studentList[found];
   else cout<<"Not found student\n";
}