//------------------------------------------------------------------------------
//  Authors :
//	  JRP	James Prettyman
//------------------------------------------------------------------------------

#pragma once
////////////////////////////////////////////////////////////////////////////////


#include "ObjBuff.h"

#include <boost/shared_array.hpp>
#include <list>


//------------------------------------------------------------------------------
//	BlockArray
//------------------------------------------------------------------------------
template<class T>
int count(const ObjBuf<T>* blocks, int numBlocks)
{
	int ret = 0;

	for (int i = 0; i < numBlocks; ++i)
	{
		if (blocks[i].constructed())
			++ret;
	}

	return ret;
}


template<class T, int kBlockSizeLog2 = 3>
class BlockArray
{
public:
	static const int kBlocksPerGroup = 1 << kBlockSizeLog2;
	typedef ObjBuf<T> Block;
	typedef boost::shared_array<Block> BlockGroup;
	typedef std::list<BlockGroup> BlockList;

	class Iterator
	{
	public:
		Iterator& operator ++()
		{
			if (mBlockIter != mBlockList->end())
				incSubIndex();

			return *this;
		}

		Iterator& operator =(const Iterator& other)
		{
			mBlockList = other.mBlockList;
			mBlockIter = other.mBlockIter;
			mSubIndex = other.mSubIndex;

			return *this;
		}

		bool operator != (const Iterator& other) const
		{
			return
				mBlockList != other.mBlockList
				|| mBlockIter != other.mBlockIter
				|| mSubIndex != other.mSubIndex;
		}

		T& operator *()
		{
			return *block().get();
		}

	private:
		friend class BlockArray;
		
		Iterator(BlockList* blockList)
			:
			mBlockList(blockList),
			mSubIndex(0)
		{
			mBlockIter = blockList->begin();

			while (!(*mBlockIter)[mSubIndex].constructed())
				++mSubIndex;
		}

		Iterator(BlockList* blockList, typename BlockList::iterator blockItr)
			:
			mBlockList(blockList),
			mBlockIter(blockItr),
			mSubIndex(0)
		{
		}

		Block& block()
		{
			return (*mBlockIter)[mSubIndex];
		}

		void incSubIndex()
		{
			if (mBlockIter == mBlockList->end())
				return;

			++mSubIndex;

			if (mSubIndex == kBlocksPerGroup)
			{
				++mBlockIter;
				mSubIndex = 0;
			}

			if (mBlockIter != mBlockList->end() && !(*mBlockIter)[mSubIndex].constructed())
				incSubIndex();
		}

		BlockList* mBlockList;
		typename BlockList::iterator mBlockIter;
		int mSubIndex;
	};


	void construct()
	{
		alloc()->construct();
	}


	template<class A>
	void construct(const A& a)
	{
		alloc()->construct(a);
	}


	template<class A, class B>
	void construct(const A& a, const B& b)
	{
		alloc()->construct(a, b);
	}


	template<class A, class B, class C>
	void construct(const A& a, const B& b, const C& c)
	{
		alloc()->construct(a, b, c);
	}


	template<class A, class B, class C, class D>
	void construct(const A& a, const B& b, const C& c, const D& d)
	{
		alloc()->construct(a, b, c, d);
	}


	template<class A, class B, class C, class D, class E>
	void construct(const A& a, const B& b, const C& c, const D& d, const E& e)
	{
		alloc()->construct(a, b, c, d, e);
	}


	template<class A, class B, class C, class D, class E, class F>
	void construct(const A& a, const B& b, const C& c, const D& d, const E& e, const F& f)
	{
		alloc()->construct(a, b, c, d, e, f);
	}


	template<class A, class B, class C, class D, class E, class F, class G>
	void construct(const A& a, const B& b, const C& c, const D& d, const E& e, const F& f, const G& g)
	{
		alloc()->construct(a, b, c, d, e, f, g);
	}


	template<class A, class B, class C, class D, class E, class F, class G, class H>
	void construct(const A& a, const B& b, const C& c, const D& d, const E& e, const F& f, const G& g, const H& h)
	{
		alloc()->construct(a, b, c, d, e, f, g, h);
	}


	T& front()
	{
		return *begin();
	}


	T& back()
	{
		int count = size();
		Iterator it = begin();

		while (--count > 1)
			++it;

		return *it;
	}


	Iterator begin()
	{
		return Iterator(&mBlocks);
	}


	Iterator end()
	{
		return Iterator(&mBlocks, mBlocks.end());
	}


	Iterator erase(Iterator it)
	{
		if (it == end())
			return;

		const Iterator oldIt = it;
		++it;

		oldIt->block().erase();

		return it;
	}


	bool empty() { return size() == 0; }


	void pop_back()
	{
		for (BlockList::reverse_iterator i = mBlocks.rbegin(); i != mBlocks.rend(); ++i)
		{
			for (int b = kBlocksPerGroup - 1; b >= 0; --b)
			{
				if ((*i)[b].constructed())
				{
					(*i)[b].erase();
					return;
				}
			}
		}
	}


	void clear()
	{
		for (BlockList::iterator i = mBlocks.begin(); i != mBlocks.end(); ++i)
		{
			for (int b = 0; b < kBlocksPerGroup; ++b)
			{
				(*i)[b].erase();
			}
		}
	}


	int size() const
	{
		int count = 0;

		for (BlockList::const_iterator i = mBlocks.begin(); i != mBlocks.end(); ++i)
		{
			for (int b = 0; b < kBlocksPerGroup; ++b)
			{
				if (mBlocks.back()[b].constructed())
				{
					++count;
				}
			}
		}

		return count;
	}


	void freeMemory()
	{
		mBlocks.clear();
	}


private:
	Block* alloc()
	{
		for (BlockList::iterator i = mBlocks.begin(); i != mBlocks.end();)
		{
			if (count<T>(i->get(), kBlocksPerGroup) == 0)
				i = mBlocks.erase(i);
			else
				++i;
		}

		if (!mBlocks.empty())
		{
			BlockGroup& block = mBlocks.back();

			for (int b = 0; b < kBlocksPerGroup; ++b)
			{
				if (!block[b].constructed())
				{
					return &block[b];
				}
			}
		}

		mBlocks.push_back(BlockGroup(new Block[kBlocksPerGroup]));

		return &(mBlocks.back())[0];
	}


	BlockList mBlocks;
};