# Alibaba Cloud Function Compute Custom Runtime Cpp Reference Implementation

[![Software License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](LICENSE)

## Version
 - Current version: 1.0 

## Overview
This is a reference cpp implementation for Alibaba Cloud Function Compute Custom Runtime. It consists of two parts: runtime and sample function handlers. You may reuse the runtime part but write your own handlers to run the custom runtime.
Alibaba Cloud Function Compute runs in debian 8 and thus it's required for this project. 
## Environment dependency
### Supported OS
- Debian 8
### Compilation
- CMake 3.14 or above
### Dependent components (already included)
- pistache: https://github.com/oktal/pistache

## Build
./build.sh

## Try the sample handlers with Alibaba Cloud Function Compute Custom Runtime
- cd bin 
- zip code.zip *
- fcli function create --code-file code.zip -f $functionname -h "any" -t custom -s $servicename
  
The handler field in this case does not matter because the sample handler is hard coded in runtime
## "Hello world" example
### Define the handler (hello_handler.h)
```Cpp 
#pragma once
#include "handler.h"
namespace Aliyun {
namespace FC {
namespace Handlers {
class HelloHandler : public FcBaseHandler
{
public:
   void OnInvoke(const std::string& payload, const FcContext& context, std::string& response) override; 
};
}}}
```
### Implement the handler
```Cpp
#include "hello_handler.h"
using namespace std;

namespace Aliyun {
namespace FC {
namespace Handlers {
void HelloHandler::OnInvoke(const string& payload, const FcContext& context, string& response)
{
    response = "hello world!"
}
}}}
```
### Register the handler and main function
```Cpp
/* register invoke handler.
*/
#include "echo_handler.h"
#include "entrypoint.h" // main function
using namespace Aliyun::FC::Handlers;
void SetInvokeAndInitHander()  // must be exact signature
{
    CustomRuntimeHandler::normalHandler = new HelloHandler();
}
```
## License
- MIT
