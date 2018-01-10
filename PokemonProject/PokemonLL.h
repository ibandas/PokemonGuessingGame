#ifndef OrderLL_h
#define OrderLL_h
#include "Pokemon.h"

struct LevelNode //Similar to the OrderNode, holds the Pokemon Object and connects to the next node
{
	Pokemon * pokemon;
	LevelNode * next;
};

class PokemonLL { //Singly linked-list
private:
	LevelNode *head;
	LevelNode *tail;
	int num_of_levels; //Keeps track of how many levels or nodes there are in the linked list
public:
	PokemonLL();
	~PokemonLL();
	LevelNode * createLevel(Pokemon * aPokemon); //Creates the level
	bool PokemonLL::CurrentPokemon(); //Shows the information for the current pokemon
	bool AddLevel(Pokemon * aPokemon); //Adds the next level at the end of the list with a new pokemon
	bool ModifyLevel(Pokemon * aPokemon); //Not used, but added as foundation for possible features that could be implemented if wanted
	bool DeleteLevel(Pokemon * aPokemon); //Not used, but added as a foundation for possible features that could be implemented if wanted
	bool ClearList(); //Deletes every dynamically created Pokemon and all of the nodes in the linked list
	void ShowPokemons(); //Shows all the information based on the level the user is on. The earlier levels it reveals more information than the later levels.
	int NumOfLevels();
};
#endif 
