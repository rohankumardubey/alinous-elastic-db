#include "includes.h"


namespace alinous {namespace runtime {namespace variant {





String* ShortData::TAG_NAME = ConstStr::getCNST_STR_1173();
bool ShortData::__init_done = __init_static_variables();
bool ShortData::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ShortData", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ShortData::ShortData(short data, ThreadContext* ctx) throw()  : IObject(ctx), IVariantData(ctx), data(0)
{
	this->data = data;
}
void ShortData::__construct_impl(short data, ThreadContext* ctx) throw() 
{
	this->data = data;
}
 ShortData::~ShortData() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ShortData::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ShortData", L"~ShortData");
	if(!prepare){
		return;
	}
}
void ShortData::outDebugXml(DomNode* parentNode, ThreadContext* ctx) throw() 
{
	DomNode* node = (new(ctx) DomNode(TAG_NAME, ctx));
	parentNode->addChild(node, ctx);
	Attribute* attr = (new(ctx) Attribute(IVariantData::ATTR_VALUE, Short::toString(this->data, ctx), node, ctx));
	node->addAttribute(attr, ctx);
}
int ShortData::getType(ThreadContext* ctx) throw() 
{
	return IVariantData::TYPE_SHORT;
}
String* ShortData::getString(ThreadContext* ctx) throw() 
{
	return Short::toString(this->data, ctx);
}
long long ShortData::getLong(ThreadContext* ctx) throw() 
{
	return this->data;
}
int ShortData::getInt(ThreadContext* ctx) throw() 
{
	return this->data;
}
short ShortData::getShort(ThreadContext* ctx) throw() 
{
	return this->data;
}
wchar_t ShortData::getChar(ThreadContext* ctx) throw() 
{
	return ((wchar_t)this->data);
}
char ShortData::getByte(ThreadContext* ctx) throw() 
{
	return ((char)this->data);
}
float ShortData::getFloat(ThreadContext* ctx) throw() 
{
	return this->data;
}
double ShortData::getDouble(ThreadContext* ctx) throw() 
{
	return this->data;
}
bool ShortData::getBoolean(ThreadContext* ctx) throw() 
{
	return this->data > (short)0;
}
BigDecimal* ShortData::getBigDecimal(ThreadContext* ctx) throw() 
{
	return (new(ctx) BigDecimal(this->data, ctx));
}
TimeOnlyTimestamp* ShortData::getTime(ThreadContext* ctx) throw() 
{
	return (new(ctx) TimeOnlyTimestamp(this->data, ctx));
}
Timestamp* ShortData::getTimestamp(ThreadContext* ctx) throw() 
{
	return (new(ctx) Timestamp(this->data, ctx));
}
int ShortData::bufferSize(ThreadContext* ctx) throw() 
{
	return 2;
}
void ShortData::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putShort(this->data, ctx);
}
bool ShortData::isNull(ThreadContext* ctx) throw() 
{
	return false;
}
int ShortData::compareTo(VariantValue* variant, ThreadContext* ctx) throw() 
{
	return this->data - variant->getShort(ctx);
}
ShortData* ShortData::importFromXml(DomNode* node, ThreadContext* ctx) throw() 
{
	if(!node->getName(ctx)->equals(TAG_NAME, ctx))
	{
		return nullptr;
	}
	IVariableValue* attr = node->getAttributeValue(IVariantData::ATTR_VALUE, ctx);
	if(attr == nullptr)
	{
		return nullptr;
	}
	ShortData* data = nullptr;
	{
		try
		{
			String* str = attr->toString(ctx);
			short val = Short::parseShort(str, ctx);
			data = (new(ctx) ShortData(val, ctx));
		}
		catch(Throwable* e)
		{
			e->printStackTrace(ctx);
			return nullptr;
		}
	}
	return data;
}
int ShortData::ValueCompare::operator() (VariantValue* _this, VariantValue* variant, ThreadContext* ctx) const throw()
{
	return _this->compareTo(variant, ctx);
}
}}}
