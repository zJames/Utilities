//------------------------------------------------------------------------------
//  Copyright : (c) 2009
//  Authors :
//	  JRP	James Prettyman
//------------------------------------------------------------------------------

#pragma once
////////////////////////////////////////////////////////////////////////////////


//------------------------------------------------------------------------------
//	PushValue
//------------------------------------------------------------------------------
template<class T>
class PushValue
{
public:
	PushValue(Ptr<T> dest, const T& newVal)
		:
		mDest(dest),
		mOldVal(*dest)
	{
		*dest = newVal;
	}

	~PushValue()
	{
		*mDest = mOldVal;
	}

private:
	const Ptr<T> mDest;
	const T mOldVal;
};