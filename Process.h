//------------------------------------------------------------------------------
// Process.h
//------------------------------------------------------------------------------
#ifndef PROCESS_H
#define PROCESS_H

#include "Function.h"
////////////////////////////////////////////////////////////////////////////////


//------------------------------------------------------------------------------
// Forward Declarations
//------------------------------------------------------------------------------
class ProcessList;
class Process;


typedef Function<Process*()> Replacer;


//------------------------------------------------------------------------------
// Class Declarations
//------------------------------------------------------------------------------
class Process
{
public:
	enum Status
	{
		ST_NORMAL,
		ST_PAUSED,
		ST_DELETE,
		ST_REPLACE,

		ST_NUM,
	};

	Process();
	virtual ~Process();

	void pause(bool);
	void queueDelete();
	void exec();
	ProcessList* parent() const;
	Status status() const;
	void replaceProcess(Process*);
	void queueReplace(const Replacer& replacer);

protected:
	virtual void update();

private:
	friend class ProcessList;

	ProcessList*	mParent;
	Status			mStatus;
	Replacer		mReplacer;
};


class ProcessList: public Process, protected std::list<Process*>
{
public:
	virtual ~ProcessList();

	using std::list<Process*>::size;
	
	void add(Process*);
	void remove(Process*);
	void deleteAll();

protected:
	/*override*/ void update();
};



////////////////////////////////////////////////////////////////////////////////
#endif