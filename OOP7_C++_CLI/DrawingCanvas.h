#pragma once
#include "Shape.h"
#include "Decorator.h"
#include "Composite.h"
#include "AbstractFactory.h"
#include "MyStorage.h"


ref class DrawingCanvas {
private:
	MyStorage<Shape^>^ shapes = gcnew MyStorage<Shape^>();  // Массив фигур
	Color shapeColor = Color::Black;
	bool ctrlPressed = false;
	bool multipleSelection = false;
	Point^ resolPoint;
public:
	DrawingCanvas() {
		resolPoint = gcnew Point;
	}
	void resetAll();  // Снятие всех выделений у фигур
	void removeSelected();  // Удаление выбранных фигур
	void drawShapes(Graphics^ g);  // Рисование фигур
	void setShapeColor(Color color);  // Установка цвета у фигур

	void add(CShape^ shape);  // Добавление фигуры в конец контейнера
	void addNewShape(CShape^ shape, int x, int y);  // Создание новой фигуры
	void moveX(int dx, int beginForm, int endForm);  // Перемещение по X
	void moveY(int dy, int beginForm, int endForm);  // Перемещение по Y
	void changeSizes(int dsize, Point^ beginForm, Point^ endForm);  // Изменение размера у выбранных фигур
	void moveALL(Point beginForm, int endFormWidth, int endFormHeight);

	void setCtrl(bool ctrl, Object^ sender);
	void setMultiple();  // Активация/Деактивация множественного выделения
	bool isCtrl();  // Возвращение значения bool ctrl_pressed
	bool containShape(int x, int y);  // Попал ли курсор в фигуру или нет

	void groupShapes();
	void ungroupShapes();

	void save(String^ filename, String^ resolution);
	void load(String^ filename, AbstractFactory^ factory);
	Point^ getResolution(String^ filename);

	
};

