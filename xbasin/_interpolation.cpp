#include <pythonic/core.hpp>
#include <pythonic/python/core.hpp>
#include <pythonic/types/bool.hpp>
#include <pythonic/types/int.hpp>
#ifdef _OPENMP
#include <omp.h>
#endif
#include <pythonic/include/types/float128.hpp>
#include <pythonic/include/types/float64.hpp>
#include <pythonic/include/types/ndarray.hpp>
#include <pythonic/include/types/float32.hpp>
#include <pythonic/types/float64.hpp>
#include <pythonic/types/float32.hpp>
#include <pythonic/types/float128.hpp>
#include <pythonic/types/ndarray.hpp>
#include <pythonic/include/__builtin__/getattr.hpp>
#include <pythonic/include/__builtin__/len.hpp>
#include <pythonic/include/__builtin__/pythran/make_shape.hpp>
#include <pythonic/include/__builtin__/range.hpp>
#include <pythonic/include/__builtin__/tuple.hpp>
#include <pythonic/include/numpy/empty.hpp>
#include <pythonic/include/operator_/add.hpp>
#include <pythonic/include/operator_/div.hpp>
#include <pythonic/include/operator_/eq.hpp>
#include <pythonic/include/operator_/floordiv.hpp>
#include <pythonic/include/operator_/ge.hpp>
#include <pythonic/include/operator_/idiv.hpp>
#include <pythonic/include/operator_/ifloordiv.hpp>
#include <pythonic/include/operator_/le.hpp>
#include <pythonic/include/operator_/lt.hpp>
#include <pythonic/include/operator_/mul.hpp>
#include <pythonic/include/types/slice.hpp>
#include <pythonic/include/types/str.hpp>
#include <pythonic/__builtin__/getattr.hpp>
#include <pythonic/__builtin__/len.hpp>
#include <pythonic/__builtin__/pythran/make_shape.hpp>
#include <pythonic/__builtin__/range.hpp>
#include <pythonic/__builtin__/tuple.hpp>
#include <pythonic/numpy/empty.hpp>
#include <pythonic/operator_/add.hpp>
#include <pythonic/operator_/div.hpp>
#include <pythonic/operator_/eq.hpp>
#include <pythonic/operator_/floordiv.hpp>
#include <pythonic/operator_/ge.hpp>
#include <pythonic/operator_/idiv.hpp>
#include <pythonic/operator_/ifloordiv.hpp>
#include <pythonic/operator_/le.hpp>
#include <pythonic/operator_/lt.hpp>
#include <pythonic/operator_/mul.hpp>
#include <pythonic/types/slice.hpp>
#include <pythonic/types/str.hpp>
namespace __pythran_interpolation_compiled
{
  struct _bisect
  {
    typedef void callable;
    typedef void pure;
    template <typename argument_type0 , typename argument_type1 >
    struct type
    {
      typedef typename pythonic::assignable<long>::type __type0;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::__builtin__::functor::len{})>::type>::type __type1;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type2;
      typedef typename pythonic::assignable<decltype(std::declval<__type1>()(std::declval<__type2>()))>::type __type3;
      typedef decltype((pythonic::operator_::add(std::declval<__type0>(), std::declval<__type3>()))) __type4;
      typedef long __type5;
      typedef typename pythonic::assignable<decltype((pythonic::operator_::functor::floordiv{}(std::declval<__type4>(), std::declval<__type5>())))>::type __type6;
      typedef typename pythonic::assignable<decltype((pythonic::operator_::add(std::declval<__type6>(), std::declval<__type5>())))>::type __type7;
      typedef typename __combined<__type0,__type7>::type __type8;
      typedef typename pythonic::returnable<decltype((std::declval<__type8>() - std::declval<__type5>()))>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 >
    typename type<argument_type0, argument_type1>::result_type operator()(argument_type0&& a, argument_type1&& x) const
    ;
  }  ;
  struct interp_new_vertical
  {
    typedef void callable;
    typedef void pure;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
    struct type
    {
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::numpy::functor::empty{})>::type>::type __type0;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::__builtin__::pythran::functor::make_shape{})>::type>::type __type1;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type2;
      typedef decltype(pythonic::__builtin__::getattr(pythonic::types::attr::SHAPE{}, std::declval<__type2>())) __type3;
      typedef typename std::tuple_element<0,typename std::remove_reference<__type3>::type>::type __type4;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type2>::type>::type __type5;
      typedef decltype(pythonic::__builtin__::getattr(pythonic::types::attr::SHAPE{}, std::declval<__type5>())) __type6;
      typedef typename std::tuple_element<1,typename std::remove_reference<__type6>::type>::type __type7;
      typedef typename std::tuple_element<2,typename std::remove_reference<__type6>::type>::type __type8;
      typedef typename std::tuple_element<3,typename std::remove_reference<__type6>::type>::type __type9;
      typedef decltype(std::declval<__type1>()(std::declval<__type4>(), std::declval<__type7>(), std::declval<__type8>(), std::declval<__type9>())) __type10;
      typedef typename pythonic::assignable<decltype(std::declval<__type0>()(std::declval<__type10>()))>::type __type11;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::__builtin__::functor::range{})>::type>::type __type12;
      typedef decltype(std::declval<__type12>()(std::declval<__type4>())) __type13;
      typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type13>::type::iterator>::value_type>::type __type14;
      typedef decltype(std::declval<__type12>()(std::declval<__type7>())) __type15;
      typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type15>::type::iterator>::value_type>::type __type16;
      typedef decltype(std::declval<__type12>()(std::declval<__type8>())) __type17;
      typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type17>::type::iterator>::value_type>::type __type18;
      typedef decltype(std::declval<__type12>()(std::declval<__type9>())) __type19;
      typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type19>::type::iterator>::value_type>::type __type20;
      typedef decltype(pythonic::types::make_tuple(std::declval<__type14>(), std::declval<__type16>(), std::declval<__type18>(), std::declval<__type20>())) __type21;
      typedef indexable<__type21> __type22;
      typedef typename __combined<__type11,__type22>::type __type23;
      typedef long __type24;
      typedef decltype(pythonic::types::make_tuple(std::declval<__type24>(), std::declval<__type16>(), std::declval<__type18>(), std::declval<__type20>())) __type25;
      typedef decltype(std::declval<__type5>()[std::declval<__type25>()]) __type26;
      typedef container<typename std::remove_reference<__type26>::type> __type27;
      typedef typename __combined<__type23,__type27>::type __type28;
      typedef typename __combined<__type28,__type22>::type __type29;
      typedef typename __combined<__type29,__type27>::type __type30;
      typedef typename pythonic::assignable<typename std::tuple_element<0,typename std::remove_reference<__type6>::type>::type>::type __type31;
      typedef decltype((std::declval<__type31>() - std::declval<__type24>())) __type32;
      typedef decltype(pythonic::types::make_tuple(std::declval<__type32>(), std::declval<__type16>(), std::declval<__type18>(), std::declval<__type20>())) __type33;
      typedef decltype(std::declval<__type5>()[std::declval<__type33>()]) __type34;
      typedef container<typename std::remove_reference<__type34>::type> __type35;
      typedef typename __combined<__type30,__type35>::type __type36;
      typedef typename __combined<__type36,__type22>::type __type37;
      typedef typename __combined<__type37,__type35>::type __type38;
      typedef _bisect __type39;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type40;
      typedef pythonic::types::contiguous_slice __type41;
      typedef decltype(std::declval<__type40>()(std::declval<__type41>(), std::declval<__type16>(), std::declval<__type18>(), std::declval<__type20>())) __type42;
      typedef decltype(std::declval<__type2>()[std::declval<__type21>()]) __type43;
      typedef typename pythonic::assignable<decltype(std::declval<__type39>()(std::declval<__type42>(), std::declval<__type43>()))>::type __type44;
      typedef decltype(pythonic::types::make_tuple(std::declval<__type44>(), std::declval<__type16>(), std::declval<__type18>(), std::declval<__type20>())) __type45;
      typedef decltype(std::declval<__type5>()[std::declval<__type45>()]) __type46;
      typedef container<typename std::remove_reference<__type46>::type> __type47;
      typedef typename __combined<__type38,__type47>::type __type48;
      typedef typename __combined<__type48,__type22>::type __type49;
      typedef typename __combined<__type49,__type47>::type __type50;
      typedef decltype(std::declval<__type40>()[std::declval<__type45>()]) __type51;
      typedef decltype((std::declval<__type43>() - std::declval<__type51>())) __type52;
      typedef decltype((pythonic::operator_::add(std::declval<__type44>(), std::declval<__type24>()))) __type53;
      typedef decltype(pythonic::types::make_tuple(std::declval<__type53>(), std::declval<__type16>(), std::declval<__type18>(), std::declval<__type20>())) __type54;
      typedef decltype(std::declval<__type5>()[std::declval<__type54>()]) __type55;
      typedef decltype((std::declval<__type55>() - std::declval<__type46>())) __type56;
      typedef decltype((pythonic::operator_::mul(std::declval<__type52>(), std::declval<__type56>()))) __type57;
      typedef decltype(std::declval<__type40>()[std::declval<__type54>()]) __type58;
      typedef decltype((std::declval<__type58>() - std::declval<__type51>())) __type59;
      typedef decltype((pythonic::operator_::div(std::declval<__type57>(), std::declval<__type59>()))) __type60;
      typedef decltype((pythonic::operator_::add(std::declval<__type46>(), std::declval<__type60>()))) __type61;
      typedef container<typename std::remove_reference<__type61>::type> __type62;
      typedef typename __combined<__type50,__type62>::type __type63;
      typedef typename __combined<__type63,__type22>::type __type64;
      typedef typename pythonic::returnable<typename __combined<__type64,__type62>::type>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
    typename type<argument_type0, argument_type1, argument_type2>::result_type operator()(argument_type0&& z_old, argument_type1&& z_new, argument_type2&& V_old) const
    ;
  }  ;
  template <typename argument_type0 , typename argument_type1 >
  typename _bisect::type<argument_type0, argument_type1>::result_type _bisect::operator()(argument_type0&& a, argument_type1&& x) const
  {
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::__builtin__::functor::len{})>::type>::type __type0;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type1;
    typedef typename pythonic::assignable<decltype(std::declval<__type0>()(std::declval<__type1>()))>::type __type2;
    typedef typename pythonic::assignable<long>::type __type3;
    typedef decltype((pythonic::operator_::add(std::declval<__type3>(), std::declval<__type2>()))) __type4;
    typedef long __type5;
    typedef typename pythonic::assignable<typename pythonic::assignable<decltype((pythonic::operator_::functor::floordiv{}(std::declval<__type4>(), std::declval<__type5>())))>::type>::type __type6;
    typedef typename pythonic::assignable<decltype((pythonic::operator_::functor::floordiv{}(std::declval<__type4>(), std::declval<__type5>())))>::type __type7;
    typedef typename pythonic::assignable<decltype((pythonic::operator_::add(std::declval<__type7>(), std::declval<__type5>())))>::type __type8;
    typename pythonic::assignable<typename __combined<__type2,__type6>::type>::type hi = pythonic::__builtin__::functor::len{}(a);
    typename pythonic::assignable<typename __combined<__type3,__type8>::type>::type lo = 0L;
    while ((pythonic::operator_::lt(lo, hi)))
    {
      typename pythonic::assignable<decltype((pythonic::operator_::functor::floordiv{}((pythonic::operator_::add(lo, hi)), 2L)))>::type mid = (pythonic::operator_::functor::floordiv{}((pythonic::operator_::add(lo, hi)), 2L));
      if ((pythonic::operator_::lt(x, a.fast(mid))))
      {
        hi = mid;
      }
      else
      {
        lo = (pythonic::operator_::add(mid, 1L));
      }
    }
    return (lo - 1L);
  }
  template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
  typename interp_new_vertical::type<argument_type0, argument_type1, argument_type2>::result_type interp_new_vertical::operator()(argument_type0&& z_old, argument_type1&& z_new, argument_type2&& V_old) const
  {
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::numpy::functor::empty{})>::type>::type __type0;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::__builtin__::pythran::functor::make_shape{})>::type>::type __type1;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type2;
    typedef decltype(pythonic::__builtin__::getattr(pythonic::types::attr::SHAPE{}, std::declval<__type2>())) __type3;
    typedef typename std::tuple_element<0,typename std::remove_reference<__type3>::type>::type __type4;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type2>::type>::type __type5;
    typedef decltype(pythonic::__builtin__::getattr(pythonic::types::attr::SHAPE{}, std::declval<__type5>())) __type6;
    typedef typename std::tuple_element<1,typename std::remove_reference<__type6>::type>::type __type7;
    typedef typename std::tuple_element<2,typename std::remove_reference<__type6>::type>::type __type8;
    typedef typename std::tuple_element<3,typename std::remove_reference<__type6>::type>::type __type9;
    typedef decltype(std::declval<__type1>()(std::declval<__type4>(), std::declval<__type7>(), std::declval<__type8>(), std::declval<__type9>())) __type10;
    typedef typename pythonic::assignable<decltype(std::declval<__type0>()(std::declval<__type10>()))>::type __type11;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::__builtin__::functor::range{})>::type>::type __type12;
    typedef decltype(std::declval<__type12>()(std::declval<__type4>())) __type13;
    typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type13>::type::iterator>::value_type>::type __type14;
    typedef decltype(std::declval<__type12>()(std::declval<__type7>())) __type15;
    typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type15>::type::iterator>::value_type>::type __type16;
    typedef decltype(std::declval<__type12>()(std::declval<__type8>())) __type17;
    typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type17>::type::iterator>::value_type>::type __type18;
    typedef decltype(std::declval<__type12>()(std::declval<__type9>())) __type19;
    typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type19>::type::iterator>::value_type>::type __type20;
    typedef decltype(pythonic::types::make_tuple(std::declval<__type14>(), std::declval<__type16>(), std::declval<__type18>(), std::declval<__type20>())) __type21;
    typedef indexable<__type21> __type22;
    typedef typename __combined<__type11,__type22>::type __type23;
    typedef long __type24;
    typedef decltype(pythonic::types::make_tuple(std::declval<__type24>(), std::declval<__type16>(), std::declval<__type18>(), std::declval<__type20>())) __type25;
    typedef decltype(std::declval<__type5>()[std::declval<__type25>()]) __type26;
    typedef container<typename std::remove_reference<__type26>::type> __type27;
    typedef typename __combined<__type23,__type27>::type __type28;
    typedef typename __combined<__type28,__type22>::type __type29;
    typedef typename pythonic::assignable<typename std::tuple_element<0,typename std::remove_reference<__type6>::type>::type>::type __type30;
    typedef decltype((std::declval<__type30>() - std::declval<__type24>())) __type31;
    typedef decltype(pythonic::types::make_tuple(std::declval<__type31>(), std::declval<__type16>(), std::declval<__type18>(), std::declval<__type20>())) __type32;
    typedef decltype(std::declval<__type5>()[std::declval<__type32>()]) __type33;
    typedef container<typename std::remove_reference<__type33>::type> __type34;
    typedef typename __combined<__type29,__type34>::type __type35;
    typedef _bisect __type36;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type37;
    typedef pythonic::types::contiguous_slice __type38;
    typedef decltype(std::declval<__type37>()(std::declval<__type38>(), std::declval<__type16>(), std::declval<__type18>(), std::declval<__type20>())) __type39;
    typedef decltype(std::declval<__type2>()[std::declval<__type21>()]) __type40;
    typedef typename pythonic::assignable<decltype(std::declval<__type36>()(std::declval<__type39>(), std::declval<__type40>()))>::type __type41;
    typedef decltype(pythonic::types::make_tuple(std::declval<__type41>(), std::declval<__type16>(), std::declval<__type18>(), std::declval<__type20>())) __type42;
    typedef decltype(std::declval<__type5>()[std::declval<__type42>()]) __type43;
    typedef container<typename std::remove_reference<__type43>::type> __type44;
    typedef typename __combined<__type35,__type44>::type __type45;
    typedef decltype(std::declval<__type37>()[std::declval<__type42>()]) __type46;
    typedef decltype((std::declval<__type40>() - std::declval<__type46>())) __type47;
    typedef decltype((pythonic::operator_::add(std::declval<__type41>(), std::declval<__type24>()))) __type48;
    typedef decltype(pythonic::types::make_tuple(std::declval<__type48>(), std::declval<__type16>(), std::declval<__type18>(), std::declval<__type20>())) __type49;
    typedef decltype(std::declval<__type5>()[std::declval<__type49>()]) __type50;
    typedef decltype((std::declval<__type50>() - std::declval<__type43>())) __type51;
    typedef decltype((pythonic::operator_::mul(std::declval<__type47>(), std::declval<__type51>()))) __type52;
    typedef decltype(std::declval<__type37>()[std::declval<__type49>()]) __type53;
    typedef decltype((std::declval<__type53>() - std::declval<__type46>())) __type54;
    typedef decltype((pythonic::operator_::div(std::declval<__type52>(), std::declval<__type54>()))) __type55;
    typedef decltype((pythonic::operator_::add(std::declval<__type43>(), std::declval<__type55>()))) __type56;
    typedef container<typename std::remove_reference<__type56>::type> __type57;
    typename pythonic::assignable<typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type17>::type::iterator>::value_type>::type>::type ji;
    typename pythonic::assignable<typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type13>::type::iterator>::value_type>::type>::type jk;
    typename pythonic::assignable<typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type15>::type::iterator>::value_type>::type>::type jj;
    typename pythonic::assignable<typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type19>::type::iterator>::value_type>::type>::type jt;
    typename pythonic::assignable<decltype(std::get<0>(pythonic::__builtin__::getattr(pythonic::types::attr::SHAPE{}, V_old)))>::type jpk_old = std::get<0>(pythonic::__builtin__::getattr(pythonic::types::attr::SHAPE{}, V_old));
    typename pythonic::assignable<typename __combined<__type45,__type57>::type>::type V_new = pythonic::numpy::functor::empty{}(pythonic::__builtin__::pythran::functor::make_shape{}(std::get<0>(pythonic::__builtin__::getattr(pythonic::types::attr::SHAPE{}, z_new)), std::get<1>(pythonic::__builtin__::getattr(pythonic::types::attr::SHAPE{}, V_old)), std::get<2>(pythonic::__builtin__::getattr(pythonic::types::attr::SHAPE{}, V_old)), std::get<3>(pythonic::__builtin__::getattr(pythonic::types::attr::SHAPE{}, V_old))));
    {
      #pragma omp parallel for collapse(4)
      for (long  jk=0L; jk < std::get<0>(pythonic::__builtin__::getattr(pythonic::types::attr::SHAPE{}, z_new)); jk += 1L)
      {
        {
          for (long  jj=0L; jj < std::get<1>(pythonic::__builtin__::getattr(pythonic::types::attr::SHAPE{}, V_old)); jj += 1L)
          {
            {
              for (long  ji=0L; ji < std::get<2>(pythonic::__builtin__::getattr(pythonic::types::attr::SHAPE{}, V_old)); ji += 1L)
              {
                {
                  for (long  jt=0L; jt < std::get<3>(pythonic::__builtin__::getattr(pythonic::types::attr::SHAPE{}, V_old)); jt += 1L)
                  {
                    if ((pythonic::operator_::le(z_new.fast(pythonic::types::make_tuple(jk, jj, ji, jt)), z_old.fast(pythonic::types::make_tuple(0L, jj, ji, jt)))))
                    {
                      V_new.fast(pythonic::types::make_tuple(jk, jj, ji, jt)) = V_old.fast(pythonic::types::make_tuple(0L, jj, ji, jt));
                    }
                    else
                    {
                      {
                        typename pythonic::assignable<typename pythonic::assignable<decltype(std::declval<__type36>()(std::declval<__type39>(), std::declval<__type40>()))>::type>::type ind;
                        if ((pythonic::operator_::ge(z_new.fast(pythonic::types::make_tuple(jk, jj, ji, jt)), z_old[pythonic::types::make_tuple((jpk_old - 1L), jj, ji, jt)])))
                        {
                          V_new.fast(pythonic::types::make_tuple(jk, jj, ji, jt)) = V_old[pythonic::types::make_tuple((jpk_old - 1L), jj, ji, jt)];
                        }
                        else
                        {
                          ind = _bisect()(z_old(pythonic::types::contiguous_slice(pythonic::__builtin__::None,pythonic::__builtin__::None),jj,ji,jt), z_new.fast(pythonic::types::make_tuple(jk, jj, ji, jt)));
                          if ((pythonic::operator_::eq(z_new.fast(pythonic::types::make_tuple(jk, jj, ji, jt)), z_old[pythonic::types::make_tuple(ind, jj, ji, jt)])))
                          {
                            V_new.fast(pythonic::types::make_tuple(jk, jj, ji, jt)) = V_old[pythonic::types::make_tuple(ind, jj, ji, jt)];
                          }
                          else
                          {
                            V_new.fast(pythonic::types::make_tuple(jk, jj, ji, jt)) = (pythonic::operator_::add(V_old[pythonic::types::make_tuple(ind, jj, ji, jt)], (pythonic::operator_::div((pythonic::operator_::mul((z_new.fast(pythonic::types::make_tuple(jk, jj, ji, jt)) - z_old[pythonic::types::make_tuple(ind, jj, ji, jt)]), (V_old[pythonic::types::make_tuple((pythonic::operator_::add(ind, 1L)), jj, ji, jt)] - V_old[pythonic::types::make_tuple(ind, jj, ji, jt)]))), (z_old[pythonic::types::make_tuple((pythonic::operator_::add(ind, 1L)), jj, ji, jt)] - z_old[pythonic::types::make_tuple(ind, jj, ji, jt)])))));
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    return V_new;
  }
}
#include <pythonic/python/exception_handler.hpp>
#ifdef ENABLE_PYTHON_MODULE
typename __pythran_interpolation_compiled::interp_new_vertical::type<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>::result_type interp_new_vertical0(pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>&& z_old, pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>&& z_new, pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>&& V_old) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_interpolation_compiled::interp_new_vertical()(z_old, z_new, V_old);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_interpolation_compiled::interp_new_vertical::type<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>::result_type interp_new_vertical1(pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>&& z_old, pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>&& z_new, pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>&& V_old) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_interpolation_compiled::interp_new_vertical()(z_old, z_new, V_old);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_interpolation_compiled::interp_new_vertical::type<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>::result_type interp_new_vertical2(pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>&& z_old, pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>&& z_new, pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>&& V_old) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_interpolation_compiled::interp_new_vertical()(z_old, z_new, V_old);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_interpolation_compiled::interp_new_vertical::type<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>::result_type interp_new_vertical3(pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>&& z_old, pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>&& z_new, pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>&& V_old) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_interpolation_compiled::interp_new_vertical()(z_old, z_new, V_old);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_interpolation_compiled::interp_new_vertical::type<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>::result_type interp_new_vertical4(pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>&& z_old, pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>&& z_new, pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>&& V_old) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_interpolation_compiled::interp_new_vertical()(z_old, z_new, V_old);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_interpolation_compiled::interp_new_vertical::type<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>::result_type interp_new_vertical5(pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>&& z_old, pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>&& z_new, pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>&& V_old) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_interpolation_compiled::interp_new_vertical()(z_old, z_new, V_old);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_interpolation_compiled::interp_new_vertical::type<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>::result_type interp_new_vertical6(pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>&& z_old, pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>&& z_new, pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>&& V_old) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_interpolation_compiled::interp_new_vertical()(z_old, z_new, V_old);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_interpolation_compiled::interp_new_vertical::type<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>::result_type interp_new_vertical7(pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>&& z_old, pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>&& z_new, pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>&& V_old) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_interpolation_compiled::interp_new_vertical()(z_old, z_new, V_old);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_interpolation_compiled::interp_new_vertical::type<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>::result_type interp_new_vertical8(pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>&& z_old, pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>&& z_new, pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>&& V_old) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_interpolation_compiled::interp_new_vertical()(z_old, z_new, V_old);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_interpolation_compiled::interp_new_vertical::type<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>::result_type interp_new_vertical9(pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>&& z_old, pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>&& z_new, pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>&& V_old) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_interpolation_compiled::interp_new_vertical()(z_old, z_new, V_old);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_interpolation_compiled::interp_new_vertical::type<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>::result_type interp_new_vertical10(pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>&& z_old, pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>&& z_new, pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>&& V_old) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_interpolation_compiled::interp_new_vertical()(z_old, z_new, V_old);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_interpolation_compiled::interp_new_vertical::type<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>::result_type interp_new_vertical11(pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>&& z_old, pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>&& z_new, pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>&& V_old) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_interpolation_compiled::interp_new_vertical()(z_old, z_new, V_old);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_interpolation_compiled::interp_new_vertical::type<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>::result_type interp_new_vertical12(pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>&& z_old, pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>&& z_new, pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>&& V_old) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_interpolation_compiled::interp_new_vertical()(z_old, z_new, V_old);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_interpolation_compiled::interp_new_vertical::type<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>::result_type interp_new_vertical13(pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>&& z_old, pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>&& z_new, pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>&& V_old) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_interpolation_compiled::interp_new_vertical()(z_old, z_new, V_old);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_interpolation_compiled::interp_new_vertical::type<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>::result_type interp_new_vertical14(pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>&& z_old, pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>&& z_new, pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>&& V_old) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_interpolation_compiled::interp_new_vertical()(z_old, z_new, V_old);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_interpolation_compiled::interp_new_vertical::type<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>::result_type interp_new_vertical15(pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>&& z_old, pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>&& z_new, pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>&& V_old) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_interpolation_compiled::interp_new_vertical()(z_old, z_new, V_old);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_interpolation_compiled::interp_new_vertical::type<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>::result_type interp_new_vertical16(pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>&& z_old, pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>&& z_new, pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>&& V_old) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_interpolation_compiled::interp_new_vertical()(z_old, z_new, V_old);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_interpolation_compiled::interp_new_vertical::type<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>::result_type interp_new_vertical17(pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>&& z_old, pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>&& z_new, pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>&& V_old) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_interpolation_compiled::interp_new_vertical()(z_old, z_new, V_old);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_interpolation_compiled::interp_new_vertical::type<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>::result_type interp_new_vertical18(pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>&& z_old, pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>&& z_new, pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>&& V_old) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_interpolation_compiled::interp_new_vertical()(z_old, z_new, V_old);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_interpolation_compiled::interp_new_vertical::type<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>::result_type interp_new_vertical19(pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>&& z_old, pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>&& z_new, pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>&& V_old) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_interpolation_compiled::interp_new_vertical()(z_old, z_new, V_old);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_interpolation_compiled::interp_new_vertical::type<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>::result_type interp_new_vertical20(pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>&& z_old, pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>&& z_new, pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>&& V_old) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_interpolation_compiled::interp_new_vertical()(z_old, z_new, V_old);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_interpolation_compiled::interp_new_vertical::type<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>::result_type interp_new_vertical21(pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>&& z_old, pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>&& z_new, pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>&& V_old) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_interpolation_compiled::interp_new_vertical()(z_old, z_new, V_old);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_interpolation_compiled::interp_new_vertical::type<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>::result_type interp_new_vertical22(pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>&& z_old, pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>&& z_new, pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>&& V_old) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_interpolation_compiled::interp_new_vertical()(z_old, z_new, V_old);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_interpolation_compiled::interp_new_vertical::type<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>::result_type interp_new_vertical23(pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>&& z_old, pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>&& z_new, pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>&& V_old) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_interpolation_compiled::interp_new_vertical()(z_old, z_new, V_old);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_interpolation_compiled::interp_new_vertical::type<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>::result_type interp_new_vertical24(pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>&& z_old, pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>&& z_new, pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>&& V_old) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_interpolation_compiled::interp_new_vertical()(z_old, z_new, V_old);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_interpolation_compiled::interp_new_vertical::type<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>::result_type interp_new_vertical25(pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>&& z_old, pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>&& z_new, pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>&& V_old) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_interpolation_compiled::interp_new_vertical()(z_old, z_new, V_old);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_interpolation_compiled::interp_new_vertical::type<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>, pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>::result_type interp_new_vertical26(pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>&& z_old, pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>&& z_new, pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>&& V_old) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_interpolation_compiled::interp_new_vertical()(z_old, z_new, V_old);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}

static PyObject *
__pythran_wrap_interp_new_vertical0(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[3+1];
    char const* keywords[] = {"z_old", "z_new", "V_old",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2]))
        return nullptr;
    if(is_convertible<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]) && is_convertible<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]) && is_convertible<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[2]))
        return to_python(interp_new_vertical0(from_python<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]), from_python<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]), from_python<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[2])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_interp_new_vertical1(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[3+1];
    char const* keywords[] = {"z_old", "z_new", "V_old",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2]))
        return nullptr;
    if(is_convertible<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]) && is_convertible<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]) && is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[2]))
        return to_python(interp_new_vertical1(from_python<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]), from_python<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]), from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[2])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_interp_new_vertical2(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[3+1];
    char const* keywords[] = {"z_old", "z_new", "V_old",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2]))
        return nullptr;
    if(is_convertible<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]) && is_convertible<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]) && is_convertible<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[2]))
        return to_python(interp_new_vertical2(from_python<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]), from_python<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]), from_python<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[2])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_interp_new_vertical3(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[3+1];
    char const* keywords[] = {"z_old", "z_new", "V_old",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2]))
        return nullptr;
    if(is_convertible<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]) && is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]) && is_convertible<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[2]))
        return to_python(interp_new_vertical3(from_python<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]), from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]), from_python<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[2])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_interp_new_vertical4(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[3+1];
    char const* keywords[] = {"z_old", "z_new", "V_old",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2]))
        return nullptr;
    if(is_convertible<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]) && is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]) && is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[2]))
        return to_python(interp_new_vertical4(from_python<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]), from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]), from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[2])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_interp_new_vertical5(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[3+1];
    char const* keywords[] = {"z_old", "z_new", "V_old",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2]))
        return nullptr;
    if(is_convertible<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]) && is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]) && is_convertible<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[2]))
        return to_python(interp_new_vertical5(from_python<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]), from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]), from_python<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[2])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_interp_new_vertical6(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[3+1];
    char const* keywords[] = {"z_old", "z_new", "V_old",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2]))
        return nullptr;
    if(is_convertible<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]) && is_convertible<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]) && is_convertible<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[2]))
        return to_python(interp_new_vertical6(from_python<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]), from_python<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]), from_python<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[2])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_interp_new_vertical7(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[3+1];
    char const* keywords[] = {"z_old", "z_new", "V_old",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2]))
        return nullptr;
    if(is_convertible<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]) && is_convertible<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]) && is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[2]))
        return to_python(interp_new_vertical7(from_python<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]), from_python<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]), from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[2])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_interp_new_vertical8(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[3+1];
    char const* keywords[] = {"z_old", "z_new", "V_old",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2]))
        return nullptr;
    if(is_convertible<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]) && is_convertible<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]) && is_convertible<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[2]))
        return to_python(interp_new_vertical8(from_python<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]), from_python<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]), from_python<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[2])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_interp_new_vertical9(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[3+1];
    char const* keywords[] = {"z_old", "z_new", "V_old",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2]))
        return nullptr;
    if(is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]) && is_convertible<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]) && is_convertible<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[2]))
        return to_python(interp_new_vertical9(from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]), from_python<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]), from_python<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[2])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_interp_new_vertical10(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[3+1];
    char const* keywords[] = {"z_old", "z_new", "V_old",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2]))
        return nullptr;
    if(is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]) && is_convertible<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]) && is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[2]))
        return to_python(interp_new_vertical10(from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]), from_python<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]), from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[2])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_interp_new_vertical11(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[3+1];
    char const* keywords[] = {"z_old", "z_new", "V_old",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2]))
        return nullptr;
    if(is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]) && is_convertible<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]) && is_convertible<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[2]))
        return to_python(interp_new_vertical11(from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]), from_python<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]), from_python<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[2])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_interp_new_vertical12(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[3+1];
    char const* keywords[] = {"z_old", "z_new", "V_old",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2]))
        return nullptr;
    if(is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]) && is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]) && is_convertible<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[2]))
        return to_python(interp_new_vertical12(from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]), from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]), from_python<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[2])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_interp_new_vertical13(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[3+1];
    char const* keywords[] = {"z_old", "z_new", "V_old",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2]))
        return nullptr;
    if(is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]) && is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]) && is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[2]))
        return to_python(interp_new_vertical13(from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]), from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]), from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[2])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_interp_new_vertical14(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[3+1];
    char const* keywords[] = {"z_old", "z_new", "V_old",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2]))
        return nullptr;
    if(is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]) && is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]) && is_convertible<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[2]))
        return to_python(interp_new_vertical14(from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]), from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]), from_python<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[2])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_interp_new_vertical15(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[3+1];
    char const* keywords[] = {"z_old", "z_new", "V_old",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2]))
        return nullptr;
    if(is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]) && is_convertible<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]) && is_convertible<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[2]))
        return to_python(interp_new_vertical15(from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]), from_python<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]), from_python<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[2])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_interp_new_vertical16(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[3+1];
    char const* keywords[] = {"z_old", "z_new", "V_old",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2]))
        return nullptr;
    if(is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]) && is_convertible<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]) && is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[2]))
        return to_python(interp_new_vertical16(from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]), from_python<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]), from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[2])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_interp_new_vertical17(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[3+1];
    char const* keywords[] = {"z_old", "z_new", "V_old",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2]))
        return nullptr;
    if(is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]) && is_convertible<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]) && is_convertible<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[2]))
        return to_python(interp_new_vertical17(from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]), from_python<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]), from_python<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[2])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_interp_new_vertical18(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[3+1];
    char const* keywords[] = {"z_old", "z_new", "V_old",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2]))
        return nullptr;
    if(is_convertible<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]) && is_convertible<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]) && is_convertible<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[2]))
        return to_python(interp_new_vertical18(from_python<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]), from_python<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]), from_python<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[2])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_interp_new_vertical19(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[3+1];
    char const* keywords[] = {"z_old", "z_new", "V_old",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2]))
        return nullptr;
    if(is_convertible<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]) && is_convertible<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]) && is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[2]))
        return to_python(interp_new_vertical19(from_python<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]), from_python<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]), from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[2])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_interp_new_vertical20(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[3+1];
    char const* keywords[] = {"z_old", "z_new", "V_old",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2]))
        return nullptr;
    if(is_convertible<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]) && is_convertible<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]) && is_convertible<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[2]))
        return to_python(interp_new_vertical20(from_python<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]), from_python<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]), from_python<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[2])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_interp_new_vertical21(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[3+1];
    char const* keywords[] = {"z_old", "z_new", "V_old",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2]))
        return nullptr;
    if(is_convertible<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]) && is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]) && is_convertible<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[2]))
        return to_python(interp_new_vertical21(from_python<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]), from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]), from_python<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[2])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_interp_new_vertical22(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[3+1];
    char const* keywords[] = {"z_old", "z_new", "V_old",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2]))
        return nullptr;
    if(is_convertible<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]) && is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]) && is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[2]))
        return to_python(interp_new_vertical22(from_python<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]), from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]), from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[2])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_interp_new_vertical23(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[3+1];
    char const* keywords[] = {"z_old", "z_new", "V_old",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2]))
        return nullptr;
    if(is_convertible<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]) && is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]) && is_convertible<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[2]))
        return to_python(interp_new_vertical23(from_python<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]), from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]), from_python<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[2])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_interp_new_vertical24(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[3+1];
    char const* keywords[] = {"z_old", "z_new", "V_old",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2]))
        return nullptr;
    if(is_convertible<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]) && is_convertible<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]) && is_convertible<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[2]))
        return to_python(interp_new_vertical24(from_python<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]), from_python<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]), from_python<pythonic::types::ndarray<float,pythonic::types::pshape<long,long,long,long>>>(args_obj[2])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_interp_new_vertical25(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[3+1];
    char const* keywords[] = {"z_old", "z_new", "V_old",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2]))
        return nullptr;
    if(is_convertible<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]) && is_convertible<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]) && is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[2]))
        return to_python(interp_new_vertical25(from_python<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]), from_python<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]), from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long,long,long,long>>>(args_obj[2])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_interp_new_vertical26(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[3+1];
    char const* keywords[] = {"z_old", "z_new", "V_old",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2]))
        return nullptr;
    if(is_convertible<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]) && is_convertible<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]) && is_convertible<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[2]))
        return to_python(interp_new_vertical26(from_python<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[0]), from_python<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[1]), from_python<pythonic::types::ndarray<long double,pythonic::types::pshape<long,long,long,long>>>(args_obj[2])));
    else {
        return nullptr;
    }
}

            static PyObject *
            __pythran_wrapall_interp_new_vertical(PyObject *self, PyObject *args, PyObject *kw)
            {
                return pythonic::handle_python_exception([self, args, kw]()
                -> PyObject* {

if(PyObject* obj = __pythran_wrap_interp_new_vertical0(self, args, kw))
    return obj;
PyErr_Clear();


if(PyObject* obj = __pythran_wrap_interp_new_vertical1(self, args, kw))
    return obj;
PyErr_Clear();


if(PyObject* obj = __pythran_wrap_interp_new_vertical2(self, args, kw))
    return obj;
PyErr_Clear();


if(PyObject* obj = __pythran_wrap_interp_new_vertical3(self, args, kw))
    return obj;
PyErr_Clear();


if(PyObject* obj = __pythran_wrap_interp_new_vertical4(self, args, kw))
    return obj;
PyErr_Clear();


if(PyObject* obj = __pythran_wrap_interp_new_vertical5(self, args, kw))
    return obj;
PyErr_Clear();


if(PyObject* obj = __pythran_wrap_interp_new_vertical6(self, args, kw))
    return obj;
PyErr_Clear();


if(PyObject* obj = __pythran_wrap_interp_new_vertical7(self, args, kw))
    return obj;
PyErr_Clear();


if(PyObject* obj = __pythran_wrap_interp_new_vertical8(self, args, kw))
    return obj;
PyErr_Clear();


if(PyObject* obj = __pythran_wrap_interp_new_vertical9(self, args, kw))
    return obj;
PyErr_Clear();


if(PyObject* obj = __pythran_wrap_interp_new_vertical10(self, args, kw))
    return obj;
PyErr_Clear();


if(PyObject* obj = __pythran_wrap_interp_new_vertical11(self, args, kw))
    return obj;
PyErr_Clear();


if(PyObject* obj = __pythran_wrap_interp_new_vertical12(self, args, kw))
    return obj;
PyErr_Clear();


if(PyObject* obj = __pythran_wrap_interp_new_vertical13(self, args, kw))
    return obj;
PyErr_Clear();


if(PyObject* obj = __pythran_wrap_interp_new_vertical14(self, args, kw))
    return obj;
PyErr_Clear();


if(PyObject* obj = __pythran_wrap_interp_new_vertical15(self, args, kw))
    return obj;
PyErr_Clear();


if(PyObject* obj = __pythran_wrap_interp_new_vertical16(self, args, kw))
    return obj;
PyErr_Clear();


if(PyObject* obj = __pythran_wrap_interp_new_vertical17(self, args, kw))
    return obj;
PyErr_Clear();


if(PyObject* obj = __pythran_wrap_interp_new_vertical18(self, args, kw))
    return obj;
PyErr_Clear();


if(PyObject* obj = __pythran_wrap_interp_new_vertical19(self, args, kw))
    return obj;
PyErr_Clear();


if(PyObject* obj = __pythran_wrap_interp_new_vertical20(self, args, kw))
    return obj;
PyErr_Clear();


if(PyObject* obj = __pythran_wrap_interp_new_vertical21(self, args, kw))
    return obj;
PyErr_Clear();


if(PyObject* obj = __pythran_wrap_interp_new_vertical22(self, args, kw))
    return obj;
PyErr_Clear();


if(PyObject* obj = __pythran_wrap_interp_new_vertical23(self, args, kw))
    return obj;
PyErr_Clear();


if(PyObject* obj = __pythran_wrap_interp_new_vertical24(self, args, kw))
    return obj;
PyErr_Clear();


if(PyObject* obj = __pythran_wrap_interp_new_vertical25(self, args, kw))
    return obj;
PyErr_Clear();


if(PyObject* obj = __pythran_wrap_interp_new_vertical26(self, args, kw))
    return obj;
PyErr_Clear();

                return pythonic::python::raise_invalid_argument(
                               "interp_new_vertical", "\n""    - interp_new_vertical(float32[:,:,:,:], float32[:,:,:,:], float32[:,:,:,:])\n""    - interp_new_vertical(float32[:,:,:,:], float32[:,:,:,:], float64[:,:,:,:])\n""    - interp_new_vertical(float32[:,:,:,:], float32[:,:,:,:], float128[:,:,:,:])\n""    - interp_new_vertical(float32[:,:,:,:], float64[:,:,:,:], float32[:,:,:,:])\n""    - interp_new_vertical(float32[:,:,:,:], float64[:,:,:,:], float64[:,:,:,:])\n""    - interp_new_vertical(float32[:,:,:,:], float64[:,:,:,:], float128[:,:,:,:])\n""    - interp_new_vertical(float32[:,:,:,:], float128[:,:,:,:], float32[:,:,:,:])\n""    - interp_new_vertical(float32[:,:,:,:], float128[:,:,:,:], float64[:,:,:,:])\n""    - interp_new_vertical(float32[:,:,:,:], float128[:,:,:,:], float128[:,:,:,:])\n""    - interp_new_vertical(float64[:,:,:,:], float32[:,:,:,:], float32[:,:,:,:])\n""    - interp_new_vertical(float64[:,:,:,:], float32[:,:,:,:], float64[:,:,:,:])\n""    - interp_new_vertical(float64[:,:,:,:], float32[:,:,:,:], float128[:,:,:,:])\n""    - interp_new_vertical(float64[:,:,:,:], float64[:,:,:,:], float32[:,:,:,:])\n""    - interp_new_vertical(float64[:,:,:,:], float64[:,:,:,:], float64[:,:,:,:])\n""    - interp_new_vertical(float64[:,:,:,:], float64[:,:,:,:], float128[:,:,:,:])\n""    - interp_new_vertical(float64[:,:,:,:], float128[:,:,:,:], float32[:,:,:,:])\n""    - interp_new_vertical(float64[:,:,:,:], float128[:,:,:,:], float64[:,:,:,:])\n""    - interp_new_vertical(float64[:,:,:,:], float128[:,:,:,:], float128[:,:,:,:])\n""    - interp_new_vertical(float128[:,:,:,:], float32[:,:,:,:], float32[:,:,:,:])\n""    - interp_new_vertical(float128[:,:,:,:], float32[:,:,:,:], float64[:,:,:,:])\n""    - interp_new_vertical(float128[:,:,:,:], float32[:,:,:,:], float128[:,:,:,:])\n""    - interp_new_vertical(float128[:,:,:,:], float64[:,:,:,:], float32[:,:,:,:])\n""    - interp_new_vertical(float128[:,:,:,:], float64[:,:,:,:], float64[:,:,:,:])\n""    - interp_new_vertical(float128[:,:,:,:], float64[:,:,:,:], float128[:,:,:,:])\n""    - interp_new_vertical(float128[:,:,:,:], float128[:,:,:,:], float32[:,:,:,:])\n""    - interp_new_vertical(float128[:,:,:,:], float128[:,:,:,:], float64[:,:,:,:])\n""    - interp_new_vertical(float128[:,:,:,:], float128[:,:,:,:], float128[:,:,:,:])", args, kw);
                });
            }


static PyMethodDef Methods[] = {
    {
    "interp_new_vertical",
    (PyCFunction)__pythran_wrapall_interp_new_vertical,
    METH_VARARGS | METH_KEYWORDS,
    "\n""  !========================================\n""  ! Compute the interpolation of the data\n""  ! The depths must be sorted increasingly\n""  ! Extend the value outside the depth range (i.e. above the surface or below the bathymetry)\n""  REAL(8), INTENT(in   ), DIMENSION(jpk_old, jpj, jpi, jpt) ::   z_old   ! old vertical positions\n""  REAL(8), INTENT(in   ), DIMENSION(jpk_new, jpj, jpi, jpt) ::   z_new   ! new vertical positions\n""  REAL(8), INTENT(in   ), DIMENSION(jpk_old, jpj, jpi, jpt) ::   V_old   ! old variable values\n""  REAL(8), INTENT(  out), DIMENSION(jpk_new, jpj, jpi, jpt) ::   V_new   ! new variable values (interpolated)\n""  !!\n""  INTEGER ::   ji, jj, jk   ! Loop indices\n""  INTEGER ::   ind   ! smallest index of the element to the left (previous) so that z_old(ind) <= z <= z_old(ind+1)\n""  !!----------------------------------------\n""\n""\n""Supported prototypes:\n""\n""- interp_new_vertical(float32[:,:,:,:], float32[:,:,:,:], float32[:,:,:,:])\n""- interp_new_vertical(float32[:,:,:,:], float32[:,:,:,:], float64[:,:,:,:])\n""- interp_new_vertical(float32[:,:,:,:], float32[:,:,:,:], float128[:,:,:,:])\n""- interp_new_vertical(float32[:,:,:,:], float64[:,:,:,:], float32[:,:,:,:])\n""- interp_new_vertical(float32[:,:,:,:], float64[:,:,:,:], float64[:,:,:,:])\n""- interp_new_vertical(float32[:,:,:,:], float64[:,:,:,:], float128[:,:,:,:])\n""- interp_new_vertical(float32[:,:,:,:], float128[:,:,:,:], float32[:,:,:,:])\n""- interp_new_vertical(float32[:,:,:,:], float128[:,:,:,:], float64[:,:,:,:])\n""- interp_new_vertical(float32[:,:,:,:], float128[:,:,:,:], float128[:,:,:,:])\n""- interp_new_vertical(float64[:,:,:,:], float32[:,:,:,:], float32[:,:,:,:])\n""- interp_new_vertical(float64[:,:,:,:], float32[:,:,:,:], float64[:,:,:,:])\n""- interp_new_vertical(float64[:,:,:,:], float32[:,:,:,:], float128[:,:,:,:])\n""- interp_new_vertical(float64[:,:,:,:], float64[:,:,:,:], float32[:,:,:,:])\n""- interp_new_vertical(float64[:,:,:,:], float64[:,:,:,:], float64[:,:,:,:])\n""- interp_new_vertical(float64[:,:,:,:], float64[:,:,:,:], float128[:,:,:,:])\n""- interp_new_vertical(float64[:,:,:,:], float128[:,:,:,:], float32[:,:,:,:])\n""- interp_new_vertical(float64[:,:,:,:], float128[:,:,:,:], float64[:,:,:,:])\n""- interp_new_vertical(float64[:,:,:,:], float128[:,:,:,:], float128[:,:,:,:])\n""- interp_new_vertical(float128[:,:,:,:], float32[:,:,:,:], float32[:,:,:,:])\n""- interp_new_vertical(float128[:,:,:,:], float32[:,:,:,:], float64[:,:,:,:])\n""- interp_new_vertical(float128[:,:,:,:], float32[:,:,:,:], float128[:,:,:,:])\n""- interp_new_vertical(float128[:,:,:,:], float64[:,:,:,:], float32[:,:,:,:])\n""- interp_new_vertical(float128[:,:,:,:], float64[:,:,:,:], float64[:,:,:,:])\n""- interp_new_vertical(float128[:,:,:,:], float64[:,:,:,:], float128[:,:,:,:])\n""- interp_new_vertical(float128[:,:,:,:], float128[:,:,:,:], float32[:,:,:,:])\n""- interp_new_vertical(float128[:,:,:,:], float128[:,:,:,:], float64[:,:,:,:])\n""- interp_new_vertical(float128[:,:,:,:], float128[:,:,:,:], float128[:,:,:,:])"},
    {NULL, NULL, 0, NULL}
};


#if PY_MAJOR_VERSION >= 3
  static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "interpolation_compiled",            /* m_name */
    "",         /* m_doc */
    -1,                  /* m_size */
    Methods,             /* m_methods */
    NULL,                /* m_reload */
    NULL,                /* m_traverse */
    NULL,                /* m_clear */
    NULL,                /* m_free */
  };
#define PYTHRAN_RETURN return theModule
#define PYTHRAN_MODULE_INIT(s) PyInit_##s
#else
#define PYTHRAN_RETURN return
#define PYTHRAN_MODULE_INIT(s) init##s
#endif
PyMODINIT_FUNC
PYTHRAN_MODULE_INIT(interpolation_compiled)(void)
#ifndef _WIN32
__attribute__ ((visibility("default")))
__attribute__ ((externally_visible))
#endif
;
PyMODINIT_FUNC
PYTHRAN_MODULE_INIT(interpolation_compiled)(void) {
    import_array()
    #if PY_MAJOR_VERSION >= 3
    PyObject* theModule = PyModule_Create(&moduledef);
    #else
    PyObject* theModule = Py_InitModule3("interpolation_compiled",
                                         Methods,
                                         ""
    );
    #endif
    if(! theModule)
        PYTHRAN_RETURN;
    PyObject * theDoc = Py_BuildValue("(sss)",
                                      "0.9.5",
                                      "2020-04-27 12:19:51.699389",
                                      "9f2511d4ade5d180672333427942a97d1921fe2996e8b9cb6c0bb95c863ddb7f");
    if(! theDoc)
        PYTHRAN_RETURN;
    PyModule_AddObject(theModule,
                       "__pythran__",
                       theDoc);


    PYTHRAN_RETURN;
}

#endif