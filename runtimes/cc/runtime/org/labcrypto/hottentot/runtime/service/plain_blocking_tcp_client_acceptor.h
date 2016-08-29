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
 
#ifndef _ORG_LABCRYPTO_HOTTENTOT_RUNTIME_SERVICE__TCP_CLIENT_ACCEPTOR_H_
#define _ORG_LABCRYPTO_HOTTENTOT_RUNTIME_SERVICE__TCP_CLIENT_ACCEPTOR_H_

#include "client_acceptor.h"


namespace org {
namespace labcrypto {
namespace hottentot {
namespace runtime {
namespace service {
  class Service;
  class RequestHandler;
  class PlainBlockingTcpClientAcceptor : public ClientAcceptor {
  public:
    PlainBlockingTcpClientAcceptor (
      std::string host,
      uint16_t port,
      std::map<uint8_t, RequestHandler*> *requestHandlers
    ) : ClientAcceptor(requestHandlers),
        host_(host),
        port_(port),
        serverSocketFD_(0) {
    }
    virtual ~PlainBlockingTcpClientAcceptor() {}
  public:
    virtual bool Start();
    private:
#ifdef _MSC_VER
    static DWORD WINAPI AcceptClients(LPVOID);
    static DWORD WINAPI HandleClientConnection(LPVOID);
#else
    static void* AcceptClients(void *);
    static void* HandleClientConnection(void *);
#endif
  protected:
    std::string host_;
    uint16_t port_;
#ifdef _MSC_VER
    SOCKET serverSocketFD_;
#else
    int serverSocketFD_;
#endif
  };
  class _HandleClientConnectionParams {
  public:
    PlainBlockingTcpClientAcceptor *clientAcceptor_;
    int clientSocketFD_;
  };
}
}
}
}
}

#endif