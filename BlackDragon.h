/*
 * BlackDragon.h
 *
 *  Created on: Dec 27, 2018
 *      Author: ise
 */

#ifndef BLACKDRAGON_H_
#define BLACKDRAGON_H_
#include "Creature.h"

class Black_Dragon : public Creature {
public:
	Black_Dragon();
	virtual ~Black_Dragon(){};

	virtual int CreatureAttack (int numOfMe, Creature& c, int numOfC)const;
	virtual string getType() const;
};

#endif /* BLACKDRAGON_H_ */


