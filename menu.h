#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "interfaces.h"
#include <math.h>
#include <cstdlib>
#include <ctime>
//#include "characters.h"

using namespace std;

class character {
	public:
	int strenght;
	int agillity;
	int intelligence;
	int character_class;
	int health_points;
	int mana_points;
	int dmg;
	int defense;
	int attack;
	int stamina;
	character (int str, int agi, int intel, int char_class){
		this -> strenght = str;
		this -> agillity = agi;
		this -> intelligence = intel;
		this -> character_class = char_class;
		if (this -> character_class == 1)
		{
			this -> health_points = 1000 + 20 * this -> strenght;
			this -> stamina = 100 + this -> strenght * 2; 
			this -> mana_points = 1000 + 10 * this -> intelligence;
			this -> dmg = 5 + this -> agillity + 2 * this -> strenght;
			this -> defense = 25 + this -> agillity;
			this -> attack = 25 + this -> agillity;
		}
		else if (this -> character_class == 2)
		{
			this -> health_points = 1000 + 10 * this -> strenght;
			this -> stamina = 100 + this -> strenght;
			this -> mana_points = 1000 + 10 * this -> intelligence;
			this -> dmg = 5 + 2 * this -> agillity + this -> strenght;
			this -> defense = 25 + 2 * this -> agillity;
			this -> attack = 25 + 2 * this -> agillity;
		}
		else if (this -> character_class == 3)
		{
			this -> health_points = 1000 + 10 * this -> strenght;
			this -> stamina = 100 + this -> strenght;
			this -> mana_points = 1000 + 20 * this -> intelligence;
			this -> dmg = 5 + this -> agillity + this -> strenght;
			this -> defense = 25 + this -> agillity;
			this -> attack = 25 + this -> agillity;
		}
	}
	void show_attributes(){
		string c_class;
		if (this -> character_class == 1) c_class = "knight";
		else if (this -> character_class == 2) c_class = "hunter";
		else if (this -> character_class == 3) c_class = "mage";
		cout << "str: " << this -> strenght << endl << "agi: " << this -> agillity << endl << "int: " << this -> intelligence << endl << "class: " << c_class << endl;
		cout << "healt points: " << this -> health_points << endl << "mana points: " << this -> mana_points << endl << "damage: " << this -> dmg << endl << "defense rate: " << this -> defense << endl << "attack rate: " << this -> attack << endl << "stamina: " << this -> stamina << endl;
	}
	void add_attributes(int number, int dyscypline)
	{
		if (dyscypline == 1)
		{
			this -> strenght = this -> strenght + number;
			if (this -> character_class == 1){
				this -> health_points = this -> health_points + number * 20;
				this -> dmg = this -> dmg + 2 * number;
				this -> stamina = this -> stamina + number * 2;
			}
			else {
				this -> health_points = this -> health_points + number * 10;
				this -> dmg = this -> dmg + 1 * number;
				this -> stamina = this -> stamina + number;
			}
		}
		else if (dyscypline == 2)
		{
			this -> agillity = this -> agillity + number;
			if (this -> character_class == 2){
				this -> defense = this -> defense + number * 2;
				this -> dmg = this -> dmg + 2 * number;
				this -> attack = this -> attack + number * 2;
			}
			else {
				this -> defense = this -> defense + number;
				this -> dmg = this -> dmg + number;
				this -> attack = this -> attack + number;
			}
		}
		else if (dyscypline == 3)
		{
			this -> intelligence = this -> intelligence + number;
			if (this -> character_class == 3){
				this -> intelligence = this -> intelligence + number * 2;
			}
			else this -> intelligence = this -> intelligence + number;
		}		
	}
	void take_damage (int dmg, int attack){
		float temp = 0;
		int store;
		int hit;
		float chance = (((float)attack / (float)this -> defense) * 50);
		if (chance > 50) 
		{
			temp = chance - 50;
			temp = sqrt(temp);
			chance = 50 + temp * 3;
		}
		else if (chance < 50)
		{
			temp = 50 - chance;
			temp = sqrt(temp);
			chance = 50 - temp * 3;
		}
		if (chance > 95) chance = 95;
		else if (chance < 5) chance = 5;
		srand(time(0));
		hit = (rand()%100);
		if (hit <= chance){
			this -> stamina = this -> stamina - 10;
			if (this -> stamina < 1)
			{
				cout << "character's stamina has depleted, his efficiency begins to drop!" << endl;
				this -> defense = this -> defense - 3;
				this -> attack = this -> attack - 3;
			}
			store = this -> health_points;
			this -> health_points = this -> health_points - dmg;
			if (this -> health_points < 0) this -> health_points = 0;
			cout << "character took " << dmg << " damage and his health pool was reduced from " << store << " to " << this -> health_points << endl << "his current stamina is equal to " << this -> stamina << endl;
		}
		else {
			this -> stamina = this -> stamina + 2;
			cout << "character's armour has succesfully blocked the attack and his health pool remains at " << this -> health_points << " points" << endl << "his stamina has increased and is now at " << this -> stamina << endl;
		}
	}
};
class menu {
	public:
	class settings {
		public: 
		int starting_attributes;
		int player_number;
		void set_starting_attributes(){
			int attributes;
			cin >> attributes;
			if (attributes > 100 || attributes < 10) {
				cout << "inserted value incorrect, insert again" << endl;
				set_starting_attributes();
			}
			else this -> starting_attributes = attributes;
		}
	};	
	char selected;	
	int attribs = 50;
	void initialization(){
		cout << "---------------welcome-----------------" << endl;
	}
	void Menu(){
		cout << endl << "---------------select one of the following-----------" << endl;
		cout << endl << "--------------------start a new game-----------------" << endl;
		cout << endl << "----------------------instructions-------------------" << endl;
		cout << endl << "------------------------options----------------------" << endl;
		cout << endl << "-------------------------exit------------------------" << endl;
		cin >> this -> selected;
		this -> actions(this -> selected);
	}
	void actions (char action){
		settings *S1 = new settings;
		char anykey;
		if (action == '1')
		{
			system ("cls");
			this -> set_starting_parameters();
		}
		else if (action == '2')
		{
			system ("cls");
			this -> instructions();
		}
		else if (action == '3')
		{
			system ("cls");
			this -> show_settings(*S1);
		}
		else if (action == '4')
		{
			system ("cls");
			this -> exit_game();
		}
		else 
		{
			system ("cls");
			cout << "action not allowed, try again (press any key to continue)" << endl;
			cin >> anykey;
			system ("cls");
			this -> Menu();
		}
	}
	void show_settings(settings &S1)
	{
		int action;
		cout << "1. set the starting attributes, default is 50, max is 100 and min is 10" << endl;
		cin >> action;
		if (action == 1){
			cout << endl << "insert: ";
			S1.set_starting_attributes();
			this -> attribs = S1.starting_attributes;
			system ("cls");
			this -> Menu();
		}
		else this -> show_settings(S1);
	}
	void set_starting_parameters(){
		int spare;
		char anykey;
		int str;
		char start;
		int agi;
		int intel;
		int char_class;
		char question;
		cout << "you have " << this -> attribs << " attribute points to spent for each character" << endl << " you also have to select the class for them" << endl << "press any key to continue";
		cin >> anykey;
		system ("cls");
		cout << "instert the strenght for the first character" << endl;
		cin >> str;
		if (str > this -> attribs || str < 0) {
			this -> attribute_error();
		}
		cout << "instert the agility for the first character" << endl;
		cin >> agi;
		if ((agi + str) > this -> attribs || agi < 0) {
			this -> attribute_error();
		}		
		cout << "instert the inteligence for the first character" << endl;
		cin >> intel;
		if ((agi + str + intel) > this -> attribs || intel < 0) {
			this -> attribute_error();
		}
		cout << "instert the class for the first character" << endl;
		cin >> char_class;
		if (char_class > 3)
		{
			this -> attribute_error();
		}
		character* First = new character (str, agi, intel, char_class); 
		if ((str+agi+intel) < this -> attribs)
		{
			cout << "you still have " << (this -> attribs-(str+agi+intel)) << " spare points left, would you like to spend them? (y = yes, n = no)" << endl;
			cin >> question;
			if (question == 'y')
			{
				system ("cls");
				spare = (this -> attribs-(str+agi+intel));
				cout << "how many strenght points would you like to send?" << endl;
				cin >> str;
				if (str > spare)
				{
					this -> attribute_error();
				}
				cout << "how many agillity points would you like to send?" << endl;
				cin >> agi;
				if ((agi + str) > spare)
				{
					this -> attribute_error();
				}
				cout << "how many intelligence points would you like to send?" << endl;
				cin >> intel;
				if ((str + agi + intel) > spare)
				{
					this -> attribute_error();
				}
				First -> add_attributes(str, 1);
				First -> add_attributes(agi, 2);
				First -> add_attributes(intel, 3);
			}
			else {}
		}
		system ("cls");
		cout << "now for the second chcracter you have " << this -> attribs << " attribute points to spent and a class to choose" << endl << "press any key to continue";
		cin >> anykey;
		system ("cls");
		cout << "instert the strenght for the second character" << endl;
		cin >> str;
		if (str > this -> attribs || str < 0) {
			this -> attribute_error();
		 }
		cout << "instert the agility for the second character" << endl;
		cin >> agi;
		if ((agi + str || agi < 0) > this -> attribs) {
			this -> attribute_error();
		}		
		cout << "instert the inteligence for the second character" << endl;
		cin >> intel;
		if ((agi + str + intel || intel < 0) > this -> attribs) {
			this -> attribute_error();
		}
		cout << "instert the class for the second character" << endl;
		cin >> char_class;
		if (char_class > 3)
		{
			this -> attribute_error();
		}
		character* Second = new character (str, agi, intel, char_class); 
		if ((str+agi+intel) < this -> attribs)
		{
			cout << "you still have " << (this -> attribs-(str+agi+intel)) << " spare points left, would you like to spend them? (y = yes, n = no)" << endl;
			cin >> question;
			if (question == 'y')
			{
				system ("cls");
				spare = (this -> attribs-(str+agi+intel));
				cout << "how many strenght points would you like to send?" << endl;
				cin >> str;
				if (str > spare)
				{
					this -> attribute_error();
				}
				cout << "how many agillity points would you like to send?" << endl;
				cin >> agi;
				if ((agi + str) > spare)
				{
					this -> attribute_error();
				}
				cout << "how many intelligence points would you like to send?" << endl;
				cin >> intel;
				if ((str + agi + intel) > spare)
				{
					this -> attribute_error();
				}
				Second -> add_attributes(str, 1);
				Second -> add_attributes(agi, 2);
				Second -> add_attributes(intel, 3);
			}
			else {}
		}
		system ("cls");
		cout << "------------First character------------" << endl << endl; 
		First -> show_attributes();
		cout << endl << endl << "------------Second character-----------" << endl << endl; 
		Second -> show_attributes();
		cout << endl << endl <<endl << "------------------GAME IS READY, PRESS ANY KEY TO CONTINUE----------------------" << endl;
		cin >> start;
		game_instance *Game_one = new game_instance;
		Game_one -> run_session (*First, *Second);
	}
	void attribute_error(){
		char anykey;
		cout << "you cannot spent more than " << this -> attribs << " attribute points for a single character, insert attributes again (press anykey to continue)" << endl;
		cin >>anykey;
		system ("cls");
		this -> set_starting_parameters();
	}
	void instructions(){
		char anykey;
		cout << "in this game u choose 3 characters, set their starting attributes and abilities and fight a turn based battle with your opponent" << endl;
		cout << "press any key to go back to the main menu";
		cin >> anykey;
		system ("cls");
		this -> Menu();
	}
	void options(){
		
	}
	void exit_game(){
		char choice;
		cout << "do your really want to exit? (y = yes, n = no)" << endl;
		cin >> choice;
		system ("cls");
		if (choice == 'y') exit(0);
		else if (choice == 'n'){
			system ("cls");
			this -> Menu(); 
		}
		else {
			cout << "data incorrect, try again" << endl;
			this -> exit_game();
		}
	}
	class game_instance {
	public:
		bool player = false;
		void run_session (character& object, character& object1){
			string action;
			char accept;
			while(1){
				this -> next_turn (this -> player);
				cout << "choose the action you want to perform, type 'attack' if you want to attack" << endl;
				cin >> action;
				if (action == "attack")
				{
					if (this -> player == true) object1.take_damage (object.dmg, object.attack);
					else object.take_damage (object1.dmg, object1.attack);
				}
				if (object1.health_points <= 0){
					this -> victory (2, 1);
				}
				if (object.health_points <= 0){
					this -> victory (1, 2);
				}
				cout << "turn over, press anything to continue" << endl;
				cin >> accept;
				system ("cls");
			}
		}
		void next_turn(bool who){
			if(who == true){
				cout << "it's player 2's' turn!" << endl;
				this -> player = false;
			}
			else{
				cout << "it's player 1's' turn!" << endl;
				this -> player = true;
			}
		}
		void victory (int one, int two){
			int z = one, k = two;
			string action;
			cout << "player's " << one << " health points have been reduced to 0 therefore player " << two << " wins, congratulations" << endl << endl << "what do you want to do? type 'menu' if you would like to come back to main menu or 'exit' if you want to exit" << endl;
			cin >> action; 
			if (action == "menu"){
				menu *new_menu = new menu;
				new_menu -> Menu();
			}
			else if (action == "exit") exit (0);
			else {
				system ("cls");
				this -> victory(z, k);
			}
		}
	};
};

