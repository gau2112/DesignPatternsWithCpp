#include <iostream>
using namespace std;
class FlyBehavior{
	public:
	virtual void fly()=0;
	virtual ~FlyBehavior() = default;
};

class QuackBehavior{
	public:
	virtual void quack()=0;
	virtual ~QuackBehavior()=default;
};

class flywithwings:public FlyBehavior{
	public:
	void fly() override{
		cout<<"Flying with wings\n";
	}
};
class nofly:public FlyBehavior{
	public:
	void fly() override{
		cout<<"Cant fly\n";
	}
};

class squeak:public QuackBehavior{
	public:
	void quack() override{
		cout<<"I Squeak\n";
	}
};

class othersound:public QuackBehavior{
	public:
	void quack() override{
		cout<<"I make other sounds\n";
	}
};

class Duck{
	protected:
	FlyBehavior* flybehavior;
	QuackBehavior* quackbehavior;
	public:
	void setflybehavior(FlyBehavior *fb){
		flybehavior = fb;
	}
	void setquackbehavior(QuackBehavior *qb){
		quackbehavior = qb;
	}
	void performfly(){
		flybehavior->fly();
	}
	void performquack(){
		quackbehavior->quack();
	}
	virtual void display() = 0;
	virtual ~Duck(){
		delete flybehavior;
		delete quackbehavior;
	}
	
};

class mallardduck:public Duck{
	public:
	mallardduck(){
		flybehavior = new flywithwings;
		quackbehavior = new squeak;
	}
	void display() override{
		cout<<"I am a mallardduck\n";
	}
};

class rubberduck:public Duck{
	public:
	rubberduck(){
		flybehavior = new nofly;
		quackbehavior = new squeak;
	}
	void display() override{
		cout<<"I am a rubberduck\n";
	}
};

int main() {
	// your code goes here
	Duck *a = new mallardduck;
	a->display();
	a->performfly();
	a->setflybehavior(new nofly);
	a->performfly();
	a->performquack();
	
	Duck *b = new rubberduck;
	b->display();
	b->performfly();
	b->performquack();
	return 0;
}
