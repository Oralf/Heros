/*
 * Warrior.cpp
 *
 *  Created on: Dec 27, 2018
 *      Author: ise
 */

#include "Warrior.h"

Warrior::Warrior() {
	heroType="Warrior";
}

Warrior::Warrior(string name){
	heroType="Warrior";
	heroName=name;
}

Warrior::Warrior(string name,double newgold,int bd,int wiz, int arch, int vamp, int zomb, int tot){
	heroName=name;
	heroType="Warrior";
	gold=newgold;
	numOfCretures[blackDragon_e]=bd;
	numOfCretures[wizard_e]=wiz;
	numOfCretures[archer_e]=arch;
	numOfCretures[vampire_e]=vamp;
	numOfCretures[zombie_e]=zomb;
	totalCreatures=tot;
}
void Warrior::SpecialSkill(Hero* heroToStole){
	 gold=gold+50;
}
