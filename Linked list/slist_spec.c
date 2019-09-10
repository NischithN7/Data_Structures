#include <assert.h>
#include "slist.h"

void test_empty_list()
{
	Slist s = slist_new();
	Slist *list = &s;

	assert (slist_length(list) == 0);
}

void test_addition_at_head()
{
    Slist s = slist_new();
	Slist *list = &s;
	Slist s2 = slist_new();
	Slist *list1 = &s2;
	Slist s3 = slist_new();
	Slist *list2 = &s3;
	Slist s4=slist_new();
	Slist *list3=&s4;
	list = slist_add_head(list, 13);
	assert (slist_length(list) == 1);

	list = slist_add_head(list, 26);
	list = slist_add_head(list, 35);
	list = slist_add_head(list, 49);
	list = slist_add_head(list, 56);
	list = slist_add_head(list, 75);
	list = slist_add_tail(list, 89);

	list1 = slist_add_head(list1, 21);
	list1 = slist_add_head(list1, 37);
	list1 = slist_add_head(list1, 42);
	list2 = slist_add_head(list2, 25);
	list2 = slist_add_head(list2, 39);
	list2 = slist_add_head(list2, 11);
	//assert(list_compare(list1,list2)==1);


	assert (slist_length(list) == 7);
	assert (slist_lookup(list, 49));
	assert (slist_min(list) == 13);
	assert (slist_max(list) == 89);
	list = slist_delete_head(list);
	list = slist_delete_tail(list);
	slist_display(list);
	list = slist_spec_ele(list,100,26);
	list = slist_spec_ele_delete(list,35);
	slist_display(list);
	reverse_list(list);
	slist_display(list);
	list3 = union_list(list3,list1,list2);
	slist_display(list3);

}

int main()
{
	test_empty_list();
	test_addition_at_head();
	return 0;
}
//gcc slist.c slist_spec.c -o slist
/*
 *	Running your programs. Assume that already you have
 *	'slist.h', 'slist.c' and 'slist_spec.c' files.
 *
 *	gcc slist.c slist_spec.c -o slist
 *
 *	If you get errors, fix them. Otherwise you have exe file
 *	with name 'slist' (due to -o slist option used during compilation)
 *
 *	Running exe file:	./a.out slist
 *	If you don't get any message in terminal, code executed perfectly
 *	( No news good news!!!!!!!)
 *
*/
