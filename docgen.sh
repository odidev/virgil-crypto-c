#!/bin/bash
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


# ###########################################################################
#   Constants.
# ###########################################################################
COLOR_RED='\033[0;31m'
COLOR_GREEN='\033[0;32m'
COLOR_RESET='\033[0m'


# ###########################################################################
#   Helper functions.
# ###########################################################################
function show_info {
    echo -e "${COLOR_GREEN}[INFO    ]  $@${COLOR_RESET}"
}

function show_error {
    echo -e "${COLOR_RED}[ERROR]  $@${COLOR_RESET}"

    #   Second parameter is a flag that tells whether abort script or not.
    if [ $# -eq 2 ]; then
        if [ $2 -ne 0 ]; then
            exit 1
        fi
    else
        exit 1
    fi
}

function abspath() {
    (
        if [ -d "$1" ]; then
            cd "$1" && pwd -P
        else
            echo "$(cd "$(dirname "$1")" && pwd -P)/$(basename "$1")"
        fi
    )
}


# ###########################################################################
#   Variables.
# ###########################################################################
SCRIPT_DIR=$(dirname "$(abspath "${BASH_SOURCE[0]}")")
CURRENT_DIR=$(abspath .)
DOCGEN_DIR="${SCRIPT_DIR}/docs"
DOCGEN_SCRIPT_NAMES=(\
        project.xnf \
        library.xnf \
        interface.xnf \
        implementor.xnf \
        class.xnf \
        module.xnf \
        c_module.xnf \
        )


# ###########################################################################
#   Check proconditions.
# ###########################################################################
if [ ! -d "${DOCGEN_DIR}" ]; then
    show_error "Directory with doc generation files does not exists: ${DOCGEN_DIR}."
fi

for script in "${DOCGEN_SCRIPT_NAMES[@]}"; do
    if [ ! -f "${DOCGEN_DIR}/${script}" ]; then
        show_error "Entrypoint file for doc generation does not exists: ${DOCGEN_DIR}/${script}."
    fi
done


command -v gsl >/dev/null 2>&1 || {
    show_error "Codegen utility GSL is not available in the system." 0;
    show_error "See https://github.com/imatix/gsl#building-and-installing.";
}

# ###########################################################################
#   Generate files.
# ###########################################################################
cd "${DOCGEN_DIR}"

show_info "Doc generation started."
for script in "${DOCGEN_SCRIPT_NAMES[@]}"; do
    gsl "${script}" || { cd && show_error "Doc generation failed."; }
done
show_info "Doc generation finished."

cd
