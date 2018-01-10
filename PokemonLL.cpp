#include <iostream>
#include <cstring>
#include <string>
#include "PokemonLL.h"

using namespace std;
PokemonLL::PokemonLL()
{
	head = NULL;
	tail = NULL;
	num_of_levels = 0;
}

PokemonLL::~PokemonLL()
{
	ClearList();
}

bool PokemonLL::AddLevel(Pokemon * aPokemon)
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

bool PokemonLL::ModifyLevel(Pokemon * aPokemon)
{
	return true;
}

LevelNode * PokemonLL::createLevel(Pokemon* aPokemon)
{
	LevelNode * node = new LevelNode();
	node->pokemon = aPokemon;
	node->next = NULL;
	return node;
}

bool PokemonLL::DeleteLevel(Pokemon * aPokemon)
{
	return true;
}

bool PokemonLL::ClearList()
{
	LevelNode *temp;
	temp = head;
	while (temp->next != NULL)
	{
		delete temp->pokemon;
		delete temp;
		temp = temp->next;
	}
	delete temp->pokemon;
	return true;
}

void PokemonLL::ShowPokemons()
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

int PokemonLL::NumOfLevels()
{
	cout << "Number of Levels: " << num_of_levels << endl;
	return num_of_levels;
}