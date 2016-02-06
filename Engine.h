#ifndef _ENGINE_H
#define _ENGINE_H

//C Runtime Header Files
#ifndef _WINDOWS_
	#include <Windows.h>
#endif

#ifndef _MAP_
	#include <map>
#endif

#ifndef _CONTEXT_H
	#include "context.h"
#endif
enum SystemType;
//Forward System declaration
class System;
class Game;
//Enumeration
enum EngineState
{
	Invalid,
	Constructing,
	Initializing,
	Running,
	ShuttingDown,
	Destroying
};



class Engine
{
public:
	Engine();
	~Engine();

	int RunLoop();
	//void* operator new (size_t size);
	//void operator delete(void* pdelete);

	static EngineState GetEngineState() {return m_EngineState;}

private:
	int Initialize();
	int Draw(const Context& context);
	int Update(const Context& context);
	int ShutDown();
	
	//Add a core system to the engine
	int AddSystem(System* psys);
	//Retrieve a core system from the engine
	template<typename T>
	T* GetSystem(SystemType systype){
		T* psys = static_cast<T*>(m_mapSystems[systype]);
		if (!psys){
			//Logger::logg("System is not valid");
			return nullptr;
		}

		return psys;
	}

	Game* CreateGame();



	std::map<SystemType, System*> m_mapSystems;
	static EngineState m_EngineState;

};



#endif