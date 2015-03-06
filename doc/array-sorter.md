# PHP Scalar objects API - Array sorters

This document describes the `array` scalar type's object-oriented sorting interface

Simple example :

```php
<?php

$example = ['strawberry', 'blackberry', 'raspberry', 'blueberry', 'cranberry'];

$sorter = new AlphaArraySOrter();
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



## Class `NaturalCaseArraySorter`

### Method `sort`

Equivalent to `natcasesort`

## Class `NaturalArraySorter`

### Method `sort`

Equivalent to `natsort`

## Class `ReverseArraySorter`

### Method `sort`

Equivalent to `rsort`

## Class `ShuffleArraySorter`

### Method `sort`

Equivalent to `shuffle`

## Class `StandardArraySorter`

### Method `sort`

Equivalent to `sort`

## Class `CustomKeyArraySorter`

### Method `sort`

Equivalent to `uksort`

## Class `CustomAssociativeArraySorter`

### Method `sort`

Equivalent to `uasort`

## Class `CustomAssociativeArraySorter`

### Method `usort`

Equivalent to `usort`


### Method `arsort`

Equivalent to `arsort`


### Method `asort`

Equivalent to `asort`


### Method `krsort`

Equivalent to `krsort`


### Method `ksort`

Equivalent to `ksort`


### Method `​rand`

Equivalent to `array_​rand`


### Method `​multisort`

Equivalent to `array_​multisort`
