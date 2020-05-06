/*
 * Hero.cpp
 *
 *  Created on: Dec 27, 2018
 *      Author: ise
 */

#include "Hero.h"

Hero::Hero() {
	gold=750;
	heroName="Name";
	heroType="Hero";
	armyCreatures[blackDragon_e]=new Black_Dragon();
	armyCreatures[wizard_e]=new Wizard();
	armyCreatures[archer_e]=new Archer();
	armyCreatures[vampire_e]=new Vampire();
	armyCreatures[zombie_e]=new Zombie();
	int i;
	for(i=0;i<5;i++){
		numOfCretures[i]=0;
	}
	totalCreatures=0;
}


Hero::Hero(string name, string type){
	gold=750;
	heroName=name;
	heroType=type;
	armyCreatures[blackDragon_e]=new Black_Dragon();
	armyCreatures[wizard_e]=new Wizard();
	armyCreatures[archer_e]=new Archer();
	armyCreatures[vampire_e]=new Vampire();
	armyCreatures[zombie_e]=new Zombie();
	int i;
	for(i=0;i<5;i++){
		numOfCretures[i]=0;
	}
	totalCreatures=0;
}


Hero::~Hero() {
	int i;
	for(i=0;i<5;i++){
		delete armyCreatures[i];
	}
}

bool Hero:: BuyCretures(string creatureType, int numToBuy){
	int totalCost=0;
	if(creatureType=="BlackDragon"){
		totalCost=(armyCreatures[blackDragon_e]->getCost()) * numToBuy;
		gold=gold-totalCost;
		numOfCretures[blackDragon_e]= numOfCretures[blackDragon_e]+ numToBuy;
		totalCreatures+= numToBuy;
		return true;
	}
	else if( creatureType=="Wizard"){
		totalCost=(armyCreatures[wizard_e]->getCost()) * numToBuy;
		gold=gold-totalCost;
		numOfCretures[wizard_e]= numOfCretures[wizard_e]+ numToBuy;
		totalCreatures+= numToBuy;
		return true;
	}
	else if (creatureType=="Archer"){
		totalCost=(armyCreatures[archer_e]->getCost()) * numToBuy;
		gold=gold-totalCost;
		numOfCretures[archer_e]= numOfCretures[archer_e]+ numToBuy;
		totalCreatures+= numToBuy;
		return true;
	}
	else if ( creatureType=="Vampire"){
		totalCost=(armyCreatures[vampire_e]->getCost()) * numToBuy;
		gold=gold-totalCost;
		numOfCretures[vampire_e]= numOfCretures[vampire_e]+ numToBuy;
		totalCreatures+= numToBuy;
		return true;
	}
	else if( creatureType=="Zombie"){
		totalCost=(armyCreatures[zombie_e]->getCost()) * numToBuy;
		gold=gold-totalCost;
		numOfCretures[zombie_e]= numOfCretures[zombie_e]+ numToBuy;
		totalCreatures+= numToBuy;
		return true;
	}
	else{
		return false;
	}
}

void Hero:: GetDailyGold(){
	gold=gold+100;
	if(gold> 2500){
		gold=2500;
	}
}


void Hero:: PrintHero ()const{
	cout << heroName<< " " << heroType <<":"<< endl;
	cout << gold << " gold"<< endl;
	bool space=false;
	if(numOfCretures[blackDragon_e] !=0 ){
		cout << numOfCretures[blackDragon_e]<< " Black_Dragon";
		space=true;
	}
	if(numOfCretures[wizard_e] !=0 ){
		if( space){
			cout<<" ";
		}
		cout << numOfCretures[wizard_e]<< " Wizard";
		space=true;
	}
	if(numOfCretures[archer_e] !=0 ){
		if( space){
			cout<<" ";
		}
		space=true;
		cout << numOfCretures[archer_e]<< " Archer";
	}
	if(numOfCretures[vampire_e] !=0 ){
		if( space){
			cout<<" ";
		}
		space=true;
		cout << numOfCretures[vampire_e]<< " Vampire";
	}
	if(numOfCretures[zombie_e] !=0){
		if( space){
			cout<<" ";
		}
		space=true;
		cout << numOfCretures[zombie_e] << " Zombie";
	}
	if(space){
		cout << "." << endl;
	}
}

void Hero:: AttackHero(Hero& defenceHero, string defenceCreature, string attackCreature)const{
	int numOfAttackC=0;
	Creature* attack;
	Creature* defence;
	if(attackCreature== "Black_Dragon"){
		numOfAttackC= numOfCretures[blackDragon_e];
		attack = new Black_Dragon;
	}
	else if( attackCreature== "Wizard"){
		numOfAttackC= numOfCretures[wizard_e];
		attack = new Wizard;
	}
	else if( attackCreature== "Archer"){
		numOfAttackC= numOfCretures[archer_e];
		attack = new Archer;
	}
	else if(attackCreature== "Vampire"){
		numOfAttackC= numOfCretures[vampire_e];
		attack = new Vampire;
	}
	else if(attackCreature== "Zombie"){
		numOfAttackC= numOfCretures[zombie_e];
		attack = new Zombie;
	}

	int  numOfDefenceC=0;
	creatureType place;
	if( defenceCreature== "Black_Dragon"){
		numOfDefenceC= defenceHero.numOfCretures[blackDragon_e];
		place = blackDragon_e;
		defence = new Black_Dragon;
	}
	else if( defenceCreature== "Wizard"){
		numOfDefenceC= defenceHero.numOfCretures[wizard_e];
		place = wizard_e;
		defence = new Wizard;
	}
	else if( defenceCreature== "Archer"){
		numOfDefenceC= defenceHero.numOfCretures[archer_e];
		place = archer_e;
		defence = new Archer;
	}
	else if(defenceCreature== "Vampire"){
		numOfDefenceC= defenceHero.numOfCretures[vampire_e];
		place = vampire_e;
		defence = new Vampire;
	}
	else if( defenceCreature== "Zombie"){
		numOfDefenceC= defenceHero.numOfCretures[zombie_e];
		place = zombie_e;
		defence = new Zombie;
	}
	int numOfDead=attack->CreatureAttack(numOfAttackC,*defence,numOfDefenceC);
	defenceHero.numOfCretures[place]-=numOfDead;
	defenceHero.setTotalCreatures(-numOfDead);
	delete attack;
	delete defence;
}

string Hero:: getName()const{
	return heroName;
}
string Hero:: getType()const{
	return heroType;
}
double Hero:: getGold()const{
	return gold;
}

void Hero:: addGold(double newGold){
	gold+=newGold;
	if(gold>2500){
		gold = 2500;
	}
	if( gold<0){
		gold=0;
	}
}


void Hero:: PrintWithoutGoldHero ()const{
	cout << heroName<< " " << heroType <<":"<< endl;
	bool space=false;
	if(numOfCretures[blackDragon_e] !=0 ){
		cout << numOfCretures[blackDragon_e]<< " Black_Dragon";
		space=true;
	}
	if(numOfCretures[wizard_e] !=0 ){
		if( space){
			cout<<" ";
		}
		cout << numOfCretures[wizard_e]<< " Wizard";
		space=true;
	}
	if(numOfCretures[archer_e] !=0 ){
		if( space){
			cout<<" ";
		}
		space=true;
		cout << numOfCretures[archer_e]<< " Archer";
	}
	if(numOfCretures[vampire_e] !=0 ){
		if( space){
			cout<<" ";
		}
		space=true;
		cout << numOfCretures[vampire_e]<< " Vampire";
	}
	if(numOfCretures[zombie_e] !=0){
		if( space){
			cout<<" ";
		}
		space=true;
		cout << numOfCretures[zombie_e] << " Zombie";
	}
	if(space){
		cout << "." << endl;
	}
}



int Hero::getNumOfCreatures(string creature)const{
	if( creature== "Black_Dragon"){
		return numOfCretures[blackDragon_e];
	}
	else if( creature== "Wizard"){
		return numOfCretures[wizard_e];
	}
	else if(creature== "Archer"){
		return numOfCretures[archer_e];
	}
	else if(creature== "Vampire"){
		return numOfCretures[vampire_e];
	}
	else if( creature== "Zombie"){
		return numOfCretures[zombie_e];
	}
	else{
		return 0;
	}
}

int Hero::getTotalCreatures()const{
	return totalCreatures;
}
void Hero:: setTotalCreatures( int toadd){
	if ( toadd !=0){
		totalCreatures+=toadd;
	}
}

