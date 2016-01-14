/***************************************************************
 * Generated by Hottentot CC Generator
 * Date: 14-01-2016 11:14:25
 * Name: list_test_service_proxy.cc
 * Description:
 *   This file contains implementation of the proxy class.
 ***************************************************************/

#include <naeem/hottentot/runtime/logger.h>
#include <naeem/hottentot/runtime/utils.h>
#include <naeem/hottentot/runtime/request.h>
#include <naeem/hottentot/runtime/response.h>
#include <naeem/hottentot/runtime/protocol_v1.h>
#include <naeem/hottentot/runtime/proxy/tcp_client.h>
#include <naeem/hottentot/runtime/proxy/proxy_runtime.h>
#include <naeem/hottentot/runtime/proxy/tcp_client_factory.h>

#include "list_test_service_proxy.h"

#include "../message.h"


namespace ir {
namespace ntnaeem {
namespace hottentot {
namespace examples {
namespace listtest {
namespace proxy {
  void
  ListTestServiceProxy::AddNames(::naeem::hottentot::runtime::types::List< ::naeem::hottentot::runtime::types::Utf8String> &names) {
    /*
     * Make request object
     */
    ::naeem::hottentot::runtime::Logger::GetOut() << "Making request object ..." << std::endl;
    ::naeem::hottentot::runtime::Request request;
    request.SetServiceId(304603072);
    request.SetMethodId(4202985802);
    request.SetType(::naeem::hottentot::runtime::Request::InvokeStateless);
    /*
     * Serialize arguments
     */
    uint32_t serializedDataLength = 0;
    unsigned char *serializedData = 0;
    /*
     * Serialization of argument 'names'
     */
    serializedDataLength = 0;
    ::naeem::hottentot::runtime::Logger::GetOut() << "Serializing argument names ..." << std::endl;
    serializedData = names.Serialize(&serializedDataLength);
    ::naeem::hottentot::runtime::Logger::GetOut() << "names is serialized." << std::endl;
    request.AddArgument(serializedData, serializedDataLength);

    ::naeem::hottentot::runtime::Logger::GetOut() << "Request object is fill with serialized arguments." << std::endl;
    /*
     * Connect to server
     */
    ::naeem::hottentot::runtime::Logger::GetOut() << "Connecting to server " << host_ << ":" << port_ << " ..." << std::endl;
    ::naeem::hottentot::runtime::proxy::TcpClient *tcpClient = 
        ::naeem::hottentot::runtime::proxy::ProxyRuntime::GetTcpClientFactory()->CreateTcpClient(host_, port_);
    tcpClient->Connect();
    ::naeem::hottentot::runtime::Logger::GetOut() << "Connected." << std::endl;
    /*
     * Serialize request according to HOTP
     */
    ::naeem::hottentot::runtime::Protocol *protocol = new ::naeem::hottentot::runtime::ProtocolV1(tcpClient->GetRemoteSocketFD()); // TODO(kamran): Use factory.
    uint32_t requestSerializedDataLength = 0;
    ::naeem::hottentot::runtime::Logger::GetOut() << "Serializing request object ..." << std::endl;
    unsigned char *requestSerializedData = protocol->SerializeRequest(request, &requestSerializedDataLength);
    ::naeem::hottentot::runtime::Logger::GetOut() << "Request object is serialized." << std::endl;
    /*
     * Send request byte array
     */
    uint32_t sendLength = (requestSerializedDataLength > 127 ? 3 : 1) + requestSerializedDataLength;
    unsigned char *sendData = new unsigned char[sendLength];
    uint32_t c = 0;
    if (requestSerializedDataLength > 127) {
      sendData[c++] = 0x82;
      sendData[c++] = requestSerializedDataLength / 256;
      sendData[c++] = requestSerializedDataLength % 256;
    } else {
      sendData[c++] = requestSerializedDataLength;
    }
    for (uint32_t i = 0; i < requestSerializedDataLength; i++) {
      sendData[c++] = requestSerializedData[i];
    }
    ::naeem::hottentot::runtime::Logger::GetOut() << "Writing " << sendLength << "    Bytes to socket ..." << std::endl;
    ::naeem::hottentot::runtime::Utils::PrintArray("To Write", sendData, sendLength);
    tcpClient->Write(sendData, sendLength);
    ::naeem::hottentot::runtime::Logger::GetOut() << "Written." << std::endl;
    delete sendData;
    delete requestSerializedData;
    /*
     * Read response from server
     */
    ::naeem::hottentot::runtime::Logger::GetOut() << "Waiting for response ..." << std::endl;
    unsigned char buffer[256];
    while (!protocol->IsResponseComplete()) {
      int numOfReadBytes = tcpClient->Read(buffer, 256);
      protocol->ProcessDataForResponse(buffer, numOfReadBytes);
    }
    /*
     * Finalization
     */
    tcpClient->Close();
    delete serializedData;
    delete protocol;
    delete tcpClient;
  }
  void
  ListTestServiceProxy::GetNames(::naeem::hottentot::runtime::types::List< ::naeem::hottentot::runtime::types::Utf8String> &out) {
    /*
     * Make request object
     */
    ::naeem::hottentot::runtime::Logger::GetOut() << "Making request object ..." << std::endl;
    ::naeem::hottentot::runtime::Request request;
    request.SetServiceId(304603072);
    request.SetMethodId(2800820226);
    request.SetType(::naeem::hottentot::runtime::Request::InvokeStateless);
    /*
     * Serialize arguments
     */
    uint32_t serializedDataLength = 0;
    unsigned char *serializedData = 0;
    ::naeem::hottentot::runtime::Logger::GetOut() << "Request object is fill with serialized arguments." << std::endl;
    /*
     * Connect to server
     */
    ::naeem::hottentot::runtime::Logger::GetOut() << "Connecting to server " << host_ << ":" << port_ << " ..." << std::endl;
    ::naeem::hottentot::runtime::proxy::TcpClient *tcpClient = 
        ::naeem::hottentot::runtime::proxy::ProxyRuntime::GetTcpClientFactory()->CreateTcpClient(host_, port_);
    tcpClient->Connect();
    ::naeem::hottentot::runtime::Logger::GetOut() << "Connected." << std::endl;
    /*
     * Serialize request according to HOTP
     */
    ::naeem::hottentot::runtime::Protocol *protocol = new ::naeem::hottentot::runtime::ProtocolV1(tcpClient->GetRemoteSocketFD()); // TODO(kamran): Use factory.
    uint32_t requestSerializedDataLength = 0;
    ::naeem::hottentot::runtime::Logger::GetOut() << "Serializing request object ..." << std::endl;
    unsigned char *requestSerializedData = protocol->SerializeRequest(request, &requestSerializedDataLength);
    ::naeem::hottentot::runtime::Logger::GetOut() << "Request object is serialized." << std::endl;
    /*
     * Send request byte array
     */
    uint32_t sendLength = (requestSerializedDataLength > 127 ? 3 : 1) + requestSerializedDataLength;
    unsigned char *sendData = new unsigned char[sendLength];
    uint32_t c = 0;
    if (requestSerializedDataLength > 127) {
      sendData[c++] = 0x82;
      sendData[c++] = requestSerializedDataLength / 256;
      sendData[c++] = requestSerializedDataLength % 256;
    } else {
      sendData[c++] = requestSerializedDataLength;
    }
    for (uint32_t i = 0; i < requestSerializedDataLength; i++) {
      sendData[c++] = requestSerializedData[i];
    }
    ::naeem::hottentot::runtime::Logger::GetOut() << "Writing " << sendLength << "    Bytes to socket ..." << std::endl;
    ::naeem::hottentot::runtime::Utils::PrintArray("To Write", sendData, sendLength);
    tcpClient->Write(sendData, sendLength);
    ::naeem::hottentot::runtime::Logger::GetOut() << "Written." << std::endl;
    delete sendData;
    delete requestSerializedData;
    /*
     * Read response from server
     */
    ::naeem::hottentot::runtime::Logger::GetOut() << "Waiting for response ..." << std::endl;
    unsigned char buffer[256];
    while (!protocol->IsResponseComplete()) {
      int numOfReadBytes = tcpClient->Read(buffer, 256);
      protocol->ProcessDataForResponse(buffer, numOfReadBytes);
    }
    /*
     * Response deserialization
     */
    ::naeem::hottentot::runtime::Utils::PrintArray("Response", protocol->GetResponse()->GetData(), protocol->GetResponse()->GetDataLength());
    out.Deserialize(protocol->GetResponse()->GetData(), protocol->GetResponse()->GetDataLength());
    /*
     * Finalization
     */
    tcpClient->Close();
    delete serializedData;
    delete protocol;
    delete tcpClient;
  }
  void
  ListTestServiceProxy::GetMessages(::naeem::hottentot::runtime::types::List< ::ir::ntnaeem::hottentot::examples::listtest::Message> &out) {
    /*
     * Make request object
     */
    ::naeem::hottentot::runtime::Logger::GetOut() << "Making request object ..." << std::endl;
    ::naeem::hottentot::runtime::Request request;
    request.SetServiceId(304603072);
    request.SetMethodId(1872129924);
    request.SetType(::naeem::hottentot::runtime::Request::InvokeStateless);
    /*
     * Serialize arguments
     */
    uint32_t serializedDataLength = 0;
    unsigned char *serializedData = 0;
    ::naeem::hottentot::runtime::Logger::GetOut() << "Request object is fill with serialized arguments." << std::endl;
    /*
     * Connect to server
     */
    ::naeem::hottentot::runtime::Logger::GetOut() << "Connecting to server " << host_ << ":" << port_ << " ..." << std::endl;
    ::naeem::hottentot::runtime::proxy::TcpClient *tcpClient = 
        ::naeem::hottentot::runtime::proxy::ProxyRuntime::GetTcpClientFactory()->CreateTcpClient(host_, port_);
    tcpClient->Connect();
    ::naeem::hottentot::runtime::Logger::GetOut() << "Connected." << std::endl;
    /*
     * Serialize request according to HOTP
     */
    ::naeem::hottentot::runtime::Protocol *protocol = new ::naeem::hottentot::runtime::ProtocolV1(tcpClient->GetRemoteSocketFD()); // TODO(kamran): Use factory.
    uint32_t requestSerializedDataLength = 0;
    ::naeem::hottentot::runtime::Logger::GetOut() << "Serializing request object ..." << std::endl;
    unsigned char *requestSerializedData = protocol->SerializeRequest(request, &requestSerializedDataLength);
    ::naeem::hottentot::runtime::Logger::GetOut() << "Request object is serialized." << std::endl;
    /*
     * Send request byte array
     */
    uint32_t sendLength = (requestSerializedDataLength > 127 ? 3 : 1) + requestSerializedDataLength;
    unsigned char *sendData = new unsigned char[sendLength];
    uint32_t c = 0;
    if (requestSerializedDataLength > 127) {
      sendData[c++] = 0x82;
      sendData[c++] = requestSerializedDataLength / 256;
      sendData[c++] = requestSerializedDataLength % 256;
    } else {
      sendData[c++] = requestSerializedDataLength;
    }
    for (uint32_t i = 0; i < requestSerializedDataLength; i++) {
      sendData[c++] = requestSerializedData[i];
    }
    ::naeem::hottentot::runtime::Logger::GetOut() << "Writing " << sendLength << "    Bytes to socket ..." << std::endl;
    ::naeem::hottentot::runtime::Utils::PrintArray("To Write", sendData, sendLength);
    tcpClient->Write(sendData, sendLength);
    ::naeem::hottentot::runtime::Logger::GetOut() << "Written." << std::endl;
    delete sendData;
    delete requestSerializedData;
    /*
     * Read response from server
     */
    ::naeem::hottentot::runtime::Logger::GetOut() << "Waiting for response ..." << std::endl;
    unsigned char buffer[256];
    while (!protocol->IsResponseComplete()) {
      int numOfReadBytes = tcpClient->Read(buffer, 256);
      protocol->ProcessDataForResponse(buffer, numOfReadBytes);
    }
    /*
     * Response deserialization
     */
    ::naeem::hottentot::runtime::Utils::PrintArray("Response", protocol->GetResponse()->GetData(), protocol->GetResponse()->GetDataLength());
    out.Deserialize(protocol->GetResponse()->GetData(), protocol->GetResponse()->GetDataLength());
    /*
     * Finalization
     */
    tcpClient->Close();
    delete serializedData;
    delete protocol;
    delete tcpClient;
  }
  void
  ListTestServiceProxy::AddMessage(::ir::ntnaeem::hottentot::examples::listtest::Message &message) {
    /*
     * Make request object
     */
    ::naeem::hottentot::runtime::Logger::GetOut() << "Making request object ..." << std::endl;
    ::naeem::hottentot::runtime::Request request;
    request.SetServiceId(304603072);
    request.SetMethodId(3626181027);
    request.SetType(::naeem::hottentot::runtime::Request::InvokeStateless);
    /*
     * Serialize arguments
     */
    uint32_t serializedDataLength = 0;
    unsigned char *serializedData = 0;
    /*
     * Serialization of argument 'message'
     */
    serializedDataLength = 0;
    ::naeem::hottentot::runtime::Logger::GetOut() << "Serializing argument message ..." << std::endl;
    serializedData = message.Serialize(&serializedDataLength);
    ::naeem::hottentot::runtime::Logger::GetOut() << "message is serialized." << std::endl;
    request.AddArgument(serializedData, serializedDataLength);

    ::naeem::hottentot::runtime::Logger::GetOut() << "Request object is fill with serialized arguments." << std::endl;
    /*
     * Connect to server
     */
    ::naeem::hottentot::runtime::Logger::GetOut() << "Connecting to server " << host_ << ":" << port_ << " ..." << std::endl;
    ::naeem::hottentot::runtime::proxy::TcpClient *tcpClient = 
        ::naeem::hottentot::runtime::proxy::ProxyRuntime::GetTcpClientFactory()->CreateTcpClient(host_, port_);
    tcpClient->Connect();
    ::naeem::hottentot::runtime::Logger::GetOut() << "Connected." << std::endl;
    /*
     * Serialize request according to HOTP
     */
    ::naeem::hottentot::runtime::Protocol *protocol = new ::naeem::hottentot::runtime::ProtocolV1(tcpClient->GetRemoteSocketFD()); // TODO(kamran): Use factory.
    uint32_t requestSerializedDataLength = 0;
    ::naeem::hottentot::runtime::Logger::GetOut() << "Serializing request object ..." << std::endl;
    unsigned char *requestSerializedData = protocol->SerializeRequest(request, &requestSerializedDataLength);
    ::naeem::hottentot::runtime::Logger::GetOut() << "Request object is serialized." << std::endl;
    /*
     * Send request byte array
     */
    uint32_t sendLength = (requestSerializedDataLength > 127 ? 3 : 1) + requestSerializedDataLength;
    unsigned char *sendData = new unsigned char[sendLength];
    uint32_t c = 0;
    if (requestSerializedDataLength > 127) {
      sendData[c++] = 0x82;
      sendData[c++] = requestSerializedDataLength / 256;
      sendData[c++] = requestSerializedDataLength % 256;
    } else {
      sendData[c++] = requestSerializedDataLength;
    }
    for (uint32_t i = 0; i < requestSerializedDataLength; i++) {
      sendData[c++] = requestSerializedData[i];
    }
    ::naeem::hottentot::runtime::Logger::GetOut() << "Writing " << sendLength << "    Bytes to socket ..." << std::endl;
    ::naeem::hottentot::runtime::Utils::PrintArray("To Write", sendData, sendLength);
    tcpClient->Write(sendData, sendLength);
    ::naeem::hottentot::runtime::Logger::GetOut() << "Written." << std::endl;
    delete sendData;
    delete requestSerializedData;
    /*
     * Read response from server
     */
    ::naeem::hottentot::runtime::Logger::GetOut() << "Waiting for response ..." << std::endl;
    unsigned char buffer[256];
    while (!protocol->IsResponseComplete()) {
      int numOfReadBytes = tcpClient->Read(buffer, 256);
      protocol->ProcessDataForResponse(buffer, numOfReadBytes);
    }
    /*
     * Finalization
     */
    tcpClient->Close();
    delete serializedData;
    delete protocol;
    delete tcpClient;
  }
} // END OF NAMESPACE proxy
}  // END OF NAMESPACE listtest
}  // END OF NAMESPACE examples
}  // END OF NAMESPACE hottentot
}  // END OF NAMESPACE ntnaeem
}  // END OF NAMESPACE ir