/******************************************************************
 * Generated by Hottentot JAVA Generator
 * Date: 
 * Name: 
 * Description:
 *   
 ******************************************************************/
package example.generated;

import ir.ntnaeem.hottentot.runtime.RequestHandler;

public abstract class AbstractAuthService implements AuthService {	
  public RequestHandler makeRequestHandler() {
    return new AuthRequestHandler(this);
  }
  public long getServiceId() {
    return 96582825L;
  }
}
