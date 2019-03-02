#include <iostream>
#include <list>
#include <string>
#include "familytree.h"

void input(f_tree &fam)
{
    int N_members, N_interac;
    int ID,day,month,year;
    char sex;
    std::string name,lname;
    
    std::cin >> N_members;
    for(int i = 0; i < N_members;i++)
    {
        std::cin >> ID >> sex >> name >> lname >> day >> month >> year;
        fam.addPerson(ID,sex,name,lname,day,month,year);
    }
    int ID_1,ID_2;
    std::string relation;

    std::cin >> N_interac;
    for(int i = 0; i < N_interac; i++)
    {
        std::cin >> ID_1 >> relation >> ID_2;

        if(relation.compare("FTHR") == 0)
        {
            fam.setFather(ID_2,ID_1);
        }
        else
        {
            fam.setMother(ID_2,ID_1);
        }
    }
}


int main()
{
    f_tree familia;
    input(familia);
    //familia.getStatus();
    std::cout<<familia.getRelation(1,6)<<std::endl;
	return 0;
}