/*
   +----------------------------------------------------------------------+
   | PHP Version 7														|
   +----------------------------------------------------------------------+
   | Copyright (c) 1997-2015 The PHP Group								|
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,	  |
   | that is bundled with this package in the file LICENSE, and is		|
   | available through the world-wide-web at the following url:		   |
   | http://www.php.net/license/3_01.txt								  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to		  |
   | license@php.net so we can mail you a copy immediately.			   |
   +----------------------------------------------------------------------+
   | Author: Grégory Planchat <gregory@luni.fr>						   |
   +----------------------------------------------------------------------+
 */

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <math.h>

#include "php.h"
#include "ext/spl/spl_iterators.h"
#include "ext/standard/info.h"
#include "zend_objects.h"
#include "zend_interfaces.h"
#include "zend_types.h"
#include "zend_exceptions.h"

#include "php_sortable.h"

#include "../mutagen/mutagen.h"

#ifdef COMPILE_DL_SORTABLE
ZEND_GET_MODULE(sortable)
#endif

zval* sortable_call_method(zval *object, zend_class_entry *obj_ce, zend_function **fn_proxy,
	const char *function_name, size_t function_name_len, int param_count, zval *retval_ptr, ...);

static zend_object_handlers sortable_handlers;

MUTAGEN_CLASS(Spl, Sortable);

MUTAGEN_CLASS(Spl, SortableCollection);

MUTAGEN_CLASS(Spl, BidirectionalSeekableIterator);

MUTAGEN_CLASS(Spl, Sorter);

MUTAGEN_CLASS(Spl, CollectionSorter);

MUTAGEN_CLASS(Spl, BidirectionalSeekableArrayIterator);

MUTAGEN_CLASS(Spl, ArraySorter);

MUTAGEN_METHOD_DEF_START(Spl, SortableCollection, swap, 2)
	MUTAGEN_METHOD_PARAM_OBJECT_OF_CLASS(leftKey, MUTAGEN_CLASS_REF(Spl, BidirectionalSeekableIterator), 0)
	MUTAGEN_METHOD_PARAM_OBJECT_OF_CLASS(rightKey, MUTAGEN_CLASS_REF(Spl, BidirectionalSeekableIterator), 0)
MUTAGEN_METHOD_DEF_END()

MUTAGEN_METHOD_DEF_START(Spl, BidirectionalSeekableIterator, distance, 1)
	MUTAGEN_METHOD_PARAM_OBJECT_OF_CLASS(friend, MUTAGEN_CLASS_REF(Spl, BidirectionalSeekableIterator), 0)
MUTAGEN_METHOD_DEF_END()

MUTAGEN_METHOD_DEF_START(Spl, BidirectionalSeekableIterator, previous, 0)
	MUTAGEN_METHOD_PARAM_LONG(offset, 0)
MUTAGEN_METHOD_DEF_END()

MUTAGEN_METHOD_DEF_START(Spl, BidirectionalSeekableIterator, next, 0)
	MUTAGEN_METHOD_PARAM_LONG(offset, 0)
MUTAGEN_METHOD_DEF_END()

MUTAGEN_METHOD_DEF_START(Spl, BidirectionalSeekableIterator, seek, 1)
	MUTAGEN_METHOD_PARAM_LONG(position, 0)
MUTAGEN_METHOD_DEF_END()

MUTAGEN_METHOD_DEF_START(Spl, Sorter, sort, 1)
	MUTAGEN_METHOD_PARAM_ARRAY_OR_OBJECT(collection, 0)
MUTAGEN_METHOD_DEF_END()

MUTAGEN_METHOD_DEF_START(Spl, Sorter, compare, 2)
	MUTAGEN_METHOD_PARAM_OBJECT_OF_CLASS(left, MUTAGEN_CLASS_REF(Spl, BidirectionalSeekableIterator), 0)
	MUTAGEN_METHOD_PARAM_OBJECT_OF_CLASS(right, MUTAGEN_CLASS_REF(Spl, BidirectionalSeekableIterator), 0)
MUTAGEN_METHOD_DEF_END()

MUTAGEN_METHOD_DEF_START(Spl, CollectionSorter, quickSort, 3)
	MUTAGEN_METHOD_PARAM_OBJECT_OF_CLASS(collection, MUTAGEN_CLASS_REF(Spl, SortableCollection), 0)
	MUTAGEN_METHOD_PARAM_OBJECT_OF_CLASS(first, MUTAGEN_CLASS_REF(Spl, BidirectionalSeekableIterator), 0)
	MUTAGEN_METHOD_PARAM_OBJECT_OF_CLASS(last, MUTAGEN_CLASS_REF(Spl, BidirectionalSeekableIterator), 0)
MUTAGEN_METHOD_DEF_END()

MUTAGEN_METHOD_DEF_START(Spl, CollectionSorter, partition, 3)
	MUTAGEN_METHOD_PARAM_OBJECT_OF_CLASS(collection, MUTAGEN_CLASS_REF(Spl, SortableCollection), 0)
	MUTAGEN_METHOD_PARAM_OBJECT_OF_CLASS(first, MUTAGEN_CLASS_REF(Spl, BidirectionalSeekableIterator), 0)
	MUTAGEN_METHOD_PARAM_OBJECT_OF_CLASS(last, MUTAGEN_CLASS_REF(Spl, BidirectionalSeekableIterator), 0)
MUTAGEN_METHOD_DEF_END()

MUTAGEN_METHOD_DEF_START(Spl, BidirectionalSeekableArrayIterator, __construct, 1)
	MUTAGEN_METHOD_PARAM_ARRAY(subject, 0)
MUTAGEN_METHOD_DEF_END()

MUTAGEN_METHOD_DEF_START(Spl, BidirectionalSeekableArrayIterator, distance, 1)
	MUTAGEN_METHOD_PARAM_OBJECT_OF_CLASS(friend, MUTAGEN_CLASS_REF(Spl, BidirectionalSeekableIterator), 0)
MUTAGEN_METHOD_DEF_END()

MUTAGEN_METHOD_DEF_START(Spl, BidirectionalSeekableArrayIterator, previous, 0)
	MUTAGEN_METHOD_PARAM_LONG(offset, 0)
MUTAGEN_METHOD_DEF_END()

MUTAGEN_METHOD_DEF_START(Spl, BidirectionalSeekableArrayIterator, next, 0)
	MUTAGEN_METHOD_PARAM_LONG(offset, 0)
MUTAGEN_METHOD_DEF_END()

MUTAGEN_METHOD_DEF_START(Spl, BidirectionalSeekableArrayIterator, seek, 1)
	MUTAGEN_METHOD_PARAM_LONG(position, 0)
MUTAGEN_METHOD_DEF_END()

MUTAGEN_METHOD_DEF_START(Spl, ArraySorter, sort, 1)
	MUTAGEN_METHOD_PARAM_ARRAY(collection, 0)
MUTAGEN_METHOD_DEF_END()

MUTAGEN_METHOD_DEF_START(Spl, ArraySorter, quickSort, 3)
	MUTAGEN_METHOD_PARAM_ARRAY(collection, 0)
	MUTAGEN_METHOD_PARAM_OBJECT_OF_CLASS(first, MUTAGEN_CLASS_REF(Spl, BidirectionalSeekableIterator), 0)
	MUTAGEN_METHOD_PARAM_OBJECT_OF_CLASS(last, MUTAGEN_CLASS_REF(Spl, BidirectionalSeekableIterator), 0)
MUTAGEN_METHOD_DEF_END()

MUTAGEN_METHOD_DEF_START(Spl, ArraySorter, partition, 3)
	MUTAGEN_METHOD_PARAM_ARRAY(collection, 0)
	MUTAGEN_METHOD_PARAM_OBJECT_OF_CLASS(first, MUTAGEN_CLASS_REF(Spl, BidirectionalSeekableIterator), 0)
	MUTAGEN_METHOD_PARAM_OBJECT_OF_CLASS(last, MUTAGEN_CLASS_REF(Spl, BidirectionalSeekableIterator), 0)
MUTAGEN_METHOD_DEF_END()

MUTAGEN_METHOD_DEF_START(Spl, ArraySorter, compare, 2)
	MUTAGEN_METHOD_PARAM_OBJECT_OF_CLASS(left, MUTAGEN_CLASS_REF(Spl, BidirectionalSeekableIterator), 0)
	MUTAGEN_METHOD_PARAM_OBJECT_OF_CLASS(right, MUTAGEN_CLASS_REF(Spl, BidirectionalSeekableIterator), 0)
MUTAGEN_METHOD_DEF_END()

/* {{{ proto mixed CollectionSorter::sort(
   SortableCollection $collection
) */
ZEND_METHOD(CollectionSorter, sort)
{
	zval* param_collection_obj;

#ifndef FAST_ZPP
	if (zend_parse_method_parameters(ZEND_NUM_ARGS(), getThis(), "O", &param_collection_obj,
		MUTAGEN_CLASS_ENTRY(Spl, SortableCollection)) == FAILURE) {
		RETURN_NULL();
	}
#else
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT(param_collection_obj)
	ZEND_PARSE_PARAMETERS_END();
#endif
	zval first, last;
	zend_class_entry *param_collection_ce = Z_OBJCE_P(param_collection_obj);
	zend_class_entry *ce = Z_OBJCE_P(getThis());

	sortable_call_method(param_collection_obj, param_collection_ce, NULL, "first", sizeof("first") - 1, 0, &first);
	sortable_call_method(param_collection_obj, param_collection_ce, NULL, "last", sizeof("last") - 1, 0, &last);

	sortable_call_method(getThis(), ce, NULL, "quicksort", sizeof("quicksort") - 1, 3, NULL,
		param_collection_obj, &first, &last);
}
/* }}} */

/* {{{ proto mixed CollectionSorter::quickSort(
   SortableCollection $collection,
   BidirectionalSeekableIterator $first,
   BidirectionalSeekableIterator $last
) */
ZEND_METHOD(CollectionSorter, quickSort)
{
	zval* param_collection_obj;
	zval* param_first_obj;
	zval* param_last_obj;

#ifndef FAST_ZPP
	if (zend_parse_method_parameters(ZEND_NUM_ARGS(), getThis(), "OOO", &param_collection_obj,
		MUTAGEN_CLASS_ENTRY(Spl, SortableCollection), &param_first_obj, MUTAGEN_CLASS_ENTRY(Spl, BidirectionalSeekableIterator),
		&param_last_obj, MUTAGEN_CLASS_ENTRY(Spl, BidirectionalSeekableIterator)) == FAILURE) {
		RETURN_NULL();
	}
#else
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(param_collection_obj, MUTAGEN_CLASS_ENTRY(Spl, SortableCollection))
		Z_PARAM_OBJECT_OF_CLASS(param_first_obj, MUTAGEN_CLASS_ENTRY(Spl, BidirectionalSeekableIterator))
		Z_PARAM_OBJECT(param_last_obj)
	ZEND_PARSE_PARAMETERS_END();
#endif

	zend_object *tmpobj;
	zend_class_entry *this_ce = Z_OBJCE_P(getThis());
	zend_class_entry *tmp_ce;
	zend_class_entry *param_collection_ce = Z_OBJCE_P(param_collection_obj);
	zend_class_entry *param_first_ce = Z_OBJCE_P(param_first_obj);
	zend_class_entry *param_last_ce = Z_OBJCE_P(param_last_obj);

	zval distance, comparison, pivot, tmp;

	sortable_call_method(param_first_obj, param_first_ce, NULL, "distance", sizeof("distance") - 1, 1, &distance, param_last_obj);

	if (Z_LVAL(distance) <= 0) {
		return;
	}

	sortable_call_method(getThis(), this_ce, NULL, "partition", sizeof("partition") - 1, 3, &pivot,
		param_collection_obj, param_first_obj, param_last_obj);

	tmpobj = zend_objects_clone_obj(&pivot);
	ZVAL_OBJ(&tmp, tmpobj);
	tmp_ce = Z_OBJCE(tmp);

	sortable_call_method(param_first_obj, param_first_ce, NULL, "distance", sizeof("distance") - 1, 1, &distance, &tmp);
	if (Z_LVAL(distance) > 1) {
		sortable_call_method(&tmp, tmp_ce, NULL, "previous", sizeof("previous") - 1, 0, NULL);

		sortable_call_method(getThis(), this_ce, NULL, "quicksort", sizeof("quicksort") - 1, 3, NULL,
			param_collection_obj, param_first_obj, &tmp);
	} else {
		sortable_call_method(getThis(), this_ce, NULL, "compare", sizeof("compare") - 1, 2, &comparison, &pivot, param_first_obj);
		if (Z_LVAL(comparison)) {
			sortable_call_method(param_collection_obj, param_collection_ce, NULL, "swap", sizeof("swap") - 1, 2, NULL, &pivot, param_first_obj);
		}
	}

	tmpobj = zend_objects_clone_obj(&pivot);
	ZVAL_OBJ(&tmp, tmpobj);
	tmp_ce = Z_OBJCE(tmp);

	sortable_call_method(&tmp, tmp_ce, NULL, "distance", sizeof("distance") - 1, 1, &distance, param_last_obj);
	if (Z_LVAL(distance) > 1) {
		sortable_call_method(&tmp, tmp_ce, NULL, "next", sizeof("next") - 1, 0, NULL);

		sortable_call_method(getThis(), this_ce, NULL, "quicksort", sizeof("quicksort") - 1, 3, NULL,
			param_collection_obj, &tmp, param_last_obj);
	} else {
		sortable_call_method(getThis(), this_ce, NULL, "compare", sizeof("compare") - 1, 2, &comparison, &pivot, param_last_obj);
		if (Z_LVAL(comparison)) {
			sortable_call_method(param_collection_obj, param_collection_ce, NULL, "swap", sizeof("swap") - 1, 2, NULL, param_last_obj, &pivot);
		}
	}
}
/* }}} */

/* {{{ proto mixed CollectionSorter::partition(
   SortableCollection $collection,
   BidirectionalSeekableIterator $first,
   BidirectionalSeekableIterator $last
) */
ZEND_METHOD(CollectionSorter, partition)
{
	zval* param_collection_obj;
	zval* param_first_obj;
	zval* param_last_obj;

#ifndef FAST_ZPP
	if (zend_parse_method_parameters(ZEND_NUM_ARGS(), getThis(), "OOO", &param_collection_obj,
		MUTAGEN_CLASS_ENTRY(Spl, SortableCollection), &param_first_obj, MUTAGEN_CLASS_ENTRY(Spl, BidirectionalSeekableIterator),
		&param_last_obj, MUTAGEN_CLASS_ENTRY(Spl, BidirectionalSeekableIterator)) == FAILURE) {
		RETURN_NULL();
	}
#else
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(param_collection_obj, MUTAGEN_CLASS_ENTRY(Spl, SortableCollection))
		Z_PARAM_OBJECT_OF_CLASS(param_first_obj, MUTAGEN_CLASS_ENTRY(Spl, BidirectionalSeekableIterator))
		Z_PARAM_OBJECT_OF_CLASS(param_last_obj, MUTAGEN_CLASS_ENTRY(Spl, BidirectionalSeekableIterator))
	ZEND_PARSE_PARAMETERS_END();
#endif

	zend_class_entry *param_collection_ce = Z_OBJCE_P(param_collection_obj);
	zend_class_entry *param_first_ce = Z_OBJCE_P(param_first_obj);
	zend_class_entry *param_last_ce = Z_OBJCE_P(param_last_obj);

	zend_object *pivotobj, *wallobj, *iteratorobj;
	zend_class_entry *this_ce = Z_OBJCE_P(getThis());
	zend_class_entry *pivot_ce, *wall_ce, *iterator_ce;
	zval pivot, wall, iterator, distance, half, comparison;

	pivotobj = zend_objects_clone_obj(param_first_obj);
	ZVAL_OBJ(&pivot, pivotobj);
	pivot_ce = Z_OBJCE(pivot);

	sortable_call_method(param_first_obj, param_first_ce, NULL, "distance", sizeof("distance") - 1, 1, &distance, param_last_obj);
	ZVAL_LONG(&half, ceil(Z_LVAL(distance) / 2.));

	sortable_call_method(&pivot, pivot_ce, NULL, "next", sizeof("next") - 1, 1, NULL, &half);

	sortable_call_method(param_collection_obj, param_collection_ce, NULL, "swap", sizeof("swap") - 1, 2, NULL,
		&pivot, param_last_obj);

	wallobj = zend_objects_clone_obj(param_first_obj);
	ZVAL_OBJ(&wall, wallobj);
	wall_ce = Z_OBJCE(wall);

	iteratorobj = zend_objects_clone_obj(param_first_obj);
	ZVAL_OBJ(&iterator, iteratorobj);
	iterator_ce = Z_OBJCE(iterator);

	while (1) {
		sortable_call_method(&iterator, iterator_ce, NULL, "distance", sizeof("distance") - 1, 1, &distance, param_last_obj);
		if (Z_LVAL(distance) < 1) {
			break;
		}
		sortable_call_method(getThis(), this_ce, NULL, "compare", sizeof("compare") - 1, 2, &comparison, &iterator, param_last_obj);
		if (Z_LVAL(comparison) > 0) {
			sortable_call_method(param_collection_obj, param_collection_ce, NULL, "swap", sizeof("swap") - 1, 2, NULL,
				&wall, &iterator);
			sortable_call_method(&wall, wall_ce, NULL, "next", sizeof("next") - 1, 0, NULL);
		}
		sortable_call_method(&iterator, iterator_ce, NULL, "next", sizeof("next") - 1, 0, NULL);
	}
	sortable_call_method(param_collection_obj, param_collection_ce, NULL, "swap", sizeof("swap") - 1, 2, NULL,
		&wall, param_last_obj);

	RETURN_ZVAL(&wall, 1, 0);
}
/* }}} */

/* {{{ proto mixed BidirectionalSeekableArrayIterator::__construct(
   array $subject
) */
ZEND_METHOD(BidirectionalSeekableArrayIterator, __construct)
{
	zval* param_subject;

#ifndef FAST_ZPP
	if (zend_parse_method_parameters(ZEND_NUM_ARGS(), getThis(), "a", &param_subject) == FAILURE) {
		RETURN_NULL();
	}
#else
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(param_subject)
	ZEND_PARSE_PARAMETERS_END();
#endif

	zend_error(E_CORE_ERROR, "Method BidirectionalSeekableArrayIterator::__construct not implemented.");
}
/* }}} */

/* {{{ proto mixed BidirectionalSeekableArrayIterator::distance(
   BidirectionalSeekableIterator $friend
) */
ZEND_METHOD(BidirectionalSeekableArrayIterator, distance)
{
	zval* param_friend_obj;

#ifndef FAST_ZPP
	if (zend_parse_method_parameters(ZEND_NUM_ARGS(), getThis(), "O", &param_friend_obj,
		MUTAGEN_CLASS_ENTRY(Spl, BidirectionalSeekableIterator)) == FAILURE) {
		RETURN_NULL();
	}
#else
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(param_friend_obj, MUTAGEN_CLASS_ENTRY(Spl, BidirectionalSeekableIterator))
	ZEND_PARSE_PARAMETERS_END();
#endif

	zend_error(E_CORE_ERROR, "Method BidirectionalSeekableArrayIterator::distance not implemented.");
}
/* }}} */

/* {{{ proto mixed BidirectionalSeekableArrayIterator::previous(
   mixed $offset
) */
ZEND_METHOD(BidirectionalSeekableArrayIterator, previous)
{
	zval* param_offset;


#ifndef FAST_ZPP
	if (zend_parse_method_parameters(ZEND_NUM_ARGS(), getThis(), "|z", &param_offset) == FAILURE) {
		RETURN_NULL();
	}
#else
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(param_offset)
	ZEND_PARSE_PARAMETERS_END();
#endif

	zend_error(E_CORE_ERROR, "Method BidirectionalSeekableArrayIterator::previous not implemented.");
}
/* }}} */

/* {{{ proto mixed BidirectionalSeekableArrayIterator::next(
   mixed $offset
) */
ZEND_METHOD(BidirectionalSeekableArrayIterator, next)
{
	zval* param_offset;


#ifndef FAST_ZPP
	if (zend_parse_method_parameters(ZEND_NUM_ARGS(), getThis(), "|z", &param_offset) == FAILURE) {
		RETURN_NULL();
	}
#else
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(param_offset)
	ZEND_PARSE_PARAMETERS_END();
#endif

	zend_error(E_CORE_ERROR, "Method BidirectionalSeekableArrayIterator::next not implemented.");
}
/* }}} */

/* {{{ proto mixed BidirectionalSeekableArrayIterator::index() */
ZEND_METHOD(BidirectionalSeekableArrayIterator, index)
{
	zend_error(E_CORE_ERROR, "Method BidirectionalSeekableArrayIterator::index not implemented.");
}
/* }}} */

/* {{{ proto mixed BidirectionalSeekableArrayIterator::end() */
ZEND_METHOD(BidirectionalSeekableArrayIterator, end)
{
	zend_error(E_CORE_ERROR, "Method BidirectionalSeekableArrayIterator::end not implemented.");
}
/* }}} */

/* {{{ proto mixed BidirectionalSeekableArrayIterator::current() */
ZEND_METHOD(BidirectionalSeekableArrayIterator, current)
{
	zend_error(E_CORE_ERROR, "Method BidirectionalSeekableArrayIterator::current not implemented.");
}
/* }}} */

/* {{{ proto mixed BidirectionalSeekableArrayIterator::key() */
ZEND_METHOD(BidirectionalSeekableArrayIterator, key)
{
	zend_error(E_CORE_ERROR, "Method BidirectionalSeekableArrayIterator::key not implemented.");
}
/* }}} */

/* {{{ proto mixed BidirectionalSeekableArrayIterator::valid() */
ZEND_METHOD(BidirectionalSeekableArrayIterator, valid)
{
	zend_error(E_CORE_ERROR, "Method BidirectionalSeekableArrayIterator::valid not implemented.");
}
/* }}} */

/* {{{ proto mixed BidirectionalSeekableArrayIterator::rewind() */
ZEND_METHOD(BidirectionalSeekableArrayIterator, rewind)
{
	zend_error(E_CORE_ERROR, "Method BidirectionalSeekableArrayIterator::rewind not implemented.");
}
/* }}} */

/* {{{ proto mixed BidirectionalSeekableArrayIterator::seek(
   mixed $position
) */
ZEND_METHOD(BidirectionalSeekableArrayIterator, seek)
{
	zval* param_position;


#ifndef FAST_ZPP
	if (zend_parse_method_parameters(ZEND_NUM_ARGS(), getThis(), "z", &param_position) == FAILURE) {
		RETURN_NULL();
	}
#else
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(param_position)
	ZEND_PARSE_PARAMETERS_END();
#endif

	zend_error(E_CORE_ERROR, "Method BidirectionalSeekableArrayIterator::seek not implemented.");
}
/* }}} */

/* {{{ proto mixed ArraySorter::sort(
   SortableCollection $collection
) */
ZEND_METHOD(ArraySorter, sort)
{
	zval* param_collection_obj;

#ifndef FAST_ZPP
	if (zend_parse_method_parameters(ZEND_NUM_ARGS(), getThis(), "O", &param_collection_obj,
		MUTAGEN_CLASS_ENTRY(Spl, BidirectionalSeekableIterator)) == FAILURE) {
		RETURN_NULL();
	}
#else
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(param_collection_obj, MUTAGEN_CLASS_ENTRY(Spl, BidirectionalSeekableIterator))
	ZEND_PARSE_PARAMETERS_END();
#endif

	zend_error(E_CORE_ERROR, "Method BidirectionalSeekableArrayIterator::sort not implemented.");
}
/* }}} */

/* {{{ proto mixed ArraySorter::quickSort(
   SortableCollection $collection,
   BidirectionalSeekableIterator $first,
   BidirectionalSeekableIterator $last
) */
ZEND_METHOD(ArraySorter, quickSort)
{
	zval* param_collection_obj;
	zval* param_first_obj;
	zval* param_last_obj;

#ifndef FAST_ZPP
	if (zend_parse_method_parameters(ZEND_NUM_ARGS(), getThis(), "OOO", &param_collection_obj,
		MUTAGEN_CLASS_ENTRY(Spl, SortableCollection), &param_first_obj, MUTAGEN_CLASS_ENTRY(Spl, BidirectionalSeekableIterator),
		&param_last_obj, MUTAGEN_CLASS_ENTRY(Spl, BidirectionalSeekableIterator)) == FAILURE) {
		RETURN_NULL();
	}
#else
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(param_collection_obj, MUTAGEN_CLASS_ENTRY(Spl, SortableCollection))
		Z_PARAM_OBJECT_OF_CLASS(param_first_obj, MUTAGEN_CLASS_ENTRY(Spl, BidirectionalSeekableIterator))
		Z_PARAM_OBJECT_OF_CLASS(param_last_obj, MUTAGEN_CLASS_ENTRY(Spl, BidirectionalSeekableIterator))
	ZEND_PARSE_PARAMETERS_END();
#endif

	zend_error(E_CORE_ERROR, "Method BidirectionalSeekableArrayIterator::quickSort not implemented.");
}
/* }}} */

/* {{{ proto mixed ArraySorter::partition(
   SortableCollection $collection,
   BidirectionalSeekableIterator $first,
   BidirectionalSeekableIterator $last
) */
ZEND_METHOD(ArraySorter, partition)
{
	zval* param_collection_obj;
	zval* param_first_obj;
	zval* param_last_obj;

#ifndef FAST_ZPP
	if (zend_parse_method_parameters(ZEND_NUM_ARGS(), getThis(), "OOO", &param_collection_obj,
		MUTAGEN_CLASS_ENTRY(Spl, SortableCollection), &param_first_obj, MUTAGEN_CLASS_ENTRY(Spl, BidirectionalSeekableIterator),
		&param_last_obj, MUTAGEN_CLASS_ENTRY(Spl, BidirectionalSeekableIterator)) == FAILURE) {
		RETURN_NULL();
	}
#else
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(param_collection_obj, MUTAGEN_CLASS_ENTRY(Spl, SortableCollection))
		Z_PARAM_OBJECT_OF_CLASS(param_first_obj, MUTAGEN_CLASS_ENTRY(Spl, BidirectionalSeekableIterator))
		Z_PARAM_OBJECT_OF_CLASS(param_last_obj, MUTAGEN_CLASS_ENTRY(Spl, BidirectionalSeekableIterator))
	ZEND_PARSE_PARAMETERS_END();
#endif

	zend_error(E_CORE_ERROR, "Method BidirectionalSeekableArrayIterator::partition not implemented.");
}
/* }}} */

const zend_function_entry sortable_fe_SortableCollection[] = {
	ZEND_ABSTRACT_ME(SplCollection, swap, MUTAGEN_ARG_INFO(Spl, SortableCollection, swap))
	ZEND_ABSTRACT_ME(SplCollection, first, NULL)
	ZEND_ABSTRACT_ME(SplCollection, last, NULL)
	ZEND_ABSTRACT_ME(SplCollection, getIterator, NULL)
	ZEND_ABSTRACT_ME(SplCollection, keys, NULL)
	ZEND_ABSTRACT_ME(SplCollection, count, NULL)
	PHP_FE_END
};

const zend_function_entry sortable_fe_BidirectionalSeekableIterator[] = {
	ZEND_ABSTRACT_ME(BidirectionalSeekableIterator, distance, MUTAGEN_ARG_INFO(Spl, BidirectionalSeekableIterator, distance))
	ZEND_ABSTRACT_ME(BidirectionalSeekableIterator, previous, MUTAGEN_ARG_INFO(Spl, BidirectionalSeekableIterator, previous))
	ZEND_ABSTRACT_ME(BidirectionalSeekableIterator, next, MUTAGEN_ARG_INFO(Spl, BidirectionalSeekableIterator, next))
	ZEND_ABSTRACT_ME(BidirectionalSeekableIterator, index, NULL)
	ZEND_ABSTRACT_ME(BidirectionalSeekableIterator, end, NULL)
	ZEND_ABSTRACT_ME(BidirectionalSeekableIterator, seek, MUTAGEN_ARG_INFO(Spl, BidirectionalSeekableIterator, seek))
	ZEND_ABSTRACT_ME(BidirectionalSeekableIterator, current, NULL)
	ZEND_ABSTRACT_ME(BidirectionalSeekableIterator, key, NULL)
	ZEND_ABSTRACT_ME(BidirectionalSeekableIterator, valid, NULL)
	ZEND_ABSTRACT_ME(BidirectionalSeekableIterator, rewind, NULL)
	PHP_FE_END
};

const zend_function_entry sortable_fe_Sorter[] = {
	ZEND_ABSTRACT_ME(Sorter, sort, MUTAGEN_ARG_INFO(Spl, Sorter, sort))
	ZEND_ABSTRACT_ME(Sorter, compare, MUTAGEN_ARG_INFO(Spl, Sorter, compare))
	PHP_FE_END
};

const zend_function_entry sortable_fe_CollectionSorter[] = {
	PHP_ME(CollectionSorter, sort, MUTAGEN_ARG_INFO(Spl, Sorter, sort), ZEND_ACC_PUBLIC | ZEND_ACC_FINAL)
	PHP_ME(CollectionSorter, quickSort, MUTAGEN_ARG_INFO(Spl, CollectionSorter, quickSort), ZEND_ACC_PROTECTED | ZEND_ACC_FINAL)
	PHP_ME(CollectionSorter, partition, MUTAGEN_ARG_INFO(Spl, CollectionSorter, partition), ZEND_ACC_PROTECTED | ZEND_ACC_FINAL)
	ZEND_ABSTRACT_ME(CollectionSorter, compare, MUTAGEN_ARG_INFO(Spl, Sorter, compare))
	PHP_FE_END
};

const zend_function_entry sortable_fe_BidirectionalSeekableArrayIterator[] = {
	PHP_ME(BidirectionalSeekableArrayIterator, __construct, MUTAGEN_ARG_INFO(Spl, BidirectionalSeekableArrayIterator, __construct), ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
	PHP_ME(BidirectionalSeekableArrayIterator, distance, MUTAGEN_ARG_INFO(Spl, BidirectionalSeekableArrayIterator, distance), ZEND_ACC_PUBLIC)
	PHP_ME(BidirectionalSeekableArrayIterator, previous, MUTAGEN_ARG_INFO(Spl, BidirectionalSeekableArrayIterator, previous), ZEND_ACC_PUBLIC)
	PHP_ME(BidirectionalSeekableArrayIterator, next, MUTAGEN_ARG_INFO(Spl, BidirectionalSeekableArrayIterator, next), ZEND_ACC_PUBLIC)
	PHP_ME(BidirectionalSeekableArrayIterator, index, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(BidirectionalSeekableArrayIterator, end, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(BidirectionalSeekableArrayIterator, current, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(BidirectionalSeekableArrayIterator, key, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(BidirectionalSeekableArrayIterator, valid, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(BidirectionalSeekableArrayIterator, rewind, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(BidirectionalSeekableArrayIterator, seek, MUTAGEN_ARG_INFO(Spl, BidirectionalSeekableArrayIterator, seek), ZEND_ACC_PUBLIC)
	PHP_FE_END
};

const zend_function_entry sortable_fe_ArraySorter[] = {
	PHP_ME(ArraySorter, sort, MUTAGEN_ARG_INFO(Spl, ArraySorter, sort), ZEND_ACC_PUBLIC | ZEND_ACC_FINAL)
	PHP_ME(ArraySorter, quickSort, MUTAGEN_ARG_INFO(Spl, ArraySorter, quickSort), ZEND_ACC_PROTECTED | ZEND_ACC_FINAL)
	PHP_ME(ArraySorter, partition, MUTAGEN_ARG_INFO(Spl, ArraySorter, partition), ZEND_ACC_PROTECTED | ZEND_ACC_FINAL)
	ZEND_ABSTRACT_ME(ArraySorter, compare, MUTAGEN_ARG_INFO(Spl, ArraySorter, compare))
	PHP_FE_END
};

static void sortable_register_class_Sortable(zend_class_entry **ppce)
{
	zend_class_entry ce;
	INIT_CLASS_ENTRY(ce, MUTAGEN_CLASS_NAME("Spl", "Sortable"), NULL);
	*ppce = zend_register_internal_interface(&ce);
}

static void sortable_register_class_SortableCollection(zend_class_entry **ppce)
{
	zend_class_entry ce;
	INIT_CLASS_ENTRY(ce, MUTAGEN_CLASS_NAME("Spl", "SortableCollection"), sortable_fe_SortableCollection);
	*ppce = zend_register_internal_interface(&ce);

	zend_class_implements(*ppce, 1, MUTAGEN_CLASS_ENTRY(Spl, Sortable));

	//(*ppce)->interface_gets_implemented = sortable_implement_SortableCollection;
}

static void sortable_register_class_BidirectionalSeekableIterator(zend_class_entry **ppce)
{
	zend_class_entry ce;
	INIT_CLASS_ENTRY(ce, MUTAGEN_CLASS_NAME("Spl", "BidirectionalSeekableIterator"), sortable_fe_BidirectionalSeekableIterator);
	*ppce = zend_register_internal_interface(&ce);

	//zend_class_implements(*ppce, 1, spl_ce_SeekableIterator);
	zend_class_implements(*ppce, 1, zend_ce_iterator);
}

static void sortable_register_class_Sorter(zend_class_entry **ppce)
{
	zend_class_entry ce;
	INIT_CLASS_ENTRY(ce, MUTAGEN_CLASS_NAME("Spl", "Sorter"), sortable_fe_Sorter);
	*ppce = zend_register_internal_interface(&ce);
}

static void sortable_register_class_CollectionSorter(zend_class_entry **ppce)
{
	zend_class_entry ce;
	INIT_CLASS_ENTRY(ce, MUTAGEN_CLASS_NAME("Spl", "CollectionSorter"), sortable_fe_CollectionSorter);
	*ppce = zend_register_internal_class(&ce);
	(*ppce)->ce_flags |= ZEND_ACC_ABSTRACT;

	//zend_class_implements(*ppce, 1, MUTAGEN_CLASS_ENTRY(Spl, Sorter));
}

static void sortable_register_class_BidirectionalSeekableArrayIterator(zend_class_entry **ppce)
{
	zend_class_entry ce;
	INIT_CLASS_ENTRY(ce, MUTAGEN_CLASS_NAME("Spl", "BidirectionalSeekableArrayIterator"), sortable_fe_BidirectionalSeekableArrayIterator);
	*ppce = zend_register_internal_class(&ce);

	zend_class_implements(*ppce, 1, MUTAGEN_CLASS_ENTRY(Spl, BidirectionalSeekableIterator));
}

static void sortable_register_class_ArraySorter(zend_class_entry **ppce)
{
	zend_class_entry ce;
	INIT_CLASS_ENTRY(ce, MUTAGEN_CLASS_NAME("Spl", "ArraySorter"), sortable_fe_ArraySorter);
	*ppce = zend_register_internal_class(&ce);
	(*ppce)->ce_flags |= ZEND_ACC_ABSTRACT;

	zend_class_implements(*ppce, 1, MUTAGEN_CLASS_ENTRY(Spl, Sorter));
}

SORTABLE_API zend_class_entry *sortable_get_class_Sortable()
{
	return MUTAGEN_CLASS_ENTRY(Spl, Sortable);
}

SORTABLE_API zend_class_entry *sortable_get_class_SortableCollection()
{
	return MUTAGEN_CLASS_ENTRY(Spl, SortableCollection);
}

SORTABLE_API zend_class_entry *sortable_get_class_BidirectionalSeekableIterator()
{
	return MUTAGEN_CLASS_ENTRY(Spl, BidirectionalSeekableIterator);
}

SORTABLE_API zend_class_entry *sortable_get_class_Sorter()
{
	return MUTAGEN_CLASS_ENTRY(Spl, Sorter);
}

SORTABLE_API zend_class_entry *sortable_get_class_CollectionSorter()
{
	return MUTAGEN_CLASS_ENTRY(Spl, CollectionSorter);
}

SORTABLE_API zend_class_entry *sortable_get_class_BidirectionalSeekableArrayIterator()
{
	return MUTAGEN_CLASS_ENTRY(Spl, BidirectionalSeekableArrayIterator);
}

SORTABLE_API zend_class_entry *sortable_get_class_ArraySorter()
{
	return MUTAGEN_CLASS_ENTRY(Spl, ArraySorter);
}

/* {{{ PHP_MSHUTDOWN_FUNCTION */
PHP_MINIT_FUNCTION(sortable)
{
	//memcpy(&sortable_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
	//sortable_handlers.sort = comparable_compare_objects;

	sortable_register_class_Sortable(&MUTAGEN_CLASS_ENTRY(Spl, Sortable));
	sortable_register_class_SortableCollection(&MUTAGEN_CLASS_ENTRY(Spl, SortableCollection));
	sortable_register_class_BidirectionalSeekableIterator(&MUTAGEN_CLASS_ENTRY(Spl, BidirectionalSeekableIterator));
	sortable_register_class_Sorter(&MUTAGEN_CLASS_ENTRY(Spl, Sorter));
	sortable_register_class_CollectionSorter(&MUTAGEN_CLASS_ENTRY(Spl, CollectionSorter));
	//sortable_register_class_BidirectionalSeekableArrayIterator(&MUTAGEN_CLASS_ENTRY(Spl, BidirectionalSeekableArrayIterator));
	//sortable_register_class_ArraySorter(&MUTAGEN_CLASS_ENTRY(Spl, ArraySorter));

	return SUCCESS;
}

/* {{{ PHP_MSHUTDOWN_FUNCTION */
PHP_MSHUTDOWN_FUNCTION(sortable)
{
	return SUCCESS;
}

ZEND_MINFO_FUNCTION(sortable)
{
}

zend_module_entry sortable_module_entry = {
	STANDARD_MODULE_HEADER,
	"sortable",
	NULL,
	ZEND_MINIT(sortable),
	ZEND_MSHUTDOWN(sortable),
	NULL,
	NULL,
	ZEND_MINFO(sortable),
	"1.0.0-dev0",
	STANDARD_MODULE_PROPERTIES
};

static int sortable_user_compare(const zval *left, const zval *right, const zval *callback) /* {{{ */
{
	zval args[2];
	zval retval;
	int  result, error;
	zend_fcall_info fci;

	ZVAL_COPY(&args[0], left);
	ZVAL_COPY(&args[1], right);

	fci.size = sizeof(fci);
	fci.function_table = EG(function_table);
	fci.object = NULL;
	ZVAL_COPY_VALUE(&fci.function_name, callback);
	fci.retval = &retval;
	fci.param_count = 2;
	fci.params = args;
	fci.no_separation = 0;
	fci.symbol_table = NULL;

	result = 0;
	error = zend_call_function(&fci, NULL);
	if (error == FAILURE) {
		zend_throw_exception(NULL, "Could not call comparison callback.", (zend_long)0);
	} else if (!Z_ISUNDEF(retval)) {
		if (Z_TYPE(retval) != IS_LONG) {
			convert_to_long_ex(&retval);
		}
		result = Z_LVAL(retval);
	} else {
		zend_throw_exception(NULL, "Comparison callback did not return a value.", (zend_long)0);
	}
	zval_ptr_dtor(&args[0]);
	zval_ptr_dtor(&args[1]);

	return result;
}

/* }}} */


/* {{{ zend_call_method
 Only returns the returned zval if retval_ptr != NULL */
zval* sortable_call_method(zval *object, zend_class_entry *obj_ce, zend_function **fn_proxy,
	const char *function_name, size_t function_name_len, int param_count, zval *retval_ptr, ...)
{
	unsigned int idx;
	int result;
	zend_fcall_info fci;
	zval retval;
	HashTable *function_table;
	zval *params, *tmp;
	va_list argv;

	params = NULL;
	if (param_count > 0) {
		params = emalloc(param_count * sizeof(zval));

		va_start(argv, retval_ptr);
		for (idx = 0; idx < param_count; idx++) {
			tmp = va_arg(argv, zval *);
			ZVAL_COPY_VALUE(&params[idx], tmp);
		}
	}

	fci.size = sizeof(fci);
	/*fci.function_table = NULL; will be read form zend_class_entry of object if needed */
	fci.object = (object && Z_TYPE_P(object) == IS_OBJECT) ? Z_OBJ_P(object) : NULL;
	ZVAL_STRINGL(&fci.function_name, function_name, function_name_len);
	fci.retval = retval_ptr ? retval_ptr : &retval;
	fci.param_count = param_count;
	fci.params = params;
	fci.no_separation = 1;
	fci.symbol_table = NULL;

	if (!fn_proxy && !obj_ce) {
		/* no interest in caching and no information already present that is
		 * needed later inside zend_call_function. */
		fci.function_table = !object ? EG(function_table) : NULL;
		result = zend_call_function(&fci, NULL);
		zval_ptr_dtor(&fci.function_name);
	} else {
		zend_fcall_info_cache fcic;

		fcic.initialized = 1;
		if (!obj_ce) {
			obj_ce = object ? Z_OBJCE_P(object) : NULL;
		}
		if (obj_ce) {
			function_table = &obj_ce->function_table;
		} else {
			function_table = EG(function_table);
		}
		if (!fn_proxy || !*fn_proxy) {
			if ((fcic.function_handler = zend_hash_find_ptr(function_table, Z_STR(fci.function_name))) == NULL) {
				/* error at c-level */
				zend_error(E_CORE_ERROR, "Couldn't find implementation for method %s%s%s", obj_ce ? obj_ce->name->val : "", obj_ce ? "::" : "", function_name);
			}
			if (fn_proxy) {
				*fn_proxy = fcic.function_handler;
			}
		} else {
			fcic.function_handler = *fn_proxy;
		}
		fcic.calling_scope = obj_ce;
		if (object) {
			fcic.called_scope = Z_OBJCE_P(object);
		} else if (obj_ce &&
			!(EG(current_execute_data) &&
			EG(current_execute_data)->called_scope &&
			instanceof_function(EG(current_execute_data)->called_scope, obj_ce))) {
			fcic.called_scope = obj_ce;
		} else {
			fcic.called_scope = EG(current_execute_data) ? EG(current_execute_data)->called_scope : NULL;
		}
		fcic.object = object ? Z_OBJ_P(object) : NULL;
		result = zend_call_function(&fci, &fcic);
		zval_ptr_dtor(&fci.function_name);
	}
	if (result == FAILURE) {
		/* error at c-level */
		if (!obj_ce) {
			obj_ce = object ? Z_OBJCE_P(object) : NULL;
		}
		if (!EG(exception)) {
			zend_error(E_CORE_ERROR, "Couldn't execute method %s%s%s", obj_ce ? obj_ce->name->val : "", obj_ce ? "::" : "", function_name);
		}
	}
	/* copy arguments back, they might be changed by references */
	if (param_count > 0) {
		va_start(argv, retval_ptr);
		for (idx = 0; idx < param_count; idx++) {
			tmp = va_arg(argv, zval *);
			if (Z_ISREF(params[idx]) && !Z_ISREF_P(tmp)) {
				ZVAL_COPY_VALUE(tmp, &params[idx]);
			}
		}
		efree(params);
	}
	if (!retval_ptr) {
		zval_ptr_dtor(&retval);
		return NULL;
	}
	return retval_ptr;
}
/* }}} */
