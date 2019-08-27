#include "echo_handler.h"
using namespace std;
using namespace Pistache;

namespace Aliyun {
namespace FC {
namespace Handlers {
std::string EchoHandler::mInitHandler;
void EchoHandler::OnInvoke(const string& payload, const FcContext& context, string& response)
{
    response = EchoHandler::mInitHandler + payload;
}

void EchoHandler::OnInitialize(const FcContext& context)
{
    EchoHandler::mInitHandler = context.initializer;
}

std::string EchoHttpHandler::mInitHandler;
CUSTOM_HEADER2(X_Header1, "header1") // test only
void EchoHttpHandler::OnInvoke(const FcContext& context, const Pistache::Http::Request& req,
            Pistache::Http::ResponseWriter& response)
{
    response.headers().add<X_Header1>(req.headers().getRaw("header1").value());
    response.send(Http::Code::Ok, EchoHttpHandler::mInitHandler + req.body());
} 

void EchoHttpHandler::OnInitialize(const FcContext& context)
{
    EchoHttpHandler::mInitHandler = context.initializer;
}
}}}