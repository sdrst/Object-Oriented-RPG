#include <iostream>
#include <ctime>
#include <cstdlib>
#include "myfns.h"


using namespace std;

int main(int argc, char *argv[]) {
    srand(time(0));

    int count = 1;
    int hours = atoi(argv[1]);
    int monster_chance = atoi(argv[2]);

    Party p;


    while (count <= hours && p.isAlive()) {
        cout << "----------Our heroes rest as time passes...----------\n" << endl;
        advanceTime(p, count, monster_chance);
    }

    if(p.isAlive()){
        cout<<"\nOur heroes have finished their journey victorious! They now return to their homes where people will sing songs about them til the end of days\n"<<endl;
        cout<<"The heroes journey took a total of "<<count-1<<" hours\n"<<endl;
    }


    for(auto &group:p.groups){
        if(group->isLiving){
            cout<<group->name<<" completes his journey with "<<group->wealth<<" coins!"<<endl;
        }
    }
    cout<<endl;
    for(auto &group:p.groups){
        if(!group->isLiving){
            cout<<group->name<<" was killed by "<<group->killer<<" in hour "<<group->time_of_death<<endl;
        }
    }

    for(auto &group: p.groups){
        delete group;
    }

}



