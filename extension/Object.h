#include <map>
#include <string>
#include <cstdlib>

#include "smsdk_ext.h"

enum UnionType
{
	boolean,
	integer,
	pChar,
	floatingPoint,
	cellArray
};

struct CellArray
{
	cell_t* c;
	size_t size;
	
	~CellArray()
	{
		free(c);
	}
};

struct T
{
	UnionType type;
	union { bool b; int i; char* p; float f; CellArray* array;};
	
	~T()
	{
		if (type == pChar)
		{
			free(p);
		}
		else if (type == cellArray)
		{
			delete array;
		}
	}
};

typedef std::map<std::string, T*> ObjectMap;

class Object
{
private:
	ObjectMap m;

public:
	void SetBool(std::string, bool);
	bool GetBool(std::string, bool&);

	void SetInt(std::string, int);
	int GetInt(std::string, bool&);

	void SetString(std::string, char*);
	char* GetString(std::string, bool&);
	
	void SetFloat(std::string, float);
	float GetFloat(std::string, bool&);
	
	void SetArray(std::string, cell_t*, size_t);
	CellArray* GetArray(std::string, bool&);

    int Size();
    
	~Object();
};
