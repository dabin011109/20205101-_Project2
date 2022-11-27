// p514, 2번 문제

#include<iostream>
using namespace std;

class Weapon 
{
public:
    virtual void load() = 0;
};
class Bomb : public Weapon 
{
public:
    void load() { cout << "폭탄을 적재합니다." << endl; }
};
class Gun : public Weapon 
{
public:
    void load() { cout << "총을 적재합니다." << endl; }
};

int main()
{
    Weapon* loa[3];
    loa[0] = new Gun;
    loa[1] = new Bomb;
    loa[2] = new Bomb;

    for (Weapon* w : loa)
        w->load();

    return 0;
}