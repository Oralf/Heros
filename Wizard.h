/*
 * Wizard.h
 *
 *  Created on: Dec 27, 2018
 *      Author: ise
 */

#ifndef WIZARD_H_
#define WIZARD_H_

#include "Creature.h"
class Wizard : public Creature{
public:
	Wizard();
	virtual ~Wizard() {};

	virtual int CreatureAttack (int numOfMe, Creature& c, int numOfC)const;
	virtual string getType() const;
};

#endif /* WIZARD_H_ */
