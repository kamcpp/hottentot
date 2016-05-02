/***************************************************************
 * Generated by Hottentot CC Generator
 * Date: 06-02-2016 03:43:41
 * Name: list_test_service.h
 * Description:
 *   This file contains definition of service interface.
 ***************************************************************/

#ifndef _IR_NTNAEEM_HOTTENTOT_EXAMPLES_LISTTEST__SERVICE__LIST_TEST_SERVICE_H_
#define _IR_NTNAEEM_HOTTENTOT_EXAMPLES_LISTTEST__SERVICE__LIST_TEST_SERVICE_H_

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
#include <naeem/hottentot/runtime/service/hot_context.h>

#include "../message.h"


namespace ir {
namespace ntnaeem {
namespace hottentot {
namespace examples {
namespace listtest {
namespace service {
  class ListTestService {
  public:
     ListTestService() {}
     virtual ~ListTestService() {}
  public:
    virtual void AddNames(
      ::naeem::hottentot::runtime::types::List< ::naeem::hottentot::runtime::types::Utf8String> &names, 
      ::naeem::hottentot::runtime::service::HotContext &hotContext
    ) = 0;
    virtual void GetNames(
      ::naeem::hottentot::runtime::types::List< ::naeem::hottentot::runtime::types::Utf8String> &out, 
      ::naeem::hottentot::runtime::service::HotContext &hotContext
    ) = 0;
    virtual void GetMessages(
      ::naeem::hottentot::runtime::types::List< ::ir::ntnaeem::hottentot::examples::listtest::Message> &out, 
      ::naeem::hottentot::runtime::service::HotContext &hotContext
    ) = 0;
    virtual void AddMessage(
      ::ir::ntnaeem::hottentot::examples::listtest::Message &message, 
      ::naeem::hottentot::runtime::service::HotContext &hotContext
    ) = 0;
  };
} // END OF NAMESPACE service
} // END OF NAMESPACE listtest
} // END OF NAMESPACE examples
} // END OF NAMESPACE hottentot
} // END OF NAMESPACE ntnaeem
} // END OF NAMESPACE ir

#endif