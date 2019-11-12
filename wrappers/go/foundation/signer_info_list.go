package foundation

// #include <virgil/crypto/foundation/vscf_foundation_public.h>
import "C"


/*
* Handles a list of "signer info" class objects.
*/
type SignerInfoList struct {
    cCtx *C.vscf_signer_info_list_t /*ct2*/
}

/* Handle underlying C context. */
func (obj *SignerInfoList) ctx () *C.vscf_impl_t {
    return (*C.vscf_impl_t)(obj.cCtx)
}

func NewSignerInfoList () *SignerInfoList {
    ctx := C.vscf_signer_info_list_new()
    return &SignerInfoList {
        cCtx: ctx,
    }
}

/* Acquire C context.
* Note. This method is used in generated code only, and SHOULD NOT be used in another way.
*/
func newSignerInfoListWithCtx (ctx *C.vscf_signer_info_list_t /*ct2*/) *SignerInfoList {
    return &SignerInfoList {
        cCtx: ctx,
    }
}

/* Acquire retained C context.
* Note. This method is used in generated code only, and SHOULD NOT be used in another way.
*/
func newSignerInfoListCopy (ctx *C.vscf_signer_info_list_t /*ct2*/) *SignerInfoList {
    return &SignerInfoList {
        cCtx: C.vscf_signer_info_list_shallow_copy(ctx),
    }
}

/*
* Release underlying C context.
*/
func (obj *SignerInfoList) Delete () {
    C.vscf_signer_info_list_delete(obj.cCtx)
}

/*
* Return true if given list has item.
*/
func (obj *SignerInfoList) HasItem () bool {
    proxyResult := /*pr4*/C.vscf_signer_info_list_has_item(obj.cCtx)

    return bool(proxyResult) /* r9 */
}

/*
* Return list item.
*/
func (obj *SignerInfoList) Item () *SignerInfo {
    proxyResult := /*pr4*/C.vscf_signer_info_list_item(obj.cCtx)

    return newSignerInfoWithCtx(proxyResult) /* r5 */
}

/*
* Return true if list has next item.
*/
func (obj *SignerInfoList) HasNext () bool {
    proxyResult := /*pr4*/C.vscf_signer_info_list_has_next(obj.cCtx)

    return bool(proxyResult) /* r9 */
}

/*
* Return next list node if exists, or NULL otherwise.
*/
func (obj *SignerInfoList) Next () *SignerInfoList {
    proxyResult := /*pr4*/C.vscf_signer_info_list_next(obj.cCtx)

    return newSignerInfoListWithCtx(proxyResult) /* r6 */
}

/*
* Return true if list has previous item.
*/
func (obj *SignerInfoList) HasPrev () bool {
    proxyResult := /*pr4*/C.vscf_signer_info_list_has_prev(obj.cCtx)

    return bool(proxyResult) /* r9 */
}

/*
* Return previous list node if exists, or NULL otherwise.
*/
func (obj *SignerInfoList) Prev () *SignerInfoList {
    proxyResult := /*pr4*/C.vscf_signer_info_list_prev(obj.cCtx)

    return newSignerInfoListWithCtx(proxyResult) /* r6 */
}

/*
* Remove all items.
*/
func (obj *SignerInfoList) Clear () {
    C.vscf_signer_info_list_clear(obj.cCtx)

    return
}
