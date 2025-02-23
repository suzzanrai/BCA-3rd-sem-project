    detail temp;
    int acnum;
    bool ismatch = false;
   cout << "Entere Bank Accoutn Number:";
   cin >> acnum;

   fstream file;
   file.open("accounts.txt", ios:: out);
   if (!file)
   {
        cout << "File Not Open.."<<endl;
        return;
   }
   fstream temp_file;
   temp_file.open("temp_accounts.txt",ios ::in );
   if (!file)
   {
    cout << "File Not Open.."<<endl;
    return;
   }
   while( file >> temp.name >> temp.accountNumber >> temp.accountType >> temp.balance)
   {
    if (temp.accountNumber == acnum)
    {
        ismatch = true;
        cout << " Account Found and Deleted..!"<<endl;
        continue;
    }
    temp_file << temp.name << temp.accountNumber << temp.accountType << temp.balance;
   }
   file.close();
   temp_file.close();
   if (!ismatch)
   {
    remove ("temp_accounts.txt");
    return;
   }
   remove("temp_accounts.txt");
   rename("temp_accounts.txt","accounts.txt");

   cout<< "Account Delete Successfully";
