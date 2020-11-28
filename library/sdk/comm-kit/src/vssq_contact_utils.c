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
//  Helps to normalize and hash user contacts: username, email, phone, etc.
// --------------------------------------------------------------------------


//  @warning
// --------------------------------------------------------------------------
//  This file is partially generated.
//  Generated blocks are enclosed between tags [@<tag>, @end].
//  User's code can be added between tags [@end, @<tag>].
// --------------------------------------------------------------------------

#include "vssq_contact_utils.h"
#include "vssq_memory.h"
#include "vssq_assert.h"

#include <ctype.h>
#include <virgil/crypto/common/private/vsc_buffer_defs.h>
#include <virgil/crypto/foundation/vscf_sha256.h>
#include <virgil/crypto/foundation/private/vscf_sha256_defs.h>
#include <virgil/crypto/foundation/vscf_binary.h>
#include <virgil/sdk/core/private/vssc_string_map_defs.h>
#include <virgil/sdk/core/private/vssc_string_map_bucket_defs.h>

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
//  Validate and normalize username.
//
//  Validation rules:
//      1. Length in the range: [1..20]
//      2. Do not start or end with an underscore
//      3. Do not start with a number
//      4. Match regex: ^[a-zA-Z0-9_]+$
//
//  Normalization rules:
//      1. All characters lowercase
//
VSSQ_PUBLIC vssq_status_t
vssq_contact_utils_normalize_username(vsc_str_t username, vsc_str_buffer_t *normalized) {

    VSSQ_ASSERT(vsc_str_is_valid_and_non_empty(username));
    VSSQ_ASSERT(vsc_str_buffer_is_valid(normalized));
    VSSQ_ASSERT(vsc_str_buffer_unused_len(normalized) >= username.len);

    //
    //  Validate rule 1 - Length in the range: [1..20].
    //
    if (username.len > vssq_contact_utils_USERNAME_LEN_MAX) {
        return vssq_status_CONTACT_VALIDATION_FAILED_USERNAME_TOO_LONG;
    }

    //
    //  Validate rule 2 - Do not start or end with an underscore.
    //
    if (('_' == username.chars[0]) || ('_' == username.chars[username.len - 1])) {
        return vssq_status_CONTACT_VALIDATION_FAILED_USERNAME_BAD_CHARS;
    }

    //
    //  Validate rule 3 - Do not start with a number.
    //
    if (isdigit(username.chars[0])) {
        return vssq_status_CONTACT_VALIDATION_FAILED_USERNAME_BAD_CHARS;
    }

    //
    //  Validate, normalize and write to the output.
    //
    char *normalized_chars = vsc_str_buffer_unused_chars(normalized);

    for (size_t pos = 0; pos < username.len; ++pos) {
        const int ch = username.chars[pos];
        //
        //  Validate rule 4 - Match regex: ^[a-zA-Z0-9_]+$.
        //  And convert to the lowercase.
        //
        if (isalnum(ch) || (ch == '_')) {
            normalized_chars[pos] = (char)tolower(ch);
        } else {
            return vssq_status_CONTACT_VALIDATION_FAILED_USERNAME_BAD_CHARS;
        }
    }

    vsc_str_buffer_inc_used(normalized, username.len);

    return vssq_status_SUCCESS;
}

//
//  Validate, normalize, and hash username.
//
VSSQ_PUBLIC vssq_status_t
vssq_contact_utils_hash_username(vsc_str_t username, vsc_str_buffer_t *digest_hex) {

    VSSQ_ASSERT(vsc_str_is_valid_and_non_empty(username));
    VSSQ_ASSERT(vsc_str_buffer_is_valid(digest_hex));
    VSSQ_ASSERT(vsc_str_buffer_unused_len(digest_hex) >= vssq_contact_utils_DIGEST_HEX_LEN);

    //
    //  Validate rule 1 - Length in the range: [1..20].
    //
    if (username.len > vssq_contact_utils_USERNAME_LEN_MAX) {
        return vssq_status_CONTACT_VALIDATION_FAILED_USERNAME_TOO_LONG;
    }

    //
    //  Validate rule 2 - Do not start or end with an underscore.
    //
    if (('_' == username.chars[0]) || ('_' == username.chars[username.len - 1])) {
        return vssq_status_CONTACT_VALIDATION_FAILED_USERNAME_BAD_CHARS;
    }

    //
    //  Validate rule 3 - Do not start with a number.
    //
    if (isdigit(username.chars[0])) {
        return vssq_status_CONTACT_VALIDATION_FAILED_USERNAME_BAD_CHARS;
    }

    //
    //  Validate, normalize and hash.
    //
    vscf_sha256_t hash;
    vscf_sha256_init(&hash);
    vscf_sha256_start(&hash);

    for (size_t pos = 0; pos < username.len; ++pos) {
        const int ch = username.chars[pos];
        //
        //  Validate rule 4 - Match regex: ^[a-zA-Z0-9_]+$.
        //  And convert to the lowercase.
        //
        if (isalnum(ch) || (ch == '_')) {
            const byte normalized_byte = (byte)tolower(ch);
            vscf_sha256_update(&hash, vsc_data(&normalized_byte, 1));
        } else {
            return vssq_status_CONTACT_VALIDATION_FAILED_USERNAME_BAD_CHARS;
        }
    }

    byte digest_bytes[vscf_sha256_DIGEST_LEN] = {0x00};
    vsc_buffer_t digest;
    vsc_buffer_init(&digest);
    vsc_buffer_use(&digest, digest_bytes, sizeof(digest_bytes));

    vscf_sha256_finish(&hash, &digest);

    vscf_binary_to_hex(vsc_buffer_data(&digest), digest_hex);

    return vssq_status_SUCCESS;
}

//
//  Validate, normalize, and hash each username.
//
//  Return a map username->hash.
//
//  Note, usernames in the returned map equals to the given.
//
VSSQ_PUBLIC vssc_string_map_t *
vssq_contact_utils_hash_usernames(const vssc_string_list_t *usernames, vssq_error_t *error) {

    VSSQ_ASSERT_PTR(usernames);

    vssc_string_map_t *result = vssc_string_map_new();
    vsc_str_buffer_t *username_hash = vsc_str_buffer_new_with_capacity(vssq_contact_utils_DIGEST_HEX_LEN);

    for (const vssc_string_list_t *username_it = usernames;
            (username_it != NULL) && vssc_string_list_has_item(username_it);
            username_it = vssc_string_list_next(username_it)) {

        vsc_str_t username = vssc_string_list_item(username_it);

        const vssq_status_t hash_status = vssq_contact_utils_hash_username(username, username_hash);

        if (hash_status == vssq_status_SUCCESS) {
            vssc_string_map_put(result, username, vsc_str_buffer_str(username_hash));
            vsc_str_buffer_reset(username_hash);
        } else {
            VSSQ_ERROR_SAFE_UPDATE(error, hash_status);
            vssc_string_map_destroy(&result);
            vsc_str_buffer_destroy(&username_hash);
            return NULL;
        }
    }

    vsc_str_buffer_destroy(&username_hash);

    return result;
}

//
//  Merge "contact request map" with "contact response map".
//
//  Contact request map : username | email | phone_number->hash
//  Contact response map: hash->identity
//  Final map : username | email | phone_number->identity
//
VSSQ_PUBLIC vssc_string_map_t *
vssq_contact_utils_merge_contact_discovery_maps(
        const vssc_string_map_t *contact_request_map, const vssc_string_map_t *contact_response_map) {

    VSSQ_ASSERT_PTR(contact_request_map);
    VSSQ_ASSERT_PTR(contact_response_map);

    vssc_string_map_t *result_map = vssc_string_map_new();

    for (size_t pos = 0; pos < contact_request_map->capacity; ++pos) {
        for (vssc_string_map_bucket_t *contact_request_bucket = contact_request_map->buckets[pos];
                (contact_request_bucket != NULL) && (contact_request_bucket->key != NULL);
                contact_request_bucket = contact_request_bucket->next) {


            vsc_str_t contact_request_key = vsc_str_buffer_str(contact_request_bucket->key);
            vsc_str_t contact_request_value = vsc_str_buffer_str(contact_request_bucket->value);

            vssc_error_t core_sdk_error;
            vssc_error_reset(&core_sdk_error);

            const vsc_str_t contact_response_value =
                    vssc_string_map_get(contact_response_map, contact_request_value, &core_sdk_error);

            if (!vssc_error_has_error(&core_sdk_error)) {
                // TODO: Optimize copy, by adding put that takes vsc_str_buffer.
                vssc_string_map_put(result_map, contact_request_key, contact_response_value);
            }
        }
    }

    return result_map;
}