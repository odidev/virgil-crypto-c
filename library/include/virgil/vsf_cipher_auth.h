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


//  @warning
// --------------------------------------------------------------------------
//  This file is partially generated.
//  Generated blocks are enclosed between tags [@<tag>, @end].
//  User's code can be added between tags [@end, @<tag>].
// --------------------------------------------------------------------------


//  @description
// --------------------------------------------------------------------------
//  Mix-in interface that provides specific functionality to authenticated
//  encryption and decryption.
// --------------------------------------------------------------------------

#ifndef VSF_CIPHER_AUTH_H_INCLUDED
#define VSF_CIPHER_AUTH_H_INCLUDED

#include "vsf_library.h"
#include "vsf_impl.h"
//  @end


#ifdef __cplusplus
extern "C" {
#endif


//  @generated
// --------------------------------------------------------------------------
//  Generated section start.
// --------------------------------------------------------------------------

//
//  Contains API requirements of the interface 'cipher auth'.
//
typedef struct vsf_cipher_auth_api_t vsf_cipher_auth_api_t;

//
//  Setup additional data.
//  Must be called before encryption / decryption operation.
//
VSF_PUBLIC void
vsf_cipher_auth_set_data (vsf_impl_t* impl, const byte* data, size_t data_len);

//
//  Write authentication tag.
//  Must be called after encryption is finished.
//
VSF_PUBLIC void
vsf_cipher_auth_write_tag (vsf_impl_t* impl, byte* tag, size_t tag_len);

//
//  Validate authentication tag.
//  Must be called after decryption is finished.
//
VSF_PUBLIC void
vsf_cipher_auth_check_tag (vsf_impl_t* impl, const byte* tag, size_t tag_len);

//
//  Returns constant 'tag len'.
//
VSF_PUBLIC size_t
vsf_cipher_auth_tag_len (const vsf_cipher_auth_api_t* cipher_auth_api);

//
//  Return cipher auth API, or NULL if it is not implemented.
//
VSF_PUBLIC const vsf_cipher_auth_api_t*
vsf_cipher_auth_api (vsf_impl_t* impl);

//
//  Return size of 'vsf_cipher_auth_api_t' type.
//
VSF_PUBLIC size_t
vsf_cipher_auth_api_size (void);

//
//  Check if given object implements interface 'cipher auth'.
//
VSF_PUBLIC bool
vsf_cipher_auth_is_implemented (vsf_impl_t* impl);


// --------------------------------------------------------------------------
//  Generated section end.
// --------------------------------------------------------------------------
//  @end


#ifdef __cplusplus
}
#endif


//  @footer
#endif // VSF_CIPHER_AUTH_H_INCLUDED
//  @end