#include "includes.h"


namespace alinous {namespace compile {namespace stmt {





bool ForStatement::__init_done = __init_static_variables();
bool ForStatement::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ForStatement", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ForStatement::~ForStatement() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ForStatement::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ForStatement", L"~ForStatement");
	__e_obj1.add(this->label, this);
	label = nullptr;
	__e_obj1.add(this->initStatement, this);
	initStatement = nullptr;
	__e_obj1.add(this->condition, this);
	condition = nullptr;
	__e_obj1.add(this->updatePart, this);
	updatePart = nullptr;
	__e_obj1.add(this->exec, this);
	exec = nullptr;
	if(!prepare){
		return;
	}
	AbstractAlinousStatement::__releaseRegerences(true, ctx);
}
void ForStatement::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
}
bool ForStatement::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->label != nullptr && !this->label->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->initStatement != nullptr && !this->initStatement->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->condition != nullptr && !this->condition->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->updatePart != nullptr && !this->updatePart->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->exec != nullptr && !this->exec->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool ForStatement::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->label != nullptr)
	{
		this->label->analyse(context, leftValue, ctx);
	}
	if(this->initStatement != nullptr)
	{
		this->initStatement->analyse(context, leftValue, ctx);
	}
	if(this->condition != nullptr)
	{
		this->condition->analyse(context, leftValue, ctx);
	}
	if(this->updatePart != nullptr)
	{
		this->updatePart->analyse(context, leftValue, ctx);
	}
	if(this->exec != nullptr)
	{
		this->exec->analyse(context, leftValue, ctx);
	}
	return true;
}
IStatement::StatementType ForStatement::getType(ThreadContext* ctx) throw() 
{
	return StatementType::FOR_STATEMENT;
}
LabeledStatement* ForStatement::getLabel(ThreadContext* ctx) throw() 
{
	return label;
}
void ForStatement::setLabel(LabeledStatement* label, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->label), label, LabeledStatement);
}
IStatement* ForStatement::getInitStatement(ThreadContext* ctx) throw() 
{
	return initStatement;
}
void ForStatement::setInitStatement(IStatement* initStatement, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->initStatement), initStatement, IStatement);
}
IExpression* ForStatement::getCondition(ThreadContext* ctx) throw() 
{
	return condition;
}
void ForStatement::setCondition(IExpression* condition, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->condition), condition, IExpression);
}
ForUpdatePart* ForStatement::getUpdatePart(ThreadContext* ctx) throw() 
{
	return updatePart;
}
void ForStatement::setUpdatePart(ForUpdatePart* updatePart, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->updatePart), updatePart, ForUpdatePart);
}
IStatement* ForStatement::getExec(ThreadContext* ctx) throw() 
{
	return exec;
}
void ForStatement::setExec(IStatement* exec, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->exec), exec, IStatement);
}
}}}
