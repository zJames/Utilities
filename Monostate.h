//------------------------------------------------------------------------------
//  Authors :
//	  JRP	James Prettyman
//------------------------------------------------------------------------------

#pragma once

#include <boost/scoped_ptr.hpp>
#include <boost/utility.hpp>
////////////////////////////////////////////////////////////////////////////////


//------------------------------------------------------------------------------
//	Monostate
//------------------------------------------------------------------------------
namespace detail
{
	template<class T, class Name>
	class MonoDetail : boost::noncopyable
	{
	public:
		class Reference : boost::noncopyable
		{
		public:
			typedef MonoDetail<T, Name> Parent;

			Reference()
			{
				if (Parent::sRefCount == 0)
					Parent::sMonoVal.reset(new T());

				++Parent::sRefCount;
			}

			Reference(T* newVal)
			{
				assert(Parent::sRefCount == 0);

				Parent::sMonoVal.reset(newVal);

				++Parent::sRefCount;
			}

			~Reference()
			{
				--Parent::sRefCount;

				if (Parent::sRefCount == 0)
					Parent::sMonoVal.reset(NULL);
			}
		};

		class FirstReference : public Reference
		{
		public:
			FirstReference(T* newVal)
				:
				Reference(newVal)
			{
			}

			FirstReference()
				:
				Reference(new T())
			{
			}
		};

		T* get() { return sMonoVal.get(); }
		T* operator -> () { assert(sMonoVal.get() != NULL); return sMonoVal.get(); }
		T& operator * () { assert(sMonoVal.get() != NULL); return *sMonoVal.get(); }

	private:
		friend class Reference;
		friend class FirstReference;

		static void addRef()
		{
			++sRefCount;
		}

		static void removeRef()
		{
			--sRefCount;

			if (sRefCount == 0)
			{
				sMonoVal.reset(NULL);
			}

			assert(sRefCount >= 0);
		}

		static int sRefCount;
		static boost::scoped_ptr<T> sMonoVal;
	};
}

#define Monostate(Type, name) \
	class name: public detail::MonoDetail<Type, name> {}

template<class T, class Name> boost::scoped_ptr<T> detail::MonoDetail<T, Name>::sMonoVal;
template<class T, class Name> int detail::MonoDetail<T, Name>::sRefCount;