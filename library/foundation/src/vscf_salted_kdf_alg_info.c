//  @license
// --------------------------------------------------------------------------
//  Copyright (C) 2015-2019 Virgil Security, Inc.
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
//  This module contains 'salted kdf alg info' implementation.
// --------------------------------------------------------------------------


//  @warning
// --------------------------------------------------------------------------
//  This file is partially generated.
//  Generated blocks are enclosed between tags [@<tag>, @end].
//  User's code can be added between tags [@end, @<tag>].
// --------------------------------------------------------------------------

#include "vscf_salted_kdf_alg_info.h"
#include "vscf_assert.h"
#include "vscf_memory.h"
#include "vscf_salted_kdf_alg_info_defs.h"
#include "vscf_salted_kdf_alg_info_internal.h"

// clang-format on
//  @end


//  @generated
// --------------------------------------------------------------------------
// clang-format off
//  Generated section start.
// --------------------------------------------------------------------------


// --------------------------------------------------------------------------
//  Generated section end.
// clang-format on
// --------------------------------------------------------------------------
//  @end


//
//  Provides initialization of the implementation specific context.
//  Note, this method is called automatically when method vscf_salted_kdf_alg_info_init() is called.
//  Note, that context is already zeroed.
//
VSCF_PRIVATE void
vscf_salted_kdf_alg_info_init_ctx(vscf_salted_kdf_alg_info_t *salted_kdf_alg_info) {

    VSCF_ASSERT_PTR(salted_kdf_alg_info);

    salted_kdf_alg_info->alg_id = vscf_alg_id_NONE;
}

//
//  Release resources of the implementation specific context.
//  Note, this method is called automatically once when class is completely cleaning up.
//  Note, that context will be zeroed automatically next this method.
//
VSCF_PRIVATE void
vscf_salted_kdf_alg_info_cleanup_ctx(vscf_salted_kdf_alg_info_t *salted_kdf_alg_info) {

    VSCF_ASSERT_PTR(salted_kdf_alg_info);

    salted_kdf_alg_info->alg_id = vscf_alg_id_NONE;
    vscf_impl_destroy(&salted_kdf_alg_info->hash_alg_info);
    vsc_buffer_destroy(&salted_kdf_alg_info->salt);
}

//
//  Create algorithm info with identificator, HASH algorithm info,
//  salt and iteration count.
//
VSCF_PUBLIC vscf_salted_kdf_alg_info_t *
vscf_salted_kdf_alg_info_new_with_members(
        vscf_alg_id_t alg_id, vscf_impl_t **hash_alg_info_ref, vsc_data_t salt, size_t iteration_count) {

    VSCF_ASSERT(alg_id != vscf_alg_id_NONE);
    VSCF_ASSERT_PTR(hash_alg_info_ref);
    VSCF_ASSERT_PTR(*hash_alg_info_ref);
    VSCF_ASSERT(vsc_data_is_valid(salt));

    vscf_salted_kdf_alg_info_t *salted_kdf_alg_info = vscf_salted_kdf_alg_info_new();

    salted_kdf_alg_info->alg_id = alg_id;
    salted_kdf_alg_info->hash_alg_info = *hash_alg_info_ref;
    *hash_alg_info_ref = NULL;
    salted_kdf_alg_info->salt = vsc_buffer_new_with_data(salt);
    salted_kdf_alg_info->iteration_count = iteration_count;

    return salted_kdf_alg_info;
}

//
//  Return hash algorithm information.
//
VSCF_PUBLIC const vscf_impl_t *
vscf_salted_kdf_alg_info_hash_alg_info(const vscf_salted_kdf_alg_info_t *salted_kdf_alg_info) {

    VSCF_ASSERT_PTR(salted_kdf_alg_info);
    VSCF_ASSERT_PTR(salted_kdf_alg_info->hash_alg_info);

    return salted_kdf_alg_info->hash_alg_info;
}

//
//  Return KDF salt.
//
VSCF_PUBLIC vsc_data_t
vscf_salted_kdf_alg_info_salt(const vscf_salted_kdf_alg_info_t *salted_kdf_alg_info) {

    VSCF_ASSERT_PTR(salted_kdf_alg_info);
    VSCF_ASSERT_PTR(salted_kdf_alg_info->salt);

    return vsc_buffer_data(salted_kdf_alg_info->salt);
}

//
//  Return KDF iteration count.
//  Note, can be 0 if KDF does not need the iteration count.
//
VSCF_PUBLIC size_t
vscf_salted_kdf_alg_info_iteration_count(const vscf_salted_kdf_alg_info_t *salted_kdf_alg_info) {

    VSCF_ASSERT_PTR(salted_kdf_alg_info);

    return salted_kdf_alg_info->iteration_count;
}

//
//  Provide algorithm identificator.
//
VSCF_PUBLIC vscf_alg_id_t
vscf_salted_kdf_alg_info_alg_id(const vscf_salted_kdf_alg_info_t *salted_kdf_alg_info) {

    VSCF_ASSERT_PTR(salted_kdf_alg_info);

    return salted_kdf_alg_info->alg_id;
}
