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

#ifndef _NAEEM_HOTTENTOT_GENERATOR__DS__DECLARATION_H_
#define _NAEEM_HOTTENTOT_GENERATOR__DS__DECLARATION_H_

#include <vector>
#include <string>
#include <stdint.h>


namespace naeem {
  namespace hottentot {
    namespace generator {
      namespace ds {
        class Declaration {
        public:
          Declaration(std::string type = "", 
                      std::string variable = "",
                      uint32_t id = 0)
            : type_(type),
              variable_(variable),
              id_(id) {
          }
          virtual ~Declaration() {}
        public:
          inline virtual std::string GetType() const {
            return type_;
          }
          inline virtual void SetType(std::string type) {
            type_ = type;
          }
          inline virtual std::string GetVariable() const {
            return variable_;
          }
          inline virtual void SetVariable(std::string variable) {
            variable_ = variable;
          }
          inline virtual uint32_t GetId() const {
            return id_;
          }
          inline virtual void SetId(uint32_t id) {
            id_ = id;
          }
        protected:
          std::string type_;
          std::string variable_;
          uint32_t id_;
        };
      }
    }
  }
}

#endif