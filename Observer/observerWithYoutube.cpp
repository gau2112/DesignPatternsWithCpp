#include <bits/stdc++.h>
using namespace std;

class observer{
    public:
    virtual void update()=0;
    virtual ~observer(){}
};

class p1:public observer{
 public:
 void update() override{
     cout<<"p1 Got notification"<<" "<<endl;
 }
};

class p2:public observer{
    public:
    void update() override{
        cout<<"P2 getting new notification "<<endl;
    }
};

class p3:public observer{
    public:
    void update() override{
        cout<<"P3 getting new notification "<<endl;
    }
};

class subject{
  public:
  virtual void attach(observer*) = 0;
  virtual void detach(observer*) = 0;
  virtual void notify() = 0;
  virtual void makechange() = 0;
  virtual ~subject() {};
};

class youtubechannel:public subject{
  set<observer*>subscribers;
  public:
  void attach(observer* ob) override{
      subscribers.insert(ob);
  }
  
  void detach(observer* ob) override{
      subscribers.erase(ob);
  }
  
  void notify() override{
      for(auto &sub:subscribers){
          sub->update();
      }
  }
  
  void makechange() override{
      cout<<"Making a change to channel \n";
      notify();
  }
};

int main() {
	subject *obchannel = new youtubechannel;
	observer *x1 = new p1;
	observer *x2 = new p2;
	observer *x3 = new p3;
	
	obchannel->attach(x1);
	obchannel->attach(x2);
	obchannel->makechange();
	obchannel->detach(x1);
	obchannel->makechange();
	obchannel->attach(x2);
	obchannel->attach(x3);
	obchannel->makechange();
	

}
