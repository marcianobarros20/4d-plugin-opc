/* --------------------------------------------------------------------------------
 #
 #	4DPlugin.h
 #	source generated by 4D Plugin Wizard
 #	Project : OPC
 #	author : miyako
 #	2013/09/29
 #
 # --------------------------------------------------------------------------------*/

#include "4DPluginAPI.h"

#include "opc_constants.h"

// --- OPC Document
void OPC_Get_document_type(sLONG_PTR *pResult, PackagePtr pParams);
void OPC_RESOURCE_TYPE_LIST(sLONG_PTR *pResult, PackagePtr pParams);
void OPC_EXTERNAL_TARGET_LIST(sLONG_PTR *pResult, PackagePtr pParams);
void OPC_EXTENSION_LIST(sLONG_PTR *pResult, PackagePtr pParams);
void OPC_Register_resource_type(sLONG_PTR *pResult, PackagePtr pParams);
void OPC_RELATION_TYPE_LIST(sLONG_PTR *pResult, PackagePtr pParams);