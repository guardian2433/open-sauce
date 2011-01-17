
__CPP_CODE_START__
#ifndef LOWLEVEL_NO_X360_XMA

#pragma comment (lib, "C:\\Program Files (x86)\\Microsoft Xbox 360 SDK\\lib\\win32\\vs2008\\xmaencoder.lib")

// Define some xmaencoder.lib extern objects that we need for decoding...
class CXMATarget
{
	PAD32; PAD32;
public:
	virtual HRESULT __stdcall DecodeWave(LPCWSTR xma_file, LPCWSTR pcm_file);
	virtual HRESULT __stdcall EncodeWave(); // I'm not going to sit here and defe the params, frig off Randy
	virtual ~CXMATarget();
}; BOOST_STATIC_ASSERT( sizeof(CXMATarget) == 0xC );

extern "C"
{
	CXMATarget* CreateXMATarget(CXMATarget*& out_obj);
	void FreeXMATarget(CXMATarget* obj);
};

#endif
__CPP_CODE_END__