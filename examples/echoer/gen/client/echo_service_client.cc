/******************************************************************
 * Generated by Hottentot CC Generator
 * Date: 01-12-2015 05:07:25
 * Name: echo_service_client.h
 * Description:
 *   This file contains a sample client.
 ******************************************************************/

#include <iostream>

#include <naeem/hottentot/runtime/logger.h>
#include <naeem/hottentot/runtime/proxy/proxy_runtime.h>

#include "../request_message.h"
#include "../response_message.h"
#include "../echo_service.h"
#include "../proxy/echo_service_proxy_builder.h"


int 
main(int argc, char **argv) {
  try {
    ::naeem::hottentot::runtime::Logger::Init();
    std::cout << "Logger is initialized." << std::endl;
    ::naeem::hottentot::runtime::proxy::ProxyRuntime::Init(argc, argv);
    std::cout << "Proxy runtime is initialized." << std::endl;
    ::ir::ntnaeem::hottentot::examples::echoer::EchoService *proxy = 
        ::ir::ntnaeem::hottentot::examples::echoer::proxy::EchoServiceProxyBuilder::Create("127.0.0.1", 2000);
    std::cout << "Proxy object is created." << std::endl;
    ::ir::ntnaeem::hottentot::examples::echoer::RequestMessage req;
    req.SetName("CK");
    ::ir::ntnaeem::hottentot::examples::echoer::ResponseMessage *res = proxy->EchoMessage(&req);
    std::cout << "Response: " << res->GetMessage() << std::endl;
    ::ir::ntnaeem::hottentot::examples::echoer::proxy::EchoServiceProxyBuilder::Destroy(proxy);
    std::cout << "Proxy object is destroyed." << std::endl;
    delete res;
  } catch (...) {
    std::cout << "Error." << std::endl;
    return 1;
  }
  return 0;
}