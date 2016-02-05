/****************************************************************************
 * Generated by Hottentot CC Generator
 * Date: 05-02-2016 08:45:04
 * Name: authenticate_service_request_handler.cc
 * Description:
 *   This file contains implementation of service's request handler class.
 ****************************************************************************/
 
#include <string.h>

#include <naeem/hottentot/runtime/request.h>
#include <naeem/hottentot/runtime/response.h>

#include "authenticate_service_request_handler.h"
#include "abstract_authenticate_service.h"
#include "../authenticate_service.h"
#include "../credential.h"
#include "../user.h"
#include "../token.h"


namespace naeem {
namespace hottentot {
namespace examples {
namespace auth {
namespace service {
  void 
  AuthenticateServiceRequestHandler::HandleRequest(::naeem::hottentot::runtime::Request &request, ::naeem::hottentot::runtime::Response &response) {
    if (request.GetMethodId() == 3526193676) {
      ::naeem::hottentot::examples::auth::service::AbstractAuthenticateService *serviceObject = 
        dynamic_cast< ::naeem::hottentot::examples::auth::service::AbstractAuthenticateService*>(service_);
      /*
       * Deserialization and making input variables
       */
      ::naeem::hottentot::examples::auth::Credential credential;
      credential.Deserialize(request.GetArgumentData(0), request.GetArgumentLength(0));
      /*
       * Calling service method
       */
      ::naeem::hottentot::examples::auth::Token result;
      serviceObject->Authenticate(credential, result);
      /*
       * Serializiation of returned object
       */
      uint32_t serializedDataLength = 0;
      unsigned char *serializedData = result.Serialize(&serializedDataLength);

      response.SetStatusCode(0);
      response.SetData(serializedData);
      response.SetDataLength(serializedDataLength);
      return;
    }
    char errorMessage[] = "Method not found.";
    response.SetStatusCode(1);
    response.SetData((unsigned char*)errorMessage);
    response.SetDataLength(strlen(errorMessage));
  }
} // END OF NAMESPACE service
} // END OF NAMESPACE auth
} // END OF NAMESPACE examples
} // END OF NAMESPACE hottentot
} // END OF NAMESPACE naeem