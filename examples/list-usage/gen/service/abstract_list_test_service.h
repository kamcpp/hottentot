/******************************************************************
 * Generated by Hottentot CC Generator
 * Date: 06-02-2016 03:32:35
 * Name: list_test_service.h
 * Description:
 *   This file contains definition of an abstract service class.
 ******************************************************************/

#ifndef _IR_NTNAEEM_HOTTENTOT_EXAMPLES_LISTTEST__SERVICE__ABSTRACT_LIST_TEST_SERVICE_H_
#define _IR_NTNAEEM_HOTTENTOT_EXAMPLES_LISTTEST__SERVICE__ABSTRACT_LIST_TEST_SERVICE_H_

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

#include <naeem/hottentot/runtime/service/service.h>

#include "../message.h"

#include "list_test_service.h"
#include "list_test_service_request_handler.h"


namespace ir {
namespace ntnaeem {
namespace hottentot {
namespace examples {
namespace listtest {
namespace service {
  class AbstractListTestService : public ListTestService, public ::naeem::hottentot::runtime::service::Service {
  public:
    AbstractListTestService() {}
    virtual ~AbstractListTestService() {}
  public:
    inline virtual uint32_t GetServiceId() const {
      return 304603072;
    }
  protected:
    inline virtual ::naeem::hottentot::runtime::service::RequestHandler* MakeRequestHandler() {
      return new ListTestServiceRequestHandler(this);
    }
  };
} // END OF NAMESPACE service
} // END OF NAMESPACE listtest
} // END OF NAMESPACE examples
} // END OF NAMESPACE hottentot
} // END OF NAMESPACE ntnaeem
} // END OF NAMESPACE ir

#endif