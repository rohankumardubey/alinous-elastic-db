#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace expression {





bool SQLSubqueryExpression::__init_done = __init_static_variables();
bool SQLSubqueryExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SQLSubqueryExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SQLSubqueryExpression::~SQLSubqueryExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SQLSubqueryExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SQLSubqueryExpression", L"~SQLSubqueryExpression");
	__e_obj1.add(this->selectStatement, this);
	selectStatement = nullptr;
	if(!prepare){
		return;
	}
	AbstractSQLCollectionExpression::__releaseRegerences(true, ctx);
}
bool SQLSubqueryExpression::hasSubExp(ThreadContext* ctx) throw() 
{
	return false;
}
bool SQLSubqueryExpression::isJoinCondition(ThreadContext* ctx) throw() 
{
	return false;
}
void SQLSubqueryExpression::collectJoinCondition(ArrayList<ISQLExpression>* list, ThreadContext* ctx) throw() 
{
}
bool SQLSubqueryExpression::isColumnIdentifier(ThreadContext* ctx) throw() 
{
	return false;
}
ScanTableColumnIdentifier* SQLSubqueryExpression::toColumnIdentifier(ThreadContext* ctx) throw() 
{
	return nullptr;
}
VariantValue* SQLSubqueryExpression::resolveSQLExpression(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	return nullptr;
}
IAlinousVariable* SQLSubqueryExpression::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	return nullptr;
}
ExpressionSourceId* SQLSubqueryExpression::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(nullptr, this, nullptr, ctx));
}
SelectStatement* SQLSubqueryExpression::getSelectStatement(ThreadContext* ctx) throw() 
{
	return selectStatement;
}
void SQLSubqueryExpression::setSelectStatement(SelectStatement* selectStatement, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->selectStatement), selectStatement, SelectStatement);
}
bool SQLSubqueryExpression::hasArrayResult(ThreadContext* ctx) throw() 
{
	return true;
}
ArrayList<VariantValue>* SQLSubqueryExpression::resolveSQLExpressionAsArray(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	return nullptr;
}
int SQLSubqueryExpression::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::sQLSubqueryExpression;
}
}}}}
