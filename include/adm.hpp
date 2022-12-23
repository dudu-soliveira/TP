#ifndef ADM
#define ADM

#include <string>
#include <iostream>

using namespace std;

class Adm
{
    string username, password, name, email, job, phone_number;
    bool priority;

    public:

    Adm(string user, string psw, string nm,
        string eml, string jb, string phone);
    
    string getUsername() const;
    string getPassword() const;
    string getName() const;
    void mudarSenha(string new_password);
    string descricao();
};

#endif