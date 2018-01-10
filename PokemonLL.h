//
//  OrderLL.h
//  Orders
//
//  Created by Maria Saenz on 10/7/16.
//  Copyright © 2016 Maria Saenz. All rights reserved.
//

#ifndef OrderLL_h
#define OrderLL_h
#include "Pokemon.h"

struct LevelNode
{
	Pokemon * pokemon;
	LevelNode * next;
};

class PokemonLL {
private:
	LevelNode *head;
	LevelNode *tail;
	int num_of_levels;
public:
	PokemonLL();
	~PokemonLL();
	LevelNode * createLevel(Pokemon * aPokemon);
	bool AddLevel(Pokemon * aPokemon);
	bool ModifyLevel(Pokemon * aPokemon);
	bool DeleteLevel(Pokemon * aPokemon);
	bool ClearList();
	void ShowPokemons();
	int NumOfLevels();
};
#endif /* OrderLL_h */5
