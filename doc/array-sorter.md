# PHP Scalar objects API - Array sorters

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

### Abstract method `sort`

* Parameter `$array`, of type `array`
* Returns `array`

## Class `SplAlphaArraySorter`

### Method `asort`

Equivalent to [`asort`](http://php.net/manual/en/function.asort.php)

* Parameter `$array`, of type `array`
* Returns `array`

## Class `SplAlphaReverseArraySorter`

### Method `sort`

Equivalent to [`arsort`](http://php.net/manual/en/function.arsort.php)

* Parameter `$array`, of type `array`
* Returns `array`

## Class `SplKeyArraySorter`

### Method `ksort`

Equivalent to `ksort`

Equivalent to [`ksort`](http://php.net/manual/en/function.ksort.php)

* Parameter `$array`, of type `array`
* Returns `array`

## Class `SplReverseKeyArraySorter`

### Method `sort`

Equivalent to [`krsort`](http://php.net/manual/en/function.krsort.php)

* Parameter `$array`, of type `array`
* Returns `array`

## Class `SplStandardArraySorter`

### Method `sort`

Equivalent to [`sort`](http://php.net/manual/en/function.sort.php)

* Parameter `$array`, of type `array`
* Returns `array`

## Class `SplReverseStandardArraySorter`

### Method `sort`

Equivalent to [`rsort`](http://php.net/manual/en/function.rsort.php)

* Parameter `$array`, of type `array`
* Returns `array`

## Class `SplCustomArraySorter`

### Method `sort`

Equivalent to [`usort`](http://php.net/manual/en/function.usort.php)

* Parameter `$array`, of type `array`
* Returns `array`

## Class `SplCustomKeyArraySorter`

### Method `__construct`

* Parameter `$callback`, of type `callable`

## Class `SplCustomAssociativeArraySorter`

### Method `sort`

Equivalent to [`uasort`](http://php.net/manual/en/function.uasort.php)

* Parameter `$array`, of type `array`
* Returns `array`

### Method `sort`

Equivalent to [`uksort`](http://php.net/manual/en/function.uksort.php)

* Parameter `$array`, of type `array`
* Returns `array`

## Class `SplShuffleArraySorter`

### Method `sort`

Equivalent to [`shuffle`](http://php.net/manual/en/function.shuffle.php)

* Parameter `$array`, of type `array`
* Returns `array`

## Class `SplNaturalCaseSensitiveArraySorter`

### Method `sort`

Equivalent to [`natcasesort`](http://php.net/manual/en/function.natcasesort.php)

* Parameter `$array`, of type `array`
* Returns `array`

## Class `SplNaturalArraySorter`

### Method `sort`

Equivalent to [`natsort`](http://php.net/manual/en/function.natsort.php)

* Parameter `$array`, of type `array`
* Returns `array`





### Method `rand`

Equivalent to `array_rand`


### Method `multisort`

Equivalent to `array_​multisort`
