#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {





constexpr const int SQLRelationalExpression::LT;
constexpr const int SQLRelationalExpression::GT;
constexpr const int SQLRelationalExpression::LT_EQ;
constexpr const int SQLRelationalExpression::GT_EQ;
bool SQLRelationalExpression::__init_done = __init_static_variables();
bool SQLRelationalExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SQLRelationalExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SQLRelationalExpression::~SQLRelationalExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SQLRelationalExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SQLRelationalExpression", L"~SQLRelationalExpression");
	__e_obj1.add(this->left, this);
	left = nullptr;
	__e_obj1.add(this->right, this);
	right = nullptr;
	if(!prepare){
		return;
	}
	AbstractSQLBooleanExpression::__releaseRegerences(true, ctx);
}
bool SQLRelationalExpression::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(!this->left->visit(visitor, this, ctx))
	{
		return false;
	}
	if(!this->right->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool SQLRelationalExpression::isConstant(ThreadContext* ctx) throw() 
{
	if(!this->left->isConstant(ctx))
	{
		return false;
	}
	if(!this->right->isConstant(ctx))
	{
		return false;
	}
	return true;
}
bool SQLRelationalExpression::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	this->left->analyse(context, leftValue, ctx);
	this->right->analyse(context, leftValue, ctx);
	return true;
}
ISQLExpression* SQLRelationalExpression::getLeft(ThreadContext* ctx) throw() 
{
	return left;
}
void SQLRelationalExpression::setLeft(ISQLExpression* left, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->left), left, ISQLExpression);
}
ISQLExpression* SQLRelationalExpression::getRight(ThreadContext* ctx) throw() 
{
	return right;
}
void SQLRelationalExpression::setRight(ISQLExpression* right, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->right), right, ISQLExpression);
}
ArrayList<ScanTableColumnIdentifier>* SQLRelationalExpression::getIndexTargetColumn(ThreadContext* ctx) throw() 
{
	ArrayList<ScanTableColumnIdentifier>* cols = this->left->getColumns(ctx);
	return cols;
}
int SQLRelationalExpression::getOpe(ThreadContext* ctx) throw() 
{
	return ope;
}
void SQLRelationalExpression::setOpe(String* opeStr, ThreadContext* ctx) throw() 
{
	if(opeStr->equals(ConstStr::getCNST_STR_986(), ctx))
	{
		this->ope = LT;
	}
		else 
	{
		if(opeStr->equals(ConstStr::getCNST_STR_82(), ctx))
		{
			this->ope = GT;
		}
				else 
		{
			if(opeStr->equals(ConstStr::getCNST_STR_987(), ctx))
			{
				this->ope = LT_EQ;
			}
						else 
			{
				if(opeStr->equals(ConstStr::getCNST_STR_988(), ctx))
				{
					this->ope = GT_EQ;
				}
			}
		}
	}
}
IAlinousVariable* SQLRelationalExpression::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	IAlinousVariable* val = this->left->resolveExpression(machine, debug, ctx);
	if(this->right == nullptr)
	{
		return val;
	}
	IAlinousVariable* rightVal = this->right->resolveExpression(machine, debug, ctx);
	if((this->ope == LT && val->compareTo(rightVal, ctx) < 0) || (this->ope == LT_EQ && val->compareTo(rightVal, ctx) <= 0) || (this->ope == GT && val->compareTo(rightVal, ctx) > 0) || (this->ope == GT_EQ && val->compareTo(rightVal, ctx) >= 0))
	{
		return (new(ctx) VariantValue(((char)1), ctx));
	}
	return (new(ctx) VariantValue(((char)0), ctx));
}
VariantValue* SQLRelationalExpression::resolveSQLExpression(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	VariantValue* val = this->left->resolveSQLExpression(record, machine, debug, ctx);
	if(this->right == nullptr)
	{
		return val;
	}
	VariantValue* rightVal = this->right->resolveSQLExpression(record, machine, debug, ctx);
	if((this->ope == LT && val->compareTo(rightVal, ctx) < 0) || (this->ope == LT_EQ && val->compareTo(rightVal, ctx) <= 0) || (this->ope == GT && val->compareTo(rightVal, ctx) > 0) || (this->ope == GT_EQ && val->compareTo(rightVal, ctx) >= 0))
	{
		return (new(ctx) VariantValue(((char)1), ctx));
	}
	return (new(ctx) VariantValue(((char)0), ctx));
}
ExpressionSourceId* SQLRelationalExpression::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(nullptr, this, (new(ctx) AlinousType(AlinousType::BOOL_TYPE, AlinousType::TYPE_PRIMITIVE, ctx)), ctx));
}
bool SQLRelationalExpression::analyseSQL(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx)
{
	if(this->left != nullptr)
	{
		this->left->analyseSQL(context, leftValue, debug, ctx);
	}
	if(this->right != nullptr)
	{
		this->right->analyseSQL(context, leftValue, debug, ctx);
	}
	return true;
}
bool SQLRelationalExpression::hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw() 
{
	if(this->left != nullptr && this->left->hasTable(table, ctx))
	{
		return true;
	}
	if(this->right != nullptr && this->right->hasTable(table, ctx))
	{
		return true;
	}
	return false;
}
ArrayList<ScanTableColumnIdentifier>* SQLRelationalExpression::getColumns(ThreadContext* ctx) throw() 
{
	ArrayList<ScanTableColumnIdentifier>* list = (new(ctx) ArrayList<ScanTableColumnIdentifier>(ctx));
	if(this->left != nullptr)
	{
		list = SQLAnalyseContext::joinList(list, this->left, ctx);
	}
	if(this->right != nullptr)
	{
		list = SQLAnalyseContext::joinList(list, this->right, ctx);
	}
	return list;
}
bool SQLRelationalExpression::hasSubExp(ThreadContext* ctx) throw() 
{
	return false;
}
bool SQLRelationalExpression::isJoinCondition(ThreadContext* ctx) throw() 
{
	return false;
}
void SQLRelationalExpression::collectJoinCondition(ArrayList<ISQLExpression>* list, ThreadContext* ctx) throw() 
{
}
bool SQLRelationalExpression::isColumnIdentifier(ThreadContext* ctx) throw() 
{
	return false;
}
IndexColumnMatchCondition* SQLRelationalExpression::getIndexScanPart(ThreadContext* ctx) throw() 
{
	if(isJoinCondition(ctx) || (!this->left->isColumnIdentifier(ctx) && !this->right->isColumnIdentifier(ctx)))
	{
		return nullptr;
	}
	ScanTableColumnIdentifier* colId = this->left->isColumnIdentifier(ctx) ? this->left->toColumnIdentifier(ctx) : this->right->toColumnIdentifier(ctx);
	IndexColumnMatchCondition* part = nullptr;
	switch(this->ope) {
	case LT:
		part = (new(ctx) IndexColumnMatchCondition(colId, IndexColumnMatchCondition::INDEX_BEFORE, nullptr, this->right, ctx));
		break ;
	case GT:
		part = (new(ctx) IndexColumnMatchCondition(colId, IndexColumnMatchCondition::INDEX_AFTER, this->right, nullptr, ctx));
		break ;
	case LT_EQ:
		part = (new(ctx) IndexColumnMatchCondition(colId, IndexColumnMatchCondition::INDEX_BEFORE, nullptr, this->right, ctx));
		part->setEndEq(true, ctx);
		break ;
	case GT_EQ:
	default:
		part = (new(ctx) IndexColumnMatchCondition(colId, IndexColumnMatchCondition::INDEX_AFTER, this->right, nullptr, ctx));
		part->setStartEq(true, ctx);
		break ;
	}
	return part;
}
ScanTableColumnIdentifier* SQLRelationalExpression::toColumnIdentifier(ThreadContext* ctx) throw() 
{
	return nullptr;
}
bool SQLRelationalExpression::hasArrayResult(ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<VariantValue>* SQLRelationalExpression::resolveSQLExpressionAsArray(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1006(), ctx));
}
int SQLRelationalExpression::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::sQLRelationalExpression;
}
}}}}}
