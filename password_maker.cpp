#include "password_maker.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>

password_maker::password_maker()
{
    std::string file_name="C:/Users/Tina/Desktop/wisielec/";

    file_name+="stolice.txt";
//    file_name+="test.txt";
//    file_name+="test2.txt";
    std::string d;

    std::fstream plik;
    plik.open(file_name, std::ios::in);

    if( plik.good() == true )
    {

        while (getline(plik, d)) {
            data.push_back(d);
        }

        plik.close();
    }

    new_password();

}

int password_maker::i_p()
{
    srand(time(NULL));
    int i=rand()%data.size();

    return i;
}

void password_maker::new_password()
{
    password=data[i_p()];
    flor_table="";

    lives[0]=0;
    lives[1]=0;

    for(int i=0; i<password.length(); i++)
    {
        flor_table+="_ ";
    }

    game_start=true;
}

void password_maker::chek(char a)
{
    int l=0;

    if((lives[0]<7)&&(lives[1]<password.length()))
    {
        for(int i=0;i < password.length();i++)
        {
            if(a==password[i])
            {
                if(flor_table[2*i]=='_')
                {
                    flor_table[2*i]=a;
                    lives[1]++;
                }
                l=1;

            }
        }

        if(l==0)
        {
            lives[0]++;
        }
    }

    win();
}

QString password_maker::pic()
{

//    std::string x = "C:/Users/Tina/Desktop/wisielec/obraz/";

//    x+= std::to_string(lives[0]);
    std::string x = std::to_string(lives[0]);
//    x+=".png";

    QString Qx=QString::fromStdString(x);
    return Qx;

}

QString password_maker::pkt()
{
    return QString::number(p);
}

void password_maker::win()
{
    if(lives[0]==7)
    {
        flor_table="przegrales";
        if(game_start)
        {
            p-=1;
            game_start=false;
        }

    }

    if(lives[1]==password.length())
    {
        flor_table="wygrales";
        if(game_start)
        {
            p+=1;
            game_start=false;
        }
    }
}


