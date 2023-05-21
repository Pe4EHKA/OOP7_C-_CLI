#include "DrawingCanvas.h"

void DrawingCanvas::resetAll()
{
	for (int i = 0; i < shapes->get_size(); ++i) {
		shapes[i]->setSelect(false);
	}
}

void DrawingCanvas::removeSelected()
{
	for (int i = 0; i < shapes->get_size(); ++i) {
		if (shapes[i]->isSelected()) {
			shapes->remove_by_index(i--);
		}
	}
	if (shapes->get_size() > 0) {
		shapes[shapes->get_size() - 1]->setSelect(true);
	}
	
}

void DrawingCanvas::drawShapes(Pen^ penSelect, SolidBrush^ brush, Graphics^ g)
{
	for (int i = 0; i < shapes->get_size(); ++i) {
		shapes[i]->setColor(shapeColor);
		shapes[i]->draw(penSelect, brush, g);
	}
}

void DrawingCanvas::setShapeColor(Color color)
{
	shapeColor = color;
}

void DrawingCanvas::add(CShape^ shape)
{
	shapes->push_back(shape);
}

void DrawingCanvas::addNewShape(CShape^ shape, int x, int y)
{
	if (shape != nullptr) {
		CShape^ unknownShape = shape->clone();
		resetAll();
		unknownShape->setSelect(true);
		unknownShape->setX(x);
		unknownShape->setY(y);
		shapes->push_back(unknownShape);
	}
}

void DrawingCanvas::moveX(int dx, int beginForm, int endForm)
{
	if (shapes->get_size() > 0) {
		for (int i = 0; i < shapes->get_size(); ++i) {
			if (shapes[i]->isSelected()) {
				shapes[i]->moveX(dx, beginForm, endForm);
			}
		}
	}
}

void DrawingCanvas::moveY(int dy, int beginForm, int endForm)
{
	if (shapes->get_size() > 0) {
		for (int i = 0; i < shapes->get_size(); ++i) {
			if (shapes[i]->isSelected()) {
				shapes[i]->moveY(dy, beginForm, endForm);
			}
		}
	}
}

void DrawingCanvas::changeSizes(int dsize)
{
	for (int i = 0; i < shapes->get_size(); ++i) {
		if (shapes[i]->isSelected()) {
			shapes[i]->changeSize(dsize);
		}
	}
}

void DrawingCanvas::moveALL(Point beginForm, int endFormWidth, int endFormHeight)
{
	if (shapes->get_size() > 0) {
		for (int i = 0; i < shapes->get_size(); ++i) {
			shapes[i]->moveX(0, beginForm.X, endFormWidth);
			shapes[i]->moveY(0, beginForm.Y, endFormHeight);
		}
	}
}

void DrawingCanvas::setCtrl(bool ctrl, Object^ sender)
{
	ctrlPressed = ctrl;
	if (sender != nullptr) {
		System::Windows::Forms::CheckBox^ box = dynamic_cast<System::Windows::Forms::CheckBox^>(sender);
		box->Checked = ctrl;
	}
}

void DrawingCanvas::setMultiple()
{
	multipleSelection = !multipleSelection;
}

bool DrawingCanvas::isCtrl()
{
	return ctrlPressed;
}

bool DrawingCanvas::containShape(int x, int y)
{
	bool contain = false;
	if (!ctrlPressed) {
		resetAll();
	}
	for (int i = shapes->get_size() - 1; i >= 0; --i) {
		if (shapes[i]->Contains(x, y) && !shapes[i]->isSelected()) {
			shapes[i]->setSelect(true);
			contain = true;
			if (!ctrlPressed || !multipleSelection) {
				break;
			}
		}
	}
	return contain;
}
