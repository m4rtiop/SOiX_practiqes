#pragma once
#include <string>
#include "ICodable.h"	

class Fruta : public ICodable
{
public:
	unsigned int semillas = 0;
	std::string hexDelColor = "";

	virtual Json::Value Code() override;
	virtual void Decode(Json::Value json) override;

	//MAL PROGRAMAT SERVEIX D'EXEMPLE 
};

