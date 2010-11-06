#pragma once
////////////////////////////////////////////////////////////////////////////////


//------------------------------------------------------------------------------
//	Function<typename R()>
//------------------------------------------------------------------------------
template<class R>
Function<typename R()> func(typename R(*func)())
{
	return
		Function<R()>(
			boost::shared_ptr<FuncDetail::FuncBase0<R> >(
				new FuncDetail::Function0a0<R>(func)));
}


template<class R, class A, class Af>
Function<typename R()> func(typename R(*func)(typename Af), const A& a)
{
	return
		Function<R()>(
			boost::shared_ptr<FuncDetail::FuncBase0<R> >(
				new FuncDetail::Function1a0<R, typename A, typename Af>(func, a)));
}


template<class R, class A, class B, class Af, class Bf>
Function<typename R()> func(typename R(*func)(typename Af, typename Bf), const A& a, const B& b)
{
	return
		Function<R()>(
			boost::shared_ptr<FuncDetail::FuncBase0<R> >(
				new FuncDetail::Function2a0<R, typename A, typename B, typename Af, typename Bf>(func, a, b)));
}


template<class R, class A, class B, class C, class Af, class Bf, class Cf>
Function<typename R()> func(typename R(*func)(typename Af, typename Bf, typename Cf), const A& a, const B& b, const C& c)
{
	return
		Function<R()>(
			boost::shared_ptr<FuncDetail::FuncBase0<R> >(
				new FuncDetail::Function3a0<R, typename A, typename B, typename C, typename Af, typename Bf, typename Cf>(func, a, b, c)));
}


template<class R, class A, class B, class C, class D, class Af, class Bf, class Cf, class Df>
Function<typename R()> func(typename R(*func)(typename Af, typename Bf, typename Cf, typename Df), const A& a, const B& b, const C& c, const D& d)
{
	return
		Function<R()>(
			boost::shared_ptr<FuncDetail::FuncBase0<R> >(
				new FuncDetail::Function4a0<R, typename A, typename B, typename C, typename D, typename Af, typename Bf, typename Cf, typename Df>(func, a, b, c, d)));
}


//------------------------------------------------------------------------------
//	Function<typename R(Af)>
//------------------------------------------------------------------------------
template<class R, class Af>
Function<typename R(typename Af)> func(typename R(*func)(Af))
{
	return
		Function<R(typename Af)>(
			boost::shared_ptr<FuncDetail::FuncBase1<R, typename Af> >(
				new FuncDetail::Function0a1<R, Af>(func)));
}


template<class R, class A, class Af, class Bf>
Function<typename R(typename Bf)> func(typename R(*func)(typename Af, Bf), const A& a)
{
	return
		Function<R(typename Bf)>(
			boost::shared_ptr<FuncDetail::FuncBase1<R, typename Bf> >(
				new FuncDetail::Function1a1<R, typename A, typename Af, Bf>(func, a)));
}


template<class R, class A, class B, class Af, class Bf, class Cf>
Function<typename R(typename Cf)> func(typename R(*func)(typename Af, typename Bf, Cf), const A& a, const B& b)
{
	return
		Function<R(typename Cf)>(
			boost::shared_ptr<FuncDetail::FuncBase1<R, typename Cf> >(
				new FuncDetail::Function2a1<R, typename A, typename B, typename Af, typename Bf, Cf>(func, a, b)));
}


template<class R, class A, class B, class C, class Af, class Bf, class Cf, class Df>
Function<typename R(typename Df)> func(typename R(*func)(typename Af, typename Bf, typename Cf, Df), const A& a, const B& b, const C& c)
{
	return
		Function<R(typename Df)>(
			boost::shared_ptr<FuncDetail::FuncBase1<R, typename Df> >(
				new FuncDetail::Function3a1<R, typename A, typename B, typename C, typename Af, typename Bf, typename Cf, Df>(func, a, b, c)));
}


template<class R, class A, class B, class C, class D, class Af, class Bf, class Cf, class Df, class Ef>
Function<typename R(typename Ef)> func(typename R(*func)(typename Af, typename Bf, typename Cf, typename Df, Ef), const A& a, const B& b, const C& c, const D& d)
{
	return
		Function<R(typename Ef)>(
			boost::shared_ptr<FuncDetail::FuncBase1<R, typename Ef> >(
				new FuncDetail::Function4a1<R, typename A, typename B, typename C, typename D, typename Af, typename Bf, typename Cf, typename Df, Ef>(func, a, b, c, d)));
}


//------------------------------------------------------------------------------
//	Function<typename R(Af, Bf)>
//------------------------------------------------------------------------------
template<class R, class Af, class Bf>
Function<typename R(typename Af, typename Bf)> func(typename R(*func)(Af, Bf))
{
	return
		Function<R(typename Af, typename Bf)>(
			boost::shared_ptr<FuncDetail::FuncBase2<R, typename Af, typename Bf> >(
				new FuncDetail::Function0a2<R, Af, Bf>(func)));
}


template<class R, class A, class Af, class Bf, class Cf>
Function<typename R(typename Bf, typename Cf)> func(typename R(*func)(typename Af, Bf, Cf), const A& a)
{
	return
		Function<R(typename Bf, typename Cf)>(
			boost::shared_ptr<FuncDetail::FuncBase2<R, typename Bf, typename Cf> >(
				new FuncDetail::Function1a2<R, typename A, typename Af, Bf, Cf>(func, a)));
}


template<class R, class A, class B, class Af, class Bf, class Cf, class Df>
Function<typename R(typename Cf, typename Df)> func(typename R(*func)(typename Af, typename Bf, Cf, Df), const A& a, const B& b)
{
	return
		Function<R(typename Cf, typename Df)>(
			boost::shared_ptr<FuncDetail::FuncBase2<R, typename Cf, typename Df> >(
				new FuncDetail::Function2a2<R, typename A, typename B, typename Af, typename Bf, Cf, Df>(func, a, b)));
}


template<class R, class A, class B, class C, class Af, class Bf, class Cf, class Df, class Ef>
Function<typename R(typename Df, typename Ef)> func(typename R(*func)(typename Af, typename Bf, typename Cf, Df, Ef), const A& a, const B& b, const C& c)
{
	return
		Function<R(typename Df, typename Ef)>(
			boost::shared_ptr<FuncDetail::FuncBase2<R, typename Df, typename Ef> >(
				new FuncDetail::Function3a2<R, typename A, typename B, typename C, typename Af, typename Bf, typename Cf, Df, Ef>(func, a, b, c)));
}


template<class R, class A, class B, class C, class D, class Af, class Bf, class Cf, class Df, class Ef, class Ff>
Function<typename R(typename Ef, typename Ff)> func(typename R(*func)(typename Af, typename Bf, typename Cf, typename Df, Ef, Ff), const A& a, const B& b, const C& c, const D& d)
{
	return
		Function<R(typename Ef, typename Ff)>(
			boost::shared_ptr<FuncDetail::FuncBase2<R, typename Ef, typename Ff> >(
				new FuncDetail::Function4a2<R, typename A, typename B, typename C, typename D, typename Af, typename Bf, typename Cf, typename Df, Ef, Ff>(func, a, b, c, d)));
}


//------------------------------------------------------------------------------
//	Function<typename R(Af, Bf, Cf)>
//------------------------------------------------------------------------------
template<class R, class Af, class Bf, class Cf>
Function<typename R(typename Af, typename Bf, typename Cf)> func(typename R(*func)(Af, Bf, Cf))
{
	return
		Function<R(typename Af, typename Bf, typename Cf)>(
			boost::shared_ptr<FuncDetail::FuncBase3<R, typename Af, typename Bf, typename Cf> >(
				new FuncDetail::Function0a3<R, Af, Bf, Cf>(func)));
}


template<class R, class A, class Af, class Bf, class Cf, class Df>
Function<typename R(typename Bf, typename Cf, typename Df)> func(typename R(*func)(typename Af, Bf, Cf, Df), const A& a)
{
	return
		Function<R(typename Bf, typename Cf, typename Df)>(
			boost::shared_ptr<FuncDetail::FuncBase3<R, typename Bf, typename Cf, typename Df> >(
				new FuncDetail::Function1a3<R, typename A, typename Af, Bf, Cf, Df>(func, a)));
}


template<class R, class A, class B, class Af, class Bf, class Cf, class Df, class Ef>
Function<typename R(typename Cf, typename Df, typename Ef)> func(typename R(*func)(typename Af, typename Bf, Cf, Df, Ef), const A& a, const B& b)
{
	return
		Function<R(typename Cf, typename Df, typename Ef)>(
			boost::shared_ptr<FuncDetail::FuncBase3<R, typename Cf, typename Df, typename Ef> >(
				new FuncDetail::Function2a3<R, typename A, typename B, typename Af, typename Bf, Cf, Df, Ef>(func, a, b)));
}


template<class R, class A, class B, class C, class Af, class Bf, class Cf, class Df, class Ef, class Ff>
Function<typename R(typename Df, typename Ef, typename Ff)> func(typename R(*func)(typename Af, typename Bf, typename Cf, Df, Ef, Ff), const A& a, const B& b, const C& c)
{
	return
		Function<R(typename Df, typename Ef, typename Ff)>(
			boost::shared_ptr<FuncDetail::FuncBase3<R, typename Df, typename Ef, typename Ff> >(
				new FuncDetail::Function3a3<R, typename A, typename B, typename C, typename Af, typename Bf, typename Cf, Df, Ef, Ff>(func, a, b, c)));
}


template<class R, class A, class B, class C, class D, class Af, class Bf, class Cf, class Df, class Ef, class Ff, class Gf>
Function<typename R(typename Ef, typename Ff, typename Gf)> func(typename R(*func)(typename Af, typename Bf, typename Cf, typename Df, Ef, Ff, Gf), const A& a, const B& b, const C& c, const D& d)
{
	return
		Function<R(typename Ef, typename Ff, typename Gf)>(
			boost::shared_ptr<FuncDetail::FuncBase3<R, typename Ef, typename Ff, typename Gf> >(
				new FuncDetail::Function4a3<R, typename A, typename B, typename C, typename D, typename Af, typename Bf, typename Cf, typename Df, Ef, Ff, Gf>(func, a, b, c, d)));
}


//------------------------------------------------------------------------------
//	Function<typename R(Af, Bf, Cf, Df)>
//------------------------------------------------------------------------------
template<class R, class Af, class Bf, class Cf, class Df>
Function<typename R(typename Af, typename Bf, typename Cf, typename Df)> func(typename R(*func)(Af, Bf, Cf, Df))
{
	return
		Function<R(typename Af, typename Bf, typename Cf, typename Df)>(
			boost::shared_ptr<FuncDetail::FuncBase4<R, typename Af, typename Bf, typename Cf, typename Df> >(
				new FuncDetail::Function0a4<R, Af, Bf, Cf, Df>(func)));
}


template<class R, class A, class Af, class Bf, class Cf, class Df, class Ef>
Function<typename R(typename Bf, typename Cf, typename Df, typename Ef)> func(typename R(*func)(typename Af, Bf, Cf, Df, Ef), const A& a)
{
	return
		Function<R(typename Bf, typename Cf, typename Df, typename Ef)>(
			boost::shared_ptr<FuncDetail::FuncBase4<R, typename Bf, typename Cf, typename Df, typename Ef> >(
				new FuncDetail::Function1a4<R, typename A, typename Af, Bf, Cf, Df, Ef>(func, a)));
}


template<class R, class A, class B, class Af, class Bf, class Cf, class Df, class Ef, class Ff>
Function<typename R(typename Cf, typename Df, typename Ef, typename Ff)> func(typename R(*func)(typename Af, typename Bf, Cf, Df, Ef, Ff), const A& a, const B& b)
{
	return
		Function<R(typename Cf, typename Df, typename Ef, typename Ff)>(
			boost::shared_ptr<FuncDetail::FuncBase4<R, typename Cf, typename Df, typename Ef, typename Ff> >(
				new FuncDetail::Function2a4<R, typename A, typename B, typename Af, typename Bf, Cf, Df, Ef, Ff>(func, a, b)));
}


template<class R, class A, class B, class C, class Af, class Bf, class Cf, class Df, class Ef, class Ff, class Gf>
Function<typename R(typename Df, typename Ef, typename Ff, typename Gf)> func(typename R(*func)(typename Af, typename Bf, typename Cf, Df, Ef, Ff, Gf), const A& a, const B& b, const C& c)
{
	return
		Function<R(typename Df, typename Ef, typename Ff, typename Gf)>(
			boost::shared_ptr<FuncDetail::FuncBase4<R, typename Df, typename Ef, typename Ff, typename Gf> >(
				new FuncDetail::Function3a4<R, typename A, typename B, typename C, typename Af, typename Bf, typename Cf, Df, Ef, Ff, Gf>(func, a, b, c)));
}


template<class R, class A, class B, class C, class D, class Af, class Bf, class Cf, class Df, class Ef, class Ff, class Gf, class Hf>
Function<typename R(typename Ef, typename Ff, typename Gf, typename Hf)> func(typename R(*func)(typename Af, typename Bf, typename Cf, typename Df, Ef, Ff, Gf, Hf), const A& a, const B& b, const C& c, const D& d)
{
	return
		Function<R(typename Ef, typename Ff, typename Gf, typename Hf)>(
			boost::shared_ptr<FuncDetail::FuncBase4<R, typename Ef, typename Ff, typename Gf, typename Hf> >(
				new FuncDetail::Function4a4<R, typename A, typename B, typename C, typename D, typename Af, typename Bf, typename Cf, typename Df, Ef, Ff, Gf, Hf>(func, a, b, c, d)));
}


//------------------------------------------------------------------------------
//	Function<typename R(Af, Bf, Cf, Df, Ef)>
//------------------------------------------------------------------------------
template<class R, class Af, class Bf, class Cf, class Df, class Ef>
Function<typename R(typename Af, typename Bf, typename Cf, typename Df, typename Ef)> func(typename R(*func)(Af, Bf, Cf, Df, Ef))
{
	return
		Function<R(typename Af, typename Bf, typename Cf, typename Df, typename Ef)>(
			boost::shared_ptr<FuncDetail::FuncBase5<R, typename Af, typename Bf, typename Cf, typename Df, typename Ef> >(
				new FuncDetail::Function0a5<R, Af, Bf, Cf, Df, Ef>(func)));
}


template<class R, class A, class Af, class Bf, class Cf, class Df, class Ef, class Ff>
Function<typename R(typename Bf, typename Cf, typename Df, typename Ef, typename Ff)> func(typename R(*func)(typename Af, Bf, Cf, Df, Ef, Ff), const A& a)
{
	return
		Function<R(typename Bf, typename Cf, typename Df, typename Ef, typename Ff)>(
			boost::shared_ptr<FuncDetail::FuncBase5<R, typename Bf, typename Cf, typename Df, typename Ef, typename Ff> >(
				new FuncDetail::Function1a5<R, typename A, typename Af, Bf, Cf, Df, Ef, Ff>(func, a)));
}


template<class R, class A, class B, class Af, class Bf, class Cf, class Df, class Ef, class Ff, class Gf>
Function<typename R(typename Cf, typename Df, typename Ef, typename Ff, typename Gf)> func(typename R(*func)(typename Af, typename Bf, Cf, Df, Ef, Ff, Gf), const A& a, const B& b)
{
	return
		Function<R(typename Cf, typename Df, typename Ef, typename Ff, typename Gf)>(
			boost::shared_ptr<FuncDetail::FuncBase5<R, typename Cf, typename Df, typename Ef, typename Ff, typename Gf> >(
				new FuncDetail::Function2a5<R, typename A, typename B, typename Af, typename Bf, Cf, Df, Ef, Ff, Gf>(func, a, b)));
}


template<class R, class A, class B, class C, class Af, class Bf, class Cf, class Df, class Ef, class Ff, class Gf, class Hf>
Function<typename R(typename Df, typename Ef, typename Ff, typename Gf, typename Hf)> func(typename R(*func)(typename Af, typename Bf, typename Cf, Df, Ef, Ff, Gf, Hf), const A& a, const B& b, const C& c)
{
	return
		Function<R(typename Df, typename Ef, typename Ff, typename Gf, typename Hf)>(
			boost::shared_ptr<FuncDetail::FuncBase5<R, typename Df, typename Ef, typename Ff, typename Gf, typename Hf> >(
				new FuncDetail::Function3a5<R, typename A, typename B, typename C, typename Af, typename Bf, typename Cf, Df, Ef, Ff, Gf, Hf>(func, a, b, c)));
}


template<class R, class A, class B, class C, class D, class Af, class Bf, class Cf, class Df, class Ef, class Ff, class Gf, class Hf, class If>
Function<typename R(typename Ef, typename Ff, typename Gf, typename Hf, typename If)> func(typename R(*func)(typename Af, typename Bf, typename Cf, typename Df, Ef, Ff, Gf, Hf, If), const A& a, const B& b, const C& c, const D& d)
{
	return
		Function<R(typename Ef, typename Ff, typename Gf, typename Hf, typename If)>(
			boost::shared_ptr<FuncDetail::FuncBase5<R, typename Ef, typename Ff, typename Gf, typename Hf, typename If> >(
				new FuncDetail::Function4a5<R, typename A, typename B, typename C, typename D, typename Af, typename Bf, typename Cf, typename Df, Ef, Ff, Gf, Hf, If>(func, a, b, c, d)));
}
