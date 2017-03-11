#include "include/global.h"


#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.remote.region.server.schema.strategy/UniqueOpValue.h"
#include "alinous.remote.region.server.schema.strategy/UniqueCheckOperation.h"

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {namespace strategy {





bool UniqueCheckOperation::__init_done = __init_static_variables();
bool UniqueCheckOperation::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"UniqueCheckOperation", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 UniqueCheckOperation::UniqueCheckOperation(List<TableColumnMetadata>* uniqueColList, ThreadContext* ctx) throw()  : IObject(ctx), uniqueColList(nullptr), values(GCUtils<List<UniqueOpValue> >::ins(this, (new(ctx) ArrayList<UniqueOpValue>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
	GCUtils<List<TableColumnMetadata> >::mv(this, &(this->uniqueColList), uniqueColList, ctx);
}
void UniqueCheckOperation::__construct_impl(List<TableColumnMetadata>* uniqueColList, ThreadContext* ctx) throw() 
{
	GCUtils<List<TableColumnMetadata> >::mv(this, &(this->uniqueColList), uniqueColList, ctx);
}
 UniqueCheckOperation::~UniqueCheckOperation() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void UniqueCheckOperation::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"UniqueCheckOperation", L"~UniqueCheckOperation");
	__e_obj1.add(this->uniqueColList, this);
	uniqueColList = nullptr;
	__e_obj1.add(this->values, this);
	values = nullptr;
	if(!prepare){
		return;
	}
}
void UniqueCheckOperation::addValue(List<VariantValue>* values, ThreadContext* ctx) throw() 
{
	UniqueOpValue* value = (new(ctx) UniqueOpValue(values, ctx));
	this->values->add(value, ctx);
}
List<TableColumnMetadata>* UniqueCheckOperation::getUniqueColList(ThreadContext* ctx) throw() 
{
	return uniqueColList;
}
List<UniqueOpValue>* UniqueCheckOperation::getValues(ThreadContext* ctx) throw() 
{
	return values;
}
void UniqueCheckOperation::__cleanUp(ThreadContext* ctx){
}
}}}}}}

