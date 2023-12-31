//////////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2023 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: fields.hpp
///
/// Author: $author$
///   Date: 8/31/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_HTTP_MESSAGE_HEADER_FIELDS_HPP
#define XOS_PROTOCOL_HTTP_MESSAGE_HEADER_FIELDS_HPP

#include "xos/protocol/xttp/message/header/fields.hpp"
#include "xos/protocol/http/message/header/field.hpp"

namespace xos {
namespace protocol {
namespace http {
namespace message {
namespace header {

/// class fieldst
template 
<class TExtends = xttp::message::header::extended::fieldst
 <http::message::header::field, http::message::part>, 
 class TImplements = typename TExtends::implements>
class exported fieldst: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef fieldst derives;

    typedef typename extends::field_t field_t;
    typedef typename extends::list_t list_t;
    typedef typename list_t::const_iterator const_iterator_t;
    typedef typename extends::part_t part_t;
    typedef typename extends::string_t string_t;
    typedef typename string_t::char_t char_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;

    /// constructor / destructor
    fieldst(const field_t* f, ...) {
        va_list va;
        va_start(va, f);
        this->is_setv(f, va);
        va_end(va);
    }
    fieldst(const field_t* f, va_list va): extends(f, va) {
        this->setv(f, va);
    }
    fieldst(const field_t& f): extends(f) {
        this->set(f);
    }
    fieldst(const string_t& chars): extends(chars) {
        this->separate();
    }
    fieldst(const char_t* chars, size_t length): extends(chars, length) {
        this->separate();
    }
    fieldst(const char_t* chars): extends(chars) {
        this->separate();
    }
    fieldst(const fieldst& copy): extends(copy) {
        this->separate();
    }
    fieldst() {
        this->set_default();
    }
    virtual ~fieldst() {
        this->clear_list();
        this->free_field();
    }
}; /// class fieldst
typedef fieldst<> fields;

} /// namespace header 
} /// namespace message 
} /// namespace http 
} /// namespace protocol 
} /// namespace xos 

#endif /// ndef XOS_PROTOCOL_HTTP_MESSAGE_HEADER_FIELDS_HPP
