#ifndef _SYSTEM_H
#define _SYSTEM_H
#endif
#include "UObject.h"

//Enums
enum SystemType{
	Sys_Window,
	Sys_Game,
	Sys_Input,
	Sys_Graphics,
	Sys_GameTimer
};

//Structs
struct SystemData{

};

class System :
	 public UObject
{
public:
	System();
	virtual ~System();

	SystemType GetType() { return m_SystemType; }

private :

	SystemType m_SystemType;
};