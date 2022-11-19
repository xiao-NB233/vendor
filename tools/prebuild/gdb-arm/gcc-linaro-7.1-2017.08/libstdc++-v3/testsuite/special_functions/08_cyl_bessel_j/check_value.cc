// { dg-do run { target c++11 } }
// { dg-options "-D__STDCPP_WANT_MATH_SPEC_FUNCS__" }
//
// Copyright (C) 2016-2017 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.

//  cyl_bessel_j
//  Compare against values generated by the GNU Scientific Library.
//  The GSL can be found on the web: http://www.gnu.org/software/gsl/
#include <limits>
#include <cmath>
#if defined(__TEST_DEBUG)
#  include <iostream>
#  define VERIFY(A) \
  if (!(A)) \
    { \
      std::cout << "line " << __LINE__ \
	<< "  max_abs_frac = " << max_abs_frac \
	<< std::endl; \
    }
#else
#  include <testsuite_hooks.h>
#endif
#include <specfun_testcase.h>


// Test data for nu=0.0000000000000000.
// max(|f - f_GSL|): 1.6653345369377348e-16
// max(|f - f_GSL| / |f_GSL|): 6.5276306654894409e-16
const testcase_cyl_bessel_j<double>
data001[21] =
{
  { 1.0000000000000000, 0.0000000000000000, 0.0000000000000000 },
  { 0.98443592929585266, 0.0000000000000000, 0.25000000000000000 },
  { 0.93846980724081297, 0.0000000000000000, 0.50000000000000000 },
  { 0.86424227516664853, 0.0000000000000000, 0.75000000000000000 },
  { 0.76519768655796661, 0.0000000000000000, 1.0000000000000000 },
  { 0.64590608527128535, 0.0000000000000000, 1.2500000000000000 },
  { 0.51182767173591814, 0.0000000000000000, 1.5000000000000000 },
  { 0.36903253018515075, 0.0000000000000000, 1.7500000000000000 },
  { 0.22389077914123562, 0.0000000000000000, 2.0000000000000000 },
  { 0.082749851288734022, 0.0000000000000000, 2.2500000000000000 },
  { -0.048383776468197998, 0.0000000000000000, 2.5000000000000000 },
  { -0.16414142780851368, 0.0000000000000000, 2.7500000000000000 },
  { -0.26005195490193334, 0.0000000000000000, 3.0000000000000000 },
  { -0.33275080217061132, 0.0000000000000000, 3.2500000000000000 },
  { -0.38012773998726335, 0.0000000000000000, 3.5000000000000000 },
  { -0.40140605493617426, 0.0000000000000000, 3.7500000000000000 },
  { -0.39714980986384740, 0.0000000000000000, 4.0000000000000000 },
  { -0.36919977029989554, 0.0000000000000000, 4.2500000000000000 },
  { -0.32054250898512149, 0.0000000000000000, 4.5000000000000000 },
  { -0.25512082749137405, 0.0000000000000000, 4.7500000000000000 },
  { -0.17759677131433835, 0.0000000000000000, 5.0000000000000000 },
};
const double toler001 = 2.5000000000000020e-13;

// Test data for nu=0.33333333333333331.
// max(|f - f_GSL|): 7.7715611723760958e-16
// max(|f - f_GSL| / |f_GSL|): 1.2121143083098064e-15
const testcase_cyl_bessel_j<double>
data002[21] =
{
  { 0.0000000000000000, 0.33333333333333331, 0.0000000000000000 },
  { 0.55338359549647709, 0.33333333333333331, 0.25000000000000000 },
  { 0.67283082949794537, 0.33333333333333331, 0.50000000000000000 },
  { 0.72490863199379008, 0.33333333333333331, 0.75000000000000000 },
  { 0.73087640216944760, 0.33333333333333331, 1.0000000000000000 },
  { 0.69953374433894455, 0.33333333333333331, 1.2500000000000000 },
  { 0.63713263706489176, 0.33333333333333331, 1.5000000000000000 },
  { 0.54956352730788460, 0.33333333333333331, 1.7500000000000000 },
  { 0.44293981814857586, 0.33333333333333331, 2.0000000000000000 },
  { 0.32366988946292502, 0.33333333333333331, 2.2500000000000000 },
  { 0.19832093341860796, 0.33333333333333331, 2.5000000000000000 },
  { 0.073389637874297489, 0.33333333333333331, 2.7500000000000000 },
  { -0.044963820940233351, 0.33333333333333331, 3.0000000000000000 },
  { -0.15118395956666372, 0.33333333333333331, 3.2500000000000000 },
  { -0.24056593952693625, 0.33333333333333331, 3.5000000000000000 },
  { -0.30946094681921288, 0.33333333333333331, 3.7500000000000000 },
  { -0.35542737345457609, 0.33333333333333331, 4.0000000000000000 },
  { -0.37731852825457068, 0.33333333333333331, 4.2500000000000000 },
  { -0.37530189159358079, 0.33333333333333331, 4.5000000000000000 },
  { -0.35080916720916927, 0.33333333333333331, 4.7500000000000000 },
  { -0.30642046380026405, 0.33333333333333331, 5.0000000000000000 },
};
const double toler002 = 2.5000000000000020e-13;

// Test data for nu=0.50000000000000000.
// max(|f - f_GSL|): 7.7715611723760958e-16
// max(|f - f_GSL| / |f_GSL|): 1.1959227189513475e-15
const testcase_cyl_bessel_j<double>
data003[21] =
{
  { 0.0000000000000000, 0.50000000000000000, 0.0000000000000000 },
  { 0.39479959874136972, 0.50000000000000000, 0.25000000000000000 },
  { 0.54097378993452760, 0.50000000000000000, 0.50000000000000000 },
  { 0.62800587637588623, 0.50000000000000000, 0.75000000000000000 },
  { 0.67139670714180244, 0.50000000000000000, 1.0000000000000000 },
  { 0.67724253810014312, 0.50000000000000000, 1.2500000000000000 },
  { 0.64983807475374655, 0.50000000000000000, 1.5000000000000000 },
  { 0.59348525447147382, 0.50000000000000000, 1.7500000000000000 },
  { 0.51301613656182721, 0.50000000000000000, 2.0000000000000000 },
  { 0.41387506064759982, 0.50000000000000000, 2.2500000000000000 },
  { 0.30200490606236535, 0.50000000000000000, 2.5000000000000000 },
  { 0.18363332138431521, 0.50000000000000000, 2.7500000000000000 },
  { 0.065008182877375753, 0.50000000000000000, 3.0000000000000000 },
  { -0.047885729975898544, 0.50000000000000000, 3.2500000000000000 },
  { -0.14960456964952620, 0.50000000000000000, 3.5000000000000000 },
  { -0.23549801845815513, 0.50000000000000000, 3.7500000000000000 },
  { -0.30192051329163944, 0.50000000000000000, 4.0000000000000000 },
  { -0.34638850218952444, 0.50000000000000000, 4.2500000000000000 },
  { -0.36767487332724025, 0.50000000000000000, 4.5000000000000000 },
  { -0.36583563802350400, 0.50000000000000000, 4.7500000000000000 },
  { -0.34216798479816180, 0.50000000000000000, 5.0000000000000000 },
};
const double toler003 = 2.5000000000000020e-13;

// Test data for nu=0.66666666666666663.
// max(|f - f_GSL|): 7.7715611723760958e-16
// max(|f - f_GSL| / |f_GSL|): 1.4163878424300161e-15
const testcase_cyl_bessel_j<double>
data004[21] =
{
  { 0.0000000000000000, 0.66666666666666663, 0.0000000000000000 },
  { 0.27434438998865135, 0.66666666666666663, 0.25000000000000000 },
  { 0.42331075068448321, 0.66666666666666663, 0.50000000000000000 },
  { 0.52870551548162792, 0.66666666666666663, 0.75000000000000000 },
  { 0.59794997367362801, 0.66666666666666663, 1.0000000000000000 },
  { 0.63338726889075891, 0.66666666666666663, 1.2500000000000000 },
  { 0.63673234502877385, 0.66666666666666663, 1.5000000000000000 },
  { 0.61022230460131899, 0.66666666666666663, 1.7500000000000000 },
  { 0.55696967691913712, 0.66666666666666663, 2.0000000000000000 },
  { 0.48101276749106114, 0.66666666666666663, 2.2500000000000000 },
  { 0.38721242477084306, 0.66666666666666663, 2.5000000000000000 },
  { 0.28105724771080542, 0.66666666666666663, 2.7500000000000000 },
  { 0.16841218049067044, 0.66666666666666663, 3.0000000000000000 },
  { 0.055235893475364915, 0.66666666666666663, 3.2500000000000000 },
  { -0.052711584404031925, 0.66666666666666663, 3.5000000000000000 },
  { -0.15015178042293029, 0.66666666666666663, 3.7500000000000000 },
  { -0.23254408502670390, 0.66666666666666663, 4.0000000000000000 },
  { -0.29630067002972543, 0.66666666666666663, 4.2500000000000000 },
  { -0.33894810189777724, 0.66666666666666663, 4.5000000000000000 },
  { -0.35922706960321099, 0.66666666666666663, 4.7500000000000000 },
  { -0.35712533549168868, 0.66666666666666663, 5.0000000000000000 },
};
const double toler004 = 2.5000000000000020e-13;

// Test data for nu=1.0000000000000000.
// max(|f - f_GSL|): 2.2204460492503131e-16
// max(|f - f_GSL| / |f_GSL|): 6.7783500059747526e-16
const testcase_cyl_bessel_j<double>
data005[21] =
{
  { 0.0000000000000000, 1.0000000000000000, 0.0000000000000000 },
  { 0.12402597732272694, 1.0000000000000000, 0.25000000000000000 },
  { 0.24226845767487390, 1.0000000000000000, 0.50000000000000000 },
  { 0.34924360217486222, 1.0000000000000000, 0.75000000000000000 },
  { 0.44005058574493355, 1.0000000000000000, 1.0000000000000000 },
  { 0.51062326031988059, 1.0000000000000000, 1.2500000000000000 },
  { 0.55793650791009952, 1.0000000000000000, 1.5000000000000000 },
  { 0.58015619763899240, 1.0000000000000000, 1.7500000000000000 },
  { 0.57672480775687363, 1.0000000000000000, 2.0000000000000000 },
  { 0.54837835664696011, 1.0000000000000000, 2.2500000000000000 },
  { 0.49709410246427416, 1.0000000000000000, 2.5000000000000000 },
  { 0.42597230295790256, 1.0000000000000000, 2.7500000000000000 },
  { 0.33905895852593648, 1.0000000000000000, 3.0000000000000000 },
  { 0.24111968801520400, 1.0000000000000000, 3.2500000000000000 },
  { 0.13737752736232706, 1.0000000000000000, 3.5000000000000000 },
  { 0.033229349129679724, 1.0000000000000000, 3.7500000000000000 },
  { -0.066043328023549230, 1.0000000000000000, 4.0000000000000000 },
  { -0.15555319297834286, 1.0000000000000000, 4.2500000000000000 },
  { -0.23106043192337070, 1.0000000000000000, 4.5000000000000000 },
  { -0.28918679864711044, 1.0000000000000000, 4.7500000000000000 },
  { -0.32757913759146529, 1.0000000000000000, 5.0000000000000000 },
};
const double toler005 = 2.5000000000000020e-13;

// Test data for nu=2.0000000000000000.
// max(|f - f_GSL|): 5.5511151231257827e-17
// max(|f - f_GSL| / |f_GSL|): 2.4155555971238584e-16
const testcase_cyl_bessel_j<double>
data006[21] =
{
  { 0.0000000000000000, 2.0000000000000000, 0.0000000000000000 },
  { 0.0077718892859626760, 2.0000000000000000, 0.25000000000000000 },
  { 0.030604023458682638, 2.0000000000000000, 0.50000000000000000 },
  { 0.067073997299650551, 2.0000000000000000, 0.75000000000000000 },
  { 0.11490348493190047, 2.0000000000000000, 1.0000000000000000 },
  { 0.17109113124052350, 2.0000000000000000, 1.2500000000000000 },
  { 0.23208767214421472, 2.0000000000000000, 1.5000000000000000 },
  { 0.29400312425941216, 2.0000000000000000, 1.7500000000000000 },
  { 0.35283402861563773, 2.0000000000000000, 2.0000000000000000 },
  { 0.40469757684189717, 2.0000000000000000, 2.2500000000000000 },
  { 0.44605905843961718, 2.0000000000000000, 2.5000000000000000 },
  { 0.47393946632335160, 2.0000000000000000, 2.7500000000000000 },
  { 0.48609126058589119, 2.0000000000000000, 3.0000000000000000 },
  { 0.48113214864150627, 2.0000000000000000, 3.2500000000000000 },
  { 0.45862918419430765, 2.0000000000000000, 3.5000000000000000 },
  { 0.41912837447200352, 2.0000000000000000, 3.7500000000000000 },
  { 0.36412814585207293, 2.0000000000000000, 4.0000000000000000 },
  { 0.29599826772185189, 2.0000000000000000, 4.2500000000000000 },
  { 0.21784898368584549, 2.0000000000000000, 4.5000000000000000 },
  { 0.13335796490311685, 2.0000000000000000, 4.7500000000000000 },
  { 0.046565116277751971, 2.0000000000000000, 5.0000000000000000 },
};
const double toler006 = 2.5000000000000020e-13;

// Test data for nu=5.0000000000000000.
// max(|f - f_GSL|): 1.3877787807814457e-16
// max(|f - f_GSL| / |f_GSL|): 1.4609680807504906e-15
const testcase_cyl_bessel_j<double>
data007[21] =
{
  { 0.0000000000000000, 5.0000000000000000, 0.0000000000000000 },
  { 2.5365161587472413e-07, 5.0000000000000000, 0.25000000000000000 },
  { 8.0536272413574753e-06, 5.0000000000000000, 0.50000000000000000 },
  { 6.0364166510576438e-05, 5.0000000000000000, 0.75000000000000000 },
  { 0.00024975773021123450, 5.0000000000000000, 1.0000000000000000 },
  { 0.00074440885254749821, 5.0000000000000000, 1.2500000000000000 },
  { 0.0017994217673606111, 5.0000000000000000, 1.5000000000000000 },
  { 0.0037577257273157133, 5.0000000000000000, 1.7500000000000000 },
  { 0.0070396297558716842, 5.0000000000000000, 2.0000000000000000 },
  { 0.012121078633445751, 5.0000000000000000, 2.2500000000000000 },
  { 0.019501625134503223, 5.0000000000000000, 2.5000000000000000 },
  { 0.029664058320006174, 5.0000000000000000, 2.7500000000000000 },
  { 0.043028434877047578, 5.0000000000000000, 3.0000000000000000 },
  { 0.059903888098560426, 5.0000000000000000, 3.2500000000000000 },
  { 0.080441986647991792, 5.0000000000000000, 3.5000000000000000 },
  { 0.10459554742314070, 5.0000000000000000, 3.7500000000000000 },
  { 0.13208665604709827, 5.0000000000000000, 4.0000000000000000 },
  { 0.16238721643623680, 5.0000000000000000, 4.2500000000000000 },
  { 0.19471465863871368, 5.0000000000000000, 4.5000000000000000 },
  { 0.22804452118769436, 5.0000000000000000, 4.7500000000000000 },
  { 0.26114054612017007, 5.0000000000000000, 5.0000000000000000 },
};
const double toler007 = 2.5000000000000020e-13;

// Test data for nu=10.000000000000000.
// max(|f - f_GSL|): 3.2526065174565133e-18
// max(|f - f_GSL| / |f_GSL|): 3.9336732209858561e-15
const testcase_cyl_bessel_j<double>
data008[21] =
{
  { 0.0000000000000000, 10.000000000000000, 0.0000000000000000 },
  { 2.5628321598050096e-16, 10.000000000000000, 0.25000000000000000 },
  { 2.6131773608228023e-13, 10.000000000000000, 0.50000000000000000 },
  { 1.4962171311759677e-11, 10.000000000000000, 0.75000000000000000 },
  { 2.6306151236874524e-10, 10.000000000000000, 1.0000000000000000 },
  { 2.4187548221114514e-09, 10.000000000000000, 1.2500000000000000 },
  { 1.4743269078039996e-08, 10.000000000000000, 1.5000000000000000 },
  { 6.7608502849897560e-08, 10.000000000000000, 1.7500000000000000 },
  { 2.5153862827167358e-07, 10.000000000000000, 2.0000000000000000 },
  { 7.9717051583730038e-07, 10.000000000000000, 2.2500000000000000 },
  { 2.2247284173983839e-06, 10.000000000000000, 2.5000000000000000 },
  { 5.5985475639210430e-06, 10.000000000000000, 2.7500000000000000 },
  { 1.2928351645715880e-05, 10.000000000000000, 3.0000000000000000 },
  { 2.7761691354244538e-05, 10.000000000000000, 3.2500000000000000 },
  { 5.6009495875078844e-05, 10.000000000000000, 3.5000000000000000 },
  { 0.00010703761729231951, 10.000000000000000, 3.7500000000000000 },
  { 0.00019504055466003446, 10.000000000000000, 4.0000000000000000 },
  { 0.00034068888474064193, 10.000000000000000, 4.2500000000000000 },
  { 0.00057300977667164505, 10.000000000000000, 4.5000000000000000 },
  { 0.00093142172588886810, 10.000000000000000, 4.7500000000000000 },
  { 0.0014678026473104744, 10.000000000000000, 5.0000000000000000 },
};
const double toler008 = 2.5000000000000020e-13;

// Test data for nu=20.000000000000000.
// max(|f - f_GSL|): 1.9387045606711586e-26
// max(|f - f_GSL| / |f_GSL|): 2.1275572270326799e-15
const testcase_cyl_bessel_j<double>
data009[21] =
{
  { 0.0000000000000000, 20.000000000000000, 0.0000000000000000 },
  { 3.5624805510586969e-37, 20.000000000000000, 0.25000000000000000 },
  { 3.7272019617047132e-31, 20.000000000000000, 0.50000000000000000 },
  { 1.2347870693633488e-27, 20.000000000000000, 0.75000000000000000 },
  { 3.8735030085246562e-25, 20.000000000000000, 1.0000000000000000 },
  { 3.3372897667043766e-23, 20.000000000000000, 1.2500000000000000 },
  { 1.2689972189332558e-21, 20.000000000000000, 1.5000000000000000 },
  { 2.7427715944032989e-20, 20.000000000000000, 1.7500000000000000 },
  { 3.9189728050907524e-19, 20.000000000000000, 2.0000000000000000 },
  { 4.0805232551365158e-18, 20.000000000000000, 2.2500000000000000 },
  { 3.3090793836587786e-17, 20.000000000000000, 2.5000000000000000 },
  { 2.1915404680645990e-16, 20.000000000000000, 2.7500000000000000 },
  { 1.2275946737992981e-15, 20.000000000000000, 3.0000000000000000 },
  { 5.9727663938305382e-15, 20.000000000000000, 3.2500000000000000 },
  { 2.5768553102807590e-14, 20.000000000000000, 3.5000000000000000 },
  { 1.0021112208287217e-13, 20.000000000000000, 3.7500000000000000 },
  { 3.5595116285938516e-13, 20.000000000000000, 4.0000000000000000 },
  { 1.1673622958555074e-12, 20.000000000000000, 4.2500000000000000 },
  { 3.5665470983611762e-12, 20.000000000000000, 4.5000000000000000 },
  { 1.0227564044880958e-11, 20.000000000000000, 4.7500000000000000 },
  { 2.7703300521289426e-11, 20.000000000000000, 5.0000000000000000 },
};
const double toler009 = 2.5000000000000020e-13;
//  cyl_bessel_j

// Test data for nu=0.0000000000000000.
// max(|f - f_GSL|): 7.6709472107694410e-15
// max(|f - f_GSL| / |f_GSL|): 4.1048891312746575e-13
const testcase_cyl_bessel_j<double>
data010[21] =
{
  { 1.0000000000000000, 0.0000000000000000, 0.0000000000000000 },
  { -0.17759677131433835, 0.0000000000000000, 5.0000000000000000 },
  { -0.24593576445134835, 0.0000000000000000, 10.000000000000000 },
  { -0.014224472826780771, 0.0000000000000000, 15.000000000000000 },
  { 0.16702466434058319, 0.0000000000000000, 20.000000000000000 },
  { 0.096266783275958154, 0.0000000000000000, 25.000000000000000 },
  { -0.086367983581040142, 0.0000000000000000, 30.000000000000000 },
  { -0.12684568275631256, 0.0000000000000000, 35.000000000000000 },
  { 0.0073668905842374085, 0.0000000000000000, 40.000000000000000 },
  { 0.11581867067325631, 0.0000000000000000, 45.000000000000000 },
  { 0.055812327669251746, 0.0000000000000000, 50.000000000000000 },
  { -0.074548302648236808, 0.0000000000000000, 55.000000000000000 },
  { -0.091471804089061859, 0.0000000000000000, 60.000000000000000 },
  { 0.018687343227677979, 0.0000000000000000, 65.000000000000000 },
  { 0.094908726483013545, 0.0000000000000000, 70.000000000000000 },
  { 0.034643913805097008, 0.0000000000000000, 75.000000000000000 },
  { -0.069742165512210033, 0.0000000000000000, 80.000000000000000 },
  { -0.070940394796273273, 0.0000000000000000, 85.000000000000000 },
  { 0.026630016699969526, 0.0000000000000000, 90.000000000000000 },
  { 0.081811967783384135, 0.0000000000000000, 95.000000000000000 },
  { 0.019985850304223170, 0.0000000000000000, 100.00000000000000 },
};
const double toler010 = 2.5000000000000014e-11;

// Test data for nu=0.33333333333333331.
// max(|f - f_GSL|): 7.9311557321659620e-15
// max(|f - f_GSL| / |f_GSL|): 4.2444155318123211e-12
const testcase_cyl_bessel_j<double>
data011[21] =
{
  { 0.0000000000000000, 0.33333333333333331, 0.0000000000000000 },
  { -0.30642046380026405, 0.33333333333333331, 5.0000000000000000 },
  { -0.18614516704869571, 0.33333333333333331, 10.000000000000000 },
  { 0.089740004221152650, 0.33333333333333331, 15.000000000000000 },
  { 0.17606058001293901, 0.33333333333333331, 20.000000000000000 },
  { 0.020097162141383233, 0.33333333333333331, 25.000000000000000 },
  { -0.13334053387426159, 0.33333333333333331, 30.000000000000000 },
  { -0.087118009397765497, 0.33333333333333331, 35.000000000000000 },
  { 0.069202942818858179, 0.33333333333333331, 40.000000000000000 },
  { 0.11387616964518317, 0.33333333333333331, 45.000000000000000 },
  { -0.00057226680771808045, 0.33333333333333331, 50.000000000000000 },
  { -0.10331600929280822, 0.33333333333333331, 55.000000000000000 },
  { -0.055618147270528003, 0.33333333333333331, 60.000000000000000 },
  { 0.064711954014113948, 0.33333333333333331, 65.000000000000000 },
  { 0.086879926462481605, 0.33333333333333331, 70.000000000000000 },
  { -0.012614484229891068, 0.33333333333333331, 75.000000000000000 },
  { -0.088199784400034537, 0.33333333333333331, 80.000000000000000 },
  { -0.036703611076564523, 0.33333333333333331, 85.000000000000000 },
  { 0.062916286828779547, 0.33333333333333331, 90.000000000000000 },
  { 0.069465244416806030, 0.33333333333333331, 95.000000000000000 },
  { -0.021271244853702364, 0.33333333333333331, 100.00000000000000 },
};
const double toler011 = 2.5000000000000017e-10;

// Test data for nu=0.50000000000000000.
// max(|f - f_GSL|): 7.4246164771807344e-15
// max(|f - f_GSL| / |f_GSL|): 3.6725252809051799e-13
const testcase_cyl_bessel_j<double>
data012[21] =
{
  { 0.0000000000000000, 0.50000000000000000, 0.0000000000000000 },
  { -0.34216798479816180, 0.50000000000000000, 5.0000000000000000 },
  { -0.13726373575505049, 0.50000000000000000, 10.000000000000000 },
  { 0.13396768882243937, 0.50000000000000000, 15.000000000000000 },
  { 0.16288076385502984, 0.50000000000000000, 20.000000000000000 },
  { -0.021120283599650493, 0.50000000000000000, 25.000000000000000 },
  { -0.14392965337039987, 0.50000000000000000, 30.000000000000000 },
  { -0.057747757589458777, 0.50000000000000000, 35.000000000000000 },
  { 0.094000962389533649, 0.50000000000000000, 40.000000000000000 },
  { 0.10120783324271411, 0.50000000000000000, 45.000000000000000 },
  { -0.029605831888924641, 0.50000000000000000, 50.000000000000000 },
  { -0.10756039213265806, 0.50000000000000000, 55.000000000000000 },
  { -0.031397461182520438, 0.50000000000000000, 60.000000000000000 },
  { 0.081827430775628554, 0.50000000000000000, 65.000000000000000 },
  { 0.073802429539054554, 0.50000000000000000, 70.000000000000000 },
  { -0.035727009681702615, 0.50000000000000000, 75.000000000000000 },
  { -0.088661035811765460, 0.50000000000000000, 80.000000000000000 },
  { -0.015238065106312516, 0.50000000000000000, 85.000000000000000 },
  { 0.075189068550269425, 0.50000000000000000, 90.000000000000000 },
  { 0.055932643481494133, 0.50000000000000000, 95.000000000000000 },
  { -0.040402132716252127, 0.50000000000000000, 100.00000000000000 },
};
const double toler012 = 2.5000000000000014e-11;

// Test data for nu=0.66666666666666663.
// max(|f - f_GSL|): 6.3629657098829284e-15
// max(|f - f_GSL| / |f_GSL|): 1.2254869540384518e-12
const testcase_cyl_bessel_j<double>
data013[21] =
{
  { 0.0000000000000000, 0.66666666666666663, 0.0000000000000000 },
  { -0.35712533549168868, 0.66666666666666663, 5.0000000000000000 },
  { -0.080149603304315808, 0.66666666666666663, 10.000000000000000 },
  { 0.16918875175798079, 0.66666666666666663, 15.000000000000000 },
  { 0.13904826122116531, 0.66666666666666663, 20.000000000000000 },
  { -0.060770629698497600, 0.66666666666666663, 25.000000000000000 },
  { -0.14489851974205062, 0.66666666666666663, 30.000000000000000 },
  { -0.024604880159644394, 0.66666666666666663, 35.000000000000000 },
  { 0.11243936464912010, 0.66666666666666663, 40.000000000000000 },
  { 0.081776275512525309, 0.66666666666666663, 45.000000000000000 },
  { -0.056589908749367777, 0.66666666666666663, 50.000000000000000 },
  { -0.10455814523765931, 0.66666666666666663, 55.000000000000000 },
  { -0.0051030148548608456, 0.66666666666666663, 60.000000000000000 },
  { 0.093398227061639236, 0.66666666666666663, 65.000000000000000 },
  { 0.055763883611864913, 0.66666666666666663, 70.000000000000000 },
  { -0.056395322915757364, 0.66666666666666663, 75.000000000000000 },
  { -0.083131347805783087, 0.66666666666666663, 80.000000000000000 },
  { 0.0072315397874096648, 0.66666666666666663, 85.000000000000000 },
  { 0.082362798520905250, 0.66666666666666663, 90.000000000000000 },
  { 0.038630504403446168, 0.66666666666666663, 95.000000000000000 },
  { -0.056778819380529734, 0.66666666666666663, 100.00000000000000 },
};
const double toler013 = 1.0000000000000006e-10;

// Test data for nu=1.0000000000000000.
// max(|f - f_GSL|): 7.1435912740724916e-15
// max(|f - f_GSL| / |f_GSL|): 1.7857949645087573e-12
const testcase_cyl_bessel_j<double>
data014[21] =
{
  { 0.0000000000000000, 1.0000000000000000, 0.0000000000000000 },
  { -0.32757913759146529, 1.0000000000000000, 5.0000000000000000 },
  { 0.043472746168861459, 1.0000000000000000, 10.000000000000000 },
  { 0.20510403861352280, 1.0000000000000000, 15.000000000000000 },
  { 0.066833124175850078, 1.0000000000000000, 20.000000000000000 },
  { -0.12535024958028990, 1.0000000000000000, 25.000000000000000 },
  { -0.11875106261662294, 1.0000000000000000, 30.000000000000000 },
  { 0.043990942179625646, 1.0000000000000000, 35.000000000000000 },
  { 0.12603831803758500, 1.0000000000000000, 40.000000000000000 },
  { 0.028348854376424561, 1.0000000000000000, 45.000000000000000 },
  { -0.097511828125175129, 1.0000000000000000, 50.000000000000000 },
  { -0.078250038308684711, 1.0000000000000000, 55.000000000000000 },
  { 0.046598383758166370, 1.0000000000000000, 60.000000000000000 },
  { 0.097330172226126929, 1.0000000000000000, 65.000000000000000 },
  { 0.0099877887848385128, 1.0000000000000000, 70.000000000000000 },
  { -0.085139995044829081, 1.0000000000000000, 75.000000000000000 },
  { -0.056057296675712555, 1.0000000000000000, 80.000000000000000 },
  { 0.049151460334891130, 1.0000000000000000, 85.000000000000000 },
  { 0.079925646708868092, 1.0000000000000000, 90.000000000000000 },
  { -0.0023925612997269283, 1.0000000000000000, 95.000000000000000 },
  { -0.077145352014112129, 1.0000000000000000, 100.00000000000000 },
};
const double toler014 = 1.0000000000000006e-10;

// Test data for nu=2.0000000000000000.
// max(|f - f_GSL|): 7.6050277186823223e-15
// max(|f - f_GSL| / |f_GSL|): 2.0010877493528614e-12
const testcase_cyl_bessel_j<double>
data015[21] =
{
  { 0.0000000000000000, 2.0000000000000000, 0.0000000000000000 },
  { 0.046565116277751971, 2.0000000000000000, 5.0000000000000000 },
  { 0.25463031368512068, 2.0000000000000000, 10.000000000000000 },
  { 0.041571677975250486, 2.0000000000000000, 15.000000000000000 },
  { -0.16034135192299820, 2.0000000000000000, 20.000000000000000 },
  { -0.10629480324238134, 2.0000000000000000, 25.000000000000000 },
  { 0.078451246073265299, 2.0000000000000000, 30.000000000000000 },
  { 0.12935945088086259, 2.0000000000000000, 35.000000000000000 },
  { -0.0010649746823579794, 2.0000000000000000, 40.000000000000000 },
  { -0.11455872158985966, 2.0000000000000000, 45.000000000000000 },
  { -0.059712800794258863, 2.0000000000000000, 50.000000000000000 },
  { 0.071702846709739240, 2.0000000000000000, 55.000000000000000 },
  { 0.093025083547667420, 2.0000000000000000, 60.000000000000000 },
  { -0.015692568697643128, 2.0000000000000000, 65.000000000000000 },
  { -0.094623361089161029, 2.0000000000000000, 70.000000000000000 },
  { -0.036914313672959179, 2.0000000000000000, 75.000000000000000 },
  { 0.068340733095317172, 2.0000000000000000, 80.000000000000000 },
  { 0.072096899745329540, 2.0000000000000000, 85.000000000000000 },
  { -0.024853891217550248, 2.0000000000000000, 90.000000000000000 },
  { -0.081862337494957332, 2.0000000000000000, 95.000000000000000 },
  { -0.021528757344505364, 2.0000000000000000, 100.00000000000000 },
};
const double toler015 = 2.5000000000000017e-10;

// Test data for nu=5.0000000000000000.
// max(|f - f_GSL|): 6.8521577301083880e-15
// max(|f - f_GSL| / |f_GSL|): 5.6813560677959848e-13
const testcase_cyl_bessel_j<double>
data016[21] =
{
  { 0.0000000000000000, 5.0000000000000000, 0.0000000000000000 },
  { 0.26114054612017007, 5.0000000000000000, 5.0000000000000000 },
  { -0.23406152818679371, 5.0000000000000000, 10.000000000000000 },
  { 0.13045613456502966, 5.0000000000000000, 15.000000000000000 },
  { 0.15116976798239498, 5.0000000000000000, 20.000000000000000 },
  { -0.066007995398422933, 5.0000000000000000, 25.000000000000000 },
  { -0.14324029551207709, 5.0000000000000000, 30.000000000000000 },
  { -0.0015053072953907251, 5.0000000000000000, 35.000000000000000 },
  { 0.12257346597711777, 5.0000000000000000, 40.000000000000000 },
  { 0.057984499200954109, 5.0000000000000000, 45.000000000000000 },
  { -0.081400247696569616, 5.0000000000000000, 50.000000000000000 },
  { -0.092569895786432765, 5.0000000000000000, 55.000000000000000 },
  { 0.027454744228344204, 5.0000000000000000, 60.000000000000000 },
  { 0.099110527701539025, 5.0000000000000000, 65.000000000000000 },
  { 0.026058129823895364, 5.0000000000000000, 70.000000000000000 },
  { -0.078523977013751398, 5.0000000000000000, 75.000000000000000 },
  { -0.065862349140031584, 5.0000000000000000, 80.000000000000000 },
  { 0.038669072284680979, 5.0000000000000000, 85.000000000000000 },
  { 0.082759319528415157, 5.0000000000000000, 90.000000000000000 },
  { 0.0079423372702472871, 5.0000000000000000, 95.000000000000000 },
  { -0.074195736964513898, 5.0000000000000000, 100.00000000000000 },
};
const double toler016 = 5.0000000000000028e-11;

// Test data for nu=10.000000000000000.
// max(|f - f_GSL|): 7.2303274478713320e-15
// max(|f - f_GSL| / |f_GSL|): 3.6974790630140835e-13
const testcase_cyl_bessel_j<double>
data017[21] =
{
  { 0.0000000000000000, 10.000000000000000, 0.0000000000000000 },
  { 0.0014678026473104744, 10.000000000000000, 5.0000000000000000 },
  { 0.20748610663335865, 10.000000000000000, 10.000000000000000 },
  { -0.090071811047659087, 10.000000000000000, 15.000000000000000 },
  { 0.18648255802394512, 10.000000000000000, 20.000000000000000 },
  { -0.075179843948523312, 10.000000000000000, 25.000000000000000 },
  { -0.12987689399858882, 10.000000000000000, 30.000000000000000 },
  { 0.063546391343962866, 10.000000000000000, 35.000000000000000 },
  { 0.11938336278226094, 10.000000000000000, 40.000000000000000 },
  { -0.026971402475010831, 10.000000000000000, 45.000000000000000 },
  { -0.11384784914946940, 10.000000000000000, 50.000000000000000 },
  { -0.015773790303746080, 10.000000000000000, 55.000000000000000 },
  { 0.097177143328071064, 10.000000000000000, 60.000000000000000 },
  { 0.054617389951112129, 10.000000000000000, 65.000000000000000 },
  { -0.065870338561952013, 10.000000000000000, 70.000000000000000 },
  { -0.080417867891894437, 10.000000000000000, 75.000000000000000 },
  { 0.024043850978184747, 10.000000000000000, 80.000000000000000 },
  { 0.086824832700067869, 10.000000000000000, 85.000000000000000 },
  { 0.019554748856312299, 10.000000000000000, 90.000000000000000 },
  { -0.072341598669443757, 10.000000000000000, 95.000000000000000 },
  { -0.054732176935472096, 10.000000000000000, 100.00000000000000 },
};
const double toler017 = 2.5000000000000014e-11;

// Test data for nu=20.000000000000000.
// max(|f - f_GSL|): 7.7177847446208148e-15
// max(|f - f_GSL| / |f_GSL|): 1.1191513260854523e-12
const testcase_cyl_bessel_j<double>
data018[21] =
{
  { 0.0000000000000000, 20.000000000000000, 0.0000000000000000 },
  { 2.7703300521289426e-11, 20.000000000000000, 5.0000000000000000 },
  { 1.1513369247813403e-05, 20.000000000000000, 10.000000000000000 },
  { 0.0073602340792234934, 20.000000000000000, 15.000000000000000 },
  { 0.16474777377532665, 20.000000000000000, 20.000000000000000 },
  { 0.051994049228303307, 20.000000000000000, 25.000000000000000 },
  { 0.0048310199934040923, 20.000000000000000, 30.000000000000000 },
  { -0.10927417397178038, 20.000000000000000, 35.000000000000000 },
  { 0.12779393355084889, 20.000000000000000, 40.000000000000000 },
  { 0.0047633437900313621, 20.000000000000000, 45.000000000000000 },
  { -0.11670435275957974, 20.000000000000000, 50.000000000000000 },
  { 0.025389204574566639, 20.000000000000000, 55.000000000000000 },
  { 0.10266020557876326, 20.000000000000000, 60.000000000000000 },
  { -0.023138582263434154, 20.000000000000000, 65.000000000000000 },
  { -0.096058573489952365, 20.000000000000000, 70.000000000000000 },
  { 0.0068961047221522270, 20.000000000000000, 75.000000000000000 },
  { 0.090565405489918357, 20.000000000000000, 80.000000000000000 },
  { 0.015985497599497172, 20.000000000000000, 85.000000000000000 },
  { -0.080345344044422534, 20.000000000000000, 90.000000000000000 },
  { -0.040253075701614051, 20.000000000000000, 95.000000000000000 },
  { 0.062217458498338672, 20.000000000000000, 100.00000000000000 },
};
const double toler018 = 1.0000000000000006e-10;

// Test data for nu=50.000000000000000.
// max(|f - f_GSL|): 6.6543992538470320e-15
// max(|f - f_GSL| / |f_GSL|): 1.6466369526724007e-13
const testcase_cyl_bessel_j<double>
data019[21] =
{
  { 0.0000000000000000, 50.000000000000000, 0.0000000000000000 },
  { 2.2942476159525415e-45, 50.000000000000000, 5.0000000000000000 },
  { 1.7845136078715964e-30, 50.000000000000000, 10.000000000000000 },
  { 6.1060519495338733e-22, 50.000000000000000, 15.000000000000000 },
  { 4.4510392847006872e-16, 50.000000000000000, 20.000000000000000 },
  { 9.7561594280229808e-12, 50.000000000000000, 25.000000000000000 },
  { 2.0581656631564172e-08, 50.000000000000000, 30.000000000000000 },
  { 7.6069951699272960e-06, 50.000000000000000, 35.000000000000000 },
  { 0.00068185243531768309, 50.000000000000000, 40.000000000000000 },
  { 0.017284343240791214, 50.000000000000000, 45.000000000000000 },
  { 0.12140902189761507, 50.000000000000000, 50.000000000000000 },
  { 0.13594720957176012, 50.000000000000000, 55.000000000000000 },
  { -0.13798273148535209, 50.000000000000000, 60.000000000000000 },
  { 0.12116217746619409, 50.000000000000000, 65.000000000000000 },
  { -0.11394866738787145, 50.000000000000000, 70.000000000000000 },
  { 0.094076799581573348, 50.000000000000000, 75.000000000000000 },
  { -0.039457764590251347, 50.000000000000000, 80.000000000000000 },
  { -0.040412060734136383, 50.000000000000000, 85.000000000000000 },
  { 0.090802099838032266, 50.000000000000000, 90.000000000000000 },
  { -0.055979156267280165, 50.000000000000000, 95.000000000000000 },
  { -0.038698339728525440, 50.000000000000000, 100.00000000000000 },
};
const double toler019 = 1.0000000000000006e-11;

// Test data for nu=100.00000000000000.
// max(|f - f_GSL|): 4.8138576458356397e-17
// max(|f - f_GSL| / |f_GSL|): 1.0835289187603112e-13
const testcase_cyl_bessel_j<double>
data020[21] =
{
  { 0.0000000000000000, 100.00000000000000, 0.0000000000000000 },
  { 6.2677893955418763e-119, 100.00000000000000, 5.0000000000000000 },
  { 6.5973160641553816e-89, 100.00000000000000, 10.000000000000000 },
  { 1.9660095611249536e-71, 100.00000000000000, 15.000000000000000 },
  { 3.9617550943362524e-59, 100.00000000000000, 20.000000000000000 },
  { 1.1064482655301687e-49, 100.00000000000000, 25.000000000000000 },
  { 4.5788015281752354e-42, 100.00000000000000, 30.000000000000000 },
  { 9.9210206714732606e-36, 100.00000000000000, 35.000000000000000 },
  { 2.3866062996027414e-30, 100.00000000000000, 40.000000000000000 },
  { 1.0329791804565538e-25, 100.00000000000000, 45.000000000000000 },
  { 1.1159273690838340e-21, 100.00000000000000, 50.000000000000000 },
  { 3.7899753451900682e-18, 100.00000000000000, 55.000000000000000 },
  { 4.7832744078781205e-15, 100.00000000000000, 60.000000000000000 },
  { 2.5375564579490517e-12, 100.00000000000000, 65.000000000000000 },
  { 6.1982452141641260e-10, 100.00000000000000, 70.000000000000000 },
  { 7.4479005905904457e-08, 100.00000000000000, 75.000000000000000 },
  { 4.6065530648234948e-06, 100.00000000000000, 80.000000000000000 },
  { 0.00015043869999501765, 100.00000000000000, 85.000000000000000 },
  { 0.0026021305819963472, 100.00000000000000, 90.000000000000000 },
  { 0.023150768009428030, 100.00000000000000, 95.000000000000000 },
  { 0.096366673295861571, 100.00000000000000, 100.00000000000000 },
};
const double toler020 = 1.0000000000000006e-11;

template<typename Tp, unsigned int Num>
  void
  test(const testcase_cyl_bessel_j<Tp> (&data)[Num], Tp toler)
  {
    const Tp eps = std::numeric_limits<Tp>::epsilon();
    Tp max_abs_diff = -Tp(1);
    Tp max_abs_frac = -Tp(1);
    unsigned int num_datum = Num;
    for (unsigned int i = 0; i < num_datum; ++i)
      {
	const Tp f = std::cyl_bessel_j(data[i].nu, data[i].x);
	const Tp f0 = data[i].f0;
	const Tp diff = f - f0;
	if (std::abs(diff) > max_abs_diff)
	  max_abs_diff = std::abs(diff);
	if (std::abs(f0) > Tp(10) * eps
	 && std::abs(f) > Tp(10) * eps)
	  {
	    const Tp frac = diff / f0;
	    if (std::abs(frac) > max_abs_frac)
	      max_abs_frac = std::abs(frac);
	  }
      }
    VERIFY(max_abs_frac < toler);
  }

int
main()
{
  test(data001, toler001);
  test(data002, toler002);
  test(data003, toler003);
  test(data004, toler004);
  test(data005, toler005);
  test(data006, toler006);
  test(data007, toler007);
  test(data008, toler008);
  test(data009, toler009);
  test(data010, toler010);
  test(data011, toler011);
  test(data012, toler012);
  test(data013, toler013);
  test(data014, toler014);
  test(data015, toler015);
  test(data016, toler016);
  test(data017, toler017);
  test(data018, toler018);
  test(data019, toler019);
  test(data020, toler020);
  return 0;
}