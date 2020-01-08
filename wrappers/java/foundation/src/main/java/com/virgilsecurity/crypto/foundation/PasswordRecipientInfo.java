/*
* Copyright (C) 2015-2020 Virgil Security, Inc.
*
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are
* met:
*
* (1) Redistributions of source code must retain the above copyright
* notice, this list of conditions and the following disclaimer.
*
* (2) Redistributions in binary form must reproduce the above copyright
* notice, this list of conditions and the following disclaimer in
* the documentation and/or other materials provided with the
* distribution.
*
* (3) Neither the name of the copyright holder nor the names of its
* contributors may be used to endorse or promote products derived from
* this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE AUTHOR ''AS IS'' AND ANY EXPRESS OR
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
* Lead Maintainer: Virgil Security Inc. <support@virgilsecurity.com>
*/

package com.virgilsecurity.crypto.foundation;

/*
* Handle information about recipient that is defined by a password.
*/
public class PasswordRecipientInfo implements AutoCloseable {

    public long cCtx;

    /* Create underlying C context. */
    public PasswordRecipientInfo() {
        super();
        this.cCtx = FoundationJNI.INSTANCE.passwordRecipientInfo_new();
    }

    /* Wrap underlying C context. */
    PasswordRecipientInfo(FoundationContextHolder contextHolder) {
        this.cCtx = contextHolder.cCtx;
    }

    /*
    * Create object and define all properties.
    */
    public PasswordRecipientInfo(AlgInfo keyEncryptionAlgorithm, byte[] encryptedKey) {
        super();
        this.cCtx = FoundationJNI.INSTANCE.passwordRecipientInfo_new(keyEncryptionAlgorithm, encryptedKey);
    }

    /*
    * Acquire C context.
    * Note. This method is used in generated code only, and SHOULD NOT be used in another way.
    */
    public static PasswordRecipientInfo getInstance(long cCtx) {
        FoundationContextHolder ctxHolder = new FoundationContextHolder(cCtx);
        return new PasswordRecipientInfo(ctxHolder);
    }

    /* Close resource. */
    public void close() {
        FoundationJNI.INSTANCE.passwordRecipientInfo_close(this.cCtx);
    }

    /*
    * Return algorithm information that was used for encryption
    * a data encryption key.
    */
    public AlgInfo keyEncryptionAlgorithm() {
        return FoundationJNI.INSTANCE.passwordRecipientInfo_keyEncryptionAlgorithm(this.cCtx);
    }

    /*
    * Return an encrypted data encryption key.
    */
    public byte[] encryptedKey() {
        return FoundationJNI.INSTANCE.passwordRecipientInfo_encryptedKey(this.cCtx);
    }
}

