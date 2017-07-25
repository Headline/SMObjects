/** Double-include prevention */
#if defined SMObjects_included
  #endinput
#endif
#define SMObjects_included

enum ObjectType
{
	Type_Boolean = 0,
	Type_Integer,
	Type_String,
	Type_Float,
	Type_CellArray
};

methodmap Object < Handle
{
	/**
	 * Constructs an Object and returns the handle
	 *
	 * @return       	Object handle
	 */
	public native Object();
	
	/**
	 * Grabs an integer from a specified key.
	 * 
	 * @param char[]	key to pull value from
	 * @return       	integer value
	 */
	public native int GetInt(char[] key);
	
	/**
	 * Sets an integer for a specified key.
	 * 
	 * @param char[]	key to pull value from
	 * @param int		value
	 * @return       	true on success
	 */
	public native bool SetInt(char[] key, int value);
	
	/**
	 * Grabs a cell type for a specified key.
	 * Note: Use GetObjectInt for integers
	 * @param char[]	key to pull value from
	 * @return       	any value
	 */
	public any GetCell(char[] key)
	{
		view_as<any>(this.GetInt(key));
	}
	
	/**
	 * Sets a cell type for a specified key.
	 * Note: Use SetObjectInt for integers
	 * @param char[]	key to pull value from
	 * @param any		value
	 * @return       	true on success
	 */
	public bool SetCell(char[] key, any value)
	{
		this.SetInt(key, view_as<int>(value));
	}
	
	/**
	 * Grabs a bool for a specified key.
	 *
	 * @param char[]	key to pull value from
	 * @return       	boolean value
	 */
	public native bool GetBool(char[] key);
	
	/**
	 * Sets a bool for a specified key.
	 *
	 * @param char[]	key to pull value from
	 * @param bool		value
	 * @return       	true on success
	 */
	public native bool SetBool(char[] key, bool value);

	/**
	 * Grabs a float for a specified key.
	 *
	 * @param char[]	key to pull value from
	 * @return       	float value
	 */
	public native float GetFloat(char[] key);
	
	/**
	 * Sets a float for a specified key.
	 *
	 * @param char[]	key to pull value from
	 * @param float		value
	 * @return       	true on success
	 */
	public native bool SetFloat(char[] key, float value);
	
	/**
	 * Grabs a string for a specified key.
	 *
	 * @param char[]	key to pull value from
	 * @param char[]	output buffer
	 * @param int		max # of bytes to write
	 * @return       	true on success
	 */
	public native bool GetString(char[] key, char[] buffer, int length);
	
	/**
	 * Sets a string for a specified key.
	 *
	 * @param char[]	key to pull value from
	 * @param char[]	input string
	 * @return       	true on success
	 */
	public native bool SetString(char[] key, char[] value);
	
	/**
	 * Gets an array for a specified key.
	 *
	 * @param char[]	key to pull value from
	 * @param any[]		output buffer
	 * @param int		max # of bytes to write
	 * @return       	true on success
	 */
	public native bool GetArray(char[] key, any[] buffer, int length);
	
	/**
	 * Sets an array for a specified key.
	 *
	 * @param char[]	key to pull value from
	 * @param any[]		input buffer
	 * @param int		max # of bytes to read
	 * @return       	true on success
	 */
	public native bool SetArray(char[] key, any[] buffer, int length);
	
	/**
	 * Grabs the size of a written array
	 *
	 * @param char[]	key to pull value from
	 * @return       	buffer size
	 */
	public native int GetArraySize(char[] key);


	/**
	 * Grabs the amount of members in the object
	 *
	 * @return int   	Size
	 */
	property int MemberCount
	{
		public native get();
	}

	/**
	 * Gets the type of a specified index
	 *
	 * @param index		member index
	 * @return none
	 */
	public native ObjectType GetMemberType(int index);
	
	/**
	 * Grabs the key name for a member index
	 *
	 * @param index		member index
	 * @param buffer	buffer to write to
	 * @param maxlen	max number of bytes to write
	 * @return none
	 */
	public native int GetMemberKey(int index, char[] buffer, int maxlen);
	
	/**
	 * Gets the int from a member index
	 *
	 * @param index		member index
	 * @return int		value
	 */
	public native int GetMemberInt(int index);
	
	/**
	 * Gets the float from a member index
	 *
	 * @param index		member index
	 * @return float	value
	 */
	public native float GetMemberFloat(int index);
	
	/**
	 * Gets the bool from a member index
	 *
	 * @param index		member index
	 * @return bool		value
	 */
	public native bool GetMemberBool(int index);

	/**
	 * Gets the string from a member index
	 *
	 * @param index		member index
	 * @param buffer	buffer to write to
	 * @param maxlen	max length
	 * @return none
	 */
	public native void GetMemberString(int index, char[] buffer, int maxlen);
	
	/**
	 * Gets the any[] array from a member index
	 *
	 * @param index		member index
	 * @param buffer	buffer to write to
	 * @param maxlen	max length
	 * @return none
	 */
	public native void GetMemberArray(int index, any[] buffer, int maxlen);
	
	/**
	 * Get's a member's array size (required for GetMemberArray)
	 *
	 * @param index		member index
	 * @return int		size
	 */
	public native int GetMemberArraySize(int index);
	
	/**
	 * Converts an SMObject type into a KeyValues structure.
	 *
	 * Creates a new handle that must be closed.
	 *
	 * @return KeyValues   	KV Structure
	 */
	public KeyValues ToKeyValues()
	{
		KeyValues kv = new KeyValues("SMObject");
		
		for (int i = 0; i < this.MemberCount; i++)
		{
			// Create new KV key
			char keyName[16];
			IntToString(i, keyName, sizeof(keyName));
			
			// Get Current SMObject key
			char key[32];
			this.GetMemberKey(i, key, sizeof(key));
			
			// Get type
			ObjectType type = this.GetMemberType(i);
			
			// Write type and key to KeyValues
			switch (type)
			{
				case Type_Integer:
					kv.SetNum(key, this.GetMemberInt(i));
				case Type_Boolean:
					kv.SetNum(key, view_as<int>(this.GetMemberBool(i)));
				case Type_Float:
					kv.SetFloat(key, this.GetMemberFloat(i));
				case Type_String:
				{
					char value[128];
					this.GetMemberString(i, value, sizeof(value));
					kv.SetString(key, value);
				}
				case Type_CellArray:
				{
					// do nothing, what would we do?
				}
			}
		}
		
		return kv;
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
