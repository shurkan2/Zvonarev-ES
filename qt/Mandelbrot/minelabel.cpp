#include "minelabel.h"

minelabel::minelabel(QWidget* parent) : QLabel(parent) 
{
}
void minelabel::mouseMoveEvent(QMouseEvent* event)
{
	this->nposx = event->x();
	this->nposy = event->y();
	emit Mouse_Move();
}

void minelabel::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton) 
	{
		this->posx = event->x();
		this->posy = event->y();
		emit Mouse_Pressed();
	}
}

void minelabel::mouseReleaseEvent(QMouseEvent* event)
{
	this->posx = event->x();
	this->posy = event->y();
	emit Mouse_Up();
}

