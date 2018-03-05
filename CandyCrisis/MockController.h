#pragma once
#ifndef MOCKCONTROLLER_H
#define MOCKCONTROLLER_H
#include "gtest/gmock.h"

#include "Controller.h"

class MockController : public Controller {
public:
	GMOCK_INCLUDE_GMOCK_GMOCK_H_;
	GMOMOCK_METHOD1();
	MockController(makeMove, bool(MovementDirection move));
};
#endif
