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

#include "interface/vcos/vcos.h"
#include "interface/vcos/vcos_reentrant_mutex.h"

VCOS_STATUS_T vcos_generic_reentrant_mutex_create(VCOS_REENTRANT_MUTEX_T *m, const char *name)
{
    m->count = 0;
    m->owner = 0;
    return vcos_mutex_create(&m->mutex, name);
}

void vcos_generic_reentrant_mutex_delete(VCOS_REENTRANT_MUTEX_T *m)
{
    vcos_assert(m->count == 0);
    vcos_mutex_delete(&m->mutex);
}

void vcos_generic_reentrant_mutex_lock(VCOS_REENTRANT_MUTEX_T *m)
{
    VCOS_THREAD_T *thread = vcos_thread_current();
    vcos_assert(m);

    vcos_assert(thread != 0);

    if (m->owner != thread)
    {
        vcos_mutex_lock(&m->mutex);
        m->owner = thread;
        vcos_assert(m->count == 0);
    }
    m->count++;
}

void vcos_generic_reentrant_mutex_unlock(VCOS_REENTRANT_MUTEX_T *m)
{
    vcos_assert(m->count != 0);
    vcos_assert(m->owner == vcos_thread_current());
    m->count--;
    if (m->count == 0)
    {
        m->owner = 0;
        vcos_mutex_unlock(&m->mutex);
    }
}






