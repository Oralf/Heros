/*
 * BlackDragon.cpp
 *
 *  Created on: Dec 27, 2018
 *      Author: ise
 */

#include "BlackDragon.h"

Black_Dragon::Black_Dragon() {
	attackLevel=9;
	defenseLevel=10;
	cost=200;
}

string Black_Dragon:: getType() const{
	return "BlackDragon";
}

int Black_Dragon:: CreatureAttack (int numOfMe, Creature& c, int numOfC)const{
	int numOfDead=0;
	int defence=c.getDefenseLevel();
	int totalAtt= attackLevel*numOfMe;
	if(c.getType()== "Wizard"){
		defence= defence*2;
	}
	while( numOfC>0 && totalAtt>= defence){
		totalAtt= totalAtt-defence;
		numOfDead++;
		numOfC--;
	}
	return numOfDead;
}
