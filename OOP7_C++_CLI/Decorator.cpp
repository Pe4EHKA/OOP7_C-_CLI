#include "Decorator.h"

void Decorator::draw(Graphics^ g)
{
	Composite^ group = dynamic_cast<Composite^>(m_shape);
	if (group) {
		group->setSelectColor(Color::Red);
		group->draw(g);
		group->setSelectColor(Color::Black);
	}
	else {
		m_shape->draw(g);
		CShape^ cshape = dynamic_cast<CShape^>(m_shape);
		int x = cshape->getX();
		int y = cshape->getY();
		int sideLength = cshape->getSideLength();
		g->DrawRectangle(selectPen, x - sideLength / 2 - 3, y - sideLength / 2 - 3, sideLength + 5, sideLength + 5);
	}
}

void Decorator::setColor(Color color)
{
	m_shape->setColor(color);
}

void Decorator::changeSize(int dsize, Point^ beginForm, Point^ endForm)
{
	m_shape->changeSize(dsize, beginForm, endForm);
}

void Decorator::moveX(int dx, int beginForm, int endForm)
{
	m_shape->moveX(dx, beginForm, endForm);
}

void Decorator::moveY(int dy, int beginForm, int endForm)
{
	m_shape->moveY(dy, beginForm, endForm);
}

bool Decorator::possibleMoveX(int dx, int beginForm, int endForm)
{
	return m_shape->possibleMoveX(dx, beginForm, endForm);
}

bool Decorator::possibleMoveY(int dy, int beginForm, int endForm)
{
	return m_shape->possibleMoveY(dy, beginForm, endForm);
}

void Decorator::setSelectColor(Color color)
{
	selectPen->Color = color;
}

Shape^ Decorator::getShape()
{
	return m_shape;
}

bool Decorator::Contains(int x, int y)
{
	return m_shape->Contains(x, y);
}

void Decorator::save(StreamWriter^ stream)
{
	m_shape->save(stream);
}
