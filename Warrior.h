/*
 * Warrior.h
 *
 *  Created on: Dec 27, 2018
 *      Author: ise
 */

#ifndef WARRIOR_H_
#define WARRIOR_H_

#include "Hero.h"
class Warrior : public Hero{
public:
	Warrior();
	virtual ~Warrior() {};
	Warrior(string name);
	Warrior(string name,double newgold,int bd,int wiz, int arch, int vamp, int zomb, int tot);

	void SpecialSkill(Hero* heroToStole=NULL);
};

#endif /* WARRIOR_H_ */
