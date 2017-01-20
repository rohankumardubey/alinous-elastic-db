#include "includes.h"


namespace alinous {namespace db {namespace table {





bool TablePartitionMaxValue::__init_done = __init_static_variables();
bool TablePartitionMaxValue::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TablePartitionMaxValue", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TablePartitionMaxValue::~TablePartitionMaxValue() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TablePartitionMaxValue::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TablePartitionMaxValue", L"~TablePartitionMaxValue");
	__e_obj1.add(this->values, this);
	values = nullptr;
	if(!prepare){
		return;
	}
}
void TablePartitionMaxValue::addValue(VariantValue* value, ThreadContext* ctx) throw() 
{
	this->values->add(value, ctx);
}
int TablePartitionMaxValue::fileSize(ThreadContext* ctx)
{
	int total = 4;
	int maxLoop = this->values->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* value = this->values->get(i, ctx);
		total += value->bufferSize(ctx);
	}
	return total;
}
void TablePartitionMaxValue::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	int maxLoop = this->values->size(ctx);
	builder->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* value = this->values->get(i, ctx);
		value->appendToEntry(builder, ctx);
	}
}
void TablePartitionMaxValue::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* value = (new(ctx) VariantValue(ctx));
		value->readData(buff, ctx);
		addValue(value, ctx);
	}
}
void TablePartitionMaxValue::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	int maxLoop = this->values->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* value = this->values->get(i, ctx);
		value->writeData(buff, ctx);
	}
}
TablePartitionMaxValue* TablePartitionMaxValue::loadFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	TablePartitionMaxValue* maxValue = (new(ctx) TablePartitionMaxValue(ctx));
	int maxLoop = fetcher->fetchInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* value = VariantValue::valueFromFetcher(fetcher, ctx);
		maxValue->addValue(value, ctx);
	}
	return maxValue;
}
TablePartitionMaxValue* TablePartitionMaxValue::fromNetwork(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	TablePartitionMaxValue* value = (new(ctx) TablePartitionMaxValue(ctx));
	value->readData(buff, ctx);
	return value;
}
}}}
