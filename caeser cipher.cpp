#include <iostream>
#include <stdlib.h>

using namespace std;
string Capital_Alphabate_array="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string Small_Alphabate_array="abcdefghijklmnopqrstuvwxyz";
string Number_array="0123456789";
string Special_character_array="!@#$%)'=_,./*-+";
string For_space_character_array="^&*`~:/?<>";
string Space="          ";

string encryption(void);
string decryption(void);



int main()
{
here:
    while(1)
    {
        system("CLS");
        int  choice=0;
        cout<<endl<<"                                  "<<"******** WELCOME TO CAESER CIPHER ENCRYPTION PROGRAM ********"<<endl;
        cout<<endl<<endl<<"1.  Encryption";
        cout<<endl<<endl<<"2.  Decryption";
        cout<<endl<<endl<<"3.  Exit"<<endl<<endl;
        cout<<endl<< "Enter your choice of operation which you want to perform : ";


        cin>>choice;
        cin.clear();
        cin.ignore(INT_MAX,'\n');

        while(!cin.good())
        {

            cout<<endl<<"Only integers are allowed ...... "<<endl<<endl;
            cin.clear();
            cin.ignore(INT_MAX,'\n');

            system("pause");
            goto here;


        }



        switch(choice)
        {

        case 1:
            encryption();
            break;

        case 2:
            decryption();
            break;

        case 3:
            exit(0);

        default:

            cout<<endl<<"Invalid choice ... "<<endl<<endl;

            break;
        }

      cout<<endl<<"Press any key to continue ... ";
       cin.get();

    }
    return 0;
}





string encryption()
{
    int key=14;
//    cout<<"Enter the key shift value :>";
//    cin>>key;
//    cin.ignore();
    string entered_text="";
    string encrypted="";
    cout<<endl<<"Enter your text for encryption : ";

    getline(cin,entered_text);






    for(int i=0; i<entered_text.length(); i++)
    {

        for(int j=0; j<=25; j++)
        {

            if(entered_text[i]==Capital_Alphabate_array[j])
            {
                int formula=(j+key)%26;
                encrypted.push_back(Capital_Alphabate_array[formula]);
                break;

            }


            else if(entered_text[i]==Small_Alphabate_array[j])
            {
                int formula=(j+key)%26;
                encrypted.push_back(Small_Alphabate_array[formula]);
                 break;

            }


            else if(entered_text[i]==Number_array[j])
            {
                int formula=(j+key)%10;
                encrypted.push_back(Number_array[formula]);
                break;


            }
            else if(entered_text[i]== Special_character_array[j])
            {
                int formula=(j+key)%15;
                encrypted.push_back(Special_character_array[formula]);
                break;

            }


            else if(entered_text[i]==Space[j])
            {
                int formula=(j+key)%10;
                encrypted.push_back(For_space_character_array[formula]);
                break;
            }

        }


    }
    cout<<endl<<"Your cipher text is :"<<encrypted<<endl<<endl;


}


string decryption()
{
     int key=14;
//    cout<<"Enter the key shift value :>";
//    cin>>key;
//    cin.ignore();
    string entered_text;
    string decrypted;


    cout<<"Enter your text to decipher  : ";



    getline(cin,entered_text);

    for(int i=0; i<entered_text.length(); i++)
    {

        for(int j=0; j<=25; j++)
        {
            if(entered_text[i]==Capital_Alphabate_array[j])
            {
                int formula=(j-key)%26;

                if(formula<0)
                {
                    formula=formula+26;
                }


                decrypted.push_back(Capital_Alphabate_array[formula]);
            }
            else if(entered_text[i]==Small_Alphabate_array[j])
            {
                int formula=(j-key)%26;


                if(formula<0)
                {
                    formula=formula+26;
                }


                decrypted.push_back(Small_Alphabate_array[formula]);
                break;
            }
            else if(entered_text[i]==Number_array[j])
            {
                int formula=(j-key)%10;

                if(formula<0)
                {
                    formula=formula+10;
                }

                decrypted.push_back(Number_array[formula]);
                break;

            }

            else if(entered_text[i]==Special_character_array[j])
            {
                int formula=(j-key)%15;

                if(formula<0)
                {
                    formula=formula+15;
                }

                decrypted.push_back(Special_character_array[formula]);
                break;

            }
            else if(entered_text[i]==For_space_character_array[j])
            {
                int formula=(j-key)%10;
                if(formula<0)
                {
                    formula=formula+10;
                }
                decrypted.push_back(Space[formula]);
                break;
            }


        }

    }
    cout<<"Your decrypted text is : "<<decrypted<<endl<<endl;


}


