# PHP 7+ Object-oriented API - Strings

This document describes the `string` scalar type's object-oriented base interface

## Scalar class helper for `string`


### Method `toLower`

Make a string lowercase

Equivalent to [`strtolower`](http://php.net/manual/fr/function.strtolower.php)

* Takes no parameter
* Returns `string`

Example:

```php
<?php

var_dump('BANANA'->toLower());
```

```
string(6) "banana"
```


### Method `toUpper`

Make a string uppercase

Equivalent to [`strtoupper`](http://php.net/manual/fr/function.strtoupper.php)

* Takes no parameter
* Returns `string`

Example:

```php
<?php

var_dump('apple'->toUpper());
```

```
string(5) "APPLE"
```

### Method `toLowerFirst`

Make a string's first character lowercase

Equivalent to [`lcfirst`](http://php.net/manual/fr/function.lcfirst.php)

* Takes no parameter
* Returns `string`

Example:

```php
<?php

var_dump('BANANA'->toLowerFirst());
```

```
string(6) "bANANA"
```

### Method `toUpperFirst`

Make a string's first character uppercase

Equivalent to [`ucfirst`](http://php.net/manual/fr/function.ucfirst.php)

* Takes no parameter
* Returns `string`

Example:

```php
<?php

var_dump('apple'->toUpperFirst());
```

```
string(5) "Apple"
```

### Method `toUpperWords`

Uppercase the first character of each word in a string

Equivalent to [`ucwords`](http://php.net/manual/fr/function.ucwords.php)

* Takes no parameter
* Returns `string`

Example:

```php
<?php

var_dump('apples and bananas'->toUpperFirst());
```

```
string(16) "Apples And Bananas"
```

### Method `length`

Get string length

Equivalent to [`strlen`](http://php.net/manual/fr/function.strlen.php)

* Takes no parameter
* Returns `integer`

Example:

```php
<?php

var_dump('\u1F500'->countChars());
```

In the case of a standard string :
```
int(3)
```

In the case of an *Unicode* string :
```
int(1)
```

### Method `countChars`

Return information about characters used in a string

Equivalent to [`count_chars`](http://php.net/manual/fr/function.count-chars.php)

* Parameter `$mode`, of type `integer`
* Returns `integer`

Values of `$mode` can be :
* `0`, an array with the byte-value as key and the frequency of every byte as value.
* `1`, same as `0` but only byte-values with a frequency greater than zero are listed.
* `2`, same as `0` but only byte-values with a frequency equal to zero are listed.
* `3`, a string containing all unique characters is returned.
* `4`, a string containing all not used characters is returned.

Example:

```php
<?php

var_dump('apple'->countChars(1));
```

```
array(4) {
    97 => 1,
    112 => 2,
    108 => 1,
    101 => 1
}
```

### Method `trim`

Strip whitespace (or other characters) from the beginning and end of a string

Equivalent to [`trim`](http://php.net/manual/fr/function.trim.php)

* Parameter `$characterMask`, of type `string`, defaults to `\x20\x09\x0A\x0D\x00\x0B`
* Returns `string`

Example:

```php
<?php

var_dump('     apple '->trim());
```

```
string(5) "apple"
```

### Method `trimRight`

Strip whitespace (or other characters) from the end of a string

Equivalent to [`rtrim`](http://php.net/manual/fr/function.rtrim.php) and [`chop`](http://php.net/manual/fr/function.chop.php)

* Parameter `$characterMask`, of type `string`, defaults to `\x20\x09\x0A\x0D\x00\x0B`
* Returns `string`

Example:

```php
<?php

var_dump('     apple '->trimRight());
```

```
string(10) "     apple"
```

### Method `trimLeft`

Strip whitespace (or other characters) from the beginning of a string

Equivalent to [`ltrim`](http://php.net/manual/fr/function.ltrim.php)

* Parameter `$characterMask`, of type `string`, defaults to `\x20\x09\x0A\x0D\x00\x0B`
* Returns `string`

Example:

```php
<?php

var_dump('     apple '->trimLeft());
```

```
string(6) "apple "
```

### Method `pad`

Pad a string to a certain length with another string

Equivalent to [`str_pad`](http://php.net/manual/fr/function.str-pad.php)

* Parameter `$padLength`, of type `integer`
* Parameter `$padString`, of type `string`, defaults to ` `
* Parameter `$padType`, of type `int`, defaults to `SplString::PAD_RIGHT`
* Returns `string`

Example:

```php
<?php

var_dump('apples'->pad(12, SplString::PAD_BOTH));
```

```
string(12) "   apples   "
```

### Method `chunkSplit`

Split a string into smaller chunks

Equivalent to [`split`](http://php.net/manual/fr/function.chunk-split.php)

* Parameter `$chunkLength`, of type `integer`, defaults to `76`
* Parameter `$separator`, of type `string`, defaults to `\r\n`
* Returns `string`

Example:

```php
<?php

var_dump('ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789'->chunkSplit(10));
```

```
string(12) "ABCDEFGHIJ
KLMNOPQRST
UVWXYZabcd
efghijklmn
opqrstuvwx
yz01234567
89"
```

### Method `shuffle`

Randomly shuffles a string

Equivalent to [`str_shuffle`](http://php.net/manual/fr/function.str-shuffle.php)

* Returns `string`

Example:

```php
<?php

var_dump('ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789'->shuffle());
```

```
string(62) "iBjaVeQ6hFwRqMDXISrW3ZAdGTmLkYEvJ1x89sU4fn72bopCOlgzc05KPtuHNy"
```

### Method `split`

Convert a string to an array

Equivalent to [`str_split`](http://php.net/manual/fr/function.str-split.php)

* Parameter `$chunkLength`, of type `integer`, defaults to `1`
* Returns `array`

Example:

```php
<?php

var_dump('ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789'->split(10));
```

```
array(7) {
    0 => "ABCDEFGHIJ",
    1 => "KLMNOPQRST",
    2 => "UVWXYZabcd",
    3 => "efghijklmn",
    4 => "opqrstuvwx",
    5 => "yz01234567",
    6 => "89"
}
```

### Method `wordCount`

Return information about words used in a string

Equivalent to [`str_word_count`](http://php.net/manual/fr/function.str-word-count.php), with value `0` passed to the `$format` parameter

* Parameter `$charList`, of type `string`, defaults to *empty string*
* Returns `integer`

Example:

```php
<?php

var_dump('Hello, friend, you are looking good today'->wordCount());
```

```
int(7)
```

### Method `words`

Return information about words used in a string

Equivalent to [`str_word_count`](http://php.net/manual/fr/function.str-word-count.php):
* natively with value `2` passed to the `$format` parameter.
* applying then the method `->values()` on the returned array brings the same functionality than the value `1` passed to the `$format` parameter.

* Parameter `$charList`, of type `string`, defaults to *empty string*
* Returns `integer`

Example:

```php
<?php

var_dump('Hello, friend, you are looking good today'->words());
```

```
array(7) {
    0 => "Hello",
    7 => "friend",
    15 => "you",
    19 => "are",
    23 => "looking",
    30 => "good",
    35 => "today"
}
```

### Method `explode`

Split a string by string

Equivalent to [`explode`](http://php.net/manual/fr/function.explode.php)

* Parameter `$separator`, of type `string`
* Parameter `$limit`, of type `integer`
* Returns `array`

Example:

```php
<?php

var_dump('Hello, friend, you are looking good today'->explode(','));
```

```
array(3) {
    0 => "Hello",
    1 => "friend",
    2 => "you are looking good today"
}
```







