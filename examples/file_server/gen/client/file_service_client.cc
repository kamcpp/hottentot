/******************************************************************
 * Generated by Hottentot CC Generator
 * Date: 11-01-2016 11:34:13
 * Name: file_service_client.h
 * Description:
 *   This file contains a sample client.
 ******************************************************************/

#include <iostream>

#include <naeem/hottentot/runtime/logger.h>
#include <naeem/hottentot/runtime/proxy/proxy_runtime.h>


#include "../file_service.h"
#include "../proxy/file_service_proxy_builder.h"


int 
main(int argc, char **argv) {
  try {
    ::naeem::hottentot::runtime::Logger::Init();
    std::cout << "Logger is initialized." << std::endl;
    ::naeem::hottentot::runtime::proxy::ProxyRuntime::Init(argc, argv);
    std::cout << "Proxy runtime is initialized." << std::endl;
    ::ir::ntnaeem::hottentot::examples::file::server::FileService *proxy = 
        ::ir::ntnaeem::hottentot::examples::file::server::proxy::FileServiceProxyBuilder::Create("127.0.0.1", 2000);
    std::cout << "Proxy object is created." << std::endl;
    // TODO Do whatever you want with proxy objects.
    ::ir::ntnaeem::hottentot::examples::file::server::proxy::FileServiceProxyBuilder::Destroy(proxy);
    std::cout << "Proxy object is destroyed." << std::endl;
    // Delete allocated objects
  } catch (...) {
    std::cout << "Error." << std::endl;
    return 1;
  }
  return 0;
}
