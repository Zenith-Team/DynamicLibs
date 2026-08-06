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
#ifndef __NN_SAVE_FUNCTIONS_H_
#define __NN_SAVE_FUNCTIONS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "os_types.h"
#include "fs_defs.h"

typedef s32 SAVEStatus;

#define SAVE_STATUS_OK               FS_STATUS_OK
#define SAVE_STATUS_NOT_FOUND        FS_STATUS_NOT_FOUND
#define SAVE_STATUS_DEVICE_FULL      FS_STATUS_STORAGE_FULL
#define SAVE_STATUS_STORAGE_FULL     FS_STATUS_STORAGE_FULL
#define SAVE_STATUS_FATAL_ERROR      FS_STATUS_FATAL_ERROR

#define SAVE_STATUS_BUFFER_TOO_SHORT (FS_STATUS_FATAL_ERROR - 1)

extern u32 nn_save_handle;

extern s32  (* SAVEInit)(void);
extern void (* SAVEShutdown)(void);

extern s32  (* SAVEInitSaveDir)(u8 user);
extern s32  (* SAVEChangeDir)(void* pClient, void* pCmd, u8 user, const char* path, s32 errHandling);
extern s32  (* SAVEChangeDirAsync)(void* pClient, void* pCmd, u8 user, const char* path, s32 errHandling, const FSAsyncParams* asyncParams);

extern s32  (* SAVEOpenFile)(void* pClient, void* pCmd, u8 user, const char* path, const char* mode, s32* fd, s32 errHandling);
extern s32  (* SAVEOpenFileAsync)(void* pClient, void* pCmd, u8 user, const char* path, const char* mode, s32* fd, s32 errHandling, const FSAsyncParams* asyncParams);

extern s32  (* SAVEOpenDir)(void* pClient, void* pCmd, u8 user, const char* path, s32* dh, s32 errHandling);
extern s32  (* SAVEOpenDirAsync)(void* pClient, void* pCmd, u8 user, const char* path, s32* dh, s32 errHandling, const FSAsyncParams* asyncParams);
extern s32  (* SAVEMakeDir)(void* pClient, void* pCmd, u8 user, const char* path, s32 errHandling);
extern s32  (* SAVEMakeDirAsync)(void* pClient, void* pCmd, u8 user, const char* path, s32 errHandling, const FSAsyncParams* asyncParams);

extern s32  (* SAVERemove)(void* pClient, void* pCmd, u8 user, const char* path, s32 errHandling);
extern s32  (* SAVERemoveAsync)(void* pClient, void* pCmd, u8 user, const char* path, s32 errHandling, const FSAsyncParams* asyncParams);

extern s32  (* SAVEGetStat)(void* pClient, void* pCmd, u8 user, const char* path, FSStat* stats, s32 errHandling);
extern s32  (* SAVEGetStatAsync)(void* pClient, void* pCmd, u8 user, const char* path, FSStat* stats, s32 errHandling, const FSAsyncParams* asyncParams);

void InitSaveFunctionPointers(void);
void InitAcquireSave(void);

#ifdef __cplusplus
}
#endif

#endif // __NN_SAVE_FUNCTIONS_H_
