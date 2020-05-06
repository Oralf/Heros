/*
 * Hero.h
 *
 *  Created on: Dec 27, 2018
 *      Author: ise
 */

#ifndef HERO_H_
#define HERO_H_

#include <iostream>
using namespace std;
#include "Creature.h"
#include "BlackDragon.h"
#include "Wizard.h"
#include "Archer.h"
#include "Vampire.h"
#include "Zombie.h"

typedef enum creatureType {blackDragon_e,wizard_e,archer_e,vampire_e,zombie_e} creatureType;
using namespace std;

class Hero {
protected:
	string heroName;
	string heroType;
	double gold;
	Creature* armyCreatures[5];
	int numOfCretures[5];
	int totalCreatures;

public:
	Hero();
	virtual ~Hero();
	Hero(string name, string type);

	virtual void SpecialSkill(Hero* heroToStole=NULL)=0;
	bool BuyCretures(string creatureType, int num);
	void GetDailyGold();
	void AttackHero(Hero& defenceHero, string defenceCreature, string attackCreature)const;
	void PrintHero ()const;
	void PrintWithoutGoldHero ()const;

	string getName()const;
	string getType()const;
	double getGold()const;
	void addGold(double newGold);
	int getNumOfCreatures(string creature)const;
	int getTotalCreatures()const;
	void setTotalCreatures( int toadd);
	void EndTurn() {};


};

#endif /* HERO_H_ */
