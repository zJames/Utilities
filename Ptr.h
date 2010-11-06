//------------------------------------------------------------------------------
//  Authors :
//	  JRP	James Prettyman
//------------------------------------------------------------------------------

#ifndef PTR_H
#define PTR_H

#include <assert.h>
////////////////////////////////////////////////////////////////////////////////


//------------------------------------------------------------------------------
//	Pointer Wrapper
//------------------------------------------------------------------------------
template<class T>
class Ptr
{
public:
	typedef Ptr<T> This;

	Ptr(T* ptr = NULL): mPtr(ptr) {}

	inline T* operator -> () const				{ assert(mPtr != NULL); return mPtr; }
	inline T& operator * () const				{ assert(mPtr != NULL); return *mPtr; }
	inline const T& operator[] (int n) const	{ assert(mPtr != NULL); return mPtr[n]; }
	inline T* get() const						{ return mPtr; }
	inline void set(T* ptr)						{ mPtr = ptr; }
	inline T& operator[] (int n)				{ assert(mPtr != NULL); return mPtr[n]; }

	inline bool operator == (const This& other) const { return mPtr == other.mPtr; }

private:
	T* mPtr;
};


////////////////////////////////////////////////////////////////////////////////
#endif