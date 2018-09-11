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


include_guard()

option(ED25519_REF10 "Using REF10 implementation of ed25519." ON)

option(ED25519_AMD64_RADIX_64_24K
           "Using radix 2^64 and a 24KB precomputed table optimization for ed25519 curves on the x86_64 processor." OFF
           )

option(ED25519_AMD64_RADIX_51_30K
           "Using radix 2^51 and a 30KB precomputed table optimization for ed25519 curves on the x86_64 processor." OFF
           )

mark_as_advanced(
        ED25519_REF10
        ED25519_AMD64_RADIX_64_24K
        ED25519_AMD64_RADIX_51_30K
        )


if(NOT ED25519_REF10 AND NOT ED25519_AMD64_RADIX_64_24K AND NOT ED25519_AMD64_RADIX_51_30K)
    message("-- error --")
    message("--")
    message("All features are disabled. Require one of the features to be enabled:")
    message("     ED25519_REF10, ED25519_AMD64_RADIX_64_24K, ED25519_AMD64_RADIX_51_30K.")
    message("--")
    message(FATAL_ERROR)
endif()


if(ED25519_REF10 AND ED25519_AMD64_RADIX_64_24K)
    message("-- error --")
    message("--")
    message("Feature ED25519_REF10 is enabled and alternative feature:")
    message("     ED25519_AMD64_RADIX_64_24K is enabled too.")
    message("--")
    message(FATAL_ERROR)
endif()


if(ED25519_REF10 AND ED25519_AMD64_RADIX_51_30K)
    message("-- error --")
    message("--")
    message("Feature ED25519_REF10 is enabled and alternative feature:")
    message("     ED25519_AMD64_RADIX_51_30K is enabled too.")
    message("--")
    message(FATAL_ERROR)
endif()


if(ED25519_AMD64_RADIX_64_24K AND ED25519_AMD64_RADIX_51_30K)
    message("-- error --")
    message("--")
    message("Feature ED25519_AMD64_RADIX_64_24K is enabled and alternative feature:")
    message("     ED25519_AMD64_RADIX_51_30K is enabled too.")
    message("--")
    message(FATAL_ERROR)
endif()
