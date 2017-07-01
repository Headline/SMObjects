#include <dynamic>
#include <profiler>

#define TAG "[DYNAMIC]"
#pragma dynamic 131072 

Handle profiler;

Dynamic objects[10000];


public void OnPluginStart()
{
	profiler = CreateProfiler();
	StartProfiling(profiler);
		
	// Initialize
	for(int i = 0; i < sizeof(objects); i++)
	{
		objects[i] = Dynamic();
	}
	
	StopProfiling(profiler);
	float time = GetProfilerTime(profiler);
	PrintToServer("%s Object creation took %f seconds", TAG, time);
	StartProfiling(profiler);

	// Write
	DynamicOffset[][] offsets = new DynamicOffset[sizeof(objects)][4];
	char buffer[32];
	for(int i = 0; i < sizeof(objects); i++)
	{
		offsets[i][0] = objects[i].SetInt("testint", i);
		offsets[i][1] = objects[i].SetFloat("testfloat", float(i));
		IntToString(i, buffer, sizeof(buffer));
		offsets[i][2] = objects[i].SetString("teststr", buffer);
		offsets[i][3] = objects[i].SetBool("testbool", true);
	}
	
	StopProfiling(profiler);
	time = GetProfilerTime(profiler);
	PrintToServer("%s Object writing took %f seconds", TAG, time);
	StartProfiling(profiler);

	// Read
	for(int i = 0; i < sizeof(objects); i++)
	{
		objects[i].GetIntByOffset(offsets[i][0]);
		objects[i].GetFloatByOffset(offsets[i][1]);
		objects[i].GetStringByOffset(offsets[i][2], buffer, sizeof(buffer));
		objects[i].GetBoolByOffset(offsets[i][3]);
	}
	
	StopProfiling(profiler);
	time = GetProfilerTime(profiler);
	PrintToServer("%s Object reading took %f seconds", TAG, time);
	StartProfiling(profiler);

	
	// Delete
	for(int i = 0; i < sizeof(objects); i++)
	{
		objects[i].Dispose();
	}
	
	StopProfiling(profiler);
	time = GetProfilerTime(profiler);
	PrintToServer("%s Object deletion took %f seconds", TAG, time);
}
