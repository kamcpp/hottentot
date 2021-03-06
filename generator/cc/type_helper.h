/*  The MIT License (MIT)
 *
 *  Copyright (c) 2015 LabCrypto Org.
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

#ifndef _ORG_LABCRYPTO_HOTTENTOT_GENERATOR__CC__TYPE_HELPER_H_
#define _ORG_LABCRYPTO_HOTTENTOT_GENERATOR__CC__TYPE_HELPER_H_

#include "runtime.h"

#include "../string_helper.h"
#include "../enum.h"


namespace org {
namespace labcrypto {
namespace hottentot {
namespace generator {
namespace cc {
  class TypeHelper {
  public:
    static inline bool IsVoid(std::string type) {
      return ::org::labcrypto::hottentot::generator::StringHelper::MakeLowerCase(type) == "void";
    }
    static inline bool IsList(std::string type) {
      std::string listStr = "list";
      return ::org::labcrypto::hottentot::generator::StringHelper::StartsWith(type, listStr);
    }
    static inline bool IsUDT(std::string type) {
      if (type == "int8") {
        return false;
      } else if (type == "int16") {
        return false;
      } else if (type == "int32") {
        return false;
      } else if (type == "int64") {
        return false;
      } else if (type == "uint8") {
        return false;
      } else if (type == "uint16") {
        return false;
      } else if (type == "uint32") {
        return false;
      } else if (type == "uint64") {
        return false;
      } else if (type == "bool") {
        return false;
      } else if (type == "string") {
        return false;
      } else if (type == "char") {
        return false;
      } else if (type == "data") {
        return false;
      } else if (type == "utc_timestamp") {
        return false;
      } else if (type == "double") {
        return false;
      } else if (type == "void") {
        return false;
      } else if (IsEnum(type)) {
        return false;
      }
      return true;
    }
    static inline bool IsFixedLength(std::string type) {
      if (type == "int8") {
        return true;
      } else if (type == "int16") {
        return true;
      } else if (type == "int32") {
        return true;
      } else if (type == "int64") {
        return true;
      } else if (type == "uint8") {
        return true;
      } else if (type == "uint16") {
        return true;
      } else if (type == "uint32") {
        return true;
      } else if (type == "uint64") {
        return true;
      } else if (type == "bool") {
        return true;
      } else if (type == "char") {
        return true;
      } else if (type == "utc_timestamp") {
        return true;
      } else if (type == "double") {
        return true;
      } else if (IsEnum(type)) {
        return true;
      }
      return false;
    }
    static inline bool IsEnum(std::string type) {
      for (uint32_t i = 0; i < Runtime::enums_.size(); i++) {
        if (Runtime::enums_[i]->GetName() == type) {
          return true;
        }
      }
      return false;
    }
    static inline uint16_t GetFixedLength(std::string type) {
      if (type == "int8") {
        return 1;
      } else if (type == "int16") {
        return 2;
      } else if (type == "int32") {
        return 4;
      } else if (type == "int64") {
        return 8;
      } else if (type == "uint8") {
        return 1;
      } else if (type == "uint16") {
        return 2;
      } else if (type == "uint32") {
        return 4;
      } else if (type == "uint64") {
        return 8;
      } else if (type == "bool") {
        return 1;
      } else if (type == "char") {
        return 1;
      } else if (type == "utc_timestamp") {
        return 8;
      } else if (type == "double") {
        return 8;
      } else if (IsEnum(type)) {
        return 2;
      }
      throw std::runtime_error("Type is not length fixed.");
    }
    static inline std::string GetCCType(std::string type, std::string ns) {
      std::string listStr = "list";
      if (type == "int8") {
        return "::org::labcrypto::hottentot::Int8";
      } else if (type == "int16") {
        return "::org::labcrypto::hottentot::Int16";
      } else if (type == "int32") {
        return "::org::labcrypto::hottentot::Int32";
      } else if (type == "int64") {
        return "::org::labcrypto::hottentot::Int64";
      } else if (type == "uint8") {
        return "::org::labcrypto::hottentot::UInt8";
      } else if (type == "uint16") {
        return "::org::labcrypto::hottentot::UInt16";
      } else if (type == "uint32") {
        return "::org::labcrypto::hottentot::UInt32";
      } else if (type == "uint64") {
        return "::org::labcrypto::hottentot::UInt64";
      } else if (type == "bool") {
        return "::org::labcrypto::hottentot::Boolean";
      } else if (type == "string") {
        return "::org::labcrypto::hottentot::Utf8String";
      } else if (type == "char") {
        return "::org::labcrypto::hottentot::Char";
      } else if (type == "data") {
        return "::org::labcrypto::hottentot::ByteArray";
      } else if (type == "utc_timestamp") {
        return "::org::labcrypto::hottentot::UtcTimestamp";
      } else if (type == "double") {
        return "::org::labcrypto::hottentot::Double";
      } else if (type == "void") {
        return "void";
      } else if(::org::labcrypto::hottentot::generator::StringHelper::StartsWith(type, listStr)) {
        return "::org::labcrypto::hottentot::List< " + 
          GetCCType(type.substr(5, type.length() - 6), ns) + ">";
      } else if(IsEnum(type)) {
        return "::org::labcrypto::hottentot::Enum< " + ns + "::" + type + ">";
      }
      if (ns.length() == 0) {
        return type;
      } else {
        return ns + "::" + type;
      }
    }
    static inline std::string GetTypeOfList(std::string type) {
      return type.substr(5, type.size() - 6);
    }
  };
}
}
}
}
}

#endif