# PHP Scalar objects API - Arrays

## Class `Spl\Array`

Implements :
* `IteratorAggregate`
* `Countable`
* `Serializable`
* `JsonSerializable`
* `ArrayAccess`
 
### Attribute `size`

Equivalent to `sizeof` and `count`

### Static method `combine`

Equivalent to `array_combine`

* Parameter `$columnKey`, of type `Traversable`
* Parameter `$indexKey`, of type `Traversable`
* Returns `Spl\Array`

### Static method `​fill`

Equivalent to `array_​fill`

* Parameter `$startIndex`, of type `integer`
* Parameter `$count`, of type `integer`
* Parameter `$value`, of type `mixed`
* Returns `Spl\Array`

### Static method `​fillKeys`

Equivalent to `array_​fill_​keys`

* Parameter `$keys`, of type `Spl\Array`
* Parameter `$value`, of type `mixed`
* Returns `Spl\Array`

### Method `changeKeyCase`

Equivalent to `array_change_key_case`

* Parameter `$size`, of type `integer`, defaults to `Spl\Array::CASE_LOWER`
* Returns `void`

### Method `chunk`

Equivalent to `array_chunk`

* Parameter `$size`, of type `integer`
* Parameter `$preserveKeys`, of type `boolean`, defaults to `false`
* Returns `Spl\Array`

### Method `column`

Equivalent to `array_column`

* Parameter `$columnKey`, of type `mixed`
* Parameter `$indexKey`, of type `mixed`
* Returns `Spl\Array`

### Method `count`

Equivalent to `count`

* Returns `integer`

### Method `countValues`

Equivalent to `array_count_values`

* Returns `Spl\Array`

### Method `​flip`

Equivalent to `array_​flip`

* Returns `Spl\Array` (a copy of current array)

### Method `​pad`

Equivalent to `array_​pad`

* Returns `Spl\Array` (a copy of current array)

### Method `​reverse`

Equivalent to `array_​reverse`

* Parameter `$preserveKeys`, of type `boolean`, defaults to `false`
* Returns `Spl\Array` (a copy of current array)

### Method `​unique`

Equivalent to `array_unique`

* Parameter `$sortFlags`, of type `integer`, defaults to `SORT_STRING`
* Returns `Spl\Array` (a copy of current array)

### Method `​hasKey`

Equivalent to `array_​key_​exists` and `key_​exists`

* Parameter `$key`, of type `mixed`
* Returns `bool`

### Method `​hasValue`

Equivalent to `in_array`

* Parameter `$key`, of type `mixed`
* Returns `bool`

### Method `​keys`

Equivalent to `array_​keys`

* Returns `Spl\Array`

### Method `​values`

Equivalent to `array_​values`

* Returns `Spl\Array`

### Method `​walk`

Equivalent to `array_​walk`

* Parameter `$callback`, of type `callable`
* Parameter `$userdata`, of type `mixed`, defaults to `null`
* returns `bool`

### Method `​recursiveWalk`

Equivalent to `array_​walk_​recursive`

* Parameter `$callback`, of type `callable`
* Parameter `$userdata`, of type `mixed`, defaults to `null`
* returns `bool`

### Method `​merge`

Equivalent to `array_​merge`

* Parameter `...$mergedArray`, of type `Spl\Array` (variadic)
* Returns `Spl\Array` (a copy of current array)

### Method `recursiveMerge`

Equivalent to `array_​merge_​recursive`

* Parameter `...$mergedArray`, of type `Spl\Array` (variadic)
* Returns `Spl\Array` (a copy of current array)

### Method `​recursiveRreplace`

Equivalent to `array_​replace_​recursive`

* Parameter `...$mergedArray`, of type `Spl\Array` (variadic)
* Returns `Spl\Array` (a copy of current array)

### Method `​replace`

Equivalent to `array_​replace`

* Parameter `...$mergedArray`, of type `Spl\Array` (variadic)
* Returns `Spl\Array` (a copy of current array)

### Method `​search`

Equivalent to `array_​search`

* Parameter `$needle`, of type `mixed`
* Parameter `$strict`, of type `boolean`, defaults to `false`
* Returns `mixed`

### Method `​reduce`

Equivalent to `array_​reduce`

* Parameter `$callback`, of type `callable`
* Parameter `$userdata`, of type `mixed`, defaults to `null`
* returns `mixed`

### Method `​slice`

Equivalent to `array_​slice`

* Parameter `$offset`, of type `integer`
* Parameter `$length`, of type `integer`, defaults to `null`
* Parameter `$preserveKeys`, of type `boolean`, defaults to `false`

### Method `​splice`

Equivalent to `array_​splice`

* Parameter `$offset`, of type `integer`
* Parameter `$length`, of type `integer`, defaults to `null`
* Parameter `$replacement`, of type `Spl\Array`, defaults to *empty array*




### Method `​map`

Equivalent to `array_​map`


### Method `​unique`

Equivalent to `array_​unique`


### Method `compact`

Equivalent to `compact`


### Method `extract`

Equivalent to `extract`






### Method `​sum`

Equivalent to `array_​sum`


### Method `​product`

Equivalent to `array_​product`





### Method `key`

Equivalent to `key`


### Method `range`

Equivalent to `range`


### Method `next`

Equivalent to `next`


### Method `pos`

Equivalent to `pos`


### Method `prev`

Equivalent to `prev`


### Method `end`

Equivalent to `end`


### Method `reset`

Equivalent to `reset`


### Method `current`

Equivalent to `current`


### Method `each`

Equivalent to `each`







### Method `​pop`

Equivalent to `array_​pop`


### Method `​push`

Equivalent to `array_​push`


### Method `​shift`

Equivalent to `array_​shift`


### Method `​unshift`

Equivalent to `array_​unshift`





### Method `list`

Equivalent to `list`

