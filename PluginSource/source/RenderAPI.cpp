#include "RenderAPI.h"
#include "PlatformBase.h"
#include "Unity/IUnityGraphics.h"


RenderAPI* CreateRenderAPI(UnityGfxRenderer apiType)
{
PLUGIN_LOG("CreateRenderAPI");
PLUGIN_LOG("CreateRenderAPI apiType %i",apiType);
#	if SUPPORT_D3D11
	if (apiType == kUnityGfxRendererD3D11)
	{
		extern RenderAPI* CreateRenderAPI_D3D11();
		return CreateRenderAPI_D3D11();
	}
#	endif // if SUPPORT_D3D11

#	if SUPPORT_D3D12
	if (apiType == kUnityGfxRendererD3D12)
	{
		extern RenderAPI* CreateRenderAPI_D3D12();
		return CreateRenderAPI_D3D12();
	}
#	endif // if SUPPORT_D3D12


#	if SUPPORT_OPENGL_UNIFIED
PLUGIN_LOG("CreateRenderAPI SUPPORT_OPENGL_UNIFIED");
	if (apiType == kUnityGfxRendererOpenGLCore || apiType == kUnityGfxRendererOpenGLES20 || apiType == kUnityGfxRendererOpenGLES30)
	{
	PLUGIN_LOG("CreateRenderAPI SUPPORT_OPENGL_UNIFIED match");
		extern RenderAPI* CreateRenderAPI_OpenGLCoreES(UnityGfxRenderer apiType);
		return CreateRenderAPI_OpenGLCoreES(apiType);
	}else{
	PLUGIN_LOG("CreateRenderAPI SUPPORT_OPENGL_UNIFIED no match");
	}
#	endif // if SUPPORT_OPENGL_UNIFIED

#	if SUPPORT_METAL
	if (apiType == kUnityGfxRendererMetal)
	{
		extern RenderAPI* CreateRenderAPI_Metal();
		return CreateRenderAPI_Metal();
	}
#	endif // if SUPPORT_METAL

#	if SUPPORT_VULKAN
	if (apiType == kUnityGfxRendererVulkan)
	{
		extern RenderAPI* CreateRenderAPI_Vulkan();
		return CreateRenderAPI_Vulkan();
	}
#	endif // if SUPPORT_VULKAN
PLUGIN_LOG("CreateRenderAPI finished");
	// Unknown or unsupported graphics API
	return NULL;
}
