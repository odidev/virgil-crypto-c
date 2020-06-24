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

option(VSSP_LIBRARY "Enable build of the 'pythia sdk' library" ON)
option(VSSP_MULTI_THREADING "Enable multi-threading safety for Pythia SDK." ON)
option(VSSP_ERROR "Enable class 'error'." ON)
option(VSSP_PYTHIA_CLIENT "Enable class 'pythia client'." ON)
option(VSSP_BRAIN_KEY_SEED "Enable class 'brain key seed'." ON)
mark_as_advanced(
        VSSP_LIBRARY
        VSSP_MULTI_THREADING
        VSSP_ERROR
        VSSP_PYTHIA_CLIENT
        VSSP_BRAIN_KEY_SEED
        )

if(VSSP_PYTHIA_CLIENT AND NOT VSSC_JSON_OBJECT)
    message("-- error --")
    message("--")
    message("Feature VSSP_PYTHIA_CLIENT depends on the feature:")
    message("     VSSC_JSON_OBJECT - which is disabled.")
    message("--")
    message(FATAL_ERROR)
endif()
