# PHP 7+ Object-oriented API for Scalar, String and Arrays

These documents describes a new API for scalar values in PHP, fully object-oriented,
but keeping in mind the interoperability with PHP's historic procedural API. This API
must keep using *ZVAL*s as they are used today, but add a new way to manage them, bringing
all the advantages OOP can have.

This work takes inspiration from Nikita Popov's [scalar objects](https://github.com/nikic/scalar_objects)
extension for the method of attaching a class to a special scalar type and from the
[PECL SPL types](http://php.net/manual/en/book.spl-types.php) extension for the base class structures.

Every functionality maps to a currently existing functionnality in the procedural API and must behave the same way.

## The Scalar API

This API comes with all the functionnalities you will need to interact with a scalar, these classes
are already availiable in the [PECL SPL Types extension](http://php.net/manual/en/book.spl-types.php).

One difference to add here is the creation of a new class called `SplNumber`, parent of the classes below :

* `SplInt`
* `SplFloat`
* `SplBool`

This API also comes with a `SplEnum` special type, built to bring the enum construct.

**todo**

## The String API

### [Base API](doc/string.md)

This base API comes with all the base functionnalities you will need to interact with a string, these are
methods of an `SplString` class availiable in the [PECL SPL Types extension](http://php.net/manual/en/book.spl-types.php) and ehances it with a fill API, independent from classic string functions.

### Decorator API

This API implements fluent string escaping and transformation (HTML, SQL, console, ect...)

**todo**

### Cyphering and hashing API

All the hashing and cyphering API (md5, sha, ect...)

**todo**

## The Array API

This is *NOT* a reimplementation of `ArrayObject`, this API would in fact make it useless.

### [Base API](doc/array.md)

This base API comes with all the base functionnalities you will need to interact with an array, these are
methods of an `SplArray` class.

### [Sorting API](doc/array-sorter.md)

Brings sorting functionalities to arrays, from basic numeric or alphanumeric sorting to user-defined sorting.

### [Intersection API](doc/array-intersector.md)

These classes brings the array intersection routines, from simple keyed-intersection to more complex and
user-defined rules.

### [Comparator API](doc/array-comparator.md)

Ability to compare arrays, by keys, values, both, depending on user-defined comparison functions, ect...

### [Decorator API](doc/array-decorator.md)

Ability to decorate arrays, changing its visible behavior whithout the need for reimplementing legacy or vendor code
