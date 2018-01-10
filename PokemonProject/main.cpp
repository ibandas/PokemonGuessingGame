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
	char temp[500]; //When reading file, holds the newlines (blank lines)
	int num_pokemon = 0; //Number of Pokemon
	int num_of_levels_main = 1; //Number of Levels in the game
	int num_of_lives = 4; //Number of lives the user has (5 lives actually)
	int PokemonID;
	string PokemonGuess; //user input to guess the pokemon
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
	string hint;
	string ascii; //Used for pictures of pokemon, logo, and instruction menu
	string text_file; //Used to get the name of the current pokemon in order to open the file with the picture of the current pokemon
	string start; //Used for the user to type start to begin the game
	int i = 0; //Used to increment through the Pokedex Object Array
	Pokemon ** Pokedex; //Holds all the pokemon from the text file
	PokemonLL *Pokemons = new PokemonLL; //Holds the pokemon from the pokedex and is used for the levels
	fin.open("PokemonPokedex.txt"); //Opens the pokedex text file with all the information about all the pokemon from the first generation
	fin >> num_pokemon; //Takes in the first line which is the number of pokemon
	Pokedex = new Pokemon *[num_pokemon]; //Dynamically allocates the Pokedex object array to the new size dependent on the number of pokemon
	while (fin.peek() != EOF) { //Reads the pokedex file, creates a new Pokemon object and inputs it into a dynamically allocated array that holds those objects.
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
	int number_of_pokemons[134]; //Basic array that has the same number at each indice (0 for 0, 1 for 1, 14 for 14)
	int final_pokedex[134]; //Going to be the shuffled numbers of pokemon and it will read in the order so the game is shuffled always. Ex: 10 at indice 0 will bring out the 10th pokemon from the pokedex array
	for (int z = 0; z < num_pokemon; z++) //Sets the number to its own indice, 0 for 0, 1 for 1, 14 for 14
	{
		number_of_pokemons[z] = z;
	}
	for (int j = num_pokemon; j > 0; j--) //Shuffles the numbers from the previous array with no repeats to allow for random non-repeating pokemons
	{
		r = rand() % j; //Random number based on how many values left in the array
		final_pokedex[k] = number_of_pokemons[r]; //Sets each incremented indice (k) to a random value from the range of numbers given in the number_of_pokemons
		k++;
		while (r < j - 1) //Shifts the values back in the number_of_pokemons in order to get every value without repeats
		{
			number_of_pokemons[r] = number_of_pokemons[r + 1];
			r++;
		}
	}
	int number = 0; //Incremented value to take from the shuffled array
	int holder = 0; //Holds the value from each indice of the shuffled array

	fin.open("PokemonLogo.txt"); //Reads the logo information
	while (fin.peek() != EOF)
	{
		getline(fin, ascii);
		cout << ascii << endl;
	}
	fin.clear();
	fin.close();

	fin.open("instruction.txt"); //Reads the instruction or help information
	while (fin.peek() != EOF)
	{
		getline(fin, ascii);
		cout << ascii << endl;
	}
	fin.clear();
	fin.close();

	holder = final_pokedex[number]; //Gets the number from the array of shuffled numbers. Say 10 is in indice zero, it will take the 10th pokemon from the Pokemon Pokedex array
	Pokemons->AddLevel(Pokedex[holder]); //Adds the current pokemon to the Linked List that holds all the levels
	while (start != ("start")) //Until the user types start to begin the game
	{
		cout << ">>";
		cin >> start;
		if (start == "start")
		{
			cout << "-------------------------------------------------------------------" << endl;
			Pokemons->ShowPokemons(); //Shows all the information of the current pokemon based on the level the user is on
			cout << "Current Level: " << num_of_levels_main << endl;

			while (num_of_levels_main != 12 && num_of_lives != 0) { //The game begins, lasts until level 12 or no more lives
				while (PokemonGuess != Pokedex[holder]->get_PokemonName()) //Loops until the user can guess the correct pokemon
				{
					if (num_of_levels_main != 12) //Until the last level of the game, the user is allowed to input guesses. When its level 12, the game is over, and they have won
					{
						cout << ">>";
						cin >> PokemonGuess;
					}
					else if (num_of_levels_main == 12) //If the level is on 12 now, the user has one and is told they won
					{
						cout << "Congratulations! You have beat the Amazing Pokemon Guessing Game!" << endl;
						for (int y = 0; y < num_pokemon; y++) //Deletes each Pokemon object at each indice
						{
							delete Pokedex[y];
						}
						delete[] Pokedex; //Deletes the Pokedex array completely
						Pokemons->ClearList(); //Deletes the Pokemon objects and all the nodes in the linked list
						system("pause");
						return 0;
					}
					if (PokemonGuess == Pokedex[holder]->get_PokemonName() && num_of_levels_main != 12) //If the user guesses the pokemon correct and the level is not the final level yet, it moves on to the next level
					{
						number++; //Incremented value used to get the next random value in the next indice of the shuffled array
						holder = final_pokedex[number]; //Gets the random number from the indice of the shuffled array
						Pokemons->AddLevel(Pokedex[holder]); //Picks the pokemon from the Pokedex using the random value from the shuffled array and adding it to the levels linked list
						num_of_levels_main++;
						cout << "Correct!" << endl;
						if (num_of_levels_main != 12) //As long as it's not the final level, it will show the next level
						{
							cout << "------------------------------------------------------" << endl;
							cout << "Let's move on to the next Pokemon!" << endl;
							Pokemons->ShowPokemons();
							cout << "Current Level: " << num_of_levels_main << endl;
						}
					}
					else if (PokemonGuess == "quit") //Exits the game if the user types "quit"
					{
						cout << "Bye!" << endl;
						for (int y = 0; y < num_pokemon; y++)
						{
							delete Pokedex[y];
						}
						delete[] Pokedex;
						Pokemons->ClearList();
						system("pause");
						return 0;
					}
					else if (PokemonGuess == "help") //Prints out the instruction again if the user types "help"
					{
						fin.open("instruction.txt");
						while (fin.peek() != EOF)
						{
							getline(fin, ascii);
							cout << ascii << endl;
						}
						fin.clear();
						fin.close();
					}
					else if (PokemonGuess == "hint" && num_of_lives != 0) //Gives a picture of the pokemon with a loss of a life if the user types "hint"
					{
						num_of_lives--;
						text_file = Pokedex[holder]->get_PokemonName(); //Gets the name of the pokemon
						text_file = text_file + ".txt"; //Adds .txt to the name of the pokemon so that it opens up the picture from their file
						fin.open(text_file);
						while (fin.peek() != EOF)
						{
							getline(fin, ascii);
							cout << ascii << endl;
						}
						fin.clear();
						fin.close();
						cout << "Current Amount of Lives: " << num_of_lives + 1 << endl; //Shows how many lives the user has left
					}
					else if (PokemonGuess == "life") //Tells the user how many lives they have left
					{
						cout << "Current Amount of Lives: " << num_of_lives + 1 << endl;
					}
					else if (num_of_lives == 0) { //Once the user gets to zero lives, the game exits while telling the user it ended
						cout << "You've lost all of your lives! Try again later!" << endl;
						for (int y = 0; y < num_pokemon; y++)
						{
							delete Pokedex[y];
						}
						delete[] Pokedex;
						Pokemons->ClearList();
						system("pause");
						return 0;
					}
					else //If none of the above is prompted, the user has most likely guessed wrong, and a life is subtracted
					{
						cout << "Wrong!" << endl;
						num_of_lives--;
						cout << "Current Amount of Lives: " << num_of_lives + 1 << endl;
					}
				}
			}
		}
		else if (start == "quit")
		{
			cout << "Bye!" << endl;
			for (int y = 0; y < num_pokemon; y++)
			{
				delete Pokedex[y];
			}
			Pokemons->ClearList();
			delete[] Pokedex;
			system("pause");
			return 0;
		}
		else //If the user didn't input start, it will prompt them to type start
		{
			cout << "Input start!" << endl;
		}
	}
}

