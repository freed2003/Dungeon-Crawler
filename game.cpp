#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <sys/types.h>
#include <string.h>
#include <cstdlib>
using namespace std;
int cur = -1;
int currency = 0;
double health = 100;
int weapon = 0;
int armor = 0;
double weadmg[9] = {1,2,4,5,7,8,9,10,15};
string weaname[9] = {"Stick", "Blade", "Rapier", "Gold Sword", "Broad Sword", "Holy Axe", "Holy Blade", "Lengendary Blade", "MOAB(Mother of All Blades)"};
double resist[9] = {.99, .9, .85, .8, .75, .6, .55, .53, .45};
string armname[9] = {"Shirt", "Shirt and Pants", "Leather Jacket", "Chainmail Armor", "Iron Armor", "Holy Armor", "Enchanted Armor", "Lengendary Armor", "MOAA(Mother of All Armors)"};
void game();
void sp(string s);
void battle();
void room1();
void room2();
void room3();
void room4();
void room5();
void room6();
void room7();
void shop();
void boss();
bool crit();
void intro();
void drawmap(int a);
void death();
int main() {
	int res = -1;
	do {
		system("cls");
		cout << "M a i n  M e n u\n1. Play Game\n0. Exit " << endl;
		cin >> res;
		if(res == 0) return 0;
		if(res == 1) {
			int cur = 1;
			int currency = 0;
			double health = 100;
			int weapon = 0;
			int armor = 0;
			game();			
		}
	} while(res != 0);
	return 0;
}

void sp(string s) {
	int N = s.length();
      for(int i=0; i<N;i++)
      {
       Sleep(10);
       cout << s[i];
      }
      cout << "\n";
}

void game() {
	int nres;
	char res;
	sp("Welcome to the dungeon");
	sp("Many have entered, none have left");
	sp("This is your last chance, will you like to continue? Y/N");
	cin >> res;
	while(res != 'Y' && res != 'N') {
		sp("I'm waiting...");
		cin >> res;
	}
	if(res == 'Y'){
		sp("Well, good luck fighter");
		system("pause");
		cur = 1;
	} else if(res == 'N') return;
	while (cur != 9){
		if(cur == 1) room1();
		else if(cur == 2) room2();
		else if(cur == 3) room3();
		else if(cur == 4) room4();
		else if(cur == 5) room5();
		else if(cur == 6) room6();
		else if(cur == 7) room7();
		else if(cur == 8) {
			sp("Well well, it looks like you've made it to the end after all");
			sp("This is your last chance, you can continue or head back now");
			sp("Will you enter? Y/N");
			cin >> res;
			if(res == 'Y') {
				sp("Good Luck");
				boss();
			} else if(res == 'N') {
				cur = 7;
			}
		}
	}	
	sp("As you see yourself fall, the dungeon walls became to crumble");
	system("pause");
	sp("You race outside...");
	system("pause");
	system("cls");
	Sleep(800);
	sp("The sun shines into your eyes, it feels like forever since you've seen the day.");
	sp("You begin to walk away from the dungeon, a thought stays in your mind");
	system("pause");
	system("cls");
	sp("Only when we beat ourselves");
	Sleep(900);
	sp(" can we truly be happy");
	system("pause");
	Sleep(3000);
	system("cls");
	sp("Thank you so much for playing!");
	sp("Credits: Gary Song");
	sp("Hope to see you again in the future!");
}

void room1() {
	int res;
	int prob;
	do {
		system("cls");
		drawmap(1);
		sp("The room is dusty...");
		sp("What will you do?");
		Sleep(100);
		cout << "1. Look for a fight\n2. Move down\n3. Look around\n4. Check Stats" << endl;
		cin >> res;
		if(res == 1) {
			battle();
		} else if(res == 2) {
			cur = 3;
			return;
		} else if(res == 3) {
			int prob;
			prob = rand() % 10;
			if(prob < 9) {
				cout << "You found nothing" << endl;
			} else {
				cout << "You uncover a small blade" << endl;
				weapon = max(weapon, 1);
			}
			system("pause");
		} else if(res == 4) {
			cout << "Health: " << health << "\nWeapon: " << weaname[weapon] << "\nDefense: " << armname[armor] << "Currency: " << currency << endl;
			system("pause");
		} 
	} while(res !=2);
}

void room2() {
	int res;
	int prob;
	do {
		system("cls");
		drawmap(2);
		sp("This room seems enchanting");
		sp("What will you do?");
		Sleep(100);
		cout << "1. Look for a fight\n2. Move down\n3. Move right\n4. Look around\n5. Check Stats" << endl;
		cin >> res;
		if(res == 1) {
			battle();
		} else if(res == 2) {
			cur = 5;
			return;
		} else if(res == 3) {
			cur = 3;
		} else if(res == 4) {
			int prob;
			prob = rand() % 100;
			if(prob < 95) {
				cout << "You found nothing" << endl;
			} else {
				cout << "You uncover Enchanted Armor" << endl;
				armor = max(armor, 6);
			}
			system("pause");
		} else if(res == 5) {
			cout << "Health: " << health << "\nWeapon: " << weaname[weapon] << "\nDefense: " << armname[armor] << "Currency: " << currency << endl;
			system("pause");
		} 
	} while(res !=2 && res != 3);
}

void room3() {
	int res;
	int prob;
	do {
		system("cls");
		drawmap(3);
		sp("There's a glimmer in the corner");
		sp("What will you do?");
		Sleep(100);
		cout << "1. Look for a fight\n2. Move down\n3. Move right\n4. Move up\n5. Move left\n6. Look around\n7. Check Stats" << endl;
		cin >> res;
		if(res == 1) {
			battle();
		} else if(res == 2) {
			cur = 6;
			return;
		} else if(res == 3) {
			cur = 4;
		} else if(res == 4) {
			cur = 1;
		} else if(res == 5) {
			cur = 2;
		} else if(res == 6) {
			int prob;
			prob = rand() % 100;
			if(prob < 60) {
				cout << "You found nothing" << endl;
			} else {
				cout << "You grab a Gold Sword" << endl;
				weapon = max(weapon, 3);
			}
			system("pause");
		} else if(res == 7) {
			cout << "Health: " << health << "\nWeapon: " << weaname[weapon] << "\nDefense: " << armname[armor] << "Currency: " << currency << endl;
			system("pause");
		} 
	} while(res !=2 && res != 3 && res != 4 && res != 5);
}

void room4() {
	int res;
	int prob;
	do {
		system("cls");
		drawmap(4);
		sp("This room seems enchanting");
		sp("What will you do?");
		Sleep(100);
		cout << "1. Look for a fight\n2. Move down\n3. Move left\n4. Look around\n5. Check Stats" << endl;
		cin >> res;
		if(res == 1) {
			battle();
		} else if(res == 2) {
			cur = 7;
			return;
		} else if(res == 3) {
			cur = 3;
		} else if(res == 4) {
			int prob;
			prob = rand() % 100;
			if(prob < 90) {
				cout << "You found nothing" << endl;
			} else if(prob < 95) {
				cout << "You found some money!" << endl;
				currency += rand() % 6;
			} else {
				cout << "You uncover Enchanted Armor" << endl;
				armor = max(armor, 6);
			}
			system("pause");
		} else if(res == 5) {
			cout << "Health: " << health << "\nWeapon: " << weaname[weapon] << "\nDefense: " << armname[armor] << "Currency: " << currency << endl;
			system("pause");
		} 
	} while(res !=2 && res != 3);
}

void room5() {
	int res;
	int prob;
	do {
		system("cls");
		drawmap(5);
		sp("You've entered some sort of shop, there is a merchant");
		sp("What will you do?");
		Sleep(100);
		cout << "1. Look for a fight\n2. Move up\n3. Move right\n4. Look around\n5. Check Stats\n6. Open Shop\n7. Heal" << endl;
		cin >> res;
		if(res == 1) {
			cout << "Merchant: Hey, No fighting in my store!" << endl;
			system("pause");
		} else if(res == 2) {
			cur = 2;
			return;
		} else if(res == 3) {
			cur = 6;
		} else if(res == 4) {
			int prob;
			prob = rand() % 100;
			if(prob < 99) {
				cout << "Merchat: Are you trying to steal something?" << endl;
				system("pause");
			} else {
				cout << "Merchant: That's it. No Stealing from me this time" << endl;
				death();
			}
		} else if(res == 5) {
			cout << "Health: " << health << "\nWeapon: " << weaname[weapon] << "\nDefense: " << armname[armor] << "Currency: " << currency << endl;
			system("pause");
		} else if(res == 6) {
			shop();
		} else if(res == 7) {
			sp("Rest easy warrior, there is more up ahead...");
			Sleep(1000);
			cout << "Health Restored" << endl;
			health = 100;
			system("pause");
		}
	} while(res !=2 && res != 3);
}

void room6() {
	int res;
	int prob;
	do {
		system("cls");
		drawmap(6);
		sp("You feel a holy presence coming from this room");
		sp("What will you do?");
		Sleep(100);
		cout << "1. Look for a fight\n2. Move left\n3. Move up\n4. Move right\n5. Look around\n6. Check Stats" << endl;
		cin >> res;
		if(res == 1) {
			battle();
		} else if(res == 2) {
			cur = 5;
		} else if(res == 3) {
			cur = 3;
		} else if(res == 4) {
			cur = 7;
		} else if(res == 5) {
			int prob;
			prob = rand() % 100;
			if(prob < 90) {
				cout << "You found nothing" << endl;
			} else if(prob < 95) {
				cout << "You found a Holy Blade!" << endl;
				weapon = max(weapon, 6);
			} else {
				cout << "You uncover Holy Armor!" << endl;
				armor = max(armor, 5);
			}
			system("pause");
		} else if(res == 6) {
			cout << "Health: " << health << "\nWeapon: " << weaname[weapon] << "\nDefense: " << armname[armor] << "Currency: " << currency << endl;
			system("pause");
		} 
	} while(res !=2 && res != 3 && res != 4);
}
void room7() {
	int res;
	int prob;
	do {
		system("cls");
		drawmap(7);
		sp("This room gives you a legendary feeling...");
		sp("What will you do?");
		Sleep(100);
		cout << "1. Look for a fight\n2. Move left\n3. Move up\n4. Look around\n5. Check Stats\n6. Enter the final room" << endl;
		cin >> res;
		if(res == 1) {
			battle();
		} else if(res == 2) {
			cur = 6;
		} else if(res == 3) {
			cur = 4;
		} else if(res == 4) {
			int prob;
			prob = rand() % 100;
			if(prob < 90) {
				cout << "You found nothing";
			} else if(prob < 95) {
				cout << "You found a Legendary Blade!" << endl;
				weapon = max(weapon, 8);
			} else {
				cout << "You uncover Legendary Armor!" << endl;
				armor = max(armor, 8);
			}
			system("pause");
		} else if(res == 5) {
			cout << "Health: " << health << "\nWeapon: " << weaname[weapon] << "\nDefense: " << armname[armor] << "Currency: " << currency << endl;
			system("pause");
		} else if(res == 6) {
			cur = 8;
		}
	} while(res !=2 && res != 3 && res != 6);
}

void shop() {
	system("cls");
	int res = 10;
	while(res > 0) {
	cout << "Welcome to the shop! Here you can buy some great goods" << endl;
	cout << "1. MOAB\n2. MOAA\n3. Legendary Blade\n4. Legendary Armor\n5. Holy Axe\n6. Leather Jacket\n7. Stick\n8. Gold Sword\n9. Chainmail Armor\n0. Exit" << endl;
	cin >> res;
	if(res == 1) {
		if(currency >= 100) {
			currency -= 100;
			weapon = max(weapon, 8);
			cout << "You bought a MOAB for 100 coins!" << endl;
		} else {
			cout << "The MOAB costs 100 coins, you have: " << currency << endl;
		}
	}
	if(res == 2) {
		if(currency > 100) {
			currency -= 100;
			armor = max(armor, 8);
			cout << "You bought the MOAA for 100 coins!" << endl;
		} else {
			cout << "The MOAA costs 100 coins, you have: " << currency << endl;
		}
	}
	if(res == 3) {
		if(currency > 50) {
			currency -= 50;
			weapon = max(weapon, 7);
			cout << "You bought a Legendary Blade for 100 coins!" << endl;
		} else {
			cout << "The Legendary Blade costs 50 coins, you have: " << currency << endl;
		}
	}
	if(res == 4) {
		if(currency > 50) {
			currency -= 50;
			armor = max(armor, 7);
			cout << "You bought a Legendary Armor for 100 coins!" << endl;
		} else {
			cout << "The Legendary Armor costs 100 coins, you have: " << currency << endl;
		}
	}
	if(res == 5) {
		if(currency > 30) {
			currency -= 30;
			weapon = max(weapon, 5);
			cout << "You bought a Holy Axe for 30 coins!" << endl;
		} else {
			cout << "The Holy Axe costs 30 coins, you have: " << currency << endl;
		}
	}
	if(res == 6) {
		if(currency >= 10) {
			currency -= 10;
			armor = max(armor,1);
			cout << "You bought a Leather Jacket for 10 coins!" << endl;
		} else {
			cout << "The Leather Jacket costs 10 coins, you have: " << currency << endl;
		}
	}
	if(res == 7) {
		cout << "Why?" << endl;
	}
	if(res == 8) {
		if(currency >= 20) {
			currency -= 20;
			weapon = max(weapon, 3);
			cout << "You bought a Gold Sword for 20 coins!" << endl;
		} else {
			cout << "The Gold Sword costs 20 coins, you have: " << currency << endl;
		}
	}
	if(res == 9) {
		if(currency >= 15) {
			currency -= 15;
			armor = max(armor, 3);
			cout << "You bought a Chainmail Armor for 15 coins!" << endl;
		} else {
			cout << "The Chainmail Armor costs 15 coins, you have: " << currency << endl;
		}
	}
	}
	cout << "Well, See you next time!" << endl;
}

void boss() {
	int res;
	health = 100;
	bool flag = true;
	int enemyhealth = 100;
	int enemydmg = 15;
	sp("Health Restored");
	Sleep(1500);
	system("cls");
	Sleep(1500);
	sp("The room is dusty, it seems no one has been here for a while");
	system("pause");
	sp("There's a figure in the corner, he seems to be facing the wall, ignoring you");
	system("pause");
	sp("You approach him.");
	sp("\"Hey!\" you yell out, \"Turn around and face me\"");
	sp("He turns around, his face seems familiar");
	system("pause");
	sp("The man, is a clone of yourself");
	sp("He stares at you with a blank expression");
	sp("A voice echos down from the roof");
	sp("\"Now you see why no one can exit this dungeon, the final monster, is yourself\"");
	system("pause");
	sp("You grip your weapon and tighten your armor. It's time to fight");
	system("pause");
	system("cls");
	Sleep(1000);
	while(enemyhealth > 0 && health > 0) {
		cout << "\nHealth: " << health << endl;
		cout << "Enemy Health: " << enemyhealth << endl;
		cout << "Pick your action!\n1.Attack" << endl;
		cin >> res;
		if(res == 1) {
			if(crit()) {
				cout << "Your attack did " << weadmg[weapon] << "damage, Critical hit!" << endl;
				enemyhealth -= weadmg[weapon] * 2;
			} else {
				cout << "Your attack did " << weadmg[weapon] << "damage!" << endl;
				enemyhealth -= weadmg[weapon];
			}
			
			if(flag) cout << "You attacked back with " << enemydmg << "damage!(This might get a little confusing...)" << endl;
			else cout << "You attacked back with " << enemydmg << "damage!" << endl;
			health -= enemydmg * resist[armor];
		} 
	}
	if(health <= 0) {
		death();
	} else {
		cur = 9;
	}
}

void battle() {
	intro();
	int val1;
	int val2;
	int enemyhealth;
	int res;
	int enemydmg;
	const int rath = 6;
	const int trollh = 10;
	const int skelh = 10;
	const int ratdmg = 1;
	const int trolldmg = 2;
	const int skeldmg = 4;
	int det = rand() % 10;
	if(det < 5) {
		sp("You've encountered a rat");
		enemyhealth = rath;
		enemydmg = ratdmg;
		
	} else if(det < 8) {
		sp("You've encountered a troll");
		enemyhealth = trollh;
		enemydmg = trolldmg;
	} else if(det < 10) {
		sp("You've encountered a skeleton, and it's alive!");
		enemyhealth = skelh;
		enemydmg = skeldmg;
	}
	while(enemyhealth > 0 && health > 0) {
		cout << "\nHealth: " << health << endl;
		cout << "Enemy Health: " << enemyhealth << endl;
		cout << "Pick your action!\n1.Attack\n2. Run" << endl;
		cin >> res;
		if(res == 1) {
			if(crit()) {
				cout << "Your attack did " << weadmg[weapon] << " damage, Critical hit!" << endl;
				enemyhealth -= weadmg[weapon] * 2;
			} else {
				cout << "Your attack did " << weadmg[weapon] << " damage!" << endl;
				enemyhealth -= weadmg[weapon];
			}
			cout << "The enemy attacked back with " << enemydmg << " damage!" << endl;
			health -= enemydmg * resist[armor];
		} else {
			return;
		}
	}
	if(health <= 0) {
		death();
	} else {
		sp("Victory!");
		cout << "You gained " << det << "coins!" << endl;
		sp("Let's look if they dropped any loot...");
		system("pause");
		val1 = rand() % 10;
		val2 = rand() % 10;
		if(det < 5) {
			if(val1 > 6 && val1 != 9) {
				cout << "You've found a Rapier!" << endl;
				weapon = max(weapon, 2);
			} else if(val1 == 9) {
				cout << "You've found a Gold Sword";
				weapon = max(weapon, 3);
			}
			if(val2 > 6 && val2 != 9) {
				cout << "You've found Shirt and Pants!" << endl;
				armor = max(armor, 1);
			} else if(val2 == 9) {
				cout << "You've found a Leather Jacket";
				armor = max(armor, 2);
			}
			if(val2 <= 5 && val1 <= 5) {
				sp("Nothing was dropped...");
			}
		} else if(det < 8) {
			if(val1 > 6) {
				cout << "You've found a Gold Sword!" << endl;
				weapon = max(weapon, 4);
			} 
			if(val2 > 6) {
				cout << "You've found Chain Mail Armor!" << endl;
				armor = max(armor, 3);
			} 
			if(val2 <= 5 && val1 <= 5) {
				sp("Nothing was dropped...");
			}
		} else if(det < 10) {
			if(val1 > 6 && val1 != 9) {
				cout << "You've found a Broad Sword!" << endl;
				weapon = max(weapon, 5);
			} else if(val1 == 9) {
				cout << "You've found a Holy Axe!";
				weapon = max(weapon, 6);
			}
			if(val2 > 6 && val2 != 9) {
				cout << "You've found Iron Armor!" << endl;
				armor = max(armor, 4);
			} else if(val2 == 9) {
				cout << "You've found a Holy Armor";
				armor = max(armor, 5);
			}
			if(val2 <= 5 && val1 <= 5) {
				sp("Nothing was dropped...");
			}
		} 
		
	}
	system("pause");
}
bool crit() {
	int crit;
	crit = rand() % 100;
	if(crit <=10) {
		return true;
	} else {
		return false;
	}
}

void intro() {
	int i;
	int j;
	int k;
	for(i = 0; i < 10; i++) {
		if(i % 2 == 0) {
			for(j = 0; j < 10; j++) {
				system("cls");
				for(k = 0; k < i; k++) {
					cout << "\n";
				} 
				for(k = 0; k < j; k++) {
					cout << " ";
				}
				cout << "||||";
			}
		} else {
			for(j = 10; j > -1; j--) {
				system("cls");
				for(k = 0; k < j; k++) {
					cout << " ";
				}
				cout << "||||";
			}
		}
	}
	system("cls");
}


void drawmap(int a) {
	int i;
	if(a == 1){
		for(i = 0; i < 3; i++) cout << right << setw(11) << "|" << setw(10) << "    *    |" << endl;
		cout << left;
		cout << "------------------------------" << endl;
		for(i = 0; i < 3; i++) cout << setw(10) << "|" << setw(10) << "|" << setw(9) << "|" << "|" << endl;
		cout << "------------------------------" << endl;
		for(i = 0; i < 3; i++) cout << setw(10) << "|" << setw(10) << "|" << setw(9) << "|" << "|"<< endl;
	}
	else if(a == 2){
		for(i = 0; i < 3; i++) cout << right << setw(11) << "|" << setw(10) << "|" << endl;
		cout << left;
		cout << "------------------------------" << endl;
		for(i = 0; i < 3; i++) cout << setw(10) << "|    *    " << setw(10) << "|" << setw(9) << "|" << "|" << endl;
		cout << "------------------------------" << endl;
		for(i = 0; i < 3; i++) cout << setw(10) << "|" << setw(10) << "|" << setw(9) << "|" << "|"<< endl;
	}
	else if(a == 3){
		for(i = 0; i < 3; i++) cout << right << setw(11) << "|" << setw(10) << "|" << endl;
		cout << left;
		cout << "------------------------------" << endl;
		for(i = 0; i < 3; i++) cout << setw(10) << "|" << setw(10) << "|    *    " << setw(9) << "|" << "|" << endl;
		cout << "------------------------------" << endl;
		for(i = 0; i < 3; i++) cout << setw(10) << "|" << setw(10) << "|" << setw(9) << "|" << "|"<< endl;
	}
	else if(a == 4){
		for(i = 0; i < 3; i++) cout << right << setw(11) << "|" << setw(10) << "|" << endl;
		cout << left;
		cout << "------------------------------" << endl;
		for(i = 0; i < 3; i++) cout << setw(10) << "|" << setw(10) << "|" << setw(9) << "|    *   " << "|" << endl;
		cout << "------------------------------" << endl;
		for(i = 0; i < 3; i++) cout << setw(10) << "|" << setw(10) << "|" << setw(9) << "|" << "|"<< endl;
	}
	else if(a == 5){
		for(i = 0; i < 3; i++) cout << right << setw(11) << "|" << setw(10) << "|" << endl;
		cout << left;
		cout << "------------------------------" << endl;
		for(i = 0; i < 3; i++) cout << setw(10) << "|" << setw(10) << "|" << setw(9) << "|" << "|" << endl;
		cout << "------------------------------" << endl;
		for(i = 0; i < 3; i++) cout << setw(10) << "|    *    " << setw(10) << "|" << setw(9) << "|" << "|"<< endl;
	}
	else if(a == 6) {
		for(i = 0; i < 3; i++) cout << right << setw(11) << "|" << setw(10) << "|" << endl;
		cout << left;
		cout << "------------------------------" << endl;
		for(i = 0; i < 3; i++) cout << setw(10) << "|" << setw(10) << "|" << setw(9) << "|" << "|" << endl;
		cout << "------------------------------" << endl;
		for(i = 0; i < 3; i++) cout << setw(10) << "|" << setw(10) << "|    *    " << setw(9) << "|" << "|"<< endl;
	}
	else if(a == 7) {
		for(i = 0; i < 3; i++) cout << right << setw(11) << "|" << setw(10) << "|" << endl;
		cout << left;
		cout << "------------------------------" << endl;
		for(i = 0; i < 3; i++) cout << setw(10) << "|" << setw(10) << "|" << setw(9) << "|" << "|" << endl;
		cout << "------------------------------" << endl;
		for(i = 0; i < 3; i++) cout << setw(10) << "|" << setw(10) << "|" << setw(9) << "|    *   " << "|"<< endl;
	}
	cout << "------------------------------" << endl;
}

void death() {
	cout <<"You died"<<endl;
	system("pause");
	exit(0);
}
