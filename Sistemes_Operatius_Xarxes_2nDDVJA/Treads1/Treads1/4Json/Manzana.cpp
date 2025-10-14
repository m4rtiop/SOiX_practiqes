#include "Manzana.h"

Json::Value Manzana::Code()
{
	Json::Value json = Fruta::Code();

	json["manzanidad"] = manzanidad;
	//json[DecodeKey()] = typeid(Manzana).name();
	ICodable::CodeSubClassType<Manzana>(json); //Es pot millorar per tal q aixo no s'hagi de posar cada cop

	return json;
}

void Manzana::Decode(Json::Value json)
{
	Fruta::Decode(json);
	manzanidad = json["manzanidad"].asInt();
}
