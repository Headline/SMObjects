#include <stdio.h>
#include <tchar.h>
#include <map>
#include <string>
#include <iostream>

struct T
{
	int type_index;
	union { bool b; int i; char* p; float f;};
	
	~T()
	{
		if (type_index == 2)
		{
			free(p);
		}
	}
};

typedef std::map<std::string, T*> ObjectMap;
typedef std::pair<std::string, T*> Pair;

class Object
{
private:
	ObjectMap m;

public:
	bool SetBool(std::string, bool);
	bool GetBool(std::string, bool&);

	bool SetInt(std::string, int);
	int GetInt(std::string, bool&);

	bool SetString(std::string, char*);
	char* GetString(std::string, bool&);
	
	bool SetFloat(std::string, float);
	float GetFloat(std::string, bool&);
	
	~Object();
};
