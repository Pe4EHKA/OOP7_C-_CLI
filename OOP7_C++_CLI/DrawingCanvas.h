#pragma once
#include "Shape.h"
#include "Decorator.h"
#include "Composite.h"
#include "AbstractFactory.h"
#include "MyStorage.h"


ref class DrawingCanvas {
private:
	MyStorage<Shape^>^ shapes = gcnew MyStorage<Shape^>();  // ������ �����
	Color shapeColor = Color::Black;
	bool ctrlPressed = false;
	bool multipleSelection = false;
	Point^ resolPoint;
public:
	DrawingCanvas() {
		resolPoint = gcnew Point;
	}
	void resetAll();  // ������ ���� ��������� � �����
	void removeSelected();  // �������� ��������� �����
	void drawShapes(Graphics^ g);  // ��������� �����
	void setShapeColor(Color color);  // ��������� ����� � �����

	void add(CShape^ shape);  // ���������� ������ � ����� ����������
	void addNewShape(CShape^ shape, int x, int y);  // �������� ����� ������
	void moveX(int dx, int beginForm, int endForm);  // ����������� �� X
	void moveY(int dy, int beginForm, int endForm);  // ����������� �� Y
	void changeSizes(int dsize, Point^ beginForm, Point^ endForm);  // ��������� ������� � ��������� �����
	void moveALL(Point beginForm, int endFormWidth, int endFormHeight);

	void setCtrl(bool ctrl, Object^ sender);
	void setMultiple();  // ���������/����������� �������������� ���������
	bool isCtrl();  // ����������� �������� bool ctrl_pressed
	bool containShape(int x, int y);  // ����� �� ������ � ������ ��� ���

	void groupShapes();
	void ungroupShapes();

	void save(String^ filename, String^ resolution);
	void load(String^ filename, AbstractFactory^ factory);
	Point^ getResolution(String^ filename);

	
};

