#include "MyQTimer.h"

#include <QThread>

MyQTimer::MyQTimer()
{
  fin=false;
}

MyQTimer::~MyQTimer()
{}

void MyQTimer::run()
{
  while(!fin)
  {
      msleep(interval.get());
      emit timeout();
  }  
}

void MyQTimer::setInterval(int t_){
//   mutex.lock();
  fin=false;
//   t=t_;
//   mutex.unlock();
  interval.set(t_);
}

void MyQTimer::stop(){
  fin=true;
}


