/*  The MIT License (MIT)
 *
 *  Copyright (c) 2015 Noavaran Tejarat Gostar NAEEM Co.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 */
 
#ifndef _NAEEM_HOTTENTOT_RUNTIME__REQUEST_H_
#define _NAEEM_HOTTENTOT_RUNTIME__REQUEST_H_

#include <stdint.h>
#include <vector>


namespace naeem {
  namespace hottentot {
    namespace runtime {
      class _Argument {
      public:
        unsigned char *data_;
        uint32_t dataLength_;
      };
      class Request {
      public:
        enum RequestType {
          Unknown,
          ServiceListQuery,
          InvokeStateless,
          InvokeStateful
        };
      public:
        Request()
          : argumentCount_(0) {
        }
        ~Request() {
          for (uint32_t i = 0; i < args_.size(); i++) {
            delete [] args_[i].data_;
          }
        }
        inline RequestType GetType() const {
          return type_;
        }
        inline void SetType(RequestType type) {
          type_ = type;
        }
        inline uint32_t GetServiceId() const {
          return serviceId_;
        }
        inline void SetServiceId(uint32_t serviceId) {
          serviceId_ = serviceId;
        }
        inline uint32_t GetMethodId() const {
          return methodId_;
        }
        inline void SetMethodId(uint32_t methodId) {
          methodId_ = methodId;
        }
        inline uint32_t GetArgumentCount() const {
          return argumentCount_;
        }
        inline void SetArgumentCount(uint32_t argumentCount) {
          argumentCount_ = argumentCount;
        }
        inline void AddArgument(unsigned char *data, uint32_t dataLength) {
          _Argument argument;
          argument.data_ = data;
          argument.dataLength_ = dataLength;
          args_.push_back(argument);
          argumentCount_++;
        }
        inline unsigned char* GetArgumentData(uint8_t index) {
          return args_[index].data_;
        }
        inline uint32_t GetArgumentLength(uint8_t index) {
          return args_[index].dataLength_;
        }
      private:
        RequestType type_;
        uint32_t serviceId_;
        uint32_t methodId_;
        uint32_t argumentCount_;
        std::vector<_Argument> args_;
      };
    }
  }
}

#endif