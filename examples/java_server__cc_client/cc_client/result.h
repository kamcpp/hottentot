/***************************************************************
 * Generated by Hottentot CC Generator
 * Date: 30-01-2016 08:21:47
 * Name: result.h
 * Description:
 *   This file contains definition of Result class.
 ***************************************************************/

#ifndef _HOTGEN__RESULT_H_
#define _HOTGEN__RESULT_H_

#include <string>

#include <naeem/hottentot/runtime/types/primitives.h>
#include <naeem/hottentot/runtime/serializable.h>


namespace hotgen {
  class Result : public ::naeem::hottentot::runtime::Serializable {
  public:
    Result() {}
    ~Result() {}
  public:
    inline ::naeem::hottentot::runtime::types::UInt8 GetStatusCode() const {
      return statusCode_;
    }
    inline void SetStatusCode(::naeem::hottentot::runtime::types::UInt8 statusCode) {
      statusCode_ = statusCode;
    }
  public:
    virtual unsigned char * Serialize(uint32_t * /* Pointer to length */);
    virtual void Deserialize(unsigned char * /* Data */, uint32_t /* Data length */);
  private:
    ::naeem::hottentot::runtime::types::UInt8 statusCode_;
  };
} // END OF NAMESPACE hotgen

#endif