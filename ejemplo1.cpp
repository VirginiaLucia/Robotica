#include "ejemplo1.h"

ejemplo1::ejemplo1(): Ui_Counter()
{
	setupUi(this);
	show();
	timer= new MyQTimer();
	connect(button, SIGNAL(clicked()), this, SLOT(doButton()) );
	connect(startButton, SIGNAL(clicked()), this, SLOT(doButtonStart()) );
	connect(timer, SIGNAL(timeout()), this, SLOT(doIncrease()) );
 	connect(horizontalSlider, SIGNAL(sliderMoved(int)), timer, SLOT(start(int)));
	
}

ejemplo1::~ejemplo1()
{}

void ejemplo1::doButton()
{
	qDebug() << "click on button";
	timer->stop();
	lcdNumber->display(i);

}

void ejemplo1::doButtonStart()
{
	qDebug() << "click on button";
	timer->stop();
	i=0;
	lcdNumber->display(i);
	timer->setInterval(300);
	timer->start();
}

void ejemplo1::doIncrease()
{
  lcdNumber->display(i++);
}




