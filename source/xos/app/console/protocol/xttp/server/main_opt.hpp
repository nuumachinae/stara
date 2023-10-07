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
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 9/2/2023, 10/7/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_OPT_HPP

#include "xos/app/console/protocol/xttp/base/main.hpp"

#define XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_REQUEST_OPT "request"
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_REQUEST_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_REQUEST_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_REQUEST_OPTARG "[string]"
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_REQUEST_OPTUSE \
    XOS_APP_CONSOLE_PROTOCOL_XTTP_BASE_MAIN_PROTOCOL_name " request"
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_REQUEST_OPTVAL_S "r::"
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_REQUEST_OPTVAL_C 'r'
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_REQUEST_OPTION \
   {XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_REQUEST_OPT, \
    XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_REQUEST_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_REQUEST_OPTARG_RESULT, \
    XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_REQUEST_OPTVAL_C}, \

#define XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_RESPONSE_OPT "response"
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_RESPONSE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_RESPONSE_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_RESPONSE_OPTARG "[string]"
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_RESPONSE_OPTUSE \
    XOS_APP_CONSOLE_PROTOCOL_XTTP_BASE_MAIN_PROTOCOL_name " response"
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_RESPONSE_OPTVAL_S "s::"
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_RESPONSE_OPTVAL_C 's'
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_RESPONSE_OPTION \
   {XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_RESPONSE_OPT, \
    XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_RESPONSE_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_RESPONSE_OPTARG_RESULT, \
    XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_RESPONSE_OPTVAL_C}, \

#define XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_STATUS_OK_OPT "ok"
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_STATUS_OK_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_STATUS_OK_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_STATUS_OK_OPTARG "[0..n]"
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_STATUS_OK_OPTUSE "OK " \
    XOS_APP_CONSOLE_PROTOCOL_XTTP_BASE_MAIN_PROTOCOL_name " response status"
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_STATUS_OK_OPTVAL_S "k::"
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_STATUS_OK_OPTVAL_C 'k'
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_STATUS_OK_OPTION \
   {XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_STATUS_OK_OPT, \
    XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_STATUS_OK_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_STATUS_OK_OPTARG_RESULT, \
    XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_STATUS_OK_OPTVAL_C}, \

#define XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_STATUS_NOT_FOUND_OPT "not-found"
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_STATUS_NOT_FOUND_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_STATUS_NOT_FOUND_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_STATUS_NOT_FOUND_OPTARG "[0..n]"
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_STATUS_NOT_FOUND_OPTUSE "Not Found " \
    XOS_APP_CONSOLE_PROTOCOL_XTTP_BASE_MAIN_PROTOCOL_name " response status"
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_STATUS_NOT_FOUND_OPTVAL_S "d::"
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_STATUS_NOT_FOUND_OPTVAL_C 'd'
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_STATUS_NOT_FOUND_OPTION \
   {XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_STATUS_NOT_FOUND_OPT, \
    XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_STATUS_NOT_FOUND_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_STATUS_NOT_FOUND_OPTARG_RESULT, \
    XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_STATUS_NOT_FOUND_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_OPTIONS_CHARS_EXTEND \
    XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_REQUEST_OPTVAL_S \
    XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_RESPONSE_OPTVAL_S \
    XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_STATUS_OK_OPTVAL_S \
    XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_STATUS_NOT_FOUND_OPTVAL_S \

#define XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_OPTIONS_OPTIONS_EXTEND \
    XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_REQUEST_OPTION \
    XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_RESPONSE_OPTION \
    XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_STATUS_OK_OPTION \
    XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_STATUS_NOT_FOUND_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_LOGGING_OPTIONS_CHARS \
   XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_PROTOCOL_XTTP_BASE_MAIN_LOGGING_OPTIONS_CHARS

#define XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_LOGGING_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_PROTOCOL_XTTP_BASE_MAIN_LOGGING_OPTIONS_OPTIONS

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_PROTOCOL_XTTP_BASE_MAIN_OPTIONS_CHARS

#define XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_PROTOCOL_XTTP_BASE_MAIN_OPTIONS_OPTIONS

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_ARGS 0
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_ARGV 0,

namespace xos {
namespace app {
namespace console {
namespace protocol {
namespace xttp {
namespace server {

/// class main_optt
template 
<class TExtends = xos::app::console::protocol::xttp::base::maint<>,  class TImplements = typename TExtends::implements>

class main_optt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef main_optt derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;

    /// constructor / destructor
    main_optt(): run_(0) {
    }
    virtual ~main_optt() {
    }
private:
    main_optt(const main_optt &copy) {
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

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////

    /// ...request_run
    virtual int request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_request_run(argc, argv, env))) {
            int err2 = 0;
            err = request_run(argc, argv, env);
            if ((err2 = after_request_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_request_run;
        return err;
    }
    virtual int request_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int request_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    /// ...file_request_run
    virtual int file_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_file_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_file_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_file_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_file_request_run(argc, argv, env))) {
            int err2 = 0;
            err = file_request_run(argc, argv, env);
            if ((err2 = after_file_request_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_file_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_file_request_run;
        return err;
    }
    virtual int file_request_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_file_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int file_request_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    /// ...response_run
    int (derives::*response_run_)(int argc, char_t** argv, char_t** env);
    virtual int response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (response_run_) {
            if (!(err = (this->*response_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_response_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = extends::run(argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int before_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_response_run(argc, argv, env))) {
            int err2 = 0;
            err = response_run(argc, argv, env);
            if ((err2 = after_response_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_response_run;
        return err;
    }
    virtual int response_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int response_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    /// ...status_run
    int (derives::*status_run_)(int argc, char_t** argv, char_t** env);
    virtual int status_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (status_run_) {
            if (!(err = (this->*status_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_status_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_status_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = extends::run(argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int before_status_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_status_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_status_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_status_run(argc, argv, env))) {
            int err2 = 0;
            err = status_run(argc, argv, env);
            if ((err2 = after_status_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_status_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_status_run;
        return err;
    }
    virtual int status_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_status_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int status_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////

    /// on...request_option...
    virtual int on_get_request_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_request_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_request_run(argc, argv, env))) {
            if (!(err = request_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_request_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            string_t& request_filename = this->request_filename();
            request_filename.assign(optarg);
        } else {
        }
        return err;
    }
    virtual int on_request_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = set_file_request_run(argc, argv, env))) {
                if (!(err = file_request_run_set(argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = set_request_run(argc, argv, env))) {
                if (!(err = request_run_set(argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual int on_request_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_request_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_request_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_request_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_request_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* request_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_REQUEST_OPTUSE;
        optarg = XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_REQUEST_OPTARG;
        return chars;
    }

    /// on...response_option...
    virtual int on_get_response_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_response_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_response_run(argc, argv, env))) {
            if (!(err = response_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_response_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_response_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_response_run(argc, argv, env))) {
            if (!(err = response_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_response_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_response_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_response_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_response_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_response_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* response_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_RESPONSE_OPTUSE;
        optarg = XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_RESPONSE_OPTARG;
        return chars;
    }

    /// on...status_ok_option...
    virtual int on_get_status_ok_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_set_status_ok_option(optarg, optind, argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int on_status_ok_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_status_run(argc, argv, env))) {
            if (!(err = status_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_status_ok_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_status_ok_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_status_run(argc, argv, env))) {
            if (!(err = status_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_status_ok_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_status_ok_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_status_ok_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_status_ok_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_status_ok_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* status_ok_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_STATUS_OK_OPTUSE;
        optarg = XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_STATUS_OK_OPTARG;
        return chars;
    }

    /// on...status_not_found_option...
    virtual int on_get_status_not_found_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_set_status_not_found_option(optarg, optind, argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int on_status_not_found_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_status_run(argc, argv, env))) {
            if (!(err = status_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_status_not_found_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_status_not_found_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_status_run(argc, argv, env))) {
            if (!(err = status_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_status_not_found_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_status_not_found_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_status_not_found_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_status_not_found_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_status_not_found_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* status_not_found_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_STATUS_NOT_FOUND_OPTUSE;
        optarg = XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_STATUS_NOT_FOUND_OPTARG;
        return chars;
    }

    /// on_option
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {

        case XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_REQUEST_OPTVAL_C:
            err = this->on_request_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_RESPONSE_OPTVAL_C:
            err = this->on_response_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        case XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_STATUS_OK_OPTVAL_C:
            err = this->on_status_ok_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_STATUS_NOT_FOUND_OPTVAL_C:
            err = this->on_status_not_found_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    
    /// option_usage
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {

        case XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_REQUEST_OPTVAL_C:
            chars = this->request_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_RESPONSE_OPTVAL_C:
            chars = this->response_option_usage(optarg, longopt);
            break;

        case XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_STATUS_OK_OPTVAL_C:
            chars = this->status_ok_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_STATUS_NOT_FOUND_OPTVAL_C:
            chars = this->status_not_found_option_usage(optarg, longopt);
            break;

        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }

    /// options
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// arguments
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

    /// ...request_filename
    virtual string_t& set_request_filename(const string_t& to) {
        string_t& request_filename = this->request_filename();
        request_filename.assign(to);
        return request_filename;
    }
    virtual string_t& set_request_filename(const char_t* to) {
        string_t& request_filename = this->request_filename();
        request_filename.assign(to);
        return request_filename;
    }
    virtual string_t& set_request_filename(const char_t* to, size_t length) {
        string_t& request_filename = this->request_filename();
        request_filename.assign(to, length);
        return request_filename;
    }
    virtual string_t& request_filename() const {
        return (string_t&)request_filename_;
    }

    /// ...file_reader
    virtual file_reader_t& file_reader() const {
        return (file_reader_t&)file_reader_;
    }
    
protected:
    string_t request_filename_;
    file_reader_t file_reader_;
}; /// class main_optt 
typedef main_optt<> main_opt;

} /// namespace server 
} /// namespace xttp 
} /// namespace protocol 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_OPT_HPP
