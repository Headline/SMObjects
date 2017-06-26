/** Double-include prevention */
#if defined SMObjects_included
  #endinput
#endif
#define SMObjects_included

native int GetObjectInt(Handle obj, char[] key);

native bool SetObjectInt(Handle obj, char[] key, int value);

stock any GetObjectCell(Handle obj2, char[] key)
{
	return view_as<any>(GetObjectInt(obj2, key));
}

stock bool SetObjectCell(Handle obj2, char[] key, any value)
{
	return SetObjectInt(obj2, key, view_as<int>(value));
}

native float GetObjectFloat(Handle obj, char[] key);

native bool SetObjectFloat(Handle obj, char[] key, float value);

native bool GetObjectBool(Handle obj, char[] key);

native bool SetObjectBool(Handle obj, char[] key, bool value);

native bool GetObjectString(Handle obj, char[] key, char[] buffer, int maxsize);

native bool SetObjectString(Handle obj, char[] key, char[] value);

native bool GetObjectArray(Handle obj, char[] key, any[] buffer, int maxsize);

native bool SetObjectArray(Handle obj, char[] key, any[] buffer, int maxsize);

native int GetObjectArraySize(Handle obj, char[] key);

native Handle CreateObject();

methodmap Object < Handle
{
	public Object()
	{
		return view_as<Object>(CreateObject());
	}
	
	public int GetInt(char[] key)
	{
		return GetObjectInt(this, key);
	}
	
	public bool SetInt(char[] key, int value)
	{
		return SetObjectInt(this, key, value);
	}
	
	public any GetCell(char[] key)
	{
		return GetObjectCell(this, key);
	}
	
	public bool SetCell(char[] key, any value)
	{
		return SetObjectCell(this, key, value);
	}
	
	public bool GetBool(char[] key)
	{
		return GetObjectBool(this, key);
	}
	
	public bool SetBool(char[] key, bool value)
	{
		return SetObjectBool(this, key, value);
	}

	public float GetFloat(char[] key)
	{
		return GetObjectFloat(this, key);
	}
	
	public bool SetFloat(char[] key, float value)
	{
		return SetObjectFloat(this, key, value);
	}
	
	public bool GetString(char[] key, char[] buffer, int length)
	{
		return GetObjectString(this, key, buffer, length);
	}
	
	public bool SetString(char[] key, char[] value)
	{
		return SetObjectString(this, key, value);
	}
	
	public bool GetArray(char[] key, any[] buffer, int length)
	{
		return GetObjectArray(this, key, buffer, length);
	}
	
	public bool SetArray(char[] key, any[] buffer, int length)
	{
		return SetObjectArray(this, key, buffer, length);
	}
	
	public int GetArraySize(char[] key)
	{
		return GetObjectArraySize(this, key);
	}
};

public Extension __ext_objects = 
{
	name = "Objects",
	file = "objects.ext",
#if defined AUTOLOAD_EXTENSIONS
	autoload = 1,
#else
	autoload = 0,
#endif
#if defined REQUIRE_EXTENSIONS
	required = 1,
#else
	required = 0,
#endif
};
