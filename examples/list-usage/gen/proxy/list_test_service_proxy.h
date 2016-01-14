/***************************************************************
 * Generated by Hottentot CC Generator
 * Date: 14-01-2016 11:14:25
 * Name: list_test_service_proxy.h
 * Description:
 *   This file contains definition of the proxy class.
 ***************************************************************/

#ifndef _IR_NTNAEEM_HOTTENTOT_EXAMPLES_LISTTEST__PROXY__LIST_TEST_SERVICE_PROXY_H_
#define _IR_NTNAEEM_HOTTENTOT_EXAMPLES_LISTTEST__PROXY__LIST_TEST_SERVICE_PROXY_H_

#include <stdint.h>
#include <string>

#include <naeem/hottentot/runtime/types/primitives.h>
#include <naeem/hottentot/runtime/proxy/proxy.h>

#include "../list_test_service.h"


namespace ir {
namespace ntnaeem {
namespace hottentot {
namespace examples {
namespace listtest {
class Message;
namespace proxy {
  class ListTestServiceProxy : public ::ir::ntnaeem::hottentot::examples::listtest::ListTestService, 
    public ::naeem::hottentot::runtime::proxy::Proxy {
  public:
    ListTestServiceProxy(std::string host, uint32_t port) 
      : ::naeem::hottentot::runtime::proxy::Proxy(host, port) {}
    virtual ~ListTestServiceProxy() {}
  public:
    virtual void AddNames(::naeem::hottentot::runtime::types::List< ::naeem::hottentot::runtime::types::Utf8String> &names);
    virtual void GetNames(::naeem::hottentot::runtime::types::List< ::naeem::hottentot::runtime::types::Utf8String> &);
    virtual void GetMessages(::naeem::hottentot::runtime::types::List< ::ir::ntnaeem::hottentot::examples::listtest::Message> &);
    virtual void AddMessage(::ir::ntnaeem::hottentot::examples::listtest::Message &message);
  };
} // END OF NAMESPACE proxy
} // END OF NAMESPACE listtest
} // END OF NAMESPACE examples
} // END OF NAMESPACE hottentot
} // END OF NAMESPACE ntnaeem
} // END OF NAMESPACE ir

#endif