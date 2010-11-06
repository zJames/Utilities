//------------------------------------------------------------------------------
//  Copyright : (c) 2006
//  Authors :
//	  JRP	James Prettyman
//------------------------------------------------------------------------------
#ifndef SCOPEDPTR_H
#define SCOPEDPTR_H
////////////////////////////////////////////////////////////////////////////////


//------------------------------------------------------------------------------
//	Scoped Pointer Class
//------------------------------------------------------------------------------
template<class T>
class ScopedPtr
{
public:
	typedef ScopedPtr<T> This;

	ScopedPtr(): mPtr(NULL) {}
	ScopedPtr(T* ptr): mPtr(NULL) { set(ptr); }
	~ScopedPtr() { delete mPtr; }

	T* operator -> () const			{ return mPtr; }
	void set(T* ptr)				{ delete mPtr; mPtr = ptr; }
	void set(This& ptr)				{ delete mPtr; mPtr = ptr.mPtr; ptr.mPtr = 0; }
	This& operator = (T* ptr)		{ set(ptr); return *this; }
	This& operator = (This& rhs)	{ set(rhs); return *this; }
	operator bool () const			{ return mPtr != NULL; }
	T* get() const					{ return mPtr; }
	T* release()					{ T* ptr = mPtr; mPtr = 0; return ptr; }

private:
	T* mPtr;
};


//------------------------------------------------------------------------------
//	Scoped Array Class
//------------------------------------------------------------------------------
template<class T>
class ScopedArray
{
public:
	typedef ScopedArray<T> This;

	ScopedArray(): mPtr(NULL)		{}
	ScopedArray(T* ptr): mPtr(NULL)	{ set(ptr); }
	~ScopedArray()					{ delete [] mPtr; }

	T& operator [] (int n)			{ return mPtr[n]; }
	void set(T* ptr)				{ delete mPtr; mPtr = ptr; }
	void set(This& ptr)				{ delete mPtr; mPtr = ptr.mPtr; ptr.mPtr = 0; }
	This& operator = (T* ptr)		{ set(ptr); return *this; }
	This& operator = (This& rhs)	{ set(rhs); return *this; }
	operator bool () const			{ return mPtr != NULL; }
	T* get() const					{ return mPtr; }
	T* release()					{ T* ptr = mPtr; mPtr = 0; return ptr; }

private:
	T* mPtr;
};


////////////////////////////////////////////////////////////////////////////////
#endif