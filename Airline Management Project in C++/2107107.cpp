#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
using namespace std;
class login;
class signup{//class-1
    string name;
    string id,phone_num,password;
    public:
    signup();
    friend int inup(signup obj1,login obj2);//friend function to compare signup and login information
};
signup::signup(){
    cout<<"Welcome to XYZ AIRLINES. Please signup to get started with"<<endl;
    cout<<"Enter name,ID,phone number & password to signup:"<<endl;
    cin>>name>>id>>phone_num>>password;
    cout<<"Account created successfully"<<endl;
}
class login{//class-2
    string ID,password;
    public:
    login();
    friend int inup(signup obj1,login obj2);//friend function to compare signup and login information
};
login::login(){
    cout<<"Enter ID and password to login"<<endl;
    cin>>ID>>password;
}
int inup(signup obj1,login obj2){
    if(obj1.id==obj2.ID && obj1.password==obj2.password){
        cout<<"Login successful"<<endl;
        return 1;
    }
    else{
        cout<<"Login not successful"<<endl;
        return 0;
    }
}
class Cancel;
class flights{//class-3
    string dest,nam[10],address[10],phone[10];
    int i,ticket;
    string flight[100];
    float price[100],total;
    public:
    flights();
    void put_info();
    void show();
    friend void cancel(flights,Cancel);//friend function to cancel reserved ticket
};
flights::flights(){
    flight[1]="Dubai";
    flight[2]="Singapore";
    flight[3]="Paris";
    flight[4]="London";
    flight[5]="Texas";
    price[1]=50000;
    price[2]=60000;
    price[3]=70000;
    price[4]=40000;
    price[5]=49000;
}
void flights::put_info(){
    int x=0;
        cout<<"These are the available flights with prices:"<<endl;
    for(i=1;i<=5;i++)
        cout<<flight[i]<<setw(12)<<price[i]<<endl;
    cout<<"Enter destination"<<endl;
    cin>>dest;
    for(i=1;i<=5;i++){
        if(dest==flight[i]){
            x=1;
            break;
        }
    }
    if(x==1){
        cout<<"How many tickets do you want to buy:"<<endl;
        cin>>ticket;
        total=price[i]*ticket;
        cout<<"Total price: "<<total<<endl;
        cout<<"Enter name,address and phone number"<<endl;
        for(i=0;i<ticket;i++){
            cin>>nam[i]>>address[i]>>phone[i];
        }
        cout<<"Tickets successfully bought"<<endl;
    }
    else
        cout<<"No ticket available"<<endl;
}
void flights::show()
{
    cout<<"Here are the ticket details:"<<endl;
    for(int j=0;j<ticket;j++)
        cout<<"Name\t"<<nam[j]<<"\tAddress\t"<<address[j]<<"\tPhone number\t"<<phone[j]<<endl;
}
class Cancel{//class-4
    string n;
    friend void cancel(flights,Cancel);
};
void cancel(flights a1,Cancel a2){
    int x,price=a1.total,m;
    int r=a1.ticket-1;
    cout<<"Press 1 to cancel ticket. Press 0 to go back to the main menu"<<endl;
    cin>>m;
    if(m){
    cout<<"Enter name to cancel ticket. Please note that first ticket you bought cannot be cancelled and you can cancel only one ticket"<<endl;
    cin>>a2.n;
    for(x=0;x<a1.ticket;x++){
        if(a1.nam[x]==a2.n){
            price=price-a1.price[a1.i];
            cout<<"Now total price:"<<price<<endl;
            cout<<"Ticket successfully cancelled"<<endl;

            for(int j=x;j<=(a1.ticket-1);j++){
                a1.nam[x]=a1.nam[x+1];
                a1.address[x]=a1.address[x+1];
                a1.phone[x]=a1.phone[x+1];
                break;
            }
            cout<<"Here are the remaining ticket details:"<<endl;
        for(int f=0;f<r;f++)
            cout<<"Name\t"<<a1.nam[f]<<"\tAddress\t"<<a1.address[f]<<"\tPhone number\t"<<a1.phone[f]<<endl;
        }
    }
}
else
    cout<<"Thanks for using our service"<<endl;
}

int main()
{
    signup obj1;
    login obj2;
    int x=inup(obj1,obj2);
    int s,w=1;
    if(x){
        while(w==1){
        cout<<"Press 1 to buy ticket"<<endl;
        cout<<"Press 2 to logout"<<endl;
        cin>>s;
        flights obj3;
        Cancel obj4;
        switch(s){
            case 1:
                obj3.put_info();
                obj3.show();
                cancel(obj3,obj4);
                break;
            case 2:
                cout<<"Logged out successfully. Have a good day.";
                w=0;
                break;
        }
    }
}
    else
        cout<<"Please enter correct information"<<endl;
    return 0;
}
