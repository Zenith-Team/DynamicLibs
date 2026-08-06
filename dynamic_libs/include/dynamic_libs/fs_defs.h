#ifndef FS_DEFS_H
#define FS_DEFS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "os_types.h"

/* FS defines and types */
#define FS_MAX_LOCALPATH_SIZE           511
#define FS_MAX_MOUNTPATH_SIZE           128
#define FS_MAX_FULLPATH_SIZE            (FS_MAX_LOCALPATH_SIZE + FS_MAX_MOUNTPATH_SIZE)
#define FS_MAX_ARGPATH_SIZE             FS_MAX_FULLPATH_SIZE

#define FS_STATUS_OK                    0
#define FS_STATUS_CANCELED              -1
#define FS_STATUS_END                   -2
#define FS_STATUS_MAX                   -3
#define FS_STATUS_ALREADY_OPEN          -4
#define FS_STATUS_EXISTS                -5
#define FS_STATUS_NOT_FOUND             -6
#define FS_STATUS_NOT_FILE              -7
#define FS_STATUS_NOT_DIR               -8
#define FS_STATUS_ACCESS_ERROR          -9
#define FS_STATUS_PERMISSION_ERROR      -10
#define FS_STATUS_FILE_TOO_BIG          -11
#define FS_STATUS_STORAGE_FULL          -12
#define FS_STATUS_JOURNAL_FULL          -13
#define FS_STATUS_UNSUPPORTED_CMD       -14
#define FS_STATUS_MEDIA_NOT_READY       -15
#define FS_STATUS_INVALID_MEDIA         -16
#define FS_STATUS_MEDIA_ERROR           -17
#define FS_STATUS_DATA_CORRUPTED        -18
#define FS_STATUS_WRITE_PROTECTED       -19

#define FS_STATUS_FATAL_ERROR           -0x400

#define FS_STATUS_CANCELLED             FS_STATUS_CANCELED

#define FS_RET_NO_ERROR                 0x0000
#define FS_RET_MAX                      0x0001
#define FS_RET_ALREADY_OPEN             0x0002
#define FS_RET_EXISTS                   0x0004
#define FS_RET_NOT_FOUND                0x0008
#define FS_RET_NOT_FILE                 0x0010
#define FS_RET_NOT_DIR                  0x0020
#define FS_RET_ACCESS_ERROR             0x0040
#define FS_RET_PERMISSION_ERROR         0x0080
#define FS_RET_FILE_TOO_BIG             0x0100
#define FS_RET_STORAGE_FULL             0x0200
#define FS_RET_UNSUPPORTED_CMD          0x0400
#define FS_RET_JOURNAL_FULL             0x0800
#define FS_RET_ALL_ERROR                (u32)(-1)

#define FS_IO_BUFFER_ALIGN              64

#define FS_STAT_FLAG_IS_DIRECTORY       0x80000000

/* max length of file/dir name */
#define FS_MAX_ENTNAME_SIZE             256

#define FS_SOURCETYPE_EXTERNAL          0
#define FS_SOURCETYPE_HFIO              1

#define FS_MOUNT_SOURCE_SIZE            0x300
#define FS_CLIENT_SIZE                  0x1700
#define FS_CMD_BLOCK_SIZE               0xA80

typedef struct FSClient_ {
    u8 buffer[FS_CLIENT_SIZE];
} FSClient;

typedef struct FSCmdBlock_ {
    u8 buffer[FS_CMD_BLOCK_SIZE];
} FSCmdBlock;

typedef struct {
    u32 flag;
    u32 permission;
    u32 owner_id;
    u32 group_id;
    u32 size;
    u32 alloc_size;
    u64 quota_size;
    u32 ent_id;
    u64 ctime;
    u64 mtime;
    u8 attributes[48];
} __attribute__((packed)) FSStat;

typedef struct {
    FSStat      stat;
    char        name[FS_MAX_ENTNAME_SIZE];
} FSDirEntry;

typedef void (*FSAsyncCallback)(FSClient * pClient, FSCmdBlock * pCmd, s32 result, void *context);
typedef struct {
    FSAsyncCallback userCallback;
    void            *userContext;
    OSMessageQueue  *ioMsgQueue;
} FSAsyncParams;

typedef struct {
    void*               data; // pointer to a FSAsyncResult;
    u32                 unkwn1;
    u32                 unkwn2;
    u32                 unkwn3; // always 0x08
} __attribute__((packed)) FSMessage;

typedef struct FSAsyncResult_ {
    FSAsyncParams       userParams;
    FSMessage           ioMsg;

    FSClient *          client;
    FSCmdBlock *        block;
    u32                 result;
} FSAsyncResult;

typedef enum {
} FSVolumeState;

typedef void (*FSStateChangeCallback)(FSClient *, FSVolumeState, void *);
typedef struct {
    FSStateChangeCallback   userCallback;
    void                   *userContext;
    OSMessageQueue         *ioMsgQueue;
} FSStateChangeParams;

typedef s32 FSFileHandle;
typedef s32 FSDirHandle;
typedef s32 FSStatus;
typedef u32 FSRetFlag;
typedef u32 FSFilePosition;
typedef u64 FSBSize;

typedef FSBSize FSFreeSpaceSize;

#ifdef __cplusplus
}
#endif

#endif  /* FS_DEFS_H */

