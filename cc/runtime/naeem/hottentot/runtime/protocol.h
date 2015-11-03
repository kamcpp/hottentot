#ifndef _NAEEM_HOTTENTOT_RUNTIME__PROTOCOL_H_
#define _NAEEM_HOTTENTOT_RUNTIME__PROTOCOL_H_

#include <stdint.h>


namespace naeem {
  namespace hottentot {
    namespace runtime {
      namespace service {
        class RequestCallback;
      }
      class Request;
      class Response;
      class Protocol {
      public:
        Protocol(int remoteSocketFD) 
          : remoteSocketFD_(remoteSocketFD) {
        }
        virtual ~Protocol() {}
      public:
        virtual unsigned char* SerializeRequest(Request &      /* Request object*/, 
                                                uint32_t *     /* Length */) = 0;
        virtual unsigned char* SerializeResponse(Response &    /* Response object*/, 
                                                 uint32_t *    /* Length */) = 0;
        virtual Request* DeserializeRequest(unsigned char *   /* Request data */, 
                                             uint32_t          /* Request data length */) = 0;
        virtual Response* DeserializeResponse(unsigned char *  /* Response data */, 
                                              uint32_t         /* Response data length */) = 0;
      public:
        virtual void SetRequestCallback(::naeem::hottentot::runtime::service::RequestCallback *requestCallback) {
          requestCallback_ = requestCallback;
        }
      public:
        virtual void ProcessDataForRequest(unsigned char *     /* Data chuck */,
                                           uint32_t            /* Data chunk length */) = 0;
        virtual void ProcessDataForResponse(unsigned char *    /* Data chuck */,
                                            uint32_t           /* Data chunk length */) = 0;
      public:
        virtual bool IsResponseComplete() = 0;
        virtual Response* GetResponse() = 0;
      protected:
        int remoteSocketFD_;
        ::naeem::hottentot::runtime::service::RequestCallback *requestCallback_;
      };
    }
  }
}

#endif