/*
 * Creature.h
 *
 *  Created on: Dec 27, 2018
 *      Author: ise
 */

#ifndef CREATURE_H_
#define CREATURE_H_

#include <iostream>
using namespace std;

class Creature {
protected:
	int attackLevel;
	int defenseLevel;
	int cost;
public:
	Creature();
	virtual ~Creature() {};

	virtual int CreatureAttack (int numOfMe, Creature& c, int numOfC)const=0;//const?????????
	void PrintCreature ()const;

	virtual string getType() const=0;
	int getAttackLevel()const;
	int getDefenseLevel()const;
	int getCost()const;
};

#endif /* CREATURE_H_ */
