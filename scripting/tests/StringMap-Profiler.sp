#include <SMObjects>
#include <sourcemod>
#include <profiler>

#define TAG "[StringMap]"
Handle profiler;

StringMap objects[10000];

public void OnPluginStart()
{
	profiler = CreateProfiler();
	StartProfiling(profiler);
		
	// Initialize
	for(int i = 0; i < sizeof(objects); i++)
	{
		objects[i] = new StringMap();
	}
	
	StopProfiling(profiler);
	float time = GetProfilerTime(profiler);
	PrintToServer("%s Object creation took %f seconds", TAG, time);
	StartProfiling(profiler);

	// Write
	char buffer[32];
	for(int i = 0; i < sizeof(objects); i++)
	{
		objects[i].SetValue("testint", i);
		objects[i].SetValue("testfloat", float(i));
		IntToString(i, buffer, sizeof(buffer));
		objects[i].SetString("teststr", buffer);
		objects[i].SetValue("testbool", true);
	}
	
	StopProfiling(profiler);
	time = GetProfilerTime(profiler);
	PrintToServer("%s Object writing took %f seconds", TAG, time);
	StartProfiling(profiler);

	// Read
	float f; int integer; bool b;
	for(int i = 0; i < sizeof(objects); i++)
	{
		objects[i].GetValue("testint", integer);
		objects[i].GetValue("testfloat", f);
		objects[i].GetString("teststr", buffer, sizeof(buffer));
		objects[i].GetValue("testbool", b);
	}
	
	StopProfiling(profiler);
	time = GetProfilerTime(profiler);
	PrintToServer("%s Object reading took %f seconds", TAG, time);
	StartProfiling(profiler);

	
	// Delete
	for(int i = 0; i < sizeof(objects); i++)
	{
		delete objects[i];
	}
	
	StopProfiling(profiler);
	time = GetProfilerTime(profiler);
	PrintToServer("%s Object deletion took %f seconds", TAG, time);
}