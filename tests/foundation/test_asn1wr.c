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


#define TEST_DEPENDENCIES_AVAILABLE VSCF_ASN1RD
#if TEST_DEPENDENCIES_AVAILABLE

#include "vscf_asn1.h"
#include "vscf_asn1wr.h"
#include "vscf_assert.h"

#include "test_data_asn1.h"


// --------------------------------------------------------------------------
// Test 'write' methods.
// --------------------------------------------------------------------------

void
test__asn1wr_seal__argument_integer_2_and_buffer_capacity_ia_doubled__returns_encoded_integer_2(void) {

    vscf_asn1wr_impl_t *asn1wr = vscf_asn1wr_new();
    VSCF_ASSERT_PTR(asn1wr);

    vsc_buffer_t *asn1 = vsc_buffer_new_with_capacity(2 * test_asn1_encoded_INT_2_LEN);

    vscf_asn1wr_reset(asn1wr, asn1);

    size_t len = vscf_asn1wr_write_int(asn1wr, 2);
    vscf_asn1wr_seal(asn1wr);

    TEST_ASSERT_EQUAL(test_asn1_encoded_INT_2_LEN, len);
    TEST_ASSERT_EQUAL(test_asn1_encoded_INT_2_LEN, vsc_buffer_len(asn1));
    TEST_ASSERT_EQUAL_HEX8_ARRAY(test_asn1_encoded_INT_2, vsc_buffer_bytes(asn1), vsc_buffer_len(asn1));

    vsc_buffer_destroy(&asn1);
    vscf_asn1wr_destroy(&asn1wr);
}

void
test__asn1wr_write_tag__argument_tag_int__returns_tag_int(void) {

    vscf_asn1wr_impl_t *asn1wr = vscf_asn1wr_new();
    VSCF_ASSERT_PTR(asn1wr);

    vsc_buffer_t *asn1 = vsc_buffer_new_with_capacity(1);

    vscf_asn1wr_reset(asn1wr, asn1);

    size_t len = vscf_asn1wr_write_tag(asn1wr, vscf_asn1_tag_INTEGER);
    vscf_asn1wr_seal(asn1wr);

    TEST_ASSERT_EQUAL(1, len);
    TEST_ASSERT_EQUAL(1, vsc_buffer_len(asn1));
    TEST_ASSERT_EQUAL(vscf_asn1_tag_INTEGER, *vsc_buffer_bytes(asn1));

    vsc_buffer_destroy(&asn1);
    vscf_asn1wr_destroy(&asn1wr);
}

void
test__asn1wr_write_len__argument_len_100000__returns_hex_830186A0(void) {

    vscf_asn1wr_impl_t *asn1wr = vscf_asn1wr_new();
    VSCF_ASSERT_PTR(asn1wr);

    vsc_buffer_t *asn1 = vsc_buffer_new_with_capacity(4);

    vscf_asn1wr_reset(asn1wr, asn1);

    size_t len = vscf_asn1wr_write_len(asn1wr, 100000);
    vscf_asn1wr_seal(asn1wr);

    byte encoded_len[] = {0x83, 0x01, 0x86, 0xA0};

    TEST_ASSERT_EQUAL(4, len);
    TEST_ASSERT_EQUAL(4, vsc_buffer_len(asn1));
    TEST_ASSERT_EQUAL_HEX8_ARRAY(encoded_len, vsc_buffer_bytes(asn1), vsc_buffer_len(asn1));

    vsc_buffer_destroy(&asn1);
    vscf_asn1wr_destroy(&asn1wr);
}

void
test__asn1wr_write_int__argument_integer_2__returns_encoded_integer_2(void) {

    vscf_asn1wr_impl_t *asn1wr = vscf_asn1wr_new();
    VSCF_ASSERT_PTR(asn1wr);

    vsc_buffer_t *asn1 = vsc_buffer_new_with_capacity(test_asn1_encoded_INT_2_LEN);

    vscf_asn1wr_reset(asn1wr, asn1);

    size_t len = vscf_asn1wr_write_int(asn1wr, 2);
    vscf_asn1wr_seal(asn1wr);

    TEST_ASSERT_EQUAL(test_asn1_encoded_INT_2_LEN, len);
    TEST_ASSERT_EQUAL(test_asn1_encoded_INT_2_LEN, vsc_buffer_len(asn1));
    TEST_ASSERT_EQUAL_HEX8_ARRAY(test_asn1_encoded_INT_2, vsc_buffer_bytes(asn1), vsc_buffer_len(asn1));

    vsc_buffer_destroy(&asn1);
    vscf_asn1wr_destroy(&asn1wr);
}

void
test__asn1wr_write_bool__argument_bool_false__returns_encoded_bool_false(void) {

    vscf_asn1wr_impl_t *asn1wr = vscf_asn1wr_new();
    VSCF_ASSERT_PTR(asn1wr);

    vsc_buffer_t *asn1 = vsc_buffer_new_with_capacity(test_asn1_encoded_BOOLEAN_FALSE_LEN);

    vscf_asn1wr_reset(asn1wr, asn1);

    size_t len = vscf_asn1wr_write_bool(asn1wr, false);
    vscf_asn1wr_seal(asn1wr);

    TEST_ASSERT_EQUAL(test_asn1_encoded_BOOLEAN_FALSE_LEN, len);
    TEST_ASSERT_EQUAL(test_asn1_encoded_BOOLEAN_FALSE_LEN, vsc_buffer_len(asn1));
    TEST_ASSERT_EQUAL_HEX8_ARRAY(test_asn1_encoded_BOOLEAN_FALSE, vsc_buffer_bytes(asn1), vsc_buffer_len(asn1));

    vsc_buffer_destroy(&asn1);
    vscf_asn1wr_destroy(&asn1wr);
}

void
test__asn1wr_write_bool__argument_bool_true__returns_encoded_bool_true(void) {

    vscf_asn1wr_impl_t *asn1wr = vscf_asn1wr_new();
    VSCF_ASSERT_PTR(asn1wr);

    vsc_buffer_t *asn1 = vsc_buffer_new_with_capacity(test_asn1_encoded_BOOLEAN_TRUE_LEN);

    vscf_asn1wr_reset(asn1wr, asn1);

    size_t len = vscf_asn1wr_write_bool(asn1wr, true);
    vscf_asn1wr_seal(asn1wr);

    TEST_ASSERT_EQUAL(test_asn1_encoded_BOOLEAN_TRUE_LEN, len);
    TEST_ASSERT_EQUAL(test_asn1_encoded_BOOLEAN_TRUE_LEN, vsc_buffer_len(asn1));
    TEST_ASSERT_EQUAL_HEX8_ARRAY(test_asn1_encoded_BOOLEAN_TRUE, vsc_buffer_bytes(asn1), vsc_buffer_len(asn1));

    vsc_buffer_destroy(&asn1);
    vscf_asn1wr_destroy(&asn1wr);
}

void
test__asn1wr_write_null__argument_null__returns_encoded_null(void) {

    vscf_asn1wr_impl_t *asn1wr = vscf_asn1wr_new();
    VSCF_ASSERT_PTR(asn1wr);

    vsc_buffer_t *asn1 = vsc_buffer_new_with_capacity(test_asn1_encoded_NULL_LEN);

    vscf_asn1wr_reset(asn1wr, asn1);

    size_t len = vscf_asn1wr_write_null(asn1wr);
    vscf_asn1wr_seal(asn1wr);

    TEST_ASSERT_EQUAL(test_asn1_encoded_NULL_LEN, len);
    TEST_ASSERT_EQUAL(test_asn1_encoded_NULL_LEN, vsc_buffer_len(asn1));
    TEST_ASSERT_EQUAL_HEX8_ARRAY(test_asn1_encoded_NULL, vsc_buffer_bytes(asn1), vsc_buffer_len(asn1));

    vsc_buffer_destroy(&asn1);
    vscf_asn1wr_destroy(&asn1wr);
}

void
test__asn1wr_write_octet_str__argument_octet_string__returns_encoded_octet_string(void) {

    vscf_asn1wr_impl_t *asn1wr = vscf_asn1wr_new();
    VSCF_ASSERT_PTR(asn1wr);

    vsc_buffer_t *asn1 = vsc_buffer_new_with_capacity(test_asn1_encoded_OCTET_STRING_LEN);

    vscf_asn1wr_reset(asn1wr, asn1);

    size_t len = vscf_asn1wr_write_octet_str(
            asn1wr, vsc_data(test_asn1_decoded_OCTET_STRING, test_asn1_decoded_OCTET_STRING_LEN));
    vscf_asn1wr_seal(asn1wr);

    TEST_ASSERT_EQUAL(test_asn1_encoded_OCTET_STRING_LEN, len);
    TEST_ASSERT_EQUAL(test_asn1_encoded_OCTET_STRING_LEN, vsc_buffer_len(asn1));
    TEST_ASSERT_EQUAL_HEX8_ARRAY(test_asn1_encoded_OCTET_STRING, vsc_buffer_bytes(asn1), vsc_buffer_len(asn1));

    vsc_buffer_destroy(&asn1);
    vscf_asn1wr_destroy(&asn1wr);
}

void
test__asn1wr_write_utf8_str_argument_utf8_string__returns_encoded_utf8_string(void) {

    vscf_asn1wr_impl_t *asn1wr = vscf_asn1wr_new();
    VSCF_ASSERT_PTR(asn1wr);

    vsc_buffer_t *asn1 = vsc_buffer_new_with_capacity(test_asn1_encoded_UTF8_STRING_LEN);

    vscf_asn1wr_reset(asn1wr, asn1);

    size_t len = vscf_asn1wr_write_utf8_str(
            asn1wr, vsc_data(test_asn1_decoded_UTF8_STRING, test_asn1_decoded_UTF8_STRING_LEN));
    vscf_asn1wr_seal(asn1wr);

    TEST_ASSERT_EQUAL(test_asn1_encoded_UTF8_STRING_LEN, len);
    TEST_ASSERT_EQUAL(test_asn1_encoded_UTF8_STRING_LEN, vsc_buffer_len(asn1));
    TEST_ASSERT_EQUAL_HEX8_ARRAY(test_asn1_encoded_UTF8_STRING, vsc_buffer_bytes(asn1), vsc_buffer_len(asn1));

    vsc_buffer_destroy(&asn1);
    vscf_asn1wr_destroy(&asn1wr);
}

void
test__asn1wr_write_oid__argument_oid_sha256__returns_encoded_oid_sha256(void) {

    vscf_asn1wr_impl_t *asn1wr = vscf_asn1wr_new();
    VSCF_ASSERT_PTR(asn1wr);

    vsc_buffer_t *asn1 = vsc_buffer_new_with_capacity(test_asn1_encoded_OID_SHA256_LEN);

    vscf_asn1wr_reset(asn1wr, asn1);

    size_t len =
            vscf_asn1wr_write_oid(asn1wr, vsc_data(test_asn1_decoded_OID_SHA256, test_asn1_decoded_OID_SHA256_LEN));
    vscf_asn1wr_seal(asn1wr);

    TEST_ASSERT_EQUAL(test_asn1_encoded_OID_SHA256_LEN, len);
    TEST_ASSERT_EQUAL(test_asn1_encoded_OID_SHA256_LEN, vsc_buffer_len(asn1));
    TEST_ASSERT_EQUAL_HEX8_ARRAY(test_asn1_encoded_OID_SHA256, vsc_buffer_bytes(asn1), vsc_buffer_len(asn1));

    vsc_buffer_destroy(&asn1);
    vscf_asn1wr_destroy(&asn1wr);
}

void
test__asn1wr_write_sequence__argument_len_32__returns_encoded_sequence_with_len_32(void) {

    vscf_asn1wr_impl_t *asn1wr = vscf_asn1wr_new();
    VSCF_ASSERT_PTR(asn1wr);

    vsc_buffer_t *asn1 = vsc_buffer_new_with_capacity(test_asn1_encoded_SEQUENCE_WITH_LEN_32_LEN);

    vscf_asn1wr_reset(asn1wr, asn1);

    size_t len = vscf_asn1wr_write_sequence(asn1wr, 32);
    vscf_asn1wr_seal(asn1wr);

    TEST_ASSERT_EQUAL(test_asn1_encoded_SEQUENCE_WITH_LEN_32_LEN, len);
    TEST_ASSERT_EQUAL(test_asn1_encoded_SEQUENCE_WITH_LEN_32_LEN, vsc_buffer_len(asn1));
    TEST_ASSERT_EQUAL_HEX8_ARRAY(test_asn1_encoded_SEQUENCE_WITH_LEN_32, vsc_buffer_bytes(asn1), vsc_buffer_len(asn1));

    vsc_buffer_destroy(&asn1);
    vscf_asn1wr_destroy(&asn1wr);
}

void
test__asn1wr_write_set__argument_len_32__returns_encoded_set_with_len_32(void) {

    vscf_asn1wr_impl_t *asn1wr = vscf_asn1wr_new();
    VSCF_ASSERT_PTR(asn1wr);

    vsc_buffer_t *asn1 = vsc_buffer_new_with_capacity(test_asn1_encoded_SET_WITH_LEN_32_LEN);

    vscf_asn1wr_reset(asn1wr, asn1);

    size_t len = vscf_asn1wr_write_set(asn1wr, 32);
    vscf_asn1wr_seal(asn1wr);

    TEST_ASSERT_EQUAL(test_asn1_encoded_SET_WITH_LEN_32_LEN, len);
    TEST_ASSERT_EQUAL(test_asn1_encoded_SET_WITH_LEN_32_LEN, vsc_buffer_len(asn1));
    TEST_ASSERT_EQUAL_HEX8_ARRAY(test_asn1_encoded_SET_WITH_LEN_32, vsc_buffer_bytes(asn1), vsc_buffer_len(asn1));

    vsc_buffer_destroy(&asn1);
    vscf_asn1wr_destroy(&asn1wr);
}


// --------------------------------------------------------------------------
// Test 'error' method.
// --------------------------------------------------------------------------

void
test__asn1wr_error__write_to_small_buffer__returns_error_small_buffer(void) {

    vscf_asn1wr_impl_t *asn1wr = vscf_asn1wr_new();
    VSCF_ASSERT_PTR(asn1wr);

    vsc_buffer_t *asn1 = vsc_buffer_new_with_capacity(1);

    vscf_asn1wr_reset(asn1wr, asn1);

    size_t len = vscf_asn1wr_write_int(asn1wr, 2);

    TEST_ASSERT_EQUAL(vscf_error_SMALL_BUFFER, vscf_asn1wr_error(asn1wr));

    vsc_buffer_destroy(&asn1);
    vscf_asn1wr_destroy(&asn1wr);
}


#endif // TEST_DEPENDENCIES_AVAILABLE


// --------------------------------------------------------------------------
// Entrypoint.
// --------------------------------------------------------------------------
int
main(void) {
    UNITY_BEGIN();

#if TEST_DEPENDENCIES_AVAILABLE
    RUN_TEST(test__asn1wr_seal__argument_integer_2_and_buffer_capacity_ia_doubled__returns_encoded_integer_2);
    RUN_TEST(test__asn1wr_write_tag__argument_tag_int__returns_tag_int);
    RUN_TEST(test__asn1wr_write_len__argument_len_100000__returns_hex_830186A0);
    RUN_TEST(test__asn1wr_write_int__argument_integer_2__returns_encoded_integer_2);
    RUN_TEST(test__asn1wr_write_bool__argument_bool_false__returns_encoded_bool_false);
    RUN_TEST(test__asn1wr_write_bool__argument_bool_true__returns_encoded_bool_true);
    RUN_TEST(test__asn1wr_write_null__argument_null__returns_encoded_null);
    RUN_TEST(test__asn1wr_write_octet_str__argument_octet_string__returns_encoded_octet_string);
    RUN_TEST(test__asn1wr_write_utf8_str_argument_utf8_string__returns_encoded_utf8_string);
    RUN_TEST(test__asn1wr_write_oid__argument_oid_sha256__returns_encoded_oid_sha256);
    RUN_TEST(test__asn1wr_write_sequence__argument_len_32__returns_encoded_sequence_with_len_32);
    RUN_TEST(test__asn1wr_write_set__argument_len_32__returns_encoded_set_with_len_32);

    RUN_TEST(test__asn1wr_error__write_to_small_buffer__returns_error_small_buffer);
#else
    RUN_TEST(test__nothing__feature_disabled__must_be_ignored);
#endif

    return UNITY_END();
}