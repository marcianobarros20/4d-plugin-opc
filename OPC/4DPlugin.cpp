/* --------------------------------------------------------------------------------
 #
 #	4DPlugin.cpp
 #	source generated by 4D Plugin Wizard
 #	Project : OPC
 #	author : miyako
 #	2017/05/02
 #
 # --------------------------------------------------------------------------------*/


#include "4DPluginAPI.h"
#include "4DPlugin.h"

#pragma mark -

bool IsProcessOnExit()
{
	C_TEXT name;
	PA_long32 state, time;
	PA_GetProcessInfo(PA_GetCurrentProcessNumber(), name, &state, &time);
	CUTF16String procName(name.getUTF16StringPtr());
	CUTF16String exitProcName((PA_Unichar *)"$\0x\0x\0\0\0");
	return (!procName.compare(exitProcName));
}

void OnStartup()
{
	opcInitLibrary();
}

void OnCloseProcess()
{
	if(IsProcessOnExit())
	{
		opcFreeLibrary();
	}
}

#pragma mark -
void PluginMain(PA_long32 selector, PA_PluginParameters params)
{
	try
	{
		PA_long32 pProcNum = selector;
		sLONG_PTR *pResult = (sLONG_PTR *)params->fResult;
		PackagePtr pParams = (PackagePtr)params->fParameters;

		CommandDispatcher(pProcNum, pResult, pParams); 
	}
	catch(...)
	{

	}
}

void CommandDispatcher (PA_long32 pProcNum, sLONG_PTR *pResult, PackagePtr pParams)
{
	switch(pProcNum)
	{
		case kInitPlugin :
		case kServerInitPlugin :
			OnStartup();
			break;
			
		case kCloseProcess :
			OnCloseProcess();
			break;

			// --- OPC Document

		case 1 :
			OPC_Get_document_type(pResult, pParams);
			break;

		case 2 :
			OPC_RESOURCE_TYPE_LIST(pResult, pParams);
			break;

		case 3 :
			OPC_EXTERNAL_TARGET_LIST(pResult, pParams);
			break;

		case 4 :
			OPC_EXTENSION_LIST(pResult, pParams);
			break;

		case 5 :
			OPC_Register_resource_type(pResult, pParams);
			break;

		case 6 :
			OPC_RELATION_TYPE_LIST(pResult, pParams);
			break;

// --- OPC Resource

		case 7 :
			OPC_Get_resource(pResult, pParams);
			break;

		case 8 :
			OPC_RESOURCE_LIST(pResult, pParams);
			break;

		case 9 :
			OPC_Get_resource_size(pResult, pParams);
			break;

		case 10 :
			OPC_Delete_resource(pResult, pParams);
			break;

		case 11 :
			OPC_Set_resource(pResult, pParams);
			break;

		case 12 :
			OPC_EXTERNAL_RESOURCE_LIST(pResult, pParams);
			break;

// --- OPC Relation

		case 13 :
			OPC_Create_relation(pResult, pParams);
			break;

		case 14 :
			OPC_Remove_relation(pResult, pParams);
			break;

		case 15 :
			OPC_Create_external_relation(pResult, pParams);
			break;

		case 16 :
			OPC_RELATION_LIST(pResult, pParams);
			break;

// --- OPC Constants

		case 17 :
			OPC_Document_type(pResult, pParams);
			break;

		case 18 :
			OPC_Relation_type(pResult, pParams);
			break;

	}
}
