/***************************************************************
 * Generated by Hottentot CC Generator
 * Date: 25-03-2016 12:32:53
 * Name: hello_service_proxy.h
 * Description:
 *   This file contains definition of the proxy class.
 ***************************************************************/

#ifndef _IR_NTNAEEM_HOTTENTOT_EXAMPLES_TIMEOUT_ON_READ__PROXY__HELLO_SERVICE_PROXY_H_
#define _IR_NTNAEEM_HOTTENTOT_EXAMPLES_TIMEOUT_ON_READ__PROXY__HELLO_SERVICE_PROXY_H_

#ifdef _MSC_VER
typedef __int8 int8_t;
typedef unsigned __int8 uint8_t;
typedef __int16 int16_t;
typedef unsigned __int16 uint16_t;
typedef __int32 int32_t;
typedef unsigned __int32 uint32_t;
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;
#else
#include <stdint.h>
#endif

#include <string>

#include <naeem/hottentot/runtime/types/primitives.h>
#include <naeem/hottentot/runtime/proxy/proxy.h>

#include "hello_service.h"
#include "../enums.h"


namespace ir {
namespace ntnaeem {
namespace hottentot {
namespace examples {
namespace timeout_on_read {

namespace proxy {
  class HelloServiceProxy : public HelloService, 
    public ::naeem::hottentot::runtime::proxy::Proxy {
  public:
    HelloServiceProxy(std::string host, uint32_t port) 
      : ::naeem::hottentot::runtime::proxy::Proxy(host, port) {}
    virtual ~HelloServiceProxy() {}
  public:
    virtual void SayHelloTo(
      ::naeem::hottentot::runtime::types::Utf8String &name, 
      ::naeem::hottentot::runtime::types::Utf8String &out
    );
  };
} // END OF NAMESPACE proxy
} // END OF NAMESPACE timeout_on_read
} // END OF NAMESPACE examples
} // END OF NAMESPACE hottentot
} // END OF NAMESPACE ntnaeem
} // END OF NAMESPACE ir

#endif