/*
 * Necromancer.cpp
 *
 *  Created on: Dec 27, 2018
 *      Author: ise
 */

#include "Necromancer.h"

Necromancer::Necromancer() {
	heroType="Necromancer";
}

Necromancer::Necromancer(string name){
	heroName=name;
	heroType="Necromancer";
}

Necromancer::Necromancer(string name,double newgold,int bd,int wiz, int arch, int vamp, int zomb, int tot){
	heroName=name;
	heroType="Necromancer";
	gold=newgold;
	numOfCretures[blackDragon_e]=bd;
	numOfCretures[wizard_e]=wiz;
	numOfCretures[archer_e]=arch;
	numOfCretures[vampire_e]=vamp;
	numOfCretures[zombie_e]=zomb;
	totalCreatures=tot;

}

void Necromancer::SpecialSkill(Hero* heroToStole){
	numOfCretures[zombie_e]= numOfCretures[zombie_e]+1;
	totalCreatures++;
}

