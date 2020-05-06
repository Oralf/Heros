/*
 * Necromancer.h
 *
 *  Created on: Dec 27, 2018
 *      Author: ise
 */

#ifndef NECROMANCER_H_
#define NECROMANCER_H_

#include "Hero.h"
class Necromancer : public Hero {
public:
	Necromancer();
	virtual ~Necromancer() {};
	Necromancer(string name);
	Necromancer(string name,double newgold,int bd,int wiz, int arch, int vamp, int zomb, int tot);

	void SpecialSkill(Hero* heroToStole=NULL);
};

#endif /* NECROMANCER_H_ */
