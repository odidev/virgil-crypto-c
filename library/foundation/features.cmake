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

option(VSCF_CIPHER "Enable interface 'cipher'." ON)
option(VSCF_AUTH_ENCRYPT "Enable interface 'auth encrypt'." ON)
option(VSCF_AUTH_DECRYPT "Enable interface 'auth decrypt'." ON)
option(VSCF_CIPHER_AUTH "Enable interface 'cipher auth'." ON)
option(VSCF_CIPHER_AUTH_INFO "Enable interface 'cipher auth info'." ON)
option(VSCF_CIPHER_INFO "Enable interface 'cipher info'." ON)
option(VSCF_DECRYPT "Enable interface 'decrypt'." ON)
option(VSCF_ENCRYPT "Enable interface 'encrypt'." ON)
option(VSCF_EX_KDF "Enable interface 'ex kdf'." ON)
option(VSCF_HASH "Enable interface 'hash'." ON)
option(VSCF_HASH_INFO "Enable interface 'hash info'." ON)
option(VSCF_HASH_STREAM "Enable interface 'hash stream'." ON)
option(VSCF_MAC "Enable interface 'mac'." ON)
option(VSCF_MAC_INFO "Enable interface 'mac info'." ON)
option(VSCF_MAC_STREAM "Enable interface 'mac stream'." ON)
option(VSCF_KDF "Enable interface 'kdf'." ON)
option(VSCF_RANDOM "Enable interface 'random'." ON)
option(VSCF_ERROR_CONTEXT "Enable interface 'error context'." ON)
option(VSCF_KEY "Enable interface 'key'." ON)
option(VSCF_PUBLIC_KEY "Enable interface 'public key'." ON)
option(VSCF_PRIVATE_KEY "Enable interface 'private key'." ON)
option(VSCF_SIGN "Enable interface 'sign'." ON)
option(VSCF_VERIFY "Enable interface 'verify'." ON)
option(VSCF_GENERATE_KEY "Enable interface 'generate key'." ON)
option(VSCF_COMPUTE_SHARED_KEY "Enable interface 'compute shared key'." ON)
option(VSCF_EXPORT_PUBLIC_KEY "Enable interface 'export public key'." ON)
option(VSCF_EXPORT_PRIVATE_KEY "Enable interface 'export private key'." ON)
option(VSCF_IMPORT_PUBLIC_KEY "Enable interface 'import public key'." ON)
option(VSCF_IMPORT_PRIVATE_KEY "Enable interface 'import private key'." ON)
option(VSCF_KEY_READER "Enable interface 'key reader'." ON)
option(VSCF_KEY_WRITER "Enable interface 'key writer'." ON)
option(VSCF_ASN1_READER "Enable interface 'asn1 reader'." ON)
option(VSCF_ASN1_WRITER "Enable interface 'asn1 writer'." ON)
option(VSCF_SHA224 "Enable implementation 'sha224'." ON)
option(VSCF_SHA256 "Enable implementation 'sha256'." ON)
option(VSCF_SHA384 "Enable implementation 'sha384'." ON)
option(VSCF_SHA512 "Enable implementation 'sha512'." ON)
option(VSCF_AES256_GCM "Enable implementation 'aes256 gcm'." ON)
option(VSCF_ASN1RD "Enable implementation 'asn1rd'." ON)
option(VSCF_ASN1WR "Enable implementation 'asn1wr'." ON)
option(VSCF_RSA_PUBLIC_KEY "Enable implementation 'rsa public key'." ON)
option(VSCF_RSA_PRIVATE_KEY "Enable implementation 'rsa private key'." ON)
option(VSCF_HMAC "Enable implementation 'hmac'." ON)
option(VSCF_HKDF "Enable implementation 'hkdf'." ON)
option(VSCF_KDF1 "Enable implementation 'kdf1'." ON)
option(VSCF_KDF2 "Enable implementation 'kdf2'." ON)
option(VSCF_FAKE_RANDOM "Enable implementation 'fake random'." ON)
option(VSCF_ERROR_CTX "Enable class 'error ctx'." ON)
option(VSCF_MBEDTLS_BIGNUM_ASN1_WRITER "Enable class 'mbedtls bignum asn1 writer'." ON)
option(VSCF_MBEDTLS_BIGNUM_ASN1_READER "Enable class 'mbedtls bignum asn1 reader'." ON)
option(VSCF_MBEDTLS_MD "Enable class 'mbedtls md'." ON)
mark_as_advanced(
        VSCF_CIPHER
        VSCF_AUTH_ENCRYPT
        VSCF_AUTH_DECRYPT
        VSCF_CIPHER_AUTH
        VSCF_CIPHER_AUTH_INFO
        VSCF_CIPHER_INFO
        VSCF_DECRYPT
        VSCF_ENCRYPT
        VSCF_EX_KDF
        VSCF_HASH
        VSCF_HASH_INFO
        VSCF_HASH_STREAM
        VSCF_MAC
        VSCF_MAC_INFO
        VSCF_MAC_STREAM
        VSCF_KDF
        VSCF_RANDOM
        VSCF_ERROR_CONTEXT
        VSCF_KEY
        VSCF_PUBLIC_KEY
        VSCF_PRIVATE_KEY
        VSCF_SIGN
        VSCF_VERIFY
        VSCF_GENERATE_KEY
        VSCF_COMPUTE_SHARED_KEY
        VSCF_EXPORT_PUBLIC_KEY
        VSCF_EXPORT_PRIVATE_KEY
        VSCF_IMPORT_PUBLIC_KEY
        VSCF_IMPORT_PRIVATE_KEY
        VSCF_KEY_READER
        VSCF_KEY_WRITER
        VSCF_ASN1_READER
        VSCF_ASN1_WRITER
        VSCF_SHA224
        VSCF_SHA256
        VSCF_SHA384
        VSCF_SHA512
        VSCF_AES256_GCM
        VSCF_ASN1RD
        VSCF_ASN1WR
        VSCF_RSA_PUBLIC_KEY
        VSCF_RSA_PRIVATE_KEY
        VSCF_HMAC
        VSCF_HKDF
        VSCF_KDF1
        VSCF_KDF2
        VSCF_FAKE_RANDOM
        VSCF_ERROR_CTX
        VSCF_MBEDTLS_BIGNUM_ASN1_WRITER
        VSCF_MBEDTLS_BIGNUM_ASN1_READER
        VSCF_MBEDTLS_MD
        )

if(VSCF_CIPHER AND NOT VSCF_ENCRYPT)
    message("-- error --")
    message("--")
    message("Feature VSCF_CIPHER depends on the feature:")
    message("     VSCF_ENCRYPT - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_CIPHER AND NOT VSCF_DECRYPT)
    message("-- error --")
    message("--")
    message("Feature VSCF_CIPHER depends on the feature:")
    message("     VSCF_DECRYPT - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_CIPHER AND NOT VSCF_CIPHER_INFO)
    message("-- error --")
    message("--")
    message("Feature VSCF_CIPHER depends on the feature:")
    message("     VSCF_CIPHER_INFO - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_CIPHER_AUTH AND NOT VSCF_CIPHER_AUTH_INFO)
    message("-- error --")
    message("--")
    message("Feature VSCF_CIPHER_AUTH depends on the feature:")
    message("     VSCF_CIPHER_AUTH_INFO - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_CIPHER_AUTH AND NOT VSCF_AUTH_ENCRYPT)
    message("-- error --")
    message("--")
    message("Feature VSCF_CIPHER_AUTH depends on the feature:")
    message("     VSCF_AUTH_ENCRYPT - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_CIPHER_AUTH AND NOT VSCF_AUTH_DECRYPT)
    message("-- error --")
    message("--")
    message("Feature VSCF_CIPHER_AUTH depends on the feature:")
    message("     VSCF_AUTH_DECRYPT - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_HASH AND NOT VSCF_HASH_INFO)
    message("-- error --")
    message("--")
    message("Feature VSCF_HASH depends on the feature:")
    message("     VSCF_HASH_INFO - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_HASH_STREAM AND NOT VSCF_HASH_INFO)
    message("-- error --")
    message("--")
    message("Feature VSCF_HASH_STREAM depends on the feature:")
    message("     VSCF_HASH_INFO - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_MAC AND NOT VSCF_MAC_INFO)
    message("-- error --")
    message("--")
    message("Feature VSCF_MAC depends on the feature:")
    message("     VSCF_MAC_INFO - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_MAC_STREAM AND NOT VSCF_MAC_INFO)
    message("-- error --")
    message("--")
    message("Feature VSCF_MAC_STREAM depends on the feature:")
    message("     VSCF_MAC_INFO - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_PUBLIC_KEY AND NOT VSCF_KEY)
    message("-- error --")
    message("--")
    message("Feature VSCF_PUBLIC_KEY depends on the feature:")
    message("     VSCF_KEY - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_PRIVATE_KEY AND NOT VSCF_KEY)
    message("-- error --")
    message("--")
    message("Feature VSCF_PRIVATE_KEY depends on the feature:")
    message("     VSCF_KEY - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_KEY_READER AND NOT VSCF_ERROR_CONTEXT)
    message("-- error --")
    message("--")
    message("Feature VSCF_KEY_READER depends on the feature:")
    message("     VSCF_ERROR_CONTEXT - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_SHA224 AND NOT MBEDTLS_SHA256_C)
    message("-- error --")
    message("--")
    message("Feature VSCF_SHA224 depends on the feature:")
    message("     MBEDTLS_SHA256_C - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_SHA256 AND NOT MBEDTLS_SHA256_C)
    message("-- error --")
    message("--")
    message("Feature VSCF_SHA256 depends on the feature:")
    message("     MBEDTLS_SHA256_C - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_SHA384 AND NOT MBEDTLS_SHA512_C)
    message("-- error --")
    message("--")
    message("Feature VSCF_SHA384 depends on the feature:")
    message("     MBEDTLS_SHA512_C - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_SHA512 AND NOT MBEDTLS_SHA512_C)
    message("-- error --")
    message("--")
    message("Feature VSCF_SHA512 depends on the feature:")
    message("     MBEDTLS_SHA512_C - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_AES256_GCM AND NOT MBEDTLS_CIPHER_C)
    message("-- error --")
    message("--")
    message("Feature VSCF_AES256_GCM depends on the feature:")
    message("     MBEDTLS_CIPHER_C - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_ASN1RD AND NOT MBEDTLS_ASN1_PARSE_C)
    message("-- error --")
    message("--")
    message("Feature VSCF_ASN1RD depends on the feature:")
    message("     MBEDTLS_ASN1_PARSE_C - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_ASN1WR AND NOT MBEDTLS_ASN1_WRITE_C)
    message("-- error --")
    message("--")
    message("Feature VSCF_ASN1WR depends on the feature:")
    message("     MBEDTLS_ASN1_WRITE_C - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_RSA_PUBLIC_KEY AND NOT MBEDTLS_RSA_C)
    message("-- error --")
    message("--")
    message("Feature VSCF_RSA_PUBLIC_KEY depends on the feature:")
    message("     MBEDTLS_RSA_C - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_RSA_PUBLIC_KEY AND NOT MBEDTLS_BIGNUM_C)
    message("-- error --")
    message("--")
    message("Feature VSCF_RSA_PUBLIC_KEY depends on the feature:")
    message("     MBEDTLS_BIGNUM_C - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_RSA_PUBLIC_KEY AND NOT MBEDTLS_PKCS1_V21)
    message("-- error --")
    message("--")
    message("Feature VSCF_RSA_PUBLIC_KEY depends on the feature:")
    message("     MBEDTLS_PKCS1_V21 - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_RSA_PUBLIC_KEY AND NOT VSCF_MBEDTLS_BIGNUM_ASN1_WRITER)
    message("-- error --")
    message("--")
    message("Feature VSCF_RSA_PUBLIC_KEY depends on the feature:")
    message("     VSCF_MBEDTLS_BIGNUM_ASN1_WRITER - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_RSA_PUBLIC_KEY AND NOT VSCF_MBEDTLS_BIGNUM_ASN1_READER)
    message("-- error --")
    message("--")
    message("Feature VSCF_RSA_PUBLIC_KEY depends on the feature:")
    message("     VSCF_MBEDTLS_BIGNUM_ASN1_READER - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_RSA_PUBLIC_KEY AND NOT VSCF_MBEDTLS_MD)
    message("-- error --")
    message("--")
    message("Feature VSCF_RSA_PUBLIC_KEY depends on the feature:")
    message("     VSCF_MBEDTLS_MD - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_RSA_PUBLIC_KEY AND NOT VSCF_HASH)
    message("-- error --")
    message("--")
    message("Feature VSCF_RSA_PUBLIC_KEY depends on the feature:")
    message("     VSCF_HASH - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_RSA_PUBLIC_KEY AND NOT VSCF_RANDOM)
    message("-- error --")
    message("--")
    message("Feature VSCF_RSA_PUBLIC_KEY depends on the feature:")
    message("     VSCF_RANDOM - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_RSA_PUBLIC_KEY AND NOT VSCF_ASN1_READER)
    message("-- error --")
    message("--")
    message("Feature VSCF_RSA_PUBLIC_KEY depends on the feature:")
    message("     VSCF_ASN1_READER - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_RSA_PUBLIC_KEY AND NOT VSCF_ASN1_WRITER)
    message("-- error --")
    message("--")
    message("Feature VSCF_RSA_PUBLIC_KEY depends on the feature:")
    message("     VSCF_ASN1_WRITER - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_RSA_PRIVATE_KEY AND NOT MBEDTLS_RSA_C)
    message("-- error --")
    message("--")
    message("Feature VSCF_RSA_PRIVATE_KEY depends on the feature:")
    message("     MBEDTLS_RSA_C - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_RSA_PRIVATE_KEY AND NOT MBEDTLS_BIGNUM_C)
    message("-- error --")
    message("--")
    message("Feature VSCF_RSA_PRIVATE_KEY depends on the feature:")
    message("     MBEDTLS_BIGNUM_C - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_RSA_PRIVATE_KEY AND NOT MBEDTLS_PKCS1_V21)
    message("-- error --")
    message("--")
    message("Feature VSCF_RSA_PRIVATE_KEY depends on the feature:")
    message("     MBEDTLS_PKCS1_V21 - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_RSA_PRIVATE_KEY AND NOT VSCF_MBEDTLS_BIGNUM_ASN1_WRITER)
    message("-- error --")
    message("--")
    message("Feature VSCF_RSA_PRIVATE_KEY depends on the feature:")
    message("     VSCF_MBEDTLS_BIGNUM_ASN1_WRITER - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_RSA_PRIVATE_KEY AND NOT VSCF_MBEDTLS_BIGNUM_ASN1_READER)
    message("-- error --")
    message("--")
    message("Feature VSCF_RSA_PRIVATE_KEY depends on the feature:")
    message("     VSCF_MBEDTLS_BIGNUM_ASN1_READER - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_RSA_PRIVATE_KEY AND NOT VSCF_MBEDTLS_MD)
    message("-- error --")
    message("--")
    message("Feature VSCF_RSA_PRIVATE_KEY depends on the feature:")
    message("     VSCF_MBEDTLS_MD - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_RSA_PRIVATE_KEY AND NOT VSCF_HASH)
    message("-- error --")
    message("--")
    message("Feature VSCF_RSA_PRIVATE_KEY depends on the feature:")
    message("     VSCF_HASH - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_RSA_PRIVATE_KEY AND NOT VSCF_RANDOM)
    message("-- error --")
    message("--")
    message("Feature VSCF_RSA_PRIVATE_KEY depends on the feature:")
    message("     VSCF_RANDOM - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_RSA_PRIVATE_KEY AND NOT VSCF_ASN1_READER)
    message("-- error --")
    message("--")
    message("Feature VSCF_RSA_PRIVATE_KEY depends on the feature:")
    message("     VSCF_ASN1_READER - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_RSA_PRIVATE_KEY AND NOT VSCF_ASN1_WRITER)
    message("-- error --")
    message("--")
    message("Feature VSCF_RSA_PRIVATE_KEY depends on the feature:")
    message("     VSCF_ASN1_WRITER - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_HMAC AND NOT VSCF_HASH_STREAM)
    message("-- error --")
    message("--")
    message("Feature VSCF_HMAC depends on the feature:")
    message("     VSCF_HASH_STREAM - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_HKDF AND NOT VSCF_HASH_STREAM)
    message("-- error --")
    message("--")
    message("Feature VSCF_HKDF depends on the feature:")
    message("     VSCF_HASH_STREAM - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_KDF1 AND NOT VSCF_HASH_STREAM)
    message("-- error --")
    message("--")
    message("Feature VSCF_KDF1 depends on the feature:")
    message("     VSCF_HASH_STREAM - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_KDF2 AND NOT VSCF_HASH_STREAM)
    message("-- error --")
    message("--")
    message("Feature VSCF_KDF2 depends on the feature:")
    message("     VSCF_HASH_STREAM - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_MBEDTLS_BIGNUM_ASN1_WRITER AND NOT MBEDTLS_BIGNUM_C)
    message("-- error --")
    message("--")
    message("Feature VSCF_MBEDTLS_BIGNUM_ASN1_WRITER depends on the feature:")
    message("     MBEDTLS_BIGNUM_C - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_MBEDTLS_BIGNUM_ASN1_WRITER AND NOT VSCF_ASN1_WRITER)
    message("-- error --")
    message("--")
    message("Feature VSCF_MBEDTLS_BIGNUM_ASN1_WRITER depends on the feature:")
    message("     VSCF_ASN1_WRITER - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_MBEDTLS_BIGNUM_ASN1_READER AND NOT MBEDTLS_BIGNUM_C)
    message("-- error --")
    message("--")
    message("Feature VSCF_MBEDTLS_BIGNUM_ASN1_READER depends on the feature:")
    message("     MBEDTLS_BIGNUM_C - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()

if(VSCF_MBEDTLS_BIGNUM_ASN1_READER AND NOT VSCF_ASN1_READER)
    message("-- error --")
    message("--")
    message("Feature VSCF_MBEDTLS_BIGNUM_ASN1_READER depends on the feature:")
    message("     VSCF_ASN1_READER - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()
