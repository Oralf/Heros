/*
 * Vampire.h
 *
 *  Created on: Dec 27, 2018
 *      Author: ise
 */

#ifndef VAMPIRE_H_
#define VAMPIRE_H_

#include "Creature.h"

class Vampire :public Creature {
public:
	Vampire();
	virtual ~Vampire(){};
	virtual int CreatureAttack (int numOfMe, Creature& c, int numOfC)const;
    virtual string getType() const;
};

#endif /* VAMPIRE_H_ */

