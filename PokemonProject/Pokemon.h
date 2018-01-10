#ifndef Pokemon_h
#define Pohemon_h
#include <string>
using namespace std;

class Pokemon{

private:
	int PokemonID;
	string PokemonName;
	string MainType;
	string OffType;
	string Ability1;
	string Ability2;
	string Ability3;
	string Ability4;
	string Attribute1;
	string Attribute2;
	int NumEvolutions;

public:
	Pokemon(); //Constructor
	Pokemon(int pID, string pName, string MT, string OT, string A1, string A2, string A3, string A4, string Att1, string Att2, int Evo); //Creates a new Pokemon based on the Pokedex text file
	~Pokemon(); //Destructor (not really needed)
	//Setters
	bool set_PokemonID(int pID);
	bool set_PokemonName(string pName);
	bool set_MainType(string MT);
	bool set_OffType(string OT);
	bool set_Ability1(string A1);
	bool set_Ability2(string A2);
	bool set_Ability3(string A3);
	bool set_Ability4(string A4);
	bool set_Attribute1(string Att1);
	bool set_Attribute2(string Att2);
	bool set_NumEvolutions(int Evo);
	//Getters
	int get_PokemonID();
	string get_PokemonName();
	string get_MainType();
	string get_OffType();
	string get_Ability1();
	string get_Ability2();
	string get_Ability3();
	string get_Ability4();
	string get_Attribute1();
	string get_Attribute2();
	int get_NumEvolutions();
	//Writes out the information based on the level the user is on, giving less information at higher levels
	void write_consoleEasy();
	void write_consoleMedium();
	void write_consoleHard();
	void write_consoleLegendary();
};
#endif