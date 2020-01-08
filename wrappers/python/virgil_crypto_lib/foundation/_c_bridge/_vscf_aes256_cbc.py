# Copyright (C) 2015-2020 Virgil Security, Inc.
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
from virgil_crypto_lib.common._c_bridge import vsc_data_t
from virgil_crypto_lib.common._c_bridge import vsc_buffer_t


class vscf_aes256_cbc_t(Structure):
    pass


class VscfAes256Cbc(object):
    """Implementation of the symmetric cipher AES-256 bit in a CBC mode.
    Note, this implementation contains dynamic memory allocations,
    this should be improved in the future releases."""

    # Cipher nfonce length or IV length in bytes, or 0 if nonce is not required.
    NONCE_LEN = 16
    # Cipher key length in bytes.
    KEY_LEN = 32
    # Cipher key length in bits.
    KEY_BITLEN = 256
    # Cipher block length in bytes.
    BLOCK_LEN = 16

    def __init__(self):
        """Create underlying C context."""
        self._ll = LowLevelLibs()
        self._lib = self._ll.foundation

    def vscf_aes256_cbc_new(self):
        vscf_aes256_cbc_new = self._lib.vscf_aes256_cbc_new
        vscf_aes256_cbc_new.argtypes = []
        vscf_aes256_cbc_new.restype = POINTER(vscf_aes256_cbc_t)
        return vscf_aes256_cbc_new()

    def vscf_aes256_cbc_delete(self, ctx):
        vscf_aes256_cbc_delete = self._lib.vscf_aes256_cbc_delete
        vscf_aes256_cbc_delete.argtypes = [POINTER(vscf_aes256_cbc_t)]
        vscf_aes256_cbc_delete.restype = None
        return vscf_aes256_cbc_delete(ctx)

    def vscf_aes256_cbc_alg_id(self, ctx):
        """Provide algorithm identificator."""
        vscf_aes256_cbc_alg_id = self._lib.vscf_aes256_cbc_alg_id
        vscf_aes256_cbc_alg_id.argtypes = [POINTER(vscf_aes256_cbc_t)]
        vscf_aes256_cbc_alg_id.restype = c_int
        return vscf_aes256_cbc_alg_id(ctx)

    def vscf_aes256_cbc_produce_alg_info(self, ctx):
        """Produce object with algorithm information and configuration parameters."""
        vscf_aes256_cbc_produce_alg_info = self._lib.vscf_aes256_cbc_produce_alg_info
        vscf_aes256_cbc_produce_alg_info.argtypes = [POINTER(vscf_aes256_cbc_t)]
        vscf_aes256_cbc_produce_alg_info.restype = POINTER(vscf_impl_t)
        return vscf_aes256_cbc_produce_alg_info(ctx)

    def vscf_aes256_cbc_restore_alg_info(self, ctx, alg_info):
        """Restore algorithm configuration from the given object."""
        vscf_aes256_cbc_restore_alg_info = self._lib.vscf_aes256_cbc_restore_alg_info
        vscf_aes256_cbc_restore_alg_info.argtypes = [POINTER(vscf_aes256_cbc_t), POINTER(vscf_impl_t)]
        vscf_aes256_cbc_restore_alg_info.restype = c_int
        return vscf_aes256_cbc_restore_alg_info(ctx, alg_info)

    def vscf_aes256_cbc_encrypt(self, ctx, data, out):
        """Encrypt given data."""
        vscf_aes256_cbc_encrypt = self._lib.vscf_aes256_cbc_encrypt
        vscf_aes256_cbc_encrypt.argtypes = [POINTER(vscf_aes256_cbc_t), vsc_data_t, POINTER(vsc_buffer_t)]
        vscf_aes256_cbc_encrypt.restype = c_int
        return vscf_aes256_cbc_encrypt(ctx, data, out)

    def vscf_aes256_cbc_encrypted_len(self, ctx, data_len):
        """Calculate required buffer length to hold the encrypted data."""
        vscf_aes256_cbc_encrypted_len = self._lib.vscf_aes256_cbc_encrypted_len
        vscf_aes256_cbc_encrypted_len.argtypes = [POINTER(vscf_aes256_cbc_t), c_size_t]
        vscf_aes256_cbc_encrypted_len.restype = c_size_t
        return vscf_aes256_cbc_encrypted_len(ctx, data_len)

    def vscf_aes256_cbc_precise_encrypted_len(self, ctx, data_len):
        """Precise length calculation of encrypted data."""
        vscf_aes256_cbc_precise_encrypted_len = self._lib.vscf_aes256_cbc_precise_encrypted_len
        vscf_aes256_cbc_precise_encrypted_len.argtypes = [POINTER(vscf_aes256_cbc_t), c_size_t]
        vscf_aes256_cbc_precise_encrypted_len.restype = c_size_t
        return vscf_aes256_cbc_precise_encrypted_len(ctx, data_len)

    def vscf_aes256_cbc_decrypt(self, ctx, data, out):
        """Decrypt given data."""
        vscf_aes256_cbc_decrypt = self._lib.vscf_aes256_cbc_decrypt
        vscf_aes256_cbc_decrypt.argtypes = [POINTER(vscf_aes256_cbc_t), vsc_data_t, POINTER(vsc_buffer_t)]
        vscf_aes256_cbc_decrypt.restype = c_int
        return vscf_aes256_cbc_decrypt(ctx, data, out)

    def vscf_aes256_cbc_decrypted_len(self, ctx, data_len):
        """Calculate required buffer length to hold the decrypted data."""
        vscf_aes256_cbc_decrypted_len = self._lib.vscf_aes256_cbc_decrypted_len
        vscf_aes256_cbc_decrypted_len.argtypes = [POINTER(vscf_aes256_cbc_t), c_size_t]
        vscf_aes256_cbc_decrypted_len.restype = c_size_t
        return vscf_aes256_cbc_decrypted_len(ctx, data_len)

    def vscf_aes256_cbc_set_nonce(self, ctx, nonce):
        """Setup IV or nonce."""
        vscf_aes256_cbc_set_nonce = self._lib.vscf_aes256_cbc_set_nonce
        vscf_aes256_cbc_set_nonce.argtypes = [POINTER(vscf_aes256_cbc_t), vsc_data_t]
        vscf_aes256_cbc_set_nonce.restype = None
        return vscf_aes256_cbc_set_nonce(ctx, nonce)

    def vscf_aes256_cbc_set_key(self, ctx, key):
        """Set cipher encryption / decryption key."""
        vscf_aes256_cbc_set_key = self._lib.vscf_aes256_cbc_set_key
        vscf_aes256_cbc_set_key.argtypes = [POINTER(vscf_aes256_cbc_t), vsc_data_t]
        vscf_aes256_cbc_set_key.restype = None
        return vscf_aes256_cbc_set_key(ctx, key)

    def vscf_aes256_cbc_state(self, ctx):
        """Return cipher's current state."""
        vscf_aes256_cbc_state = self._lib.vscf_aes256_cbc_state
        vscf_aes256_cbc_state.argtypes = [POINTER(vscf_aes256_cbc_t)]
        vscf_aes256_cbc_state.restype = c_int
        return vscf_aes256_cbc_state(ctx)

    def vscf_aes256_cbc_start_encryption(self, ctx):
        """Start sequential encryption."""
        vscf_aes256_cbc_start_encryption = self._lib.vscf_aes256_cbc_start_encryption
        vscf_aes256_cbc_start_encryption.argtypes = [POINTER(vscf_aes256_cbc_t)]
        vscf_aes256_cbc_start_encryption.restype = None
        return vscf_aes256_cbc_start_encryption(ctx)

    def vscf_aes256_cbc_start_decryption(self, ctx):
        """Start sequential decryption."""
        vscf_aes256_cbc_start_decryption = self._lib.vscf_aes256_cbc_start_decryption
        vscf_aes256_cbc_start_decryption.argtypes = [POINTER(vscf_aes256_cbc_t)]
        vscf_aes256_cbc_start_decryption.restype = None
        return vscf_aes256_cbc_start_decryption(ctx)

    def vscf_aes256_cbc_update(self, ctx, data, out):
        """Process encryption or decryption of the given data chunk."""
        vscf_aes256_cbc_update = self._lib.vscf_aes256_cbc_update
        vscf_aes256_cbc_update.argtypes = [POINTER(vscf_aes256_cbc_t), vsc_data_t, POINTER(vsc_buffer_t)]
        vscf_aes256_cbc_update.restype = None
        return vscf_aes256_cbc_update(ctx, data, out)

    def vscf_aes256_cbc_out_len(self, ctx, data_len):
        """Return buffer length required to hold an output of the methods
        "update" or "finish" in an current mode.
        Pass zero length to define buffer length of the method "finish"."""
        vscf_aes256_cbc_out_len = self._lib.vscf_aes256_cbc_out_len
        vscf_aes256_cbc_out_len.argtypes = [POINTER(vscf_aes256_cbc_t), c_size_t]
        vscf_aes256_cbc_out_len.restype = c_size_t
        return vscf_aes256_cbc_out_len(ctx, data_len)

    def vscf_aes256_cbc_encrypted_out_len(self, ctx, data_len):
        """Return buffer length required to hold an output of the methods
        "update" or "finish" in an encryption mode.
        Pass zero length to define buffer length of the method "finish"."""
        vscf_aes256_cbc_encrypted_out_len = self._lib.vscf_aes256_cbc_encrypted_out_len
        vscf_aes256_cbc_encrypted_out_len.argtypes = [POINTER(vscf_aes256_cbc_t), c_size_t]
        vscf_aes256_cbc_encrypted_out_len.restype = c_size_t
        return vscf_aes256_cbc_encrypted_out_len(ctx, data_len)

    def vscf_aes256_cbc_decrypted_out_len(self, ctx, data_len):
        """Return buffer length required to hold an output of the methods
        "update" or "finish" in an decryption mode.
        Pass zero length to define buffer length of the method "finish"."""
        vscf_aes256_cbc_decrypted_out_len = self._lib.vscf_aes256_cbc_decrypted_out_len
        vscf_aes256_cbc_decrypted_out_len.argtypes = [POINTER(vscf_aes256_cbc_t), c_size_t]
        vscf_aes256_cbc_decrypted_out_len.restype = c_size_t
        return vscf_aes256_cbc_decrypted_out_len(ctx, data_len)

    def vscf_aes256_cbc_finish(self, ctx, out):
        """Accomplish encryption or decryption process."""
        vscf_aes256_cbc_finish = self._lib.vscf_aes256_cbc_finish
        vscf_aes256_cbc_finish.argtypes = [POINTER(vscf_aes256_cbc_t), POINTER(vsc_buffer_t)]
        vscf_aes256_cbc_finish.restype = c_int
        return vscf_aes256_cbc_finish(ctx, out)

    def vscf_aes256_cbc_shallow_copy(self, ctx):
        vscf_aes256_cbc_shallow_copy = self._lib.vscf_aes256_cbc_shallow_copy
        vscf_aes256_cbc_shallow_copy.argtypes = [POINTER(vscf_aes256_cbc_t)]
        vscf_aes256_cbc_shallow_copy.restype = POINTER(vscf_aes256_cbc_t)
        return vscf_aes256_cbc_shallow_copy(ctx)

    def vscf_aes256_cbc_impl(self, ctx):
        vscf_aes256_cbc_impl = self._lib.vscf_aes256_cbc_impl
        vscf_aes256_cbc_impl.argtypes = [POINTER(vscf_aes256_cbc_t)]
        vscf_aes256_cbc_impl.restype = POINTER(vscf_impl_t)
        return vscf_aes256_cbc_impl(ctx)
