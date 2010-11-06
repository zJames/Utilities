//------------------------------------------------------------------------------
//  Authors :
//	  JRP	James Prettyman
//------------------------------------------------------------------------------

#pragma once
////////////////////////////////////////////////////////////////////////////////


#include <boost/utility.hpp>


typedef unsigned char BYTE;


//------------------------------------------------------------------------------
//	ObjBuff
//------------------------------------------------------------------------------
template<class T>
class ObjBuf : boost::noncopyable
{
public:
	static const int kBuffSize = sizeof(T);

	ObjBuf(): mConstructed(false) { }
	~ObjBuf() { erase(); }

	inline T* get() { return reinterpret_cast<T*>(mData); }
	inline T* operator ->() { return get(); }

	inline const T* get() const { return reinterpret_cast<const T*>(mData); }
	inline const T* operator ->() const { return get(); }
	inline bool constructed() const { return mConstructed; }

	void construct()
	{
		erase();
		new (mData) T();
		mConstructed = true;
	}

	template<class A>
	void construct(const A& a)
	{
		erase();
		new (mData) T(a);
		mConstructed = true;
	}

	template<class A, class B>
	void construct(const A& a, const B& b)
	{
		erase();
		new (mData) T(a, b);
		mConstructed = true;
	}

	template<class A, class B, class C>
	void construct(const A& a, const B& b, const C& c)
	{
		erase();
		new (mData) T(a, b, c);
		mConstructed = true;
	}

	template<class A, class B, class C, class D>
	void construct(const A& a, const B& b, const C& c, const D& d)
	{
		erase();
		new (mData) T(a, b, c, d);
		mConstructed = true;
	}

	template<class A, class B, class C, class D, class E>
	void construct(const A& a, const B& b, const C& c, const D& d, const E& e)
	{
		erase();
		new (mData) T(a, b, c, d, e);
		mConstructed = true;
	}

	template<class A, class B, class C, class D, class E, class F>
	void construct(const A& a, const B& b, const C& c, const D& d, const E& e, const F& f)
	{
		erase();
		new (mData) T(a, b, c, d, e, f);
		mConstructed = true;
	}

	template<class A, class B, class C, class D, class E, class F, class G>
	void construct(const A& a, const B& b, const C& c, const D& d, const E& e, const F& f, const G& g)
	{
		erase();
		new (mData) T(a, b, c, d, e, f, g);
		mConstructed = true;
	}

	template<class A, class B, class C, class D, class E, class F, class G, class H>
	void construct(const A& a, const B& b, const C& c, const D& d, const E& e, const F& f, const G& g, const H& h)
	{
		erase();
		new (mData) T(a, b, c, d, e, f, g, h);
		mConstructed = true;
	}

	void erase()
	{
		if (mConstructed)
			get()->~T();

		mConstructed = false;
	}

private:
	BYTE mData[kBuffSize];
	bool mConstructed;
};
