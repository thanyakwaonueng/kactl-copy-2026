/**
 * Author: Tanya
 * Description: random pragma magic that I don't fucking know how this work, but it ocassionaly solve my stupid bad implementation code in the past(segtree constant factor), this should not be mandatory and only last resort
 */
//some one on cf told us that these are mostly enough
#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
//just in case have this one
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
