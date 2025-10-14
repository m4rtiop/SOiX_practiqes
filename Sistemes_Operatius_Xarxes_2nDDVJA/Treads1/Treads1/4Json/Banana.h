#pragma once
#include "Fruta.h"

class Banana : public Fruta
{
public:
	int bananidad = 0;

	Json::Value Code() override;
	void Decode(Json::Value json) override;
};

