/** Double-include prevention */
#if defined _hl_challenge_included
  #endinput
#endif
#define _hl_challenge_included









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
