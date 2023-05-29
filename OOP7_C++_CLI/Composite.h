#pragma once
#include "Shape.h"
#include "MyStorage.h"
#include "Decorator.h"

// Единый интерфейс для работы с отдельными объектами и составными объектами
ref class Composite : public Shape {
private:
	MyStorage<Shape^>^ composedShapes = gcnew MyStorage<Shape^>();

public:
	
	void addToGroup(Shape^ shape);

	virtual void draw(Graphics^ g) override;
	virtual void setColor(Color color) override;
	virtual void changeSize(int dsize, Point^ beginForm, Point^ endForm) override;

	// Передвижение с проверкой на условия (Бизнес логика)
	virtual void moveX(int dx, int beginForm, int endForm) override;
	virtual void moveY(int dy, int beginForm, int endForm) override;
	bool possibleMoveX(int dx, int beginForm, int endForm) override;
	bool possibleMoveY(int dy, int beginForm, int endForm) override;

	virtual bool Contains(int x, int y) override;
	virtual void save(StreamWriter^ stream) override;

	void setSelectColor(Color color);
	int getCount();
	Shape^ getShape();
	void remove();
	


};

