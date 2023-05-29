#include "DrawingCanvas.h"

void DrawingCanvas::resetAll()
{
	for (int i = 0; i < shapes->get_size(); ++i) {
		Decorator^ decorator = dynamic_cast<Decorator^>(shapes[i]);
		if (decorator) {
			shapes[i] = decorator->getShape();
		}
	}
}

void DrawingCanvas::removeSelected()
{
	for (int i = 0; i < shapes->get_size(); ++i) {
		if (dynamic_cast<Decorator^>(shapes[i])) {
			shapes->remove_by_index(i--);
		}
	}
	if (shapes->get_size() > 0) {
		if (shapes[shapes->get_size() - 1]) {
			shapes[shapes->get_size() - 1] = gcnew Decorator(shapes[shapes->get_size() - 1]);
		}
	}
	
}

void DrawingCanvas::drawShapes(Graphics^ g)
{
	for (int i = 0; i < shapes->get_size(); ++i) {
		Decorator^ decorator = dynamic_cast<Decorator^>(shapes[i]);
		if (decorator) {
			decorator->setColor(shapeColor);
		}
		shapes[i]->draw(g);
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
		unknownShape->setX(x);
		unknownShape->setY(y);
		Decorator^ decorator = gcnew Decorator(unknownShape);
		shapes->push_back(decorator);
	}
}

void DrawingCanvas::moveX(int dx, int beginForm, int endForm)
{

	for (int i = 0; i < shapes->get_size(); ++i) {
		Decorator^ decorator = dynamic_cast<Decorator^>(shapes[i]);
		if (decorator) {
			decorator->moveX(dx, beginForm, endForm);
		}
	}
}

void DrawingCanvas::moveY(int dy, int beginForm, int endForm)
{
	for (int i = 0; i < shapes->get_size(); ++i) {
		Decorator^ decorator = dynamic_cast<Decorator^>(shapes[i]);
		if (decorator) {
			decorator->moveY(dy, beginForm, endForm);
		}
	}
}

void DrawingCanvas::changeSizes(int dsize, Point^ beginForm, Point^ endForm)
{
	for (int i = 0; i < shapes->get_size(); ++i) {
		Decorator^ decorator = dynamic_cast<Decorator^>(shapes[i]);
		if (decorator) {
			decorator->changeSize(dsize, beginForm, endForm);
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
		if (shapes[i]->Contains(x, y) && !(dynamic_cast<Decorator^>(shapes[i]))) {
			shapes[i] = gcnew Decorator(shapes[i]);
			contain = true;
			if (!ctrlPressed || !multipleSelection) {
				break;
			}
		}
	}
	return contain;
}

void DrawingCanvas::groupShapes()
{
	int decoratorCount = 0;
	for (int i = 0; i < shapes->get_size(); ++i) {
		if (dynamic_cast<Decorator^>(shapes[i])) {
			decoratorCount++;
			if (decoratorCount > 1) {
				break;
			}
		}
	}
	if (decoratorCount > 0) {
		Shape^ group = gcnew Composite();
		for (int i = 0; i < shapes->get_size(); ++i) {
			if (dynamic_cast<Decorator^>(shapes[i])) {
				dynamic_cast<Composite^>(group)->addToGroup(shapes[i]);
				shapes->remove_by_index(i--);
			}
		}
		group = gcnew Decorator(group);
		shapes->push_back(group);
	}
}

void DrawingCanvas::ungroupShapes()
{
	for (int i = 0; i < shapes->get_size(); ++i) {
		Decorator^ decorator = dynamic_cast<Decorator^>(shapes[i]);
		if (decorator) {
			Composite^ group = dynamic_cast<Composite^>(decorator->getShape());
			if (group) {
				for (int i = group->getCount(); i > 1; --i) {
					shapes->push_back(group->getShape());
					group->remove();
				}
				shapes->push_back(group->getShape());
				shapes->remove_element(shapes[i]);
			}
		}
	}
}

void DrawingCanvas::save(String^ filename, String^ resolution)
{
	StreamWriter^ stream = gcnew StreamWriter(filename, false);// Сохраняет, перезаписывая файл
	try {
		stream->WriteLine("Resoulution = " + resolution);
		stream->WriteLine("Number of Shapes = " + shapes->get_size());
		for (int i = 0; i < shapes->get_size(); ++i) {
			shapes[i]->save(stream);
		}
	}
	finally {
		if (stream != nullptr) {
			stream->Close();
		}
	}
}

void DrawingCanvas::load(String^ filename, AbstractFactory^ factory)  // Здесь используется Абстрактная фабрика для создания фигур
{
	shapes->clear();
	if (!File::Exists(filename)) {
		return;
	}
	StreamReader^ stream = File::OpenText(filename);
	try {
		Shape^ shape;
		stream->ReadLine();
		cli::array<String^>^ countLine = stream->ReadLine()->Split(' ');
		int count = Int32::Parse(countLine[countLine->Length - 1]);
		for (int i = 0; i < count; ++i) {
			shape = factory->createShape(stream->ReadLine());
			Composite^ group = dynamic_cast<Composite^>(shape);
			if (group) {
				Shape^ sGroup;
				cli::array<String^>^ countShape = stream->ReadLine()->Split(' ');
				int countGroup = Int32::Parse(countShape[countShape->Length - 1]);
				for (int j = 0; j < countGroup; ++j) {
					sGroup = factory->createShape(stream->ReadLine());
					if (sGroup != nullptr) {
						(dynamic_cast<CShape^>(sGroup))->load(stream);
						sGroup = gcnew Decorator(sGroup);
						group->addToGroup(sGroup);
					}
				}
				shapes->push_back(shape);
			}
			else {
				if (shape != nullptr) {
					(dynamic_cast<CShape^>(shape))->load(stream);
					shapes->push_back(shape);
				}
			}
		}
	}
	finally {
		if (stream != nullptr)
			stream->Close();
	}
}


Point^ DrawingCanvas::getResolution(String^ filename)
{
	if (!File::Exists(filename)) {
		return nullptr;
	}
	StreamReader^ stream = File::OpenText(filename);
	try {
		cli::array<String^>^ resol = stream->ReadLine()->Split(' ');
		resolPoint->X = Int32::Parse(resol[resol->Length - 2]);
		resolPoint->Y = Int32::Parse(resol[resol->Length - 1]);
	}
	finally {
		if (stream != nullptr)
			stream->Close();
	}

	return resolPoint;
}

