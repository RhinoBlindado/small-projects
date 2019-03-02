//  AUTHOR:     VALENTINO GLAUCO LUGLI
//  START DATE: DECEMBER - 2018

#include <iostream>
#include "familytree.h"
//                                              ====Implementation====
//      :: Internal Methods
/* setRelative
 DESCR: Add a relative (Mother or Father) to a person and add the person to the child list
 PARAM: int IDBase      ID of the base person
        int IDRelative  ID of the relative
        bool isDad      If 1 -> father; if 0 -> mother
 RETUR: N/A
*/
void f_tree::setRelative(int IDBase,int IDRelative,bool isDad)
{
    person *base = NULL,*relative = NULL,*temp;
    std::list<person*>::iterator i;

//  Perform a search through the list to find the persons
    for(i = this->listPeople.begin(); i != this->listPeople.end();++i)
    {
        temp = *i;
        if(temp->getID() == IDBase)
        {
            base = temp;
        }
        if(temp->getID() == IDRelative)
        {
            relative = temp;
        }
    }
//  If both exist in the list, then proceed to add the conection.
    if(base && relative)
    {
//      1 -> setFather; 0 -> setMother
        if(isDad)
            base->setFather(relative);
        else
            base->setMother(relative);

        relative->addChild(base);
    }
}
/* bool isOnPath
 DESCR: Helper function that determines if a given person is on the list.
 PARAM: person *act         Pointer to the chosen person
        list<person*> path  List of persons used in findPath
 RETUR: bool                TRUE if person is on list, FALSE otherwise.
*/
bool f_tree::isOnPath(person *act,std::list<person*> &path)
{
    std::list<person*>::iterator i;
    person *temp;
    bool exists = false;
    for(i = path.begin(); i != path.end();++i)
    {
        temp = *i;
        if(temp == act)
        {
            exists = true;
        }
    }

    return exists;
}

/* void findPath
 DESCR: Backtraking fuction to find a path between two relatives
 PARAM: person *act         Pointer to the current person being evaluated
        person *tgt         Pointer to the 'target' person.
        list<char> path     List that records the path, that is, how does the algorimth move on the family tree.
        vector<int> coord   Coordinates in the 'family matrix' to determine the relationship between the persons
        bool found          Boolean value to determine if a path was found.
                            Example: Person->Father->Father would be the Paternal Grandparent of a person.
 RETUR: N/A
*/
void f_tree::findPath(person *act,person *tgt,std::list<person*> &path,std::vector<int> &coord,bool &found)
{
    person *mom, *dad, *temp;
    std::list<person*> relatives;

    mom = act->getMother();
    dad = act->getFather();
    relatives = act->getOffspr();
    relatives.push_front(mom);
    relatives.push_front(dad);

    while(!relatives.empty() && !found)
    {
        temp = relatives.front();
        relatives.pop_front();
        if(temp != NULL && !isOnPath(temp,path))
        {
            path.push_front(temp);

            if(temp == mom || temp == dad)
                coord[0]++;
            else
                coord[1]++;

            if(temp == tgt)
            {
                found = true;
            }
            else
            {
                findPath(temp,tgt,path,coord,found);

                if(!found)
                {
                    path.pop_front();
                    if(temp == mom || temp == dad)
                        coord[0]--;
                    else
                        coord[1]--;
                }
            }
        }
    }
}

/* famMatrix
 DESCR: Outputs name of the relationship as a string
 PARAM: int x       Contains the x coordinate indicating the relation in a matrix.
        int y       Ditto, y coordinate.
        bool isMale Boolean value indicating if the person is male (TRUE) or female (FALSE).
 RETUR: string      Name of the relationship between the persons.
*/
std::string f_tree::famMatrix(int x, int y, bool isMale)
{
//  Initialization of the matrix of family member's name of relationship to ego.
//  It could be loaded from a file but for the time being it's hardcoded to Spanish.
    std::string str = "";
    std::string mat[5][5] =
    {
        {"Ego","Hijo/Hija","Nieto/Nieta","Bisnieto/Bisnieta","Tataranieto/Tataranieta"},
        {"Padre/Madre","Hermano/Hermana","Sobrino/Sobrina","Sobrino Nieto/Sobrina Nieta","Sobrino Bisnieto/Sobrina Bisnieta"},
        {"Abuelo/Abuela","Tio/Tia","Primo/Prima","Sobrino Segundo/Sobrina Segunda","Sobrino Nieto Segundo/Sobrina Nieta Segunda"},
        {"Bisabuelo/Bisabuela","Tio Abuelo/Tia Abuela","Tio Segundo/Tia Segunda","Primo Segundo/Prima Segunda","Sobrino Tercero"},
        {"Tatarabuelo","Tio Bisabuelo/Tia Bisabuela","Tio Abuelo Segundo/Tia Abuela Segunda","Tio Tercero/Tia Tercera","Primo Tercero/Prima Tercera"}
    };

//  If the coordinates are within the size of the matrix, just lookup the coordinate
    if(x < 5 && y < 5)
    {
        str = mat[x][y];
//      A substring is made before or after "/" depending on the sex.
        int temp = str.find_first_of("/");
        if(isMale)
            str = str.substr(0,temp);
        else
            str = str.substr(temp+1,str.size());
    }
    else
    {
        str = "Fuera de Rango";
    }

    return str;
}

//      :: Constructors and Destructors
/* f_tree
 DESCR: Basic constructor, nothing to add.
 PARAM: N/A
 RETUR: N/A
*/
f_tree::f_tree()
{
    // Mo-san a qt.
}

/* ~f_tree
 DESCR: Basic destructor, nothing to be done here.
 PARAM: N/A
 RETUR: N/A
 */
f_tree::~f_tree()
{
    // Mordred is my waifu
}

//      :: Input
/* Add a person
 DESCR: Adds a person to the "tree" data structure
 PARAM: int ID_ : ID Number (Any number, but has to be used only on one person), char sex_: A character 'M' or 'F',
        string f_name: First name, string s_name: Last name/surname, int day_ & month_ & year_: Birthday as DD/MM/YYYY.
 RETUR: N/A 
*/
void f_tree::addPerson(int ID_, char sex_, std::string f_name_, std::string l_name_, int day_, int month_, int year_)
{
    person *new_person = new person(ID_,sex_,f_name_,l_name_,day_,month_,year_);
    this->listPeople.push_front(new_person);
}

/* Add a deceased person
 DESCR: Ditto.
 PARAM: Ditto plus date of death.
 RETUR: N/A
*/
void f_tree::addPerson(int ID_, char sex_, std::string f_name_, std::string l_name_, int day_, int month_, int year_, int d_day, int d_month, int d_year)
{
    person *new_person = new person(ID_,sex_,f_name_,l_name_,day_,month_,year_,d_day,d_month,d_year);
    this->listPeople.push_front(new_person);
}

/* setMother
 DESCR: Set the mother of a person and set the person as the mother's child
 PARAM: int IDPerson    ID of the base person
        int IDMother    ID of the mother
 RETUR: N/A
*/
void f_tree::setMother(int IDPerson, int IDMother)
{
    setRelative(IDPerson,IDMother,false);
}

/* setFather
 DESCR: Set the father of a person and set the person as the father's child
 PARAM: int IDPerson    ID of the base person
        int IDFather    ID of the father
 RETUR: N/A
*/
void f_tree::setFather(int IDPerson,int IDFather)
{
    setRelative(IDPerson,IDFather,true);
}

/* setParents
 DESCR: Set the Mother and Father of a person, and set the person as their child
 PARAM: Ditto from setFather and setMother
 RETUR: N/A
*/
void f_tree::setParents(int IDPerson, int IDMother, int IDFather)
{
    setRelative(IDPerson,IDMother,false);
    setRelative(IDPerson,IDFather,true);
}

//      :: Output
/* getRelation
 DESCR: Get a string detailing the relation between two individuals
 PARAM: int PersonA ID of the first person.
        int PersonB ID of the second person.
 RETUR: string      Contains the relationshinp between the two individuals separated in two lines. Line 1 for person A and 2 for B.
                    Example: Father \n Son; Granmother \n Granchild
*/
std::string f_tree::getRelation(int PersonA, int PersonB)
{
    std::string relation = "";
    person *perA = NULL, *perB = NULL, *temp;
    std::list<person*>::iterator i;

    for(i = this->listPeople.begin(); i != this->listPeople.end();++i)
    {
        temp = *i;
        if(temp->getID() == PersonA)
            perA = temp;

        if(temp->getID() == PersonB)
            perB = temp;
    }
    
    if(perA && perB)
    {
        std::list<person*> path;
        std::vector<int> coord;
        bool found = false;

        coord.assign(2,0);
        path.push_front(perA);

        findPath(perA,perB,path,coord,found);
        relation = famMatrix(coord[0],coord[1],perB->getSex() == 'm');
    }

    return relation;
}

//      :: Debug
/* getStatus()
 DESCR: Print to CL the status of the data stuct.
 PARAM: N/A
 RETUR: N/A
*/
void f_tree::getStatus()
{
    std::cout << "\n**************************"<<std::endl;
	std::cout <<"CLASS FAMILY TREE - GET STATUS:"<<std::endl;

    std::cout <<"NUMBER OF NODES: " << this->listPeople.size() <<"\n";
    std::cout <<"MEMBERS: \n";

    std::list<person*>::iterator i;
    person *temp; int it = 1;
    for(i = this->listPeople.begin(); i != this->listPeople.end();++i)
    {
        std::cout << "#"<< it;
        it++;
        temp = *i;
        temp->getStatus();
    }

}