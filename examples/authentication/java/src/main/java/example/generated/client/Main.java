/******************************************************************
 * Generated by Hottentot JAVA Generator
 * Date: 
 * Name: 
 * Description:
 *   
 ******************************************************************/
package example.generated.client;

import example.generated.AuthenticationService;
import example.generated.AuthenticationServiceProxyBuilder;
import example.generated.StringWrapper;

import java.io.IOException;
import java.util.List;

public class Main {
  public static void main(String[] args) throws IOException {
    ir.ntnaeem.hottentot.runtime.config.Config.setMainArgs(args);
    final AuthenticationService proxy = AuthenticationServiceProxyBuilder.create("127.0.0.1", 2000);
    //
    List<StringWrapper> stringWrapperList2 = proxy.test2();
    System.out.println("TEST2 stringWrapperList2 size : " + stringWrapperList2.size());
    System.out.println("TEST2 stringWrapperList2 : " + stringWrapperList2);

  }
}