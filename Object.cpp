#include "Object.h"

bool Object::SetBool(std::string std, bool value)
{
	if (m.count(std) == 0) // doesn't exist create
	{
		T* str = new T;
		str->b = value;
		str->type = boolean;

		m.insert(std::make_pair(std, str));
		return true;
	}
	else // does exist set
	{
		T* Tvalue = m.find(std)->second;

		if (Tvalue->type != boolean)
		{
			return false;
		}
		else
		{
			Tvalue->b = value;
			return true;
		}
	}
}

bool Object::GetBool(std::string std, bool &didFail)
{
	T* value = m.find(std)->second;

	if (value->type != boolean)
	{
		didFail = true;
		return false;
	}
	
	didFail = false;
	return value->b;
}

bool Object::SetInt(std::string std, int value)
{
	if (m.count(std) == 0) // doesn't exist create
	{
		T* str = new T;
		str->i = value;
		str->type = integer;

		m.insert(std::make_pair(std, str));
		return true;
	}
	else // does exist set
	{
		T* Tvalue = m.find(std)->second;

		if (Tvalue->type != integer)
		{
			return false;
		}
		else
		{
			Tvalue->i = value;
			return true;
		}
	}
}

int Object::GetInt(std::string std, bool &didFail)
{
	T* value = m.find(std)->second;

	if (value->type != integer)
	{
		didFail = true;
		return -1;
	}
	
	didFail = false;
	return value->i;
}


bool Object::SetString(std::string std, char* value)
{
	if (m.count(std) == 0) // doesn't exist create
	{
		T* str = new T;
		str->type = pChar;
		
		str->p = strdup(value);
		
		m.insert(std::make_pair(std, str));
		return true;
	}
	else // does exist set
	{
		T* Tvalue = m.find(std)->second;

		if (Tvalue->type != pChar)
		{
			return false;
		}
		else
		{
			free(Tvalue->p);
			Tvalue->p = strdup(value);
			return true;
		}
	}
}

char* Object::GetString(std::string std, bool &didFail)
{
	T* value = m.find(std)->second;

	if (value->type != pChar)
	{
		didFail = true;
		return "";
	}
	
	didFail = false;
	return value->p;
}

bool Object::SetFloat(std::string std, float value)
{
	if (m.count(std) == 0) // doesn't exist create
	{
		T* str = new T;
		str->f = value;
		str->type = floatingPoint;

		m.insert(std::make_pair(std, str));
		return true;
	}
	else // does exist set
	{
		T* Tvalue = m.find(std)->second;

		if (Tvalue->type != floatingPoint)
		{
			return false;
		}
		else
		{
			Tvalue->f = value;
			return true;
		}
	}
}

float Object::GetFloat(std::string std, bool &didFail)
{
	T* value = m.find(std)->second;

	if (value->type != floatingPoint)
	{
		didFail = true;
		return -1.0;
	}
	
	didFail = false;
	return value->f;
}

Object::~Object()
{
	
	for (ObjectMap::iterator it = m.begin(); it != m.end(); ++it)
	{
		delete it->second;
	}
}