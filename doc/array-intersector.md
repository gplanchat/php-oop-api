# PHP Scalar objects API - Array intersectors

Array intersectors 

```php
<?php

$array1 = [2, 4, 6, 8, 10, 12];
$array2 = [1, 2, 3, 4, 5, 6];

$intersector = new SplByValueArrayIntersector();
var_dump($intersector->intersect($array1, $array2));
var_dump($intersector->intersect($array2, $array1));
```

```
array(3) {
  [0]=> int(2)
  [1]=> int(4)
  [2]=> int(6)
}

array(3) {
  [1]=> int(2)
  [3]=> int(4)
  [5]=> int(6)
}
```

## Interface `SplArrayIntersector`

### Method `intersect`

* Parameter `...$comparedArray`, of type `Spl\Array` (variadic)
* Returns `Spl\Array`

## Class `SplByValueArrayIntersector`

Computes the intersection of arrays

Equivalent to [`array_intersect`](http://php.net/manual/fr/function.array-intersect.php)

### Method `intersect`

* Parameter `...$subjectArray`, of type `array` (variadic)
* Returns `array`

## Class `SplByKeyArrayIntersector`

Computes the intersection of arrays

Equivalent to [`array_intersect_key`](http://php.net/manual/fr/function.array-intersect-key.php)

### Method `intersect`

* Parameter `...$subjectArray`, of type `array` (variadic)
* Returns `array`

## Class `SplAssociativeArrayIntersector`

Computes the intersection of arrays

Equivalent to [`array_intersect_assoc`](http://php.net/manual/fr/function.array-intersect-assoc.php)

### Method `intersect`

* Parameter `...$subjectArray`, of type `array` (variadic)
* Returns `array`

## Class `SplCustomAssociativeArrayIntersector`

Computes the intersection of arrays

Equivalent to :
* [`array_intersect_assoc`](http://php.net/manual/fr/function.array-intersect-assoc.php)
* [`array_uintersect_uassoc`](http://php.net/manual/fr/function.array-uintersect-uassoc.php)
* [`array_intersect_uassoc`](http://php.net/manual/fr/function.array-intersect-uassoc.php)
* [`array_uintersect_assoc`](http://php.net/manual/fr/function.array-uintersect-assoc.php)

### Method `__construct`

* Parameter `$valueCallback`, of type `callable`, defaults to `null`
* Parameter `$keyCallback`, of type `callable`, defaults to `null`

### Method `intersect`

* Parameter `...$subjectArray`, of type `array` (variadic)
* Returns `array`

## Class `SplCustomByKeyArrayIntersector`

Computes the intersection of arrays

Equivalent to [`array_intersect_ukey`](http://php.net/manual/fr/function.array-intersect-ukey.php)

### Method `__construct`

* Parameter `$valueCallback`, of type `callable`, defaults to `null`
* Parameter `$keyCallback`, of type `callable`, defaults to `null`

### Method `intersect`

* Parameter `...$subjectArray`, of type `array` (variadic)
* Returns `array`

## Class `SplCustomByValueArrayIntersector`

Computes the intersection of arrays

Equivalent to [`array_uintersect`](http://php.net/manual/fr/function.array-uintersect.php)

### Method `intersect`

* Parameter `...$subjectArray`, of type `array` (variadic)
* Returns `array`
