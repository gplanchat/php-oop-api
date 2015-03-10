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

#include "php.h"
#include "ext/spl/spl_iterators.h"

#include <stdio.h>
#include "ext/standard/info.h"
#include "php_sortable.h"

#ifdef COMPILE_DL_SORTABLE
ZEND_GET_MODULE(sortable)
#endif

zend_class_entry * sortable_ce_Sortable;
zend_class_entry * sortable_ce_SortableCollection;
zend_class_entry * sortable_ce_BidirectionalSeekableIterator;
zend_class_entry * sortable_ce_Sorter;
zend_class_entry * sortable_ce_CollectionSorter;
zend_class_entry * sortable_ce_BidirectionalSeekableArrayIterator;
zend_class_entry * sortable_ce_ArraySorter;

ZEND_BEGIN_ARG_INFO_EX(sortable_arginfo_SortableCollection_swap, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, leftKey, BidirectionalSeekableIterator, 0)
	ZEND_ARG_OBJ_INFO(0, rightKey, BidirectionalSeekableIterator, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(sortable_arginfo_BidirectionalSeekableIterator_distance, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, friend, BidirectionalSeekableIterator, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(sortable_arginfo_BidirectionalSeekableIterator_previous, 0, 0, 0)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(sortable_arginfo_BidirectionalSeekableIterator_next, 0, 0, 0)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(sortable_arginfo_BidirectionalSeekableIterator_seek, 0, 0, 1)
	ZEND_ARG_INFO(0, position)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(sortable_arginfo_Sorter_sort, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, collection, SortableCollection, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(sortable_arginfo_Sorter_compare, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, left, BidirectionalSeekableIterator, 0)
	ZEND_ARG_OBJ_INFO(0, right, BidirectionalSeekableIterator, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(sortable_arginfo_CollectionSorter_sort, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, collection, SortableCollection, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(sortable_arginfo_CollectionSorter_compare, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, left, BidirectionalSeekableIterator, 0)
	ZEND_ARG_OBJ_INFO(0, right, BidirectionalSeekableIterator, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(sortable_arginfo_BidirectionalSeekableArrayIterator___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, subject, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(sortable_arginfo_BidirectionalSeekableArrayIterator_distance, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, friend, BidirectionalSeekableIterator, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(sortable_arginfo_BidirectionalSeekableArrayIterator_previous, 0, 0, 0)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(sortable_arginfo_BidirectionalSeekableArrayIterator_next, 0, 0, 0)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(sortable_arginfo_BidirectionalSeekableArrayIterator_seek, 0, 0, 1)
	ZEND_ARG_INFO(0, position)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(sortable_arginfo_ArraySorter_sort, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, collection, SortableCollection, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(sortable_arginfo_ArraySorter_quickSort, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, collection, SortableCollection, 0)
	ZEND_ARG_OBJ_INFO(0, first, BidirectionalSeekableIterator, 0)
	ZEND_ARG_OBJ_INFO(0, last, BidirectionalSeekableIterator, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(sortable_arginfo_ArraySorter_partition, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, collection, SortableCollection, 0)
	ZEND_ARG_OBJ_INFO(0, first, BidirectionalSeekableIterator, 0)
	ZEND_ARG_OBJ_INFO(0, last, BidirectionalSeekableIterator, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(sortable_arginfo_ArraySorter_compare, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, left, BidirectionalSeekableIterator, 0)
	ZEND_ARG_OBJ_INFO(0, right, BidirectionalSeekableIterator, 0)
ZEND_END_ARG_INFO()

/* {{{ proto mixed SortableCollection::swap(
   BidirectionalSeekableIterator $leftKey,
   BidirectionalSeekableIterator $rightKey
) */
ZEND_METHOD(SortableCollection, swap)
{
	zval* param_leftKey_obj;
	zval* param_rightKey_obj;

#ifndef FAST_ZPP
	if (zend_parse_method_parameters(ZEND_NUM_ARGS(), getThis(), "OO", &param_leftKey_obj,
		sortable_ce_BidirectionalSeekableIterator, &param_rightKey_obj,
		sortable_ce_BidirectionalSeekableIterator) == FAILURE) {
		RETURN_NULL();
	}
#else
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(param_leftKey_obj, sortable_ce_BidirectionalSeekableIterator)
		Z_PARAM_OBJECT_OF_CLASS(param_rightKey_obj, sortable_ce_BidirectionalSeekableIterator)
	ZEND_PARSE_PARAMETERS_END();
#endif

}
/* }}} */

/* {{{ proto mixed SortableCollection::first() */
ZEND_METHOD(SortableCollection, first)
{
}
/* }}} */

/* {{{ proto mixed SortableCollection::last() */
ZEND_METHOD(SortableCollection, last)
{
}
/* }}} */

/* {{{ proto mixed SortableCollection::getIterator() */
ZEND_METHOD(SortableCollection, getIterator)
{
}
/* }}} */

/* {{{ proto mixed SortableCollection::keys() */
ZEND_METHOD(SortableCollection, keys)
{
}
/* }}} */

/* {{{ proto mixed SortableCollection::count() */
ZEND_METHOD(SortableCollection, count)
{
}
/* }}} */

/* {{{ proto mixed BidirectionalSeekableIterator::distance(
   BidirectionalSeekableIterator $friend
) */
ZEND_METHOD(BidirectionalSeekableIterator, distance)
{
	zval* param_friend_obj;

#ifndef FAST_ZPP
	if (zend_parse_method_parameters(ZEND_NUM_ARGS(), getThis(), "O", &param_friend_obj,
		sortable_ce_BidirectionalSeekableIterator) == FAILURE) {
		RETURN_NULL();
	}
#else
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(param_friend_obj, sortable_ce_BidirectionalSeekableIterator)
	ZEND_PARSE_PARAMETERS_END();
#endif

}
/* }}} */

/* {{{ proto mixed BidirectionalSeekableIterator::previous(
   mixed $offset
) */
ZEND_METHOD(BidirectionalSeekableIterator, previous)
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

}
/* }}} */

/* {{{ proto mixed BidirectionalSeekableIterator::next(
   mixed $offset
) */
ZEND_METHOD(BidirectionalSeekableIterator, next)
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

}
/* }}} */

/* {{{ proto mixed BidirectionalSeekableIterator::index() */
ZEND_METHOD(BidirectionalSeekableIterator, index)
{
}
/* }}} */

/* {{{ proto mixed BidirectionalSeekableIterator::end() */
ZEND_METHOD(BidirectionalSeekableIterator, end)
{
}
/* }}} */

/* {{{ proto mixed BidirectionalSeekableIterator::seek(
   mixed $position
) */
ZEND_METHOD(BidirectionalSeekableIterator, seek)
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

}
/* }}} */

/* {{{ proto mixed BidirectionalSeekableIterator::current() */
ZEND_METHOD(BidirectionalSeekableIterator, current)
{
}
/* }}} */

/* {{{ proto mixed BidirectionalSeekableIterator::key() */
ZEND_METHOD(BidirectionalSeekableIterator, key)
{
}
/* }}} */

/* {{{ proto mixed BidirectionalSeekableIterator::valid() */
ZEND_METHOD(BidirectionalSeekableIterator, valid)
{
}
/* }}} */

/* {{{ proto mixed BidirectionalSeekableIterator::rewind() */
ZEND_METHOD(BidirectionalSeekableIterator, rewind)
{
}
/* }}} */

/* {{{ proto mixed CollectionSorter::sort(
   SortableCollection $collection
) */
ZEND_METHOD(CollectionSorter, sort)
{
	zval* param_collection_obj;

#ifndef FAST_ZPP
	if (zend_parse_method_parameters(ZEND_NUM_ARGS(), getThis(), "O", &param_collection_obj,
		sortable_ce_SortableCollection) == FAILURE) {
		RETURN_NULL();
	}
#else
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(param_collection_obj, sortable_ce_SortableCollection)
	ZEND_PARSE_PARAMETERS_END();
#endif

}
/* }}} */

/* {{{ proto mixed CollectionSorter::compare(
   BidirectionalSeekableIterator $left,
   BidirectionalSeekableIterator $right
) */
ZEND_METHOD(CollectionSorter, compare)
{
	zval* param_left_obj;
	zval* param_right_obj;

#ifndef FAST_ZPP
	if (zend_parse_method_parameters(ZEND_NUM_ARGS(), getThis(), "OO", &param_left_obj,
		sortable_ce_BidirectionalSeekableIterator, &param_right_obj,
		sortable_ce_BidirectionalSeekableIterator) == FAILURE) {
		RETURN_NULL();
	}
#else
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(param_left_obj, sortable_ce_BidirectionalSeekableIterator)
		Z_PARAM_OBJECT_OF_CLASS(param_right_obj, sortable_ce_BidirectionalSeekableIterator)
	ZEND_PARSE_PARAMETERS_END();
#endif

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
		sortable_ce_BidirectionalSeekableIterator) == FAILURE) {
		RETURN_NULL();
	}
#else
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(param_friend_obj, sortable_ce_BidirectionalSeekableIterator)
	ZEND_PARSE_PARAMETERS_END();
#endif

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

}
/* }}} */

/* {{{ proto mixed BidirectionalSeekableArrayIterator::index() */
ZEND_METHOD(BidirectionalSeekableArrayIterator, index)
{
}
/* }}} */

/* {{{ proto mixed BidirectionalSeekableArrayIterator::end() */
ZEND_METHOD(BidirectionalSeekableArrayIterator, end)
{
}
/* }}} */

/* {{{ proto mixed BidirectionalSeekableArrayIterator::current() */
ZEND_METHOD(BidirectionalSeekableArrayIterator, current)
{
}
/* }}} */

/* {{{ proto mixed BidirectionalSeekableArrayIterator::key() */
ZEND_METHOD(BidirectionalSeekableArrayIterator, key)
{
}
/* }}} */

/* {{{ proto mixed BidirectionalSeekableArrayIterator::valid() */
ZEND_METHOD(BidirectionalSeekableArrayIterator, valid)
{
}
/* }}} */

/* {{{ proto mixed BidirectionalSeekableArrayIterator::rewind() */
ZEND_METHOD(BidirectionalSeekableArrayIterator, rewind)
{
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
		sortable_ce_BidirectionalSeekableIterator) == FAILURE) {
		RETURN_NULL();
	}
#else
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(param_collection_obj, sortable_ce_BidirectionalSeekableIterator)
	ZEND_PARSE_PARAMETERS_END();
#endif

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
		sortable_ce_SortableCollection, &param_first_obj, sortable_ce_BidirectionalSeekableIterator,
		&param_last_obj, sortable_ce_BidirectionalSeekableIterator) == FAILURE) {
		RETURN_NULL();
	}
#else
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(param_collection_obj, sortable_ce_SortableCollection)
		Z_PARAM_OBJECT_OF_CLASS(param_first_obj, sortable_ce_BidirectionalSeekableIterator)
		Z_PARAM_OBJECT_OF_CLASS(param_last_obj, sortable_ce_BidirectionalSeekableIterator)
	ZEND_PARSE_PARAMETERS_END();
#endif

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
		sortable_ce_SortableCollection, &param_first_obj, sortable_ce_BidirectionalSeekableIterator,
		&param_last_obj, sortable_ce_BidirectionalSeekableIterator) == FAILURE) {
		RETURN_NULL();
	}
#else
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(param_collection_obj, sortable_ce_SortableCollection)
		Z_PARAM_OBJECT_OF_CLASS(param_first_obj, sortable_ce_BidirectionalSeekableIterator)
		Z_PARAM_OBJECT_OF_CLASS(param_last_obj, sortable_ce_BidirectionalSeekableIterator)
	ZEND_PARSE_PARAMETERS_END();
#endif

}
/* }}} */

/* {{{ proto mixed ArraySorter::compare(
   BidirectionalSeekableIterator $left,
   BidirectionalSeekableIterator $right
) */
ZEND_METHOD(ArraySorter, compare)
{
	zval* param_left_obj;
	zval* param_right_obj;

#ifndef FAST_ZPP
	if (zend_parse_method_parameters(ZEND_NUM_ARGS(), getThis(), "OO", &param_left_obj,
		sortable_ce_BidirectionalSeekableIterator, &param_right_obj, sortable_ce_BidirectionalSeekableIterator) == FAILURE) {
		RETURN_NULL();
	}
#else
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(param_left_obj, sortable_ce_BidirectionalSeekableIterator)
		Z_PARAM_OBJECT_OF_CLASS(param_right_obj, sortable_ce_BidirectionalSeekableIterator)
	ZEND_PARSE_PARAMETERS_END();
#endif

}
/* }}} */


const zend_function_entry sortable_fe_SortableCollection[] = {
	PHP_ME(SortableCollection, swap, sortable_arginfo_SortableCollection_swap, ZEND_ACC_PUBLIC | ZEND_ACC_ABSTRACT)
	PHP_ME(SortableCollection, first, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_ABSTRACT)
	PHP_ME(SortableCollection, last, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_ABSTRACT)
	PHP_ME(SortableCollection, getIterator, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_ABSTRACT)
	PHP_ME(SortableCollection, keys, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_ABSTRACT)
	PHP_ME(SortableCollection, count, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_ABSTRACT)
};

const zend_function_entry sortable_fe_BidirectionalSeekableIterator[] = {
	PHP_ME(BidirectionalSeekableIterator, distance, sortable_arginfo_BidirectionalSeekableIterator_distance, ZEND_ACC_PUBLIC | ZEND_ACC_ABSTRACT)
	PHP_ME(BidirectionalSeekableIterator, previous, sortable_arginfo_BidirectionalSeekableIterator_previous, ZEND_ACC_PUBLIC | ZEND_ACC_ABSTRACT)
	PHP_ME(BidirectionalSeekableIterator, next, sortable_arginfo_BidirectionalSeekableIterator_next, ZEND_ACC_PUBLIC | ZEND_ACC_ABSTRACT)
	PHP_ME(BidirectionalSeekableIterator, index, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_ABSTRACT)
	PHP_ME(BidirectionalSeekableIterator, end, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_ABSTRACT)
	PHP_ME(BidirectionalSeekableIterator, seek, sortable_arginfo_BidirectionalSeekableIterator_seek, ZEND_ACC_PUBLIC | ZEND_ACC_ABSTRACT)
	PHP_ME(BidirectionalSeekableIterator, current, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_ABSTRACT)
	PHP_ME(BidirectionalSeekableIterator, key, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_ABSTRACT)
	PHP_ME(BidirectionalSeekableIterator, valid, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_ABSTRACT)
	PHP_ME(BidirectionalSeekableIterator, rewind, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_ABSTRACT)
};

const zend_function_entry sortable_fe_Sorter[] = {
	PHP_ME(CollectionSorter, sort, sortable_arginfo_Sorter_sort, ZEND_ACC_PUBLIC | ZEND_ACC_ABSTRACT)
	PHP_ME(CollectionSorter, compare, sortable_arginfo_Sorter_compare, ZEND_ACC_PUBLIC | ZEND_ACC_ABSTRACT)
};

const zend_function_entry sortable_fe_CollectionSorter[] = {
	PHP_ME(CollectionSorter, sort, sortable_arginfo_CollectionSorter_sort, ZEND_ACC_PUBLIC)
	PHP_ME(CollectionSorter, compare, sortable_arginfo_CollectionSorter_compare, ZEND_ACC_PUBLIC)
};

const zend_function_entry sortable_fe_BidirectionalSeekableArrayIterator[] = {
	PHP_ME(BidirectionalSeekableArrayIterator, __construct, sortable_arginfo_BidirectionalSeekableArrayIterator___construct, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
	PHP_ME(BidirectionalSeekableArrayIterator, distance, sortable_arginfo_BidirectionalSeekableArrayIterator_distance, ZEND_ACC_PUBLIC)
	PHP_ME(BidirectionalSeekableArrayIterator, previous, sortable_arginfo_BidirectionalSeekableArrayIterator_previous, ZEND_ACC_PUBLIC)
	PHP_ME(BidirectionalSeekableArrayIterator, next, sortable_arginfo_BidirectionalSeekableArrayIterator_next, ZEND_ACC_PUBLIC)
	PHP_ME(BidirectionalSeekableArrayIterator, index, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(BidirectionalSeekableArrayIterator, end, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(BidirectionalSeekableArrayIterator, current, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(BidirectionalSeekableArrayIterator, key, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(BidirectionalSeekableArrayIterator, valid, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(BidirectionalSeekableArrayIterator, rewind, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(BidirectionalSeekableArrayIterator, seek, sortable_arginfo_BidirectionalSeekableArrayIterator_seek, ZEND_ACC_PUBLIC)
};

const zend_function_entry sortable_fe_ArraySorter[] = {
	PHP_ME(ArraySorter, sort, sortable_arginfo_ArraySorter_sort, ZEND_ACC_PUBLIC)
	PHP_ME(ArraySorter, quickSort, sortable_arginfo_ArraySorter_quickSort, ZEND_ACC_PUBLIC)
	PHP_ME(ArraySorter, partition, sortable_arginfo_ArraySorter_partition, ZEND_ACC_PUBLIC)
	PHP_ME(ArraySorter, compare, sortable_arginfo_ArraySorter_compare, ZEND_ACC_PUBLIC | ZEND_ACC_ABSTRACT)
};

void sortable_register_class_Sortable(zend_class_entry **ppce)
{
	zend_class_entry ce;
	INIT_CLASS_ENTRY(ce, "Sortable", NULL);
	*ppce = zend_register_internal_interface(&ce);
}

void sortable_register_class_SortableCollection(zend_class_entry **ppce)
{
	zend_class_entry ce;
	INIT_CLASS_ENTRY(ce, "SortableCollection", sortable_fe_SortableCollection);
	zend_class_implements(&ce, 1, sortable_ce_Sortable);
	*ppce = zend_register_internal_interface(&ce);
}

void sortable_register_class_BidirectionalSeekableIterator(zend_class_entry **ppce)
{
	zend_class_entry ce;
	INIT_CLASS_ENTRY(ce, "BidirectionalSeekableIterator", sortable_fe_BidirectionalSeekableIterator);

	zend_class_implements(&ce, 1, spl_ce_SeekableIterator);
	*ppce = zend_register_internal_interface(&ce);
}

void sortable_register_class_Sorter(zend_class_entry **ppce)
{
	zend_class_entry ce;
	INIT_CLASS_ENTRY(ce, "Sorter", sortable_fe_Sorter);
	*ppce = zend_register_internal_interface(&ce);
}

void sortable_register_class_CollectionSorter(zend_class_entry **ppce)
{
	zend_class_entry ce;
	INIT_CLASS_ENTRY(ce, "CollectionSorter", sortable_fe_CollectionSorter);
	zend_class_implements(&ce, 1, sortable_ce_Sorter);
	*ppce = zend_register_internal_class(&ce);
}

void sortable_register_class_BidirectionalSeekableArrayIterator(zend_class_entry **ppce)
{
	zend_class_entry ce;
	INIT_CLASS_ENTRY(ce, "BidirectionalSeekableArrayIterator", sortable_fe_BidirectionalSeekableArrayIterator);
	zend_class_implements(&ce, 1, sortable_ce_BidirectionalSeekableIterator);
	*ppce = zend_register_internal_class(&ce);
}

void sortable_register_class_ArraySorter(zend_class_entry **ppce)
{
	zend_class_entry ce;
	INIT_CLASS_ENTRY(ce, "ArraySorter", sortable_fe_ArraySorter);
	zend_class_implements(&ce, 1, sortable_ce_Sorter);
	*ppce = zend_register_internal_class(&ce);
}

SORTABLE_API zend_class_entry *sortable_get_class_Sortable()
{
	return sortable_ce_Sortable;
}

SORTABLE_API zend_class_entry *sortable_get_class_SortableCollection()
{
	return sortable_ce_SortableCollection;
}

SORTABLE_API zend_class_entry *sortable_get_class_BidirectionalSeekableIterator()
{
	return sortable_ce_BidirectionalSeekableIterator;
}

SORTABLE_API zend_class_entry *sortable_get_class_Sorter()
{
	return sortable_ce_CollectionSorter;
}

SORTABLE_API zend_class_entry *sortable_get_class_CollectionSorter()
{
	return sortable_ce_CollectionSorter;
}

SORTABLE_API zend_class_entry *sortable_get_class_BidirectionalSeekableArrayIterator()
{
	return sortable_ce_BidirectionalSeekableArrayIterator;
}

SORTABLE_API zend_class_entry *sortable_get_class_ArraySorter()
{
	return sortable_ce_ArraySorter;
}

/* {{{ PHP_MSHUTDOWN_FUNCTION */
PHP_MINIT_FUNCTION(sortable)
{
	sortable_register_class_Sortable(&sortable_ce_Sortable);
	sortable_register_class_SortableCollection(&sortable_ce_SortableCollection);
	sortable_register_class_BidirectionalSeekableIterator(&sortable_ce_BidirectionalSeekableIterator);
	sortable_register_class_Sorter(&sortable_ce_Sorter);
	sortable_register_class_CollectionSorter(&sortable_ce_CollectionSorter);
	sortable_register_class_BidirectionalSeekableArrayIterator(&sortable_ce_BidirectionalSeekableArrayIterator);
	sortable_register_class_ArraySorter(&sortable_ce_ArraySorter);

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
