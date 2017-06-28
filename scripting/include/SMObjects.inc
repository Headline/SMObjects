/** Double-include prevention */
#if defined SMObjects_included
  #endinput
#endif
#define SMObjects_included

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
	public native any GetCell(char[] key);
	
	/**
	 * Sets a cell type for a specified key.
	 * Note: Use SetObjectInt for integers
	 * @param char[]	key to pull value from
	 * @param any		value
	 * @return       	true on success
	 */
	public native bool SetCell(char[] key, any value);
	
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
};

/**
 * Grabs an integer from a specified key.
 * 
 * @param Handle 	object
 * @param char[]	key to pull value from
 * @return       	integer value
 */
native int GetObjectInt(Handle obj, char[] key);

/**
 * Sets an integer for a specified key.
 * 
 * @param Handle 	object
 * @param char[]	key to pull value from
 * @param int		value
 * @return       	true on success
 */
native bool SetObjectInt(Handle obj, char[] key, int value);

/**
 * Grabs a cell type for a specified key.
 * Note: Use GetObjectInt for integers
 * @param Handle 	object
 * @param char[]	key to pull value from
 * @return       	any value
 */
stock any GetObjectCell(Handle obj2, char[] key)
{
	return view_as<any>(GetObjectInt(obj2, key));
}

/**
 * Sets a cell type for a specified key.
 * Note: Use SetObjectInt for integers
 * @param Handle 	object
 * @param char[]	key to pull value from
 * @param any		value
 * @return       	true on success
 */
stock bool SetObjectCell(Handle obj2, char[] key, any value)
{
	return SetObjectInt(obj2, key, view_as<int>(value));
}

/**
 * Grabs a float for a specified key.
 *
 * @param Handle 	object
 * @param char[]	key to pull value from
 * @return       	float value
 */
native float GetObjectFloat(Handle obj, char[] key);

/**
 * Sets a float for a specified key.
 *
 * @param Handle 	object
 * @param char[]	key to pull value from
 * @param float		value
 * @return       	true on success
 */
native bool SetObjectFloat(Handle obj, char[] key, float value);

/**
 * Grabs a bool for a specified key.
 *
 * @param Handle 	object
 * @param char[]	key to pull value from
 * @return       	boolean value
 */
native bool GetObjectBool(Handle obj, char[] key);

/**
 * Sets a bool for a specified key.
 *
 * @param Handle 	object
 * @param char[]	key to pull value from
 * @param bool		value
 * @return       	true on success
 */
native bool SetObjectBool(Handle obj, char[] key, bool value);

/**
 * Grabs a string for a specified key.
 *
 * @param Handle 	object
 * @param char[]	key to pull value from
 * @param char[]	output buffer
 * @param int		max # of bytes to write
 * @return       	true on success
 */
native bool GetObjectString(Handle obj, char[] key, char[] buffer, int maxsize);

/**
 * Sets a string for a specified key.
 *
 * @param Handle 	object
 * @param char[]	key to pull value from
 * @param char[]	input string
 * @return       	true on success
 */
native bool SetObjectString(Handle obj, char[] key, char[] value);

/**
 * Gets an array for a specified key.
 *
 * @param Handle 	object
 * @param char[]	key to pull value from
 * @param any[]		output buffer
 * @param int		max # of bytes to write
 * @return       	true on success
 */
native bool GetObjectArray(Handle obj, char[] key, any[] buffer, int maxsize);

/**
 * Sets an array for a specified key.
 *
 * @param Handle 	object
 * @param char[]	key to pull value from
 * @param any[]		input buffer
 * @param int		max # of bytes to read
 * @return       	true on success
 */
native bool SetObjectArray(Handle obj, char[] key, any[] buffer, int maxsize);

/**
 * Grabs the size of a written array
 *
 * @param Handle 	object
 * @param char[]	key to pull value from
 * @return       	buffer size
 */
native int GetObjectArraySize(Handle obj, char[] key);

/**
 * Constructs an Object and returns the handle
 *
 * @return       	Object handle
 */
native Handle CreateObject();

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
