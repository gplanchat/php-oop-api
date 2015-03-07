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

### Method `str_pad`

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







### Method `chr`

Return a specific character

Equivalent to [`chr`](http://php.net/manual/fr/function.chr.php)


### Method `chunk_split`

Split a string into smaller chunks

Equivalent to [`chunk_split`](http://php.net/manual/fr/function.chunk-split.php)


### Method `convert_cyr_string`

Convert from one Cyrillic character set to another

Equivalent to [`convert_cyr_string`](http://php.net/manual/fr/function.convert-cyr-string.php)


### Method `convert_uudecode`

Decode a uuencoded string

Equivalent to [`convert_uudecode`](http://php.net/manual/fr/function.convert-uudecode.php)


### Method `convert_uuencode`

Uuencode a string

Equivalent to [`convert_uuencode`](http://php.net/manual/fr/function.convert-uuencode.php)



### Method `echo`

Output one or more strings

Equivalent to [`echo`](http://php.net/manual/fr/function.echo.php)


### Method `explode`

Split a string by string

Equivalent to [`explode`](http://php.net/manual/fr/function.explode.php)


### Method `implode`

Join array elements with a string

Equivalent to [`implode`](http://php.net/manual/fr/function.implode.php) and [`join`](http://php.net/manual/fr/function.join.php)


### Method `levenshtein`

Calculate Levenshtein distance between two strings

Equivalent to [`levenshtein`](http://php.net/manual/fr/function.levenshtein.php)


### Method `localeconv`

Get numeric formatting information

Equivalent to [`localeconv`](http://php.net/manual/fr/function.localeconv.php)


### Method `metaphone`

Calculate the metaphone key of a string

Equivalent to [`metaphone`](http://php.net/manual/fr/function.metaphone.php)


### Method `money_format`

Formats a number as a currency string

Equivalent to [`money_format`](http://php.net/manual/fr/function.money-format.php)


### Method `nl_langinfo`

Query language and locale information

Equivalent to [`nl_langinfo`](http://php.net/manual/fr/function.nl-langinfo.php)


### Method `nl2br`

Inserts HTML line breaks before all newlines in a string

Equivalent to [`nl2br`](http://php.net/manual/fr/function.nl2br.php)


### Method `number_format`

Format a number with grouped thousands

Equivalent to [`number_format`](http://php.net/manual/fr/function.number-format.php)


### Method `ord`

Return ASCII value of character

Equivalent to [`ord`](http://php.net/manual/fr/function.ord.php)


### Method `parse_str`

Parses the string into variables

Equivalent to [`parse_str`](http://php.net/manual/fr/function.parse-str.php)


### Method `print`

Output a string

Equivalent to [`print`](http://php.net/manual/fr/function.print.php)


### Method `quoted_printable_decode`

Convert a quoted-printable string to an 8 bit string

Equivalent to [`quoted_printable_decode`](http://php.net/manual/fr/function.quoted-printable-decode.php)


### Method `quoted_printable_encode`

Convert a 8 bit string to a quoted-printable string

Equivalent to [`quoted_printable_encode`](http://php.net/manual/fr/function.quoted-printable-encode.php)


### Method `quotemeta`

Quote meta characters

Equivalent to [`quotemeta`](http://php.net/manual/fr/function.quotemeta.php)


### Method `setlocale`

Set locale information

Equivalent to [`setlocale`](http://php.net/manual/fr/function.setlocale.php)


### Method `similar_text`

Calculate the similarity between two strings

Equivalent to [`similar_text`](http://php.net/manual/fr/function.similar-text.php)


### Method `soundex`

Calculate the soundex key of a string

Equivalent to [`soundex`](http://php.net/manual/fr/function.soundex.php)


### Method `str_getcsv`

Parse a CSV string into an array

Equivalent to [`str_getcsv`](http://php.net/manual/fr/function.str-getcsv.php)


### Method `str_ireplace`

Case-insensitive version of str_replace.

Equivalent to [`str_ireplace`](http://php.net/manual/fr/function.str-ireplace.php)


### Method `str_repeat`

Repeat a string

Equivalent to [`str_repeat`](http://php.net/manual/fr/function.str-repeat.php)


### Method `str_replace`

Replace all occurrences of the search string with the replacement string

Equivalent to [`str_replace`](http://php.net/manual/fr/function.str-replace.php)


### Method `str_rot13`

Perform the rot13 transform on a string

Equivalent to [`str_rot13`](http://php.net/manual/fr/function.str-rot13.php)


### Method `str_shuffle`

Randomly shuffles a string

Equivalent to [`str_shuffle`](http://php.net/manual/fr/function.str-shuffle.php)


### Method `str_split`

Convert a string to an array

Equivalent to [`str_split`](http://php.net/manual/fr/function.str-split.php)


### Method `str_word_count`

Return information about words used in a string

Equivalent to [`str_word_count`](http://php.net/manual/fr/function.str-word-count.php)


### Method `strcoll`

Locale based string comparison

Equivalent to [`strcoll`](http://php.net/manual/fr/function.strcoll.php)


### Method `strcspn`

Find length of initial segment not matching mask

Equivalent to [`strcspn`](http://php.net/manual/fr/function.strcspn.php)


### Method `stripos`

Find the position of the first occurrence of a case-insensitive substring in a string

Equivalent to [`stripos`](http://php.net/manual/fr/function.stripos.php)


### Method `stristr`

Case-insensitive strstr

Equivalent to [`stristr`](http://php.net/manual/fr/function.stristr.php)


### Method `strpbrk`

Search a string for any of a set of characters

Equivalent to [`strpbrk`](http://php.net/manual/fr/function.strpbrk.php)


### Method `strpos`

Find the position of the first occurrence of a substring in a string

Equivalent to [`strpos`](http://php.net/manual/fr/function.strpos.php)


### Method `strrchr`

Find the last occurrence of a character in a string

Equivalent to [`strrchr`](http://php.net/manual/fr/function.strrchr.php)


### Method `strrev`

Reverse a string

Equivalent to [`strrev`](http://php.net/manual/fr/function.strrev.php)


### Method `strripos`

Find the position of the last occurrence of a case-insensitive substring in a string

Equivalent to [`strripos`](http://php.net/manual/fr/function.strripos.php)


### Method `strrpos`

Find the position of the last occurrence of a substring in a string

Equivalent to [`strrpos`](http://php.net/manual/fr/function.strrpos.php)


### Method `strspn`

Finds the length of the initial segment of a string consisting entirely of characters contained within a given mask.

Equivalent to [`strspn`](http://php.net/manual/fr/function.strspn.php)


### Method `strstr`

Find the first occurrence of a string

Equivalent to [`strstr`](http://php.net/manual/fr/function.strstr.php) and [`strchr`](http://php.net/manual/fr/function.strchr.php)


### Method `strtok`

Tokenize string

Equivalent to [`strtok`](http://php.net/manual/fr/function.strtok.php)


### Method `strtr`

Translate characters or replace substrings

Equivalent to [`strtr`](http://php.net/manual/fr/function.strtr.php)


### Method `substr_compare`

Binary safe comparison of two strings from an offset, up to length characters

Equivalent to [`substr_compare`](http://php.net/manual/fr/function.substr-compare.php)


### Method `substr_count`

Count the number of substring occurrences

Equivalent to [`substr_count`](http://php.net/manual/fr/function.substr-count.php)


### Method `substr_replace`

Replace text within a portion of a string

Equivalent to [`substr_replace`](http://php.net/manual/fr/function.substr-replace.php)


### Method `substr`

Return part of a string

Equivalent to [`substr`](http://php.net/manual/fr/function.substr.php)


### Method `wordwrap`

Wraps a string to a given number of characters

Equivalent to [`wordwrap`](http://php.net/manual/fr/function.wordwrap.php)



--- Internationalization related

### Method `hebrev`

Convert logical Hebrew text to visual text

Equivalent to [`hebrev`](http://php.net/manual/fr/function.hebrev.php)


### Method `hebrevc`

Convert logical Hebrew text to visual text with newline conversion

Equivalent to [`hebrevc`](http://php.net/manual/fr/function.hebrevc.php)





--- Streams related

### Method `vfprintf`

Write a formatted string to a stream

Equivalent to [`vfprintf`](http://php.net/manual/fr/function.vfprintf.php)


### Method `vprintf`

Output a formatted string

Equivalent to [`vprintf`](http://php.net/manual/fr/function.vprintf.php)


### Method `vsprintf`

Return a formatted string

Equivalent to [`vsprintf`](http://php.net/manual/fr/function.vsprintf.php)


### Method `fprintf`

Write a formatted string to a stream

Equivalent to [`fprintf`](http://php.net/manual/fr/function.fprintf.php)


### Method `printf`

Output a formatted string

Equivalent to [`printf`](http://php.net/manual/fr/function.printf.php)


### Method `sprintf`

Return a formatted string

Equivalent to [`sprintf`](http://php.net/manual/fr/function.sprintf.php)


### Method `sscanf`

Parses input from a string according to a format

Equivalent to [`sscanf`](http://php.net/manual/fr/function.sscanf.php)



--- Cryptography related

### Method `crc32`

Calculates the crc32 polynomial of a string

Equivalent to [`crc32`](http://php.net/manual/fr/function.crc32.php)


### Method `crypt`

One-way string hashing

Equivalent to [`crypt`](http://php.net/manual/fr/function.crypt.php)


### Method `sha1_file`

Calculate the sha1 hash of a file

Equivalent to [`sha1_file`](http://php.net/manual/fr/function.sha1-file.php)


### Method `sha1`

Calculate the sha1 hash of a string

Equivalent to [`sha1`](http://php.net/manual/fr/function.sha1.php)



### Method `md5_file`

Calculates the md5 hash of a given file

Equivalent to [`md5_file`](http://php.net/manual/fr/function.md5-file.php)


### Method `md5`

Calculate the md5 hash of a string

Equivalent to [`md5`](http://php.net/manual/fr/function.md5.php)






--- Quoting related 


### Method `addcslashes`

Quote string with slashes in a C style

Equivalent to [`addcslashes`](http://php.net/manual/fr/function.addcslashes.php)


### Method `addslashes`

Quote string with slashes

Equivalent to [`addslashes`](http://php.net/manual/fr/function.addslashes.php)


### Method `strip_tags`

Strip HTML and PHP tags from a string

Equivalent to [`strip_tags`](http://php.net/manual/fr/function.strip-tags.php)


### Method `stripcslashes`

Un-quote string quoted with addcslashes

Equivalent to [`stripcslashes`](http://php.net/manual/fr/function.stripcslashes.php)


### Method `stripslashes`

Un-quotes a quoted string

Equivalent to [`stripslashes`](http://php.net/manual/fr/function.stripslashes.php)


### Method `get_html_translation_table`

Returns the translation table used by htmlspecialchars and htmlentities

Equivalent to [`get_html_translation_table`](http://php.net/manual/fr/function.get-html-translation-table.php)


### Method `html_entity_decode`

Convert all HTML entities to their applicable characters

Equivalent to [`html_entity_decode`](http://php.net/manual/fr/function.html-entity-decode.php)


### Method `htmlentities`

Convert all applicable characters to HTML entities

Equivalent to [`htmlentities`](http://php.net/manual/fr/function.htmlentities.php)


### Method `htmlspecialchars_decode`

Convert special HTML entities back to characters

Equivalent to [`htmlspecialchars_decode`](http://php.net/manual/fr/function.htmlspecialchars-decode.php)


### Method `htmlspecialchars`

Convert special characters to HTML entities

Equivalent to [`htmlspecialchars`](http://php.net/manual/fr/function.htmlspecialchars.php)





--- Comparison related



### Method `strcasecmp`

Binary safe case-insensitive string comparison

Equivalent to [`strcasecmp`](http://php.net/manual/fr/function.strcasecmp.php)


### Method `strcmp`

Binary safe string comparison

Equivalent to [`strcmp`](http://php.net/manual/fr/function.strcmp.php)


### Method `strnatcasecmp`

Case insensitive string comparisons using a "natural order" algorithm

Equivalent to [`strnatcasecmp`](http://php.net/manual/fr/function.strnatcasecmp.php)


### Method `strnatcmp`

String comparisons using a "natural order" algorithm

Equivalent to [`strnatcmp`](http://php.net/manual/fr/function.strnatcmp.php)


### Method `strncasecmp`

Binary safe case-insensitive string comparison of the first n characters

Equivalent to [`strncasecmp`](http://php.net/manual/fr/function.strncasecmp.php)


### Method `strncmp`

Binary safe string comparison of the first n characters

Equivalent to [`strncmp`](http://php.net/manual/fr/function.strncmp.php)





--- Conversion related

### Method `bin2hex`

Convert binary data into hexadecimal representation

Equivalent to [`bin2hex`](http://php.net/manual/fr/function.bin2hex.php)

### Method `hex2bin`

Decodes a hexadecimally encoded binary string

Equivalent to [`hex2bin`](http://php.net/manual/fr/function.hex2bin.php)