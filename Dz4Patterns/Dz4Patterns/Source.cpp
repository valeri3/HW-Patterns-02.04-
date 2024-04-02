#include <iostream>
#include <string>

using namespace std;

// Базовый класс персонажа
class Character 
{
protected:
    string name;
    int attack;
    int speed;
    int health;
    int defense;

public:
    Character(string name, int attack, int speed, int health, int defense)
    {
        this->name = name;
        this->attack = attack;
        this->speed = speed;
        this->health = health;
        this->defense = defense;
    }

    string GetName() const 
    { 
        return name; 
    }
    int GetAttack() const 
    { 
        return attack;
    }
    int GetSpeed() const 
    { 
        return speed; 
    }
    int GetHealth() const 
    {
        return health;
    }
    int GetDefense() const 
    { 
        return defense; 
    }

    void SetName(const string& newName) 
    { 
        name = newName; 
    }
    void SetAttack(int newAttack) 
    { 
        attack = newAttack; 
    }
    void SetSpeed(int newSpeed) 
    { 
        speed = newSpeed; 
    }
    void SetHealth(int newHealth) 
    { 
        health = newHealth; 
    }
    void SetDefense(int newDefense) 
    {
        defense = newDefense; 
    }

    virtual void DisplayStats() const 
    {
        cout << "Name: " << name << ", Attack: " << attack << ", Speed: " << speed
            << ", Health: " << health << ", Defense: " << defense << endl;
    }
};

class Human : public Character 
{
public:
    Human(string name) : Character(name, 20, 20, 150, 0) 
    {
        DisplayStats();
    }
};

class Elf : public Character 
{
public:
    Elf(string name) : Character(name, 15, 30, 100, 0) 
    {
        DisplayStats();
    }
};

//декоратор людей
class HumanCharacterDecorator : public Character
{
protected:
    Character* character;

public:
    HumanCharacterDecorator(Character* character) :
        Character(
            character->GetName(), character->GetAttack(), character->GetSpeed(),
            character->GetHealth(), character->GetDefense()),
        character(character
        ) 
    { }

    void DisplayStats() const override 
    {
        character->DisplayStats();
    }
};

// Воин человека
class HumanWarriorDecorator : public HumanCharacterDecorator 
{
public:
    HumanWarriorDecorator(Character* character) : HumanCharacterDecorator(character)
    {
        SetName(character->GetName() + ", Human Warrior");
        SetAttack(character->GetAttack() + 20);
        SetSpeed(character->GetSpeed() + 10);
        SetHealth(character->GetHealth() + 50);
        SetDefense(character->GetDefense() + 20);
    }

    void DisplayStats() const override 
    {
        cout << "Upgraded to Warrior - ";
        Character::DisplayStats();
    }
};

// Меченосец человека
class SwordsmanDecorator : public HumanCharacterDecorator {
public:
    SwordsmanDecorator(Character* character) : HumanCharacterDecorator(character) 
    {
        SetName(character->GetName() + ", Swordsman");
        SetAttack(character->GetAttack() + 40);
        SetSpeed(character->GetSpeed() - 10);
        SetHealth(character->GetHealth() + 50);
        SetDefense(character->GetDefense() + 40);
    }

    void DisplayStats() const override
    {
        cout << "Upgraded to Swordsman - ";
        Character::DisplayStats();
    }
};

// Лучник человека
class ArcherDecorator : public HumanCharacterDecorator 
{
public:
    ArcherDecorator(Character* character) : HumanCharacterDecorator(character) 
    {
        SetName(character->GetName() + ", Archer");
        SetAttack(character->GetAttack() + 20);
        SetSpeed(character->GetSpeed() + 20);
        SetHealth(character->GetHealth() + 50);
        SetDefense(character->GetDefense() + 10);
    }

    void DisplayStats() const override
    {
        cout << "Upgraded to Archer - ";
        Character::DisplayStats();
    }
};

// Всадник человека
class KnightDecorator : public HumanCharacterDecorator 
{
public:
    KnightDecorator(Character* character) : HumanCharacterDecorator(character) 
    {
        SetName(character->GetName() + ", Knight");
        SetAttack(character->GetAttack() - 10);
        SetSpeed(character->GetSpeed() + 40);
        SetHealth(character->GetHealth() + 200);
        SetDefense(character->GetDefense() + 100);
    }

    void DisplayStats() const override
    {
        cout << "Upgraded to Knight - ";
        Character::DisplayStats();
    }
};


// Декоратор эльфов
class ElfCharacterDecorator : public Character {
protected:
    Character* character;

public:
    ElfCharacterDecorator(Character* character)
        : Character(
            character->GetName(), character->GetAttack(), character->GetSpeed(),
            character->GetHealth(), character->GetDefense()),
        character(character) { }

    void DisplayStats() const override {
        character->DisplayStats();
    }
};

// Воин эльфов
class ElfWarriorDecorator : public ElfCharacterDecorator 
{
public:
    ElfWarriorDecorator(Character* character) : ElfCharacterDecorator(character) 
    {
        SetName(character->GetName() + ", Elf Warrior");
        SetAttack(character->GetAttack() + 20);
        SetSpeed(character->GetSpeed() - 10);
        SetHealth(character->GetHealth() + 100);
        SetDefense(character->GetDefense() + 20);
    }

    void DisplayStats() const override 
    {
        cout << "Upgraded to Elf Warrior - ";
        Character::DisplayStats();
    }
};

// Маг эльфов
class ElfMageDecorator : public ElfCharacterDecorator 
{
public:
    ElfMageDecorator(Character* character) : ElfCharacterDecorator(character) 
    {
        SetName(character->GetName() + ", Elf Mage");
        SetAttack(character->GetAttack() + 10);
        SetSpeed(character->GetSpeed() + 10);
        SetHealth(character->GetHealth() - 50);
        SetDefense(character->GetDefense() + 10);
    }

    void DisplayStats() const override 
    {
        cout << "Upgraded to Elf Mage - ";
        Character::DisplayStats();
    }
};

// Арбалетчик эльфов
class CrossbowmanDecorator : public ElfCharacterDecorator 
{
public:
    CrossbowmanDecorator(Character* character) : ElfCharacterDecorator(character) 
    {
        SetName(character->GetName() + ", Crossbowman");
        SetAttack(character->GetAttack() + 20);
        SetSpeed(character->GetSpeed() + 10);
        SetHealth(character->GetHealth() + 50);
        SetDefense(character->GetDefense() - 10);
    }

    void DisplayStats() const override 
    {
        cout << "Upgraded to Crossbowman - ";
        Character::DisplayStats();
    }
};

// Злой маг эльфов
class EvilMageDecorator : public ElfCharacterDecorator 
{
public:
    EvilMageDecorator(Character* character) : ElfCharacterDecorator(character) 
    {
        SetName(character->GetName() + ", Evil Mage");
        SetAttack(character->GetAttack() + 70);
        SetSpeed(character->GetSpeed() + 20);
        SetHealth(character->GetHealth());
        SetDefense(character->GetDefense());
    }

    void DisplayStats() const override 
    {
        cout << "Upgraded to Evil Mage - ";
        Character::DisplayStats();
    }
};

// Добрый маг эльфов
class GoodMageDecorator : public ElfCharacterDecorator 
{
public:
    GoodMageDecorator(Character* character) : ElfCharacterDecorator(character) 
    {
        SetName(character->GetName() + ", Good Mage");
        SetAttack(character->GetAttack() + 50);
        SetSpeed(character->GetSpeed() + 30);
        SetHealth(character->GetHealth() + 100);
        SetDefense(character->GetDefense() + 30);
    }

    void DisplayStats() const override 
    {
        cout << "Upgraded to Good Mage - ";
        Character::DisplayStats();
    }
};

int main() 
{
    // Создание базовых персонажей
    Character* basicHuman = new Human("John");
    Character* basicElf = new Elf("Elen");

    // Применение профессий к человеку
    Character* humanWarrior = new HumanWarriorDecorator(basicHuman);
    Character* swordsman = new SwordsmanDecorator(humanWarrior);
    Character* archer = new ArcherDecorator(basicHuman);
    Character* knight = new KnightDecorator(swordsman);

    // Применение профессий к эльфу
    Character* elfWarrior = new ElfWarriorDecorator(basicElf);
    Character* elfMage = new ElfMageDecorator(basicElf);
    Character* crossbowman = new CrossbowmanDecorator(elfWarrior);
    Character* evilMage = new EvilMageDecorator(elfMage);
    Character* goodMage = new GoodMageDecorator(elfMage);

    cout << endl;

    cout << "Basic Human:" << endl;
    basicHuman->DisplayStats();

    cout <<endl;

    cout << "Human Warrior:" << endl;
    humanWarrior->DisplayStats();
    cout << "Swordsman:" << endl;
    swordsman->DisplayStats();
    cout << "Archer:" << endl;
    archer->DisplayStats();
    cout << "Knight:" << endl;
    knight->DisplayStats();

    cout << endl;

    cout << "Basic Elf:" << endl;
    basicElf->DisplayStats();

    cout << endl;

    cout << "Elf Warrior:" << endl;
    elfWarrior->DisplayStats();
    cout << "Elf Mage:" << endl;
    elfMage->DisplayStats();
    cout << "Crossbowman:" << endl;
    crossbowman->DisplayStats();
    cout << "Evil Mage:" << endl;
    evilMage->DisplayStats();
    cout << "Good Mage:" << endl;
    goodMage->DisplayStats();

    delete basicHuman;
    delete basicElf;
    delete humanWarrior;
    delete swordsman;
    delete archer;
    delete knight;
    delete elfWarrior;
    delete elfMage;
    delete crossbowman;
    delete evilMage;
    delete goodMage;

    return 0;
}