#include <SMObjects>
#include <profiler>

#define TAG "[SMOBJECTS]"
Handle profiler;

Object objects[10000];

public void OnPluginStart()
{
	profiler = CreateProfiler();
	StartProfiling(profiler);
		
	// Initialize
	for(int i = 0; i < sizeof(objects); i++)
	{
		objects[i] = new Object();
	}
	
	StopProfiling(profiler);
	float time = GetProfilerTime(profiler);
	PrintToServer("%s Object creation took %f seconds", TAG, time);
	StartProfiling(profiler);

	// Write
	char buffer[32];
	for(int i = 0; i < sizeof(objects); i++)
	{
		objects[i].SetInt("testint", i);
		objects[i].SetFloat("testfloat", float(i));
		IntToString(i, buffer, sizeof(buffer));
		objects[i].SetString("teststr", buffer);
		objects[i].SetBool("testbool", true);
	}
	
	StopProfiling(profiler);
	time = GetProfilerTime(profiler);
	PrintToServer("%s Object writing took %f seconds", TAG, time);
	StartProfiling(profiler);

	// Read
	for(int i = 0; i < sizeof(objects); i++)
	{
		objects[i].GetInt("testint");
		objects[i].GetFloat("testfloat");
		objects[i].GetString("teststr", buffer, sizeof(buffer));
		objects[i].GetBool("testbool");
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