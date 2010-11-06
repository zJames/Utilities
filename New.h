//------------------------------------------------------------------------------
//  Copyright : (c) 2010
//  Authors :
//	  JRP	James Prettyman
//------------------------------------------------------------------------------

#pragma once
////////////////////////////////////////////////////////////////////////////////


//------------------------------------------------------------------------------
//	New
//------------------------------------------------------------------------------
template<class T>
T* New() { return new T(); }

template<class T, class A>
T* New(const A& a) { return new T(a); }

template<class T, class A, class B>
T* New(const A& a, const B& b) { return new T(a, b); }

template<class T, class A, class B, class C>
T* New(const A& a, const B& b, const C& c) { return new T(a, b, c); }

template<class T, class A, class B, class C, class D>
T* New(const A& a, const B& b, const C& c, const D& d) { return new T(a, b, c, d); }

template<class T, class A, class B, class C, class D, class E>
T* New(const A& a, const B& b, const C& c, const D& d, const E& e) { return new T(a, b, c, d, e); }
