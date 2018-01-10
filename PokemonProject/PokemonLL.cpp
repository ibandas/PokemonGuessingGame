#include <iostream>
#include <cstring>
#include <string>
#include "PokemonLL.h"

using namespace std;
PokemonLL::PokemonLL() //Constructor
{
	head = NULL;
	tail = NULL;
	num_of_levels = 0;
}

PokemonLL::~PokemonLL() //Destructor
{
	ClearList();
}

bool PokemonLL::AddLevel(Pokemon * aPokemon) //Adds a new level at the end of the linked list
{
	num_of_levels++;
	LevelNode *temp = createLevel(aPokemon);
	if (head == NULL)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
	return true;
}

bool PokemonLL::ModifyLevel(Pokemon * aPokemon) //Not needed, mentioned for future features if wanted
{
	return true;
}

LevelNode * PokemonLL::createLevel(Pokemon* aPokemon) //Creates the node that holds the pokemon information that will be used in the AddLevel
{
	LevelNode * node = new LevelNode();
	node->pokemon = aPokemon;
	node->next = NULL;
	return node;
}

bool PokemonLL::DeleteLevel(Pokemon * aPokemon) //Not needed, mentioned for future features if wanted
{
	return true;
}

bool PokemonLL::ClearList() //Deletes each dynamically allocated object at each node and deletes the nodes to not have memory leaks
{
	LevelNode *temp;
	LevelNode * current;
	temp = head;
	while (temp != NULL)
	{
		current = temp; //Current will be deleted
		temp = temp->next; //Next node will be remembered before deletion
		delete current; //Delete current node
	}
	head = tail = NULL; //Set head and tail to null for future PokemonLL
	return true;
}

bool PokemonLL::CurrentPokemon() //Grabs the current pokemon name
{
	LevelNode *temp;
	temp = tail;
	tail->pokemon->get_PokemonName();
	return true;
}

void PokemonLL::ShowPokemons() //Gives the information of the pokemon, easier at earlier levels, and harder at later levels
{
	if (num_of_levels <= 3)
	{
		tail->pokemon->write_consoleEasy();
	}
	else if (num_of_levels <= 6)
	{
		tail->pokemon->write_consoleMedium();
	}
	else if (num_of_levels <= 9)
	{
		tail->pokemon->write_consoleHard();
	}
	else
	{
		tail->pokemon->write_consoleLegendary();
	}
}

int PokemonLL::NumOfLevels() //Returns the number of levels in the current linked list
{
	cout << "Number of Levels: " << num_of_levels << endl;
	return num_of_levels;
}