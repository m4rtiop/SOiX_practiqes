#include <iostream>
#include <json/json.h>
#include <fstream>

//#include "1TutorialThread/ThreadTutorial.h"
#include "Utils/ConsoleControl.h"
#include "2InputSystem/InputSystem.h"
#include "Utils/Timer.h"
#include "3NodeMap/Node.h"
#include "3NodeMap/NodeMap.h"

#include <functional>
#include <string>
#include <list>
/*
typedef std::function<int(int, int)> SumaFuncion;
typedef std::list<std::list<int>> ListdeListsdeInts;

void TestLambdasMolonas(SumaFuncion funcionMolona)
{
	std::cout << "Voy a ejecutar una funcion que estaba en una variable" << std::endl;

	int number = funcionMolona(6,7);

	std::cout << "Ya la he ejecutado y ha devuelto --> " << number << std::endl;
}*/


class Tree : public INodeContent
{
	void Draw(Vector2 offset) override
	{
		CC::Lock();
		CC::SetColor(CC::DARKGREEN, CC::BLACK);
		CC::setPosition(offset.X, offset.Y);
		std::cout << "T";

		CC::Unlock();
	}
};

/*class Potatoe
{
	
};*/

class Player // :Codable --> Serializable + Deserializable
{
public:
	int life = 0;	
	std::string name = "Pepe";
	unsigned int coins = 0;

	Player();
	~Player();

	void Decode(Json::Value json) //Des serializar
	{
		life = json["life"].asInt();
		name = json["name"].asString();
		coins = json["coins"].asInt();
	}

	Json::Value Encode() //Serializar
	{
		Json::Value json;

		json["life"] = life;
		json["name"] = name;
		json["coins"] = coins;

		return json;
	}
};

int main()
{
    //ThreadTutorialTest();
	//CC::SetColor(CC::WHITE, CC::DARKCYAN);
	/*
	std::string name = "Pepe";

	ListdeListsdeInts listaDeListas;

	SumaFuncion functionQueHaceCosasPeroEsUnaVariable = [name](int a, int b)
		{
			std::cout << "Esto no se como pero funciona y se llama --> " << name << std::endl;
			return a + b;
		};

	TestLambdasMolonas(functionQueHaceCosasPeroEsUnaVariable);*/

	/*
	InputSystem* iS = new InputSystem();

	InputSystem::KeyBinding* kb1 = iS->AddListener(K_1, []()
		{
			CC::Lock();
			std::cout << "Pressed 1" << std::endl;
			CC::Unlock();

		});

	InputSystem::KeyBinding* kb2 = iS->AddListener(K_2, []()
		{
			CC::Lock();
			std::cout << "Pressed 2" << std::endl;
			CC::Unlock();

		});

	InputSystem::KeyBinding* kb3 = iS->AddListener(K_3, []()
		{
			CC::Lock();
			std::cout << "Pressed 3" << std::endl;
			CC::Unlock();

		});

	iS->StartListen();


	*/

	/*Timer::StartTimer(3000, []()
		{
			CC::Lock();
			std::cout << "Han pasado 3 segundos" << std::endl;
			CC::Unlock();
		}
	);*/


	/*Node* node = new Node(Vector2(0, 0));

	Tree* tree = new Tree();
	Potatoe* potatoe = new Potatoe();

	node->SetContent(tree);

	Tree* tree2 = node->GetContent<Tree>();
	Potatoe* potatoe2 = node->GetContent<Potatoe>();*/

	/*NodeMap* myMap = new NodeMap(Vector2(20, 20), Vector2(2, 2));

	Tree* t1 = new Tree();
	Tree* t2 = new Tree();
	Tree* t3 = new Tree();
	Tree* t4 = new Tree();
	Tree* t5 = new Tree();

	myMap->SafePickNode(Vector2(0, 0), [t1](Node* node)
		{
			node->SetContent(t1);
		});

	myMap->SafePickNode(Vector2(19, 0), [t2](Node* node)
		{
			node->SetContent(t2);
		});

	myMap->SafePickNode(Vector2(0, 19), [t3](Node* node)
		{
			node->SetContent(t3);
		});

	myMap->SafePickNode(Vector2(19, 19), [t4](Node* node)
		{
			node->SetContent(t4);
		});

	myMap->SafePickNode(Vector2(10, 10), [t5](Node* node)
		{
			node->SetContent(t5);
		});

	myMap->UnsafeDraw();

	InputSystem* iS = new InputSystem();

	iS->AddListener(K_UP, [myMap]()
		{
			std::list<Vector2> positions;
			positions.push_back(Vector2(10, 10));
			positions.push_back(Vector2(10, 9));

			myMap->SafeMultiPickNode(positions, [](std::list<Node*> nodes)
				{
					std::list<Node*>::iterator it = nodes.begin();
					
					Node* n1 = *it;
					it++;

					Node* n2 = *it;
					n2->SetContent(n1->GetContent());

					n1->SetContent(nullptr);
					n1->DrawContent(Vector2(2, 2));
					n2->DrawContent(Vector2(2, 2));

				});
		});

	iS->StartListen();
	*/

	Player* player = new Player();
	player->life = 100;
	player->name = "Pepe Lluis Llach";
	player->coins = 250;

	Json::Value newJson;

	newJson["Player"] = player->Encode();

	std::ofstream* file = new std::ofstream("player.json", std::ios::binary);



	while (true) {}

	return 0;
}