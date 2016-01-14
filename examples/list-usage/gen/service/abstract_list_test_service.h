/******************************************************************
 * Generated by Hottentot CC Generator
 * Date: 14-01-2016 11:14:25
 * Name: list_test_service.h
 * Description:
 *   This file contains definition of an abstract service class.
 ******************************************************************/

#ifndef _IR_NTNAEEM_HOTTENTOT_EXAMPLES_LISTTEST__SERVICE__ABSTRACT_LIST_TEST_SERVICE_H_
#define _IR_NTNAEEM_HOTTENTOT_EXAMPLES_LISTTEST__SERVICE__ABSTRACT_LIST_TEST_SERVICE_H_

#include <stdint.h>
#include <string>

#include <naeem/hottentot/runtime/service/service.h>

#include "../message.h"
#include "../list_test_service.h"
#include "list_test_service_request_handler.h"


namespace ir {
namespace ntnaeem {
namespace hottentot {
namespace examples {
namespace listtest {
namespace service {
  class AbstractListTestService : public ListTestService, public ::naeem::hottentot::runtime::service::Service {
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