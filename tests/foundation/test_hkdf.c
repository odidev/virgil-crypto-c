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


#include "unity.h"
#include "test_utils.h"


#define TEST_DEPENDENCIES_AVAILABLE VSCF_HKDF &&VSCF_HMAC256
#if TEST_DEPENDENCIES_AVAILABLE

#include "vscf_hkdf.h"
#include "vscf_hmac256.h"
#include "vscf_assert.h"
#include "vscf_memory.h"

#include "test_data_hkdf.h"


// --------------------------------------------------------------------------
// Test implementation of the interface 'hkdf'.
// --------------------------------------------------------------------------
void
test__derive__sha256_vector_1__success(void) {

    byte *key = vscf_alloc(test_hkdf_VECTOR_1_DERIVED_DATA_LEN);

    vscf_hkdf_impl_t *hkdf_impl = vscf_hkdf_new();

    vscf_hkdf_take_hmac_stream(hkdf_impl, vscf_hmac256_impl(vscf_hmac256_new()));

    vscf_hkdf_derive(hkdf_impl, test_hkdf_VECTOR_1_KEY, test_hkdf_VECTOR_1_KEY_LEN, test_hkdf_VECTOR_1_SALT,
            test_hkdf_VECTOR_1_SALT_LEN, test_hkdf_VECTOR_1_INFO, test_hkdf_VECTOR_1_INFO_LEN, key,
            test_hkdf_VECTOR_1_DERIVED_DATA_LEN);

    vscf_hkdf_destroy(&hkdf_impl);

    TEST_ASSERT_EQUAL_HEX8_ARRAY(test_hkdf_VECTOR_1_DERIVED_DATA, key, test_hkdf_VECTOR_1_DERIVED_DATA_LEN);

    vscf_dealloc(key);
}

void
test__derive__sha256_vector_2__success(void) {

    byte *key = vscf_alloc(test_hkdf_VECTOR_2_DERIVED_DATA_LEN);

    vscf_hkdf_impl_t *hkdf_impl = vscf_hkdf_new();

    vscf_hkdf_take_hmac_stream(hkdf_impl, vscf_hmac256_impl(vscf_hmac256_new()));

    vscf_hkdf_derive(hkdf_impl, test_hkdf_VECTOR_2_KEY, test_hkdf_VECTOR_2_KEY_LEN, test_hkdf_VECTOR_2_SALT,
            test_hkdf_VECTOR_2_SALT_LEN, test_hkdf_VECTOR_2_INFO, test_hkdf_VECTOR_2_INFO_LEN, key,
            test_hkdf_VECTOR_2_DERIVED_DATA_LEN);

    vscf_hkdf_destroy(&hkdf_impl);

    TEST_ASSERT_EQUAL_HEX8_ARRAY(test_hkdf_VECTOR_2_DERIVED_DATA, key, test_hkdf_VECTOR_2_DERIVED_DATA_LEN);

    vscf_dealloc(key);
}

void
test__derive__sha256_vector_3__success(void) {
    byte *key = vscf_alloc(test_hkdf_VECTOR_3_DERIVED_DATA_LEN);

    vscf_hkdf_impl_t *hkdf_impl = vscf_hkdf_new();

    vscf_hkdf_take_hmac_stream(hkdf_impl, vscf_hmac256_impl(vscf_hmac256_new()));

    vscf_hkdf_derive(hkdf_impl, test_hkdf_VECTOR_3_KEY, test_hkdf_VECTOR_3_KEY_LEN, test_hkdf_VECTOR_3_SALT,
            test_hkdf_VECTOR_3_SALT_LEN, test_hkdf_VECTOR_3_INFO, test_hkdf_VECTOR_3_INFO_LEN, key,
            test_hkdf_VECTOR_3_DERIVED_DATA_LEN);

    vscf_hkdf_destroy(&hkdf_impl);

    TEST_ASSERT_EQUAL_HEX8_ARRAY(test_hkdf_VECTOR_3_DERIVED_DATA, key, test_hkdf_VECTOR_3_DERIVED_DATA_LEN);

    vscf_dealloc(key);
}

#endif // TEST_DEPENDENCIES_AVAILABLE


// --------------------------------------------------------------------------
// Entrypoint.
// --------------------------------------------------------------------------
int
main(void) {
    UNITY_BEGIN();

#if TEST_DEPENDENCIES_AVAILABLE
    RUN_TEST(test__derive__sha256_vector_1__success);
    RUN_TEST(test__derive__sha256_vector_2__success);
    RUN_TEST(test__derive__sha256_vector_3__success);
#else
    RUN_TEST(test__nothing__feature_disabled__must_be_ignored);
#endif

    return UNITY_END();
}
