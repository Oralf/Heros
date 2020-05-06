/*
 * Creature.cpp
 *
 *  Created on: Dec 27, 2018
 *      Author: ise
 */

#include "Creature.h"

Creature::Creature() :attackLevel(0), defenseLevel(0), cost(0){ }


void Creature::PrintCreature ()const{
	cout << "Attack level: "<< attackLevel <<", Defense level: "<< defenseLevel << endl;
}

int Creature::getAttackLevel()const{
	return attackLevel;
}
int Creature::getDefenseLevel()const{
	return defenseLevel;
}
int  Creature::getCost()const{
	return cost;
}
