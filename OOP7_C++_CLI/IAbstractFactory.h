#pragma once
#include "Shape.h"

public interface class IAbstractFactory {

	virtual Shape^ createShape(System::String^ name);
};