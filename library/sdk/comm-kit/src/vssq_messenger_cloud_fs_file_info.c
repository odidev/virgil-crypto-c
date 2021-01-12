//  @license
// --------------------------------------------------------------------------
//  Copyright (C) 2015-2020 Virgil Security, Inc.
//
//  All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions are
//  met:
//
//      (1) Redistributions of source code must retain the above copyright
//      notice, this list of conditions and the following disclaimer.
//
//      (2) Redistributions in binary form must reproduce the above copyright
//      notice, this list of conditions and the following disclaimer in
//      the documentation and/or other materials provided with the
//      distribution.
//
//      (3) Neither the name of the copyright holder nor the names of its
//      contributors may be used to endorse or promote products derived from
//      this software without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE AUTHOR ''AS IS'' AND ANY EXPRESS OR
//  IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
//  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
//  DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
//  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
//  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
//  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
//  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
//  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
//  IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
//  POSSIBILITY OF SUCH DAMAGE.
//
//  Lead Maintainer: Virgil Security Inc. <support@virgilsecurity.com>
// --------------------------------------------------------------------------
// clang-format off


//  @description
// --------------------------------------------------------------------------
//  Value object that handles public available file info.
// --------------------------------------------------------------------------


//  @warning
// --------------------------------------------------------------------------
//  This file is partially generated.
//  Generated blocks are enclosed between tags [@<tag>, @end].
//  User's code can be added between tags [@end, @<tag>].
// --------------------------------------------------------------------------

#include "vssq_messenger_cloud_fs_file_info.h"
#include "vssq_memory.h"
#include "vssq_assert.h"
#include "vssq_messenger_cloud_fs_file_info_defs.h"

// clang-format on
//  @end


//  @generated
// --------------------------------------------------------------------------
// clang-format off
//  Generated section start.
// --------------------------------------------------------------------------

//
//  Perform context specific initialization.
//  Note, this method is called automatically when method vssq_messenger_cloud_fs_file_info_init() is called.
//  Note, that context is already zeroed.
//
static void
vssq_messenger_cloud_fs_file_info_init_ctx(vssq_messenger_cloud_fs_file_info_t *self);

//
//  Release all inner resources.
//  Note, this method is called automatically once when class is completely cleaning up.
//  Note, that context will be zeroed automatically next this method.
//
static void
vssq_messenger_cloud_fs_file_info_cleanup_ctx(vssq_messenger_cloud_fs_file_info_t *self);

//
//  Create fully defined object.
//
static void
vssq_messenger_cloud_fs_file_info_init_ctx_with(vssq_messenger_cloud_fs_file_info_t *self, vsc_str_t id, vsc_str_t name,
        vsc_str_t type, size_t size, size_t created_at, size_t updated_at);

//
//  Return size of 'vssq_messenger_cloud_fs_file_info_t'.
//
VSSQ_PUBLIC size_t
vssq_messenger_cloud_fs_file_info_ctx_size(void) {

    return sizeof(vssq_messenger_cloud_fs_file_info_t);
}

//
//  Perform initialization of pre-allocated context.
//
VSSQ_PUBLIC void
vssq_messenger_cloud_fs_file_info_init(vssq_messenger_cloud_fs_file_info_t *self) {

    VSSQ_ASSERT_PTR(self);

    vssq_zeroize(self, sizeof(vssq_messenger_cloud_fs_file_info_t));

    self->refcnt = 1;

    vssq_messenger_cloud_fs_file_info_init_ctx(self);
}

//
//  Release all inner resources including class dependencies.
//
VSSQ_PUBLIC void
vssq_messenger_cloud_fs_file_info_cleanup(vssq_messenger_cloud_fs_file_info_t *self) {

    if (self == NULL) {
        return;
    }

    vssq_messenger_cloud_fs_file_info_cleanup_ctx(self);

    vssq_zeroize(self, sizeof(vssq_messenger_cloud_fs_file_info_t));
}

//
//  Allocate context and perform it's initialization.
//
VSSQ_PUBLIC vssq_messenger_cloud_fs_file_info_t *
vssq_messenger_cloud_fs_file_info_new(void) {

    vssq_messenger_cloud_fs_file_info_t *self = (vssq_messenger_cloud_fs_file_info_t *) vssq_alloc(sizeof (vssq_messenger_cloud_fs_file_info_t));
    VSSQ_ASSERT_ALLOC(self);

    vssq_messenger_cloud_fs_file_info_init(self);

    self->self_dealloc_cb = vssq_dealloc;

    return self;
}

//
//  Perform initialization of pre-allocated context.
//  Create fully defined object.
//
VSSQ_PUBLIC void
vssq_messenger_cloud_fs_file_info_init_with(vssq_messenger_cloud_fs_file_info_t *self, vsc_str_t id, vsc_str_t name,
        vsc_str_t type, size_t size, size_t created_at, size_t updated_at) {

    VSSQ_ASSERT_PTR(self);

    vssq_zeroize(self, sizeof(vssq_messenger_cloud_fs_file_info_t));

    self->refcnt = 1;

    vssq_messenger_cloud_fs_file_info_init_ctx_with(self, id, name, type, size, created_at, updated_at);
}

//
//  Allocate class context and perform it's initialization.
//  Create fully defined object.
//
VSSQ_PUBLIC vssq_messenger_cloud_fs_file_info_t *
vssq_messenger_cloud_fs_file_info_new_with(vsc_str_t id, vsc_str_t name, vsc_str_t type, size_t size, size_t created_at,
        size_t updated_at) {

    vssq_messenger_cloud_fs_file_info_t *self = (vssq_messenger_cloud_fs_file_info_t *) vssq_alloc(sizeof (vssq_messenger_cloud_fs_file_info_t));
    VSSQ_ASSERT_ALLOC(self);

    vssq_messenger_cloud_fs_file_info_init_with(self, id, name, type, size, created_at, updated_at);

    self->self_dealloc_cb = vssq_dealloc;

    return self;
}

//
//  Release all inner resources and deallocate context if needed.
//  It is safe to call this method even if the context was statically allocated.
//
VSSQ_PUBLIC void
vssq_messenger_cloud_fs_file_info_delete(const vssq_messenger_cloud_fs_file_info_t *self) {

    vssq_messenger_cloud_fs_file_info_t *local_self = (vssq_messenger_cloud_fs_file_info_t *)self;

    if (local_self == NULL) {
        return;
    }

    size_t old_counter = local_self->refcnt;
    VSSQ_ASSERT(old_counter != 0);
    size_t new_counter = old_counter - 1;

    #if defined(VSSQ_ATOMIC_COMPARE_EXCHANGE_WEAK)
    //  CAS loop
    while (!VSSQ_ATOMIC_COMPARE_EXCHANGE_WEAK(&local_self->refcnt, &old_counter, new_counter)) {
        old_counter = local_self->refcnt;
        VSSQ_ASSERT(old_counter != 0);
        new_counter = old_counter - 1;
    }
    #else
    local_self->refcnt = new_counter;
    #endif

    if (new_counter > 0) {
        return;
    }

    vssq_dealloc_fn self_dealloc_cb = local_self->self_dealloc_cb;

    vssq_messenger_cloud_fs_file_info_cleanup(local_self);

    if (self_dealloc_cb != NULL) {
        self_dealloc_cb(local_self);
    }
}

//
//  Delete given context and nullifies reference.
//  This is a reverse action of the function 'vssq_messenger_cloud_fs_file_info_new ()'.
//
VSSQ_PUBLIC void
vssq_messenger_cloud_fs_file_info_destroy(vssq_messenger_cloud_fs_file_info_t **self_ref) {

    VSSQ_ASSERT_PTR(self_ref);

    vssq_messenger_cloud_fs_file_info_t *self = *self_ref;
    *self_ref = NULL;

    vssq_messenger_cloud_fs_file_info_delete(self);
}

//
//  Copy given class context by increasing reference counter.
//
VSSQ_PUBLIC vssq_messenger_cloud_fs_file_info_t *
vssq_messenger_cloud_fs_file_info_shallow_copy(vssq_messenger_cloud_fs_file_info_t *self) {

    VSSQ_ASSERT_PTR(self);

    #if defined(VSSQ_ATOMIC_COMPARE_EXCHANGE_WEAK)
    //  CAS loop
    size_t old_counter;
    size_t new_counter;
    do {
        old_counter = self->refcnt;
        new_counter = old_counter + 1;
    } while (!VSSQ_ATOMIC_COMPARE_EXCHANGE_WEAK(&self->refcnt, &old_counter, new_counter));
    #else
    ++self->refcnt;
    #endif

    return self;
}

//
//  Copy given class context by increasing reference counter.
//  Reference counter is internally synchronized, so constness is presumed.
//
VSSQ_PUBLIC const vssq_messenger_cloud_fs_file_info_t *
vssq_messenger_cloud_fs_file_info_shallow_copy_const(const vssq_messenger_cloud_fs_file_info_t *self) {

    return vssq_messenger_cloud_fs_file_info_shallow_copy((vssq_messenger_cloud_fs_file_info_t *)self);
}


// --------------------------------------------------------------------------
//  Generated section end.
// clang-format on
// --------------------------------------------------------------------------
//  @end


//
//  Perform context specific initialization.
//  Note, this method is called automatically when method vssq_messenger_cloud_fs_file_info_init() is called.
//  Note, that context is already zeroed.
//
static void
vssq_messenger_cloud_fs_file_info_init_ctx(vssq_messenger_cloud_fs_file_info_t *self) {

    VSSQ_ASSERT_PTR(self);

    VSSQ_ASSERT(0 && "The default constructor is forbidden.");
}

//
//  Release all inner resources.
//  Note, this method is called automatically once when class is completely cleaning up.
//  Note, that context will be zeroed automatically next this method.
//
static void
vssq_messenger_cloud_fs_file_info_cleanup_ctx(vssq_messenger_cloud_fs_file_info_t *self) {

    VSSQ_ASSERT_PTR(self);

    vsc_str_mutable_release(&self->id);
    vsc_str_mutable_release(&self->name);
    vsc_str_mutable_release(&self->type);
}

//
//  Create fully defined object.
//
static void
vssq_messenger_cloud_fs_file_info_init_ctx_with(vssq_messenger_cloud_fs_file_info_t *self, vsc_str_t id, vsc_str_t name,
        vsc_str_t type, size_t size, size_t created_at, size_t updated_at) {

    VSSQ_ASSERT_PTR(self);
    VSSQ_ASSERT(vsc_str_is_valid_and_non_empty(id));
    VSSQ_ASSERT(vsc_str_is_valid_and_non_empty(name));
    VSSQ_ASSERT(vsc_str_is_valid_and_non_empty(type));
    VSSQ_ASSERT(size > 0);
    VSSQ_ASSERT(created_at > 0);
    VSSQ_ASSERT(updated_at > 0);

    self->id = vsc_str_mutable_from_str(id);
    self->name = vsc_str_mutable_from_str(name);
    self->type = vsc_str_mutable_from_str(type);
    self->size = size;
    self->created_at = created_at;
    self->updated_at = updated_at;
}

//
//  Return folder id.
//
VSSQ_PUBLIC vsc_str_t
vssq_messenger_cloud_fs_file_info_id(const vssq_messenger_cloud_fs_file_info_t *self) {

    VSSQ_ASSERT_PTR(self);

    return vsc_str_mutable_as_str(self->id);
}

//
//  Return folder name.
//
VSSQ_PUBLIC vsc_str_t
vssq_messenger_cloud_fs_file_info_name(const vssq_messenger_cloud_fs_file_info_t *self) {

    VSSQ_ASSERT_PTR(self);

    return vsc_str_mutable_as_str(self->name);
}

//
//  Return folder type, aka "text/plain".
//
VSSQ_PUBLIC vsc_str_t
vssq_messenger_cloud_fs_file_info_type(const vssq_messenger_cloud_fs_file_info_t *self) {

    VSSQ_ASSERT_PTR(self);

    return vsc_str_mutable_as_str(self->type);
}

//
//  Return folder "size" timestamp.
//
VSSQ_PUBLIC size_t
vssq_messenger_cloud_fs_file_info_size(const vssq_messenger_cloud_fs_file_info_t *self) {

    VSSQ_ASSERT_PTR(self);

    return self->size;
}

//
//  Return folder "created at" timestamp.
//
VSSQ_PUBLIC size_t
vssq_messenger_cloud_fs_file_info_created_at(const vssq_messenger_cloud_fs_file_info_t *self) {

    VSSQ_ASSERT_PTR(self);

    return self->created_at;
}

//
//  Return folder "updated at" timestamp.
//
VSSQ_PUBLIC size_t
vssq_messenger_cloud_fs_file_info_updated_at(const vssq_messenger_cloud_fs_file_info_t *self) {

    VSSQ_ASSERT_PTR(self);

    return self->updated_at;
}