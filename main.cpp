/*
 * main.cpp
 *
 *  Created on: Dec 27, 2018
 *      Author: ise
 */

#include <iostream>
using namespace std;

#include "Creature.h"
#include "BlackDragon.h"
#include "Wizard.h"
#include "Archer.h"
#include "Vampire.h"
#include "Zombie.h"
#include "Hero.h"
#include "Warrior.h"
#include "Necromancer.h"
#include "Thief.h"

#include <sys/stat.h>
#include <fstream>
#include <cstdlib>
#include <dirent.h>


bool isValidName(string name){
	int i;
	char a;
	if( name.length()>31){
		return false;
	}
	for(i=0;i<name.length();i++){
		a=name[i];
		if(a == ' '){
			return false;
		}
		if( !(a<='z' && a>='a') && !(a<='Z' && a>='A')&& !(a>='0'&& a<='9')){
			return false;
		}
	}
	return true;
}


int main(int argc, char *argv[]){

	bool notVal=false;
	bool gotGold= false;
	bool specialSkill = false;
	int realNumPlayer=0;
	int roundNum=1;
	int currPlayer=0;
	int fromUser=0;

	Hero* tempPlayer[9];
	int i;
	for( i=0;i<9;i++){
		tempPlayer[i]=NULL;
	}

	if( argc==2){
		ifstream filename;
		filename.open("Game/gameDetails.txt");
		string gameDet[15];
		string line;
		int k=0;
		while( getline(filename, line)){
			gameDet[k]=line;
			k++;
		}
		filename.close();


		realNumPlayer=atoi(gameDet[0].c_str());
		string arrayDet[9];
		int n;
		for(n=0;n<realNumPlayer;n++){
			string filePath="Players/"+gameDet[n+1]+"/Details.txt";
			ifstream playerDet;
			playerDet.open(filePath.c_str());
			string line1;
			int g=0;
			while( getline(playerDet, line1)){
				arrayDet[g]=line1;
				g++;
			}
			playerDet.close();


			double gold = atof(arrayDet[2].c_str());
			int numBD= atoi(arrayDet[3].c_str());
			int numWiz=atoi(arrayDet[4].c_str());
			int numArch=atoi(arrayDet[5].c_str());
			int numVamp=atoi(arrayDet[6].c_str());
			int numZomb=atoi(arrayDet[7].c_str());
			int totalCreat=atoi(arrayDet[8].c_str());

			if(arrayDet[1]=="Warrior"){
				tempPlayer[n]= new Warrior(arrayDet[0],gold,numBD,numWiz,numArch,numVamp,numZomb,totalCreat);
			}
			else if(arrayDet[1]=="Thief"){
				tempPlayer[n]= new Thief(arrayDet[0],gold,numBD,numWiz,numArch,numVamp,numZomb,totalCreat);
			}
			else{
				tempPlayer[n]= new Necromancer(arrayDet[0],gold,numBD,numWiz,numArch,numVamp,numZomb,totalCreat);
			}
		}//for all players in temp
		currPlayer=atoi(gameDet[realNumPlayer+1].c_str());
		int goldBool= atoi(gameDet[realNumPlayer+2].c_str());
		if(goldBool==0){
			gotGold=false;
		}
		else{
			gotGold=true;
		}
		int specBool= atoi(gameDet[realNumPlayer+3].c_str());
		if(specBool==0){
			specialSkill=false;
		}
		else{
			specialSkill=true;
		}
		roundNum=atoi(gameDet[realNumPlayer+4].c_str());

		int m;
		for(m=0;m<realNumPlayer;m++){
			string fileToDelete="Players/"+gameDet[m+1]+"/Details.txt";
			string folderToDelete="Players/"+gameDet[m+1];
			remove(fileToDelete.c_str());
			remove(folderToDelete.c_str());
		}
		remove("Players");
		remove("Game/gameDetails.txt");
		remove("Game");

	}// if argc==2

	else if( argc==5){
		// delete all the details of the old game!!!!
		struct stat myst;
		if ((stat("Game", &myst)==0) && S_ISDIR(myst.st_mode)){//HERO
			ifstream filename;
			filename.open("Game/gameDetails.txt");
			string array[15];
			string line;
			int i=0;
			while( getline(filename, line)){
				array[i]=line;
				i++;
			}
			filename.close();

			if( (stat("Players",&myst)==0) && S_ISDIR(myst.st_mode)){
				string first= array[0];
				int numOfOld= atoi(first.c_str());
				int m;
				for(m=0;m<numOfOld;m++){
					string fileToDelete="Players/"+array[m+1]+"/Details.txt";
					string folderToDelete="Players/"+array[m+1];
					remove(fileToDelete.c_str());
					remove(folderToDelete.c_str());
				}
			}
			remove("Players");
			remove("Game/gameDetails.txt");
			remove("Game");
		}


		int numOfW= atoi(argv[2]);
		int numOfT= atoi(argv[3]);
		int numOfN= atoi(argv[4]);
		if (numOfW<0 || numOfT<0 || numOfN<0 || numOfW>3 || numOfT>3 || numOfN>3){
			cout<< "The arguments you inserted are not valid"<<endl;
			fromUser=7;
			notVal=true;
		}
		else{
			realNumPlayer=0;
			realNumPlayer= numOfN+ numOfT+ numOfW;
			int randomPlace;
			string name;
			int j;
			for(j=0; j<numOfW; j++){
				cout << "Please insert warrior number "<< j+1<<" name:"<< endl;
				try{
					//string error1= "name is not valid";
					getline(cin,name);


					if(!isValidName(name)){
						throw invalid_argument("name is not valid");
					}
					else{
						randomPlace= rand()%9;
						while( tempPlayer[randomPlace] !=NULL){
							randomPlace= rand()%9;
						}
						tempPlayer[randomPlace]=new Warrior(name);
					}
				}
				catch (const invalid_argument& e) {
					cout << "name is not valid"<< endl;
					j=j-1;
				}
			}
			int k;
			for(k=0; k<numOfT; k++){
				cout << "Please insert thief number "<< k+1<<" name:"<< endl;
				try{
					//string error2="name is not valid";
					getline(cin,name);
					if(!isValidName(name)){
						throw invalid_argument("name is not valid");
					}
					else{
						randomPlace= rand()%9;
						while( tempPlayer[randomPlace] !=NULL){
							randomPlace= rand()%9;
						}
						tempPlayer[randomPlace]=new Thief(name);
					}
				}
				catch (const invalid_argument& e) {
					cout << "name is not valid"<< endl;
					k--;
				}
			}
			int t;
			for(t=0; t<numOfN; t++){
				cout << "Please insert necromancer number "<< t+1<<" name:"<< endl;
				try{
					//string error3="name is not valid";
					getline(cin,name);
					if(!isValidName(name)){
						throw invalid_argument("name is not valid");
					}
					else{
						randomPlace= rand()%9;
						while( tempPlayer[randomPlace] !=NULL){
							randomPlace= rand()%9;
						}
						tempPlayer[randomPlace]=new Necromancer(name);
					}
				}
				catch (const invalid_argument& e) {
					cout << "name is not valid"<< endl;
					t--;
				}
			}
		}
	}//else if argc==5

	Hero* Players[9];//!!!!!!!!!!!!
	int y;
	for(y=0;y<9;y++){
		Players[y]=NULL;
	}
	int e;
	int in=0;
	for(e=0;e<9;e++){
		if( tempPlayer[e] != NULL){
			Players[in]= tempPlayer[e];
			in++;
		}
	}

	int numOfPlaying=realNumPlayer;

	bool iDiedInAttack=false;
	bool winnerInGame=false;

	while( fromUser !=7){
		// the menu!!!
		cout << "Welcome " << Players[currPlayer]->getName() << endl;
		cout << "What is your next step in the path to victory?" << endl;
		cout << "1. Attack" << endl;
		cout << "2. Get daily gold" << endl;
		cout << "3. Buy creatures" << endl;
		cout << "4. Show details" << endl;
		cout << "5. Special skill" << endl;
		cout << "6. End of my turn" << endl;
		cout << "7. Exit" << endl;
		cin >> fromUser;
		cin.ignore();//!!!
		switch (fromUser) {

		case 1:

			int attackMenu;
			cout << "1. Show me my opponents"<< endl;
			cout << "2. Attack hero"<< endl;
			cin >> attackMenu;
			cin.ignore();//!!!
			switch (attackMenu) {
			case 1:
			{
				int counter=1;
				int i;
				for(i=0; i< numOfPlaying;i++){
					if( Players[i]->getType()== "Warrior" && i!= currPlayer){
						if(counter !=numOfPlaying-1){
							cout << Players[i]->getName() << " Warrior"<< endl;
							counter++;
						}
						else{
							cout << Players[i]->getName() << " Warrior";
						}

					}
				}
				int j;
				for(j=0; j< numOfPlaying;j++){
					if( Players[j]->getType()== "Thief"&& j!=currPlayer){
						if(counter !=numOfPlaying-1){
							cout << Players[j]->getName() << " Thief"<< endl;
							counter++;
						}
						else{
							cout << Players[j]->getName() << " Thief";
						}
					}
				}
				int k;
				for(k=0; k< numOfPlaying;k++){
					if( Players[k]->getType()== "Necromancer"&& k!=currPlayer){
						if(counter !=numOfPlaying-1){
							cout << Players[k]->getName() << " Necromancer"<< endl;
							counter++;
						}
						else{
							cout << Players[k]->getName() << " Necromancer";
						}
					}
				}
				cin.get();
				break;
			}//case 1
			break;
			case 2:
			{
				if( roundNum<=3 ){
					cout << "you can not attack in the first three rounds"<< endl;
					break;
				}//if
				else{
					bool found= false;
					int index=-1;
					while( !found){
						string opponentName;
						cout << "Please insert your opponent name:";
						getline(cin,opponentName);
						//cin.ignore();//!!!
						int i;
						for(i=0; i< numOfPlaying && !found; i++){
							if( Players[i]->getName() == opponentName){
								index=i;
								found = true;
							}
						}
						try{
							//string error4="no player with this name";
							if(!found){
								throw invalid_argument("name is not valid");
							}
						}
						catch ( const invalid_argument& e ){
							cout << "there is no player with this name"<< endl;
						}
						try {
							//string errorYou="you cant attack yourself";
							if(index==currPlayer){
								found=false;
								throw invalid_argument("you cant attack yourself");
							}
						}
						catch(const invalid_argument& e ){
							cout <<"you cant attack yourself" << endl;
						}
					}
					int turn=0;
					bool someoneDead=false;
					Players[currPlayer]->PrintWithoutGoldHero();
					//cout << endl;
					Players[index]->PrintWithoutGoldHero();

					while( !someoneDead){
						if( turn%2==0){// attacker in the one with the turn
							bool creatureOk=false;
							string attackName;
							string defenceName;
							if(Players[index]->getTotalCreatures()==0){// defence not have army
								creatureOk=true;
							}
							else{// defence  have army
								int count2=0;
								while (!creatureOk){
									if(count2 !=0){
										Players[currPlayer]->PrintWithoutGoldHero();
										//cout << endl;
										Players[index]->PrintWithoutGoldHero();
									}
									count2++;
									string creatures;
									cout << Players[currPlayer]->getName() <<"'s turn:"<< endl;
									getline(cin,creatures);
									try{
										//string eror5="not good name";
										int indexSpace=creatures.find(" ");
										attackName= creatures.substr(0,indexSpace);
										defenceName= creatures.substr(indexSpace+1);
										if(indexSpace ==-1){
											throw invalid_argument("name is not valid");
										}
										if(Players[currPlayer]->getNumOfCreatures(attackName)==0){
											throw invalid_argument("name is not valid");
										}
										if(Players[index]->getNumOfCreatures(defenceName)==0){
											throw invalid_argument("name is not valid");
										}
										creatureOk=true;
									}//try
									catch(const invalid_argument& e){
										cout<< "you dont have this creature in your army" << endl;
									}
								}// while creatureOk
								Players[currPlayer]->AttackHero(*Players[index],defenceName,attackName);
								if( Players[index]->getTotalCreatures()!=0){
									Players[index]->PrintWithoutGoldHero();
									//cout << endl;
									Players[currPlayer]->PrintWithoutGoldHero();
								}
							}//else- defence have army
							if( Players[index]->getTotalCreatures()==0){
								someoneDead= true;
								cout << "you have been victorious"<< endl;
								Players[currPlayer]->addGold(Players[index]->getGold());
								Hero* temp = Players[index];
								int j;
								for (j=index;j<numOfPlaying-1;j++){
									Players[j]=Players[j+1];
								}
								Players[numOfPlaying-1]= temp;
								numOfPlaying--;
								if(currPlayer>index){
									currPlayer--;
								}
								if(numOfPlaying==1){
									winnerInGame= true;
									cout << Players[currPlayer]->getName() << " is the winner!"<< endl;
								}
							}//if dead
						}// if turn%2==0
						else{// turn of defence
							bool creatureOk=false;
							string attackName;
							string defenceName;
							int count1=0;
							while(!creatureOk){
								string creatures;
								if(count1 !=0){
									Players[index]->PrintWithoutGoldHero();
									//cout << endl;
									Players[currPlayer]->PrintWithoutGoldHero();
								}
								count1++;
								cout << Players[index]->getName() <<"'s turn:"<< endl;

								getline(cin,creatures);
								try{
									//string eror6="not good name";
									int indexSpace=creatures.find(" ");
									attackName= creatures.substr(0,indexSpace);
									defenceName= creatures.substr(indexSpace+1);
									if( Players[currPlayer]->getTotalCreatures()==0){
										creatureOk=true;
									}
									else{
										if(indexSpace ==-1){
											throw invalid_argument("name is not valid");
										}
										if( Players[index]->getNumOfCreatures(attackName)==0){
											throw invalid_argument("name is not valid");
										}
										if(Players[currPlayer]->getNumOfCreatures(defenceName)==0){
											throw invalid_argument("name is not valid");
										}
										creatureOk=true;
									}
								}//try
								catch(const invalid_argument& e){
									cout<< "you dont have this creature in your army" << endl;
								}

							}// while creatureOk

							Players[index]->AttackHero(*Players[currPlayer],defenceName,attackName);
							if( Players[currPlayer]->getTotalCreatures()!=0){
								Players[currPlayer]->PrintWithoutGoldHero();
								//cout << endl;
								Players[index]->PrintWithoutGoldHero();
							}
							if( Players[currPlayer]->getTotalCreatures()==0){
								someoneDead= true;
								cout << "You have been perished"<< endl;
								Players[index]->addGold(Players[currPlayer]->getGold());
								Hero* temp = Players[currPlayer];
								int j;
								for (j=currPlayer;j<numOfPlaying-1;j++){
									Players[j]=Players[j+1];
								}
								Players[numOfPlaying-1]= temp;
								numOfPlaying--;
								iDiedInAttack=true;
								if( numOfPlaying==1){
									winnerInGame=true;
									iDiedInAttack=false;
									cout << Players[index]->getName() << " is the winner!"<< endl;
								}
							}// if someone dead
						}//else
						turn ++;
					}// while someone dead
				}// else
			}// case 2
			break;

			default:
				break;

			}// switch
			break;

			case 2:
				if(!gotGold){
					Players[currPlayer]->addGold(100);
					gotGold=true;
				}
				break;

			case 3:
				int creatureToBuy;
				cout << "1. Buy Zombies."<< endl;
				cout << "2. Buy Archers."<< endl;
				cout << "3. Buy Vampire."<< endl;
				cout << "4. Buy Wizard."<< endl;
				cout << "5. Buy Black Dragon."<< endl;
				cin >> creatureToBuy;
				cin.ignore();//!!!

				switch (creatureToBuy) {
				case 1:
				{
					Zombie zomb;
					zomb.PrintCreature();
					int numToBuy;
					cin >> numToBuy;
					cin.ignore();//!!!
					double total= zomb.getCost() * numToBuy;
					try{
						//string error7="your buy not accepted";
						if (Players[currPlayer]->getGold()< total || total <=0){
							throw invalid_argument("name is not valid");
						}
						Players[currPlayer]->BuyCretures("Zombie",numToBuy);
						break;
					}
					catch(const invalid_argument& e){
						cout << "your buy has not been accepted" << endl;
						break;
					}
				}
				break;
				case 2:
				{
					Archer arch;
					arch.PrintCreature();
					int numToBuy;
					cin >> numToBuy;
					cin.ignore();//!!!
					double total= arch.getCost() * numToBuy;
					try{
						//string error8 = "your buy not accepted";
						if (Players[currPlayer]->getGold()< total || total <=0){
							throw invalid_argument("name is not valid");
						}
						Players[currPlayer]->BuyCretures("Archer",numToBuy);
						break;
					}
					catch( const invalid_argument& e){
						cout << "your buy has not been accepted" << endl;
						break;
					}
				}
				break;
				case 3:
				{
					Vampire vamp;
					vamp.PrintCreature();
					int numToBuy;
					cin >> numToBuy;
					cin.ignore();//!!!
					double total= vamp.getCost() * numToBuy;
					try{
						//string error9 = "your buy not accepted";
						if (Players[currPlayer]->getGold()< total || total <=0){
							throw invalid_argument("name is not valid");
						}
						Players[currPlayer]->BuyCretures("Vampire",numToBuy);
						break;
					}
					catch(const invalid_argument& e){
						cout << "your buy has not been accepted" << endl;
						break;
					}
				}
				break;
				case 4:
				{
					Wizard wiz;
					wiz.PrintCreature();
					int numToBuy;
					cin >> numToBuy;
					cin.ignore();//!!!
					double total= wiz.getCost() * numToBuy;
					try{
						//string error10="your buy not accepted";
						if (Players[currPlayer]->getGold()< total || total <=0){
							throw invalid_argument("name is not valid");
						}
						Players[currPlayer]->BuyCretures("Wizard",numToBuy);
						break;
					}
					catch(const invalid_argument& e){
						cout << "your buy has not been accepted" << endl;
						break;
					}
				}
				break;
				case 5:
				{
					Black_Dragon black;
					black.PrintCreature();
					int numToBuy;
					cin >> numToBuy;
					cin.ignore();//!!!
					double total= black.getCost() * numToBuy;
					try{
						//string error11="your buy not accepted";
						if (Players[currPlayer]->getGold()< total || total <=0){
							throw invalid_argument("name is not valid");
						}
						Players[currPlayer]->BuyCretures("BlackDragon",numToBuy);
						break;
					}
					catch(const invalid_argument& e){
						cout << "your buy has not been accepted" << endl;
						break;
					}
				}
				break;
				default:
					// what to do in defualt?!?!
					break;
				}
				break;

				case 4:
				{
					Players[currPlayer]->PrintHero();
				}
				break;

				case 5:
				{
					if(specialSkill){
						//cout << "you already used your special skill in this turn" << endl;
						break;
					}
					else{
						if( Players[currPlayer]->getType() == "Warrior"){
							Players[currPlayer]->SpecialSkill();
							specialSkill=true;
							cout << "Gold added successfully" << endl;
							break;
						}
						else if ( Players[currPlayer]->getType() == "Thief"){
							string robbedName;
							cout << "Please insert hero name:"<< endl;
							cin >> robbedName;
							cin.ignore();//!!!
							int i;
							int index;
							bool found= false;
							for(i=0; i< numOfPlaying && !found; i++){
								if( Players[i]->getName() == robbedName){
									index=i;
									found = true;
								}
							}
							if(found){
								if(Players[index]->getGold()==0){
									specialSkill=true;
								}
								else{
									Players[currPlayer]->SpecialSkill(Players[index]);
									specialSkill=true;
								}
							}
							else{
								cout << "player not found"  << endl;
							}
							break;
						}
						else{
							Players[currPlayer]->SpecialSkill();
							specialSkill=true;
							cout << "Zombie added successfully" << endl;
							break;
						}
					}
				}
				break;

				case 6:
					//int i;
					//for(i=0;i<numOfPlaying;i++){
					//	Players[i]->PrintHero();
					//}
					currPlayer++;
					if(currPlayer == numOfPlaying){
						roundNum ++;
						currPlayer=0;
					}


					gotGold=false;
					specialSkill=false;
					iDiedInAttack=false;
					winnerInGame=false;
					break;

				case 7:
				{

					mkdir("Players", 0777);
					mkdir("Game", 0777);

					//WRITING IN FILES
					int i;
					string folderPath;
					string name;
					string filePath;
					for( i=0;i<numOfPlaying;i++){
						//make folder with name
						name = Players[i]->getName();//revi
						folderPath="Players/"+name;//Debug/Players/revi
						mkdir(folderPath.c_str(), 0777);
						filePath=folderPath+"/Details.txt";//Debug/Players/revi/Details.txt
						ofstream fileDetails(filePath.c_str());

						fileDetails<< Players[i]->getName()<< endl;//revi
						fileDetails<< Players[i]->getType()<< endl;//Worrior
						fileDetails << Players[i]->getGold() << endl;
						fileDetails << Players[i]->getNumOfCreatures("Black_Dragon")<< endl;
						fileDetails << Players[i]->getNumOfCreatures("Wizard")<< endl;
						fileDetails << Players[i]->getNumOfCreatures("Archer")<< endl;
						fileDetails << Players[i]->getNumOfCreatures("Vampire")<< endl;
						fileDetails << Players[i]->getNumOfCreatures("Zombie")<< endl;
						fileDetails << Players[i]->getTotalCreatures()<< endl;//total

					}


					ofstream gameDetails("Game/gameDetails.txt");
					gameDetails<< numOfPlaying << endl;
					int h;
					for(h=0;h<numOfPlaying;h++){
						gameDetails<< Players[h]->getName()<<endl;
						//gameDetails<< Players[h]->getType()<< endl;
					}
					gameDetails<< currPlayer<< endl;
					gameDetails<< gotGold<< endl;
					gameDetails<< specialSkill<< endl;
					gameDetails<< roundNum<< endl;


					//DELETE THE PROGRAM
					int j;
					for(j=0;j<9;j++){
						delete Players[j];
					}
				}
				break;

				default:
					break;
		}
		if(iDiedInAttack){
			if(currPlayer == numOfPlaying){
				currPlayer=0;
			}
			gotGold=false;
			specialSkill=false;
			iDiedInAttack=false;
			winnerInGame=false;

		}
		if(winnerInGame){
			//DELETE THE PROGRAM
			int j;
			for(j=0;j<9;j++){
				delete Players[j];
			}
			fromUser=7;
		}
	}
	if(notVal){
		int j;
		for(j=0;j<9;j++){
			delete Players[j];
		}

	}
	return 0;
}




