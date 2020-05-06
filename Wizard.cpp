/*
 * Wizard.cpp
 *
 *  Created on: Dec 27, 2018
 *      Author: ise
 */

#include "Wizard.h"

Wizard::Wizard() {
	attackLevel=8;
	defenseLevel=2;
	cost=150;
}

string Wizard:: getType() const{
	return "Wizard";
}

int Wizard::CreatureAttack (int numOfMe, Creature& c, int numOfC)const{
	int numOfDead=0;
	int totalAtt= attackLevel*numOfMe;
	while( numOfC>0 && totalAtt>= c.getDefenseLevel()){
		totalAtt= totalAtt-c.getDefenseLevel();
		numOfDead++;
		numOfC--;
	}
	return numOfDead;
}



