//  @license
// --------------------------------------------------------------------------
//  Copyright (C) 2015-2018 Virgil Security Inc.
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


//  @description
// --------------------------------------------------------------------------
//  Provides interface to the key derivation function (KDF) algorithms.
// --------------------------------------------------------------------------


//  @warning
// --------------------------------------------------------------------------
//  This file is partially generated.
//  Generated blocks are enclosed between tags [@<tag>, @end].
//  User's code can be added between tags [@end, @<tag>].
// --------------------------------------------------------------------------

#include "vsf_kdf.h"
#include "vsf_assert.h"
#include "vsf_kdf_api.h"
//  @end


//  @generated
// --------------------------------------------------------------------------
//  Generated section start.
// --------------------------------------------------------------------------

//
//  Calculate hash over given data.
//
VSF_PUBLIC void
vsf_kdf_derive (const vsf_kdf_api_t* kdf_api, const byte* data, size_t data_len, byte* key,
        size_t key_len) {

    VSF_ASSERT_PTR (kdf_api);

    VSF_ASSERT_PTR (kdf_api->derive_cb);
    kdf_api->derive_cb (data, data_len, key, key_len);
}

//
//  Return kdf API, or NULL if it is not implemented.
//
VSF_PUBLIC const vsf_kdf_api_t*
vsf_kdf_api (vsf_impl_t* impl) {

    VSF_ASSERT_PTR (impl);

    const vsf_api_t *api = vsf_impl_api (impl, vsf_api_tag_KDF);
    return (const vsf_kdf_api_t *) api;
}

//
//  Return size of 'vsf_kdf_api_t' type.
//
VSF_PUBLIC size_t
vsf_kdf_api_size (void) {

    return sizeof(vsf_kdf_api_t);
}

//
//  Check if given object implements interface 'kdf'.
//
VSF_PUBLIC bool
vsf_kdf_is_implemented (vsf_impl_t* impl) {

    VSF_ASSERT_PTR (impl);

    return vsf_impl_api (impl, vsf_api_tag_KDF) != NULL;
}


// --------------------------------------------------------------------------
//  Generated section end.
// --------------------------------------------------------------------------
//  @end
