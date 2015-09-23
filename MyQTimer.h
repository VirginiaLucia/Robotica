#ifndef MyQTimer_H
#define MyQTimer_H


#include <QtCore>
#include <QThread>
#include <QMutex>

class MyQTimer : public QThread
{
  Q_OBJECT
  
public:
    MyQTimer();
    virtual ~MyQTimer();
      
protected:
  void run();
	
public:
	void setInterval(int);
	void stop();
	
signals:
    void timeout();

private:
//   int t;
  bool fin;
//   QMutex mutex;
  struct Interval
  {
      QMutex mutex;
      int t;
      void set(int v){
	QMutexLocker m(&mutex);
	t=v;
      }
      int get(){
	QMutexLocker m(&mutex);
	return t;
      }
  }interval;
};

#endif