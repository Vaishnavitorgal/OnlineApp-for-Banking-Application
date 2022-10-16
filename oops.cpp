#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;
class Debit;
class Credit;
class BankAcc;
class BankingApp;
int linked=0;
int flagc=0;

class Singleton
{
    static Singleton *instance;
    string msg;
    Singleton(){msg = "TO SELF TRANSFER OPTION IS ALL SET TO USE";}

public:
    static Singleton *getinstance()
    {
        if(!instance)
            instance = new Singleton;
        return instance;
    }
    void getMsg()
    {
        cout<<msg<<endl;
    }
};

Singleton *Singleton::instance=0;



//EXCEPTION
class creditLimit
{
public:
    string msg;
    int error;
    creditLimit():error(0),msg(""){}
    creditLimit(int e,string m):error(e),msg(m){}

    void show()
    {
        cout<<error<<":"<<msg<<endl;
    }
};

//EXCEPTION
class exceedingAmt
{
public:
    int error;
    string msg;

    exceedingAmt():error(0),msg(""){}
    exceedingAmt(int e,string m):error(e),msg(m){}

    void show()
    {
        cout<<error<<":"<<msg<<endl;
    }
};


class BankAcc
{
	public:

	long  long  accNo;
	long long phoneNo;
	double curBal;
	string name;
	float  intrestRate;
	bool   intrestTaken;
	bool   loan;

	   BankAcc(): accNo(0),phoneNo(0L),curBal(0),intrestRate(0),name(""){}
	   BankAcc(long long ac,long long  ph,double cr, string n, float ir):accNo(ac),phoneNo(ph),curBal(cr),name(n),intrestRate(ir){
	   intrestTaken=0;
	   loan=0;}

	   	void sendSMS (string msg, float payment)
	   	{
	   	    cout<<" SMS ON PHONE "<<endl;
	   	    cout<<"YOUR PAYMENT OF Rs "<< payment <<" IS SUCCESSFULLY DONE FOR "<< msg <<" BILL "<<endl;
		}

	   	void display()
	   	  {
            cout<< accNo <<":"<< phoneNo <<":"<< curBal <<":"<< name <<endl;
          }

};


enum rechargeType
{
    rDTH, rmobile, rBroadband
};


class Recharge
{
public:
    long long mobile;
    string billername;
    string type;

    Recharge(double m):mobile(m){}

    virtual void selectBillerName(){
        cout<<"ENTER BILLERNAME :"<<endl;
        cin>>billername;

    }
    virtual void recharge(BankAcc *ba)=0;//send bankacc as parameter
    static Recharge* Create1(rechargeType type1);
};

class DTH : public Recharge
{
public:
    DTH(long long m):Recharge(m){}
    int bill;
    void selectBillerName()
    {
        cout<<"DD FREE DISH, TATA PLAY, AIRTEL"<<endl;
        cout<<"SELECT THE TYPE :"<<endl;
        cin>>type;

        Recharge::selectBillerName();
    }

    void recharge(BankAcc *ba)//ba
    {
        cout<<"ENTER RECHARGE BILL"<<endl;
        cin>>bill;
        while(1){
        int check;
        cout<<"CONFIRM PAYMENT?"<<endl<<"PRESS 1"<<endl;
        cin>>check;
        if(check)
        {
            break;
        }
        }
        ba->curBal=ba->curBal-bill;

        cout<<billername<<":"<<"DTH RECHARGE SUCCESSFULLY DONE"<<endl;
        ba->sendSMS("DTH",bill);
    }
};


class Mobile : public Recharge
{
public:
    Mobile(long long m):Recharge(m){}
    int bill;
    void selectBillerName()
    {
        cout<<"JIO, AIRTEL, VI AND BSNL"<<endl;
        cout<<"SELECT THE TYPE :"<<endl;
        cin>>type;

        Recharge::selectBillerName();
    }

    void recharge(BankAcc *ba)//ba
    {
        cout<<"ENTER RECHARGE BILL"<<endl;
        cin>>bill;
        while(1){
        int check;
        cout<<"CONFIRM PAYMENT?"<<endl<<"PRESS 1"<<endl;
        cin>>check;
        if(check)
        {
            break;
        }
        }
        ba->curBal=ba->curBal-bill;

        cout<<billername<<":"<<"MOBILE RECHARGE SUCCESSFULLY DONE"<<endl;
        ba->sendSMS("MOBILE",bill);
    }
};


class Broadband : public Recharge
{
public:
    Broadband(long long m):Recharge(m){}
    int bill;
    void selectBillerName()
    {
        cout<<"AIRTEL, EXCITEL, MTNL, BSNL"<<endl;
        cout<<"SELECT THE TYPE :"<<endl;
        cin>>type;

        Recharge::selectBillerName();
    }

    void recharge(BankAcc *ba)//ba
    {
        cout<<"ENTER RECHARGE BILL"<<endl;
        cin>>bill;
        while(1){
        int check;
        cout<<"CONFIRM PAYMENT?"<<endl<<"PRESS 1"<<endl;
        cin>>check;
        if(check)
        {
            break;
        }
        }
        ba->curBal=ba->curBal-bill;
        cout<<billername<<":"<<"BROADBAND RECHARGE SUCCESSFULLY DONE"<<endl;
        ba->sendSMS("BROADBAND",bill);
    }
};


//FACTORY METHOD
Recharge* Recharge::Create1(rechargeType type1)
{
    if(type1 == rDTH){
        return new DTH(7836627387);}
    else if(type1 == rmobile){
        return new Mobile(7272927238);}
    else if(type1 == rBroadband){
        return new Broadband(7272924458);}
    else
        return NULL;
}


class Client
{
public:
    Client()
    {
        rechargeType type1=rDTH;
        precharge = Recharge::Create1(type1);
    }
    ~Client()
    {
        if(precharge){
            delete[] precharge;
            precharge = NULL;
        }
    }
    Recharge *getRech()
    {
        return precharge;
    }
private:
    Recharge *precharge;
};
//TILL HERE


class BillPayment
{
public:
    long long mobileNo;
    float bill;
    int houseId;

    BillPayment():mobileNo(00.00){}
    BillPayment(long long m):mobileNo(m){}

    virtual void doPayment(BankAcc *baa)
    {

    }
    //add bankacc var as parameter
};


class Water : public BillPayment
{
public:
    Water():BillPayment(0){}
    Water(long long mobile):BillPayment(mobile){}

    void doPayment(BankAcc *baa)
    {

         while(1){
        cout<<"ENTER HOUSE ID AND BILL AMOUNT"<<endl;
        cin>>houseId;
        cin>>bill;

        int check;
        cout<<"CONFIRM PAYMENT?"<<endl<<"PRESS 1"<<endl;
        cin>>check;
        if(check)
        {
            break;
        }
        }
        baa->curBal=baa->curBal-bill;

        cout<<"WATER PAYMENT SUCCESSFULLY DONE"<<endl;
        baa->sendSMS("WATER",bill);

    }
};

class Gas : public BillPayment
{
public:
    Gas():BillPayment(0){}
    Gas(long long mobile):BillPayment(mobile){}
    void doPayment(BankAcc *baa)//ba
    {

        while(1){
        cout<<"ENTER HOUSE ID AND BILL AMOUNT"<<endl;
        cin>>houseId;
        cin>>bill;

        int check;
        cout<<"CONFIRM PAYMENT?"<<endl<<"PRESS 1"<<endl;
        cin>>check;
        if(check)
        {
            break;
        }
        }
        baa->curBal=baa->curBal-bill;


        cout<<"GAS PAYMENT SUCCESSFULLY DONE"<<endl;
        baa->sendSMS("GAS",bill);

    }
};

class Electricity : public BillPayment
{
public:
    Electricity():BillPayment(0){}
    Electricity(long long mobile):BillPayment(mobile){}
    void doPayment(BankAcc *baa)//ba
    {

        while(1){
        cout<<"ENTER HOUSE ID AND BILL AMOUNT"<<endl;
        cin>>houseId;
        cin>>bill;

        int check;
        cout<<"CONFIRM PAYMENT?"<<endl<<"PRESS 1"<<endl;
        cin>>check;
        if(check)
        {
           break;
        }
        }

        baa->curBal=baa->curBal-bill;

        cout<<"ELECTRICITY PAYMENT SUCCESSFULLY DONE"<<endl;
        baa->sendSMS("ELECTRICITY",bill);

    }
};

class LoanRepayment : public BillPayment
{
public:
    LoanRepayment(){}
    void doPayment(BankAcc *ba)//ba
    {
        if(ba->loan==true){
        while(1){
        cout<<"ENTER HOUSE ID AND BILL AMOUNT"<<endl;
        cin>>houseId;
        cin>>bill;

        int check;
        cout<<"CONFIRM PAYMENT?"<<endl<<"PRESS 1"<<endl;
        cin>>check;
        if(check)
        {
            break;
        }
        }
        ba->curBal=ba->curBal-ba->intrestRate;
        ba->curBal=ba->curBal-bill;

        cout<<"LOAN REPAYMENT SUCCESSFULLY DONE"<<endl;
        ba->sendSMS("LOAN",bill);
        }
    }
};

class Booking
{
public:
    long long mobileNo;
    string destination;
    string classType;
    string onDate;
    float bill;

    Booking():mobileNo(00.00),destination(""),classType(""),onDate(""){}
    Booking(long long m,string dest,string date):mobileNo(m),destination(dest),onDate(date){}

    virtual void selectType()
    {

    }
    //add bankacc var as parameter

    virtual void payAmount(BankAcc *ba)=0;

};

class Flight : public Booking
{
public:
    string name;
    Flight(long long m,string dest,string date):Booking(m,dest,date){}

    void selectType()
    {
        cout<<"ENTER TYPE : FIRST CLASS, BUSINESS CLASS OR ECONOMY CLASS"<<endl;
        cin>>classType;
    }

    void payAmount(BankAcc *ba)//bank acc as parameter
    {

        if(classType == "first")
        {
            cout<<" 1 INDIGO     78000  "<<endl;
            cout<<" 2 AIRINDIA   70000  "<<endl;
        }
        else if(classType == "business")
        {
            cout<<" 1 INDIGO         48000  "<<endl;
            cout<<" 2 AIRASIAINDIA   50000  "<<endl;
        }
        else
        {
            cout<<" 1 VISTARA    38000  "<<endl;
            cout<<" 2 AIRINDIA   45000  "<<endl;
        }
        cout<<"ENTER AMOUNT AND FLIGHT NAME"<<endl;
        cin>>bill;
        cin>>name;
        while(1){
        int check;
        cout<<"CONFIRM PAYMENT?"<<endl<<"PRESS 1"<<endl;
        cin>>check;
        if(check)
        {
            break;
        }
        }
        ba->curBal=ba->curBal-bill;

        cout<<name<<":"<<"FLIGHT SUCCESSFULLY BOOKED"<<endl;
        ba->sendSMS("FLIGHT",bill);
    }
};

class Cab : public Booking
{
public:
    string name;
    Cab(long long m,string dest,string date):Booking(m,dest,date){}

    void selectType()
    {
        cout<<"ENTER TYPE : 4-SEATER, 6-SEATER, 8-SEATER"<<endl;
        cin>>classType;
    }

    void payAmount(BankAcc *ba)//bank acc as parameter
    {

        cout<<"ENTER AMOUNT AND CAR NAME"<<endl;
        cin>>bill;
        cin>>name;
        while(1){
        int check;
        cout<<"CONFIRM PAYMENT?"<<endl<<"PRESS 1"<<endl;
        cin>>check;
        if(check)
        {
            break;
        }
        }
        ba->curBal=ba->curBal-bill;

        cout<<name<<":"<<"CAB SUCCESSFULLY BOOKED"<<endl;
        ba->sendSMS("CAB",bill);
    }
};

class Hotel : public Booking
{
public:
    string name;
    Hotel(long long m,string dest,string date):Booking(m,dest,date){}

    void selectType()
    {
        cout<<"ENTER TYPE : 2-ROOM, 3-ROOM, ROOM-BALCONY"<<endl;
        cin>>classType;
    }

    void payAmount(BankAcc *ba)//bank acc as parameter
    {

        cout<<"ENTER AMOUNT AND HOTEL NAME"<<endl;
        cin>>bill;
        cin>>name;
        while(1){
        int check;
        cout<<"CONFIRM PAYMENT?"<<endl<<"PRESS 1"<<endl;
        cin>>check;
        if(check)
        {
            break;
        }
        }
        ba->curBal=ba->curBal-bill;

        cout<<name<<":"<<"HOTEL SUCCESSFULLY BOOKED"<<endl;
        ba->sendSMS("HOTEL",bill);
    }
};

class User
{
	public:

	string name;
	string address;
	string mailID;
	int    pinCode;
	int    userPin;
	long long   mobPhn;
	string  dob;
    //BankAcc ba;
	string see;
	   User(): name(""),address(""),mailID(""),pinCode(0),userPin(0),mobPhn(0),dob(0){}
	   User(string n,string adr,string mID, int pCD, int uPin,long long mobn,string d):name(n),address(adr),mailID(mID),pinCode(pCD),userPin(uPin),mobPhn(mobn),dob(d){}

	   	void getDetails()
	   	{
		   cout<<"DISPLAY ON THE APPLICATION OF USER :"<<endl;
		   cout<<" NAME:"<< name  <<" MAIL-ID:"<< mailID <<" MOBILE PHONE:"<< mobPhn <<" DATE-OF-BIRTH:"<< dob <<endl;

		   cout<<"SEE USER-PIN?  ENTER YES"<<endl;
		   cin>>see;
		   if(see=="YES")
           {
               cout<<userPin<<endl;
           }
		}

	   	void diplay()
	   	  {
            cout<< name <<":"<< address <<":"<< mailID <<":"<< pinCode <<":"<< userPin <<":"<< mobPhn <<":"<< dob <<endl;
          }
};

class BankingApp
{
    public:
        long accNo;
        int pin;
        long long cardNo;
        string expDate;
        string cardType;
        string name;
        long long phoneNo;
        double balance;
        double loanAmount;
        static int trans;

        int flag=0;

        BankingApp():accNo(0),pin(0),cardNo(0),expDate(0),cardType(""),name(""),phoneNo(0),balance(0),loanAmount(0){}
        BankingApp(int p,long long cn,string ed,string ct,double la):pin(p),cardNo(cn),expDate(ed),cardType(ct),loanAmount(la){}


        void linkAccount(BankAcc *ba)
        {
            long long num;
            cout<<"ENTER YOUR PHONE NUMBER:"<<endl;
            cin>>num;
            for(int i=0;i<2;i++)
            {
                if(num==ba[i].phoneNo && flag==0)  //THIS WON'T LET TO CREATE ANOTHER BANK USING SAME PHONE NUMBER
                {
                    accNo=ba[i].accNo;
                    phoneNo=ba[i].phoneNo;
                    balance=ba[i].curBal;
                    name=ba[i].name;
                    cout<<"YOUR BANK ACCOUNT HAS BEEN LINKED SUCCESSFULLY!"<<endl;
                    flag=1;
                    linked=1;
                }

            }
            if(flag==0)
                {
                   cout<<"YOUR BANK ACCOUNT COUNLDN'T BE LINKED!!"<<endl<<"YOUR MOBILE NUMBER IS NOT LINKED TO YOUR BANK ACCOUNT"<<endl;
                   cout<<"MAY BE YOUR ACCOUNT IS ALREADY LINKED"<<endl;
                }
        }
         void withDraw(BankAcc *ba)
         {
             int amt,flag2=0;
             long long pho;
             cout<<"ENTER AMOUNT TO BE DEBIT :"<<endl;
             cin>>amt;
             balance-=amt;
             cout<<"AMOUNT DEBITED"<<endl;

             cout<<"ENTER PHONE NUMBER WHICH IS LINKED TO BANK ACCOUNT, TO TRANSFER MONEY!"<<endl;
             cin>>pho;
             for(int i=0;i<2;i++)
            {
                if(pho==ba[i].phoneNo)
                {
                    ba[i].curBal+=amt;
                    trans++;
                    int flag2=1;
                }
            }
            if(flag2==0)
            {
                cout<<"NO INFORMATION PRESENT REGARDING THIS BANK ACCOUNT, ADD BENEFICIARY"<<endl;
            }

         }

        void applyLoan(BankAcc *ba)
        {
            double amt;
            cout<<"ENTER LOAN AMOUNT"<<endl;
            cin>>amt;
                    balance+=amt;
                    ba->curBal+=amt;
                    ba->loan=1;
                    ba->intrestTaken=1;
                    ba->intrestRate=700;

            cout<<"LOAN AVAILED OF RUPEES "<<amt<<endl;
        }

        void history()
        {
            cout<<"CURRENTLY YOU HAVE DONE "<<trans<<endl<<" ENJOY YOUR TRANSACTIONS "<<endl;
        }

        void viewUserDetail(User &u)
        {
            u.getDetails();
        }

        void chooseCardType()
        {
            string type;
            cout<<"ENTER THE TYPE OF CARD FOR TRANSACTION:";
            cin>>type;
            cardType=type;
            cout<<"CARD CHOSEN IS "<<cardType<<endl;
        }

};
int BankingApp::trans=0;

class ToSelfTransfer
{
public:
    long long transferAccNo;
    double transferAmount;
    BankAcc *ba1;
    ToSelfTransfer(long long tan,double ta):transferAccNo(tan),transferAmount(ta){

    Singleton *s = s->getinstance();
    s->getMsg();
    }

    void selfTransfer(BankAcc *ba)
        {
            if(transferAmount>100000)
            {
                throw exceedingAmt(-200," TRANSACTION LIMIT IS SET TO 1LAKH RUPEES ONLY ");
            }
            ba1->curBal=ba1->curBal-transferAmount;
            ba->curBal+=transferAmount;
            cout<<" AMOUNT OF "<< transferAmount <<" HAS BEEN TRANSFERED TO THE ACCOUNT "<< transferAccNo <<endl;
        }
};

class manageAcc
{
public:
    BankingApp *b;
    manageAcc(){}
    int pinchange;
    void getDetails()
    {
        cout<<"WANT TO MODIFY BANKING APP PRIVACY?  CHANGE PIN? PRESS 1 FOR PIN CHANGE"<<endl;
        cin>>pinchange;

        if(pinchange==1)
        {
            int newpin;
            while(1){
            cout<<"YOUR CURRENT PIN IS :"<<b->pin<<endl;
            cout<<"ENTER NEW PIN :"<<endl;
            cin>>newpin;
            if(newpin!=b->pin)
            {
                break;
            }
            else {
                cout<<"NEW PIN SHOULD NOT BE SAME AS CURRENT PIN, ENTER AGAIN "<<endl;
            }
        }

        b->pin=newpin;
        cout<<"NEW PIN IS SET"<<endl;
        }
        else{
            cout<<"here"<<endl;
        }

    }
};

class Debit
{
    public:
        long accNo;
        long long cardNo;
        string expDate;
        string cardType;
        double balance;
        double loanAmount;
        static int transaction;
    BankAcc *baa;
    ToSelfTransfer *s;
    manageAcc *m;
    Debit():accNo(0),cardNo(0),expDate(""),cardType(""),balance(0),loanAmount(0){}
    void init(BankingApp *ba)
    {
        this->accNo=ba->accNo;
        this->cardNo=ba->cardNo;
        this->expDate=ba->expDate;
        this->balance=ba->balance;
        this->loanAmount=ba->loanAmount;
        this->cardType="DEBIT";
    }

    void selfTransferAmount(BankAcc *b)
    {
        s->selfTransfer(b);
        transaction++;
    }

    void history()
    {
        cout<<"CURRENTLY YOU HAVE DONE "<<transaction<<endl<<" ENJOY YOUR TRANSACTIONS "<<endl;
    }

    void getcurrentBal(BankAcc *b)
    {
        cout<<"CURRENT BALANCE FOR THE CARD NUMBER "<< cardNo <<"BALANCE IS : "<< b->curBal <<endl;
        m->getDetails();
    }

    void getLoanDetails(BankAcc *bs)
    {
        if(bs->loan==1)
        {
            cout<<"DEAR CUSTOMER YOUR LOAN AMOUNT FOR THE BANK ACCOUNT :"<< accNo <<" IS "<< loanAmount <<endl;
        }
        else
        {
            cout<<"THERE IS NO LOAN TAKEN FROM THIS BANK, FOR THE ACCOUNT NUMBER : "<<bs->accNo<<endl;
        }
    }

    void sendMoney(BankAcc *ba)
    {
        int amt,flag2=0;
             long long pho;
             cout<<"ENTER AMOUNT TO BE DEBIT :"<<endl;
             cin>>amt;
             balance-=amt;
             cout<<"AMOUNT DEBITED"<<endl;
             baa->curBal-=amt;
             ba->curBal+=amt;
             transaction++;


    }

    template <typename type>
    void doBooking(type copydata)
    {
        Booking *r=&copydata;
        r->selectType();
        r->payAmount(baa);
    }

    template <typename type1>
    void doRecharge(type1 ra)
    {
        Recharge *r=&ra;
        r->selectBillerName();
        r->recharge(baa);
    }

    template <typename type2>
    void payBill(type2 wa)
    {
        BillPayment *r=&wa;
        r->doPayment(baa);
    }
} ;
int Debit :: transaction =0;

class Credit
{
public:
        long accNo;
        long long cardNo;
        string expDate;
        string cardType;
        double balance;
        double creditamt;

    ToSelfTransfer *s;
    manageAcc *m;
    BankAcc *baa;
    Credit():accNo(0),cardNo(0),expDate(""),cardType(""),balance(0),creditamt(0){}
    void init(BankingApp *ba)
    {
        int income;
        this->accNo=ba->accNo;
        this->cardNo=ba->cardNo;
        this->expDate=ba->expDate;
        this->balance=ba->balance;
        this->cardType="CREDIT";
        cout<<"ENTER CREDIT AMOUNT "<<endl;
        cin>>creditamt;
        if(creditamt==0)
        {
            flagc=1;
        }
        cout<<"ENTER ANNUAL INCOME "<<endl;
        cin>>income;
        if(creditamt>300000 || creditamt>(0.3*income))
        {
            creditamt=0;
            throw creditLimit(-100,"CREDIT LIMIT EXCEEDS, AS CREDIT AMOUNT CANNOT BE PERMIT!");
        }
    }

    static int ctransaction;
    void selfTransferAmount(BankAcc *b)
    {
        s->selfTransfer(b);
    }


    void sendMoney(BankAcc *ba)
    {
        int amt,flag2=0;
             long long pho;
             cout<<"ENTER AMOUNT TO BE DEBIT :"<<endl;
             cin>>amt;
             balance-=amt;
             cout<<"AMOUNT DEBITED"<<endl;
             baa->curBal-=amt;
             ba->curBal+=amt;
             ctransaction++;
    }

    void history()
    {
        cout<<"CURRENTLY YOU HAVE DONE "<<ctransaction<<endl<<" ENJOY YOUR TRANSACTIONS "<<endl;
    }

    void getcurrentBal(BankAcc *b)
    {
        cout<<"CURRENT BALANCE FOR THE CARD NUMBER "<<cardNo<<"BALANCE IS : "<<b->curBal<<endl;
        m->getDetails();
    }

    template <typename type>
    void doBooking(type copydata)
    {
        Booking *r=&copydata;
        r->selectType();
        r->payAmount(baa);
    }

    template <typename type1>
    void doRecharge(type1 ra)
    {
        Recharge *r=&ra;
        r->selectBillerName();
        r->recharge(baa);
    }

    template <typename type2>
    void payBill(type2 wa)
    {
        int timel;
        cout<<"ENTER DURATION OF CREDIT EXPIRE DATE"<<endl;
        cin>>timel;
        if(timel>30)
        {
            cout<<"20,000 WILL BE DEDUCTED FROM YOUR BANK BALANCE AS THEIR IS CREDIT DUE OF MORE THAN A MONTH"<<endl;
            balance-=20,000;
            if(balance<0)
            {
                balance=0;
            }
        }
        BillPayment *r=&wa;
        r->doPayment(baa);
    }
} ;
int Credit::ctransaction =0;

int main()
{
    int choice;
    User u1("DEEP","ASHOK NAGAR","Dee123@gmail.com",79001,4561,8917781199,"4-July-2002");
    User u2("RAVI","VIJAY NAGAR","Rv2123@gmail.com",79001,5671,9090234567,"23-Dec-1999");
    cout<<"USER DETAILS :"<<endl;
    u1.diplay();
    u2.diplay();

    cout<<"******************************"<<endl;

    BankAcc ba(123214562,8917781199,579000,"DEEP",0);
    BankAcc ba1(223214572,9090234567,70090,"RAVI",0);
    BankAcc barray[2];
    barray[0]= ba;
    barray[1]= ba1;
    //u1.ba=ba;
    cout<<"BANK ACCOUNT DETAILS :"<<endl;
    barray[0].display();
    barray[1].display();

    cout<<"******************************"<<endl;
    //cout<<ba1.phoneNo<<endl;
    BankingApp b1(1223,2345678133457892,"25-07","DEBIT",0);  //DEEP WILL BE USING BANKING APP b1
    BankingApp b2(1673,3399991334578921,"23-12","CREDIT",0); //EXPIRY DATE IN FORMAT OF YEAR-MONTH AND CARD NUMBER OF 16 DIGIT

    cout<<"USER VIEWING DETAILS THROUGH BANKING APP :"<<endl;
    b1.viewUserDetail(u1);
    b1.viewUserDetail(u2);

    Debit d;
    Credit c;
    //LOGIN


    d.init(&b1);
    try{
    c.init(&b1);
    }
    catch(creditLimit &ce)
    {
        ce.show();
        flagc=1;
    }

    d.baa=&ba;
    c.baa=&ba;

    manageAcc ma;
    ma.b=&b1;
    d.m=&ma;
    c.m=&ma;
    ToSelfTransfer sa(673563710987,2000);

    sa.ba1=&ba;
    d.s=&sa;
    c.s=&sa;
    //cout<<d.s->transferAccNo;
    //cout<<"here";
    //sa.selfTransfer(&ba1);
    //d.selfTransferAmount(&ba1);

    Water w(9899234934);
    Gas g(9833762261);
    Electricity e(7866226529);
    LoanRepayment l;

    Client *pclient = new Client();
    Recharge *precharge = pclient->getRech();
    //DTH dth(9088925124);
    //Broadband b(892673651);
    //Mobile m(9029277624);

    Hotel h(6238881761,"BANGALORE","7-JUNE");
    Flight f(9883726438,"PUNE","16-AUGUST");
    Cab cab(9336727839,"DHARWAD","29-MAY");

    cout<<"******************************"<<endl;

    int see;
    string type;
    cout<<"WANT TO USE DEBIT OR CREDIT?"<<endl;
    cin>>type;

    if(type=="DEBIT"){
    while(1){
    cout<<"ENTER YOUR CHOICE:"<<endl;
    cout<<"1.selfTransferAmount, 2.history, 3.getcurrentBalance, 4.getLoanDetails, 5.Payments, 6.Recharge, 7.Booking, 8.Send Money, 9.Apply Loan 10.close app "<<endl;
    cin>>choice;
    switch(choice)
    {
    case 1: cout<<"OPTION: SELF TRANSFER"<<endl;
            try{
            d.selfTransferAmount(&ba1);
            }
            catch(exceedingAmt &e1)
            {
                e1.show();
            }
            cout<<"TRANSFERRED SUCCESSFULLY"<<endl;
            break;
    case 2: cout<<"OPTION: VIEW HISTORY"<<endl;
            d.history();
            break;
    case 3: cout<<"OPTION :CURRENT BANK DETAILS"<<endl;
            d.getcurrentBal(&ba);
            cout<<"CLOSING "<<endl;
            break;
    case 4: cout<<"OPTION :LOANDETAILS"<<endl;
            d.getLoanDetails(&ba);
            cout<<"CLOSING"<<endl;
            break;
    case 5: cout<<"PAYMENTS"<<endl;
            cout<<"PRESS AS PER NUMBERS GIVEN BELOW FOR YOUR GIVEN REQUIREMENTS"<<endl;
            cout<<"1.WATER"<<" 2.GAS"<<" 3.ELECTRICITY"<<" 4.LOANREPAYMENT"<<endl;
            cin>>see;
            if(see==1){
            d.payBill(w);
            cout<<"DONE WATER PAYMENT"<<endl;}
            else if(see==2){
            d.payBill(e);
            cout<<"DONE GAS PAYMENT"<<endl;}
            else if(see==3){
            d.payBill(e);
            cout<<"DONE ELECTRICIITY PAYMENT"<<endl;}
            else
            {
                BillPayment *r=&l;
                r->doPayment(&ba);
            }
            break;
    case 6: cout<<"RECHARGE"<<endl;
            cout<<"PRESS AS PER NUMBERS GIVEN BELOW FOR YOUR GIVEN REQUIREMENTS"<<endl;
            cout<<"1.DTH"<<" 2.BROADBAND"<<" 3.MOBILE"<<endl;
            cin>>see;
            if(see==1){
            precharge->selectBillerName();
            precharge->recharge(&ba);
            //d.doRecharge(dth);
            cout<<"DONE DTH PAYMENT"<<endl;}
            else if(see==2){
            //d.doRecharge(b);
            cout<<"DONE BROADBAND PAYMENT"<<endl;}
            else if(see==3){
            //d.doRecharge(m);
            cout<<"DONE MOBILE PAYMENT"<<endl;}
            break;
    case 7: cout<<"BOOKING"<<endl;
            cout<<"PRESS AS PER NUMBERS GIVEN BELOW FOR YOUR GIVEN REQUIREMENTS"<<endl;
            cout<<"1.HOTEL"<<" 2.CAB"<<" 3.FLIGHT"<<endl;
            cin>>see;
            if(see==1){
            d.doBooking(h);
            cout<<"DONE HOTEL PAYMENT"<<endl;}
            else if(see==2){
            d.doBooking(cab);
            cout<<"DONE CAB PAYMENT"<<endl;}
            else if(see==3){
            d.doBooking(f);
            cout<<"DONE FLIGHT PAYMENT"<<endl;}
            break;
    case 8: cout<<"SEND MONEY :"<<endl;
            d.sendMoney(&ba1);
            break;
    case 9: cout<<"APPLY LOAN"<<endl;
            b1.applyLoan(&ba);
            break;
    case 10:exit(0);

        }

    }
    }
    else if(type=="CREDIT")
    {
        if(flagc==0){
        while(1){

    cout<<"ENTER YOUR CHOICE:"<<endl;
    cout<<"1.selfTransferAmount, 2.history, 3.getcurrentBalance, 4.Payments, 5.Recharge, 6.Booking, 7.Send Money, 8.close app "<<endl;
    cin>>choice;
    switch(choice)
    {
        case 1: cout<<"OPTION: SELF TRANSFER"<<endl;
            try{
            c.selfTransferAmount(&ba1);
            }
            catch(exceedingAmt &e1)
            {
                e1.show();
            }
            cout<<"TRANSFERRED SUCCESSFULLY"<<endl;
            break;
    case 2: cout<<"OPTION: VIEW HISTORY"<<endl;
            c.history();
            break;
    case 3: cout<<"OPTION :CURRENT BANK DETAILS"<<endl;
            c.getcurrentBal(&ba);
            cout<<"CLOSING "<<endl;
            break;
    case 4: cout<<"PAYMENTS"<<endl;
            cout<<"PRESS AS PER NUMBERS GIVEN BELOW FOR YOUR GIVEN REQUIREMENTS"<<endl;
            cout<<"1.WATER"<<" 2.GAS"<<" 3.ELECTRICITY"<<endl;
            cin>>see;
            if(see==1){
            c.payBill(w);
            cout<<"DONE WATER PAYMENT"<<endl;}
            else if(see==2){
            c.payBill(g);
            cout<<"DONE GAS PAYMENT"<<endl;}
            else if(see==3){
            c.payBill(e);
            cout<<"DONE ELECTRICIITY PAYMENT"<<endl;}
            else
            {
                BillPayment *r=&l;
                r->doPayment(&ba);
            }
            break;
    case 5: cout<<"RECHARGE"<<endl;
            cout<<"PRESS AS PER NUMBERS GIVEN BELOW FOR YOUR GIVEN REQUIREMENTS"<<endl;
            cout<<"1.DTH"<<" 2.BROADBAND"<<" 3.MOBILE"<<endl;
            cin>>see;
            if(see==1){
            //c.doRecharge(dth);
            cout<<"DONE DTH PAYMENT"<<endl;}
            else if(see==2){
            //c.doRecharge(b);
            cout<<"DONE BROADBAND PAYMENT"<<endl;}
            else if(see==3){
            //c.doRecharge(m);
            cout<<"DONE MOBILE PAYMENT"<<endl;}
            break;
    case 6: cout<<"BOOKING"<<endl;
            cout<<"PRESS AS PER NUMBERS GIVEN BELOW FOR YOUR GIVEN REQUIREMENTS"<<endl;
            cout<<"1.HOTEL"<<" 2.CAB"<<" 3.FLIGHT"<<endl;
            cin>>see;
            if(see==1){
            c.doBooking(h);
            cout<<"DONE HOTEL PAYMENT"<<endl;}
            else if(see==2){
            c.doBooking(cab);
            cout<<"DONE CAB PAYMENT"<<endl;}
            else if(see==3){
            c.doBooking(f);
            cout<<"DONE FLIGHT PAYMENT"<<endl;}
            break;
    case 7: cout<<"SEND MONEY :"<<endl;
            c.sendMoney(&ba1);
            break;
    case 8:exit(0);

        }
}
        }
        else{
            cout<<"CREDIT CARD NOT LINKED"<<endl;
        }
}
else
{
   cout<<"INVALID OPTION, TRY TO LOGIN AGAIN"<<endl;
}
   return(0);
}


/*TEST CASES:
RUNTIME INPUTS:
1) IF CREDIT AMOUNT MORE THAN 1LAKH OR AVAILING AMOUNT MORE THAN 30% OF ANNUAL INCOME
2) IF CREDIT AMOUNT IS 0, CREDIT CARD CANNOT BE USED
3) PAYMENT WILL NOT BE DONE, IF CONFIRMATION FROM USER IS NOT GIVEN
4) INVALID OPTION WILL BE HANDLED IF WRONG TYPE OF CREDIT IS CHOSE
STATIC INPUTS:
5) SELF TRANSFER MORE THAN 1LAKH
ToSelfTransfer sa(673563710987,200000);
*/
