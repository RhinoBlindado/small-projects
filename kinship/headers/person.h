#ifndef PERSON_H_
#define PERSON_H_

#include <list>
#include <vector>
#include <string>
#include "date.h"

class person 
{
//												====Atributes====
    person* mother;
    person* father;

    std::list<person*> offSpr;

    std::string f_name;
    std::string l_name;

    char sex;

    date born;
    date death;   
    bool isAlive;

    int ID;

//												====Methods====
        public:
        /*Constructor*/
        person();
        person(int ID_, char sex_, std::string f_name_, std::string l_name_, int day_, int month_, int year_);
        person(int ID_, char sex_, std::string f_name_, std::string l_name_, int day_, int month_, int year_, int d_day, int d_month, int d_year);

        /*Destructor*/
        ~person();

//      :: Input
        void modFirstName(std::string new_first_name);
        void modLastName(std::string new_last_name);
        void modName(std::string new_name); //<--TO-DO

        void setMother(person* n_mother);
        void setFather(person* n_father);

        void addChild(person* n_child); //<--- WIP
        void rmChild(person* n_child);

        void modDateBorn(date n_birth);
        void modDateBorn(int day, int month, int year);

        void modisAlive(bool life);
        void modDateDeath(date death_);
        void modDateDeath(int day, int month, int year);


//      :: Output
//      -Methods relating to names
        std::string getFirname(); 
        std::string getLasname(); 
        std::string getName();  
//      -Methods relating to dates and age.
        std::string getBirthday(); // Need to make all these v
        int getBirthday_int();
        std::string getDeathdate();
        int getDeathdate_int();
        int getAge();
        float getAge_float();
        int getAgeDeath();
        float getAgeDeath_float(); // Need to make all these^
//      -Methods relating to parents and children
        person* getMother(); 
        person* getFather(); 
        bool hasOffspr();         
        std::list<person*> getOffspr(); 
        int numberOffspr(); 
//      :: Misc
        char getSex();
        int getID();
//      :: Debug
		void getStatus(); 

};

#endif