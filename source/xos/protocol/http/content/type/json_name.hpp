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
///   File: json_name.hpp
///
/// Author: $author$
///   Date: 8/31/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_HTTP_CONTENT_TYPE_JSON_NAME_HPP
#define XOS_PROTOCOL_HTTP_CONTENT_TYPE_JSON_NAME_HPP

#include "xos/protocol/http/content/type/name.hpp"

namespace xos {
namespace protocol {
namespace http {
namespace content {
namespace type {

/// class json_namet
template 
<class TExtends = xos::protocol::http::content::type::name, class TImplements = implement>

class exported json_namet: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef json_namet derives; 
    
    typedef typename extends::which_t name_which_t;
    enum { name_which = content::type::json };

    typedef typename extends::type_name_t type_name_t;
    typedef typename extends::type_which_t type_which_t;
    enum { type_which = media::type::text };

    typedef typename extends::subtype_name_t subtype_name_t;
    typedef typename extends::subtype_which_t subtype_which_t;
    enum { subtype_which = media::subtype::json };

    typedef extends part_t;
    typedef typename extends::string_t string_t;
    typedef typename string_t::char_t char_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;

    /// constructors / destructor
    json_namet(const json_namet& copy): extends(copy) {
    }
    json_namet(): extends(name_which) {
    }
    virtual ~json_namet() {
    }

}; /// class json_namet
typedef json_namet<> json_name;

} /// namespace type 
} /// namespace content 
} /// namespace http 
} /// namespace protocol 
} /// namespace xos 

#endif /// ndef XOS_PROTOCOL_HTTP_CONTENT_TYPE_JSON_NAME_HPP
