#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include <string>
#include <fstream>

/* We have taken help from various Online sources. We do not intend to steal any code or claim it to be ours.
  We have learned and modified the codes to make it work in our way. Sources where we took help from : tutorialspoint,cplusplus,MSDN,differnt forums that we came
  to know about from www.google.com */
using namespace std;

class Balance
{
    public:
    int Balancea1();
    static double balance;
    double getBalance()
    {
    return balance;
    }
    void setBalance(double bala)
    {
        balance+=bala;                      //adding balance
    }
};
double Balance :: balance;
double p;
int Balance1()
{
    Balance b1;
    //int b;
    double ba;
    level:
    system("cls");
    cout<<"1. Check balance.\n2. Recharge. \n3. Return"<<endl;
    int pointer;
    cin>> pointer;
    switch (pointer)
    {
    case 1:
        {
            Sleep(1000);
            cout<<"Your current balance is "<<fixed<<setprecision(2)<<b1.balance-p;
            Sleep(1000);
        } break;

    case 2:
        {
            Sleep(1000);
            cout<<"Amount of recharge : ";
            cin>>ba;

            b1.setBalance(ba);

            Sleep(1000);

            cout<<"Your balance is now "<<fixed<<setprecision(2)<<b1.getBalance();
            Sleep(4000);
        }
        break;

    case 3:
        {
            break;
        }
    default:
        {
            Sleep(1000);
            cout<<"Invalid number. Please enter the right number.";
            goto level;
            break;
        }
    }
    return 0;
}
// create a class call phone book
class Phone_book
{
public:
// create a default constructed
    Phone_book(){}
// declare the member functions
    void add_data();
    void display();
    char* getName(){return name;}
    char* getNum(){return phone_number;}
// create method to give the contact number
    int get_contact_num(){return contact_no;}
//give two private data name and phone number
private:
    char name[20];
    char phone_number[20];
// create static int to calculate total contacts
    static int contact_no;
};
int Phone_book::contact_no;
// create funtion to search data by name
void serach_by_name( Phone_book* &ob);

int Phmain()
{
// create the object first
    Phone_book ob[10];
// create a choice capture for user
    char choice[10];
// create a variable for total contact
    int total;
// create the manu
    while(1)
    {
// clear the screen first
        system("cls");
// get the total contact first
        total=ob[0].get_contact_num();
        cout<<"Total contacts:"<<total<<endl;
        cout<<"Menu"<<endl;
        cout<<"1.Add"<<endl;
        cout<<"2.Display"<<endl;
        cout<<"3.Search"<<endl;
        cout<<"4.Return"<<endl;
// asked the user
        cout<<"\n\n\nEnter your choice:";
        cin>>choice[0];
    switch(choice[0])
    {
    case '1':
// clear the screen
        system("cls");
        ob[total].add_data();
        break;

    case '2':
//clear the screen
        system("cls");
// if there is not number than return

        if(total== 0)
        {
            cout<<"The phone book is empty."<<endl;
            cout<<endl<<"Press any key to continue:"<<endl;
            cin.ignore();
            cin.get();
            continue;
        }
            for(int i=0 ; i<total;i++)
            {
                cout<<"Contact no:"<<i+1<<endl;
                ob[i].display();
            }
            cout<<endl<<"Press any key to continue:"<<endl;
            cin.ignore(10,'\n');
            cin.get();
            break;

    case '3':
        system("cls");
// if the obj is empty than print empty
        if(total == 0)
        {
            cout<<"Noting to search!"<<endl;
            cout<<endl<<"Press any key to continue:"<<endl;
            cin.ignore();
            cin.get();
            continue;
        }
// create a temporary phone book pointer
        Phone_book *temp;
// save the current phone book obj
        temp=ob;
// send to search
        serach_by_name(temp);
// cin.ignore();
        cin.get();
        break;

    case '4':
        {
            return 0;
        }
        break;
    }

    }

return 0;
}
// define the add_data() int class
void Phone_book::add_data()
{
    cout<<"Contact number:"<<contact_no+1<<endl;
    cout<<"Enter the name:"<<endl;
    cin>>name;
    cout<<"Enter the person number:"<<endl;
    cin>>phone_number;
// increment the contact numbers
    contact_no++;
}
// define the display() in class
void Phone_book::display()
{
    cout<<"Name:"<<name<<endl;
    cout<<"Number:"<<phone_number<<endl;
// give a 3 line gap

    cout<<"\n\n\n";
}

void serach_by_name( Phone_book* &ob)
{
// asked the user for name

    cout<<"Enter the name:"<<endl;
    char temp[20];
    cin>>temp;
//loop the ob and search for the name
    for(int i=0 ;i<ob[0].get_contact_num();i++)
    {
// compare the temp one by one
        if( strcmp(ob[i].getName(),temp) ==0)
        {
// if a match is found than print the name and number

            cout<<"Name:"<<ob[i].getName()<<endl;
            cout<<"Phone number:"<<ob[i].getNum();
// pause for user to see
            cin.get();
//return to the main function
            return;
        }
    }
// if no match was found then print the massage
        cout<<"No name as "<<temp<<" in the contact."<<endl;
        cout<<endl<<"Press any key to continue:"<<endl;
        cin.get();
}
//write file fn()

void writefile (string fn,string tx)
{
    fstream myfile(fn.c_str(), fstream::out | fstream::app);
    myfile<<tx<<"\n";
}

class Phone
{
    public:
        string number;
        string name;
//float callduration;
        float credit;
public:
    string getNumber();
    string getName();
    float getCallDuration();
    float getcredit();
    string hisnumber[200];
    string countnumber;
    string setNumber();
    string setName();
    void getTimeDate();

};

class contact: public Phone
{
public:
//NUMBER SECTION!!!
    string getName()
    {
        return name;
    }
    string getNumber()
    {
            return number;
    }
    void setName(string n)
    {
        name=n;
    }
    void setNumber(string num)
    {
        number=num;
    }

int getCall(){

    contact b1;
    string a;
    string b;
    char n;
level:
    cout<<"\nPress 1 to enter new number."<<endl;
    cout<<"Press 2 to call form contact list."<<endl;
    cin>>n;
switch(n)
{
case '1' :
    cout<<"Enter your number : ";
    cin>>b;
    b1.setNumber(b);
//write file data
    writefile ("call_logfile.dat",b);
    cout <<b1.getName() << "\n" << b1.getNumber()<< "\nCalling...";
    cin.ignore();
    break;

case '2' :
    cout<<"Enter contact no of phonebook : ";
    cin>>b;
    cout<<"\ncalling..."<<endl;
    break;
default:
    cout<<"Invalid input. \nPlease enter valid input."<<endl;
    goto level;

}
    b1.getCallduration();
    b1.getTimeDate();
    float CallCost();
    return 0;
    }
//Call Duration And Cost
    float getCallduration()
{

    unsigned int start = clock();
    cout << "Call Received.\n\nCancel Call? \n";
    cin.ignore();

    cout << "Call Duration: " << (clock()-start)/1000 <<" Seconds";

    cin.ignore();

    p=((clock()-start)/1000) *0.025;
    cout<<"Call Cost: BDT "<< p;

    return 0;
}
// Time And Date
    void getTimeDate()
{
    time_t rawtime;
    struct tm * timeinfo;
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    cout<<"\n"<< asctime(timeinfo);
}

public:

contact();

};

contact::contact()
{
    cout << "";
}

// Menu Function

int menu(){

string Menu[5] = {"Call", "Credit", "Call Log","Phone Options","Exit"};
int pointer = 0;

while(true)
{
    system("cls");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout << "Mobile Phone Bills\n\n";

    for (int i = 0; i < 5; ++i)
    {
    if (i == pointer)
    {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
    cout << Menu[i] << endl;
    }
    else
    {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout << Menu[i] << endl;
    }
}

while(true)
{
    if (GetAsyncKeyState(VK_UP) != 0)
    {
        pointer -= 1;
        if (pointer == -1)
        {
            pointer = 4;
        }
        break;
    }
    else if (GetAsyncKeyState(VK_DOWN) != 0)
    {
        pointer += 1;
        if (pointer == 5)
        {
            pointer = 0;
        }
        break;
    }
    else if (GetAsyncKeyState(0x48) != 0)

    {
    switch (pointer)
    {
    case 0:
    {
    cout << "\n\n\n";
    contact b1;
    b1.getCall();
    Sleep(5000);
    system("cls");
    //return 0;

    } break;
    case 1:
    {
    cout << "\n\n\n";
    Balance1();
    Sleep(1000);
    //return 0;
    } break;
    case 2:
    {
    cout<<"This is your call log"<< endl;
    } break;
    case 3:
    {
    Phmain();

    }break;
    case 4:
    {
    ExitProcess(0);
    }
    }
}

}
Sleep(200);

}
}
/// NAVID
class SimRegistration{
public:
    virtual int registration() =0;

};

class SimRegistration1: public SimRegistration{

    public:

    int registration(){                         ///sim 1 registration
    level:
    cout<<"For registration type 'R' and send SMS to 1111."<<endl;
    char text;
    int number;
    cout<<"\nText : "<<endl;
    cin>>text;
    cout<<"\nTo : ";
    cin>>number;
    Sleep(2000);
    cout<<"\nYour SMS has been sent. Please wait for your confirmation SMS."<<endl;
    Sleep(8000);
    system("cls");
    Sleep(1000);
    if(text=='R' && number==1111){
        cout<<"From : 1111 \nThanks for your request. Your sim has been registered. Please Wait for the next registration if any."<<endl;
    }
    else{
        cout<<"From : 1111 \nYou entered the wrong code. Please write the right code."<<endl;
        goto level;
    }
    Sleep(1500);
    cout<<"\n\nYour sim is now ready to use."<<endl;
    Sleep(400);
    return 0;
}
};

void simregistration()                           ///works of registration
{   level:
    system("cls");
    cout<<"How many sim do u want to use?"<<endl;
    int n;
    cin>>n;
    SimRegistration1 b[n];
    if(n<200){
            for(int i=0; i<n;i++)
        b[i].registration();

    }

     else
    {
        cout<<"Invalid Option, Please try again."<<endl;
        Sleep(400);
        goto level;
    }


}
//works of sms
void sms(int num)
{
    //clear screen first
    system("cls");
    string text;
    int number;
    int n, a;
    lev:
    cout<<"1. Write sms \n2. Inbox"<<endl<<endl;
    cout<<"Enter your choice : ";
    cin>>a;
    if(a==1)
    {
        cout<<"\nText : "<<endl;
        cin>>text;
        //cin.getline(text,sizeof (text));
        level:
        cout<<"1. Phonebook \n2. Number "<<endl;
        cin>>number;
        if(number==1)
        {
            cout<<"Contact no : ";
            cin>>n;
        }
        else if(number==2)
        {
            cout<<"To : ";
            cin>>n;
        }
        else
        {
            cout<<"Invalid number. Please enter the right number."<<endl<<endl;
            goto level;
        }
        Sleep(750);
        cout<<"From: \n1. Sim 1 \n2. Sim 2"<<endl;
        cin>>n;
        Sleep(2000);
        cout<<"Massage sent."<<endl;
    }

    else if(a==2)
    {
        Sleep(1000);
        cout<<"Your inbox is empty."<<endl;
    }

    else
    {
        Sleep(1000);
        cout<<"Invalid number."<<endl<<endl;
        goto lev;
    }
}
//read file function()
void readfile(string fn)
        {
            string line;
            ifstream myfile (fn.c_str());
            if (myfile.is_open())
            {
            while ( getline (myfile,line) )
            {
              cout << line << '\n';
            }
            myfile.close();
          }
            else cout << "Unable to open file";
      }

void CallLog()
{
    system("cls");
    cout<<"This is your call log:"<<endl;
//read file
    readfile("call_logfile.dat");
    cin.ignore();
}

int main()

{


//menu();
    string ch;
    contact c1;

    cout<<"Mobile Phone Bills "<<endl;
    level:
    cout<<"Do you want to register your sim? \n1. Yes \n2. No"<<endl;
    cin>>ch;
    if(ch=="1")
    {
        simregistration();
        Sleep(1000);
        string Menu[6] = {"SMS", "Call", "Credit","Call Log","Phone Options", "Exit"};
        int pointer = 0;
while(true)
{
system("cls");

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
cout << "Mobile Phone Bills\n\n";

for (int i = 0; i < 6; ++i)
{


if (i == pointer)
{
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
cout << Menu[i] << endl;
}
else
{
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
cout << Menu[i] << endl;
}
}

while(true)
{
if (GetAsyncKeyState(VK_UP) != 0)
{
pointer -= 1;
if (pointer == -1)
{
pointer = 5;
}
break;
}
else if (GetAsyncKeyState(VK_DOWN) != 0)
{
pointer += 1;
if (pointer == 6)
{
pointer = 0;
}
break;
}
else if (GetAsyncKeyState(0x48) != 0)

{
        switch (pointer)
        {
        case 0 :
            sms(1);
            Sleep(1000);
            system ("cls");
            //goto menu;
            break;
        case 1 :
            c1.getCall();
            Sleep(1000);
            system ("cls");
            //goto menu;
            break;
        case 2 :
            Balance1();
            Sleep(1000);
            //goto menu;
            break;
        case 3 :
            cout<<"This is your call log"<< endl;
            CallLog();
            //system("cls");
            //goto menu;
            break;

        case 4 :
            Phmain();
            //goto menu;
            break;
        case 5 :
            return 0;
        default :
            cout<<"Invalid number. Please enter the right number."<<endl;
            //goto menu;
            break;
        }
    }
} Sleep(200);}}
    else
    {
        cout<<"To continue, you have to register your sim first."<<endl;
        Sleep(1000);
        system("cls");
        goto level;
    }
}
