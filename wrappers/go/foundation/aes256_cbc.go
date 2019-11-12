package foundation

// #include <virgil/crypto/foundation/vscf_foundation_public.h>
import "C"


/*
* Implementation of the symmetric cipher AES-256 bit in a CBC mode.
* Note, this implementation contains dynamic memory allocations,
* this should be improved in the future releases.
*/
type Aes256Cbc struct {
    IAlg
    IEncrypt
    IDecrypt
    ICipherInfo
    ICipher
    cCtx *C.vscf_aes256_cbc_t /*ct10*/
}

/* Handle underlying C context. */
func (obj *Aes256Cbc) ctx () *C.vscf_impl_t {
    return (*C.vscf_impl_t)(obj.cCtx)
}

func NewAes256Cbc () *Aes256Cbc {
    ctx := C.vscf_aes256_cbc_new()
    return &Aes256Cbc {
        cCtx: ctx,
    }
}

/* Acquire C context.
* Note. This method is used in generated code only, and SHOULD NOT be used in another way.
*/
func newAes256CbcWithCtx (ctx *C.vscf_aes256_cbc_t /*ct10*/) *Aes256Cbc {
    return &Aes256Cbc {
        cCtx: ctx,
    }
}

/* Acquire retained C context.
* Note. This method is used in generated code only, and SHOULD NOT be used in another way.
*/
func newAes256CbcCopy (ctx *C.vscf_aes256_cbc_t /*ct10*/) *Aes256Cbc {
    return &Aes256Cbc {
        cCtx: C.vscf_aes256_cbc_shallow_copy(ctx),
    }
}

/*
* Release underlying C context.
*/
func (obj *Aes256Cbc) Delete () {
    C.vscf_aes256_cbc_delete(obj.cCtx)
}

/*
* Provide algorithm identificator.
*/
func (obj *Aes256Cbc) AlgId () AlgId {
    proxyResult := /*pr4*/C.vscf_aes256_cbc_alg_id(obj.cCtx)

    return AlgId(proxyResult) /* r8 */
}

/*
* Produce object with algorithm information and configuration parameters.
*/
func (obj *Aes256Cbc) ProduceAlgInfo () (IAlgInfo, error) {
    proxyResult := /*pr4*/C.vscf_aes256_cbc_produce_alg_info(obj.cCtx)

    return FoundationImplementationWrapIAlgInfo(proxyResult) /* r4 */
}

/*
* Restore algorithm configuration from the given object.
*/
func (obj *Aes256Cbc) RestoreAlgInfo (algInfo IAlgInfo) error {
    proxyResult := /*pr4*/C.vscf_aes256_cbc_restore_alg_info(obj.cCtx, (*C.vscf_impl_t)(algInfo.ctx()))

    err := FoundationErrorHandleStatus(proxyResult)
    if err != nil {
        return err
    }

    return nil
}

/*
* Encrypt given data.
*/
func (obj *Aes256Cbc) Encrypt (data []byte) ([]byte, error) {
    outBuf, outBufErr := bufferNewBuffer(int(obj.EncryptedLen(uint32(len(data))) /* lg2 */))
    if outBufErr != nil {
        return nil, outBufErr
    }
    defer outBuf.Delete()
    dataData := helperWrapData (data)

    proxyResult := /*pr4*/C.vscf_aes256_cbc_encrypt(obj.cCtx, dataData, outBuf.ctx)

    err := FoundationErrorHandleStatus(proxyResult)
    if err != nil {
        return nil, err
    }

    return outBuf.getData() /* r7 */, nil
}

/*
* Calculate required buffer length to hold the encrypted data.
*/
func (obj *Aes256Cbc) EncryptedLen (dataLen uint32) uint32 {
    proxyResult := /*pr4*/C.vscf_aes256_cbc_encrypted_len(obj.cCtx, (C.size_t)(dataLen)/*pa10*/)

    return uint32(proxyResult) /* r9 */
}

/*
* Precise length calculation of encrypted data.
*/
func (obj *Aes256Cbc) PreciseEncryptedLen (dataLen uint32) uint32 {
    proxyResult := /*pr4*/C.vscf_aes256_cbc_precise_encrypted_len(obj.cCtx, (C.size_t)(dataLen)/*pa10*/)

    return uint32(proxyResult) /* r9 */
}

/*
* Decrypt given data.
*/
func (obj *Aes256Cbc) Decrypt (data []byte) ([]byte, error) {
    outBuf, outBufErr := bufferNewBuffer(int(obj.DecryptedLen(uint32(len(data))) /* lg2 */))
    if outBufErr != nil {
        return nil, outBufErr
    }
    defer outBuf.Delete()
    dataData := helperWrapData (data)

    proxyResult := /*pr4*/C.vscf_aes256_cbc_decrypt(obj.cCtx, dataData, outBuf.ctx)

    err := FoundationErrorHandleStatus(proxyResult)
    if err != nil {
        return nil, err
    }

    return outBuf.getData() /* r7 */, nil
}

/*
* Calculate required buffer length to hold the decrypted data.
*/
func (obj *Aes256Cbc) DecryptedLen (dataLen uint32) uint32 {
    proxyResult := /*pr4*/C.vscf_aes256_cbc_decrypted_len(obj.cCtx, (C.size_t)(dataLen)/*pa10*/)

    return uint32(proxyResult) /* r9 */
}

/*
* Cipher nfonce length or IV length in bytes, or 0 if nonce is not required.
*/
func (obj *Aes256Cbc) GetNonceLen () uint32 {
    return 16
}

/*
* Cipher key length in bytes.
*/
func (obj *Aes256Cbc) GetKeyLen () uint32 {
    return 32
}

/*
* Cipher key length in bits.
*/
func (obj *Aes256Cbc) GetKeyBitlen () uint32 {
    return 256
}

/*
* Cipher block length in bytes.
*/
func (obj *Aes256Cbc) GetBlockLen () uint32 {
    return 16
}

/*
* Setup IV or nonce.
*/
func (obj *Aes256Cbc) SetNonce (nonce []byte) {
    nonceData := helperWrapData (nonce)

    C.vscf_aes256_cbc_set_nonce(obj.cCtx, nonceData)

    return
}

/*
* Set cipher encryption / decryption key.
*/
func (obj *Aes256Cbc) SetKey (key []byte) {
    keyData := helperWrapData (key)

    C.vscf_aes256_cbc_set_key(obj.cCtx, keyData)

    return
}

/*
* Start sequential encryption.
*/
func (obj *Aes256Cbc) StartEncryption () {
    C.vscf_aes256_cbc_start_encryption(obj.cCtx)

    return
}

/*
* Start sequential decryption.
*/
func (obj *Aes256Cbc) StartDecryption () {
    C.vscf_aes256_cbc_start_decryption(obj.cCtx)

    return
}

/*
* Process encryption or decryption of the given data chunk.
*/
func (obj *Aes256Cbc) Update (data []byte) []byte {
    outBuf, outBufErr := bufferNewBuffer(int(obj.OutLen(uint32(len(data))) /* lg2 */))
    if outBufErr != nil {
        return nil
    }
    defer outBuf.Delete()
    dataData := helperWrapData (data)

    C.vscf_aes256_cbc_update(obj.cCtx, dataData, outBuf.ctx)

    return outBuf.getData() /* r7 */
}

/*
* Return buffer length required to hold an output of the methods
* "update" or "finish" in an current mode.
* Pass zero length to define buffer length of the method "finish".
*/
func (obj *Aes256Cbc) OutLen (dataLen uint32) uint32 {
    proxyResult := /*pr4*/C.vscf_aes256_cbc_out_len(obj.cCtx, (C.size_t)(dataLen)/*pa10*/)

    return uint32(proxyResult) /* r9 */
}

/*
* Return buffer length required to hold an output of the methods
* "update" or "finish" in an encryption mode.
* Pass zero length to define buffer length of the method "finish".
*/
func (obj *Aes256Cbc) EncryptedOutLen (dataLen uint32) uint32 {
    proxyResult := /*pr4*/C.vscf_aes256_cbc_encrypted_out_len(obj.cCtx, (C.size_t)(dataLen)/*pa10*/)

    return uint32(proxyResult) /* r9 */
}

/*
* Return buffer length required to hold an output of the methods
* "update" or "finish" in an decryption mode.
* Pass zero length to define buffer length of the method "finish".
*/
func (obj *Aes256Cbc) DecryptedOutLen (dataLen uint32) uint32 {
    proxyResult := /*pr4*/C.vscf_aes256_cbc_decrypted_out_len(obj.cCtx, (C.size_t)(dataLen)/*pa10*/)

    return uint32(proxyResult) /* r9 */
}

/*
* Accomplish encryption or decryption process.
*/
func (obj *Aes256Cbc) Finish () ([]byte, error) {
    outBuf, outBufErr := bufferNewBuffer(int(obj.OutLen(0) /* lg2 */))
    if outBufErr != nil {
        return nil, outBufErr
    }
    defer outBuf.Delete()


    proxyResult := /*pr4*/C.vscf_aes256_cbc_finish(obj.cCtx, outBuf.ctx)

    err := FoundationErrorHandleStatus(proxyResult)
    if err != nil {
        return nil, err
    }

    return outBuf.getData() /* r7 */, nil
}
