// p514, 2�� ����

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
    void load() { cout << "��ź�� �����մϴ�." << endl; }
};
class Gun : public Weapon 
{
public:
    void load() { cout << "���� �����մϴ�." << endl; }
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