#include <test>

public void OnPluginStart()
{
	RegAdminCmd("sm_test", Command_Test, ADMFLAG_ROOT);
}

public Action Command_Test(int client, int args)
{
	Handle handle = CreateObject();
	if (handle == null)
	{
		PrintToServer("NULL");
	}
	else
	{
		PrintToServer("VALUE IS %i", handle);
	}
	SetObjectInt(handle, "index", 32323232);
	PrintToServer("CLinet Index: %i", GetObjectInt(handle, "index"));
	//delete handle;
}
