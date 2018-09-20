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

#include "vscr_ratchet_session.h"
#include "vscr_memory.h"
#include "vscr_assert.h"
#include "vscr_ratchet_rng.h"
#include "vscr_ratchet_session_defs.h"

#include <ed25519/ed25519.h>
//  @end


//  @generated
// --------------------------------------------------------------------------
// clang-format off
//  Generated section start.
// --------------------------------------------------------------------------

//
//  Perform context specific initialization.
//  Note, this method is called automatically when method vscr_ratchet_session_init() is called.
//  Note, that context is already zeroed.
//
static void
vscr_ratchet_session_init_ctx(vscr_ratchet_session_t *ratchet_session_ctx);

//
//  Release all inner resources.
//  Note, this method is called automatically once when class is completely cleaning up.
//  Note, that context will be zeroed automatically next this method.
//
static void
vscr_ratchet_session_cleanup_ctx(vscr_ratchet_session_t *ratchet_session_ctx);

//
//  Return size of 'vscr_ratchet_session_t'.
//
VSCR_PUBLIC size_t
vscr_ratchet_session_ctx_size(void) {

    return sizeof(vscr_ratchet_session_t);
}

//
//  Perform initialization of pre-allocated context.
//
VSCR_PUBLIC void
vscr_ratchet_session_init(vscr_ratchet_session_t *ratchet_session_ctx) {

    VSCR_ASSERT_PTR(ratchet_session_ctx);

    vscr_zeroize(ratchet_session_ctx, sizeof(vscr_ratchet_session_t));

    ratchet_session_ctx->refcnt = 1;

    vscr_ratchet_session_init_ctx(ratchet_session_ctx);
}

//
//  Release all inner resources including class dependencies.
//
VSCR_PUBLIC void
vscr_ratchet_session_cleanup(vscr_ratchet_session_t *ratchet_session_ctx) {

    if (ratchet_session_ctx == NULL) {
        return;
    }

    if (ratchet_session_ctx->refcnt == 0) {
        return;
    }

    if (--ratchet_session_ctx->refcnt == 0) {
        vscr_ratchet_session_cleanup_ctx(ratchet_session_ctx);

        vscr_ratchet_session_release_rng(ratchet_session_ctx);
        vscr_ratchet_session_release_ratchet(ratchet_session_ctx);

        vscr_zeroize(ratchet_session_ctx, sizeof(vscr_ratchet_session_t));
    }
}

//
//  Allocate context and perform it's initialization.
//
VSCR_PUBLIC vscr_ratchet_session_t *
vscr_ratchet_session_new(void) {

    vscr_ratchet_session_t *ratchet_session_ctx = (vscr_ratchet_session_t *) vscr_alloc(sizeof (vscr_ratchet_session_t));
    VSCR_ASSERT_ALLOC(ratchet_session_ctx);

    vscr_ratchet_session_init(ratchet_session_ctx);

    ratchet_session_ctx->self_dealloc_cb = vscr_dealloc;

    return ratchet_session_ctx;
}

//
//  Release all inner resources and deallocate context if needed.
//  It is safe to call this method even if context was allocated by the caller.
//
VSCR_PUBLIC void
vscr_ratchet_session_delete(vscr_ratchet_session_t *ratchet_session_ctx) {

    if (ratchet_session_ctx == NULL) {
        return;
    }

    vscr_ratchet_session_cleanup(ratchet_session_ctx);

    vscr_dealloc_fn self_dealloc_cb = ratchet_session_ctx->self_dealloc_cb;

    if (ratchet_session_ctx->refcnt == 0 && self_dealloc_cb != NULL) {
        self_dealloc_cb(ratchet_session_ctx);
    }
}

//
//  Delete given context and nullifies reference.
//  This is a reverse action of the function 'vscr_ratchet_session_new ()'.
//
VSCR_PUBLIC void
vscr_ratchet_session_destroy(vscr_ratchet_session_t **ratchet_session_ctx_ref) {

    VSCR_ASSERT_PTR(ratchet_session_ctx_ref);

    vscr_ratchet_session_t *ratchet_session_ctx = *ratchet_session_ctx_ref;
    *ratchet_session_ctx_ref = NULL;

    vscr_ratchet_session_delete(ratchet_session_ctx);
}

//
//  Copy given class context by increasing reference counter.
//
VSCR_PUBLIC vscr_ratchet_session_t *
vscr_ratchet_session_copy(vscr_ratchet_session_t *ratchet_session_ctx) {

    VSCR_ASSERT_PTR(ratchet_session_ctx);

    ++ratchet_session_ctx->refcnt;

    return ratchet_session_ctx;
}

//
//  Setup dependency to the interface 'ratchet rng' with shared ownership.
//
VSCR_PUBLIC void
vscr_ratchet_session_use_rng(vscr_ratchet_session_t *ratchet_session_ctx, vscr_impl_t *rng) {

    VSCR_ASSERT_PTR(ratchet_session_ctx);
    VSCR_ASSERT_PTR(rng);
    VSCR_ASSERT_PTR(ratchet_session_ctx->rng == NULL);

    VSCR_ASSERT(vscr_ratchet_rng_is_implemented(rng));

    ratchet_session_ctx->rng = vscr_impl_copy(rng);
}

//
//  Setup dependency to the interface 'ratchet rng' and transfer ownership.
//  Note, transfer ownership does not mean that object is uniquely owned by the target object.
//
VSCR_PUBLIC void
vscr_ratchet_session_take_rng(vscr_ratchet_session_t *ratchet_session_ctx, vscr_impl_t *rng) {

    VSCR_ASSERT_PTR(ratchet_session_ctx);
    VSCR_ASSERT_PTR(rng);
    VSCR_ASSERT_PTR(ratchet_session_ctx->rng == NULL);

    VSCR_ASSERT(vscr_ratchet_rng_is_implemented(rng));

    ratchet_session_ctx->rng = rng;
}

//
//  Release dependency to the interface 'ratchet rng'.
//
VSCR_PUBLIC void
vscr_ratchet_session_release_rng(vscr_ratchet_session_t *ratchet_session_ctx) {

    VSCR_ASSERT_PTR(ratchet_session_ctx);

    vscr_impl_destroy(&ratchet_session_ctx->rng);
}

//
//  Setup dependency to the class 'ratchet' with shared ownership.
//
VSCR_PUBLIC void
vscr_ratchet_session_use_ratchet(vscr_ratchet_session_t *ratchet_session_ctx, vscr_ratchet_t *ratchet) {

    VSCR_ASSERT_PTR(ratchet_session_ctx);
    VSCR_ASSERT_PTR(ratchet);
    VSCR_ASSERT_PTR(ratchet_session_ctx->ratchet == NULL);

    ratchet_session_ctx->ratchet = vscr_ratchet_copy(ratchet);
}

//
//  Setup dependency to the class 'ratchet' and transfer ownership.
//  Note, transfer ownership does not mean that object is uniquely owned by the target object.
//
VSCR_PUBLIC void
vscr_ratchet_session_take_ratchet(vscr_ratchet_session_t *ratchet_session_ctx, vscr_ratchet_t *ratchet) {

    VSCR_ASSERT_PTR(ratchet_session_ctx);
    VSCR_ASSERT_PTR(ratchet);
    VSCR_ASSERT_PTR(ratchet_session_ctx->ratchet == NULL);

    ratchet_session_ctx->ratchet = ratchet;
}

//
//  Release dependency to the class 'ratchet'.
//
VSCR_PUBLIC void
vscr_ratchet_session_release_ratchet(vscr_ratchet_session_t *ratchet_session_ctx) {

    VSCR_ASSERT_PTR(ratchet_session_ctx);

    vscr_ratchet_destroy(&ratchet_session_ctx->ratchet);
}


// --------------------------------------------------------------------------
//  Generated section end.
// clang-format on
// --------------------------------------------------------------------------
//  @end


//
//  Perform context specific initialization.
//  Note, this method is called automatically when method vscr_ratchet_session_init() is called.
//  Note, that context is already zeroed.
//
static void
vscr_ratchet_session_init_ctx(vscr_ratchet_session_t *ratchet_session_ctx) {

    VSCR_ASSERT_PTR(ratchet_session_ctx);

    // TODO: Proper initialization
    ratchet_session_ctx->ratchet = vscr_ratchet_new();
}

//
//  Release all inner resources.
//  Note, this method is called automatically once when class is completely cleaning up.
//  Note, that context will be zeroed automatically next this method.
//
static void
vscr_ratchet_session_cleanup_ctx(vscr_ratchet_session_t *ratchet_session_ctx) {

    VSCR_ASSERT_PTR(ratchet_session_ctx);

    vscr_ratchet_destroy(&ratchet_session_ctx->ratchet);
    vscr_impl_destroy(&ratchet_session_ctx->rng);
}

VSCR_PUBLIC void
vscr_ratchet_session_initiate(vscr_ratchet_session_t *ratchet_session_ctx, vsc_buffer_t *sender_identity_private_key,
        vsc_buffer_t *receiver_identity_public_key, vsc_buffer_t *receiver_long_term_public_key,
        vsc_buffer_t *receiver_one_time_public_key) {

    VSCR_ASSERT_PTR(ratchet_session_ctx);
    VSCR_ASSERT_PTR(sender_identity_private_key);
    VSCR_ASSERT_PTR(receiver_identity_public_key);
    VSCR_ASSERT_PTR(receiver_long_term_public_key);

    VSCR_ASSERT(vsc_buffer_len(sender_identity_private_key) == ED25519_KEY_LEN);
    VSCR_ASSERT(vsc_buffer_len(receiver_identity_public_key) == ED25519_KEY_LEN);
    VSCR_ASSERT(vsc_buffer_len(receiver_long_term_public_key) == ED25519_KEY_LEN);

    size_t shared_secret_count = 3;
    if (receiver_one_time_public_key) {
        VSCR_ASSERT(vsc_buffer_len(receiver_one_time_public_key) == ED25519_KEY_LEN);
        shared_secret_count = 4;
    }

    vsc_buffer_t *ephemeral_private_key = vsc_buffer_new_with_capacity(ED25519_KEY_LEN);
    vscr_ratchet_rng_generate_random_data(ratchet_session_ctx->rng, ED25519_KEY_LEN, ephemeral_private_key);;

    vsc_buffer_t *shared_secret = vsc_buffer_new_with_capacity(shared_secret_count * ED25519_KEY_LEN);
    curve25519_key_exchange(vsc_buffer_ptr(shared_secret),
                            vsc_buffer_bytes(receiver_long_term_public_key),
                            vsc_buffer_bytes(sender_identity_private_key));
    vsc_buffer_reserve(shared_secret, ED25519_KEY_LEN);

    curve25519_key_exchange(vsc_buffer_ptr(shared_secret),
                            vsc_buffer_bytes(receiver_identity_public_key),
                            vsc_buffer_bytes(ephemeral_private_key));
    vsc_buffer_reserve(shared_secret, ED25519_KEY_LEN);

    curve25519_key_exchange(vsc_buffer_ptr(shared_secret),
                            vsc_buffer_bytes(receiver_long_term_public_key),
                            vsc_buffer_bytes(ephemeral_private_key));
    vsc_buffer_reserve(shared_secret, ED25519_KEY_LEN);

    if (receiver_one_time_public_key) {
        curve25519_key_exchange(vsc_buffer_ptr(shared_secret),
                                vsc_buffer_bytes(receiver_one_time_public_key),
                                vsc_buffer_bytes(ephemeral_private_key));
        vsc_buffer_reserve(shared_secret, ED25519_KEY_LEN);
    }

    vscr_ratchet_initiate(ratchet_session_ctx->ratchet, vsc_buffer_data(shared_secret), ephemeral_private_key);

    vsc_buffer_erase(shared_secret);
    vsc_buffer_destroy(&shared_secret);
    vsc_buffer_destroy(&ephemeral_private_key);
}

VSCR_PUBLIC void
vscr_ratchet_session_respond(vscr_ratchet_session_t *ratchet_session_ctx, vsc_buffer_t *sender_identity_public_key,
        vsc_buffer_t *receiver_identity_private_key, vsc_buffer_t *receiver_long_term_public_key,
        vsc_buffer_t *receiver_one_time_public_key) {

    VSCR_UNUSED(ratchet_session_ctx);
    VSCR_UNUSED(sender_identity_public_key);
    VSCR_UNUSED(receiver_identity_private_key);
    VSCR_UNUSED(receiver_long_term_public_key);
    VSCR_UNUSED(receiver_one_time_public_key);
    //  TODO: This is STUB. Implement me.
}
