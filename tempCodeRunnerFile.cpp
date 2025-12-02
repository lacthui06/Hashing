int main()
{
   hashMapLinear hm;
   hm.insert("Anh Lac", "001", "thui@gmail.com");
   hm.insert("Kiet Pham", "002", "do@gmail.com");
   hm.insert("Ahn Lca", "003", "tron@gmail.com");
   hm.insert("Khanh Linh", "004", "chum@gmail.com");

   cout << " === HASH TABLE ===\n";
   hm.display();

   cout << "Insert duplicate id (Dang Khoi - 002) -> "
        << (hm.insert("Dang Khoi", "002", "tiu@gmail.com") ? "OK\n" : "FAILED (duplicate id)\n");
}