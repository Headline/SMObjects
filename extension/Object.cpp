#include "Object.h"
#include <string.h>

UnionType Object::GetType(int index)
{
    ObjectMap::iterator it;
    int count = 0;
    for (it = m.begin(); it != m.end(); ++it)
    {
        if (count == index)
        {
            return it->second->type;
        }
    }
    
    return invalid;
}

void Object::SetBool(std::string std, bool value)
{
	std::pair<ObjectMap::iterator, bool> ret; 
	
	ret = m.insert(std::pair<std::string, T*>(std, NULL));
	
	if (!ret.second) // if value already exists
	{	
		T* str = ret.first->second;
		
		if (str->type == pChar)
		{
			free(str->p);
		}
		else if (str->type == cellArray)
		{
			free(str->array->c);	
		}
		
		str->type = boolean;
		str->b = value;
	}
	else
	{
		T* str = new T;
		str->b = value;
		str->type = boolean;
		
		ret.first->second = str;
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

int Object::Size()
{
    return m.size();
}

void Object::SetInt(std::string std, int value)
{
	std::pair<ObjectMap::iterator, bool> ret; 
	
	ret = m.insert(std::pair<std::string, T*>(std, NULL));
	
	if (!ret.second) // if value already exists
	{	
		T* str = ret.first->second;
		
		if (str->type == pChar)
		{
			free(str->p);
		}
		else if (str->type == cellArray)
		{
			free(str->array->c);	
		}
		
		str->type = integer;
		str->i = value;
	}
	else
	{
		T* str = new T;
		str->i = value;
		str->type = integer;
		
		ret.first->second = str;
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


void Object::SetString(std::string std, char* value)
{
	std::pair<ObjectMap::iterator, bool> ret; 
	
	ret = m.insert(std::pair<std::string, T*>(std, NULL));
	
	if (!ret.second) // if value already exists
	{	
		T* str = ret.first->second;
		
		if (str->type == pChar)
		{
			free(str->p);
		}
		else if (str->type == cellArray)
		{
			free(str->array->c);	
		}

		str->type = pChar;
		str->p = strdup(value);
	}
	else
	{
		T* str = new T;
		str->p = strdup(value);
		str->type = pChar;
		
		ret.first->second = str;
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

void Object::SetFloat(std::string std, float value)
{
	std::pair<ObjectMap::iterator, bool> ret; 
	
	ret = m.insert(std::pair<std::string, T*>(std, NULL));
	
	if (!ret.second) // if value already exists
	{	
		T* str = ret.first->second;
		
		if (str->type == pChar)
		{
			free(str->p);
		}
		else if (str->type == cellArray)
		{
			free(str->array->c);	
		}
		
		str->type = floatingPoint;
		str->f = value;
	}
	else
	{
		T* str = new T;
		str->f = value;
		str->type = floatingPoint;
		
		ret.first->second = str;
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

void Object::SetArray(std::string std, cell_t* value, size_t size)
{
	std::pair<ObjectMap::iterator, bool> ret; 
	
	ret = m.insert(std::pair<std::string, T*>(std, NULL));
	
	if (!ret.second) // if value already exists
	{	
		T* str = ret.first->second;
		
		if (str->type == pChar)
		{
			free(str->p);
		}
		else if (str->type == cellArray)
		{
			free(str->array->c);	
		}

		
		str->type = cellArray;
		str->array->c = (cell_t*) malloc(sizeof(cell_t) * size);
		memcpy(str->array->c, value, sizeof(cell_t) * size);
		str->array->size = size;
	}
	else // values doesn't exist so insert
	{
		T* str = new T;
		str->type = cellArray;
		
		str->array = new CellArray;
		str->array->c = (cell_t*) malloc(sizeof(cell_t) * size);
		memcpy(str->array->c, value, sizeof(cell_t) * size);
		str->array->size = size;

		ret.first->second = str;
	}
}

CellArray* Object::GetArray(std::string std, bool &didFail)
{
	T* value = m.find(std)->second;

	if (value->type != cellArray)
	{
		didFail = true;
		return NULL;
	}
	
	didFail = false;
	return value->array;
}

Object::~Object()
{
	
	for (ObjectMap::iterator it = m.begin(); it != m.end(); ++it)
	{
		delete it->second;
	}
}
