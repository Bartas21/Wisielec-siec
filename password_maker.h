#ifndef PASSWORD_MAKER_H
#define PASSWORD_MAKER_H

#include <iostream>
#include <vector>
#include <QString>

class password_maker
{

    std::vector<std::string> data;
    std::string password;
    int i_p();
    int lives[2]={0,0};
    bool game_start=false;

public:

    std::string flor_table;

    int p=0;

    password_maker();

    void new_password();

    void chek(char a);

    QString pic();

    QString pkt();

    void win();  

};

#endif // PASSWORD_MAKER_H
