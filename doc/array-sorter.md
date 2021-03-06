# PHP 7+ Object-oriented API - Array sorters

This document describes the `array` scalar type's object-oriented sorting interface

Simple example :

```php
<?php

$example = ['strawberry', 'blackberry', 'raspberry', 'blueberry', 'cranberry'];

$sorter = new SplAlphaArraySorter();
$sortedArray = $sorter->sort($example);

var_dump($sortedArray);
```

```
array(5) {
    0 => 'blackberry',
    1 => 'blueberry',
    2 => 'cranberry',
    3 => 'raspberry',
    4 => 'strawberry'
}
```

## Abstract class `SplArraySorter`

Implements:

* `CollectionSorter` (see [Sorting API](sorting.md))

### Abstract method `sort`

Prototype:
* Parameter `$array`, of type `array`
* Returns `array`

## Class `SplAlphaArraySorter`

Extends:

* `SplArraySorter`

### Method `asort`

Equivalent to:
* [`asort`](http://php.net/manual/en/function.asort.php)
* [`arsort`](http://php.net/manual/en/function.arsort.php) (in conjunction with a `SplReverseArraySorter`)

Prototype:
* Parameter `$array`, of type `array`
* Returns `array`

## Class `SplKeyArraySorter`

Extends:

* `SplArraySorter`

### Method `sort`

Equivalent to `ksort`

Equivalent to:
* [`ksort`](http://php.net/manual/en/function.ksort.php)
* [`krsort`](http://php.net/manual/en/function.krsort.php) (in conjunction with a `SplReverseArraySorter`)

Prototype:
* Parameter `$array`, of type `array`
* Returns `array`

## Class `SplStandardArraySorter`

Extends:

* `SplArraySorter`

### Method `sort`

Equivalent to:
* [`sort`](http://php.net/manual/en/function.sort.php)
* [`rsort`](http://php.net/manual/en/function.rsort.php) (in conjunction with a `SplReverseArraySorter`)

Prototype:
* Parameter `$array`, of type `array`
* Returns `array`

## Class `SplCustomArraySorter`

Extends:

* `SplArraySorter`

### Method `__construct`

Prototype:
* Parameter `$callback`, of type `callable`

### Method `sort`

Equivalent to [`usort`](http://php.net/manual/en/function.usort.php)

Prototype:
* Parameter `$array`, of type `array`
* Returns `array`

## Class `SplCustomAssociativeArraySorter`

Extends:

* `SplArraySorter`

### Method `__construct`

Prototype:
* Parameter `$callback`, of type `callable`

### Method `sort`

Equivalent to [`uasort`](http://php.net/manual/en/function.uasort.php)

Prototype:
* Parameter `$array`, of type `array`
* Returns `array`

## Class `SplCustomKeyArraySorter`

Extends:

* `SplArraySorter`

### Method `__construct`

Prototype:
* Parameter `$callback`, of type `callable`

### Method `sort`

Equivalent to [`uksort`](http://php.net/manual/en/function.uksort.php)

Prototype:
* Parameter `$array`, of type `array`
* Returns `array`

## Class `SplShuffleArraySorter`

Extends:

* `SplArraySorter`

### Method `sort`

Equivalent to [`shuffle`](http://php.net/manual/en/function.shuffle.php)

Prototype:
* Parameter `$array`, of type `array`
* Returns `array`

## Class `SplNaturalCaseSensitiveArraySorter`

Extends:

* `SplArraySorter`

### Method `sort`

Equivalent to [`natcasesort`](http://php.net/manual/en/function.natcasesort.php)

Prototype:
* Parameter `$array`, of type `array`
* Returns `array`

## Class `SplNaturalArraySorter`

Extends:

* `SplArraySorter`

### Method `sort`

Equivalent to [`natsort`](http://php.net/manual/en/function.natsort.php)

Prototype:
* Parameter `$array`, of type `array`
* Returns `array`

## Class `SplChainingArraySorter`

Extends:

* `SplArraySorter`

### Method `__construct`

Initantiates a multi-sorter, with in parameter every internal sorter

Prototype:
* Parameter `...$sorters`, of type `SplArraySorter` (variadic)

### Method `add`

Adds multiple internal sorters in the multi-sorter

Prototype:
* Parameter `...$sorters`, of type `SplArraySorter` (variadic)

### Method `remove`

Removes multiple internal sorters from the multi-sorter

Prototype:
* Parameter `...$sorters`, of type `SplArraySorter` (variadic)

### Method `sort`

Equivalent to [`array_multisort`](http://php.net/manual/en/function.array-multisort.php)

Prototype:
* Parameter `$array`, of type `array`
* Returns `array`

## Class `SplReverseArraySorter`

Extends:

* `SplArraySorter`

### Method `__construct`

Initantiates a reverse sorter, with in parameter the internal sorter

Prototype:
* Parameter `$sorter`, of type `SplArraySorter`

### Method `sort`

Prototype:
* Parameter `$array`, of type `array`
* Returns `array`
