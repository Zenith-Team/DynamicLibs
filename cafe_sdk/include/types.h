#pragma once

typedef unsigned char       u8;
typedef unsigned short      u16;
typedef unsigned int        u32;
typedef unsigned long long  u64;

typedef signed char         s8;
typedef signed short        s16;
typedef signed int          s32;
typedef signed long long    s64;

typedef float               f32;
typedef double              f64;

typedef signed long         ssize_t;

typedef unsigned long       uintptr_t;
typedef signed long         intptr_t;

typedef wchar_t             char16;

typedef int                 BOOL;

static_assert(sizeof(u8) == 1, "u8 must be 1 byte");
static_assert(sizeof(u16) == 2, "u16 must be 2 bytes");
static_assert(sizeof(u32) == 4, "u32 must be 4 bytes");
static_assert(sizeof(u64) == 8, "u64 must be 8 bytes");

static_assert(sizeof(s8) == 1, "s8 must be 1 byte");
static_assert(sizeof(s16) == 2, "s16 must be 2 bytes");
static_assert(sizeof(s32) == 4, "s32 must be 4 bytes");
static_assert(sizeof(s64) == 8, "s64 must be 8 bytes");

static_assert(sizeof(f32) == 4, "f32 must be 4 bytes");
static_assert(sizeof(f64) == 8, "f64 must be 8 bytes");

static_assert(sizeof(ssize_t) == sizeof(void*), "ssize_t must be the same size as a pointer");
static_assert(sizeof(uintptr_t) == sizeof(void*), "uintptr_t must be the same size as a pointer");
static_assert(sizeof(intptr_t) == sizeof(void*), "intptr_t must be the same size as a pointer");

static_assert(sizeof(char16) == 2, "char16 must be 2 bytes");
