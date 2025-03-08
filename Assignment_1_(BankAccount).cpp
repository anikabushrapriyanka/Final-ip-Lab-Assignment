#include<iostream>
using namespace std;
 
class Account
{
    private:
        string accountName;
        string accountNo;
        double acountBalance;
        string accountType;
    
    public: Account() {} //Constructor
    
    public: Account(string name, string num, int balance, string type)
    {
        accountName = name;
        accountNo = num;
        acountBalance = balance;
        accountType = type;
    }
    
    public: void setAccountName(string name) { // Setter
        accountName = name;
    }
    
    public: string getAccountName() { // Getter
       return accountName;
    }
    
    public: void setBalance(float balance) {
      acountBalance = balance;
    }
 
    public: int getBalance() {
      return acountBalance;
    }
    
    void Deposit(int amount)
    {
       acountBalance = acountBalance + amount;
       cout << amount << "tk credited \n";
    }
    
    void withdraw(int amount)
    {
       if (acountBalance > amount) {
            acountBalance = acountBalance - amount;
            cout << amount << "tk debited \n";
        }
        else{
            cout <<"\n Insufficiant Balance";
        }
    }
    
    void ShowAccountDetail()
    {
       cout << "Account Name is: " << accountName << "\n";
       cout << "Account Number is: " << accountNo << "\n";
       cout << "Account Balance is: " << acountBalance << "\n";
       cout << "Account Type is: " << accountType << "\n";
       cout << "\n";
    }
    
    void transfer(int amount, Account &account)
    {
        if (acountBalance > amount) {
           acountBalance = acountBalance - amount;
 
            cout << "Amount tk "<< amount <<" debited\n";
            
            float total = account.acountBalance + amount;
            account.setBalance(total);
        }
        else{
            cout <<"\n Insufficiant Balance";
        }
    }
    
    ~Account() {}
};
 
 
int main(){ 
    Account acc1(“Anika Bushra", "21833452001", 1000, "salary");
    Account acc2("Priyanka Azmain", "21400452701", 100, "savings");
  
    acc1.ShowAccountDetail();
    acc2.ShowAccountDetail();
    
    acc2.Deposit(500);
    acc2.ShowAccountDetail();
    
    acc1.withdraw(200);
    acc1.ShowAccountDetail();
 
    acc1.transfer(50, acc2);
    acc1.ShowAccountDetail();
    acc2.ShowAccountDetail();
    
    return 0;
}