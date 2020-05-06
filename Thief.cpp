/*
 * Thief.cpp
 *
 *  Created on: Dec 27, 2018
 *      Author: ise
 */


#include "Thief.h"

Thief::Thief() {
	heroType="Thief";
}
Thief::Thief(string name){
	heroType="Thief";
	heroName=name;
}

Thief::Thief(string name,double newgold,int bd,int wiz, int arch, int vamp, int zomb, int tot){
	heroName=name;
	heroType="Thief";
	gold=newgold;
	numOfCretures[blackDragon_e]=bd;
	numOfCretures[wizard_e]=wiz;
	numOfCretures[archer_e]=arch;
	numOfCretures[vampire_e]=vamp;
	numOfCretures[zombie_e]=zomb;
	totalCreatures=tot;
}
void Thief::SpecialSkill(Hero* heroToStole){
	if(heroToStole != NULL){
		double moneyOfStolen=heroToStole->getGold();
		double howMuchto2500= 2500-gold;
		double toSteel=70;
		if(howMuchto2500<70){
			toSteel=howMuchto2500;
		}
		if(moneyOfStolen<toSteel){
			heroToStole->addGold(-moneyOfStolen);
			this->addGold(moneyOfStolen);
		}
		else{// have more then 70
			heroToStole->addGold(-toSteel);
			this->addGold(toSteel);
		}
	}
}


