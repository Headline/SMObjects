#ifndef _INCLUDE_SM_EXT_HEADER
#define _INCLUDE_SM_EXT_HEADER

#include "smsdk_ext.h"

class Objects : public SDKExtension
{
public:
	virtual void SDK_OnAllLoaded();
	virtual void SDK_OnUnload();
};

#endif
