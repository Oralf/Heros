/*
 * Archer.h
 *
 *  Created on: Dec 27, 2018
 *      Author: ise
 */

#ifndef ARCHER_H_
#define ARCHER_H_

#include "Creature.h"

class Archer : public Creature{
public:
	Archer();
	virtual ~Archer() {};

	virtual int CreatureAttack (int numOfMe, Creature& c, int numOfC)const;
	virtual string getType() const;
};

#endif /* ARCHER_H_ */
