// Copyright (c) 2019, Leonardo Lang
//
// This file is distributed under the GNU LGPL v2.1
//
// See LICENSE file for details.

/* uncomment this to enable examples which trigger a compilation failure */

// #define FAIL

template <int V>
struct value
{
    enum { R = V };
};

typedef value<1> V1;
typedef value<2> V2;
typedef value<3> V3;
typedef value<4> V4;
typedef value<5> V5;
typedef value<6> V6;
typedef value<7> V7;
typedef value<8> V8;
typedef value<9> V9;

/*
   structs below implement the error "messages", which will trigger a failure
   to compile if some number is not on the right position. they can be interpreted
   by decoding the three parameters passed by the templates:

   - first: number of times the value appeared (always different from one in case of error);
   - second: column/row/block number (from counting top left to bottom right);
   - third: the value (number) which appears more than once (or not at all).
*/

template <int RES, int ROW, int NUM>
struct row_value_assert_once_failed;

template <int ROW, int NUM>
struct row_value_assert_once_failed<1, ROW, NUM> { typedef V1 t; };

template <int RES, int COL, int NUM>
struct col_value_assert_once_failed;

template <int COL, int NUM>
struct col_value_assert_once_failed<1, COL, NUM> { typedef int t; };

template <int RES, int COL, int NUM>
struct block_value_assert_once_failed;

template <int COL, int NUM>
struct block_value_assert_once_failed<1, COL, NUM> { typedef int t; };

template <typename V, typename T>
struct cmp
{
    enum { R = ((int)(V::R) == (int)(T::R)) ? 1 : 0 };
};

template <typename V, typename A, typename B, typename C>
struct and_ifeq3
{
    enum { R = cmp<V,A>::R && cmp<V,B>::R && cmp<V,C>::R };
};

template <typename V,
          typename A, typename B, typename C,
          typename D, typename E, typename F,
          typename G, typename H, typename I>
struct and_ifeq8
{
    enum { R = cmp<V,A>::R && cmp<V,B>::R && cmp<V,C>::R &&
               cmp<V,D>::R && cmp<V,E>::R && cmp<V,F>::R &&
               cmp<V,G>::R && cmp<V,H>::R && cmp<V,I>::R };
};

template <template <int RES, int POS, int NUM> typename Z,
          int POS, typename V, typename S>
struct is_unique
{
    typedef typename S::v0 v0;
    typedef typename S::v1 v1;
    typedef typename S::v2 v2;
    typedef typename S::v3 v3;
    typedef typename S::v4 v4;
    typedef typename S::v5 v5;
    typedef typename S::v6 v6;
    typedef typename S::v7 v7;
    typedef typename S::v8 v8;

    enum { R = cmp<V,v0>::R + cmp<V,v1>::R + cmp<V,v2>::R +
               cmp<V,v3>::R + cmp<V,v4>::R + cmp<V,v5>::R +
               cmp<V,v6>::R + cmp<V,v7>::R + cmp<V,v8>::R };

    typedef typename Z<R, POS, V::R>::t t;
};

template < typename C, typename R, typename B, int NR >
struct validate
{
    typedef typename is_unique<col_value_assert_once_failed, NR, V1, C>::t C1;
    typedef typename is_unique<col_value_assert_once_failed, NR, V2, C>::t C2;
    typedef typename is_unique<col_value_assert_once_failed, NR, V3, C>::t C3;
    typedef typename is_unique<col_value_assert_once_failed, NR, V4, C>::t C4;
    typedef typename is_unique<col_value_assert_once_failed, NR, V5, C>::t C5;
    typedef typename is_unique<col_value_assert_once_failed, NR, V6, C>::t C6;
    typedef typename is_unique<col_value_assert_once_failed, NR, V7, C>::t C7;
    typedef typename is_unique<col_value_assert_once_failed, NR, V8, C>::t C8;
    typedef typename is_unique<col_value_assert_once_failed, NR, V9, C>::t C9;

    typedef typename is_unique<row_value_assert_once_failed, NR, V1, R>::t R1;
    typedef typename is_unique<row_value_assert_once_failed, NR, V2, R>::t R2;
    typedef typename is_unique<row_value_assert_once_failed, NR, V3, R>::t R3;
    typedef typename is_unique<row_value_assert_once_failed, NR, V4, R>::t R4;
    typedef typename is_unique<row_value_assert_once_failed, NR, V5, R>::t R5;
    typedef typename is_unique<row_value_assert_once_failed, NR, V6, R>::t R6;
    typedef typename is_unique<row_value_assert_once_failed, NR, V7, R>::t R7;
    typedef typename is_unique<row_value_assert_once_failed, NR, V8, R>::t R8;
    typedef typename is_unique<row_value_assert_once_failed, NR, V9, R>::t R9;

    typedef typename is_unique<block_value_assert_once_failed, NR, V1, B>::t B1;
    typedef typename is_unique<block_value_assert_once_failed, NR, V2, B>::t B2;
    typedef typename is_unique<block_value_assert_once_failed, NR, V3, B>::t B3;
    typedef typename is_unique<block_value_assert_once_failed, NR, V4, B>::t B4;
    typedef typename is_unique<block_value_assert_once_failed, NR, V5, B>::t B5;
    typedef typename is_unique<block_value_assert_once_failed, NR, V6, B>::t B6;
    typedef typename is_unique<block_value_assert_once_failed, NR, V7, B>::t B7;
    typedef typename is_unique<block_value_assert_once_failed, NR, V8, B>::t B8;
    typedef typename is_unique<block_value_assert_once_failed, NR, V9, B>::t B9;

    typedef and_ifeq8<V1, C1, C2, C3, C4, C5, C6, C7, C8, C9> Ct;
    typedef and_ifeq8<V1, R1, R2, R3, R4, R5, R6, R7, R8, R9> Rt;
    typedef and_ifeq8<V1, B1, B2, B3, B4, B5, B6, B7, B8, B9> Bt;

    typedef and_ifeq3<V1, Ct, Rt, Bt> t;
};

template <int A, int B, int C,
          int D, int E, int F,
          int G, int H, int I>
struct row
{
    typedef value<A> v0;
    typedef value<B> v1;
    typedef value<C> v2;
    typedef value<D> v3;
    typedef value<E> v4;
    typedef value<F> v5;
    typedef value<G> v6;
    typedef value<H> v7;
    typedef value<I> v8;
};

template <typename T> struct get0 { typedef typename T::v0 t; };
template <typename T> struct get1 { typedef typename T::v1 t; };
template <typename T> struct get2 { typedef typename T::v2 t; };
template <typename T> struct get3 { typedef typename T::v3 t; };
template <typename T> struct get4 { typedef typename T::v4 t; };
template <typename T> struct get5 { typedef typename T::v5 t; };
template <typename T> struct get6 { typedef typename T::v6 t; };
template <typename T> struct get7 { typedef typename T::v7 t; };
template <typename T> struct get8 { typedef typename T::v8 t; };

template <template <typename ROW> typename GET,
          typename A, typename B, typename C,
          typename D, typename E, typename F,
          typename G, typename H, typename I>
struct column
{
    typedef typename GET<A>::t v0;
    typedef typename GET<B>::t v1;
    typedef typename GET<C>::t v2;
    typedef typename GET<D>::t v3;
    typedef typename GET<E>::t v4;
    typedef typename GET<F>::t v5;
    typedef typename GET<G>::t v6;
    typedef typename GET<H>::t v7;
    typedef typename GET<I>::t v8;
};

template <template <typename ROW> typename GET0,
          template <typename ROW> typename GET1,
          template <typename ROW> typename GET2,
          typename R0, typename R1, typename R2>
struct block
{
    typedef typename GET0<R0>::t v0;
    typedef typename GET1<R0>::t v1;
    typedef typename GET2<R0>::t v2;
    typedef typename GET0<R1>::t v3;
    typedef typename GET1<R1>::t v4;
    typedef typename GET2<R1>::t v5;
    typedef typename GET0<R2>::t v6;
    typedef typename GET1<R2>::t v7;
    typedef typename GET2<R2>::t v8;
};

template <typename R0, typename R1, typename R2,
          typename R3, typename R4, typename R5,
          typename R6, typename R7, typename R8>

struct table
{
    typedef column< get0, R0, R1, R2, R3, R4, R5, R6, R7, R8 > C0;
    typedef column< get1, R0, R1, R2, R3, R4, R5, R6, R7, R8 > C1;
    typedef column< get2, R0, R1, R2, R3, R4, R5, R6, R7, R8 > C2;
    typedef column< get3, R0, R1, R2, R3, R4, R5, R6, R7, R8 > C3;
    typedef column< get4, R0, R1, R2, R3, R4, R5, R6, R7, R8 > C4;
    typedef column< get5, R0, R1, R2, R3, R4, R5, R6, R7, R8 > C5;
    typedef column< get6, R0, R1, R2, R3, R4, R5, R6, R7, R8 > C6;
    typedef column< get7, R0, R1, R2, R3, R4, R5, R6, R7, R8 > C7;
    typedef column< get8, R0, R1, R2, R3, R4, R5, R6, R7, R8 > C8;

    typedef block< get0, get1, get2, R0, R1, R2 > B0;
    typedef block< get3, get4, get5, R0, R1, R2 > B1;
    typedef block< get6, get7, get8, R0, R1, R2 > B2;
    typedef block< get0, get1, get2, R3, R4, R5 > B3;
    typedef block< get3, get4, get5, R3, R4, R5 > B4;
    typedef block< get6, get7, get8, R3, R4, R5 > B5;
    typedef block< get0, get1, get2, R6, R7, R8 > B6;
    typedef block< get3, get4, get5, R6, R7, R8 > B7;
    typedef block< get6, get7, get8, R6, R7, R8 > B8;

    typedef typename validate< C0, R0, B0, 0 >::t T0;
    typedef typename validate< C1, R1, B1, 1 >::t T1;
    typedef typename validate< C2, R2, B2, 2 >::t T2;
    typedef typename validate< C3, R3, B3, 3 >::t T3;
    typedef typename validate< C4, R4, B4, 4 >::t T4;
    typedef typename validate< C5, R5, B5, 5 >::t T5;
    typedef typename validate< C6, R6, B6, 6 >::t T6;
    typedef typename validate< C7, R7, B7, 7 >::t T7;
    typedef typename validate< C8, R8, B8, 8 >::t T8;

    typedef and_ifeq8<V1, T0, T1, T2, T3, T4, T5, T6, T7, T8> t;
};

int main()
{
    typedef
    table< row< 1, 2, 6,  9, 8, 4,  5, 7, 3 >,
           row< 5, 4, 8,  1, 7, 3,  6, 9, 2 >,
           row< 9, 3, 7,  2, 5, 6,  1, 4, 8 >,

           row< 4, 7, 1,  3, 9, 8,  2, 5, 6 >,
           row< 2, 6, 5,  4, 1, 7,  8, 3, 9 >,
           row< 8, 9, 3,  6, 2, 5,  7, 1, 4 >,

           row< 3, 8, 2,  7, 4, 1,  9, 6, 5 >,
           row< 6, 1, 9,  5, 3, 2,  4, 8, 7 >,
           row< 7, 5, 4,  8, 6, 9,  3, 2, 1 > >::t
    sudoku_ok1_t;

    typedef
    table< row< 6, 5, 9,  3, 8, 1,  4, 7, 2 >,
           row< 3, 8, 1,  7, 4, 2,  5, 9, 6 >,
           row< 7, 2, 4,  5, 6, 9,  3, 8, 1 >,

           row< 8, 4, 6,  9, 5, 3,  1, 2, 7 >,
           row< 2, 3, 5,  6, 1, 7,  8, 4, 9 >,
           row< 9, 1, 7,  8, 2, 4,  6, 3, 5 >,

           row< 4, 6, 2,  1, 7, 8,  9, 5, 3 >,
           row< 5, 9, 8,  2, 3, 6,  7, 1, 4 >,
           row< 1, 7, 3,  4, 9, 5,  2, 6, 8 > >::t
    sudoku_ok2_t;


#ifdef FAIL
    typedef
    table< row< 3, 2, 6,  9, 8, 4,  5, 7, 1 >,
           row< 5, 4, 8,  1, 7, 3,  6, 9, 2 >,
           row< 9, 3, 7,  2, 5, 6,  1, 4, 8 >,

           row< 4, 7, 1,  3, 9, 8,  2, 5, 6 >,
           row< 2, 6, 5,  4, 1, 7,  8, 3, 9 >,
           row< 8, 9, 3,  6, 2, 5,  7, 1, 4 >,

           row< 3, 8, 2,  7, 4, 1,  9, 6, 5 >,
           row< 6, 1, 9,  5, 3, 2,  4, 8, 7 >,
           row< 7, 5, 4,  8, 6, 9,  3, 2, 1 > >::t
    sudoku_error_t;
#endif

    return 0;
};
