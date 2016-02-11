/******************************************************************
 * Generated by Hottentot CC Generator
 * Date: 11-02-2016 01:24:45
 * Name: phone_manager_service.h
 * Description:
 *   This file contains definition of an abstract service class.
 ******************************************************************/

#ifndef _IR_NTNAEEM_SERVICES__SERVICE__ABSTRACT_PHONE_MANAGER_SERVICE_H_
#define _IR_NTNAEEM_SERVICES__SERVICE__ABSTRACT_PHONE_MANAGER_SERVICE_H_

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

#include "../person.h"
#include "../phone.h"

#include "phone_manager_service.h"
#include "phone_manager_service_request_handler.h"


namespace ir {
namespace ntnaeem {
namespace services {
namespace service {
  class AbstractPhoneManagerService : public PhoneManagerService, public ::naeem::hottentot::runtime::service::Service {
  public:
    AbstractPhoneManagerService() {}
    virtual ~AbstractPhoneManagerService() {}
  public:
    inline virtual uint32_t GetServiceId() const {
      return 1831722476;
    }
  protected:
    inline virtual ::naeem::hottentot::runtime::service::RequestHandler* MakeRequestHandler() {
      return new PhoneManagerServiceRequestHandler(this);
    }
  };
} // END OF NAMESPACE service
} // END OF NAMESPACE services
} // END OF NAMESPACE ntnaeem
} // END OF NAMESPACE ir

#endif