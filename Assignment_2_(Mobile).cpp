#include <iostream>
#include <string>
using namespace std;
 
class Mobile {
private:
    string mobileOwnerName;
    string mobileNumber;
    double mobileBalance;
    string mobileOSName;
    bool lockStatus;
 
public:
    Mobile() {}
 
    Mobile(string ownerName, string number, double balance, string osName, bool isLocked) {
        mobileOwnerName = ownerName;
        mobileNumber = number;
        mobileBalance = balance;
        mobileOSName = osName;
        lockStatus = isLocked;
    }
 
     void setMobileOwnerName(string ownerName) { 
        mobileOwnerName = ownerName; 
    }

    string getMobileOwnerName() { 
        return mobileOwnerName; 
    }
    
    void setMobileNumber(string number) { 
        mobileNumber = number; 
    }
 
    string getMobileNumber() {
        return mobileNumber; 
    }

    void setMobileBalance(double balance) { 
        mobileBalance = balance; 
    }

    double getMobileBalance(){ 
        return mobileBalance; 
    }
    
     void setLock(bool isLocked) { 
        lockStatus = isLocked; 
    }

    bool isLocked() { 
        return lockStatus; 
    }

    void ShowInfo() {
        cout << "Mobile Owner: " << mobileOwnerName << endl;
        cout << "Mobile Number: " << mobileNumber << endl;
        cout << "Balance: " << mobileBalance << endl;
        cout << "OS Name: " << mobileOSName << endl;
        if(lockStatus){
            cout << "Phone is locked \n" << endl;
        } else {
            cout << "Phone is unlocked \n" << endl;
        }
    }
 
    void Recharge(int amount) {
        if (lockStatus) {
            cout << "Phone is locked. Unlock to recharge. \n" << endl;
        } else {
            mobileBalance += amount;
            cout << "Recharge successful. New balance: " << mobileBalance << "\n" << endl;
        }
    }
 
    void CallSomeone(int timeDuration) {
        if (lockStatus) {
            cout << "Phone is locked. Unlock to make a call." << endl;
        } else {
            int cost = 0.5 * timeDuration;
            if (mobileBalance >= cost) {
                mobileBalance -= cost;
                cout << "Call successful. Remaining balance: " << mobileBalance << endl;
            } else {
                cout << "Insufficient balance to make the call." << endl;
            }
        }
    }
};
 
int main() {
    Mobile iPhone14("Anika Bushra", "", 0.00, "ios", true);
    iPhone14.ShowInfo();
    
    iPhone14.setMobileNumber("0123456780");
 
    iPhone14.setLock(false);
     
    iPhone14.Recharge(30);
    
    iPhone14.ShowInfo();
 
    iPhone14.CallSomeone(5);
    
    cout << "--------------- \n";
    
    Mobile SamsungS10("Anika Priyanka", "0143458780", 42, "Android", true);
    
    SamsungS10.ShowInfo();
 
    SamsungS10.Recharge(50);
    
    SamsungS10.setLock(false);
    
    if(!SamsungS10.isLocked()){
        cout << "Phone is unlocked\n";
    }
 
    SamsungS10.CallSomeone(5);
 
    return 0;
}