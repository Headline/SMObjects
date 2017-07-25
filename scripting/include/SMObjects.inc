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

	public native ObjectType GetType(int index);

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
