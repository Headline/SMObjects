#include <map>

enum UnionType
{
	boolean,
	integer,
	pChar,
	floatingPoint
};

struct T
{
	UnionType type;
	union { bool b; int i; char* p; float f;};
	
	~T()
	{
		if (type == pChar)
		{
			free(p);
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
	
	~Object();
};
