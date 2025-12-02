#include <bits/stdc++.h>
#include <string>
using namespace std;
class Student
{
private:
   string id, name, phoneNum, gmail;

public:
   Student()
   {
      id = "";
      name = "";
      phoneNum = "";
      gmail = "";
   }
   Student(string _id, string _name, string pn, string _gmail)
   {
      id = _id;
      name = _name;
      phoneNum = pn;
      gmail = _gmail;
   }
   string getID() { return id; }
   string getName() { return name; }
   string getPN() { return phoneNum; }
   string getMail() { return gmail; }
   void setID(string _id) { id = _id; }
   void setName(string _name) { name = _name; }
   void setPN(string pn) { phoneNum = pn; }
   void setMail(string _gmail) { gmail = _gmail; }
   friend istream &operator>>(istream &in, Student &s)
   {
      cout<<"Enter ID student: "; in>>s.id;
      in.ignore();
      cout << "Enter student name: "; getline(in, s.name);
      cout<<"Enter student phone number: "; in>>s.phoneNum;
      cout<<"Enter student gmail: "; in>>s.gmail;
      return in;
   }
   friend ostream &operator<<(ostream &out, const Student &s)
   {
      out<<"ID student: "<<s.id
         << "\nStudent name: "<<s.name
         <<"\nStudent phone number: "<<s.phoneNum
         <<"\nStudent gmail: "<<s.gmail;
      return out;
   }
   void inp(int n, vector <Student> & list)
   {
      for (int i = 0; i < n; i++)
      {
         cout<<"\nEnter infomation of student "<< i+1 <<"\n";
         Student s; cin>>s;
         list.push_back(s);
      }
   }
   void print(vector<Student> list)
   {
      for (int i = 0; i < list.size(); i++)
      {
         cout<<"\nFULL information of student "<< i + 1<< "\n";
         cout<<list[i];
      }
   }
};