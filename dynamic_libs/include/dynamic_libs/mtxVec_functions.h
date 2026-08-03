#ifndef __MTXVEC_FUNCTIONS_H_
#define __MTXVEC_FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

#include "os_types.h"

typedef f32 Mtx[3][4];
typedef f32 Mtx44[4][4];

void ASM_MTXConcat(Mtx a, Mtx b, Mtx o);
void ASM_MTXCopy(Mtx n, Mtx o);
void ASM_MTXIdentity(Mtx o);
u32  ASM_MTXInverse(Mtx n, Mtx o);
void ASM_MTXScale(Mtx o, f32 x, f32 y, f32 z);
void ASM_MTXScaleApply(Mtx a, Mtx b, f32 x, f32 y, f32 z);
void ASM_MTXTrans(Mtx o, f32 x, f32 y, f32 z);
void ASM_MTXTransApply(Mtx n, Mtx o, f32 x, f32 y, f32 z);
void ASM_MTXTranspose(Mtx n, Mtx o);
void ASM_MTX44Concat(Mtx44 a, Mtx44 b, Mtx44 o);
void ASM_MTX44Copy(Mtx44 n, Mtx44 o);
void ASM_MTX44Identity(Mtx44 o);

typedef f32 Vec[3];

void ASM_VECAdd(const Vec* a, const Vec* b, Vec* o);
void ASM_VECCrossProduct(const Vec* a, const Vec* b, Vec* o);
f32  ASM_VECDistance(const Vec* a, const Vec* b);
f32  ASM_VECDotProduct(const Vec* a, const Vec* b);
f32  ASM_VECMag(const Vec* v);
void ASM_VECScale(const Vec* v, Vec* o, f32 t);
f32  ASM_VECSquareDistance(const Vec* a, const Vec* b);
f32  ASM_VECSquareMag(const Vec* v);
void ASM_VECSubtract(const Vec* a, const Vec* b, Vec* o);

void ASM_MTXMultVec(Mtx a, const Vec* b, Vec* o);
void ASM_MTXMultVecSR(Mtx a, const Vec* b, Vec* o);

typedef struct {
	f32 x, y, z, w;
} Quaternion;

void C_QUATSlerp(const Quaternion* p, const Quaternion* q, Quaternion* r, f32 t);

typedef struct _Mat34
{
    union
    {
        struct 
        {
            f32 _00, _01, _02, _03;
            f32 _10, _11, _12, _13;
            f32 _20, _21, _22, _23;
        };
        f32 m[3][4];
        f32 a[12];
        Mtx mtx;
    };
} Mat34;

typedef struct _Mat44
{
    union
    {
        struct 
        {
            f32 _00, _01, _02, _03;
            f32 _10, _11, _12, _13;
            f32 _20, _21, _22, _23;
            f32 _30, _31, _32, _33;
        };
        f32 m[4][4];
        f32 a[16];
        Mtx44 mtx;
    };
} Mat44;

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MTXVEC_FUNCTIONS_H
