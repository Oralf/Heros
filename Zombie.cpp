/*
 * Zombie.cpp
 *
 *  Created on: Dec 27, 2018
 *      Author: ise
 */

#include "Zombie.h"

Zombie::Zombie() {
	attackLevel=2;
	defenseLevel=5;
	cost=50;

}

string Zombie:: getType() const{
	return "Zombie";
}

int Zombie::CreatureAttack (int numOfMe, Creature& c, int numOfC)const{
	int numOfDead=0;
	int totalAtt= attackLevel*numOfMe;
	if( c.getType()=="Archer"){
		totalAtt= totalAtt*2;
	}
	while( numOfC>0 && totalAtt>= c.getDefenseLevel()){
		totalAtt= totalAtt-c.getDefenseLevel();
		numOfDead++;
		numOfC--;
	}
	return numOfDead;
}
