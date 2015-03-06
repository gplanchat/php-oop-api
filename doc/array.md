# PHP Scalar objects API - Arrays

This document specifies the `array` scalar type's object-oriented interface for PHP 7+.

This **IS NOT** a reimplementation of the array type into objects.

It **IS** a thin layer above the current array API, availiable in the userspace and inter-operable with the current API.

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
    2 => 'three',
    3 => 'four',
    4 => 'five',
    5 => 'six',
    6 => 'seven',
    7 => 'eight',
    8 => 'nine'
}
```

## Scalar class helper for `array`

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
* Returns `array`

Example :

```php
<?php

$keys = ['one', 'two', 'three'];
$values = ['apple', 'melon', 'banana'];

$result = SplArray::combine($keys, $values);
var_dump($result);
```

```
array(3) {
    'one' => 'apple',
    'two' => 'melon',
    'three' => 'banana'
}
```

### Static method `range`

Create an array containing a range of elements

Equivalent to [`range`](http://php.net/manual/en/function.range.php)

* Parameter `$start`, of type `mixed`
* Parameter `$end`, of type `mixed`
* Parameter `$step`, of type `numeric`, defaults to `1`
* Returns `integer`

Example :

```php
<?php

$myArray = SplArray::range(0, 10, 2);

$result = $myArray->pair();
var_dump($result);
```

```
array(2) {
    0 => 0,
    1 => 2,
    2 => 4,
    3 => 6,
    4 => 8,
    5 => 10
}
```

### Static method `compact`

Create array containing variables and their values

Equivalent to [`compact`](http://php.net/manual/en/function.compact.php)

* Parameter `...$vars`, of type `mixed` (variadic)
* Returns `array`

Example :

```php
<?php

$one = 'one';
$two = 'two';
$three = 'three';

$result = SplArray::compact($one, $two, $three);
var_dump($result);
```

```
array(3) {
    0 => 'one',
    1 => 'two',
    2 => 'three'
}
```

### Static method `fill`

Fill an array with values

Equivalent to [`array_​fill`](http://php.net/manual/en/function.array-fill.php)

* Parameter `$startIndex`, of type `integer`
* Parameter `$count`, of type `integer`
* Parameter `$value`, of type `mixed`
* Returns `array`

Example :

```php
<?php

$result = SplArray::fill(0, 5, 'Initial value');
var_dump($result);
```

```
array(5) {
    0 => 'Initial value',
    1 => 'Initial value',
    2 => 'Initial value',
    3 => 'Initial value',
    4 => 'Initial value'
}
```

### Static method `fillKeys`

Fill an array with values, specifying keys

Equivalent to [`array_​fill_​keys`](http://php.net/manual/en/function.array-fill-keys.php)

* Parameter `$keys`, of type `array`
* Parameter `$value`, of type `mixed`
* Returns `array`

Example :

```php
<?php

$keys = ['one', 'two', 'three'];
$result = SplArray::fillKeys($keys, 'Initial value');
var_dump($result);
```

```
array(3) {
    'one' => 'Initial value',
    'two' => 'Initial value',
    'three' => 'Initial value'
}
```

### Method `changeKeyCase`

Changes the case of all keys in an array

Equivalent to [`array_change_key_case`](http://php.net/manual/en/function.array-change-key-case.php)

* Parameter `$size`, of type `integer`, defaults to `SplArray::CASE_LOWER`, possible values :
  * SplArray::CASE_LOWER
  * SplArray::CASE_UPPER
* Returns `array`

Example :

```php
<?php

$myArray = [
   'one' => 'apple',
   'two' => 'melon',
   'three' => 'banana'
];
$result = $myArray->changeKeyCase();
var_dump($result);
```

```
array(3) {
    'ONE' => 'apple',
    'TWO' => 'melon',
    'THREE' => 'banana'
}
```

### Method `chunk`

Split an array into chunks

Equivalent to [`array_chunk`](http://php.net/manual/en/function.array-chunk.php)

* Parameter `$size`, of type `integer`
* Parameter `$preserveKeys`, of type `boolean`, defaults to `false`
* Returns `array`

Example :

```php
<?php

$myArray = [
   'one',
   'two',
   'three',
   'four',
   'five'
];
$result = $myArray->chunk(2, true);
var_dump($result);
```

```
array(3) {
    0 => array(2) {
        0 => 'one',
        1 => 'two'
    },
    1 => array(2) {
        0 => 'three',
        1 => 'four'
    },
    2 => array(2) {
        0 => 'five'
    }
}
```

### Method `column`

Return the values from a single column in the input array

Equivalent to [`array_column`](http://php.net/manual/en/function.array-column.php)

* Parameter `$columnKey`, of type `mixed`
* Parameter `$indexKey`, of type `mixed`
* Returns `array`

Example :

```php
<?php

$records = array(
    array(
        'id' => 2135,
        'first_name' => 'John',
        'last_name' => 'Doe',
    ),
    array(
        'id' => 3245,
        'first_name' => 'Sally',
        'last_name' => 'Smith',
    ),
    array(
        'id' => 5342,
        'first_name' => 'Jane',
        'last_name' => 'Jones',
    ),
    array(
        'id' => 5623,
        'first_name' => 'Peter',
        'last_name' => 'Doe',
    )
);
$result = $records->chunk('first_name');
var_dump($result);
```

```
array(4) {
    0 => 'John'
    1 => 'Sally'
    2 => 'Jane'
    3 => 'Peter'
}
```

### Method `count`

Count elements of the array

Equivalent to [`sizeof`](http://php.net/manual/en/function.sizeof.php) and [`count`](http://php.net/manual/en/function.count.php).

Implements [`Countable::count`](http://php.net/manual/en/countable.count.php).

* Returns `integer`

Example :

```php
<?php

$myArray = [
   'one',
   'two',
   'three',
   'four',
   'five'
];
$result = $myArray->count();
var_dump($result);
```

```
int(5)
```

### Method `countValues`

Counts all the values of an array

Equivalent to [`array_count_values`](http://php.net/manual/en/function.array-count-values.php)

* Returns `array`

Example :

```php
<?php

$myArray = [1, 'hello', 1, 'world', 'hello'];
$result = $myArray->countValues();
var_dump($result);
```

```
array(3) {
    1 => 2,
    'hello' => 2,
    'world' => 1
}
```

### Method `flip`

Exchanges all keys with their associated values in an array

Equivalent to [`array_flip`](http://php.net/manual/en/function.array-flip.php)

* Returns `array`

Example :

```php
<?php

$myArray = [
    'one' => 'apple',
    'two' => 'melon',
    'three' => 'banana'
];
$result = $myArray->flip();
var_dump($result);
```

```
array(3) {
    'apple' => 'one',
    'melon' => 'two',
    'banana' => 'three'
}
```

### Method `pad`

Pad array to the specified length with a value

Equivalent to [`array_pad`](http://php.net/manual/en/function.array-pad.php)

* Returns `array`

Example :

```php
<?php

$myArray = [
    'one',
    'two',
    'three'
];
$result = $myArray->pad(5, 'unsetted value');
var_dump($result);
```

```
array(3) {
    0 => 'one',
    1 => 'two',
    2 => 'three',
    3 => 'unsetted value',
    4 => 'unsetted value'
}
```

### Method `reverse`

Return an array with elements in reverse order

Equivalent to [`array_reverse`](http://php.net/manual/en/function.array-reverse.php)

* Parameter `$preserveKeys`, of type `boolean`, defaults to `false`
* Returns `array`

Example :

```php
<?php

$myArray = [
    'apple',
    'melon',
    'banana'
];
$result = $myArray->reverse();
var_dump($result);
```

```
array(3) {
    0 => 'three',
    1 => 'two',
    2 => 'one'
}
```

### Method `unique`

Removes duplicate values from an array

Equivalent to [`array_unique`](http://php.net/manual/en/function.array-unique.php)

* Parameter `$sortFlags`, of type `integer`, defaults to `SplArray::SORT_STRING`
* Returns `array`

Example :

```php
<?php

$myArray = [
    'apple',
    'melon',
    'apple',
    'banana',
    'melon',
];
$result = $myArray->unique();
var_dump($result);
```

```
array(3) {
    0 => 'apple',
    1 => 'melon',
    2 => 'banana'
}
```

### Method `hasKey`

Checks if the given key or index exists in the array

Equivalent to [`array_key_exists`](http://php.net/manual/en/function.array-key-exists.php) and [`key_exists`](http://php.net/manual/en/function.array-key-exists.php)

* Parameter `$key`, of type `mixed`
* Returns `bool`

Example :

```php
<?php

$myArray = [
    'one' => 'apple',
    'two' => 'melon',
    'three' => 'banana'
];
$result = $myArray->hasKey('two');
var_dump($result);
```

```
bool(true)
```

### Method `has`

Checks if a value exists in an array

Equivalent to [`in_array`](http://php.net/manual/en/function.in-array.php)

* Parameter `$value`, of type `mixed`
* Returns `bool`

Example :

```php
<?php

$myArray = [
    'one' => 'apple',
    'two' => 'melon',
    'three' => 'banana'
];
$result = $myArray->hasKey('melon');
var_dump($result);
```

```
bool(true)
```

### Method `keys`

Return all the keys or a subset of the keys of an array

Equivalent to [`array_keys`](http://php.net/manual/en/function.array-keys.php)

* Returns `array`

Example :

```php
<?php

$myArray = [
    'one' => 'apple',
    'two' => 'melon',
    'three' => 'banana'
];
$result = $myArray->keys('melon');
var_dump($result);
```

```
array(3) {
    0 => 'one',
    1 => 'two',
    2 => 'three'
}
```

### Method `values`

Return all the values of an array

Equivalent to [`array_values`](http://php.net/manual/en/function.array-values.php)

* Returns `array`

Example :

```php
<?php

$myArray = [
    'one' => 'apple',
    'two' => 'melon',
    'three' => 'banana'
];
$result = $myArray->values('melon');
var_dump($result);
```

```
array(3) {
    0 => 'apple',
    1 => 'melon',
    2 => 'banana'
}
```

### Method `walk`

Apply a user supplied function to every member of an array

Equivalent to [`array_walk`](http://php.net/manual/en/function.array-walk.php)

* Parameter `$callback`, of type `callable`
* Parameter `$userdata`, of type `mixed`, defaults to `null`
* returns `bool`

Example :

```php
<?php

$myArray = [
    'one' => 'apple',
    'two' => 'melon',
    'three' => 'banana'
];
$result = $myArray->walk(function($value, $key, $pattern){
    return sprintf($pattern, $value);
}, '%s is a fruit');
var_dump($result);
```

```
array(3) {
    'one' => 'apple is a fruit',
    'two' => 'melon is a fruit',
    'three' => 'banana is a fruit'
}
```

### Method `recursiveWalk`

Apply a user function recursively to every member of an array

Equivalent to [`array_walk_recursive`](http://php.net/manual/en/function.array-walk-recursive.php)

* Parameter `$callback`, of type `callable`
* Parameter `$userdata`, of type `mixed`, defaults to `null`
* returns `bool`

Example :

```php
<?php

$myArray = [
    [
        'one' => 'apple',
        'two' => 'melon',
        'three' => 'banana'
    ], [
        'four' => 'strawberry',
        'five' => 'pineapple',
        'six' => 'lemon'
    ]
];
$result = $myArray->RecursiveWalk(function($value, $key, $pattern){
    return sprintf($pattern, $value);
}, '%s is a fruit');
var_dump($result);
```

```
array(2) {
    array(3) {
        'one' => 'apple is a fruit',
        'two' => 'melon is a fruit',
        'three' => 'banana is a fruit'
    },
    array(3) {
        'four' => 'strawberry is a fruit',
        'five' => 'pineapple is a fruit',
        'six' => 'lemon is a fruit'
    }
}
```

### Method `merge`

Merge one or more arrays

Equivalent to [`array_merge`](http://php.net/manual/en/function.array-merge.php)

* Parameter `...$mergedArray`, of type `array` (variadic)
* Returns `array`

Example :

```php
<?php

$myArray = [
    'apple',
    'melon',
    'banana'
];
$friendArray = [
    'strawberry',
    'pineapple',
    'lemon'
];
$result = $myArray->merge($friendArray);
var_dump($result);
```

```
array(5) {
    0 => 'apple',
    1 => 'melon',
    2 => 'banana',
    3 => 'strawberry',
    4 => 'pineapple',
    5 => 'lemon'
}
```

### Method `recursiveMerge`

Merge two or more arrays recursively

Equivalent to [`array_merge_recursive`](http://php.net/manual/en/function.array-merge-recursive.php)

* Parameter `...$mergedArray`, of type `array` (variadic)
* Returns `array`

Example :

```php
<?php

$myArray = [
    [
        'apple',
        'melon',
        'banana'
    ], [
        'strawberry',
        'pineapple'
    ]
];

$friendArray = [
    [
        'pineapple',
    ], [
        'lemon'
    ]
];

$result = $myArray->merge($friendArray);
var_dump($result);
```

```
array(2) {
    array(3) {
        0 => 'apple',
        1 => 'melon',
        2 => 'banana',
        3 => 'pineapple'
    },
    array(3) {
        0 => 'strawberry',
        1 => 'pineapple',
        2 => 'lemon'
    }
}
```

### Method `replace`

Replaces elements from passed arrays into the first array

Equivalent to [`array_replace`](http://php.net/manual/en/function.array-replace.php)

* Parameter `...$replacing`, of type `array` (variadic)
* Returns `array`

Example :

```php
<?php

$myArray = [
    'one' => 'apple',
    'two' => 'melon',
    'three' => 'banana'
];
$friendArray = [
    'three' => 'strawberry',
    'four' => 'pineapple',
    'five' => 'lemon'
];
$result = $myArray->replace($friendArray);
var_dump($result);
```

```
array(5) {
    'one' => 'apple',
    'two' => 'melon',
    'three' => 'strawberry',
    'four' => 'pineapple',
    'five' => 'lemon'
}
```

### Method `recursiveReplace`

Replaces elements from passed arrays into the first array recursively

Equivalent to [`array_replace_recursive`](http://php.net/manual/en/function.array-replace-recursive.php)

* Parameter `...$mergedArray`, of type `array` (variadic)
* Returns `array` (a copy of current array)

Example :

```php
<?php

$myArray = [
    [
        'one' => 'apple',
        'two' => 'melon',
        'three' => 'banana'
    ], [
        'four' => 'strawberry',
        'five' => 'pineapple'
    ]
];

$friendArray = [
    [
        'one' => 'pineapple',
    ], [
        'six' => 'lemon',
        'seven' => 'pear'
    ]
];

$result = $myArray->recursiveReplace($friendArray);
var_dump($result);
```

```
array(2) {
    array(3) {
        'one' => 'pineapple',
        'two' => 'melon',
        'three' => 'banana'
    },
    array(4) {
        'four' => 'strawberry',
        'five' => 'pineapple',
        'six' => 'lemon',
        'seven' => 'pear'
    }
}
```

### Method `search`

Searches the array for a given value and returns the corresponding key if successful

Equivalent to [`array_search`](http://php.net/manual/en/function.array-search.php)

* Parameter `$needle`, of type `mixed`
* Parameter `$strict`, of type `boolean`, defaults to `false`
* Returns `mixed`

Example :

```php
<?php

$myArray = [
    'one' => 'apple',
    'two' => 'melon',
    'three' => 'banana'
];
$result = $myArray->search('melon');
var_dump($result);
```

```
string(3) "two"
```

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
* Returns `array`

Example :

```php
<?php

$myArray = [
    'apple',
    'melon',
    'banana',
    'strawberry',
    'pineapple',
    'lemon'
];
$result = $myArray->slice(2, 3, true);
var_dump($result);
```

```
array(3) {
    2 => 'banana',
    3 => 'strawberry',
    4 => 'pineapple',
}
```

### Method `splice`

Remove a portion of the array and replace it with something else

Equivalent to [`array_splice`](http://php.net/manual/en/function.array-splice.php)

* Parameter `$offset`, of type `integer`
* Parameter `$length`, of type `integer`, defaults to `null`
* Parameter `$replacement`, of type `array`, defaults to *empty array*
* Returns `array`

Example :

```php
<?php

$myArray = [
    'apple',
    'melon',
    'banana',
    'strawberry',
    'pineapple',
    'lemon'
];

$result = $myArray->splice(2, 3, true);
var_dump($result);
```

```
array(3) {
    0 => 'apple',
    1 => 'melon',
    5 => 'lemon',
}
```

### Method `extract`

Import variables into the current symbol table from an array

Equivalent to [`extract`](http://php.net/manual/en/function.extract.php)

* Parameter `$flags`, of type `integer`, defaults to `SplArray::EXTR_OVERWRITE`
* Parameter `$prefix`, of type `string`, defaults to `null`
* Returns `integer`

Example :

```php
<?php

$myArray = [
    'one' => 'apple',
    'two' => 'melon',
    'three' => 'banana'
];

$result = $myArray->extract();
var_dump($one, $two, $three);
```

```
string(3) "one"
string(3) "two"
string(5) "three"
```

### Method `sum`

Calculate the sum of values in an array

Equivalent to [`array_sum`](http://php.net/manual/en/function.array-sum.php)

* Returns `number`

Example :

```php
<?php

$myArray = [2, 7, 14];

$result = $myArray->extract();
var_dump($result);
```

```
integer(23)
```

### Method `product`

Calculate the product of values in an array

Equivalent to [`array_product`](http://php.net/manual/en/function.array-product.php)

* Returns `number`

Example :

```php
<?php

$myArray = [2, 7, 14];

$result = $myArray->extract();
var_dump($result);
```

```
integer(196)
```

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

* Returns `array`

Example :

```php
<?php

$myArray = [
    'one' => 'apple'
];

$result = $myArray->pair();
var_dump($result);
```

```
array(2) {
    0 => 'one'
    1 => 'apple'
}
```

### Method `pop`

Pop the element off the end of array

Equivalent to [`array_pop`](http://php.net/manual/en/function.array-pop.php)

* Returns `mixed`

Example :

```php
<?php

$myArray = [
    'apple',
    'melon',
    'banana'
];

$result = $myArray->pop();
var_dump($result, $myArray);
```

```
string(3) "banana"
array(2) {
    0 => 'apple'
    1 => 'melon'
}
```

### Method `push`

Push one or more elements onto the end of array

Equivalent to [`array_push`](http://php.net/manual/en/function.array-push.php)

* Parameter `...$items`, of type `mixed` (variadic)
* Returns `void`

Example :

```php
<?php

$myArray = [
    'apple',
    'melon',
    'banana'
];

$myArray->push('pineapple');
var_dump($myArray);
```

```
array(2) {
    0 => 'melon',
    1 => 'banana',
    2 => 'banana',
    3 => 'pineapple'
}
```

### Method `shift`

Shift an element off the beginning of array

Equivalent to [`array_shift`](http://php.net/manual/en/function.array-shift.php)

* Returns `mixed`

Example :

```php
<?php

$myArray = [
    'apple',
    'melon',
    'banana'
];

$result = $myArray->shift();
var_dump($result, $myArray);
```

```
string(3) "apple"
array(2) {
    0 => 'melon'
    1 => 'banana'
}
```

### Method `unshift`

Prepend one or more elements to the beginning of an array

Equivalent to [`array_unshift`](http://php.net/manual/en/function.array-unshift.php)

* Parameter `...$items`, of type `mixed` (variadic)
* Returns `void`

Example :

```php
<?php

$myArray = [
    'apple',
    'melon',
    'banana'
];

$myArray->unshift('pineapple');
var_dump($myArray);
```

```
array(2) {
    0 => 'pineapple',
    1 => 'melon',
    2 => 'banana',
    3 => 'banana'
}
```

### Method `random`

Pick one random entry out of an array

Equivalent to [`array_rand`](http://php.net/manual/en/function.array-rand.php) when returning 1 item

* Returns `mixed`

Example :

```php
<?php

$myArray = [
    'one' => 'apple',
    'two' => 'melon',
    'three' => 'banana'
];

$result = $myArray->random();
var_dump($random);
```

```
string(3) "melon"
```

### Method `randomSlice`

Pick multiple random entries out of an array

Equivalent to [`array_rand`](http://php.net/manual/en/function.array-rand.php) when returning more than 1 item

* Parameter `$count`, of type `integer`, defaults to `1`
* Returns `array`

Example :

```php
<?php

$myArray = [
    'one' => 'apple',
    'two' => 'melon',
    'three' => 'banana'
];

$result = $myArray->randomSlice(2);
var_dump($result);
```

```
array(2) {
    0 => 'banana',
    1 => 'apple'
}
```

