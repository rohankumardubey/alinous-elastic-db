#ifndef ALINOUS_COMPILE_DECLARE_VIRTUALTABLE_H_
#define ALINOUS_COMPILE_DECLARE_VIRTUALTABLE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace declare {
class AlinousClass;}}}

namespace alinous {namespace compile {namespace declare {
class ClassMethodFunction;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace declare {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;



class VirtualTable final : public virtual IObject {
public:
	class MethodPair;
	VirtualTable(const VirtualTable& base) = default;
public:
	VirtualTable(ThreadContext* ctx) throw()  : IObject(ctx), list(GCUtils<ArrayList<VirtualTable::MethodPair> >::ins(this, (new(ctx) ArrayList<VirtualTable::MethodPair>(ctx)), ctx, __FILEW__, __LINE__, L""))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~VirtualTable() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ArrayList<VirtualTable::MethodPair>* list;
public:
	void addVirtualFunction(AlinousClass* clazz, ClassMethodFunction* method, ThreadContext* ctx) throw() ;
	ClassMethodFunction* getMethod(AlinousClass* clazz, ThreadContext* ctx) throw() ;
public:



	class MethodPair final : public virtual IObject {
	public:
		MethodPair(const MethodPair& base) = default;
	public:
		MethodPair(AlinousClass* clazz, ClassMethodFunction* func, ThreadContext* ctx) throw() ;
		void __construct_impl(AlinousClass* clazz, ClassMethodFunction* func, ThreadContext* ctx) throw() ;
		virtual ~MethodPair() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	public:
		AlinousClass* clazz;
		ClassMethodFunction* func;
	public:
		static bool __init_done;
		static bool __init_static_variables();
	public:
		static void __cleanUp(ThreadContext* ctx){
		}
	};

	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_COMPILE_DECLARE_VIRTUALTABLE_H_ */