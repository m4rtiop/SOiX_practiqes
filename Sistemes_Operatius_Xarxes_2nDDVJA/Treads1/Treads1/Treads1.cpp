#include <iostream>

//#include "1TutorialThread/ThreadTutorial.h"
#include "Utils/ConsoleControl.h"
#include "2InputSystem/InputSystem.h"

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

	while(true) { }

	return 0;
}