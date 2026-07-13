/**
 * Author: Tanya
 * Description: 
 */
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
ordered_set<int> st;
//st.order_of_key(x) - find # of elements in st stricly less than x, i.e. index of x
//st.size() - size of st
//st.find_by_order(x) - return iterator point to xth indexed element
//st.clear() - clear container
