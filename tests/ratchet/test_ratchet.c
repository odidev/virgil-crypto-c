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

#define UNITY_BEGIN() UnityBegin(__FILENAME__)

#include "unity.h"
#include "test_utils.h"

#define TEST_DEPENDENCIES_AVAILABLE VSCR_RATCHET
#if TEST_DEPENDENCIES_AVAILABLE

#include "vscr_ratchet_rng.h"
#include "vscr_ratchet.h"
#include "vscr_virgil_ratchet_fake_rng_impl.h"
#include "test_data_ratchet.h"

#include <virgil/crypto/common/private/vsc_buffer_defs.h>
#include <ed25519/ed25519.h>

static void
initialize(vscr_ratchet_t *ratchet_alice, vscr_ratchet_t *ratchet_bob, RegularMessage *regular_message) {
    vscr_ratchet_cipher_t *ratchet_cipher = vscr_ratchet_cipher_new();
    vscr_ratchet_use_cipher(ratchet_alice, ratchet_cipher);
    vscr_ratchet_use_cipher(ratchet_bob, ratchet_cipher);
    vscr_ratchet_cipher_destroy(&ratchet_cipher);

    vscr_ratchet_take_rng(ratchet_alice, vscr_virgil_ratchet_fake_rng_impl(vscr_virgil_ratchet_fake_rng_new()));
    vscr_ratchet_take_rng(ratchet_bob, vscr_virgil_ratchet_fake_rng_impl(vscr_virgil_ratchet_fake_rng_new()));

    vsc_buffer_t *ratchet_private_key = vsc_buffer_new_with_capacity(test_ratchet_ratchet_private_key.len);
    memcpy(vsc_buffer_ptr(ratchet_private_key), test_ratchet_ratchet_private_key.bytes,
            test_ratchet_ratchet_private_key.len);
    vsc_buffer_reserve(ratchet_private_key, test_ratchet_ratchet_private_key.len);

    vsc_buffer_t *ratchet_public_key = vsc_buffer_new_with_capacity(ED25519_KEY_LEN);
    TEST_ASSERT_EQUAL_INT(
            0, curve25519_get_pubkey(vsc_buffer_ptr(ratchet_public_key), test_ratchet_ratchet_private_key.bytes));
    vsc_buffer_reserve(ratchet_public_key, test_ratchet_ratchet_private_key.len);

    TEST_ASSERT_EQUAL_INT(
            vscr_SUCCESS, vscr_ratchet_initiate(ratchet_alice, test_ratchet_shared_secret, ratchet_private_key));

    vscr_error_t result = vscr_ratchet_encrypt(ratchet_alice, test_ratchet_plain_text1, regular_message);
    TEST_ASSERT_EQUAL(vscr_SUCCESS, result);

    vscr_error_ctx_t error_ctx;
    vscr_error_ctx_reset(&error_ctx);

    vscr_ratchet_respond(ratchet_bob, test_ratchet_shared_secret, ratchet_public_key, *regular_message);

    vsc_buffer_destroy(&ratchet_private_key);
    vsc_buffer_destroy(&ratchet_public_key);
}

void
test__1(void) {
    vscr_ratchet_t *ratchet_alice = vscr_ratchet_new();
    vscr_ratchet_t *ratchet_bob = vscr_ratchet_new();

    RegularMessage regular_message = RegularMessage_init_zero;

    initialize(ratchet_alice, ratchet_bob, &regular_message);

    size_t plain_text_len = vscr_ratchet_decrypt_len(ratchet_bob, regular_message.cipher_text.size);

    vsc_buffer_t *decrypted = vsc_buffer_new_with_capacity(plain_text_len);
    vscr_error_t result = vscr_ratchet_decrypt(ratchet_bob, &regular_message, decrypted);
    TEST_ASSERT_EQUAL(vscr_SUCCESS, result);

    TEST_ASSERT_EQUAL_INT(test_ratchet_plain_text1.len, vsc_buffer_len(decrypted));
    TEST_ASSERT_EQUAL_MEMORY(test_ratchet_plain_text1.bytes, vsc_buffer_bytes(decrypted), test_ratchet_plain_text1.len);

    RegularMessage regular_message2 = RegularMessage_init_zero;

    result = vscr_ratchet_encrypt(ratchet_bob, test_ratchet_plain_text2, &regular_message2);
    TEST_ASSERT_EQUAL(vscr_SUCCESS, result);

    size_t plain_text2_len = vscr_ratchet_decrypt_len(ratchet_alice, vscr_ratchet_encrypt_len(ratchet_bob, test_ratchet_plain_text2.len));
    vsc_buffer_t *decrypted2 = vsc_buffer_new_with_capacity(plain_text2_len);
    result = vscr_ratchet_decrypt(ratchet_alice, &regular_message2, decrypted2);
    TEST_ASSERT_EQUAL(vscr_SUCCESS, result);

    TEST_ASSERT_EQUAL_INT(test_ratchet_plain_text2.len, vsc_buffer_len(decrypted2));
    TEST_ASSERT_EQUAL_MEMORY(
            test_ratchet_plain_text2.bytes, vsc_buffer_bytes(decrypted2), test_ratchet_plain_text2.len);

    vscr_ratchet_destroy(&ratchet_alice);
    vscr_ratchet_destroy(&ratchet_bob);
    vsc_buffer_destroy(&decrypted);
    vsc_buffer_destroy(&decrypted2);
}

void
test__2(void) {
    vscr_ratchet_t *ratchet_alice = vscr_ratchet_new();
    vscr_ratchet_t *ratchet_bob = vscr_ratchet_new();

    RegularMessage regular_message1 = RegularMessage_init_zero;

    initialize(ratchet_alice, ratchet_bob, &regular_message1);

    RegularMessage regular_message2 = RegularMessage_init_zero;

    vscr_error_t result = vscr_ratchet_encrypt(ratchet_alice, test_ratchet_plain_text2, &regular_message2);
    TEST_ASSERT_EQUAL(vscr_SUCCESS, result);

    size_t plain_text2_len = vscr_ratchet_decrypt_len(ratchet_bob, regular_message2.cipher_text.size);

    vsc_buffer_t *decrypted2 = vsc_buffer_new_with_capacity(plain_text2_len);
    result = vscr_ratchet_decrypt(ratchet_bob, &regular_message2, decrypted2);
    TEST_ASSERT_EQUAL(vscr_SUCCESS, result);

    TEST_ASSERT_EQUAL_INT(test_ratchet_plain_text2.len, vsc_buffer_len(decrypted2));
    TEST_ASSERT_EQUAL_MEMORY(
            test_ratchet_plain_text2.bytes, vsc_buffer_bytes(decrypted2), test_ratchet_plain_text2.len);

    size_t plain_text1_len = vscr_ratchet_decrypt_len(ratchet_bob, regular_message1.cipher_text.size);

    vsc_buffer_t *decrypted = vsc_buffer_new_with_capacity(plain_text1_len);
    result = vscr_ratchet_decrypt(ratchet_bob, &regular_message1, decrypted);
    TEST_ASSERT_EQUAL(vscr_SUCCESS, result);

    TEST_ASSERT_EQUAL_INT(test_ratchet_plain_text1.len, vsc_buffer_len(decrypted));
    TEST_ASSERT_EQUAL_MEMORY(test_ratchet_plain_text1.bytes, vsc_buffer_bytes(decrypted), test_ratchet_plain_text1.len);

    vscr_ratchet_destroy(&ratchet_alice);
    vscr_ratchet_destroy(&ratchet_bob);
    vsc_buffer_destroy(&decrypted);
    vsc_buffer_destroy(&decrypted2);
}

void
test__3(void) {
    vscr_ratchet_t *ratchet_alice = vscr_ratchet_new();
    vscr_ratchet_t *ratchet_bob = vscr_ratchet_new();

    RegularMessage regular_message = RegularMessage_init_zero;

    initialize(ratchet_alice, ratchet_bob, &regular_message);

    // FIXME
    vscr_impl_t *rng = vscr_virgil_ratchet_fake_rng_impl(vscr_virgil_ratchet_fake_rng_new());

    for (int i = 0; i < 100; i++) {
        byte rnd_plain_text_len;
        vsc_buffer_t *fake_buffer1 = vsc_buffer_new();
        vsc_buffer_use(fake_buffer1, &rnd_plain_text_len, sizeof(rnd_plain_text_len));
        vscr_ratchet_rng_generate_random_data(rng, sizeof(rnd_plain_text_len), fake_buffer1);

        if (rnd_plain_text_len == 0)
            rnd_plain_text_len = 10;

        byte dice_rnd;
        vsc_buffer_t *fake_buffer2 = vsc_buffer_new();
        vsc_buffer_use(fake_buffer2, &dice_rnd, sizeof(dice_rnd));
        vscr_ratchet_rng_generate_random_data(rng, sizeof(dice_rnd), fake_buffer2);
        bool dice = dice_rnd % 2 == 0;

        if (i == 0)
            dice = true;

        vsc_buffer_destroy(&fake_buffer1);
        vsc_buffer_destroy(&fake_buffer2);

        vsc_buffer_t *plain_text = vsc_buffer_new_with_capacity(rnd_plain_text_len);
        vscr_ratchet_rng_generate_random_data(rng, vsc_buffer_capacity(plain_text), plain_text);

        vscr_ratchet_t *sender, *receiver;

        // Alice sends msg
        if (dice) {
            sender = ratchet_alice;
            receiver = ratchet_bob;
        } else {
            sender = ratchet_bob;
            receiver = ratchet_alice;
        }

        RegularMessage regular_message = RegularMessage_init_zero;

        vscr_error_t result = vscr_ratchet_encrypt(sender, vsc_buffer_data(plain_text), &regular_message);
        TEST_ASSERT_EQUAL(vscr_SUCCESS, result);

        size_t plain_text_len = vscr_ratchet_decrypt_len(ratchet_bob, regular_message.cipher_text.size);

        vsc_buffer_t *decrypted = vsc_buffer_new_with_capacity(plain_text_len);
        result = vscr_ratchet_decrypt(receiver, &regular_message, decrypted);
        TEST_ASSERT_EQUAL(vscr_SUCCESS, result);

        TEST_ASSERT_EQUAL_INT(vsc_buffer_len(plain_text), vsc_buffer_len(decrypted));
        TEST_ASSERT_EQUAL_MEMORY(vsc_buffer_bytes(plain_text), vsc_buffer_bytes(decrypted), vsc_buffer_len(plain_text));

        vsc_buffer_destroy(&plain_text);
        vsc_buffer_destroy(&decrypted);
    }

    vscr_impl_destroy(&rng);
    vscr_ratchet_destroy(&ratchet_alice);
    vscr_ratchet_destroy(&ratchet_bob);
}

#endif // TEST_DEPENDENCIES_AVAILABLE


// --------------------------------------------------------------------------
// Entrypoint.
// --------------------------------------------------------------------------
int
main(void) {
    UNITY_BEGIN();

#if TEST_DEPENDENCIES_AVAILABLE
    RUN_TEST(test__1);
    RUN_TEST(test__2);
    RUN_TEST(test__3);
#else
    RUN_TEST(test__nothing__feature_disabled__must_be_ignored);
#endif

    return UNITY_END();
}
