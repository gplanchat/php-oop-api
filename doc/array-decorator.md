# PHP 7+ Object-oriented API - array decorators

## Abstract class SplArrayDecorator

Creates the foundations of a base class for decorating arrays and change the behavior of it,
bringing inversion of control to any routine, making it possible to change the array pointer
seeking mode or applying filters on the fly, without the need for the routine to be aware of it.

Implements :
* `IteratorAggregate`
* `Countable`
* `Serializable`
* `JsonSerializable`
* `ArrayAccess`

## Method `__construct`

* Parameter `$array`, of type `array`
