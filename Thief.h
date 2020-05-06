/*
 * Thief.h
 *
 *  Created on: Dec 27, 2018
 *      Author: ise
 */


#ifndef THIEF_H_
#define THIEF_H_

#include "Hero.h"


class Thief: public Hero{
public:
    Thief();
    Thief(string name);
    Thief(string name,double newgold,int bd,int wiz, int arch, int vamp, int zomb, int tot);
    virtual ~Thief(){};
    void SpecialSkill(Hero* heroToStole=NULL);
};

#endif

