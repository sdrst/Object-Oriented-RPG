
#include <iostream>
#include <cstdlib>
#include "myfns.h"

using namespace std;


static string heroNames[50] = {"Adrahil","Gandalf", "Aragorn", "Legolas","Samwise", "Gimli","Bilbo","Peregrin",
                               "Boromir", "Galadriel", "Meriadoc", "Elrond", "Faramir", "Treebeard", "Frodo",
                               "Eomer", "Thorin", "Eowyn","Theoden","Saruman", "Arwen", "Haldir","Radagast",
                               "Kili", "Balin","Tauriel","Thranduil","Fili","Dwalin", "Tom", "Gloin", "Celeborn",
                               "Bofur","Beorn","Bombur","Oin","Gwaihir","Ori","Nori","Bifur","Elendil","Dori",
                               "Thror","Gamling","Isildur","Thrain","Lindir","Hama","Elwing","Alatar"};


static string wimpNames[36] = {"Azong","Bolg","Gobby","Gothmog","Ugluk","Tiny", "Smelly", "Grumpy", "Lumpy",
                               "Bumpy","Stumpy","Frumpy","Dumpy","Chumpy", "Grimy", "Slimy", "Ugly", "Stinky",
                               "Cowardly","Limey","Chubby","Stinky","Nine-Toes", "One-Tooth","Scrappy","Balcmeg",
                               "Golfimbul","Gorbag","Gorgol","Lug","Lagduf","Snaga","Ugluk","Radbug","Orcobal","Lugdush"};

static string evilNames[20] = {"Sauron","Ancalagon the Black", "Drogon the Terrible", "Eldrax the Great", "Icefyre",
                               "Golden Dragon", "Smaug","Alexstrasza the Life Binder","Deathwing","Seeth the Scaleless",
                               "Fafnir the Horrible", "Ililig Threadcarver","Valath Wildstriker","Ghatham Woundwalker",
                               "Scylla","Charybdis","Typhon","Incubus","Beezlebub","Drakon"};



//--------------------------------------- Monster --------------------------------------------//


Monster::~Monster() {
}

//---------------------------------------end Monster----------------------------------------------//

//--------------------------------------- Character --------------------------------------------//

Character::~Character() {
}

//---------------------------------------end Character----------------------------------------------//


Warrior::Warrior(){
    name = heroNames[char_rand];
    MAX_HEALTH = 170;
    health = MAX_HEALTH;
    close_ability = 30;
    isLiving = true;
    isClose = false;
    isIdle = true;
    target = 0;
    wealth = 0;
}
//---------------------------------------end Warrior----------------------------------------------//

//---------------------------------------AttackMage----------------------------------------------//

AttackMage::AttackMage() : spell1("Fire Ball", 30, 0, 20), spell2("Wind Hammer",10,0,10), spell3("Ice Turret",20,0,20){
    name = heroNames[char_rand];
    MAX_HEALTH = 130;
    health = MAX_HEALTH;
    ranged_ability = 15;
    close_ability = 5;
    mana = 70;
    isLiving = true;
    isClose = false;
    isIdle = true;
    target = 0;
    wealth = 0;
}

void AttackMage::castSpell(Monster *m) {
    int rand_spell = rand()%3;
    if(rand_spell == 0 && mana>=20){
        cout<<name<<" casts "<<spell1.spell_name<<"!"<<endl;
        m->health-=spell1.damage;
        cout<<"The spell hits "<<m->name<<" and a seering ball of fire envelopes him causing "<<spell1.damage<<" damage!"<<endl;
        mana -= spell1.cost;
    }
    else if(rand_spell == 1 && mana>=20){
        cout<<name<<" casts "<<spell3.spell_name<<"!"<<endl;
        m->health-=spell3.damage;
        cout<<"The spell hits "<<m->name<<" with hundreds of icicles causing "<<spell3.damage<<" damage!"<<endl;
        mana -= spell3.cost;
    }
    else{
        cout<<name<<" casts "<<spell2.spell_name<<"!"<<endl;
        m->health-=spell2.damage;
        cout<<"The spell hits "<<m->name<<" with a gust of air, throwing him into the air causing "<<spell2.damage<<" damage!"<<endl;
        mana -= spell2.cost;
    }
}

//---------------------------------------end AttackMage----------------------------------------------//

//---------------------------------------DefenderMage----------------------------------------------//

DefenderMage::DefenderMage() : spell1("Push Back", 5, 0, 10), spell2("Iron Blanket", 0, 15, 10), spell3("Unbreakable",0,100, 30){
    name = heroNames[char_rand];
    MAX_HEALTH = 140;
    health = MAX_HEALTH;
    mana = 70;
    ranged_ability = 15;
    close_ability = 5;
    target = 0;
    wealth = 0;
    isLiving = true;
    isClose = false;
    isIdle = true;
}
//---------------------------------------end DefenderMage----------------------------------------------//

//---------------------------------------Rogue----------------------------------------------//
Rogue::Rogue(){
    name = heroNames[char_rand];
    MAX_HEALTH = 160;
    health = MAX_HEALTH;
    ranged_ability = 30;
    close_ability = 20;
    target = 0;
    wealth = 0;

    isLiving = true;
    isClose = false;
    isIdle = true;
}

//---------------------------------------end Rogue----------------------------------------------//

//---------------------------------------Random Character----------------------------------------------//

RandomCharacter::RandomCharacter() {
    if(random == 1){
        character = new Warrior;
    }
    else if(random == 2){
        character = new AttackMage;
    }
    else if(random == 3){
        character = new DefenderMage;
    }
    else{
        character = new Rogue;
    }

}

//---------------------------------------end Random Character----------------------------------------------//

//---------------------------------------Small Monsters----------------------------------------------//

Weakling::Weakling(){
    name = wimpNames[char_rand1];
    health = 50;
    close_ability = 15;
    accuracy = 50;
    isLiving = true;
    isClose = false;
    isIdle = true;
    target = 0;

}

Goblin::Goblin(){
    name = wimpNames[char_rand1];
    health = 50;
    close_ability = 10;
    ranged_ability = 20;
    accuracy = 50;
    isLiving = true;
    isClose = false;
    isIdle = true;
    target = 0;
}

Warlock::Warlock() : spell1("Thorn-Wrap",20,0,20), spell2("Poison Flood",20,0,20), spell3("Dark Blanket",10,0,10){
    name = wimpNames[char_rand1];
    health = 50;
    close_ability = 5;
    ranged_ability = 10;
    accuracy = 50;
    mana = 50;
    isLiving = true;
    isClose = false;
    isIdle = true;
    target = 0;
}

void Warlock::castSpell(Character *c) {
    int rand_spell = rand()%3;
    if(rand_spell == 0 and mana>=20){
        cout<<name<<", the warlock, casts "<<spell1.spell_name<<"!"<<endl;
        c->health-=spell1.damage;
        cout<<"The spell hits "<<c->name<<" and a tight binding of thorns causes "<<spell1.damage<<" damage!"<<endl;
        mana -= spell1.cost;
    }
    else if(rand_spell == 1 and mana>=20){
        cout<<name<<", the warlock, casts "<<spell2.spell_name<<"!"<<endl;
        c->health-=spell2.damage;
        cout<<"The spell hits "<<c->name<<" and a wave of poison causes "<<spell2.damage<<" damage!"<<endl;
        mana -= spell2.cost;
    }
    else{
        cout<<name<<", the warlock, casts "<<spell3.spell_name<<"!"<<endl;
        c->health-=spell3.damage;
        cout<<"The spell hits "<<c->name<<" and causes the hero to be confused and hurt himself, causing "<<spell3.damage<<" damage!"<<endl;
        mana -= spell3.cost;
    }
}

//---------------------------------------end Small Monsters----------------------------------------------//

//---------------------------------------Big Monsters----------------------------------------------//

Dragon::Dragon(){
    name = evilNames[char_rand2];
    health = 100;
    close_ability = 30;
    ranged_ability = 50;
    accuracy = 70;
    isLiving = true;
    isClose = false;
    isIdle = true;
    target = 0;
}


Goliath::Goliath(){
    name = evilNames[char_rand2];
    health = 100;
    close_ability = 60;
    accuracy = 70;
    isLiving = true;
    isClose = false;
    isIdle = true;
    target = 0;
}

//---------------------------------------end Big Monsters----------------------------------------------//

//---------------------------------------Random Monsters----------------------------------------------//

RandomSmallMonster::RandomSmallMonster() {
    if(random == 0){
        monster = new Weakling;
    }
    else if(random == 1){
        monster = new Goblin;
    }
    else{
        monster = new Warlock;
    }
}



RandomBigMonster::RandomBigMonster() {
    if(random == 1){
        monster = new Dragon;
    }
    else{
        monster = new Goliath;
    }
}

//---------------------------------------end Random Monsters----------------------------------------------//

// -----------------------------------------------Parties------------------------------------------------ \\

bool Party::isAlive(){
    for (int i = 0; i < 7; i++){
        if(groups[i]->isLiving){
            return true;
        };
    }
    return false;
}

void Party::livingMembers() {
    for (auto &group:groups) {
        if (group->isLiving) {
            group->battleCry();
        }
    }
}

void Party::fullHealth() {
    for (auto &group : groups) {
        if (group->isLiving) {
            group->health = group->MAX_HEALTH;
        }
    }
}
void Party::manaRecharge() {
    for (auto &group : groups) {
        if (group->isLiving) {
            group->mana = 50;
        }
    }
}

void Party::strengthPotion() {
    for (auto &group : groups) {
        if (group->isLiving) {
            group->close_ability += 2;
        }
    }
}

void Party::divideTreasure() {
    int count = 0;
    for (auto &group : groups) {
        if (group->isLiving) {
            count++;
        }
    }
    int split = totalTreasure / count;
    for (auto &group : groups) {
        if (group->isLiving) {
            group->wealth += split;
        }

    }
}


bool SmallMonsterParty::isAlive() {
    for (int i = 0; i < rand1; i++){
        if(small_mon[i]->isLiving){
            return true;
        };
    }
    return false;
}

int SmallMonsterParty::nextIdle(){
    for(int i = 0; i<rand1; i++){
        if(small_mon[i]->isLiving && small_mon[i]->isIdle){
            small_mon[i]->isIdle = false;
            return i;
        }

    }
    return -1;
}




bool BigMonsterParty::isAlive() {
    for (int i = 0; i < rand2; i++){
        if(big_mon[i]->isLiving){
            return true;
        };
    }
    return false;
}

int BigMonsterParty::nextIdle() {
    for(int i = 0; i<rand2; i++){
        if(big_mon[i]->isLiving && big_mon[i]->isIdle){
            big_mon[i]->isIdle = false;
            return i;
        }

    }
    return -1;
}

// ----------------------------------------End Parties---------------------------------------------- \\



// ----------------------------------------Attack Functions----------------------------------------- \\

void Warrior::attack(Party p, Monster *m) {
    isIdle = false;
    m->isIdle = false;
    cout<<"---------------------------------------------------------------------------------"<<endl;
    if (!isClose or !m->isClose) {
        advance();
        cout<<name<<" the warrior, advances towards his enemy"<<endl;
        m->advance();
    } else {
        cout << name << " swings his sword at " << m->name << " with incredible force!" << endl;
        if(rand()%100 < accuracy) {
            m->health -= close_ability;
            cout << name << " connected! He did " << close_ability << " damage to " << m->name << endl;
        }
        else{
            cout<<"Attack Missed!"<<endl;
        }
    }
    if (m->health < 1) {
        m->isDead();
        isIdle = true;
        isClose = false;
    }
    cout<<"---------------------------------------------------------------------------------"<<endl;
}



void AttackMage::attack(Party p, Monster *m) {
    isIdle = false;
    m->isIdle = false;
    cout<<"---------------------------------------------------------------------------------"<<endl;
    if(mana > 0 && !isClose){
        castSpell(m);
    }
    else if(!isClose){
        cout<<"Out of mana!"<<endl;
        cout<<name<<" summons stones from the ground and fires them in the direction of "<<m->name<<endl;
        if(rand()%100 < accuracy) {
            m->health -= ranged_ability;
            cout << "The ranged attack does " << ranged_ability << " damage!" << endl;
        }
        else{
            cout<<"The monster has dodged the attack!"<<endl;
        }
    }
    else{
        cout<<name<<" swings his bow staff at "<<m->name<<endl;
        if(rand()%100 < accuracy) {
            m->health -= close_ability;
            cout << "It hits weakly for " << close_ability << " damage" << endl;
        }
        else{
            cout<<"Attack Missed!"<<endl;
        }
    }
    if(m->health<1){
        m->isDead();
        isIdle = true;
        isClose = false;
    }
    cout<<"---------------------------------------------------------------------------------"<<endl;
}

void DefenderMage::castSpell(Party p, Monster *m) {
    if(m->isClose or isClose){
        cout<<name<<" casts "<<spell1.spell_name<<"!"<<endl;
        m->health-=spell1.damage;
        cout<<"The spell hits "<<m->name<<" and the monster is pushed back across the map causing "<<spell1.damage<<" damage!"<<endl;
        mana -= spell1.cost;
        m->isClose = false;
        isClose = false;
    }
    else if(mana>=30){
        cout<<name<<" casts "<<spell3.spell_name<<"!"<<endl;
        for (auto &group : p.groups) {
            group->health = group->MAX_HEALTH;
        }
        cout<<"All members in the party have returned to full health!"<<endl;
        mana -= spell3.cost;
    }
    else {
        cout << name << " casts " << spell2.spell_name << "!" << endl;
        for (auto &group : p.groups) {
            group->health += spell2.protection;
        }
        cout<<"All members in the party have gained 15 hitpoints of protection!"<<endl;
        mana -= spell2.cost;
    }
}

void DefenderMage::attack(Party p, Monster *m) {
    isIdle = false;
    m->isIdle = false;
    cout<<"---------------------------------------------------------------------------------"<<endl;
    if(mana>0){
        castSpell(p, m);
    }
    else if(!isClose) {
        cout<<"Out of mana!"<<endl;
        cout << name << " summons branches from the trees and fires them in the direction of " << m->name << endl;
        if(rand()%100 < accuracy) {
            m->health -= ranged_ability;
            cout << "The ranged attack does " << ranged_ability << " damage!" << endl;
        }
        else{
            cout<<"The monster has dodged the attack!"<<endl;
        }
    }
    else{
        cout<<name<<" throws a punch at "<<m->name<<endl;
        if(rand()%100 < accuracy) {
            m->health -= close_ability;
            cout << "It hits weakly for " << close_ability << " damage" << endl;
        }
        else{
            cout<<"Attack Missed!"<<endl;
        }
    }
    if(m->health < 1){
        m->isDead();
        isIdle = true;
        isClose = false;
    }
    cout<<"---------------------------------------------------------------------------------"<<endl;
}

void Rogue::attack(Party p, Monster *m) {
    isIdle = false;
    m->isIdle = false;
    cout<<"---------------------------------------------------------------------------------"<<endl;
    if(!isClose){
        cout<<name<<" the rogue, draws his long bow and looses a three arrow shot at "<<m->name<<"!"<<endl;
        if(rand()%100 < accuracy) {
            m->health -= ranged_ability;
            cout << "The shot connects for " << ranged_ability << " damage!" << endl;
            isClose = false;
        }
        else{
            cout<<"The monster has dodged this attack!"<<endl;
        }
    }
    else{
        cout<<name<<" the rogue, draws his dagger from its sheath and swiftly lunges at "<<m->name<<"!"<<endl;
        if(rand()%100 < accuracy) {
            m->health -= close_ability;
            cout << m->name << " has been cut for " << close_ability << " damage!" << endl;
        }else{
            cout<<"Attack Missed!"<<endl;
        }
    }
    if(m->health<1){
        m->isDead();
        isIdle = true;
        isClose = false;
    }
    cout<<"---------------------------------------------------------------------------------"<<endl;
}

void Weakling::attack(Character *c, int count) {
    isIdle = false;
    c->isIdle = false;
    cout<<"---------------------------------------------------------------------------------"<<endl;
    if (!isClose or !c->isClose) {
        advance();
        c->advance();
        cout << name << ", the weakling, has advanced towards " << c->name << endl;
    } else {
        cout << name << ", the weakling, takes a swipe at " << c->name << endl;
        if(rand()%100 < accuracy) {
            c->health -= close_ability;
            cout << "The little creature lands its strike for " << close_ability << " damage!" << endl;
        }
        else{
            cout<<"The Attack Missed!"<<endl;
        }
    }
    if (c->health < 1) {
        c->isDead();
        c->time_of_death = count;
        c->killer = name + " the weakling";
        isIdle = true;
        isClose = false;
    }
    cout<<"---------------------------------------------------------------------------------"<<endl;
}





void Goblin::attack(Character *c, int count){
    isIdle = false;
    c->isIdle = false;
    cout<<"---------------------------------------------------------------------------------"<<endl;
    if(!isClose){
        cout << name << " the goblin, throws a bone javelin at " << c->name << "!" << endl;
        if(rand()%100 < accuracy) {
            c->health -= ranged_ability;
            cout << "The javelin connects for " << ranged_ability << " damage!" << endl;
            isClose = false;
        }
        else{
            cout<<"The Attack Missed!"<<endl;
        }
    }
    else{
        cout << name << " the goblin, wields a wooden club and swings hard at the knees of " << c->name << "!" << endl;
        if(rand()%100 < accuracy) {
            c->health -= close_ability;
            cout << c->name << " has been clubbed for " << close_ability << " damage!" << endl;
        }
        else{
            cout<<"The attack has missed!"<<endl;
        }
    }
    if(c->health<1){
        c->isDead();
        c->time_of_death = count;
        c->killer = name + " the goblin";
        isIdle = true;
        isClose = false;
    }
    cout<<"---------------------------------------------------------------------------------"<<endl;
}







void Warlock::attack(Character *c, int count){
    isIdle = false;
    c->isIdle = false;
    cout<<"---------------------------------------------------------------------------------"<<endl;
    if(mana > 0 && !isClose){
        castSpell(c);
    }
    else if(!isClose){
        cout << "Out of mana!" << endl;
        cout << name << ", the warlock, sends a group of undead spirits in the direction of " << c->name << endl;
        if(rand()%100 < accuracy) {
            c->health -= ranged_ability;
            cout << "The ranged attack does " << ranged_ability << " damage!" << endl;
        }
        else{
            cout<<"Attack Missed!"<<endl;
        }
    }
    else{
        cout<<name<<", the warlock, stretches out a clawed hand and swipes at "<<c->name<<endl;
        if(rand()%100 < accuracy) {
            c->health -= close_ability;
            cout << "It hits weakly for " << close_ability << " damage" << endl;
        }
        else{
            cout<<"This Attack has missed!"<<endl;
        }
    }
    if(c->health<1){
        c->isDead();
        c->time_of_death = count;
        c->killer = name + " the warlock";
        isIdle = true;
        isClose = false;
    }
    cout<<"---------------------------------------------------------------------------------"<<endl;
}


void Dragon::attack(Character *c, int count) {
    isIdle = false;
    c->isIdle = false;
    cout<<"---------------------------------------------------------------------------------"<<endl;
    if(!isClose){
        cout<<name<<" the great dragon, flies high and spots "<<c->name<<"! The dragon breathes a huge ball of fire!"<<endl;
        if(rand()%100 < accuracy) {
            c->health -= ranged_ability;
            cout << c->name << " is burned for " << ranged_ability << " damage!" << endl;
            isClose = false;
        }else{
            cout<<"Attack Missed!"<<endl;
        }
    }
    else{
        cout<<name<<" the dragon, now grounded, takes a bite at "<<c->name<<"!"<<endl;
        if(rand()%100 < accuracy) {
            c->health -= close_ability;
            cout << c->name << " has been bitten for " << close_ability << " damage!" << endl;
        }
        else{
            cout<<"The attack has missed!"<<endl;
        }
    }
    if(c->health<1){
        c->isDead();
        c->time_of_death = count;
        c->killer = name + " the dragon";
        isIdle = true;
        isClose = false;
    }
    cout<<"---------------------------------------------------------------------------------"<<endl;
}



void Goliath::attack(Character *c, int count) {
    isIdle = false;
    c->isIdle = false;
    cout<<"---------------------------------------------------------------------------------"<<endl;
    if (!isClose or !c->isClose) {
        advance();
        c->advance();
        cout<< name << ", the Goliath, has advanced towards " << c->name << endl;
    }
    else{
        cout<< name<<", the Goliath, smiles with delight before crashing down upon "<< c->name<<endl;
        if(rand()%100 < accuracy) {
            c->health -= close_ability;
            cout << "A devastating blow, the huge beast has dealt " << close_ability << " damage!" << endl;
        }
        else{
            cout<<"The Goliath has missed!"<<endl;
        }
    }
    if(c->health<1){
        c->isDead();
        c->time_of_death = count;
        c->killer = name + " the goliath";
        isIdle = true;
        isClose = false;
    }
    cout<<"---------------------------------------------------------------------------------"<<endl;
}



void Party::partyAttackSmall(SmallMonsterParty sm) {
    int t;
    for(int i = 0; i<7; i++){
        if(groups[i]->isLiving) {
            t = sm.nextIdle();
            if (t == -1) {
                groups[i]->setTarget(rand()%sm.rand1);
            } else {
                groups[i]->setTarget(t);
                sm.small_mon[t]->setTarget(i);
            }
        }
    }

}
void Party::partyAttackBig(BigMonsterParty bm) {
    int t;
    for(int i = 0; i<7; i++){
        if(groups[i]->isLiving) {
            t = bm.nextIdle();
            if (t == -1) {
                groups[i]->Character::setTarget(rand()%bm.rand2);
            } else {
                groups[i]->Character::setTarget(t);
                bm.big_mon[t]->Monster::setTarget(i);
            }
        }
    }

}


void battleSequence(Party p, SmallMonsterParty &s, BigMonsterParty &bm, int count){
    while(p.isAlive() && s.isAlive()){
        int x = 0;
        p.partyAttackSmall(s);
        for (auto &group : p.groups) {
            if (group->isLiving && s.small_mon[group->target]->isLiving) {
                group->attack(p, s.small_mon[group->target]);
                if(s.small_mon[group->target]->isLiving){
                    s.small_mon[group->target]->attack(group, count);
                }
            }
        }
        if(x<1) {
            cout << "TURN OVER" << endl;
            x++;
        }
    }
    while(p.isAlive() && bm.isAlive()){
        int y = 0;
        p.partyAttackBig(bm);
        for (auto &group : p.groups) {
            if (group->isLiving && bm.big_mon[group->target]->isLiving) {
                group->attack(p, bm.big_mon[group->target]);
                if(bm.big_mon[group->target]->isLiving){
                    bm.big_mon[group->target]->attack(group,count);
                }
            }
        }
        if(y<1) {
            cout << "TURN OVER" << endl;
            y++;
        }
    }
    if(!p.isAlive()){
        cout<<"All has been lost! Our heroes have all perished, our adventure is over."<<endl;
    }
    else{
        cout<<"Victory! Our heroes will live to fight another battle!\n"<<endl;
    }

}

void advanceTime(Party p, int &count, int monster_chance){
    const int potion_percent_chance = 20;
    int mon_chance = (rand() % 90) + 5;
    int treasure_chance = (rand() % 500) + 1;
    int potion_chance = (rand()% 100)+1;
    SmallMonsterParty sm;
    BigMonsterParty bm;

    cout << "Hour: " << count << endl;
    cout << "The living members of the party shall declare themselves:" << endl;

    p.livingMembers();
    cout << "Our heroes are on their way!\n" << endl;

    if (mon_chance <= monster_chance) {

        cout << "A rumbling is heard in the distance. Monsters are approaching!" << endl;
        cout<<"Over the horizon comes "<<sm.rand1<<" small monster(s) and "<< bm.rand2<<" big monster(s)!\n"<<endl;
        battleSequence(p, sm, bm, count);
        if(p.isAlive()){
            cout<<"Treasure has been looted from the defeated monsters as well as collected from fallen comrades"<<endl;
            p.totalTreasure += treasure_chance;
            p.divideTreasure();
            cout<<"A total of "<<treasure_chance<<" coins were looted and divided amongst our living heroes\n"<<endl;
            p.fullHealth();
            p.manaRecharge();
            for(auto &group: p.groups){
                group->isClose = false;
            }
        }
    } else {
        cout << "The group has survived the hour undetected" << endl;
    }
    if(p.isAlive()) {
        if (potion_chance <= potion_percent_chance) {
            cout << "Strength Potion Found! +2 close range damage!" << endl;
            p.strengthPotion();
        }
        count++;
    }
    else {
        cout<<"The tale of this party is now finished. The heroes survived until hour "<<count<<"\n"<<endl;
    }

    for (auto &i : sm.small_mon) {
        delete i;
    }
    for (auto &i : bm.big_mon) {
        delete i;
    }
}


// --------------------------------------End Attack Functions-------------------------------------- \\


