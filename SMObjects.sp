#include <test>

public void OnPluginStart()
{
	RegAdminCmd("sm_test", Command_Test, ADMFLAG_ROOT);
}

public Action Command_Test(int client, int args)
{
	Handle handle = CreateObject();
	SetObjectInt(handle, "something", 32);
	PrintToServer("Some number: %i", GetObjectInt(handle, "something"));
}
