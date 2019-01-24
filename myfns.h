#pragma once

#include <cstdlib>
#include <iostream>

using namespace std;

class Party;
class Character;
class SmallMonsterParty;
class BigMonsterParty;

class Monster {
public:
    string name;
    int health;
    int target;
    int close_ability;
    int ranged_ability;
    int accuracy;
    bool isLiving;
    bool isClose;
    bool isIdle;
    int char_rand1 = rand() % 36;
    int char_rand2 = rand() % 20;

    void advance(){isClose = true;}
    void isDead(){isLiving = false; cout << name << " has been slain!" << endl;}
    void setTarget(int t){target = t;}

    virtual void attack(Character *c, int count) = 0;
    virtual ~Monster() = 0;
};


class Character {
    friend class Monster;

public:
    string name;
    int MAX_HEALTH;
    int health;
    int wealth;
    int target;
    int ranged_ability;
    int close_ability;
    int accuracy = 80;
    bool isLiving;
    bool isClose;
    bool isIdle;
    int char_rand = rand() % 50;
    int age = (rand() % 20) + 20;
    int mana;
    int time_of_death;
    string killer;

    void isDead(){isLiving = false; cout << "The hero " << name << " is dead!" << endl;}
    void advance(){isClose = true;}
    void setTarget(int t){target = t;}

    virtual void attack(Party p, Monster *m) = 0;
    virtual void battleCry() = 0;
    virtual ~Character() = 0;
};

class Warrior: public Character {
public:
    Warrior();
    void battleCry() override {cout<<"My Name is "<<name<<" and I am a Warrior"<<endl;}
    void attack(Party p, Monster *m) override;
    ~Warrior() override = default; //?
};

class Spells{
    friend class AttackMage;
    friend class DefenderMage;
    friend class Warlock;
private:
    const char* spell_name;
    int damage;
    int protection;
    int cost;
public:
    Spells(const char* n, int d, int p, int c) : spell_name(n), damage(d), protection(p), cost(c) {}
};

class AttackMage: public Character {
private:
    Spells spell1;
    Spells spell2;
    Spells spell3;
public:
    AttackMage();
    ~AttackMage() override = default;
    void castSpell(Monster *m);
    void battleCry() override {cout<<"My Name is "<<name<<" and I am an offensive mage"<<endl;}
    void attack(Party p, Monster *m) override;

};

class DefenderMage: public Character {
private:
    Spells spell1;
    Spells spell2;
    Spells spell3;
public:
    DefenderMage();
    ~DefenderMage() override = default;
    void castSpell(Party p, Monster *m);
    void battleCry() override {cout<<"My Name is "<<name<<" and I am an defensive mage"<<endl;}
    void attack(Party p, Monster *m) override;

};

class Rogue: public Character {
public:
    Rogue();
    void battleCry() override {cout<<"My Name is "<<name<<" and I am a rogue"<<endl;};
    void attack(Party p, Monster *m) override;
    ~Rogue() override = default;
};

class RandomCharacter{
private:
    int random = (rand()%4)+1;
public:
    Character *character;
    RandomCharacter();

};

class Weakling: public Monster {
public:
    Weakling();
    void attack(Character *c, int count) override;
    ~Weakling() override = default;

};

class Goblin: public Monster{
public:
    Goblin();
    void attack(Character *c, int count) override;
    ~Goblin() override = default;
};


class Warlock: public Monster{
private:
    int mana;
    Spells spell1;
    Spells spell2;
    Spells spell3;
public:
    Warlock();
    void castSpell(Character *c);
    void attack(Character *c, int count) override;
    ~Warlock() override = default;
};

class Dragon: public Monster{
public:
    Dragon();
    void attack(Character *c, int count) override;
    ~Dragon() override = default;
};

class Goliath: public Monster{
public:
    Goliath();
    void attack(Character *c, int count) override;
    ~Goliath() override = default;

};

class RandomSmallMonster {
private:
    int random = rand()%3;
public:
    Monster *monster;
    RandomSmallMonster();

};

class RandomBigMonster {
private:
    int random = rand()%2;
public:
    Monster *monster;
    RandomBigMonster();
};

class Party {
public:
    int totalTreasure = 0;
    Character *warrior = new Warrior;
    Character *mage = new AttackMage;
    Character *wizard = new DefenderMage;
    Character *rogue = new Rogue;
    RandomCharacter rand1;
    RandomCharacter rand2;
    RandomCharacter rand3;

    Character *groups[7] = {new Warrior(), mage, wizard, rogue, rand1.character, rand2.character, rand3.character};


    bool isAlive();
    void livingMembers();
    void divideTreasure();
    void fullHealth();
    void manaRecharge();
    void strengthPotion();
    void partyAttackSmall(SmallMonsterParty sm);
    void partyAttackBig(BigMonsterParty bm);
    Party(){groups[0] = warrior;}


};

class SmallMonsterParty {
public:
    int rand1 = (rand()%5)+1;
    RandomSmallMonster mon1;
    RandomSmallMonster mon2;
    RandomSmallMonster mon3;
    RandomSmallMonster mon4;
    RandomSmallMonster mon5;
    Monster *small_mon[5] = {nullptr, mon2.monster, mon3.monster, mon4.monster, mon5.monster};


    bool isAlive();

    int nextIdle();
    SmallMonsterParty(){small_mon[0] = mon1.monster;}



};

class BigMonsterParty {
public:
    int rand2 = rand() % 3;
    RandomBigMonster mon1;
    RandomBigMonster mon2;
    Monster *big_mon[2] = {nullptr, mon2.monster};
    bool isAlive();
    int nextIdle();

    BigMonsterParty(){big_mon[0] = mon1.monster;}

};


void battleSequence(Party p, SmallMonsterParty &s, BigMonsterParty &bm, int count);

void advanceTime(Party p, int &count, int monster_chance);



