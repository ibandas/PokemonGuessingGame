#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS //Added these definitions because there was error of c4996 (strcpy) that the compiler was not liking.
#include <iostream>
#include "Pokemon.h"


using namespace std;


Pokemon::Pokemon() {
	PokemonID = 0;
	PokemonName = '\0';
	MainType = '\0';
	OffType = '\0';
	Ability1 = '\0';
	Ability2 = '\0';
	Ability3 = '\0';
	Ability4 = '\0';
	Attribute1 = '\0';
	Attribute2 = '\0';
	NumEvolutions = 0;
}

Pokemon::Pokemon(int pID, string pName, string MT, string OT, string A1, string A2, string A3, string A4, string Att1, string Att2, int Evo) {
	PokemonID = pID;
	PokemonName = pName;
	MainType = MT;
	OffType = OT;
	Ability1 = A1;
	Ability2 = A2;
	Ability3 = A3;
	Ability4 = A4;
	Attribute1 = Att1;
	Attribute2 = Att2;
	NumEvolutions = Evo;
}


Pokemon::~Pokemon() 
{
	
}
//Getters and Setters below for each part of the Pokemon
bool Pokemon::set_PokemonID(int pID)
{
	PokemonID = pID;
	return true;
}
bool Pokemon::set_PokemonName(string pName)
{
	PokemonName = pName;
	return true;
}
bool Pokemon::set_MainType(string MT)
{
	MainType = MT;
	return true;
}
bool Pokemon::set_OffType(string OT)
{
	OffType = OT;
	return true;
}
bool Pokemon::set_Ability1(string A1) 
{
	Ability1 = A1;
	return true;
}
bool Pokemon::set_Ability2(string A2)
{
	Ability2 = A2;
	return true;
}
bool Pokemon::set_Ability3(string A3)
{
	Ability3 = A3;
	return true;
}
bool Pokemon::set_Ability4(string A4)
{
	Ability4 = A4;
	return true;
}
bool Pokemon::set_Attribute1(string Att1)
{
	Attribute1 = Att1;
	return true;
}
bool Pokemon::set_Attribute2(string Att2)
{
	Attribute2 = Att2;
	return true;
}
bool Pokemon::set_NumEvolutions(int Evo)
{
	NumEvolutions = Evo;
	return true;
}
int Pokemon::get_PokemonID()
{
	return PokemonID;
}
string Pokemon::get_PokemonName()
{
	return PokemonName;
}
string Pokemon::get_MainType()
{
	return MainType;
}
string Pokemon::get_OffType()
{
	return OffType;
}
string Pokemon::get_Ability1()
{
	return Ability1;
}
string Pokemon::get_Ability2()
{
	return Ability2;
}
string Pokemon::get_Ability3()
{
	return Ability3;
}
string Pokemon::get_Ability4()
{
	return Ability4;
}
string Pokemon::get_Attribute1()
{
	return Attribute1;
}
string Pokemon::get_Attribute2()
{
	return Attribute2;
}
int Pokemon::get_NumEvolutions()
{
	return NumEvolutions;
}

void Pokemon::write_consoleEasy() //Gives all the information of the Pokemon to the user in the beginning, making it easy
{
	cout << "PokemonID: #" << PokemonID << endl;
	cout << "MainType: " << MainType << endl;
	cout << "OffType: " << OffType << endl;
	cout << "Ability1: " << Ability1 << endl;
	cout << "Ability2: " << Ability2 << endl;
	cout << "Ability3: " << Ability3 << endl; 
	cout << "Ability4: " << Ability4 << endl;
	cout << "Attribute1: " << Attribute1 << endl; 
	cout << "Attribute2: " << Attribute2 << endl;
	cout << "Number of Evolutions: " << NumEvolutions << endl;
	cout << "What's that Pokemon?!" << endl;
}

void Pokemon::write_consoleMedium() //Gives less information to the user, making the game harder now
{
	cout << "PokemonID: #" << PokemonID << endl;
	cout << "MainType: " << MainType << endl;
	cout << "Ability1: " << Ability1 << endl;
	cout << "Ability2: " << Ability2 << endl;
	cout << "Attribute1: " << Attribute1 << endl;
	cout << "Number of Evolutions: " << NumEvolutions << endl;
	cout << "What's that Pokemon?!" << endl;
}

void Pokemon::write_consoleHard() //Gives less information making the game harder
{
	cout << "PokemonID: #" << PokemonID << endl;
	cout << "MainType: " << MainType << endl;
	cout << "Ability1: " << Ability1 << endl;
	cout << "Attribute1: " << Attribute1 << endl;
	cout << "Number of Evolutions: " << NumEvolutions << endl;
	cout << "What's that Pokemon?!" << endl;

}

void Pokemon::write_consoleLegendary() //Gives the least amount of information making the game harder
{
	cout << "PokemonID: #" << PokemonID << endl;
	cout << "OffType: " << OffType << endl;
	cout << "Ability1: " << Ability1 << endl;
	cout << "Number of Evolutions: " << NumEvolutions << endl;
	cout << "What's that Pokemon?!" << endl;
}