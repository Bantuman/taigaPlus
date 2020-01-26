#pragma once

#include <limits>
#include <string_view>

namespace hypp::status {

// status-code = 3DIGIT
using code_t = int;
static_assert(std::numeric_limits<code_t>::max() >= 999);

// > The first digit of the status-code defines the class of response. The last
// two digits do not have any categorization role.
// Reference: https://tools.ietf.org/html/rfc7231#section-6
enum Class : code_t {
  k1xx_Informational = 100,  // > The request was received, continuing process
  k2xx_Successful = 200,     // > The request was successfully received, understood, and accepted
  k3xx_Redirection = 300,    // > Further action needs to be taken in order to complete the request
  k4xx_Client_Error = 400,   // > The request contains bad syntax or cannot be fulfilled
  k5xx_Server_Error = 500,   // > The server failed to fulfill an apparently valid request
};

// Reference: https://tools.ietf.org/html/rfc7231#section-6.1
// Reference: https://www.iana.org/assignments/http-status-codes
enum Code : code_t {
  // Do not modify this list. It is automatically generated by a script.
  // @http-status-codes-begin
  k100_Continue = 100,                         // [RFC7231, Section 6.2.1]
  k101_Switching_Protocols = 101,              // [RFC7231, Section 6.2.2]
  k102_Processing = 102,                       // [RFC2518]
  k103_Early_Hints = 103,                      // [RFC8297]
  k200_OK = 200,                               // [RFC7231, Section 6.3.1]
  k201_Created = 201,                          // [RFC7231, Section 6.3.2]
  k202_Accepted = 202,                         // [RFC7231, Section 6.3.3]
  k203_NonAuthoritative_Information = 203,     // [RFC7231, Section 6.3.4]
  k204_No_Content = 204,                       // [RFC7231, Section 6.3.5]
  k205_Reset_Content = 205,                    // [RFC7231, Section 6.3.6]
  k206_Partial_Content = 206,                  // [RFC7233, Section 4.1]
  k207_MultiStatus = 207,                      // [RFC4918]
  k208_Already_Reported = 208,                 // [RFC5842]
  k226_IM_Used = 226,                          // [RFC3229]
  k300_Multiple_Choices = 300,                 // [RFC7231, Section 6.4.1]
  k301_Moved_Permanently = 301,                // [RFC7231, Section 6.4.2]
  k302_Found = 302,                            // [RFC7231, Section 6.4.3]
  k303_See_Other = 303,                        // [RFC7231, Section 6.4.4]
  k304_Not_Modified = 304,                     // [RFC7232, Section 4.1]
  k305_Use_Proxy = 305,                        // [RFC7231, Section 6.4.5]
  k307_Temporary_Redirect = 307,               // [RFC7231, Section 6.4.7]
  k308_Permanent_Redirect = 308,               // [RFC7538]
  k400_Bad_Request = 400,                      // [RFC7231, Section 6.5.1]
  k401_Unauthorized = 401,                     // [RFC7235, Section 3.1]
  k402_Payment_Required = 402,                 // [RFC7231, Section 6.5.2]
  k403_Forbidden = 403,                        // [RFC7231, Section 6.5.3]
  k404_Not_Found = 404,                        // [RFC7231, Section 6.5.4]
  k405_Method_Not_Allowed = 405,               // [RFC7231, Section 6.5.5]
  k406_Not_Acceptable = 406,                   // [RFC7231, Section 6.5.6]
  k407_Proxy_Authentication_Required = 407,    // [RFC7235, Section 3.2]
  k408_Request_Timeout = 408,                  // [RFC7231, Section 6.5.7]
  k409_Conflict = 409,                         // [RFC7231, Section 6.5.8]
  k410_Gone = 410,                             // [RFC7231, Section 6.5.9]
  k411_Length_Required = 411,                  // [RFC7231, Section 6.5.10]
  k412_Precondition_Failed = 412,              // [RFC7232, Section 4.2] [RFC8144, Section 3.2]
  k413_Payload_Too_Large = 413,                // [RFC7231, Section 6.5.11]
  k414_URI_Too_Long = 414,                     // [RFC7231, Section 6.5.12]
  k415_Unsupported_Media_Type = 415,           // [RFC7231, Section 6.5.13] [RFC7694, Section 3]
  k416_Range_Not_Satisfiable = 416,            // [RFC7233, Section 4.4]
  k417_Expectation_Failed = 417,               // [RFC7231, Section 6.5.14]
  k421_Misdirected_Request = 421,              // [RFC7540, Section 9.1.2]
  k422_Unprocessable_Entity = 422,             // [RFC4918]
  k423_Locked = 423,                           // [RFC4918]
  k424_Failed_Dependency = 424,                // [RFC4918]
  k426_Upgrade_Required = 426,                 // [RFC7231, Section 6.5.15]
  k428_Precondition_Required = 428,            // [RFC6585]
  k429_Too_Many_Requests = 429,                // [RFC6585]
  k431_Request_Header_Fields_Too_Large = 431,  // [RFC6585]
  k451_Unavailable_For_Legal_Reasons = 451,    // [RFC7725]
  k500_Internal_Server_Error = 500,            // [RFC7231, Section 6.6.1]
  k501_Not_Implemented = 501,                  // [RFC7231, Section 6.6.2]
  k502_Bad_Gateway = 502,                      // [RFC7231, Section 6.6.3]
  k503_Service_Unavailable = 503,              // [RFC7231, Section 6.6.4]
  k504_Gateway_Timeout = 504,                  // [RFC7231, Section 6.6.5]
  k505_HTTP_Version_Not_Supported = 505,       // [RFC7231, Section 6.6.6]
  k506_Variant_Also_Negotiates = 506,          // [RFC2295]
  k507_Insufficient_Storage = 507,             // [RFC4918]
  k508_Loop_Detected = 508,                    // [RFC5842]
  k510_Not_Extended = 510,                     // [RFC2774]
  k511_Network_Authentication_Required = 511,  // [RFC6585]
  // @http-status-codes-end
  k418_Im_a_Teapot = 418,                      // [RFC2324, Section 2.3.2] [RFC7168, Section 2.3.3]
};

// > A client MUST (...) treat an unrecognized status code as being equivalent
// to the x00 status code of that class, (...). For example, if an unrecognized
// status code of 471 is received by a client, the client can (...) treat the
// response as if it had received a 400 (Bad Request) status code.
// Reference: https://tools.ietf.org/html/rfc7231#section-6
constexpr code_t to_class(const code_t code) {
  return static_cast<code_t>((code / 100) * 100);
}

// Reference: https://tools.ietf.org/html/rfc7231#section-6.1
// Reference: https://www.iana.org/assignments/http-status-codes
constexpr const std::string_view to_phrase(const code_t code) {
  switch (code) {
    // Do not modify this list. It is automatically generated by a script.
    // @http-status-phrases-begin
    case 100: return "Continue";
    case 101: return "Switching Protocols";
    case 102: return "Processing";
    case 103: return "Early Hints";
    case 200: return "OK";
    case 201: return "Created";
    case 202: return "Accepted";
    case 203: return "Non-Authoritative Information";
    case 204: return "No Content";
    case 205: return "Reset Content";
    case 206: return "Partial Content";
    case 207: return "Multi-Status";
    case 208: return "Already Reported";
    case 226: return "IM Used";
    case 300: return "Multiple Choices";
    case 301: return "Moved Permanently";
    case 302: return "Found";
    case 303: return "See Other";
    case 304: return "Not Modified";
    case 305: return "Use Proxy";
    case 307: return "Temporary Redirect";
    case 308: return "Permanent Redirect";
    case 400: return "Bad Request";
    case 401: return "Unauthorized";
    case 402: return "Payment Required";
    case 403: return "Forbidden";
    case 404: return "Not Found";
    case 405: return "Method Not Allowed";
    case 406: return "Not Acceptable";
    case 407: return "Proxy Authentication Required";
    case 408: return "Request Timeout";
    case 409: return "Conflict";
    case 410: return "Gone";
    case 411: return "Length Required";
    case 412: return "Precondition Failed";
    case 413: return "Payload Too Large";
    case 414: return "URI Too Long";
    case 415: return "Unsupported Media Type";
    case 416: return "Range Not Satisfiable";
    case 417: return "Expectation Failed";
    case 421: return "Misdirected Request";
    case 422: return "Unprocessable Entity";
    case 423: return "Locked";
    case 424: return "Failed Dependency";
    case 426: return "Upgrade Required";
    case 428: return "Precondition Required";
    case 429: return "Too Many Requests";
    case 431: return "Request Header Fields Too Large";
    case 451: return "Unavailable For Legal Reasons";
    case 500: return "Internal Server Error";
    case 501: return "Not Implemented";
    case 502: return "Bad Gateway";
    case 503: return "Service Unavailable";
    case 504: return "Gateway Timeout";
    case 505: return "HTTP Version Not Supported";
    case 506: return "Variant Also Negotiates";
    case 507: return "Insufficient Storage";
    case 508: return "Loop Detected";
    case 510: return "Not Extended";
    case 511: return "Network Authentication Required";
    // @http-status-phrases-end
    case 418: return "I'm a Teapot";
    default:
      return {};
  }
}

}  // namespace hypp::status