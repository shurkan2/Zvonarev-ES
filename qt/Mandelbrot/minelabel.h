
#ifndef MINELABEL_H

#define MINELABEL_H


#include <qlabel.h>
#include <qevent.h>

class minelabel:public QLabel
{
	Q_OBJECT
public:
	explicit minelabel(QWidget *parent = Q_NULLPTR);
	void mouseMoveEvent(QMouseEvent* event);
	void mousePressEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);

	int posx=0, posy = 0, nposx=0, nposy=0;
signals:
	void Mouse_Pressed();
	void Mouse_Move();
	void Mouse_Up();
public slots:

};
#endif // !MINELABEL_H