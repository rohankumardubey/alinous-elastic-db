#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {





constexpr const int AbstractSQLBooleanCollectionExpression::AND_EXP;
constexpr const int AbstractSQLBooleanCollectionExpression::OR_EXP;
bool AbstractSQLBooleanCollectionExpression::__init_done = __init_static_variables();
bool AbstractSQLBooleanCollectionExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractSQLBooleanCollectionExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractSQLBooleanCollectionExpression::AbstractSQLBooleanCollectionExpression(ThreadContext* ctx) throw()  : IObject(ctx), ISQLBoolExpression(ctx), first(nullptr), expressions(GCUtils<ArrayList<SQLBoolSubExpression> >::ins(this, (new(ctx) ArrayList<SQLBoolSubExpression>(ctx)), ctx, __FILEW__, __LINE__, L"")), asName(nullptr)
{
}
void AbstractSQLBooleanCollectionExpression::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AbstractSQLBooleanCollectionExpression::AbstractSQLBooleanCollectionExpression(ArrayList<ISQLExpression>* list, String* op, ThreadContext* ctx) throw()  : IObject(ctx), ISQLBoolExpression(ctx), first(nullptr), expressions(GCUtils<ArrayList<SQLBoolSubExpression> >::ins(this, (new(ctx) ArrayList<SQLBoolSubExpression>(ctx)), ctx, __FILEW__, __LINE__, L"")), asName(nullptr)
{
	if(list->isEmpty(ctx))
	{
		return;
	}
	int maxLoop = list->size(ctx);
	__GC_MV(this, &(this->first), list->get(0, ctx), ISQLExpression);
	for(int i = 1; i != maxLoop; ++i)
	{
		SQLBoolSubExpression* subExp = (new(ctx) SQLBoolSubExpression(op, list->get(i, ctx), ctx));
		this->expressions->add(subExp, ctx);
	}
}
void AbstractSQLBooleanCollectionExpression::__construct_impl(ArrayList<ISQLExpression>* list, String* op, ThreadContext* ctx) throw() 
{
	if(list->isEmpty(ctx))
	{
		return;
	}
	int maxLoop = list->size(ctx);
	__GC_MV(this, &(this->first), list->get(0, ctx), ISQLExpression);
	for(int i = 1; i != maxLoop; ++i)
	{
		SQLBoolSubExpression* subExp = (new(ctx) SQLBoolSubExpression(op, list->get(i, ctx), ctx));
		this->expressions->add(subExp, ctx);
	}
}
 AbstractSQLBooleanCollectionExpression::~AbstractSQLBooleanCollectionExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractSQLBooleanCollectionExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AbstractSQLBooleanCollectionExpression", L"~AbstractSQLBooleanCollectionExpression");
	__e_obj1.add(this->first, this);
	first = nullptr;
	__e_obj1.add(this->expressions, this);
	expressions = nullptr;
	__e_obj1.add(this->asName, this);
	asName = nullptr;
	if(!prepare){
		return;
	}
	ISQLBoolExpression::__releaseRegerences(true, ctx);
}
ISQLExpression* AbstractSQLBooleanCollectionExpression::getFirst(ThreadContext* ctx) throw() 
{
	return first;
}
void AbstractSQLBooleanCollectionExpression::setFirst(ISQLExpression* first, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->first), first, ISQLExpression);
}
ArrayList<SQLBoolSubExpression>* AbstractSQLBooleanCollectionExpression::getExpressions(ThreadContext* ctx) throw() 
{
	return expressions;
}
void AbstractSQLBooleanCollectionExpression::addSubExpression(SQLBoolSubExpression* exp, ThreadContext* ctx) throw() 
{
	this->expressions->add(exp, ctx);
}
bool AbstractSQLBooleanCollectionExpression::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->first != nullptr && !this->first->visit(visitor, this, ctx))
	{
		return false;
	}
	int maxLoop = this->expressions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		if(!this->expressions->get(i, ctx)->visit(visitor, this, ctx))
		{
			return false;
		}
	}
	return true;
}
bool AbstractSQLBooleanCollectionExpression::isConstant(ThreadContext* ctx) throw() 
{
	if(this->first != nullptr && !this->first->isConstant(ctx))
	{
		return false;
	}
	int maxLoop = this->expressions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		if(!this->expressions->get(i, ctx)->isConstant(ctx))
		{
			return false;
		}
	}
	return true;
}
bool AbstractSQLBooleanCollectionExpression::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->first != nullptr)
	{
		this->first->analyse(context, leftValue, ctx);
	}
	int maxLoop = this->expressions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		bool res = this->expressions->get(i, ctx)->analyse(context, leftValue, ctx);
		if(!res)
		{
			break ;
		}
	}
	return true;
}
ExpressionSourceId* AbstractSQLBooleanCollectionExpression::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(nullptr, this, (new(ctx) AlinousType(AlinousType::BOOL_TYPE, AlinousType::TYPE_PRIMITIVE, ctx)), ctx));
}
bool AbstractSQLBooleanCollectionExpression::analyseSQL(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx)
{
	if(this->first != nullptr)
	{
		this->first->analyseSQL(context, leftValue, debug, ctx);
	}
	int maxLoop = this->expressions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		this->expressions->get(i, ctx)->analyseSQL(context, leftValue, debug, ctx);
	}
	return true;
}
bool AbstractSQLBooleanCollectionExpression::hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw() 
{
	if(this->first != nullptr && this->first->hasTable(table, ctx))
	{
		return true;
	}
	int maxLoop = this->expressions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		bool ans = this->expressions->get(i, ctx)->hasTable(table, ctx);
		if(ans)
		{
			return true;
		}
	}
	return false;
}
ArrayList<ScanTableColumnIdentifier>* AbstractSQLBooleanCollectionExpression::getColumns(ThreadContext* ctx) throw() 
{
	ArrayList<ScanTableColumnIdentifier>* list = (new(ctx) ArrayList<ScanTableColumnIdentifier>(ctx));
	if(this->first != nullptr)
	{
		ArrayList<ScanTableColumnIdentifier>* sublist = this->first->getColumns(ctx);
		if(sublist != nullptr)
		{
			list->addAll(sublist, ctx);
		}
	}
	int maxLoop = this->expressions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		list = SQLAnalyseContext::joinList(list, this->expressions->get(i, ctx), ctx);
	}
	return list;
}
bool AbstractSQLBooleanCollectionExpression::hasSubExp(ThreadContext* ctx) throw() 
{
	return true;
}
int AbstractSQLBooleanCollectionExpression::getLine(ThreadContext* ctx) throw() 
{
	return ISQLBoolExpression::getLine(ctx);
}
int AbstractSQLBooleanCollectionExpression::getStartPosition(ThreadContext* ctx) throw() 
{
	return ISQLBoolExpression::getStartPosition(ctx);
}
int AbstractSQLBooleanCollectionExpression::getEndLine(ThreadContext* ctx) throw() 
{
	return ISQLBoolExpression::getEndLine(ctx);
}
int AbstractSQLBooleanCollectionExpression::getEndPosition(ThreadContext* ctx) throw() 
{
	return ISQLBoolExpression::getEndPosition(ctx);
}
AbstractSrcElement* AbstractSQLBooleanCollectionExpression::getParent(ThreadContext* ctx) throw() 
{
	return ISQLBoolExpression::getParent(ctx);
}
void AbstractSQLBooleanCollectionExpression::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	ISQLBoolExpression::setParent(parent, ctx);
}
bool AbstractSQLBooleanCollectionExpression::isSQLExp(ThreadContext* ctx) throw() 
{
	return true;
}
String* AbstractSQLBooleanCollectionExpression::getAsName(ThreadContext* ctx) throw() 
{
	return this->asName;
}
void AbstractSQLBooleanCollectionExpression::setAsName(String* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->asName), name, String);
}
}}}}}
