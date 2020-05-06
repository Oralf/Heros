/*
 * Vampire.cpp
 *
 *  Created on: Dec 27, 2018
 *      Author: ise
 */

#include "Vampire.h"

Vampire::Vampire() {
	attackLevel=4;
	defenseLevel=4;
	cost=80;
}

string Vampire:: getType() const{
	return "Vampire";
}

int Vampire::CreatureAttack(int numOfMe, Creature& c, int numOfC)const{
	int numOfDead=0;
	int totalAtt= attackLevel*numOfMe;
	while( numOfC>0 && totalAtt>= c.getDefenseLevel()){
		totalAtt= totalAtt-c.getDefenseLevel();
		numOfDead++;
		numOfC--;
	}
	return numOfDead;
}
