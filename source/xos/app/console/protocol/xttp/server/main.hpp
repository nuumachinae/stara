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
///   File: main.hpp
///
/// Author: $author$
///   Date: 9/2/2023, 10/7/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_HPP
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_HPP

#include "xos/app/console/protocol/xttp/server/main_opt.hpp"

#include "xos/protocol/http/url/encoded/reader.hpp"
#include "xos/protocol/http/form/field.hpp"
#include "xos/protocol/http/form/fields.hpp"

#include "xos/protocol/http/request/method/which.hpp"
#include "xos/protocol/http/request/method/name.hpp"
#include "xos/protocol/http/request/method/nameof.hpp"
#include "xos/protocol/http/request/resource/which.hpp"
#include "xos/protocol/http/request/resource/identifier.hpp"
#include "xos/protocol/http/request/line.hpp"
#include "xos/protocol/http/request/message.hpp"

#include "xos/protocol/http/response/status/codeof.hpp"
#include "xos/protocol/http/response/status/reason.hpp"
#include "xos/protocol/http/response/line.hpp"
#include "xos/protocol/http/response/message.hpp"

namespace xos {
namespace app {
namespace console {
namespace protocol {
namespace xttp {
namespace server {

/// class maint
template 
<class TExtends = xos::app::console::protocol::xttp::server::main_optt<>,  class TImplements = typename TExtends::implements>

class maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;

    /// constructor / destructor
    maint()
    : run_(0), status_(ok_), reason_(status_), response_line_(this->protocol_, status_, reason_),
      response_headers_(&this->content_type_header_, &this->content_length_header_, null),
      response_(response_line_, response_headers_, this->content_) {
    }
    virtual ~maint() {
    }
private:
    maint(const maint &copy) {
        throw exception(exception_unexpected);
    }

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;

    typedef typename extends::file_reader_t file_reader_t;

    typedef typename extends::headers_t headers_t;
    typedef typename extends::content_encoding_header_t content_encoding_header_t;
    typedef typename extends::content_type_header_t content_type_header_t;
    typedef typename extends::content_length_header_t content_length_header_t;

    typedef typename extends::content_t content_t;
    typedef typename extends::content_string_t content_string_t;
    typedef typename extends::content_type_t content_type_t;
    typedef typename extends::content_type_char_t content_type_char_t;
    typedef typename extends::url_encoded_form_content_type_t url_encoded_form_content_type_t;
    typedef typename extends::text_content_type_t text_content_type_t;
    typedef typename extends::json_content_type_t json_content_type_t;
    typedef typename extends::text_content_t text_content_t;

    typedef typename extends::content_part_t content_part_t;
    typedef typename extends::content_reader_t content_reader_t;
    typedef typename extends::content_part_reader_t content_part_reader_t;

    typedef xos::protocol::http::url::encoded::readert<content_part_reader_t> url_encoded_content_reader_t;
    typedef xos::protocol::http::form::field form_field_t;
    typedef xos::protocol::http::form::fields form_fields_t;

    typedef xos::protocol::http::request::method::which request_method_which_t;
    typedef xos::protocol::http::request::method::name request_method_t;
    typedef xos::protocol::http::request::resource::identifier request_resource_t;
    typedef xos::protocol::http::request::line request_line_t;
    typedef xos::protocol::http::request::message request_t;
    typedef xos::protocol::http::request::message::string_t request_string_t;

    typedef xos::protocol::http::response::status::code response_status_t;
    typedef xos::protocol::http::response::status::reason response_reason_t;
    typedef xos::protocol::http::response::line response_line_t;
    typedef xos::protocol::http::response::message response_t;
    typedef xos::protocol::http::response::message::string_t response_string_t;

    /// run
    int (derives::*run_)(int argc, char_t** argv, char_t** env);
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((run_)) {
            err = (this->*run_)(argc, argv, env);
        } else {
            err = extends::run(argc, argv, env);
        }
        return err;
    }

    /// ...request_run
    virtual int request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        in_reader_t& reader = this->in_reader();
        request_t& request = this->request();
        response_t& response = this->response();

        LOGGER_IS_LOGGED_INFO("!(err = all_process_response_to_request(response, reader, request, argc, argv, env))...");
        if (!(err = all_process_response_to_request(response, reader, request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_process_response_to_request(response, reader, request, argc, argv, env))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = all_process_response_to_request(response, reader, request, argc, argv, env))");
        }
        return err;
    }
    virtual int before_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        in_reader_t& reader = this->in_reader();
        request_t& request = this->request();
        ssize_t amount = 0;

        LOGGER_IS_LOGGED_INFO("!(err = all_read_request_with_content(amount, request, reader, argc, argv, env))...");
        if (!(err = all_read_request_with_content(amount, request, reader, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_read_request_with_content(amount = " << amount << ", request, reader, argc, argv, env))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = all_read_request_with_content(amount = " << amount << ", request, reader, argc, argv, env))");
        }
        return err;
    }
    virtual int after_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("!(err = this->all_response_run(argc, argv, env))...");
        if (!(err = this->all_response_run(argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = this->all_response_run(argc, argv, env))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = this->all_response_run(argc, argv, env))");
        }
        return err;
    }
    /// ...file_request_run
    virtual int file_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        file_reader_t& reader = this->file_reader();
        request_t& request = this->request();
        response_t& response = this->response();

        LOGGER_IS_LOGGED_INFO("!(err = all_process_response_to_request(response, reader, request, argc, argv, env))...");
        if (!(err = all_process_response_to_request(response, reader, request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_process_response_to_request(response, reader, request, argc, argv, env))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = all_process_response_to_request(response, reader, request, argc, argv, env))");
        }
        return err;
    }
    virtual int before_file_request_run(int argc, char_t** argv, char_t** env) {
        int err = 1;
        const string_t& filename = this->request_filename();
        const char_t* chars = 0; size_t length = 0;
        
        LOGGER_IS_LOGGED_INFO("(chars = filename.has_chars(length))...");
        if ((chars = filename.has_chars(length))) {
            file_reader_t& reader = this->file_reader();
            
            LOGGER_IS_LOGGED_INFO("...(\"" << chars << "\" = filename.has_chars(" << length << "))");
            LOGGER_IS_LOGGED_INFO("(reader.open(\"" << chars << "\"))...");
            if ((reader.open(chars))) {
                request_t& request = this->request();
                ssize_t amount = 0;
        
                LOGGER_IS_LOGGED_INFO("...(reader.open(\"" << chars << "\"))");
                LOGGER_IS_LOGGED_INFO("!(err = all_read_request_with_content(amount, request, reader, argc, argv, env))...");
                if (!(err = all_read_request_with_content(amount, request, reader, argc, argv, env))) {
                    LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_read_request_with_content(amount = " << amount << ", request, reader, argc, argv, env))");
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = all_read_request_with_content(amount = " << amount << ", request, reader, argc, argv, env))");
                }
                LOGGER_IS_LOGGED_INFO("(reader.close())...");
                if ((reader.close())) {
                    LOGGER_IS_LOGGED_INFO("...(reader.close())");
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed on (reader.close())");
                }
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (file.open(\"" << chars << "\"))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (\"" << chars << "\" = filename.has_chars(" << length << "))");
        }
        return err;
    }
    virtual int after_file_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("!(err = after_request_run(argc, argv, env))...");
        if (!(err = after_request_run(argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = after_request_run(argc, argv, env))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = after_request_run(argc, argv, env))");
        }
        return err;
    }

    /// ...response_run
    virtual int response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        out_writer_t& writer = this->out_writer();
        response_t& response = this->response();
        ssize_t amount = 0;

        LOGGER_IS_LOGGED_INFO("!(err = all_write_response(amount, writer, response, argc, argv, env))...");
        if (!(err = all_write_response(amount, writer, response, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_write_response(amount = " << amount << ", writer, response, argc, argv, env))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = all_write_response(amount = " << amount << ", writer, response, argc, argv, env))");
        }
        return err;
    }

    /// ...status_run
    virtual int status_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;
        response_status_t& status = this->response_status();
        if ((chars = status.has_chars(length))) {
            this->outln(chars, length);
        }
        return err;
    }

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    /// ...option...
    int (derives::*on_set_response_option_)(const char_t* optarg, int optind, int argc, char_t** argv, char_t** env);
    virtual int on_set_response_option(const char_t* optarg, int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (on_set_response_option_) {
            err = (this->*on_set_response_option_)(optarg, optind, argc, argv, env);
        } else {
            err = file_on_set_response_option(optarg, optind, argc, argv, env);
        }
        return err;
    }
    virtual int file_on_set_response_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        const char_t* chars = 0;
        if ((chars = optarg) && (chars[0])) {
            xos::io::crt::file::reader source;

            LOGGER_IS_LOGGED_INFO("source.open(chars = \"" << chars << "\")...");
            if ((source.open(chars))) {
                xos::io::crt::file::reader::sized_t c = 0;
                ssize_t amount = 0, count = 0;

                LOGGER_IS_LOGGED_INFO("...source.open(chars = \"" << chars << "\")");
                if (0 < (amount = source.read(&c, 1))) {
                    response_string_t& response_literal = this->response_literal();
                    response_t& response = this->response();
                    
                    response_literal.clear();
                    do {
                        response_string_t::char_t cc = ((response_string_t::char_t)c);
                        response_literal.append(&cc, 1);
                        count += amount;
                    } while (0 < (amount = source.read(&c, 1)));
                    LOGGER_IS_LOGGED_INFO("response.set(response_literal = \"" << response_literal << "\")...");
                    response.set(response_literal);
                }
                LOGGER_IS_LOGGED_INFO("source.close() \"" << chars << "\"...");
                if ((source.close())) {
                    LOGGER_IS_LOGGED_INFO("...source.close() \"" << chars << "\"");
                } else {
                    LOGGER_IS_LOGGED_ERROR("...failed on source.close() \"" << chars << "\"");
                }
            } else {
                LOGGER_IS_LOGGED_ERROR("...failed on source.open(chars = \"" << chars << "\")");
            }
        } else {
        }
        return err;
    }
    virtual int string_on_set_response_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        char_t c = 0;
        const char_t* chars = 0;
        if ((chars = optarg) && (0 != (c = chars[0]))) {
            response_string_t& response_literal = this->response_literal();
            response_t& response = this->response();
            
            LOGGER_IS_LOGGED_INFO("chars = \"" << chars << "\"...");
            response_literal.clear();
            do {
                response_string_t::char_t cc = ((response_string_t::char_t)c);
                response_literal.append(&cc, 1);
            } while (0 != (c = (++chars)[0]));
            LOGGER_IS_LOGGED_INFO("response.set(response_literal = \"" << response_literal << "\")...");
            response.set(response_literal);
        } else {
        }
        return err;
    }
    virtual int set_file_on_set_response_option(int argc, char_t** argv, char_t** env) {
        int err = 0;
        on_set_response_option_ = &derives::file_on_set_response_option;
        return err;
    }
    virtual int set_string_on_set_response_option(int argc, char_t** argv, char_t** env) {
        int err = 0;
        on_set_response_option_ = &derives::string_on_set_response_option;
        return err;
    }

    /// ...option...
    virtual int on_set_status_ok_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_response_status(optarg);
        } else {
            set_response_status_ok();
        }
        return err;
    }

    /// ...option...
    virtual int on_set_status_not_found_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_response_status(optarg);
        } else {
            set_response_status_not_found();
        }
        return err;
    }

    /// ...option...
    virtual int on_content_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            content_type_header_t& content_type_header = this->content_type_header();
            content_length_header_t& content_length_header = this->content_length_header();
            headers_t& response_headers = this->response_headers();
            content_t& response_content = this->content();

            content_length_header.set_length(response_content.length());
            response_headers.is_setl(&content_type_header, &content_length_header, null);
            err = all_set_response_content(response_headers, response_content, argc, argv, env);
        } else {
        }
        return err;
    }
    virtual int on_content_type_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            content_type_header_t& content_type_header = this->content_type_header();
            content_length_header_t& content_length_header = this->content_length_header();
            headers_t& response_headers = this->response_headers();
            content_t& response_content = this->content();

            response_headers.is_setl(&content_type_header, &content_length_header, null);
            err = all_set_response_content(response_headers, response_content, argc, argv, env);
        } else {
        }
        return err;
    }
    virtual int on_content_encoding_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            content_encoding_header_t& content_encoding_header = this->content_encoding_header();
            content_type_header_t& content_type_header = this->content_type_header();
            content_length_header_t& content_length_header = this->content_length_header();
            headers_t& response_headers = this->response_headers();
            content_t& response_content = this->content();

            response_headers.is_setl(&content_encoding_header, &content_type_header, &content_length_header, null);
            err = all_set_response_content(response_headers, response_content, argc, argv, env);
        } else {
        }
        return err;
    }

    /// on_..._input_option_set
    virtual int on_file_input_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = extends::on_file_input_option_set(optarg, optind, argc, argv, env))) {
            if (!(err = set_file_on_set_response_option(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_string_input_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = extends::on_string_input_option_set(optarg, optind, argc, argv, env))) {
            if (!(err = set_string_on_set_response_option(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    /// ...process_response_to_request
    virtual int process_response_to_request(response_t &response, reader_t& reader, const request_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        const request_method_t& method = request.method();

        LOGGER_IS_LOGGED_INFO("!(err = all_process_response_to_method(response, reader, method, request, argc, argv, env))...");
        if (!(err = all_process_response_to_method(response, reader, method, request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_process_response_to_method(response, reader, method, request, argc, argv, env))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = all_process_response_to_method(response, reader, method, request, argc, argv, env))");
        }
        return err;
    }
    virtual int before_process_response_to_request(response_t &response, reader_t& reader, const request_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_response_to_request(response_t &response, reader_t& reader, const request_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_response_to_request(response_t &response, reader_t& reader, const request_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_process_response_to_request(response, reader, request, argc, argv, env))) {
            int err2 = 0;
            err = process_response_to_request(response, reader, request, argc, argv, env);
            if ((err2 = after_process_response_to_request(response, reader, request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...process_response_to_method
    virtual int process_response_to_method(response_t &response, reader_t& reader, const request_method_t& method, const request_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        const request_method_which_t which = method.which();
        
        switch(which) {
        case xos::protocol::http::request::method::GET:
        LOGGER_IS_LOGGED_INFO("!(err = all_process_response_to_method_get(response, reader, method, request, argc, argv, env))...");
        if (!(err = all_process_response_to_method_get(response, reader, method, request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_process_response_to_method_get(response, reader, method, request, argc, argv, env))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = all_process_response_to_method_get(response, reader, method, request, argc, argv, env))");
        }
        break;

        case xos::protocol::http::request::method::POST:
        LOGGER_IS_LOGGED_INFO("!(err = all_process_response_to_method_post(response, reader, method, request, argc, argv, env))...");
        if (!(err = all_process_response_to_method_post(response, reader, method, request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_process_response_to_method_post(response, reader, method, request, argc, argv, env))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = all_process_response_to_method_post(response, reader, method, request, argc, argv, env))");
        }
        break;

        case xos::protocol::http::request::method::restart:
        LOGGER_IS_LOGGED_INFO("!(err = all_process_response_to_method_restart(response, reader, method, request, argc, argv, env))...");
        if (!(err = all_process_response_to_method_restart(response, reader, method, request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_process_response_to_method_restart(response, reader, method, request, argc, argv, env))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = all_process_response_to_method_restart(response, reader, method, request, argc, argv, env))");
        }
        break;

        case xos::protocol::http::request::method::start:
        LOGGER_IS_LOGGED_INFO("!(err = all_process_response_to_method_start(response, reader, method, request, argc, argv, env))...");
        if (!(err = all_process_response_to_method_start(response, reader, method, request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_process_response_to_method_start(response, reader, method, request, argc, argv, env))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = all_process_response_to_method_start(response, reader, method, request, argc, argv, env))");
        }
        break;

        case xos::protocol::http::request::method::stop:
        LOGGER_IS_LOGGED_INFO("!(err = all_process_response_to_method_stop(response, reader, method, request, argc, argv, env))...");
        if (!(err = all_process_response_to_method_stop(response, reader, method, request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_process_response_to_method_stop(response, reader, method, request, argc, argv, env))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = all_process_response_to_method_stop(response, reader, method, request, argc, argv, env))");
        }
        break;

        case xos::protocol::http::request::method::unknown:
        default:
            LOGGER_IS_LOGGED_INFO("!(err = all_process_response_to_method_unknown(response, reader, method, request, argc, argv, env))...");
            if (!(err = all_process_response_to_method_unknown(response, reader, method, request, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_process_response_to_method_unknown(response, reader, method, request, argc, argv, env))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = all_process_response_to_method_unknown(response, reader, method, request, argc, argv, env))");
            }
            break;
        } /// switch(which)
        return err;
    }
    virtual int before_process_response_to_method(response_t &response, reader_t& reader, const request_method_t& method, const request_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_response_to_method(response_t &response, reader_t& reader, const request_method_t& method, const request_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_response_to_method(response_t &response, reader_t& reader, const request_method_t& method, const request_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_process_response_to_method(response, reader, method, request, argc, argv, env))) {
            int err2 = 0;
            err = process_response_to_method(response, reader, method, request, argc, argv, env);
            if ((err2 = after_process_response_to_method(response, reader, method, request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...process_response_to_method_get
    virtual int process_response_to_method_get(response_t &response, reader_t& reader, const request_method_t& method, const request_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("!(err = all_process_response_to_method_any(response, reader, method, request, argc, argv, env))...");
        if (!(err = all_process_response_to_method_any(response, reader, method, request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_process_response_to_method_any(response, reader, method, request, argc, argv, env))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = all_process_response_to_method_any(response, reader, method, request, argc, argv, env))");
        }
        return err;
    }
    virtual int before_process_response_to_method_get(response_t &response, reader_t& reader, const request_method_t& method, const request_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_response_to_method_get(response_t &response, reader_t& reader, const request_method_t& method, const request_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_response_to_method_get(response_t &response, reader_t& reader, const request_method_t& method, const request_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_process_response_to_method_get(response, reader, method, request, argc, argv, env))) {
            int err2 = 0;
            err = process_response_to_method_get(response, reader, method, request, argc, argv, env);
            if ((err2 = after_process_response_to_method_get(response, reader, method, request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...process_response_to_method_post
    virtual int process_response_to_method_post(response_t &response, reader_t& reader, const request_method_t& method, const request_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("!(err = all_process_response_to_method_any(response, reader, method, request, argc, argv, env))...");
        if (!(err = all_process_response_to_method_any(response, reader, method, request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_process_response_to_method_any(response, reader, method, request, argc, argv, env))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = all_process_response_to_method_any(response, reader, method, request, argc, argv, env))");
        }
        return err;
    }
    virtual int before_process_response_to_method_post(response_t &response, reader_t& reader, const request_method_t& method, const request_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_response_to_method_post(response_t &response, reader_t& reader, const request_method_t& method, const request_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_response_to_method_post(response_t &response, reader_t& reader, const request_method_t& method, const request_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_process_response_to_method_post(response, reader, method, request, argc, argv, env))) {
            int err2 = 0;
            err = process_response_to_method_post(response, reader, method, request, argc, argv, env);
            if ((err2 = after_process_response_to_method_post(response, reader, method, request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...process_response_to_method_restart
    virtual int process_response_to_method_restart(response_t &response, reader_t& reader, const request_method_t& method, const request_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_process_response_to_method_restart(response_t &response, reader_t& reader, const request_method_t& method, const request_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_response_to_method_restart(response_t &response, reader_t& reader, const request_method_t& method, const request_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_response_to_method_restart(response_t &response, reader_t& reader, const request_method_t& method, const request_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_process_response_to_method_restart(response, reader, method, request, argc, argv, env))) {
            int err2 = 0;
            err = process_response_to_method_restart(response, reader, method, request, argc, argv, env);
            if ((err2 = after_process_response_to_method_restart(response, reader, method, request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...process_response_to_method_start
    virtual int process_response_to_method_start(response_t &response, reader_t& reader, const request_method_t& method, const request_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_process_response_to_method_start(response_t &response, reader_t& reader, const request_method_t& method, const request_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_response_to_method_start(response_t &response, reader_t& reader, const request_method_t& method, const request_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_response_to_method_start(response_t &response, reader_t& reader, const request_method_t& method, const request_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_process_response_to_method_start(response, reader, method, request, argc, argv, env))) {
            int err2 = 0;
            err = process_response_to_method_start(response, reader, method, request, argc, argv, env);
            if ((err2 = after_process_response_to_method_start(response, reader, method, request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...process_response_to_method_stop
    virtual int process_response_to_method_stop(response_t &response, reader_t& reader, const request_method_t& method, const request_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_process_response_to_method_stop(response_t &response, reader_t& reader, const request_method_t& method, const request_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_response_to_method_stop(response_t &response, reader_t& reader, const request_method_t& method, const request_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_response_to_method_stop(response_t &response, reader_t& reader, const request_method_t& method, const request_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_process_response_to_method_stop(response, reader, method, request, argc, argv, env))) {
            int err2 = 0;
            err = process_response_to_method_stop(response, reader, method, request, argc, argv, env);
            if ((err2 = after_process_response_to_method_stop(response, reader, method, request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...process_response_to_method_unknown
    virtual int process_response_to_method_unknown(response_t &response, reader_t& reader, const request_method_t& method, const request_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_process_response_to_method_unknown(response_t &response, reader_t& reader, const request_method_t& method, const request_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_response_to_method_unknown(response_t &response, reader_t& reader, const request_method_t& method, const request_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_response_to_method_unknown(response_t &response, reader_t& reader, const request_method_t& method, const request_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_process_response_to_method_unknown(response, reader, method, request, argc, argv, env))) {
            int err2 = 0;
            err = process_response_to_method_unknown(response, reader, method, request, argc, argv, env);
            if ((err2 = after_process_response_to_method_unknown(response, reader, method, request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...process_response_to_method_any
    virtual int process_response_to_method_any(response_t &response, reader_t& reader, const request_method_t& method, const request_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        const content_t* request_content = 0;
        
        LOGGER_IS_LOGGED_INFO("(request_content = request.content())...");
        if ((request_content = request.content())) {
            const content_t& content = *request_content;
            size_t content_length = content.length();

            LOGGER_IS_LOGGED_INFO("...(request_content = request.content())");
            LOGGER_IS_LOGGED_INFO("(0 < (content_length = content.length()))...");
            if ((0 < (content_length = content.length()))) {
                const content_type_char_t* content_type_chars = 0;

                LOGGER_IS_LOGGED_INFO("(content_type_chars = request.content_type_chars())...");
                if ((content_type_chars = request.content_type_chars())) {
                    int unequal = 0;
                    const url_encoded_form_content_type_t url_encoded_form_content_type;

                    LOGGER_IS_LOGGED_INFO("...(\"" << content_type_chars << "\" = request.content_type_chars())");
                    LOGGER_IS_LOGGED_INFO("!(unequal = url_encoded_form_content_type.compare(c\"" << content_type_chars << "\"))...");
                    if (!(unequal = url_encoded_form_content_type.compare(content_type_chars))) {
                        content_part_reader_t content_part_reader(content);
                        url_encoded_content_reader_t url_encoded_content_reader(content_part_reader);
                        
                        LOGGER_IS_LOGGED_INFO("...!(" << unequal << " = url_encoded_form_content_type.compare(\"" << content_type_chars << "\"))");
                    } else {
                        LOGGER_IS_LOGGED_INFO("...failed on !(" << unequal << " = url_encoded_form_content_type.compare(\"" << content_type_chars << "\"))");
                    }
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed on (" << content_type_chars << " = request.content_type_chars())");
                }
                LOGGER_IS_LOGGED_INFO("...(0 < (" << content_length << " = content.length()))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (0 < (" << content_length << " = content.length()))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (request_content = request.content())");
        }
        return err;
    }
    virtual int before_process_response_to_method_any(response_t &response, reader_t& reader, const request_method_t& method, const request_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_response_to_method_any(response_t &response, reader_t& reader, const request_method_t& method, const request_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_response_to_method_any(response_t &response, reader_t& reader, const request_method_t& method, const request_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_process_response_to_method_any(response, reader, method, request, argc, argv, env))) {
            int err2 = 0;
            err = process_response_to_method_any(response, reader, method, request, argc, argv, env);
            if ((err2 = after_process_response_to_method_any(response, reader, method, request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    /// ...read_request
    virtual int read_request(ssize_t& amount, request_t& request, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        char_t c = 0;
        request.read(amount, c, reader);
        return err;
    }
    virtual int before_read_request(ssize_t& amount, request_t& request, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_read_request(ssize_t& amount, request_t& request, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_read_request(ssize_t& amount, request_t& request, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_read_request(amount, request, reader, argc, argv, env))) {
            int err2 = 0;
            err = read_request(amount, request, reader, argc, argv, env);
            if ((err2 = after_read_request(amount, request, reader, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...read_request_with_content
    virtual int read_request_with_content(ssize_t& amount, request_t& request, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        char_t c = 0;
        request.read_with_content(amount, c, reader);
        return err;
    }
    virtual int before_read_request_with_content(ssize_t& amount, request_t& request, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_read_request_with_content(ssize_t& amount, request_t& request, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_read_request_with_content(ssize_t& amount, request_t& request, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_read_request_with_content(amount, request, reader, argc, argv, env))) {
            int err2 = 0;
            err = read_request_with_content(amount, request, reader, argc, argv, env);
            if ((err2 = after_read_request_with_content(amount, request, reader, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...write_response
    virtual int write_response(ssize_t& amount, writer_t& writer, response_t& response, int argc, char_t** argv, char** env) {
        int err = 0;
        response.write(amount, writer);
        return err;
    }
    virtual int before_write_response(ssize_t& amount, writer_t& writer, response_t& response, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_write_response(ssize_t& amount, writer_t& writer, response_t& response, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_write_response(ssize_t& amount, writer_t& writer, response_t& response, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_write_response(amount, writer, response, argc, argv, env))) {
            int err2 = 0;
            err = write_response(amount, writer, response, argc, argv, env);
            if ((err2 = after_write_response(amount, writer, response, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    /// ...set_response_content
    virtual int set_response_content(headers_t& headers, content_t& content, int argc, char_t** argv, char** env) {
        response_line_t& response_line = this->response_line();
        response_t& response = this->response();
        int err = 0;
        response.set(response_line, headers, content);
        return err;
    }
    virtual int before_set_response_content(headers_t& headers, content_t& content, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_response_content(headers_t& headers, content_t& content, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_response_content(headers_t& headers, content_t& content, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_set_response_content(headers, content, argc, argv, env))) {
            int err2 = 0;
            err = set_response_content(headers, content, argc, argv, env);
            if ((err2 = after_set_response_content(headers, content, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// response...
    virtual response_string_t& response_literal() const {
        return (response_string_t&)response_literal_;
    }
    virtual response_t& response() const {
        return (response_t&)response_;
    }
    virtual headers_t& response_headers() const {
        return (headers_t&)response_headers_;
    }
    virtual response_line_t& response_line() const {
        return (response_line_t&)response_line_;
    }
    virtual response_reason_t& response_reason() const {
        return (response_reason_t&)reason_;
    }
    virtual response_status_t& set_response_status_ok() {
        return set_response_status(response_status_ok());
    }
    virtual response_status_t& response_status_ok() const {
        return (response_status_t&)ok_;
    }
    virtual response_status_t& set_response_status_not_found() {
        return set_response_status(response_status_not_found());
    }
    virtual response_status_t& response_status_not_found() const {
        return (response_status_t&)not_found_;
    }
    virtual response_status_t& set_response_status(const response_status_t& to) {
        return set_response_status(to.chars());
    }
    virtual response_status_t& set_response_status(const char_t* to) {
        response_status_t& status_ = this->response_status();
        response_reason_t& reason_ = this->response_reason();
        response_line_t& response_line_ = this->response_line();
        response_t& response_ = this->response();
        status_.set(to);
        reason_.set(status_);
        response_line_.set_status(status_);
        response_line_.set_reason(reason_);
        response_.set_status(status_);
        response_.set_reason(reason_);
        response_.set_line(response_line_);
        return (response_status_t&)status_;
    }
    virtual response_status_t& response_status() const {
        return (response_status_t&)status_;
    }
    virtual const content_type_t& set_response_content_type(const string_t& to) {
        size_t to_length = 0;
        const char_t* to_chars = to.has_chars(to_length);
        return set_response_content_type(to_chars, to_length);
    }
    virtual const content_type_t& set_response_content_type(const char_t* to, size_t length) {
        headers_t& headers = this->response_headers();
        if ((to) && (length)) {
            response_line_t& response_line = this->response_line();
            response_t& response = this->response();
            content_t& content = this->content();
            headers.set_content_type(to, length);
            response.set(response_line, headers, content);
        }
        return headers.content_type();
    }
    virtual content_t& set_response_content(const string_t& to) {
        size_t to_length = 0;
        const char_t* to_chars = to.has_chars(to_length);
        return set_response_content(to_chars, to_length);
    }
    virtual content_t& set_response_content(const char_t* to, size_t length) {
        content_t& content = this->content();
        if ((to) && (length)) {
            response_line_t& response_line = this->response_line();
            headers_t& headers = this->response_headers();
            response_t& response = this->response();
            headers.set_content_length(length);
            content.set(to, length);
            response.set(response_line, headers, content);
        }
        return content;
    }

    /// ...request...
    virtual content_t& request_content() const {
        return (content_t&)request_content_;
    }
    virtual form_fields_t& request_form() const {
        return (form_fields_t&)request_form_;
    }
    virtual request_t& request() const {
        return (request_t&)request_;
    }

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

protected:
    xos::protocol::http::response::status::codeof::OK ok_;
    xos::protocol::http::response::status::codeof::Not_Found not_found_;
    xos::protocol::http::response::status::code status_;
    xos::protocol::http::response::status::reason reason_;

    xos::protocol::http::response::line response_line_;
    xos::protocol::http::message::header::fields response_headers_;
    xos::protocol::http::response::message response_;
    xos::protocol::http::response::message::string_t response_literal_;

    xos::protocol::http::message::body::content request_content_;
    xos::protocol::http::form::fields request_form_;
    xos::protocol::http::request::message request_;
}; /// class maint 
typedef maint<> main;

} /// namespace server 
} /// namespace xttp 
} /// namespace protocol 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_HPP
