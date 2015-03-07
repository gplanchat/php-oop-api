# PHP 7+ Object-oriented API - Computing array differences

## Interface `SplArrayDiff`

### Method `diff`

Common method for each derivative class, that has to be implemented.

* Parameter `...$comparedArray`, of type `SplArray` (variadic)
* Returns `SplArray`

## Class `SplValueArrayDiff`

Equivalent to [`array_diff`](http://php.net/manual/en/function.array-diff.php) and [`array_udiff`](http://php.net/manual/en/function.array-udiff.php)

If the `$callback` parameter is not specified or null, the class behaves like `array_diff`, else it behaves like `array_udiff`.

### Method `__construct`

* Parameter `$callback`, of type `callable`, defaults to `null`

### Method `diff`

* Parameter `...$comparedArray`, of type `SplArray` (variadic)
* Returns `SplArray`

## Class `SplAssociativeArrayDiff`

Equivalent to [`array_diff_assoc`](http://php.net/manual/en/function.array-diff-assoc.php) and [`array_udiff_assoc`](http://php.net/manual/en/function.array-udiff-assoc.php) and [`array_diff_uassoc`](http://php.net/manual/en/function.array-diff-uassoc.php) and [`array_udiff_uassoc`](http://php.net/manual/en/function.array-udiff-uassoc.php)

* If the `$keyCallback` and `$valueCallback` parameters are not specified or null, the class behaves like `array_diff_assoc`
* else if `$keyCallback` is specified and `$valueCallback` parameter is not specified or null it behaves like `array_diff_uassoc`
* else if `$keyCallback` is not specified or null and `$valueCallback` is specified it behaves like `array_udiff_assoc`
* else, both `$keyCallback` and `$valueCallback` are specified, it behaves like `array_udiff_uassoc`

### Method `__construct`

* Parameter `$keyCallback`, of type `callable`, defaults to `null`
* Parameter `$valueCallback`, of type `callable`, defaults to `null`

### Method `diff`

* Parameter `...$comparedArray`, of type `SplArray` (variadic)
* Returns `SplArray`

## Class `SplKeyArrayDiff`

Equivalent to [`array_diff_key`](http://php.net/manual/en/function.array-diff-key.php) and [`array_diff_ukey`](http://php.net/manual/en/function.array-diff-ukey.php)

If the `$callback` parameter is not specified or null, the class behaves like `array_diff_key`, else it behaves like `array_diff_ukey`.

### Method `__construct`

* Parameter `$callback`, of type `callable`, defaults to `null`

### Method `diff`

* Parameter `...$comparedArray`, of type `SplArray` (variadic)
* Returns `SplArray`
