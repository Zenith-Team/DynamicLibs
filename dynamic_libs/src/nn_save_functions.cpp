/****************************************************************************
 * Copyright (C) 2015
 * by Dimok
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any
 * damages arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any
 * purpose, including commercial applications, and to alter it and
 * redistribute it freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you
 * must not claim that you wrote the original software. If you use
 * this software in a product, an acknowledgment in the product
 * documentation would be appreciated but is not required.
 *
 * 2. Altered source versions must be plainly marked as such, and
 * must not be misrepresented as being the original software.
 *
 * 3. This notice may not be removed or altered from any source
 * distribution.
 ***************************************************************************/
#include "dynamic_libs/os_functions.h"
#include "dynamic_libs/nn_save_functions.h"

u32 nn_save_handle = 0;


EXPORT_DECL(s32, SAVEInit, void);
EXPORT_DECL(void, SAVEShutdown, void);

EXPORT_DECL(s32, SAVEInitSaveDir, u8 user);
EXPORT_DECL(s32, SAVEChangeDir, void* pClient, void* pCmd, u8 user, const char* path, s32 errHandling);
EXPORT_DECL(s32, SAVEChangeDirAsync, void* pClient, void* pCmd, u8 user, const char* path, s32 errHandling, const FSAsyncParams* asyncParams);

EXPORT_DECL(s32, SAVEOpenFile, void* pClient, void* pCmd, u8 user, const char* path, const char* mode, s32* fd, s32 errHandling);
EXPORT_DECL(s32, SAVEOpenFileAsync, void* pClient, void* pCmd, u8 user, const char* path, const char* mode, s32* fd, s32 errHandling, const FSAsyncParams* asyncParams);

EXPORT_DECL(s32, SAVEOpenDir, void* pClient, void* pCmd, u8 user, const char* path, s32* dh, s32 errHandling);
EXPORT_DECL(s32, SAVEOpenDirAsync, void* pClient, void* pCmd, u8 user, const char* path, s32* dh, s32 errHandling, const FSAsyncParams* asyncParams);
EXPORT_DECL(s32, SAVEMakeDir, void* pClient, void* pCmd, u8 user, const char* path, s32 errHandling);
EXPORT_DECL(s32, SAVEMakeDirAsync, void* pClient, void* pCmd, u8 user, const char* path, s32 errHandling, const FSAsyncParams* asyncParams);

EXPORT_DECL(s32, SAVERemove, void* pClient, void* pCmd, u8 user, const char* path, s32 errHandling);
EXPORT_DECL(s32, SAVERemoveAsync, void* pClient, void* pCmd, u8 user, const char* path, s32 errHandling, const FSAsyncParams* asyncParams);

EXPORT_DECL(s32, SAVEGetStat, void* pClient, void* pCmd, u8 user, const char* path, FSStat* stats, s32 errHandling);
EXPORT_DECL(s32, SAVEGetStatAsync, void* pClient, void* pCmd, u8 user, const char* path, FSStat* stats, s32 errHandling, const FSAsyncParams* asyncParams);

void InitAcquireSave(void) {
    if(coreinit_handle == 0) {
        InitAcquireOS();
    };
    OSDynLoad_Acquire("nn_save.rpl", &nn_save_handle);
}

void InitSaveFunctionPointers(void) {
    u32 *funcPointer = 0;
    InitAcquireSave();

    OS_FIND_EXPORT(nn_save_handle, SAVEInit);
    OS_FIND_EXPORT(nn_save_handle, SAVEShutdown);

    OS_FIND_EXPORT(nn_save_handle, SAVEInitSaveDir);
    OS_FIND_EXPORT(nn_save_handle, SAVEChangeDir);
    OS_FIND_EXPORT(nn_save_handle, SAVEChangeDirAsync);

    OS_FIND_EXPORT(nn_save_handle, SAVEOpenFile);
    OS_FIND_EXPORT(nn_save_handle, SAVEOpenFileAsync);

    OS_FIND_EXPORT(nn_save_handle, SAVEOpenDir);
    OS_FIND_EXPORT(nn_save_handle, SAVEOpenDirAsync);
    OS_FIND_EXPORT(nn_save_handle, SAVEMakeDir);
    OS_FIND_EXPORT(nn_save_handle, SAVEMakeDirAsync);

    OS_FIND_EXPORT(nn_save_handle, SAVERemove);
    OS_FIND_EXPORT(nn_save_handle, SAVERemoveAsync);

    OS_FIND_EXPORT(nn_save_handle, SAVEGetStat);
    OS_FIND_EXPORT(nn_save_handle, SAVEGetStatAsync);
}
