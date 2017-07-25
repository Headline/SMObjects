#include "extension.h"
#include "Object.h"
#include <cstring>

Objects g_obj;		/**< Global singleton for extension's main interface */
HandleType_t g_ObjectType;

class ObjectTypeHandler : public IHandleTypeDispatch
{
public:
	void OnHandleDestroy(HandleType_t type, void *object)
	{
		delete ((Object*) object);
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
	
	obj->SetInt(key, value);
	
	return 1;
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
	
	
	obj->SetBool(key, value);
	
	return 1;
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
	
	
	obj->SetString(key, value);
	
	return 1;
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
	
	
	obj->SetFloat(key, value);
	
	return 1;
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
	
	obj->SetArray(key, value, size);
	
	return 1;
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

cell_t GetMemberSize(IPluginContext *pContext, const cell_t *params)
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
    
    return obj->Size();
}

cell_t GetMemberType(IPluginContext *pContext, const cell_t *params)
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
    
    int index = static_cast<int>(params[2]);
	
	std::pair<std::string, T*> pair = obj->GetPair(index);
    if (pair.second == nullptr)
    {
        return pContext->ThrowNativeError("Invalid Index: %d (maxsize: %d)", index, obj->Size());
    }
    
	UnionType type = pair.second->type;
    return type;
}

cell_t GetMemberKey(IPluginContext *pContext, const cell_t *params)
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
	
	int index = static_cast<int>(params[2]);
	std::pair<std::string, T*> pair = obj->GetPair(index);
	
	if (pair.second == nullptr) // not found
	{
		return pContext->ThrowNativeError("Invalid Index: %d (maxsize: %d)", index, obj->Size());
	}

	char* buffer;
	pContext->LocalToString(params[3], &buffer);
	size_t size = static_cast<size_t>(params[4]);

	snprintf(buffer, size, pair.first.c_str());
	return true;
}

cell_t GetMemberInt(IPluginContext *pContext, const cell_t *params)
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
	
	int index = static_cast<int>(params[2]);
	std::pair<std::string, T*> pair = obj->GetPair(index);
	
	if (pair.second == nullptr) // not found
	{
		return pContext->ThrowNativeError("Invalid Index: %d (maxsize: %d)", index, obj->Size());
	}
	
	if (pair.second->type != integer) // inconsistent types
	{
		return pContext->ThrowNativeError("Inconsistent types");
	}

    return pair.second->i;
}

cell_t GetMemberFloat(IPluginContext *pContext, const cell_t *params)
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
	
	int index = static_cast<int>(params[2]);
	std::pair<std::string, T*> pair = obj->GetPair(index);
	
	if (pair.second == nullptr) // not found
	{
		return pContext->ThrowNativeError("Invalid Index: %d (maxsize: %d)", index, obj->Size());
	}
	
	if (pair.second->type != floatingPoint) // inconsistent types
	{
		return pContext->ThrowNativeError("Inconsistent types");
	}

    return sp_ftoc(pair.second->f);
}

cell_t GetMemberBool(IPluginContext *pContext, const cell_t *params)
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
	
	int index = static_cast<int>(params[2]);
	std::pair<std::string, T*> pair = obj->GetPair(index);
	
	if (pair.second == nullptr) // not found
	{
		return pContext->ThrowNativeError("Invalid Index: %d (maxsize: %d)", index, obj->Size());
	}
	
	if (pair.second->type != boolean) // inconsistent types
	{
		return pContext->ThrowNativeError("Inconsistent types");
	}

    return pair.second->b;
}

cell_t GetMemberString(IPluginContext *pContext, const cell_t *params)
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
	
	int index = static_cast<int>(params[2]);
	std::pair<std::string, T*> pair = obj->GetPair(index);
	
	if (pair.second == nullptr) // not found
	{
		return pContext->ThrowNativeError("Invalid Index: %d (maxsize: %d)", index, obj->Size());
	}
	
	if (pair.second->type != pChar) // inconsistent types
	{
		return pContext->ThrowNativeError("Inconsistent types");
	}

	char* buffer;
	pContext->LocalToString(params[3], &buffer);
	size_t size = static_cast<size_t>(params[4]);

	snprintf(buffer, size, pair.second->p);
}

cell_t GetMemberArray(IPluginContext *pContext, const cell_t *params)
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
	
	int index = static_cast<int>(params[2]);
	std::pair<std::string, T*> pair = obj->GetPair(index);
	
	if (pair.second == nullptr) // not found
	{
		return pContext->ThrowNativeError("Invalid Index: %d (maxsize: %d)", index, obj->Size());
	}
	
	if (pair.second->type != cellArray) // inconsistent types
	{
		return pContext->ThrowNativeError("Inconsistent types");
	}

	cell_t* addr;
	pContext->LocalToPhysAddr(params[3], &addr);
	size_t size = static_cast<size_t>(params[4]);

	memcpy(addr, pair.second->array, sizeof(cell_t) * size);
}

cell_t GetMemberArraySize(IPluginContext *pContext, const cell_t *params)
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
	
	int index = static_cast<int>(params[2]);
	std::pair<std::string, T*> pair = obj->GetPair(index);
	
	if (pair.second == nullptr) // not found
	{
		return pContext->ThrowNativeError("Invalid Index: %d (maxsize: %d)", index, obj->Size());
	}
	
	if (pair.second->type != cellArray) // inconsistent types
	{
		return pContext->ThrowNativeError("Inconsistent types");
	}

	return pair.second->array->size;
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
	{"Object.Object",           CreateObject},
	{"Object.SetInt",           SetInt},
	{"Object.GetInt",           GetInt},
	{"Object.SetBool",          SetBool},
	{"Object.GetBool",          GetBool},
	{"Object.SetFloat",         SetFloat},
	{"Object.GetFloat",         GetFloat},
	{"Object.GetString",        GetString},
	{"Object.SetString",        SetString},
	{"Object.GetArray",         GetArray},
	{"Object.SetArray",         SetArray},
	{"Object.GetArraySize",     GetArraySize},
	
	// iteration stuff
	{"Object.MemberCount.get",		GetMemberSize},
    {"Object.GetMemberType",		GetMemberType},
	{"Object.GetMemberKey",			GetMemberKey},
    {"Object.GetMemberInt",			GetMemberInt},
    {"Object.GetMemberFloat",		GetMemberFloat},
    {"Object.GetMemberBool",		GetMemberBool},
    {"Object.GetMemberString",		GetMemberString},
    {"Object.GetMemberArray",		GetMemberArray},
    {"Object.GetMemberArraySize",	GetMemberArraySize},
	{NULL,                      NULL},
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
