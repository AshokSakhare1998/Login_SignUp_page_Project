#include<iostream>
#include<fstream>
using namespace std;

class temp{
    string userName,Email,password;
    string searchName,searchPass,searchEmail;
    fstream file;
    public:
    void login();
    void signUp();
    void forgot();
    void Exit();
}obj;

int main()
{
char choice;
cout<<"\n1-login"<<endl;
cout<<"\n2-signUp"<<endl;
cout<<"\n3-forgot password"<<endl;
cout<<"\n4-Exit"<<endl;
cout<<"\nEnter your choice ::";
cin>>choice;
switch (choice)
{
case '1':
obj.login();

    break;
case '2':
obj.signUp();
    break;
    case '3':
    obj.forgot();
    break;
    case '4':
    return 0;
    break;
   
default:
cout<<"Invalide selection...!";
    break;
}


}
void temp ::signUp(){
    cout<<"\nEnter your User name ::"<<endl;
    getline(cin,userName);
    cout<<"Enter your Email Address ::";
    getline(cin,Email);
    cout<<"Enter your password  ::";
    getline(cin,password);
    file.open("loginData.txt",ios ::out |ios :: app);
    file<<userName<<"*"<<Email<<"*"<<password<<endl;
    file.close();

}
void temp::login(){
    
    cout<<"------------LOGIN---------"<<endl;
    cout<<"Enter your User Name  ::"<<endl;
    getline(cin,searchName);
    cout<<"Enter your password ::"<<endl;
    getline(cin,searchPass);

    file.open("loginData.txt",ios ::in);
    getline(file,userName,'*');
    getline(file,Email,'*');
    getline(file,password,'\n');

    while(!file.eof()){
        if(userName==searchName){
            if(password== searchPass){
                //cout<<"\nAccount \login \successful...!"<<endl;
                cout<<"\nUsername::"<<userName<<endl;
                cout<<"\nEmail::"<<Email<<endl;

            }else{
                cout<<"Password is Incorrect.....!";
            }
        }
        getline(file,userName,'*');
        getline(file,Email,'*');
        getline(file,password,'\n');

    }
    file.close();

}
void temp ::forgot(){
    cout<<"\n enter your UserName ::";
getline(cin,searchName);
cout<<"\nEnter your Email Address ::";
getline(cin,searchEmail);

file.open("loginData.txt",ios :: in);
getline(file,userName,'*');
getline(file,Email,'*');
getline(file,password,'\n');
while(!file.eof()){
    if(userName==searchName){
        if(Email==searchEmail){
cout<<"\nAccount found....!"<<endl;
cout<<"your Password :: "<<password<<endl;

        }else
        {
            cout<<"Not found...!\n";
        }
    }else{
        cout<<"\nNot fount....!\n";
    }
}
file.close();
}