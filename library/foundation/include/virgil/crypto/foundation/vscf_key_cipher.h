//  @license
// --------------------------------------------------------------------------
//  Copyright (C) 2015-2021 Virgil Security, Inc.
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


//  @warning
// --------------------------------------------------------------------------
//  This file is partially generated.
//  Generated blocks are enclosed between tags [@<tag>, @end].
//  User's code can be added between tags [@end, @<tag>].
// --------------------------------------------------------------------------


//  @description
// --------------------------------------------------------------------------
//  Provide data encryption and decryption interface with asymmetric keys.
// --------------------------------------------------------------------------

#ifndef VSCF_KEY_CIPHER_H_INCLUDED
#define VSCF_KEY_CIPHER_H_INCLUDED

#include "vscf_library.h"
#include "vscf_impl.h"
#include "vscf_key_alg.h"
#include "vscf_status.h"
#include "vscf_api.h"

#if !VSCF_IMPORT_PROJECT_COMMON_FROM_FRAMEWORK
#   include <virgil/crypto/common/vsc_data.h>
#   include <virgil/crypto/common/vsc_buffer.h>
#endif

#if VSCF_IMPORT_PROJECT_COMMON_FROM_FRAMEWORK
#   include <VSCCommon/vsc_data.h>
#   include <VSCCommon/vsc_buffer.h>
#endif

// clang-format on
//  @end


#ifdef __cplusplus
extern "C" {
#endif


//  @generated
// --------------------------------------------------------------------------
// clang-format off
//  Generated section start.
// --------------------------------------------------------------------------

//
//  Contains API requirements of the interface 'key cipher'.
//
typedef struct vscf_key_cipher_api_t vscf_key_cipher_api_t;

//
//  Check if algorithm can encrypt data with a given key.
//
VSCF_PUBLIC bool
vscf_key_cipher_can_encrypt(const vscf_impl_t *impl, const vscf_impl_t *public_key, size_t data_len);

//
//  Calculate required buffer length to hold the encrypted data.
//
VSCF_PUBLIC size_t
vscf_key_cipher_encrypted_len(const vscf_impl_t *impl, const vscf_impl_t *public_key, size_t data_len);

//
//  Encrypt data with a given public key.
//
VSCF_PUBLIC vscf_status_t
vscf_key_cipher_encrypt(const vscf_impl_t *impl, const vscf_impl_t *public_key, vsc_data_t data,
        vsc_buffer_t *out) VSCF_NODISCARD;

//
//  Check if algorithm can decrypt data with a given key.
//  However, success result of decryption is not guaranteed.
//
VSCF_PUBLIC bool
vscf_key_cipher_can_decrypt(const vscf_impl_t *impl, const vscf_impl_t *private_key, size_t data_len);

//
//  Calculate required buffer length to hold the decrypted data.
//
VSCF_PUBLIC size_t
vscf_key_cipher_decrypted_len(const vscf_impl_t *impl, const vscf_impl_t *private_key, size_t data_len);

//
//  Decrypt given data.
//
VSCF_PUBLIC vscf_status_t
vscf_key_cipher_decrypt(const vscf_impl_t *impl, const vscf_impl_t *private_key, vsc_data_t data,
        vsc_buffer_t *out) VSCF_NODISCARD;

//
//  Return key cipher API, or NULL if it is not implemented.
//
VSCF_PUBLIC const vscf_key_cipher_api_t *
vscf_key_cipher_api(const vscf_impl_t *impl);

//
//  Return key alg API.
//
VSCF_PUBLIC const vscf_key_alg_api_t *
vscf_key_cipher_key_alg_api(const vscf_key_cipher_api_t *key_cipher_api);

//
//  Check if given object implements interface 'key cipher'.
//
VSCF_PUBLIC bool
vscf_key_cipher_is_implemented(const vscf_impl_t *impl);

//
//  Returns interface unique identifier.
//
VSCF_PUBLIC vscf_api_tag_t
vscf_key_cipher_api_tag(const vscf_key_cipher_api_t *key_cipher_api);


// --------------------------------------------------------------------------
//  Generated section end.
// clang-format on
// --------------------------------------------------------------------------
//  @end


#ifdef __cplusplus
}
#endif


//  @footer
#endif // VSCF_KEY_CIPHER_H_INCLUDED
//  @end
