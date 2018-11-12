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
// clang-format off


//  @warning
// --------------------------------------------------------------------------
//  This file is partially generated.
//  Generated blocks are enclosed between tags [@<tag>, @end].
//  User's code can be added between tags [@end, @<tag>].
// --------------------------------------------------------------------------


//  @description
// --------------------------------------------------------------------------
//  Provide interface for exporting private key to the binary format.
//  Binary format must be defined in the key specification.
//  For instance, RSA private key must be exported in format defined in
//  RFC 3447 Appendix A.1.2.
// --------------------------------------------------------------------------

#ifndef VSCF_EXPORT_PRIVATE_KEY_H_INCLUDED
#define VSCF_EXPORT_PRIVATE_KEY_H_INCLUDED

#include "vscf_library.h"
#include "vscf_impl.h"
#include "vscf_error.h"
#include "vscf_api.h"

#if !VSCF_IMPORT_PROJECT_COMMON_FROM_FRAMEWORK
#   include <virgil/crypto/common/vsc_buffer.h>
#endif

#if VSCF_IMPORT_PROJECT_COMMON_FROM_FRAMEWORK
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
//  Contains API requirements of the interface 'export private key'.
//
typedef struct vscf_export_private_key_api_t vscf_export_private_key_api_t;

//
//  Export private key in the binary format.
//
VSCF_PUBLIC vscf_error_t
vscf_export_private_key(vscf_impl_t *impl, vsc_buffer_t *out);

//
//  Return length in bytes required to hold exported private key.
//
VSCF_PUBLIC size_t
vscf_export_private_key_exported_private_key_len(vscf_impl_t *impl);

//
//  Return export private key API, or NULL if it is not implemented.
//
VSCF_PUBLIC const vscf_export_private_key_api_t *
vscf_export_private_key_api(vscf_impl_t *impl);

//
//  Check if given object implements interface 'export private key'.
//
VSCF_PUBLIC bool
vscf_export_private_key_is_implemented(vscf_impl_t *impl);

//
//  Returns interface unique identifier.
//
VSCF_PUBLIC vscf_api_tag_t
vscf_export_private_key_api_tag(const vscf_export_private_key_api_t *export_private_key_api);

//
//  Returns implementation unique identifier.
//
VSCF_PUBLIC vscf_impl_tag_t
vscf_export_private_key_impl_tag(const vscf_export_private_key_api_t *export_private_key_api);


// --------------------------------------------------------------------------
//  Generated section end.
// clang-format on
// --------------------------------------------------------------------------
//  @end


#ifdef __cplusplus
}
#endif


//  @footer
#endif // VSCF_EXPORT_PRIVATE_KEY_H_INCLUDED
//  @end