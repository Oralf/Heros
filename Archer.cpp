/*
 * Archer.cpp
 *
 *  Created on: Dec 27, 2018
 *      Author: ise
 */

#include "Archer.h"

Archer::Archer() {
	attackLevel=5;
	defenseLevel=4;
	cost=90;
}

string Archer:: getType() const{
	return "Archer";
}

int Archer::CreatureAttack (int numOfMe, Creature& c, int numOfC)const{
	int numOfDead=0;
	int totalAtt= attackLevel*numOfMe;
	if( c.getType()=="Black Dragon"){
		totalAtt= totalAtt*1.2;
	}
	while( numOfC>0 && totalAtt>= c.getDefenseLevel()){
		totalAtt= totalAtt-c.getDefenseLevel();
		numOfDead++;
		numOfC--;
	}
	return numOfDead;
}

