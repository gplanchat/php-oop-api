# PHP Scalar objects API - Arrays

This document specifies the `array` scalar type's object-oriented interface

Example :

```php
<?php

$example = ['one', 'two', 'three'];

var_dump($example->merge(['four', 'five', 'six'], ['seven', 'eight', 'nine']));
```

```
array(9) {
    0 => 'one',
    1 => 'two',
    2 => 'three'
    3 => 'four',
    4 => 'five',
    5 => 'six',
    6 => 'seven',
    7 => 'eight',
    8 => 'nine'
}
```

## Virtual class `SplArray`

Implements :
* `IteratorAggregate`
* `Countable`
* `Serializable`
* `JsonSerializable`
* `ArrayAccess`

### Static method `combine`

Creates an array by using one array for keys and another for its values

Equivalent to [`array_combine`](http://php.net/manual/en/function.array-combine.php)

* Parameter `$columnKey`, of type `Traversable`
* Parameter `$indexKey`, of type `Traversable`
* Returns `SplArray`

### Static method `compact`

Create array containing variables and their values

Equivalent to [`compact`](http://php.net/manual/en/function.compact.php)

* Parameter `...$vars`, of type `mixed` (variadic)
* Returns `SplArray`

### Static method `fill`

Fill an array with values

Equivalent to [`array_​fill`](http://php.net/manual/en/function.array-fill.php)

* Parameter `$startIndex`, of type `integer`
* Parameter `$count`, of type `integer`
* Parameter `$value`, of type `mixed`
* Returns `SplArray`

### Static method `fillKeys`

Fill an array with values, specifying keys

Equivalent to [`array_​fill_​keys`](http://php.net/manual/en/function.array-fill-keys.php)

* Parameter `$keys`, of type `SplArray`
* Parameter `$value`, of type `mixed`
* Returns `SplArray`

### Method `changeKeyCase`

Changes the case of all keys in an array

Equivalent to [`array_change_key_case`](http://php.net/manual/en/function.array-change-key-case.php)

* Parameter `$size`, of type `integer`, defaults to `SplArray::CASE_LOWER`
* Returns `void`

### Method `chunk`

Split an array into chunks

Equivalent to [`array_chunk`](http://php.net/manual/en/function.array-chunk.php)

* Parameter `$size`, of type `integer`
* Parameter `$preserveKeys`, of type `boolean`, defaults to `false`
* Returns `SplArray`

### Method `column`

Return the values from a single column in the input array

Equivalent to [`array_column`](http://php.net/manual/en/function.array-column.php)

* Parameter `$columnKey`, of type `mixed`
* Parameter `$indexKey`, of type `mixed`
* Returns `SplArray`

### Method `count`

Count elements of the array

Equivalent to [`sizeof`](http://php.net/manual/en/function.sizeof.php) and [`count`](http://php.net/manual/en/function.count.php).

Implements [`Countable::count`](http://php.net/manual/en/countable.count.php).

* Returns `integer`

### Method `countValues`

Counts all the values of an array

Equivalent to [`array_count_values`](http://php.net/manual/en/function.array-count-values.php)

* Returns `SplArray`

### Method `flip`

Exchanges all keys with their associated values in an array

Equivalent to [`array_flip`](http://php.net/manual/en/function.array-flip.php)

* Returns `SplArray` (a copy of current array)

### Method `pad`

Pad array to the specified length with a value

Equivalent to [`array_pad`](http://php.net/manual/en/function.array-pad.php)

* Returns `SplArray` (a copy of current array)

### Method `reverse`

Return an array with elements in reverse order

Equivalent to [`array_reverse`](http://php.net/manual/en/function.array-reverse.php)

* Parameter `$preserveKeys`, of type `boolean`, defaults to `false`
* Returns `SplArray` (a copy of current array)

### Method `unique`

Removes duplicate values from an array

Equivalent to [`array_unique`](http://php.net/manual/en/function.array-unique.php)

* Parameter `$sortFlags`, of type `integer`, defaults to `SplArray::SORT_STRING`
* Returns `SplArray` (a copy of current array)

### Method `hasKey`

Checks if the given key or index exists in the array

Equivalent to [`array_key_exists`](http://php.net/manual/en/function.array-key-exists.php) and [`key_exists`](http://php.net/manual/en/function.array-key-exists.php)

* Parameter `$key`, of type `mixed`
* Returns `bool`

### Method `has`

Checks if a value exists in an array

Equivalent to [`in_array`](http://php.net/manual/en/function.in-array.php)

* Parameter `$key`, of type `mixed`
* Returns `bool`

### Method `keys`

Return all the keys or a subset of the keys of an array

Equivalent to [`array_keys`](http://php.net/manual/en/function.array-keys.php)

* Returns `SplArray`

### Method `values`

Return all the values of an array

Equivalent to [`array_values`](http://php.net/manual/en/function.array-values.php)

* Returns `SplArray`

### Method `walk`

Apply a user supplied function to every member of an array

Equivalent to [`array_walk`](http://php.net/manual/en/function.array-walk.php)

* Parameter `$callback`, of type `callable`
* Parameter `$userdata`, of type `mixed`, defaults to `null`
* returns `bool`

### Method `recursiveWalk`

Apply a user function recursively to every member of an array

Equivalent to [`array_walk_recursive`](http://php.net/manual/en/function.array-walk-recursive.php)

* Parameter `$callback`, of type `callable`
* Parameter `$userdata`, of type `mixed`, defaults to `null`
* returns `bool`

### Method `merge`

Merge one or more arrays

Equivalent to [`array_merge`](http://php.net/manual/en/function.array-merge.php)

* Parameter `...$mergedArray`, of type `SplArray` (variadic)
* Returns `SplArray` (a copy of current array)

### Method `recursiveMerge`

Merge two or more arrays recursively

Equivalent to [`array_merge_recursive`](http://php.net/manual/en/function.array-merge-recursive.php)

* Parameter `...$mergedArray`, of type `SplArray` (variadic)
* Returns `SplArray` (a copy of current array)

### Method `replace`

Replaces elements from passed arrays into the first array

Equivalent to [`array_replace`](http://php.net/manual/en/function.array-replace.php)

* Parameter `...$mergedArray`, of type `SplArray` (variadic)
* Returns `SplArray` (a copy of current array)

### Method `recursiveReplace`

Replaces elements from passed arrays into the first array recursively

Equivalent to [`array_replace_recursive`](http://php.net/manual/en/function.array-replace-recursive.php)

* Parameter `...$mergedArray`, of type `SplArray` (variadic)
* Returns `SplArray` (a copy of current array)

### Method `search`

Searches the array for a given value and returns the corresponding key if successful

Equivalent to [`array_search`](http://php.net/manual/en/function.array-search.php)

* Parameter `$needle`, of type `mixed`
* Parameter `$strict`, of type `boolean`, defaults to `false`
* Returns `mixed`

### Method `reduce`

Iteratively reduce the array to a single value using a callback function

Equivalent to [`array_reduce`](http://php.net/manual/en/function.array-reduce.php)

* Parameter `$callback`, of type `callable`
* Parameter `$userdata`, of type `mixed`, defaults to `null`
* returns `mixed`

### Method `slice`

Extract a slice of the array

Equivalent to [`array_slice`](http://php.net/manual/en/function.array-slice.php)

* Parameter `$offset`, of type `integer`
* Parameter `$length`, of type `integer`, defaults to `null`
* Parameter `$preserveKeys`, of type `boolean`, defaults to `false`
* Returns `SplArray` (a copy of current array)

### Method `splice`

Remove a portion of the array and replace it with something else

Equivalent to [`array_splice`](http://php.net/manual/en/function.array-splice.php)

* Parameter `$offset`, of type `integer`
* Parameter `$length`, of type `integer`, defaults to `null`
* Parameter `$replacement`, of type `SplArray`, defaults to *empty array*
* Returns `SplArray` (a copy of current array)

### Method `unique`

Removes duplicate values from an array

Equivalent to [`array_unique`](http://php.net/manual/en/function.array-unique.php)

* Returns `SplArray` (a copy of current array)

### Method `extract`

Import variables into the current symbol table from an array

Equivalent to [`extract`](http://php.net/manual/en/function.extract.php)

* Parameter `$flags`, of type `integer`, defaults to `SplArray::EXTR_OVERWRITE`
* Parameter `$prefix`, of type `string`, defaults to `null`
* Returns `integer`

### Method `sum`

Calculate the sum of values in an array

Equivalent to [`array_sum`](http://php.net/manual/en/function.array-sum.php)

* Returns `number`

### Method `product`

Calculate the product of values in an array

Equivalent to [`array_product`](http://php.net/manual/en/function.array-product.php)

* Returns `number`

### Method `range`

Create an array containing a range of elements

Equivalent to [`range`](http://php.net/manual/en/function.range.php)

* Parameter `$start`, of type `mixed`
* Parameter `$end`, of type `mixed`
* Parameter `$step`, of type `numeric`, defaults to `1`
* Returns `integer`

### Method `current`

Return the current element in an array

Equivalent to [`current`](http://php.net/manual/en/function.current.php) and [`pos`](http://php.net/manual/en/function.pos.php)

Implements [`ArrayIterator::current`](http://php.net/manual/en/arrayiterator.current.php)

* Returns `void`

### Method `key`

Fetch a key from an array

Equivalent to [`key`](http://php.net/manual/en/function.key.php)

Implements [`ArrayIterator::key`](http://php.net/manual/en/arrayiterator.key.php)

* Returns `mixed`

### Method `next`

Advance the internal array pointer of an array

Equivalent [`next`](http://php.net/manual/en/function.next.php)

Implements [`ArrayIterator::next`](http://php.net/manual/en/arrayiterator.next.php)

* Returns `void`

### Method `prev`

Move back the internal array pointer of an array

Reverse method of [`next`](http://php.net/manual/en/function.next.php)

* Returns `void`

### Method `rewind`

Set the internal pointer of an array to its first element

Equivalent [`reset`](http://php.net/manual/en/function.reset.php)

Implements [`ArrayIterator::reset`](http://php.net/manual/en/arrayiterator.reset.php)

* Returns `void`

### Method `seek`

Seek to position

Implements [`ArrayIterator::seek`](http://php.net/manual/en/arrayiterator.seek.php)

* Parameter `$position`, of type `integer`
* Returns `void`

### Method `valid`

Check whether array contains more entries

Implements [`ArrayIterator::reset`](http://php.net/manual/en/arrayiterator.valid.php)

* Returns `boolean`

### Method `end`

Set the internal pointer of an array to its last element

Equivalent to [`end`](http://php.net/manual/en/function.end.php)

* Returns `void`

### Method `pair`

Return the current key and value pair from an array and advance the array cursor

Equivalent to [`each`](http://php.net/manual/en/function.each.php)

* Returns `SplArray`

### Method `pop`

Pop the element off the end of array

Equivalent to [`array_pop`](http://php.net/manual/en/function.array-pop.php)

* Returns `mixed`

### Method `push`

Push one or more elements onto the end of array

Equivalent to [`array_push`](http://php.net/manual/en/function.array-push.php)

* Parameter `...$items`, of type `mixed` (variadic)
* Returns `void`

### Method `shift`

Shift an element off the beginning of array

Equivalent to [`array_shift`](http://php.net/manual/en/function.array-shift.php)

* Returns `mixed`

### Method `unshift`

Prepend one or more elements to the beginning of an array

Equivalent to [`array_unshift`](http://php.net/manual/en/function.array-unshift.php)

* Parameter `...$items`, of type `mixed` (variadic)
* Returns `void`

