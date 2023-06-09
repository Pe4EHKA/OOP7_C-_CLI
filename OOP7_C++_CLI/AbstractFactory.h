#pragma once
#include "Shape.h"
#include "CCircle.h"
#include "CSquare.h"
#include "CTriangle.h"
#include "Composite.h"
#include "IAbstractFactory.h"

using namespace System;

// Определяет методы для создания объектов разных типов. 
ref class AbstractFactory : IAbstractFactory {
public:
	Shape^ createShape(String^ name) override {
		if (name == "Circle") {
			return gcnew CCircle();
		}
		else if (name == "Square") {
			return gcnew CSquare();
		}
		else if (name == "Triangle") {
			return gcnew CTriangle();
		}
		else if (name == "Group") {
			return gcnew Composite();
		}
	}

};