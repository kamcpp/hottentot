/******************************************************************
 * Generated by Hottentot JAVA Generator
 * Date: 
 * Name: 
 * Description:
 *   
 ******************************************************************/
package server;



import ir.ntnaeem.hottentot.runtime.Service;
import ir.ntnaeem.hottentot.runtime.ServiceRuntime;

import java.io.IOException;

public class Main {
  public static void main(String[] args) throws IOException {
    ir.ntnaeem.hottentot.runtime.config.Config.setMainArgs(args);
    ir.ntnaeem.hottentot.runtime.config.Config.setConfigPropertiesFromConfigFile();
    ServiceRuntime serviceRuntime = new ServiceRuntime();
    Service authenticationService = new AuthenticationImpl();
    serviceRuntime.register("127.0.0.1",2000, authenticationService);
    serviceRuntime.start();
  }
}



