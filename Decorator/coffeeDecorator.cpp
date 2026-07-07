#include <bits/stdc++.h>
using namespace std;
class coffee{
    public:
    virtual ~coffee(){}
    virtual void description()=0;
    virtual int cost()=0;
};

class addons: public coffee{
    protected:
    coffee *cf;
    public:
    virtual int cost()=0;
    virtual void description(){
        cout<<"\nThis is some addon";
    }
};

class milk:public addons {
    public:
    milk(coffee* ob){
        cf = ob;
    }
    int cost() override{
        
       cout<<"\nAdding Cost of Milk  = 25";
        return cf->cost() + 25;
    }
};


class cream:public addons{
    public:
    cream(coffee *ob){
        cf = ob;
        
    }
    int cost() override{
        
       cout<<"\nAdding Cost of Cream  = 29";
       return cf->cost() + 29;
    }
};

class espresso:public coffee{
    public:
    void description() override{
        cout<<"\nWe are having espresso";
    }
    int cost() override{
       cout<<"\nAdding Cost of Espresso  = 100";
        return 100;
    }
    ~espresso(){
        cout<<"\n Espresso deleted";
    }
};
int main() {
	// your code goes here
	coffee *myCoffee = new espresso;
	//cout<<endl<<myCoffee->cost();
	myCoffee = new cream(myCoffee);
	myCoffee = new milk(myCoffee);
	int total = myCoffee->cost();
	cout<<endl<<"Total cost of your coffee is "<<total;
	//extra->cf = gtm;
	//cout<<endl<<myCoffee->cost()<<endl;
}
