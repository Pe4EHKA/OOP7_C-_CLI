#pragma once
#include "CShape.h"
#include "CCircle.h"
#include "CSquare.h"
#include "CTriangle.h"
#include "MyStorage.h"


ref class DrawingCanvas {
private:
	MyStorage<CShape^>^ shapes = gcnew MyStorage<CShape^>();  // ������ �����
	Color shapeColor = Color::Black;
	bool ctrlPressed = false;
	bool multipleSelection = false;
public:
	void resetAll();  // ������ ���� ��������� � �����
	void removeSelected();  // �������� ��������� �����
	void drawShapes(Pen^ penSelect, SolidBrush^ brush, Graphics^ g);  // ��������� �����
	void setShapeColor(Color color);  // ��������� ����� � �����

	void add(CShape^ shape);  // ���������� ������ � ����� ����������
	void addNewShape(CShape^ shape, int x, int y);  // �������� ����� ������
	void moveX(int dx, int beginForm, int endForm);  // ����������� �� X
	void moveY(int dy, int beginForm, int endForm);  // ����������� �� Y
	void changeSizes(int dsize);  // ��������� ������� � ��������� �����
	void moveALL(Point beginForm, int endFormWidth, int endFormHeight);

	void setCtrl(bool ctrl, Object^ sender);
	void setMultiple();  // ���������/����������� �������������� ���������
	bool isCtrl();  // ����������� �������� bool ctrl_pressed
	bool containShape(int x, int y);  // ����� �� ������ � ������ ��� ���


	
};

