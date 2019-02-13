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

#include "test_data_ratchet_key_utils.h"

const byte test_ratchet_curve_private_key_BYTES[] = {
        0x30, 0x2e, 0x02, 0x01, 0x00, 0x30, 0x05, 0x06,
        0x03, 0x2b, 0x65, 0x6e, 0x04, 0x22, 0x04, 0x20,
        0x4e, 0x15, 0x36, 0x42, 0x4a, 0x84, 0xf3, 0xd8,
        0x3c, 0x26, 0x01, 0x3e, 0x3c, 0x12, 0xb7, 0x14,
        0x0e, 0x76, 0x9d, 0x87, 0x44, 0x0a, 0x44, 0xa6,
        0xf5, 0x0f, 0xed, 0x0d, 0x84, 0x3d, 0x36, 0x92,
};

const byte test_ratchet_curve_public_key_BYTES[] = {
        0x30, 0x2a, 0x30, 0x05, 0x06, 0x03, 0x2b, 0x65,
        0x6e, 0x03, 0x21, 0x00, 0xa9, 0xa2, 0x6e, 0x9d,
        0x40, 0x9d, 0x22, 0xbf, 0x6d, 0x71, 0x1b, 0x7a,
        0x10, 0x1d, 0x00, 0xbe, 0xcf, 0x87, 0x6a, 0x9c,
        0xc7, 0x51, 0x14, 0x24, 0x05, 0xcf, 0xf8, 0x4b,
        0x69, 0x09, 0x73, 0x3b,
};

const byte test_ratchet_curve_public_key_raw_BYTES[] = {
        0xa9, 0xa2, 0x6e, 0x9d, 0x40, 0x9d, 0x22, 0xbf,
        0x6d, 0x71, 0x1b, 0x7a, 0x10, 0x1d, 0x00, 0xbe,
        0xcf, 0x87, 0x6a, 0x9c, 0xc7, 0x51, 0x14, 0x24,
        0x05, 0xcf, 0xf8, 0x4b, 0x69, 0x09, 0x73, 0x3b,
};

const byte test_ratchet_curve_public_key_id_BYTES[] = {
        0xe4, 0x10, 0x5f, 0x84, 0x70, 0xbb, 0xad, 0xe4,
};

const byte test_ratchet_ed_private_key_BYTES[] = {
        0x30, 0x2e, 0x02, 0x01, 0x00, 0x30, 0x05, 0x06,
        0x03, 0x2b, 0x65, 0x70, 0x04, 0x22, 0x04, 0x20,
        0xb9, 0xc0, 0x4c, 0xd8, 0x84, 0x5b, 0x33, 0x7a,
        0xf3, 0xc9, 0xe0, 0x64, 0x24, 0xdc, 0x8f, 0x84,
        0x4f, 0x08, 0x10, 0x9d, 0xf8, 0x1f, 0xc0, 0x2d,
        0xc1, 0x7e, 0x9f, 0x9d, 0x0d, 0x48, 0xed, 0x84,
};

const byte test_ratchet_ed_public_key_BYTES[] = {
        0x30, 0x2a, 0x30, 0x05, 0x06, 0x03, 0x2b, 0x65,
        0x70, 0x03, 0x21, 0x00, 0x7c, 0xe2, 0x93, 0x8c,
        0x78, 0xe4, 0x67, 0xc2, 0x88, 0x97, 0x9e, 0x01,
        0xc2, 0x7f, 0xd5, 0x46, 0x9b, 0x14, 0xb1, 0xda,
        0x6c, 0x01, 0x38, 0x5b, 0x13, 0xd4, 0x08, 0x55,
        0x6c, 0xed, 0xbf, 0xce
};

const vsc_data_t test_ratchet_curve_private_key = {
        test_ratchet_curve_private_key_BYTES, sizeof(test_ratchet_curve_private_key_BYTES)
};

const vsc_data_t test_ratchet_curve_public_key = {
        test_ratchet_curve_public_key_BYTES, sizeof(test_ratchet_curve_public_key_BYTES)
};

const vsc_data_t test_ratchet_curve_public_key_raw = {
        test_ratchet_curve_public_key_raw_BYTES, sizeof(test_ratchet_curve_public_key_raw_BYTES)
};

const vsc_data_t test_ratchet_curve_public_key_id = {
        test_ratchet_curve_public_key_id_BYTES, sizeof(test_ratchet_curve_public_key_id_BYTES)
};

const vsc_data_t test_ratchet_ed_private_key = {
        test_ratchet_ed_private_key_BYTES, sizeof(test_ratchet_ed_private_key_BYTES)
};

const vsc_data_t test_ratchet_ed_public_key = {
        test_ratchet_ed_public_key_BYTES, sizeof(test_ratchet_ed_public_key_BYTES)
};