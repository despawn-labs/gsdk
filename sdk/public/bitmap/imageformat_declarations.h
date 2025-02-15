//========== Copyright � Valve Corporation, All rights reserved. ========

#ifndef IMAGEFORMAT_DECLARATIONS_HDR
#define IMAGEFORMAT_DECLARATIONS_HDR


enum NormalDecodeMode_t
{
	NORMAL_DECODE_NONE			= 0,
	NORMAL_DECODE_ATI2N			= 1,
	NORMAL_DECODE_ATI2N_ALPHA	= 2
};

// Forward declaration
#ifdef _WIN32
typedef enum _D3DFORMAT D3DFORMAT;
typedef enum DXGI_FORMAT;
#endif

//-----------------------------------------------------------------------------
// The various image format types
//-----------------------------------------------------------------------------

// don't bitch that inline functions aren't used!!!!
#ifndef SPU
#pragma warning(disable : 4514)
#endif

enum ImageFormat 
{
	IMAGE_FORMAT_DEFAULT = -2,	// Use this image format if you want to perform tool operations on the texture
	IMAGE_FORMAT_UNKNOWN = -1,
	IMAGE_FORMAT_RGBA8888 = 0,
	IMAGE_FORMAT_ABGR8888,
	IMAGE_FORMAT_RGB888,
	IMAGE_FORMAT_BGR888,
	IMAGE_FORMAT_RGB565,
	IMAGE_FORMAT_I8,
	IMAGE_FORMAT_IA88,
	IMAGE_FORMAT_P8,
	IMAGE_FORMAT_A8,
	IMAGE_FORMAT_RGB888_BLUESCREEN,
	IMAGE_FORMAT_BGR888_BLUESCREEN,
	IMAGE_FORMAT_ARGB8888,
	IMAGE_FORMAT_BGRA8888,
	IMAGE_FORMAT_DXT1,
	IMAGE_FORMAT_DXT3,
	IMAGE_FORMAT_DXT5,
	IMAGE_FORMAT_BGRX8888,
	IMAGE_FORMAT_BGR565,
	IMAGE_FORMAT_BGRX5551,
	IMAGE_FORMAT_BGRA4444,
	IMAGE_FORMAT_DXT1_ONEBITALPHA,
	IMAGE_FORMAT_BGRA5551,
	IMAGE_FORMAT_UV88,
	IMAGE_FORMAT_UVWQ8888,
	IMAGE_FORMAT_RGBA16161616F,
	IMAGE_FORMAT_RGBA16161616,
	IMAGE_FORMAT_UVLX8888,
	IMAGE_FORMAT_R32F,			// Single-channel 32-bit floating point
	IMAGE_FORMAT_RGB323232F,	// NOTE: D3D9 does not have this format
	IMAGE_FORMAT_RGBA32323232F,
	IMAGE_FORMAT_RG1616F,
	IMAGE_FORMAT_RG3232F,
	IMAGE_FORMAT_RGBX8888,

	IMAGE_FORMAT_NULL,			// Dummy format which takes no video memory

	// Compressed normal map formats
	IMAGE_FORMAT_ATI2N,			// One-surface ATI2N / DXN format
	IMAGE_FORMAT_ATI1N,			// Two-surface ATI1N format

	IMAGE_FORMAT_RGBA1010102,	// 10 bit-per component render targets
	IMAGE_FORMAT_BGRA1010102,
	IMAGE_FORMAT_R16F,			// 16 bit FP format

	// Depth-stencil texture formats
	IMAGE_FORMAT_D16,
	IMAGE_FORMAT_D15S1,
	IMAGE_FORMAT_D32,
	IMAGE_FORMAT_D24S8,
	IMAGE_FORMAT_LINEAR_D24S8,
	IMAGE_FORMAT_D24X8,
	IMAGE_FORMAT_D24X4S4,
	IMAGE_FORMAT_D24FS8,
	IMAGE_FORMAT_D16_SHADOW,	// Specific formats for shadow mapping
	IMAGE_FORMAT_D24X8_SHADOW,	// Specific formats for shadow mapping

	// supporting these specific formats as non-tiled for procedural cpu access (360-specific)
	IMAGE_FORMAT_LINEAR_BGRX8888,
	IMAGE_FORMAT_LINEAR_RGBA8888,
	IMAGE_FORMAT_LINEAR_ABGR8888,
	IMAGE_FORMAT_LINEAR_ARGB8888,
	IMAGE_FORMAT_LINEAR_BGRA8888,
	IMAGE_FORMAT_LINEAR_RGB888,
	IMAGE_FORMAT_LINEAR_BGR888,
	IMAGE_FORMAT_LINEAR_BGRX5551,
	IMAGE_FORMAT_LINEAR_I8,
	IMAGE_FORMAT_LINEAR_RGBA16161616,
	IMAGE_FORMAT_LINEAR_A8,
	IMAGE_FORMAT_LINEAR_DXT1,
	IMAGE_FORMAT_LINEAR_DXT3,
	IMAGE_FORMAT_LINEAR_DXT5,

	IMAGE_FORMAT_LE_BGRX8888,
	IMAGE_FORMAT_LE_BGRA8888,

	// these are used for runtime conversion to DXT1/5
	IMAGE_FORMAT_DXT1_RUNTIME,
	IMAGE_FORMAT_DXT5_RUNTIME,

	// special depth format
	IMAGE_FORMAT_INTZ,

	NUM_IMAGE_FORMATS
};



#if defined( DX_TO_GL_ABSTRACTION ) || defined( _PS3 )
typedef enum _D3DFORMAT
	{
		D3DFMT_INDEX16,
		D3DFMT_D16,
		D3DFMT_D24S8,
		D3DFMT_A8R8G8B8,
		D3DFMT_A4R4G4B4,
		D3DFMT_X8R8G8B8,
		D3DFMT_R5G6R5,
		D3DFMT_X1R5G5B5,
		D3DFMT_A1R5G5B5,
		D3DFMT_L8,
		D3DFMT_A8L8,
		D3DFMT_A,
		D3DFMT_DXT1,
		D3DFMT_DXT3,
		D3DFMT_DXT5,
		D3DFMT_V8U8,
		D3DFMT_Q8W8V8U8,
		D3DFMT_X8L8V8U8,
		D3DFMT_A16B16G16R16F,
		D3DFMT_A16B16G16R16,
		D3DFMT_R32F,
		D3DFMT_A32B32G32R32F,
		D3DFMT_R8G8B8,
		D3DFMT_D24X4S4,
		D3DFMT_A8,
		D3DFMT_R5G6B5,
		D3DFMT_D15S1,
		D3DFMT_D24X8,
		D3DFMT_VERTEXDATA,
		D3DFMT_INDEX32,

		// new d3d format enums for Source main engine (i.e Portal2, AS, Dota)
		D3DFMT_D24FS8,
		D3DFMT_A8B8G8R8,
		D3DFMT_P8,
		D3DFMT_G16R16F,
		D3DFMT_G32R32F,
		D3DFMT_X8B8G8R8,
		D3DFMT_A2B10G10R10,
		D3DFMT_A2R10G10B10,
		D3DFMT_R16F,
		D3DFMT_D32,

		// adding fake D3D format names for the vendor specific ones (eases debugging/logging)
		
		// NV shadow depth tex
		D3DFMT_NV_INTZ		= 0x5a544e49,	// MAKEFOURCC('I','N','T','Z')
		D3DFMT_NV_RAWZ		= 0x5a574152,	// MAKEFOURCC('R','A','W','Z')

		// NV null tex
		D3DFMT_NV_NULL		= 0x4c4c554e,	// MAKEFOURCC('N','U','L','L')

		// ATI shadow depth tex
		D3DFMT_ATI_D16		= 0x36314644,	// MAKEFOURCC('D','F','1','6')
		D3DFMT_ATI_D24S8	= 0x34324644,	// MAKEFOURCC('D','F','2','4')

		// ATI 1N and 2N compressed tex
		D3DFMT_ATI_2N		= 0x32495441,	// MAKEFOURCC('A', 'T', 'I', '2')
		D3DFMT_ATI_1N		= 0x31495441,	// MAKEFOURCC('A', 'T', 'I', '1')
		
		D3DFMT_UNKNOWN
	} D3DFORMAT;
#endif



#endif
