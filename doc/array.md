# PHP Scalar objects API - Arrays

## Virtual class `SplArray`

Implements :
* `IteratorAggregate`
* `Countable`
* `Serializable`
* `JsonSerializable`
* `ArrayAccess`

### Static method `combine`

Equivalent to [`array_combine`](http://php.net/manual/fr/function.array-combine.php)

* Parameter `$columnKey`, of type `Traversable`
* Parameter `$indexKey`, of type `Traversable`
* Returns `SplArray`

### Static method `compact`

Equivalent to [`compact`](http://php.net/manual/fr/function.array-compact.php)

* Parameter `...$vars`, of type `mixed` (variadic)
* Returns `SplArray`

### Static method `fill`

Equivalent to [`array_​fill`](http://php.net/manual/fr/function.array-fill.php)

* Parameter `$startIndex`, of type `integer`
* Parameter `$count`, of type `integer`
* Parameter `$value`, of type `mixed`
* Returns `SplArray`

### Static method `fillKeys`

Equivalent to [`array_​fill_​keys`](http://php.net/manual/fr/function.array-fill-keys.php)

* Parameter `$keys`, of type `SplArray`
* Parameter `$value`, of type `mixed`
* Returns `SplArray`

### Method `changeKeyCase`

Equivalent to [`array_change_key_case`](http://php.net/manual/fr/function.array-change-key-case.php)

* Parameter `$size`, of type `integer`, defaults to `SplArray::CASE_LOWER`
* Returns `void`

### Method `chunk`

Equivalent to [`array_chunk`](http://php.net/manual/fr/function.array-chunk.php)

* Parameter `$size`, of type `integer`
* Parameter `$preserveKeys`, of type `boolean`, defaults to `false`
* Returns `SplArray`

### Method `column`

Equivalent to [`array_column`](http://php.net/manual/fr/function.array-column.php)

* Parameter `$columnKey`, of type `mixed`
* Parameter `$indexKey`, of type `mixed`
* Returns `SplArray`

### Method `count`

Equivalent to [`sizeof`](http://php.net/manual/fr/function.sizeof.php) and [`count`](http://php.net/manual/fr/function.count.php).

Implements [`Countable::count`](http://php.net/manual/fr/countable.count.php).

* Returns `integer`

### Method `countValues`

Equivalent to [`array_count_values`](http://php.net/manual/fr/function.array-count-values.php)

* Returns `SplArray`

### Method `flip`

Equivalent to [`array_flip`](http://php.net/manual/fr/function.array-flip.php)

* Returns `SplArray` (a copy of current array)

### Method `pad`

Equivalent to [`array_pad`](http://php.net/manual/fr/function.array-pad.php)

* Returns `SplArray` (a copy of current array)

### Method `reverse`

Equivalent to [`array_reverse`](http://php.net/manual/fr/function.array-reverse.php)

* Parameter `$preserveKeys`, of type `boolean`, defaults to `false`
* Returns `SplArray` (a copy of current array)

### Method `unique`

Equivalent to [`array_unique`](http://php.net/manual/fr/function.array-unique.php)

* Parameter `$sortFlags`, of type `integer`, defaults to `SplArray::SORT_STRING`
* Returns `SplArray` (a copy of current array)

### Method `hasKey`

Equivalent to [`array_key_exists`](http://php.net/manual/fr/function.array-key-exists.php) and [`key_exists`](http://php.net/manual/fr/function.array-key-exists.php)

* Parameter `$key`, of type `mixed`
* Returns `bool`

### Method `has`

Equivalent to [`in_array`](http://php.net/manual/fr/function.in-array.php)

* Parameter `$key`, of type `mixed`
* Returns `bool`

### Method `keys`

Equivalent to [`array_keys`](http://php.net/manual/fr/function.array-keys.php)

* Returns `SplArray`

### Method `values`

Equivalent to [`array_values`](http://php.net/manual/fr/function.array-values.php)

* Returns `SplArray`

### Method `walk`

Equivalent to [`array_walk`](http://php.net/manual/fr/function.array_walk.php)

* Parameter `$callback`, of type `callable`
* Parameter `$userdata`, of type `mixed`, defaults to `null`
* returns `bool`

### Method `recursiveWalk`

Equivalent to [`array_walk_recursive`](http://php.net/manual/fr/function.array-walk-recursive.php)

* Parameter `$callback`, of type `callable`
* Parameter `$userdata`, of type `mixed`, defaults to `null`
* returns `bool`

### Method `merge`

Equivalent to [`array_merge`](http://php.net/manual/fr/function.array-merge.php)

* Parameter `...$mergedArray`, of type `SplArray` (variadic)
* Returns `SplArray` (a copy of current array)

### Method `recursiveMerge`

Equivalent to [`array_merge_recursive`](http://php.net/manual/fr/function.array-merge-recursive.php)

* Parameter `...$mergedArray`, of type `SplArray` (variadic)
* Returns `SplArray` (a copy of current array)

### Method `replace`

Equivalent to [`array_replace`](http://php.net/manual/fr/function.array-replace.php)

* Parameter `...$mergedArray`, of type `SplArray` (variadic)
* Returns `SplArray` (a copy of current array)

### Method `recursiveReplace`

Equivalent to [`array_replace_recursive`](http://php.net/manual/fr/function.array-replace-recursive.php)

* Parameter `...$mergedArray`, of type `SplArray` (variadic)
* Returns `SplArray` (a copy of current array)

### Method `search`

Equivalent to [`array_search`](http://php.net/manual/fr/function.array-search.php)

* Parameter `$needle`, of type `mixed`
* Parameter `$strict`, of type `boolean`, defaults to `false`
* Returns `mixed`

### Method `reduce`

Equivalent to [`array_reduce`](http://php.net/manual/fr/function.array-reduce.php)

* Parameter `$callback`, of type `callable`
* Parameter `$userdata`, of type `mixed`, defaults to `null`
* returns `mixed`

### Method `slice`

Equivalent to [`array_slice`](http://php.net/manual/fr/function.array-slice.php)

* Parameter `$offset`, of type `integer`
* Parameter `$length`, of type `integer`, defaults to `null`
* Parameter `$preserveKeys`, of type `boolean`, defaults to `false`
* Returns `SplArray` (a copy of current array)

### Method `splice`

Equivalent to [`array_splice`](http://php.net/manual/fr/function.array-splice.php)

* Parameter `$offset`, of type `integer`
* Parameter `$length`, of type `integer`, defaults to `null`
* Parameter `$replacement`, of type `SplArray`, defaults to *empty array*
* Returns `SplArray` (a copy of current array)

### Method `unique`

Equivalent to [`array_unique`](http://php.net/manual/fr/function.array-unique.php)

* Returns `SplArray` (a copy of current array)

### Method `extract`

Equivalent to [`extract`](http://php.net/manual/fr/function.extract.php)

* Parameter `$flags`, of type `integer`, defaults to `SplArray::EXTR_OVERWRITE`
* Parameter `$prefix`, of type `string`, defaults to `null`
* Returns `integer`

### Method `sum`

Equivalent to [`array_sum`](http://php.net/manual/fr/function.array-sum.php)

* Returns `number`

### Method `product`

Equivalent to [`array_product`](http://php.net/manual/fr/function.array-product.php)

* Returns `number`

### Method `range`

Equivalent to [`range`](http://php.net/manual/fr/function.range.php)

* Parameter `$start`, of type `mixed`
* Parameter `$end`, of type `mixed`
* Parameter `$step`, of type `numeric`, defaults to `1`
* Returns `integer`

### Method `current`

Equivalent to [`current`](http://php.net/manual/fr/function.current.php) and [`pos`](http://php.net/manual/fr/function.pos.php)

Implements [`ArrayIterator::current`](http://php.net/manual/fr/arrayiterator.current.php)

### Method `key`

Equivalent to [`key`](http://php.net/manual/fr/function.key.php)

Implements [`ArrayIterator::key`](http://php.net/manual/fr/arrayiterator.key.php)

### Method `next`

Equivalent [`next`](http://php.net/manual/fr/function.next.php)

Implements [`ArrayIterator::next`](http://php.net/manual/fr/arrayiterator.next.php)

### Method `prev`

Reverse method of [`next`](http://php.net/manual/fr/function.next.php)

### Method `rewind`

Equivalent [`reset`](http://php.net/manual/fr/function.reset.php)

Implements [`ArrayIterator::reset`](http://php.net/manual/fr/arrayiterator.reset.php)

### Method `seek`

Implements [`ArrayIterator::seek`](http://php.net/manual/fr/arrayiterator.seek.php)

### Method `valid`

Implements [`ArrayIterator::reset`](http://php.net/manual/fr/arrayiterator.valid.php)

### Method `end`

Equivalent to [`end`](http://php.net/manual/fr/function.end.php)

### Method `begin`

Reverse method of [`end`](http://php.net/manual/fr/function.end.php)

### Method `pair`

Equivalent to [`each`](http://php.net/manual/fr/function.each.php)














### Method `pop`

Equivalent to `array_pop`


### Method `push`

Equivalent to `array_push`


### Method `shift`

Equivalent to `array_shift`


### Method `unshift`

Equivalent to `array_unshift`





### Method `list`

Equivalent to `list`

