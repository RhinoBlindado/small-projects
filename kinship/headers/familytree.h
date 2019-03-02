#ifndef FAMILYTREE_H_
#define FAMILYTREE_H_

#include "person.h"

class f_tree
{
//                                              ====Atributes====
    protected:
        std::list<person*> listPeople;
//                                              ====Methods====
//      Internal Methods
        void setRelative(int IDBase,int IDRelative,bool who);
        bool isOnPath(person* act,std::list<person*> &path);
        void findPath(person *act,person *tgt,std::list<person*> &path,std::vector<int> &coord,bool &found);
        std::string famMatrix(int x,int y,bool isMale);
    public:
//      Constructors and Destructors
        f_tree();
        ~f_tree();
//      Input
        void addPerson(int ID_, char sex_, std::string f_name_, std::string l_name_, int day_, int month_, int year_); //Done
        void addPerson(int ID_, char sex_, std::string f_name_, std::string l_name_, int day_, int month_, int year_, int d_day, int d_month, int d_year); //Done
        void setMother(int IDPerson, int IDMother); //Done
        void setFather(int IDPerson, int IDFather); //Done
        void setParents(int IDPerson, int IDMother, int IDFather); //Done
//      Output
        std::string getRelation(int PersonA, int PersonB);
//      Debug
        void getStatus(); //Done but there's stuff to add.
};

#endif