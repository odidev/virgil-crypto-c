#   @license
#   -------------------------------------------------------------------------
#   Copyright (C) 2015-2020 Virgil Security, Inc.
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

if(NOT TARGET pythia_sdk)
    message(FATAL_ERROR "Expected target 'pythia_sdk' to be defined first.")
endif()

include(CheckIncludeFiles)
check_include_files(assert.h VSSP_HAVE_ASSERT_H)
check_include_files(stdatomic.h VSSP_HAVE_STDATOMIC_H)

configure_file(
        "${CMAKE_CURRENT_LIST_DIR}/include/virgil/sdk/pythia/vssp_platform.h.in"
        "${CMAKE_CURRENT_BINARY_DIR}/include/virgil/sdk/pythia/vssp_platform.h"
        )

set_property(
    SOURCE "${CMAKE_CURRENT_LIST_DIR}/include/virgil/sdk/pythia/vssp_assert.h"
    PROPERTY MACOSX_PACKAGE_LOCATION "Headers"
)

set_property(
    SOURCE "${CMAKE_CURRENT_LIST_DIR}/include/virgil/sdk/pythia/vssp_library.h"
    PROPERTY MACOSX_PACKAGE_LOCATION "Headers"
)

set_property(
    SOURCE "${CMAKE_CURRENT_LIST_DIR}/include/virgil/sdk/pythia/vssp_memory.h"
    PROPERTY MACOSX_PACKAGE_LOCATION "Headers"
)

set_property(
    SOURCE "${CMAKE_CURRENT_BINARY_DIR}/include/virgil/sdk/pythia/vssp_platform.h"
    PROPERTY MACOSX_PACKAGE_LOCATION "Headers"
)

set_property(
    SOURCE "${CMAKE_CURRENT_LIST_DIR}/include/virgil/sdk/pythia/vssp_brain_key_seed.h"
    PROPERTY MACOSX_PACKAGE_LOCATION "Headers"
)

set_property(
    SOURCE "${CMAKE_CURRENT_LIST_DIR}/include/virgil/sdk/pythia/vssp_error.h"
    PROPERTY MACOSX_PACKAGE_LOCATION "Headers"
)

set_property(
    SOURCE "${CMAKE_CURRENT_LIST_DIR}/include/virgil/sdk/pythia/vssp_pythia_client.h"
    PROPERTY MACOSX_PACKAGE_LOCATION "Headers"
)

set_property(
    SOURCE "${CMAKE_CURRENT_LIST_DIR}/include/virgil/sdk/pythia/vssp_status.h"
    PROPERTY MACOSX_PACKAGE_LOCATION "Headers"
)

set_property(
    SOURCE "${CMAKE_CURRENT_LIST_DIR}/include/virgil/sdk/pythia/vssp_pythia_sdk_public.h"
    PROPERTY MACOSX_PACKAGE_LOCATION "Headers"
)

target_sources(pythia_sdk
    PRIVATE
            "${CMAKE_CURRENT_LIST_DIR}/include/virgil/sdk/pythia/vssp_assert.h"
            "${CMAKE_CURRENT_LIST_DIR}/include/virgil/sdk/pythia/vssp_library.h"
            "${CMAKE_CURRENT_LIST_DIR}/include/virgil/sdk/pythia/vssp_memory.h"
            "${CMAKE_CURRENT_LIST_DIR}/include/virgil/sdk/pythia/private/vssp_atomic.h"
            "${CMAKE_CURRENT_BINARY_DIR}/include/virgil/sdk/pythia/vssp_platform.h"
            "$<$<BOOL:${VSSP_BRAIN_KEY_SEED}>:${CMAKE_CURRENT_LIST_DIR}/include/virgil/sdk/pythia/vssp_brain_key_seed.h>"
            "$<$<BOOL:${VSSP_BRAIN_KEY_SEED}>:${CMAKE_CURRENT_LIST_DIR}/include/virgil/sdk/pythia/private/vssp_brain_key_seed_defs.h>"
            "$<$<BOOL:${VSSP_ERROR}>:${CMAKE_CURRENT_LIST_DIR}/include/virgil/sdk/pythia/vssp_error.h>"
            "$<$<BOOL:${VSSP_PYTHIA_CLIENT}>:${CMAKE_CURRENT_LIST_DIR}/include/virgil/sdk/pythia/vssp_pythia_client.h>"
            "$<$<BOOL:${VSSP_PYTHIA_CLIENT}>:${CMAKE_CURRENT_LIST_DIR}/include/virgil/sdk/pythia/private/vssp_pythia_client_defs.h>"
            "${CMAKE_CURRENT_LIST_DIR}/include/virgil/sdk/pythia/vssp_status.h"
            "${CMAKE_CURRENT_LIST_DIR}/include/virgil/sdk/pythia/vssp_pythia_sdk_public.h"
            "${CMAKE_CURRENT_LIST_DIR}/include/virgil/sdk/pythia/private/vssp_pythia_sdk_private.h"

            "${CMAKE_CURRENT_LIST_DIR}/src/vssp_assert.c"
            "${CMAKE_CURRENT_LIST_DIR}/src/vssp_library.c"
            "${CMAKE_CURRENT_LIST_DIR}/src/vssp_memory.c"
            "$<$<BOOL:${VSSP_BRAIN_KEY_SEED}>:${CMAKE_CURRENT_LIST_DIR}/src/vssp_brain_key_seed.c>"
            "$<$<BOOL:${VSSP_BRAIN_KEY_SEED}>:${CMAKE_CURRENT_LIST_DIR}/src/vssp_brain_key_seed_defs.c>"
            "$<$<BOOL:${VSSP_ERROR}>:${CMAKE_CURRENT_LIST_DIR}/src/vssp_error.c>"
            "$<$<BOOL:${VSSP_PYTHIA_CLIENT}>:${CMAKE_CURRENT_LIST_DIR}/src/vssp_pythia_client.c>"
            "$<$<BOOL:${VSSP_PYTHIA_CLIENT}>:${CMAKE_CURRENT_LIST_DIR}/src/vssp_pythia_client_defs.c>"
            "${CMAKE_CURRENT_LIST_DIR}/src/vssp_status.c"
        )

target_include_directories(pythia_sdk
        PUBLIC
            $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/virgil/sdk/pythia>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/virgil/sdk/pythia/private>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include/virgil/sdk/pythia>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include/virgil/sdk/pythia/private>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/src>
            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
        )