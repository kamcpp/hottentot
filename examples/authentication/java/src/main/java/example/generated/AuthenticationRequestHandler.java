/******************************************************************
 * Generated by Hottentot JAVA Generator
 * Date: 
 * Name: 
 * Description:
 *   
 ******************************************************************/
package example.generated;

import ir.ntnaeem.hottentot.runtime.Argument;
import ir.ntnaeem.hottentot.runtime.Request;
import ir.ntnaeem.hottentot.runtime.RequestHandler;
import ir.ntnaeem.hottentot.runtime.Response;
import ir.ntnaeem.hottentot.runtime.Service;
import ir.ntnaeem.hottentot.runtime.exception.MethodNotSupportException;
import ir.ntnaeem.hottentot.runtime.exception.TcpClientConnectException;
import ir.ntnaeem.hottentot.runtime.exception.TcpClientReadException;
import ir.ntnaeem.hottentot.runtime.exception.TcpClientWriteException;
import ir.ntnaeem.hottentot.serializerHelper.PDTDeserializer;
import ir.ntnaeem.hottentot.serializerHelper.PDTSerializer;
import java.util.List;

public class AuthenticationRequestHandler extends RequestHandler {
  public AuthenticationRequestHandler(Service service) {
    super(service);
  }
  @Override
  public Response handleRequest(Request request) throws TcpClientWriteException, TcpClientReadException, TcpClientConnectException, MethodNotSupportException {
    long methodId = request.getMethodId();
    AuthenticationService authenticationImpl = (AbstractAuthenticationService) service;

    if(methodId == 2550194791L){
      List <Argument> args = request.getArgs();
      Argument arg0 = args.get(0);
      byte[] serializedCredential = arg0.getData();
      Credential credential = new Credential();
      credential.deserialize(serializedCredential);
      SerializableTokenList serializableTokenList = new SerializableTokenList();
      Response response = new Response();
      List<Token> tokenList = authenticationImpl.auth(credential);
      byte[] serializedTokenList;
      if(tokenList == null){
        serializedTokenList  = new byte[0];
      }else{
        serializableTokenList.setTokenList(tokenList);
        serializedTokenList = serializableTokenList.serialize();
      }
      response.setStatusCode((byte) 0);
      response.setData(serializedTokenList);
      response.setLength(serializedTokenList.length + 1);
      return response;
    }
    if(methodId == 3646353831L){
      List <Argument> args = request.getArgs();
      SerializableDataWrapperList serializableDataWrapperList = new SerializableDataWrapperList();
      Response response = new Response();
      List<DataWrapper> datawrapperList = authenticationImpl.test();
      byte[] serializedDataWrapperList;
      if(datawrapperList == null){
        serializedDataWrapperList  = new byte[0];
      }else{
        serializableDataWrapperList.setDataWrapperList(datawrapperList);
        serializedDataWrapperList = serializableDataWrapperList.serialize();
      }
      response.setStatusCode((byte) 0);
      response.setData(serializedDataWrapperList);
      response.setLength(serializedDataWrapperList.length + 1);
      return response;
    }
    if(methodId == 17562162L){
      List <Argument> args = request.getArgs();
      SerializableStringWrapperList serializableStringWrapperList = new SerializableStringWrapperList();
      Response response = new Response();
      List<StringWrapper> stringwrapperList = authenticationImpl.test2();
      byte[] serializedStringWrapperList;
      if(stringwrapperList == null){
        serializedStringWrapperList  = new byte[0];
      }else{
        serializableStringWrapperList.setStringWrapperList(stringwrapperList);
        serializedStringWrapperList = serializableStringWrapperList.serialize();
      }
      response.setStatusCode((byte) 0);
      response.setData(serializedStringWrapperList);
      response.setLength(serializedStringWrapperList.length + 1);
      return response;
    }
    if(methodId == 1467434780L){
      List <Argument> args = request.getArgs();
      StringWrapper stringWrapper = null;
      Response response = new Response();
      stringWrapper = authenticationImpl.test3();
      byte[] serializedStringWrapper;
      if(stringWrapper == null){
        serializedStringWrapper  = new byte[0];
      }else{
      serializedStringWrapper = stringWrapper.serialize();
      }
      response.setStatusCode((byte) 0);
      response.setData(serializedStringWrapper);
      response.setLength(serializedStringWrapper.length + 1);
      return response;
    }
    if(methodId == 269734079L){
      List <Argument> args = request.getArgs();
      DataWrapper dataWrapper = null;
      Response response = new Response();
      dataWrapper = authenticationImpl.test4();
      byte[] serializedDataWrapper;
      if(dataWrapper == null){
        serializedDataWrapper  = new byte[0];
      }else{
      serializedDataWrapper = dataWrapper.serialize();
      }
      response.setStatusCode((byte) 0);
      response.setData(serializedDataWrapper);
      response.setLength(serializedDataWrapper.length + 1);
      return response;
    }
    if(methodId == 3266268561L){
      List <Argument> args = request.getArgs();
      Argument arg0 = args.get(0);
      byte[] serializedInputList = arg0.getData();
      SerializableStringWrapperList serializableStringWrapperList = new SerializableStringWrapperList();
      serializableStringWrapperList.deserialize( serializedInputList);
      List<StringWrapper> inputList = serializableStringWrapperList.getStringWrapperList();
      DataWrapper dataWrapper = null;
      Response response = new Response();
      dataWrapper = authenticationImpl.test5(inputList);
      byte[] serializedDataWrapper;
      if(dataWrapper == null){
        serializedDataWrapper  = new byte[0];
      }else{
      serializedDataWrapper = dataWrapper.serialize();
      }
      response.setStatusCode((byte) 0);
      response.setData(serializedDataWrapper);
      response.setLength(serializedDataWrapper.length + 1);
      return response;
    }
    if(methodId == 989571763L){
      List <Argument> args = request.getArgs();
      Argument arg0 = args.get(0);
      byte[] serializedInputs = arg0.getData();
      SerializableDataWrapperList serializableDataWrapperList = new SerializableDataWrapperList();
      serializableDataWrapperList.deserialize( serializedInputs);
      List<DataWrapper> inputs = serializableDataWrapperList.getDataWrapperList();
      DataWrapper dataWrapper = null;
      Response response = new Response();
      dataWrapper = authenticationImpl.test6(inputs);
      byte[] serializedDataWrapper;
      if(dataWrapper == null){
        serializedDataWrapper  = new byte[0];
      }else{
      serializedDataWrapper = dataWrapper.serialize();
      }
      response.setStatusCode((byte) 0);
      response.setData(serializedDataWrapper);
      response.setLength(serializedDataWrapper.length + 1);
      return response;
    }
    if(methodId == 1740079794L){
      List <Argument> args = request.getArgs();
      Result result = null;
      Response response = new Response();
      result = authenticationImpl.test7();
      byte[] serializedResult;
      if(result == null){
        serializedResult  = new byte[0];
      }else{
      serializedResult = result.serialize();
      }
      response.setStatusCode((byte) 0);
      response.setData(serializedResult);
      response.setLength(serializedResult.length + 1);
      return response;
    }
    if(methodId == 1095152123L){
      List <Argument> args = request.getArgs();
      Argument arg0 = args.get(0);
      byte[] serializedStr = arg0.getData();
      StringWrapper str = new StringWrapper();
      str.deserialize(serializedStr);
      StringWrapper stringWrapper = null;
      Response response = new Response();
      stringWrapper = authenticationImpl.test8(str);
      byte[] serializedStringWrapper;
      if(stringWrapper == null){
        serializedStringWrapper  = new byte[0];
      }else{
      serializedStringWrapper = stringWrapper.serialize();
      }
      response.setStatusCode((byte) 0);
      response.setData(serializedStringWrapper);
      response.setLength(serializedStringWrapper.length + 1);
      return response;
    }
    if(methodId == 1152274733L){
      List <Argument> args = request.getArgs();
      Argument arg0 = args.get(0);
      byte[] serializedStr = arg0.getData();
      String str = PDTDeserializer.getFullString(serializedStr);
      Argument arg1 = args.get(1);
      byte[] serializedFlag = arg1.getData();
      boolean flag = PDTDeserializer.getBool(serializedFlag);
      Argument arg2 = args.get(2);
      byte[] serializedNum = arg2.getData();
      short num = PDTDeserializer.getUint16(serializedNum);
      Argument arg3 = args.get(3);
      byte[] serializedD = arg3.getData();
      byte[] d = PDTDeserializer.getFullData(serializedD);
      Response response = new Response();
      byte result = authenticationImpl.test9(str,flag,num,d);
      byte[] serializedResult = PDTSerializer.getUint8( result );
      response.setStatusCode((byte) 0);
      response.setData(serializedResult);
      response.setLength(serializedResult.length + 1);
      return response;
    }

    throw new MethodNotSupportException("method id is incorrect");
  }
}
