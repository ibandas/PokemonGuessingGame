#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS //Added these definitions because there was error of c4996 (strcpy) that the compiler was not liking.

#include "PokemonLL.h"
#include <fstream> 
#include <cstring>
#include <iostream>
#include <string>
#include <time.h>


using namespace std;

int main() {
	ifstream fin; //Filestream when opening a new file
	char temp[500]; //When reading file, holds the newlines
	int num_pokemon = 0; //Number of Pokemon
	int num_of_levels = 0; //Number of Levels in the game
	int num_of_lives = 4; //Number of lives the user has
	int PokemonID;
	string PokemonGuess;
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
	int i = 0; //Used to increment through the Pokedex Object Array
	Pokemon ** Pokedex; //Holds all the pokemon from the text file
	PokemonLL *Pokemons = new PokemonLL; //Holds the pokemon from the pokedex and is used for the levels
	fin.open("PokemonPokedex.txt"); //Opens the pokedex text file with all the information about all the pokemon from the first generation
	fin >> num_pokemon; //Takes in the first line which is the number of pokemon
	Pokedex = new Pokemon *[num_pokemon]; //Dynamically allocates the Pokedex object array to the new size dependent on the number of pokemon
	while (fin.peek() != EOF) { //Reads the pokedex file and assigns all the information
		fin >> PokemonID;
		fin.getline(temp, 500, '\n');
		getline(fin, PokemonName);
		getline(fin, MainType);
		getline(fin, OffType);
		getline(fin, Ability1);
		getline(fin, Ability2);
		getline(fin, Ability3);
		getline(fin, Ability4);
		getline(fin, Attribute1);
		getline(fin, Attribute2);
		fin >> NumEvolutions;
		fin.getline(temp, 500, '\n');
		Pokedex[i] = new Pokemon(PokemonID, PokemonName, MainType, OffType, Ability1, Ability2, Ability3, Ability4, Attribute1, Attribute2, NumEvolutions);	//Places the new pokemon into the pokedex array
		i++;
	}
	fin.clear();
	fin.close();

	int k = 0; //Used to increment through shuffled pokedex array
	int r = 0; //Assigned a random value 
	srand(time(NULL));
	int number_of_pokemons[14]; //Basic array that has the number of pokemon
	int final_pokedex[14]; //Going to be the shuffled numbers of pokemon and it will read in the order so the game is shuffled always. Ex: 10 at indice 0 will bring out the 10th pokemon from the pokedex array
	for (int z = 0; z < 14; z++) //Sets the number to its own indice, 0 for 0, 1 for 1, 14 for 14
	{
		number_of_pokemons[z] = z;
	}
	for (int j = 14; j > 0; j--) //Shuffles the numbers from the previous array with no repeats to allow for random non-repeating pokemons
	{
		r = rand() % j; //Random number based on how many values left in the array
		final_pokedex[k] = number_of_pokemons[r]; //final_pokedex array is the shuffled array
		k++;
		while (r < j - 1) //Shifts the values back in the number_of_pokemons in order to get every value without repeats
		{
			number_of_pokemons[r] = number_of_pokemons[r + 1];
			r++;
		}
	}
	int number = 0; //Incremented value to take from the shuffled array
	int holder = 0; //Holds the value from each indice of the shuffled array
	holder = final_pokedex[number];
	Pokemons->AddLevel(Pokedex[holder]);
	Pokemons->ShowPokemons();
	string hint;

	while (num_of_levels < 12 && num_of_lives != 0) { //The game begins, lasts until level 12 or no more lives
		while (PokemonGuess != Pokedex[holder]->get_PokemonName())
		{
			cin >> PokemonGuess;
			if (PokemonGuess == Pokedex[holder]->get_PokemonName())
			{
				number++;
				holder = final_pokedex[number];
				Pokemons->AddLevel(Pokedex[holder]);
				num_of_levels++;
				cout << "Correct!" << endl;
				cout << "------------------------------------------------------" << endl;
				cout << "Let's move on to the next Pokemon!" << endl;
				Pokemons->ShowPokemons();
				Pokemons->NumOfLevels();
			}
			else if (PokemonGuess == "quit")
			{
				delete Pokedex;
				delete Pokemons;
				return 0;
			}
			else if (PokemonGuess == "hint" && num_of_lives != 0)
			{
				num_of_lives--;
				string ascii;
				string text_file;
				text_file = Pokedex[holder]->get_PokemonName();
				text_file = text_file + ".txt";
				fin.open(text_file);
				while (fin.peek() != EOF)
				{
					getline(fin, ascii);
					cout << ascii << endl;
				}
				fin.clear();
				fin.close();
				cout << "Current Amount of Lives: " << num_of_lives+1 << endl;
			}
			else if (num_of_lives == 0) {
				cout << "You've lost all of your lives! Try again later!" << endl;
				break;
			}
			else 
			{
				cout << "Wrong!" << endl;
				num_of_lives--;
				cout << "Current Amount of Lives: " << num_of_lives + 1 << endl;
			}
		}
		if (num_of_lives == 0 || PokemonGuess == "quit")
		{
			break;
		}
	}
	delete Pokedex;
	delete Pokemons;
	system("pause");
	return 0;
}

