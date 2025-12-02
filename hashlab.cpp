#include <bits/stdc++.h>
using namespace std;
struct Word
{
   int key;
   char val[100];
};
int hashing(int M, int key)
{
   if(M == 0) return 0;
   return key % M;
}
void initHash(vector <int> &H, int M)
{
   vector <int> K;
   for (int i = 0; i < M; i++)
   {
      cout<<"Nhap phan tu thu "<<i + 1<<" : ";
      int n;
      cin>>n;
      K.push_back(n);
   }
   H.resize(M); // Ensure H has size M
   for (int i = 0; i < M; i++)
      H[i] = 0;
   for (int i = 0; i < M; i++)
   {
      int pos = hashing(M, K[i]);
      while (H[pos] != 0)
         pos = (pos + 1) % M;
      H[pos] = K[i];
   }
}
/*void initHash(Word *&H, int M)
{
   Word K[5];
   K[0].key = 1;//MSSV
   strcpy(K[0].val, "Messsi");
   K[1].key = 3;
   strcpy(K[1].val, "RONALDO");
   K[2].key = 13;
   strcpy(K[2].val, "Neymar");
   K[3].key = 7;
   strcpy(K[3].val, "Pele");
   K[4].key = 9;
   strcpy(K[4].val, "Pobba");
   for (int i = 0; i < M; i++)
      H[i].key = 0;
   for (int i = 0; i < 5; i++)
   {
      int pos = hashing(M, K[i].key);
      H[pos] = K[i];
   }
}*/
int main()
{
   int M, key; cout<<"Enter num of element in hash table: "; cin>>M;

   vector <int> H;
   //int *H = new int[M];
   initHash(H, M);
   int pos = hashing(M, key);
   if(H[pos] != key) cout<<"khong tim thay\n";
   else cout<<"co thay\n";
/*
   Word *W = new Word[M];
   initHash(W, M);
   int pos2 = hashing(M, key);
   if (W[pos2].key == key) cout << W[pos2].val;
   else cout << "khong tim thay\n";*/
}