#include "extension.h"
#include "Object.h"

Objects g_obj;		/**< Global singleton for extension's main interface */
HandleType_t g_ObjectType;

class ObjectTypeHandler : public IHandleTypeDispatch
{
public:
	void OnHandleDestroy(HandleType_t type, void *object)
	{
		delete object;
	}
};

ObjectTypeHandler g_ObjectTypeHandler;

cell_t SetInt(IPluginContext *pContext, const cell_t *params)
{
	Handle_t hndl = static_cast<Handle_t>(params[1]);
	HandleError err;
	HandleSecurity sec;
 
	sec.pOwner = NULL;
	sec.pIdentity = myself->GetIdentity();
 

	Object* obj;
	if ((err = g_pHandleSys->ReadHandle(hndl, g_ObjectType, &sec, (void **)&obj)) != HandleError_None)
	{
		return pContext->ThrowNativeError("Invalid object handle %x (error %d)", hndl, err);
	}
 
	char* key;
	pContext->LocalToString(params[2], &key);
 
	int value = params[3];
	
	if (obj->SetInt(key, value))
	{
		return true;
	}
	else
	{
		return pContext->ThrowNativeError("Inconsistent types");
	}
}

cell_t GetInt(IPluginContext *pContext, const cell_t *params)
{
	Handle_t hndl = static_cast<Handle_t>(params[1]);
	HandleError err;
	HandleSecurity sec;
 
	sec.pOwner = NULL;
	sec.pIdentity = myself->GetIdentity();
 

	Object* obj;
	if ((err = g_pHandleSys->ReadHandle(hndl, g_ObjectType, &sec, (void **)&obj)) != HandleError_None)
	{
		return pContext->ThrowNativeError("Invalid object handle %x (error %d)", hndl, err);
	}
 
	char* key;
	pContext->LocalToString(params[2], &key);
 	
	bool didFail;
	int result;
	
	result = obj->GetInt(key, didFail);
	if (didFail)
	{
		return pContext->ThrowNativeError("Inconsistent types");
	}
	else
	{
		return result;
	}
}

cell_t SetBool(IPluginContext *pContext, const cell_t *params)
{
	Handle_t hndl = static_cast<Handle_t>(params[1]);
	HandleError err;
	HandleSecurity sec;
 
	sec.pOwner = NULL;
	sec.pIdentity = myself->GetIdentity();
 

	Object* obj;
	if ((err = g_pHandleSys->ReadHandle(hndl, g_ObjectType, &sec, (void **)&obj)) != HandleError_None)
	{
		return pContext->ThrowNativeError("Invalid object handle %x (error %d)", hndl, err);
	}
 
	char* key;
	pContext->LocalToString(params[2], &key);
 
	bool value = params[3];
	
	
	if (obj->SetBool(key, value))
	{
		return true;
	}
	else
	{
		return pContext->ThrowNativeError("Inconsistent types");
	}
}

cell_t GetBool(IPluginContext *pContext, const cell_t *params)
{
	Handle_t hndl = static_cast<Handle_t>(params[1]);
	HandleError err;
	HandleSecurity sec;
 
	sec.pOwner = NULL;
	sec.pIdentity = myself->GetIdentity();
 

	Object* obj;
	if ((err = g_pHandleSys->ReadHandle(hndl, g_ObjectType, &sec, (void **)&obj)) != HandleError_None)
	{
		return pContext->ThrowNativeError("Invalid object handle %x (error %d)", hndl, err);
	}
 
	char* key;
	pContext->LocalToString(params[2], &key);
 	
	bool didFail;
	bool result;
	
	result = obj->GetBool(key, didFail);
	if (didFail)
	{
		return pContext->ThrowNativeError("Inconsistent types");
	}
	else
	{
		return result;
	}
}

cell_t SetString(IPluginContext *pContext, const cell_t *params)
{
	Handle_t hndl = static_cast<Handle_t>(params[1]);
	HandleError err;
	HandleSecurity sec;
 
	sec.pOwner = NULL;
	sec.pIdentity = myself->GetIdentity();
 

	Object* obj;
	if ((err = g_pHandleSys->ReadHandle(hndl, g_ObjectType, &sec, (void **)&obj)) != HandleError_None)
	{
		return pContext->ThrowNativeError("Invalid object handle %x (error %d)", hndl, err);
	}
 
	char* key;
	pContext->LocalToString(params[2], &key);
 
	char* value;
	pContext->LocalToString(params[3], &value);
	
	
	if (obj->SetString(key, value))
	{
		return true;
	}
	else
	{
		return pContext->ThrowNativeError("Inconsistent types");
	}
}

cell_t GetString(IPluginContext *pContext, const cell_t *params) // handle, key, str, size
{
	Handle_t hndl = static_cast<Handle_t>(params[1]);
	HandleError err;
	HandleSecurity sec;
 
	sec.pOwner = NULL;
	sec.pIdentity = myself->GetIdentity();
 

	Object* obj;
	if ((err = g_pHandleSys->ReadHandle(hndl, g_ObjectType, &sec, (void **)&obj)) != HandleError_None)
	{
		return pContext->ThrowNativeError("Invalid object handle %x (error %d)", hndl, err);
	}
 
	char* key;
	pContext->LocalToString(params[2], &key);
 	
	bool didFail;
	char* result;
	
	result = obj->GetString(key, didFail);
	if (didFail)
	{
		return pContext->ThrowNativeError("Inconsistent types");
	}
	else
	{
		char* buffer;
		pContext->LocalToString(params[3], &buffer);
		size_t size = static_cast<size_t>(params[4]);

		snprintf(buffer, size, result);
		return true;
	}
}

cell_t SetFloat(IPluginContext *pContext, const cell_t *params)
{
	Handle_t hndl = static_cast<Handle_t>(params[1]);
	HandleError err;
	HandleSecurity sec;
 
	sec.pOwner = NULL;
	sec.pIdentity = myself->GetIdentity();
 

	Object* obj;
	if ((err = g_pHandleSys->ReadHandle(hndl, g_ObjectType, &sec, (void **)&obj)) != HandleError_None)
	{
		return pContext->ThrowNativeError("Invalid object handle %x (error %d)", hndl, err);
	}
 
	char* key;
	pContext->LocalToString(params[2], &key);
 
	float value = sp_ctof(params[3]);
	
	
	if (obj->SetFloat(key, value))
	{
		return true;
	}
	else
	{
		return pContext->ThrowNativeError("Inconsistent types");
	}
}

cell_t GetFloat(IPluginContext *pContext, const cell_t *params)
{
	Handle_t hndl = static_cast<Handle_t>(params[1]);
	HandleError err;
	HandleSecurity sec;
 
	sec.pOwner = NULL;
	sec.pIdentity = myself->GetIdentity();
 

	Object* obj;
	if ((err = g_pHandleSys->ReadHandle(hndl, g_ObjectType, &sec, (void **)&obj)) != HandleError_None)
	{
		return pContext->ThrowNativeError("Invalid object handle %x (error %d)", hndl, err);
	}
 
	char* key;
	pContext->LocalToString(params[2], &key);
 	
	bool didFail;
	float result;
	
	result = obj->GetFloat(key, didFail);
	if (didFail)
	{
		return pContext->ThrowNativeError("Inconsistent types");
	}
	else
	{
		return sp_ftoc(result);
	}
}

cell_t SetArray(IPluginContext *pContext, const cell_t *params) // handle, key, array, size
{
	Handle_t hndl = static_cast<Handle_t>(params[1]);
	HandleError err;
	HandleSecurity sec;
 
	sec.pOwner = NULL;
	sec.pIdentity = myself->GetIdentity();
 

	Object* obj;
	if ((err = g_pHandleSys->ReadHandle(hndl, g_ObjectType, &sec, (void **)&obj)) != HandleError_None)
	{
		return pContext->ThrowNativeError("Invalid object handle %x (error %d)", hndl, err);
	}
 
	char* key;
	pContext->LocalToString(params[2], &key);
 
	cell_t* value;
	pContext->LocalToPhysAddr(params[3], &value);
	
	size_t size = static_cast<size_t>(params[4]);
	
	if (obj->SetArray(key, value, size))
	{
		return true;
	}
	else
	{
		return pContext->ThrowNativeError("Inconsistent types");
	}
}

cell_t GetArray(IPluginContext *pContext, const cell_t *params) // handle, key, buffer, maxlen
{
	Handle_t hndl = static_cast<Handle_t>(params[1]);
	HandleError err;
	HandleSecurity sec;
 
	sec.pOwner = NULL;
	sec.pIdentity = myself->GetIdentity();
 

	Object* obj;
	if ((err = g_pHandleSys->ReadHandle(hndl, g_ObjectType, &sec, (void **)&obj)) != HandleError_None)
	{
		return pContext->ThrowNativeError("Invalid object handle %x (error %d)", hndl, err);
	}
 
	char* key;
	pContext->LocalToString(params[2], &key);
 	
	bool didFail;
	CellArray* result;
	
	result = obj->GetArray(key, didFail);
	if (didFail)
	{
		return pContext->ThrowNativeError("Inconsistent types");
	}
	else
	{
		cell_t* addr;
		pContext->LocalToPhysAddr(params[3], &addr);
		size_t size = static_cast<size_t>(params[4]);

		memcpy(addr, result->c, sizeof(cell_t) * size);

		return true;
	}
}

cell_t GetArraySize(IPluginContext *pContext, const cell_t *params) // handle, key, buffer, maxlen
{
	Handle_t hndl = static_cast<Handle_t>(params[1]);
	HandleError err;
	HandleSecurity sec;
 
	sec.pOwner = NULL;
	sec.pIdentity = myself->GetIdentity();
 

	Object* obj;
	if ((err = g_pHandleSys->ReadHandle(hndl, g_ObjectType, &sec, (void **)&obj)) != HandleError_None)
	{
		return pContext->ThrowNativeError("Invalid object handle %x (error %d)", hndl, err);
	}
 
	char* key;
	pContext->LocalToString(params[2], &key);
 	
	bool didFail;
	CellArray* result;
	
	result = obj->GetArray(key, didFail);
	if (didFail)
	{
		return pContext->ThrowNativeError("Inconsistent types");
	}
	else
	{
		return result->size;
	}
}

cell_t CreateObject(IPluginContext *pContext, const cell_t *params)
{
	Object* obj = new Object();
	
	Handle_t handle = handlesys->CreateHandle(g_ObjectType,
					obj,
					pContext->GetIdentity(),
					myself->GetIdentity(),
					NULL);

	if (handle == BAD_HANDLE)
	{
		delete obj;
		return BAD_HANDLE;
	}
	
	
	return handle;
}

const sp_nativeinfo_t MyNatives[] = 
{
	{"CreateObject",	CreateObject},
	{"SetObjectInt",	SetInt},
	{"GetObjectInt",	GetInt},
	{"SetObjectBool",	SetBool},
	{"GetObjectBool",	GetBool},
	{"SetObjectFloat",	SetFloat},
	{"GetObjectFloat",	GetFloat},
	{"GetObjectString",	GetString},
	{"SetObjectString",	SetString},
	{"GetObjectArray",	GetArray},
	{"SetObjectArray",	SetArray},
	{"GetObjectArraySize",	GetArraySize},
	{NULL,			NULL},
};

void Objects::SDK_OnAllLoaded()
{
	sharesys->AddNatives(myself, MyNatives);
	
	g_ObjectType = g_pHandleSys->CreateType("Object", 
		&g_ObjectTypeHandler, 
		0, 
		NULL, 
		NULL, 
		myself->GetIdentity(), 
		NULL);
}

void Objects::SDK_OnUnload()
{
	g_pHandleSys->RemoveType(g_ObjectType, myself->GetIdentity());
}

SMEXT_LINK(&g_obj);
