Heroes: Archer.o BlackDragon.o Creature.o Hero.o main.o Necromancer.o Thief.o Vampire.o Warrior.o Wizard.o Zombie.o
	g++ Archer.o BlackDragon.o Creature.o Hero.o main.o Necromancer.o Thief.o Vampire.o Warrior.o Wizard.o Zombie.o -o Heroes
Archer.o: Archer.cpp Archer.h Creature.h
	g++ -c Archer.cpp
BlackDragon.o: BlackDragon.cpp BlackDragon.h Creature.h
	g++ -c BlackDragon.cpp
Creature.o: Creature.cpp Creature.h
	g++ -c Creature.cpp
Hero.o: Hero.cpp Hero.h Creature.h BlackDragon.h Wizard.h Archer.h Vampire.h Zombie.h
	g++ -c Hero.cpp
main.o: main.cpp Creature.h BlackDragon.h Wizard.h Archer.h Vampire.h Zombie.h Hero.h Warrior.h Necromancer.h Thief.h
	g++ -c main.cpp
Necromancer.o: Necromancer.cpp Necromancer.h Hero.h Creature.h BlackDragon.h Wizard.h Archer.h Vampire.h Zombie.h
	g++ -c Necromancer.cpp
Thief.o: Thief.cpp Thief.h Hero.h Creature.h BlackDragon.h Wizard.h Archer.h Vampire.h Zombie.h
	g++ -c Thief.cpp
Vampire.o: Vampire.cpp Vampire.h Creature.h
	g++ -c Vampire.cpp
Warrior.o: Warrior.cpp Warrior.h Hero.h Creature.h BlackDragon.h Wizard.h Archer.h Vampire.h Zombie.h
	g++ -c Warrior.cpp
Wizard.o: Wizard.cpp Wizard.h Creature.h
	g++ -c Wizard.cpp
Zombie.o: Zombie.cpp Zombie.h Creature.h
	g++ -c Zombie.cpp
clean:
	rm -f *.o
