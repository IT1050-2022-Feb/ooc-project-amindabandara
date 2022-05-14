#include <iostream>
#include <string>
using namespace std;

//implement Property class
class Property
{
  private:
    int propID;
    string location;
    float price;

  public:
    Property(int prID, string loca, float pPrice )
    {
        propID = prID;
        location = loca;
        price = pPrice;
    }

    void showPropertyDetails(){}

    ~Property(){
      cout<<" Deleting Property"<<endl;
    }

};

//implement Person class
class Person
{
  protected:
    string name;
    string email;
    string address;
    string phoneNo;

  public:
    Person(){}//constructor
    //overloaded constructor
    Person(string na, string em, string addr, string pNo)
    {
      name = na;
      email = em;
      address = addr;
      phoneNo = pNo;

    }

    void showDetails(){}

};
//implement derived class Agent
class Agent : public Person{

  private:
    int AgentID;
    string NIC;
    Property *prop[1];

  public:

    Agent()
    {
      prop[0] = new Property(10001,"Colombo 07", 8950000.00);
      
    }
    //implement overloaded constructor for Agent
    Agent(string na, string em, string addr, string pNo, int aID, string ni, int pr, string lo, float p) : Person(na, em, addr, pNo)
    {
      AgentID = aID;
      NIC = ni;
      prop[0] = new Property(pr, lo, p);

    }

    void addDetails(){}
    void addProperty(){}
    void showDetails(){}//overriding

    ~Agent()
    {
      cout<<"Agent is left"<<endl;
    }

};

//implement derived Customer class
class Customer : public Person
{
  private:
    int CusID;

  public:
  //implement overloaded constructor
  Customer(string na, string em, string addr, string pNo, int cID) : Person(na, em, addr, pNo)
  {
      CusID = cID;
  }

  void addDetails(){}
  void reserve(){}
  void showDetails(){}//overriding

};
//implement derived Manager class
class Manager : public Person
{
  private:
    int managerID;

  public:
    //implement overloaded constructor
    Manager(string na, string em, string addr, string pNo, int mID) : Person(na, em, addr, pNo)
    {
        managerID = mID;
    }
    void showDetails(){}//overriding
    void reviewDetails(Report *p1){}
};

//implement Admin class
class Admin : public Person
{
  private:
    int adminID;

  public:
    Admin(string na, string em, string addr, string pNo, int adID) : Person(na, em, addr, pNo)
    {
      adminID = adID;
    }

    void showDetails(){}
    void updateAgentDetails(){}
    void deleteAgentDetails(){}
    void updatePropertyDetails(){}
    void deletePropertyDetails(){}
    void updateCustomerDetails(){}
    void deleteCustomerDetails(){}
};
//implement Payment class
class Payment
{
  protected:
    float amount;
    int receiptNo;
    string date;
    string time;
    Customer *c;

public:
  Payment(float am, int recNo, string d, string t)
  {
    amount=am;
    receiptNo= recNo;
    date=d;
    time=t;
  }
  float calPayment(){}
  void showPaymentDetails(){}

};

//implement CreditCard class
class CreditCard : public Payment
{
  private:
    int cardNo;
    string expDate;

  public:
    CreditCard(float am, int recNo, string d, string t, int cNo, string exD) : Payment( am, recNo, d, t)
    {
        cardNo= cNo;
        expDate= exD;
    }
    void showPaymentDetails(){}

};

//implement VisaCard class
class VisaCard : public Payment
{
 private:
    int cardNo;
    string expDate;

  public:
    VisaCard(float am, int recNo, string d, string t, int cNo, string exD) : Payment( am, recNo, d, t)
    {
      cardNo= cNo;
      expDate= exD;
    }
    void showPaymentDetails(){}

};

//implement Cash class
class Cash : public Payment
{
 private:
    string bankName;
  public:
    Cash(float am, int recNo, string d, string t, string bName) :Payment( am, recNo, d, t)
    {
      bankName= bName;
    }
    void showPaymentDetails(){}
};


//implement Report class
class Report
{
  private:
    string date;
    string time;
    string type;

    public:
      void displayReport(){}
      ~Report(){}
};


int main() {

  Person p("Kamal", "kamal@gmail.com", "Kandy", "0718894554");

  Customer c1("Sachini", "sachini@gmail.com", "Anuradhapura", "0779898665", 1001);

  Manager m1("Lakmal", "lakmal@gmail.com", "Galle", "0769982322", 50075);

  Admin ad1("Sajan", "Sajan@yahoo.com", "Colombo", "0771445653", 64512);

  Agent *ag2 = new Agent();
  
  Report *p1= new Report();
  
  CreditCard cc(15000.00, 5645, "2022/09/04","12:45:00",14445556, "2023/03/12");

  VisaCard vc(652000.00, 5748, "2022/10/01","09:26:54",19985556, "2023/09/06");

  Cash(752045.00, 6898, "2022/10/10","14:00:31","BOC");

  char ch;
  cin>>ch;
  
}





