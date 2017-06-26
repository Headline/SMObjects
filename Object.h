#include <map>
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
	bool SetBool(std::string, bool);
	bool GetBool(std::string, bool&);

	bool SetInt(std::string, int);
	int GetInt(std::string, bool&);

	bool SetString(std::string, char*);
	char* GetString(std::string, bool&);
	
	bool SetFloat(std::string, float);
	float GetFloat(std::string, bool&);
	
	bool SetArray(std::string, cell_t*, size_t);
	CellArray* GetArray(std::string, bool&);

	~Object();
};
