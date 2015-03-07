

## Interface `SplArrayDiff`

### Method `diff`

Common method for each derivative class, that has to be implemented.

* Parameter `...$comparedArray`, of type `SplArray` (variadic)
* Returns `SplArray`

## Class `SplValueArrayDiff`

Equivalent to [`array_diff`](http://php.net/manual/en/function.array-diff.php)

### Method `diff`

* Parameter `...$comparedArray`, of type `SplArray` (variadic)
* Returns `SplArray`

## Class `SplCustomValueArrayDiff`

Equivalent to [`array_udiff`](http://php.net/manual/en/function.array-udiff.php)

### Method `diff`

* Parameter `...$comparedArray`, of type `SplArray` (variadic)
* Returns `SplArray`




### Method `compareKeys`

Equivalent to `array_diff_key`

* Parameter `...$comparedArray`, of type `Spl\Array` (variadic)
* Returns `Spl\Array`

### Method `compareBoth`

Equivalent to `array_diff_assoc`

* Parameter `$callback`, of type `callable`
* Parameter `...$comparedArray`, of type `Spl\Array` (variadic)
* Returns `Spl\Array`

### Method `compareKeysCustom`

Equivalent to `array_diff_ukey`

* Parameter `$callback`, of type `callable`
* Parameter `...$comparedArray`, of type `Spl\Array` (variadic)
* Returns `Spl\Array`

### Method `compareBothCustom`

Equivalent to `array_diff_uassoc`

* Parameter `...$comparedArray`, of type `Spl\Array` (variadic)
* Returns `Spl\Array`


### Method `​udiff_​assoc`

Equivalent to `array_​udiff_​assoc`


### Method `​udiff_​uassoc`

Equivalent to `array_​udiff_​uassoc`


### Method `​udiff`

Equivalent to `array_​udiff`
