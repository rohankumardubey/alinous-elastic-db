#ifndef ALINOUS_COMPILE_EXPRESSION_DOMINDEXSEGMENT_H_
#define ALINOUS_COMPILE_EXPRESSION_DOMINDEXSEGMENT_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace expression {
class IExpression;}}}

namespace java {namespace lang {
class StringBuffer;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace compile {
class Token;}}

namespace alinous {namespace compile {namespace expression {
class IDomSegment;}}}

namespace alinous {namespace runtime {namespace dom {
class IDomVariable;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace expression {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::compile::AbstractSrcElement;
using ::alinous::compile::Token;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::runtime::dom::IDomVariable;
using ::alinous::runtime::dom::VariableException;



class DomIndexSegment final : public IDomSegment {
public:
	DomIndexSegment(const DomIndexSegment& base) = default;
public:
	DomIndexSegment(ThreadContext* ctx) throw()  : IObject(ctx), IDomSegment(ctx), index(nullptr), segmentVariableType(IDomVariable::TYPE_DOM)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	DomIndexSegment(IExpression* index, ThreadContext* ctx) throw() ;
	void __construct_impl(IExpression* index, ThreadContext* ctx) throw() ;
	virtual ~DomIndexSegment() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	IExpression* index;
	int segmentVariableType;
public:
	String* toString(ThreadContext* ctx) throw() ;
	IExpression* getIndex(ThreadContext* ctx) throw()  final;
	void setIndex(IExpression* index, ThreadContext* ctx) throw() ;
	int getDomSegmentType(ThreadContext* ctx) throw()  final;
	String* getName(ThreadContext* ctx) final;
	int getSegmentVariableType(ThreadContext* ctx) throw()  final;
	void setSegmentVariableType(int segmentVariableType, ThreadContext* ctx) throw()  final;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
	int getLine(ThreadContext* ctx) throw()  final;
	int getStartPosition(ThreadContext* ctx) throw()  final;
	int getEndLine(ThreadContext* ctx) throw()  final;
	int getEndPosition(ThreadContext* ctx) throw()  final;
	AbstractSrcElement* getParent(ThreadContext* ctx) throw()  final;
	void setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	void position(Token* t2, AbstractSrcElement* segment, ThreadContext* ctx) throw()  final;
	void position(Token* start, Token* end, ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_COMPILE_EXPRESSION_DOMINDEXSEGMENT_H_ */