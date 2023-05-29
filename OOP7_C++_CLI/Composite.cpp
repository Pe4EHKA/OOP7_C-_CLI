#include "Composite.h"

void Composite::addToGroup(Shape^ shape)
{
	composedShapes->push_back(shape);
}

void Composite::draw(Graphics^ g)
{
	for (int i = 0; i < composedShapes->get_size(); ++i) {
		composedShapes[i]->draw(g);
	}
}

void Composite::setColor(Color color)
{
	for (int i = 0; i < composedShapes->get_size(); ++i) {
		composedShapes[i]->setColor(color);
	}
}

void Composite::changeSize(int dsize, Point^ beginForm, Point^ endForm)
{
	for (int i = 0; i < composedShapes->get_size(); ++i) {
		composedShapes[i]->changeSize(dsize, beginForm, endForm);
	}
}

void Composite::moveX(int dx, int beginForm, int endForm)
{
	if (possibleMoveX(dx, beginForm, endForm)) {
		for (int i = 0; i < composedShapes->get_size(); ++i) {
			composedShapes[i]->moveX(dx, beginForm, endForm);
		}
	}
}

void Composite::moveY(int dy, int beginForm, int endForm)
{
	if (possibleMoveY(dy, beginForm, endForm)) {
		for (int i = 0; i < composedShapes->get_size(); ++i) {
			composedShapes[i]->moveY(dy, beginForm, endForm);
		}
	}
}

bool Composite::possibleMoveX(int dx, int beginForm, int endForm)
{
	for (int i = 0; i < composedShapes->get_size(); ++i) {
		if (!composedShapes[i]->possibleMoveX(dx, beginForm, endForm)) {
			return false;
		}
	}
	return true;
}

bool Composite::possibleMoveY(int dy, int beginForm, int endForm)
{
	for (int i = 0; i < composedShapes->get_size(); ++i) {
		if (!composedShapes[i]->possibleMoveY(dy, beginForm, endForm)) {
			return false;
		}
	}
	return true;
}

bool Composite::Contains(int x, int y)
{
	for (int i = 0; i < composedShapes->get_size(); ++i) {
		if (composedShapes[i]->Contains(x, y)) {
			return true;
		}
	}
	return false;
}

void Composite::save(StreamWriter^ stream)
{
	String^ saveLine = "Group\n" + "Count = " + composedShapes->get_size();
	stream->WriteLine(saveLine);
	for (int i = 0; i < composedShapes->get_size(); ++i) {
		composedShapes[i]->save(stream);
	}
}

void Composite::setSelectColor(Color color)
{
	for (int i = 0; i < composedShapes->get_size(); ++i) {
		Decorator^ decorator = dynamic_cast<Decorator^>(composedShapes[i]);
		if (decorator) {
			decorator->setSelectColor(color);
		}
	}
}

int Composite::getCount()
{
	return composedShapes->get_size();
}

Shape^ Composite::getShape()
{
	return composedShapes[0];
}


void Composite::remove()
{
	composedShapes->remove_by_index(0);
}
