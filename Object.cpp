#include "Object.h"

#include <stdio.h>
#include <tchar.h>
#include <map>
#include <string>
#include <iostream>

bool Object::SetBool(std::string std, bool value)
{
	if (m.count(std) == 0) // doesn't exist create
	{
		T str;
		str.b = value;
		str.type_index = 0;

		m.insert(std::pair<std::string, T>(std, str));
		return true;
	}
	else // does exist set
	{
		T Tvalue = m.find(std)->second;

		if (Tvalue.type_index != 0)
		{
			return false;
		}
		else
		{
			Tvalue.b = value;
			return true;
		}
	}
}

bool Object::GetBool(std::string std, bool &didFail)
{
	T value = m.find(std)->second;

	if (value.type_index != 0)
	{
		didFail = true;
		return false;
	}
	
	didFail = false;
	return value.b;
}

bool Object::SetInt(std::string std, int value)
{
	if (m.count(std) == 0) // doesn't exist create
	{
		T str;
		str.i = value;
		str.type_index = 1;

		m.insert(std::pair<std::string, T>(std, str));
		return true;
	}
	else // does exist set
	{
		T Tvalue = m.find(std)->second;

		if (Tvalue.type_index != 1)
		{
			return false;
		}
		else
		{
			Tvalue.i = value;
			return true;
		}
	}
}

int Object::GetInt(std::string std, bool &didFail)
{
	T value = m.find(std)->second;

	if (value.type_index != 1)
	{
		didFail = true;
		return -1;
	}
	
	didFail = false;
	return value.i;
}


bool Object::SetString(std::string std, char* value)
{
	if (m.count(std) == 0) // doesn't exist create
	{
		T str;
		str.p = value;
		str.type_index = 2;

		m.insert(std::pair<std::string, T>(std, str));
		return true;
	}
	else // does exist set
	{
		T Tvalue = m.find(std)->second;

		if (Tvalue.type_index != 2)
		{
			return false;
		}
		else
		{
			Tvalue.p = value;
			return true;
		}
	}
}

char* Object::GetString(std::string std, bool &didFail)
{
	T value = m.find(std)->second;

	if (value.type_index != 2)
	{
		didFail = true;
		return "";
	}
	
	didFail = false;
	return value.p;
}

bool Object::SetFloat(std::string std, float value)
{
	if (m.count(std) == 0) // doesn't exist create
	{
		T str;
		str.f = value;
		str.type_index = 3;

		m.insert(std::pair<std::string, T>(std, str));
		return true;
	}
	else // does exist set
	{
		T Tvalue = m.find(std)->second;

		if (Tvalue.type_index != 3)
		{
			return false;
		}
		else
		{
			Tvalue.f = value;
			return true;
		}
	}
}

float Object::GetFloat(std::string std, bool &didFail)
{
	T value = m.find(std)->second;

	if (value.type_index != 3)
	{
		didFail = true;
		return -1.0;
	}
	
	didFail = false;
	return value.f;
}

