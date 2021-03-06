// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             //  从 Windows 头文件中排除极少使用的信息
// Windows 头文件:
#include <windows.h>
#include <WindowsX.h>
#include <Commctrl.h>			// Windows component
#include <Shellapi.h>			// Windows Shell API
#include <Tlhelp32.h>			// Windows Process API
#include <shobjidl.h>			
#include <shlobj.h>
#include <Shlwapi.h>
#include <commdlg.h>
// C 运行时头文件
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <string.h>
// C++ 运行时文件
#include <assert.h>
// VC++ Header Files:
#include <uxtheme.h>
//Kernel Function..
#include <Winternl.h>
//DirectX Files:
#include "dinput.h"
// TODO: 在此处引用程序需要的其他头文件
