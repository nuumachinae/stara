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
///   File: content.hpp
///
/// Author: $author$
///   Date: 9/1/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_HTTP_TEXT_CONTENT_HPP
#define XOS_PROTOCOL_HTTP_TEXT_CONTENT_HPP

#include "xos/protocol/xttp/message/part.hpp"

namespace xos {
namespace protocol {
namespace http {
namespace text {

/// class contentt
template <class TExtends = xttp::message::part, class TImplements = typename TExtends::implements>
class exported contentt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef contentt derives;

    typedef extends part_t;
    typedef typename extends::string_t string_t;
    typedef typename string_t::char_t char_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;

    /// constructor / destructor
    contentt(const contentt& copy): extends(copy) {
    }
    contentt() {
    }
    virtual ~contentt() {
    }

    /// read
    virtual ssize_t read(reader_t& reader) {
        ssize_t count = 0, amount = 0; char_t c = 0;
        while (1 <= (amount = reader.read(&c, 1))) {
            this->append(&c, 1);
            count += amount;
        }
        return count;
    }
}; /// class contentt
typedef contentt<> content;

} /// namespace text 
} /// namespace http 
} /// namespace protocol 
} /// namespace xos 

#endif /// ndef XOS_PROTOCOL_HTTP_TEXT_CONTENT_HPP
