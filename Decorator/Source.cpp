#include <iostream>
#include <string>
using namespace std;

// паттерн Decorator динамически добавляет объекту новые обязанности. 
// Является гибкой альтернативой порождению подклассов с целью расширения функциональности.

// Component (Pizza) - компонент определяет интерфейс для объектов, на которые могут быть динамически возложены дополнительные обязанности
//class Pizza abstract
//{	
//protected:
//	string Name;
//public:
//	Pizza(string n)
//	{
//		Name = n;
//	}
//	string GetName()
//	{
//		return Name;
//	}
//	virtual int GetCost()abstract;
//};
class Character abstract
{
protected:
	string job;
	int attack, speed, health, protection;
public:
	Character(string j)
	{
		this->job = j;
	}
	string GetJob()
	{
		return job;
	}
	virtual int GetAttack() abstract;
	virtual int GetSpeed() abstract;
	virtual int GetHealth() abstract;
	virtual int GetProtection() abstract;
};

// ConcreteComponent (ItalianPizza) - конкретный компонент определяет объект, на который возлагаются дополнительные обязанности
//class ItalianPizza: public Pizza
//{
//public:
//	ItalianPizza(): Pizza("Italian pizza")
//	{ }
//	int GetCost() override
//	{
//		return 10;
//	}
//};
class Human : public Character
{
public:
	Human() : Character("Human"){ }
	int GetAttack() override {
		return 20;
	}
	int GetSpeed() override {
		return 20;
	 }
	int GetHealth() override {
		return 150;
	 }
	int GetProtection() override {
		return 0;
	 }
	
};

// ConcreteComponent (BulgarianPizza) - конкретный компонент определяет объект, на который возлагаются дополнительные обязанности
class Elph : public Character
{
public:
	Elph() : Character("Elph") { }
	int GetAttack() override {
		return 15;
	}
	int GetSpeed() override {
		return 30;
	}
	int GetHealth() override {
		return 100;
	}
	int GetProtection() override {
		return 0;
	}
	/*int GetCost() override
	{
		return 10;
	}*/
};

// Decorator (PizzaDecorator) хранит ссылку на объект Component и определяет интерфейс, соответствующий интерфейсу Component
class CharacterDecoratorHuman abstract: public Character
{
protected:
	Character *character;
public:
	CharacterDecoratorHuman(string j, Character* character): Character(j)
	{
		this->character = character;
	}
};

class CharacterDecoratorElph abstract : public Character
{
protected:
	Character* character;
public:
	CharacterDecoratorElph(string j, Character* character) : Character(j)
	{
		this->character = character;
	}
};

// ConcreteDecorator (TomatoPizza) - конкретный декоратор возлагает дополнительные обязанности на компонент.
class HumanWarrior: public CharacterDecoratorHuman
{
public:
	HumanWarrior(Character* ch): CharacterDecoratorHuman(ch->GetJob() + " warrior", ch) { }
	int GetAttack() override {
		return character->GetAttack() + 20;
	}
	int GetSpeed() override {
		return character->GetSpeed() + 10;
	}
	int GetHealth() override {
		return character->GetHealth() + 50;
	}
	int GetProtection() override {
		return character->GetProtection() + 20;
	}
	
};

// ConcreteDecorator (CheesePizza) - конкретный декоратор возлагает дополнительные обязанности на компонент.
class Swordtail : public CharacterDecoratorHuman
{
public:
	Swordtail(Character* ch) : CharacterDecoratorHuman(ch->GetJob() + " swordtail", ch) { }
	int GetAttack() override {
		return character->GetAttack() + 40;
	}
	int GetSpeed() override {
		return character->GetSpeed() - 10;
	}
	int GetHealth() override {
		return character->GetHealth() + 50;
	}
	int GetProtection() override {
		return character->GetProtection() + 40;
	}
};
class Archer : public CharacterDecoratorHuman
{
public:
	Archer(Character* ch) : CharacterDecoratorHuman(ch->GetJob() + " archer", ch) { }
	int GetAttack() override {
		return character->GetAttack() + 20;
	}
	int GetSpeed() override {
		return character->GetAttack() + 20;
	}
	int GetHealth() override {
		return character->GetHealth() + 50;
	}
	int GetProtection() override {
		return character->GetProtection() + 10;
	}
	
};

class Rider : public CharacterDecoratorHuman
{
public:
	Rider(Character* ch) : CharacterDecoratorHuman(ch->GetJob() + " rider", ch) { }
	int GetAttack() override {
		return character->GetAttack() - 10;
	}
	int GetSpeed() override {
		return character->GetSpeed() + 40;
	}
	int GetHealth() override {
		return character->GetHealth() + 200;
	}
	int GetProtection() override {
		return character->GetProtection() + 100;
	}
};

class ElphWarrior : public CharacterDecoratorElph
{
public:
	ElphWarrior(Character* ch) : CharacterDecoratorElph(ch->GetJob() + " warrior", ch) { }
	int GetAttack() override {
		return character->GetAttack() + 20;
	}
	int GetSpeed() override {
		return character->GetSpeed() - 10;
	}
	int GetHealth() override {
		return character->GetHealth() + 100;
	}
	int GetProtection() override {
		return character->GetProtection() + 20;
	}

};
class ElphWizard : public CharacterDecoratorElph
{
public:
	ElphWizard(Character* ch) : CharacterDecoratorElph(ch->GetJob() + " wizard", ch) { }
	int GetAttack() override {
		return character->GetAttack() + 10;
	}
	int GetSpeed() override {
		return character->GetSpeed() + 10;
	}
	int GetHealth() override {
		return character->GetHealth() - 50;
	}
	int GetProtection() override {
		return character->GetProtection() + 10;
	}
	
};

class ElphArbalet : public CharacterDecoratorElph
{
public:
	ElphArbalet(Character* ch) : CharacterDecoratorElph(ch->GetJob() + " arbalet", ch) { }
	int GetAttack() override {
		return character->GetAttack() + 20;
	}
	int GetSpeed() override {
		return character->GetSpeed() + 10;
	}
	int GetHealth() override {
		return character->GetHealth() + 50;
	}
	int GetProtection() override {
		return character->GetProtection() - 10;
	}
	
};
class ElphWickedWiz : public CharacterDecoratorElph
{
public:
	ElphWickedWiz(Character* ch) : CharacterDecoratorElph(ch->GetJob() + " wicked wizard", ch) { }
	int GetAttack() override {
		return character->GetAttack() + 70;
	}
	int GetSpeed() override {
		return character->GetSpeed() + 20;
	}
	int GetHealth() override {
		return character->GetHealth() + 0;
	}
	int GetProtection() override {
		return character->GetProtection() + 0;
	}
	
};
class ElphKindWiz : public CharacterDecoratorElph
{
public:
	ElphKindWiz(Character* ch) : CharacterDecoratorElph(ch->GetJob() + " kind wizard", ch) { }
	int GetAttack() override {
		return character->GetAttack() + 50;
	}
	int GetSpeed() override {
		return character->GetSpeed() + 30;
	}
	int GetHealth() override {
		return character->GetHealth() + 100;
	}
	int GetProtection() override {
		return character->GetProtection() + 30;
	}
	
};

void client(Character * ch)
{
	char s[100];
	sprintf_s(s, "Job: %s  Attack: %d Speed: %d Health: %d Protection: %d", ch->GetJob().c_str(), ch->GetAttack(), ch->GetSpeed(), ch->GetHealth(), ch->GetProtection());
	cout << s << endl;
}

int main()
{
	Character* ch = new Human();
	ch = new HumanWarrior(ch); 
	client(ch);

	ch = new Elph();
	ch = new ElphWarrior(ch);

	client(ch);

	ch = new Human();
	ch = new HumanWarrior(ch);
	ch = new Swordtail(ch);
	client(ch);

	system("pause");
}