/*
 * Zombie.h
 *
 *  Created on: Dec 27, 2018
 *      Author: ise
 */

#ifndef ZOMBIE_H_
#define ZOMBIE_H_

#include "Creature.h"

class Zombie : public Creature {
public:
	Zombie();
	virtual ~Zombie() {};

	virtual int CreatureAttack (int numOfMe, Creature& c, int numOfC)const;
	virtual string getType() const;
};

#endif /* ZOMBIE_H_ */
