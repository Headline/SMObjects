/** Double-include prevention */
#if defined _hl_challenge_included
  #endinput
#endif
#define _hl_challenge_included

native int GetObjectInt(Handle obj, char[] key);

native bool SetObjectInt(Handle obj, char[] key, int value);

native float GetObjectFloat(Handle obj, char[] key);

native bool SetObjectFloat(Handle obj, char[] key, float value);

native bool GetObjectBool(Handle obj, char[] key);

native bool SetObjectBool(Handle obj, char[] key, bool value);

native bool GetObjectString(Handle obj, char[] key, char[] buffer, int maxsize);

native bool SetObjectString(Handle obj, char[] key, char[] value);

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
