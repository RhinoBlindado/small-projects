#include <iostream>
#include "person.h"

//                                              =====Implementation=====
// 												1 Constructors and Destructors:
/* Constructor without parameters.
 DESCR: Creates an empty instance of the class.
 PARAM: N/A
 RETUR: N/A.
*/
person::person()
{
	this->f_name = "f_name not set";
	this->l_name = "l_name not set";
    this->father = NULL;
    this->mother = NULL;
	this->isAlive = true;
	//this->next_person = NULL;
	this->ID = -1;
}

/* Constructor with parameters.
 DESCR: Creates an instance with basic information: Complete name and birthday.
 PARAM: First name, last name, day of birth, month of birth, year of birth.
 RETUR: N/A
*/
person::person(int ID_, char sex_, std::string f_name_, std::string l_name_, int day_, int month_, int year_)
{
	date temp(day_,month_,year_);
	this->ID = ID_;
	this->f_name = f_name_;
	this->l_name = l_name_;
	this->sex = sex_;
	this->born.copyDate(temp);
    this->father = NULL;
    this->mother = NULL;
	this->isAlive = true;
	//this->next_person = NULL;
}

/* Constructor with parameters
 DESCR: Ditto plus date of death
 PARAM:
 RETUR:
*/
person::person(int ID_, char sex_, std::string f_name_, std::string l_name_, int day_, int month_, int year_, int d_day, int d_month, int d_year)
{
	date temp(day_,month_,year_);
	date tempD(d_day,d_month,d_year);
	this->ID = ID_;
	this->f_name = f_name_;
	this->l_name = l_name_;
	this->sex = sex_;
	this->born.copyDate(temp);
	this->death.copyDate(tempD);
    this->father = NULL;
    this->mother = NULL;
	this->isAlive = false;	
}


/* Destructor.
 DESCR: Destroys the instance.
 PARAM: N/A
 RETUR: N/A
*/
person::~person()
{
		/*WIP*/
}

//												2 Input Methods:
// Set first name.
// Parameters: First Name (string).
void person::modFirstName(std::string new_name)
{
    this->f_name = new_name;
}

//  Set last name.
// Parameters: Last Name (string).
void person::modLastName(std::string new_last_name)
{
    this->l_name = new_last_name;
}
// Set whole name.
// Parameters: Complete name (string).
void person::modName(std::string new_name)
{
	
}

// Set mother
void person::setMother(person* n_mother)
{
	this->mother = n_mother;
}

// Set father
void person::setFather(person* n_father)
{
	this->father = n_father;
}

/* Add an offspring.
 DESCR: Add a child of the person
 PARAM: The child's instace (pointer to person)
 RETUR: N/A
*/
void person::addChild(person* n_child)
{
	this->offSpr.push_front(n_child);
	//LATER ADD COMPARISON TO REMOVE DUPLICATES
}

/* Remove an offspring.
 DESCR: Removes a specific person from the list of children.
 PARAM: The specified person's instance (pointer to person).
 RETUR: N/A 
*/
void person::rmChild(person* n_child)
{
	this->offSpr.remove(n_child);
}

/* Set birthday.
 DESCR: Sets the day of birth.
 PARAM: Birthday (class date).
 RETUR: N/A.
*/
void person::modDateBorn(date birth)
{
    this->born.copyDate(birth);
}

/* Set birthday.
 DESCR: Ditto.
 PARAM: Day of birth(int), month of birth(int), year of birth(int)
 RETUR: N/A
*/
void person::modDateBorn(int day, int month, int year)
{
    date dummy(day,month,year);
    this->born.copyDate(dummy);
}

// Set living status
// Parameters: Is this person alive? (bool).
void person::modisAlive(bool life)
{
    this->isAlive = life;
}

// Set death date
// Parameters: date of death (date),
void person::modDateDeath(date death_)
{
    this->death.copyDate(death_);
}

// Set death date
// Parameters: day(int), month(int), year(int).
void person::modDateDeath(int day, int month, int year)
{
    date dummy(day,month,year);
    this->death.copyDate(dummy);
}

//													Output
/* Get first name
 DESCR: Return a string with the first name.
 PARAM: N/A
 RETUR: String
*/
std::string person::getFirname()
{
	return this->f_name;
}

/* Get last name
 DESCR: Return a string with the last name.
 PARAM: N/A
 RETUR: String
*/
std::string person::getLasname()
{
	return this->l_name;
}

/* Get whole name
 DESCR: Return a string with the whole name.
 PARAM: N/A
 RETUR: String
*/
std::string person::getName()
{
	return this->f_name + " " + this->l_name;
}

/* Get mother
 DESCR: Return a pointer to the mother of this person
 PARAM: N/A
 RETUR: Pointer to Person
*/
person* person::getMother()
{
	return this->mother;
}

/* Get father
 DESCR: Return a pointer to the father of this person
 PARAM: N/A
 RETUR: Pointer to Person
*/
person* person::getFather()
{
	return this->father;
}

/* This person has an offspring?
 DESCR: Return boolean value stating wheter the person has children
 PARAM: N/A
 RETUR: Boolean value
*/
bool person::hasOffspr()
{
	return this->offSpr.empty();
}

/* List of offsprings
 DESCR: Return a list of pointers to the children of this person.
 PARAM: N/A
 RETUR: STD List of type pointer to person
*/
std::list<person*> person::getOffspr()
{
	return this->offSpr;
}

/* Number of offsprings
 DESCR: Return the number of children
 PARAM: N/A
 RETUR: Integer
*/
int person::numberOffspr()
{
	return this->offSpr.size();
}

/* getSex
 DESCR: Obtain the sex of the person as a char
 PARAM: N/A
 RETUR: char		Contains either 'm' or 'f'.
*/
char person::getSex()
{
	return this->sex;
}

/* Get the ID number
 DESCR: Obtain the ID of this person
 PARAM: N/A
 RETUR: Integer
*/
int person::getID()
{
	return this->ID;
}

//													Debug
/* Print the status of a person.
 DESCR: Output to terminal the information an instance has.
 PARAM: N/A
 RETUR: N/A
*/
void person::getStatus()
{
//	Setting some strings that will get a lot of use.
	std::string NotS = "Not set";
	
	std::cout << "\n**************************"<<std::endl;
	std::cout <<"CLASS PERSON - GET STATUS:"<<std::endl;

//	Basic info
	std::cout <<"ID: "<<this->ID<<std::endl;
	std::cout <<"NAME: "<<this->f_name << " " << this->l_name<<std::endl;
	std::cout <<"DOB: "; 
	(this->born.getDay() < 0) ? 
	std::cout<<NotS<<std::endl : std::cout<<this->born.getDate()<<std::endl;
	std::cout <<"DOD: ";
	(this->death.getDay() < 0) ?
	std::cout<<NotS<<std::endl : std::cout<<this->death.getDate()<<std::endl;
	std::cout <<"IS ALIVE? "<<(this->isAlive)<<std::endl;

//	Relatives
	std::cout <<"MOTHER: ";
	if(this->mother != NULL)
		std::cout << this->mother->f_name <<" "<<this->mother->l_name;
	else
		std::cout << NotS;
	std::cout << std::endl;
	std::cout<<"FATHER: ";
	if(this->father != NULL)
		std::cout << this->father->f_name <<" "<< this->father->l_name;
	else
		std::cout << NotS;
	std::cout << std::endl;

//	Children
	std::cout<<"HAS CHILDREN? ";
	(this->offSpr.empty()) ? std::cout<<"No"<<std::endl : std::cout<<"Yes, "<< std::to_string(this->offSpr.size())<<std::endl;
	
//	Technical
	//std::cout<<"PERSON POINTED TO: ";
	//(this->next_person == NULL) ? std::cout<<"NULL"<<std::endl : std::cout<<this->next_person->f_name<<std::endl;
}
