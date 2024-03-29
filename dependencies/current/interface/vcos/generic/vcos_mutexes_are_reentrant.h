/*
Copyright (c) 2012, Broadcom Europe Ltd
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the copyright holder nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/*=============================================================================
VideoCore OS Abstraction Layer - reentrant mutexes mapped directly to regular ones
=============================================================================*/

#ifndef VCOS_GENERIC_REENTRANT_MUTEX_H
#define VCOS_GENERIC_REENTRANT_MUTEX_H

#ifdef __cplusplus
extern "C" {
#endif

#include "interface/vcos/vcos_types.h"
#include "interface/vcos/vcos_mutex.h"

/**
 * \file
 *
 * Reentrant Mutexes directly using the native re-entrant mutex.
 *
 */

typedef VCOS_MUTEX_T VCOS_REENTRANT_MUTEX_T;

/* Inline forwarding functions */

#if defined(VCOS_INLINE_BODIES)

VCOS_INLINE_IMPL
VCOS_STATUS_T vcos_reentrant_mutex_create(VCOS_REENTRANT_MUTEX_T *m, const char *name)
{
    return vcos_mutex_create(m, name);
}

VCOS_INLINE_IMPL
void vcos_reentrant_mutex_delete(VCOS_REENTRANT_MUTEX_T *m)
{
    vcos_mutex_delete(m);
}

VCOS_INLINE_IMPL
void vcos_reentrant_mutex_lock(VCOS_REENTRANT_MUTEX_T *m)
{
    vcos_mutex_lock(m);
}

VCOS_INLINE_IMPL
void vcos_reentrant_mutex_unlock(VCOS_REENTRANT_MUTEX_T *m)
{
    vcos_mutex_unlock(m);
}

VCOS_INLINE_IMPL
int vcos_reentrant_mutex_is_locked(VCOS_REENTRANT_MUTEX_T *m)
{
    return vcos_mutex_is_locked(m);
}

#endif

#ifdef __cplusplus
}
#endif
#endif



