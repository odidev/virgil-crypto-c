# Copyright (C) 2015-2019 Virgil Security, Inc.
#
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met:
#
#     (1) Redistributions of source code must retain the above copyright
#     notice, this list of conditions and the following disclaimer.
#
#     (2) Redistributions in binary form must reproduce the above copyright
#     notice, this list of conditions and the following disclaimer in
#     the documentation and/or other materials provided with the
#     distribution.
#
#     (3) Neither the name of the copyright holder nor the names of its
#     contributors may be used to endorse or promote products derived from
#     this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR ''AS IS'' AND ANY EXPRESS OR
# IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
# INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
# (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
# SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
# STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
# IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
# Lead Maintainer: Virgil Security Inc. <support@virgilsecurity.com>


from virgil_crypto_lib._libs import *
from ctypes import *
from ._vscf_impl import vscf_impl_t


class vscf_chained_private_key_t(Structure):
    pass


class VscfChainedPrivateKey(object):
    """Handles chained private key.

    Chained private key contains 2 private keys:
        - l1 cipher key - is used for decryption data decrypted by the l2;
        - l2 cipher key - is used for decryption given data."""

    def __init__(self):
        """Create underlying C context."""
        self._ll = LowLevelLibs()
        self._lib = self._ll.foundation

    def vscf_chained_private_key_new(self):
        vscf_chained_private_key_new = self._lib.vscf_chained_private_key_new
        vscf_chained_private_key_new.argtypes = []
        vscf_chained_private_key_new.restype = POINTER(vscf_chained_private_key_t)
        return vscf_chained_private_key_new()

    def vscf_chained_private_key_delete(self, ctx):
        vscf_chained_private_key_delete = self._lib.vscf_chained_private_key_delete
        vscf_chained_private_key_delete.argtypes = [POINTER(vscf_chained_private_key_t)]
        vscf_chained_private_key_delete.restype = None
        return vscf_chained_private_key_delete(ctx)

    def vscf_chained_private_key_alg_id(self, ctx):
        """Algorithm identifier the key belongs to."""
        vscf_chained_private_key_alg_id = self._lib.vscf_chained_private_key_alg_id
        vscf_chained_private_key_alg_id.argtypes = [POINTER(vscf_chained_private_key_t)]
        vscf_chained_private_key_alg_id.restype = c_int
        return vscf_chained_private_key_alg_id(ctx)

    def vscf_chained_private_key_alg_info(self, ctx):
        """Return algorithm information that can be used for serialization."""
        vscf_chained_private_key_alg_info = self._lib.vscf_chained_private_key_alg_info
        vscf_chained_private_key_alg_info.argtypes = [POINTER(vscf_chained_private_key_t)]
        vscf_chained_private_key_alg_info.restype = POINTER(vscf_impl_t)
        return vscf_chained_private_key_alg_info(ctx)

    def vscf_chained_private_key_len(self, ctx):
        """Length of the key in bytes."""
        vscf_chained_private_key_len = self._lib.vscf_chained_private_key_len
        vscf_chained_private_key_len.argtypes = [POINTER(vscf_chained_private_key_t)]
        vscf_chained_private_key_len.restype = c_size_t
        return vscf_chained_private_key_len(ctx)

    def vscf_chained_private_key_bitlen(self, ctx):
        """Length of the key in bits."""
        vscf_chained_private_key_bitlen = self._lib.vscf_chained_private_key_bitlen
        vscf_chained_private_key_bitlen.argtypes = [POINTER(vscf_chained_private_key_t)]
        vscf_chained_private_key_bitlen.restype = c_size_t
        return vscf_chained_private_key_bitlen(ctx)

    def vscf_chained_private_key_impl_tag(self, ctx):
        """Return tag of an associated algorithm that can handle this key."""
        vscf_chained_private_key_impl_tag = self._lib.vscf_chained_private_key_impl_tag
        vscf_chained_private_key_impl_tag.argtypes = [POINTER(vscf_chained_private_key_t)]
        vscf_chained_private_key_impl_tag.restype = c_int
        return vscf_chained_private_key_impl_tag(ctx)

    def vscf_chained_private_key_is_valid(self, ctx):
        """Check that key is valid.
        Note, this operation can be slow."""
        vscf_chained_private_key_is_valid = self._lib.vscf_chained_private_key_is_valid
        vscf_chained_private_key_is_valid.argtypes = [POINTER(vscf_chained_private_key_t)]
        vscf_chained_private_key_is_valid.restype = c_bool
        return vscf_chained_private_key_is_valid(ctx)

    def vscf_chained_private_key_extract_public_key(self, ctx):
        """Extract public key from the private key."""
        vscf_chained_private_key_extract_public_key = self._lib.vscf_chained_private_key_extract_public_key
        vscf_chained_private_key_extract_public_key.argtypes = [POINTER(vscf_chained_private_key_t)]
        vscf_chained_private_key_extract_public_key.restype = POINTER(vscf_impl_t)
        return vscf_chained_private_key_extract_public_key(ctx)

    def vscf_chained_private_key_l1_cipher_key(self, ctx):
        """Return l1 cipher private key."""
        vscf_chained_private_key_l1_cipher_key = self._lib.vscf_chained_private_key_l1_cipher_key
        vscf_chained_private_key_l1_cipher_key.argtypes = [POINTER(vscf_chained_private_key_t)]
        vscf_chained_private_key_l1_cipher_key.restype = POINTER(vscf_impl_t)
        return vscf_chained_private_key_l1_cipher_key(ctx)

    def vscf_chained_private_key_l2_cipher_key(self, ctx):
        """Return l2 cipher private key."""
        vscf_chained_private_key_l2_cipher_key = self._lib.vscf_chained_private_key_l2_cipher_key
        vscf_chained_private_key_l2_cipher_key.argtypes = [POINTER(vscf_chained_private_key_t)]
        vscf_chained_private_key_l2_cipher_key.restype = POINTER(vscf_impl_t)
        return vscf_chained_private_key_l2_cipher_key(ctx)

    def vscf_chained_private_key_shallow_copy(self, ctx):
        vscf_chained_private_key_shallow_copy = self._lib.vscf_chained_private_key_shallow_copy
        vscf_chained_private_key_shallow_copy.argtypes = [POINTER(vscf_chained_private_key_t)]
        vscf_chained_private_key_shallow_copy.restype = POINTER(vscf_chained_private_key_t)
        return vscf_chained_private_key_shallow_copy(ctx)

    def vscf_chained_private_key_impl(self, ctx):
        vscf_chained_private_key_impl = self._lib.vscf_chained_private_key_impl
        vscf_chained_private_key_impl.argtypes = [POINTER(vscf_chained_private_key_t)]
        vscf_chained_private_key_impl.restype = POINTER(vscf_impl_t)
        return vscf_chained_private_key_impl(ctx)
