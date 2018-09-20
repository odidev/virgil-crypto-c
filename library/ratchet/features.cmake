#   @license
#   -------------------------------------------------------------------------
#   Copyright (C) 2015-2018 Virgil Security Inc.
#
#   All rights reserved.
#
#   Redistribution and use in source and binary forms, with or without
#   modification, are permitted provided that the following conditions are
#   met:
#
#       (1) Redistributions of source code must retain the above copyright
#       notice, this list of conditions and the following disclaimer.
#
#       (2) Redistributions in binary form must reproduce the above copyright
#       notice, this list of conditions and the following disclaimer in
#       the documentation and/or other materials provided with the
#       distribution.
#
#       (3) Neither the name of the copyright holder nor the names of its
#       contributors may be used to endorse or promote products derived from
#       this software without specific prior written permission.
#
#   THIS SOFTWARE IS PROVIDED BY THE AUTHOR ''AS IS'' AND ANY EXPRESS OR
#   IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
#   WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
#   DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
#   INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
#   (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
#   SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
#   HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
#   STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
#   IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
#   POSSIBILITY OF SUCH DAMAGE.
#
#   Lead Maintainer: Virgil Security Inc. <support@virgilsecurity.com>
#   -------------------------------------------------------------------------

#   @warning
#   -------------------------------------------------------------------------
#   This file is fully generated by script 'cmake_files_codegen.gsl'.
#   It can be changed temporary for debug purposes only.
#   -------------------------------------------------------------------------
#   @end


include_guard()

option(VSCR_RATCHET_RNG "Enable interface 'ratchet rng'." ON)
option(VSCR_VIRGIL_RATCHET_FAKE_RNG "Enable implementation 'virgil ratchet fake rng'." ON)
option(VSCR_RATCHET_COMMON "Enable class 'ratchet common'." ON)
option(VSCR_ERROR_CTX "Enable class 'error ctx'." ON)
option(VSCR_RATCHET_CIPHER "Enable class 'ratchet cipher'." ON)
option(VSCR_RATCHET_CHAIN_KEY "Enable class 'ratchet chain key'." ON)
option(VSCR_RATCHET_MESSAGE_KEY "Enable class 'ratchet message key'." ON)
option(VSCR_RATCHET_KDF_INFO "Enable class 'ratchet kdf info'." ON)
option(VSCR_RATCHET_RECEIVER_CHAIN "Enable class 'ratchet receiver chain'." ON)
option(VSCR_RATCHET_RECEIVER_CHAIN_LIST_NODE "Enable class 'ratchet receiver chain list node'." ON)
option(VSCR_RATCHET_SKIPPED_MESSAGE_KEY "Enable class 'ratchet skipped message key'." ON)
option(VSCR_RATCHET_SKIPPED_MESSAGE_KEY_LIST_NODE "Enable class 'ratchet skipped message key list node'." ON)
option(VSCR_RATCHET_SENDER_CHAIN "Enable class 'ratchet sender chain'." ON)
option(VSCR_RATCHET_MESSAGE "Enable class 'ratchet message'." ON)
option(VSCR_RATCHET "Enable class 'ratchet'." ON)
option(VSCR_RATCHET_SESSION "Enable class 'ratchet session'." ON)
mark_as_advanced(
        VSCR_RATCHET_RNG
        VSCR_VIRGIL_RATCHET_FAKE_RNG
        VSCR_RATCHET_COMMON
        VSCR_ERROR_CTX
        VSCR_RATCHET_CIPHER
        VSCR_RATCHET_CHAIN_KEY
        VSCR_RATCHET_MESSAGE_KEY
        VSCR_RATCHET_KDF_INFO
        VSCR_RATCHET_RECEIVER_CHAIN
        VSCR_RATCHET_RECEIVER_CHAIN_LIST_NODE
        VSCR_RATCHET_SKIPPED_MESSAGE_KEY
        VSCR_RATCHET_SKIPPED_MESSAGE_KEY_LIST_NODE
        VSCR_RATCHET_SENDER_CHAIN
        VSCR_RATCHET_MESSAGE
        VSCR_RATCHET
        VSCR_RATCHET_SESSION
        )

if(VSCR_RATCHET_CHAIN_KEY AND NOT VSCR_RATCHET_COMMON)
    message("-- error --")
    message("--")
    message("Feature VSCR_RATCHET_CHAIN_KEY depends on the feature:")
    message("     VSCR_RATCHET_COMMON - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCR_RATCHET_MESSAGE_KEY AND NOT VSCR_RATCHET_COMMON)
    message("-- error --")
    message("--")
    message("Feature VSCR_RATCHET_MESSAGE_KEY depends on the feature:")
    message("     VSCR_RATCHET_COMMON - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCR_RATCHET_RECEIVER_CHAIN_LIST_NODE AND NOT VSCR_RATCHET_RECEIVER_CHAIN)
    message("-- error --")
    message("--")
    message("Feature VSCR_RATCHET_RECEIVER_CHAIN_LIST_NODE depends on the feature:")
    message("     VSCR_RATCHET_RECEIVER_CHAIN - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCR_RATCHET_SKIPPED_MESSAGE_KEY_LIST_NODE AND NOT VSCR_RATCHET_SKIPPED_MESSAGE_KEY_LIST_NODE)
    message("-- error --")
    message("--")
    message("Feature VSCR_RATCHET_SKIPPED_MESSAGE_KEY_LIST_NODE depends on the feature:")
    message("     VSCR_RATCHET_SKIPPED_MESSAGE_KEY_LIST_NODE - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCR_RATCHET AND NOT VSCR_RATCHET_COMMON)
    message("-- error --")
    message("--")
    message("Feature VSCR_RATCHET depends on the feature:")
    message("     VSCR_RATCHET_COMMON - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCR_RATCHET AND NOT VSCR_RATCHET_MESSAGE)
    message("-- error --")
    message("--")
    message("Feature VSCR_RATCHET depends on the feature:")
    message("     VSCR_RATCHET_MESSAGE - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCR_RATCHET AND NOT VSCR_RATCHET_MESSAGE_KEY)
    message("-- error --")
    message("--")
    message("Feature VSCR_RATCHET depends on the feature:")
    message("     VSCR_RATCHET_MESSAGE_KEY - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCR_RATCHET AND NOT VSCR_RATCHET_CHAIN_KEY)
    message("-- error --")
    message("--")
    message("Feature VSCR_RATCHET depends on the feature:")
    message("     VSCR_RATCHET_CHAIN_KEY - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()
