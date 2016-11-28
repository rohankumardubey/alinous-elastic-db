#ifndef ALINOUS_RUNTIME_ENGINE_DEBUGGER_CLIENT_STEPINREQUEST_H_
#define ALINOUS_RUNTIME_ENGINE_DEBUGGER_CLIENT_STEPINREQUEST_H_
namespace alinous {namespace runtime {namespace engine {namespace debugger {
class AlinousServerDebugHttpResponse;}}}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {
class AlinousScriptDebugger;}}}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {
class DebugThread;}}}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {
class StepInOperation;}}}}}

namespace java {namespace util {
template <typename  T, typename V> class Map;}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace client {
class IClientRequest;}}}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace client {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::HashMap;
using ::java::util::Map;
using ::alinous::runtime::engine::debugger::AlinousScriptDebugger;
using ::alinous::runtime::engine::debugger::AlinousServerDebugHttpResponse;
using ::alinous::runtime::engine::debugger::DebugThread;
using ::alinous::runtime::engine::debugger::server::StepInOperation;



class StepInRequest final : public IClientRequest, public virtual IObject {
public:
	StepInRequest(const StepInRequest& base) = default;
public:
	StepInRequest(ThreadContext* ctx) throw()  : IObject(ctx), IClientRequest(ctx), threadId(0), stackId(0)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~StepInRequest() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	long long threadId;
	long long stackId;
public:
	static String* THREAD_ID;
	static String* STACK_ID;
public:
	AlinousServerDebugHttpResponse* executeRequest(AlinousScriptDebugger* debugManager, ThreadContext* ctx) throw()  final;
	String* getCommand(ThreadContext* ctx) throw()  final;
	Map<String,String>* getParamMap(ThreadContext* ctx) throw()  final;
	void importParams(Map<String,String>* params, ThreadContext* ctx) throw()  final;
	long long getStackId(ThreadContext* ctx) throw() ;
	void setStackId(long long stackId, ThreadContext* ctx) throw() ;
	long long getThreadId(ThreadContext* ctx) throw() ;
	void setThreadId(long long threadId, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}}

#endif /* end of ALINOUS_RUNTIME_ENGINE_DEBUGGER_CLIENT_STEPINREQUEST_H_ */