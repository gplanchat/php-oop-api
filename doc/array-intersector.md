# PHP Scalar objects API - Array intersectors

Array intersectors 

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

Equivalent to :
* [`array_uintersect_key`](http://php.net/manual/fr/function.array-uintersect-key.php)
* [`array_intersect_ukey`](http://php.net/manual/fr/function.array-intersect-ukey.php)

### Method `__construct`

* Parameter `$valueCallback`, of type `callable`, defaults to `null`
* Parameter `$keyCallback`, of type `callable`, defaults to `null`

### Method `intersect`

* Parameter `...$subjectArray`, of type `array` (variadic)
* Returns `array`



### Method `​intersectCustom`

Equivalent to `array_​uintersect`
