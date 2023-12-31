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
///   File: nameof.hpp
///
/// Author: $author$
///   Date: 8/31/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_HTTP_CONTENT_TYPE_NAMEOF_HPP
#define XOS_PROTOCOL_HTTP_CONTENT_TYPE_NAMEOF_HPP

#include "xos/protocol/http/content/type/name.hpp"

namespace xos {
namespace protocol {
namespace http {
namespace content {
namespace type {
namespace nameof {

/// class css
class exported css: public type::name {
public:
    typedef type::name extends;
    typedef name derives;
    /// constructor / destructor
    css(const css& copy): extends(copy) {}
    css(): extends(type::css) {}
    virtual ~css() {}
}; /// class css

/// class html
class exported html: public type::name {
public:
    typedef type::name extends;
    typedef name derives;
    /// constructor / destructor
    html(const html& copy): extends(copy) {}
    html(): extends(type::html) {}
    virtual ~html() {}
}; /// class html

/// class text
class exported text: public type::name {
public:
    typedef type::name extends;
    typedef name derives;
    /// constructor / destructor
    text(const text& copy): extends(copy) {}
    text(): extends(type::text) {}
    virtual ~text() {}
}; /// class text

/// class xml
class exported xml: public type::name {
public:
    typedef type::name extends;
    typedef name derives;
    /// constructor / destructor
    xml(const xml& copy): extends(copy) {}
    xml(): extends(type::xml) {}
    virtual ~xml() {}
}; /// class xml

/// class javascript
class exported javascript: public type::name {
public:
    typedef type::name extends;
    typedef name derives;
    /// constructor / destructor
    javascript(const javascript& copy): extends(copy) {}
    javascript(): extends(type::javascript) {}
    virtual ~javascript() {}
}; /// class javascript

/// class json
class exported json: public type::name {
public:
    typedef type::name extends;
    typedef name derives;
    /// constructor / destructor
    json(const json& copy): extends(copy) {}
    json(): extends(type::json) {}
    virtual ~json() {}
}; /// class json

/// class multipart_form_data
class exported multipart_form_data: public type::name {
public:
    typedef type::name extends;
    typedef name derives;
    /// constructor / destructor
    multipart_form_data(const multipart_form_data& copy): extends(copy) {}
    multipart_form_data(): extends(type::multipart_form_data) {}
    virtual ~multipart_form_data() {}
}; /// class multipart_form_data

/// class urlencoded_form_data
class exported urlencoded_form_data: public type::name {
public:
    typedef type::name extends;
    typedef name derives;
    /// constructor / destructor
    urlencoded_form_data(const urlencoded_form_data& copy): extends(copy) {}
    urlencoded_form_data(): extends(type::urlencoded_form_data) {}
    virtual ~urlencoded_form_data() {}
}; /// class urlencoded_form_data

} /// namespace nameof
} /// namespace type 
} /// namespace content 
} /// namespace http 
} /// namespace protocol 
} /// namespace xos 

#endif /// ndef XOS_PROTOCOL_HTTP_CONTENT_TYPE_NAMEOF_HPP
