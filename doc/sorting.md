# PHP 7+ Object-oriented API - Sorting collection data structures

## Abstract

This document describes a way to make uniform collections/array sorting in an OO-style.
It also suggests some new iterator `BidirectionalSeekableIterator` to handle more easily and effectively sortings.

A quicksort (actually very uneffective here) could be implemented this way :

```php
<?php

class UserlandQuickSortAlgorithmSorter
   implements CollectionSorter
{
    public function sort(SortableCollection $collection)
    {
        $this->quickSort($collection, $collection->first(), $collection->last());
    }

    private function quickSort(
        SortableCollection $collection,
        BidirectionalSeekableIterator $first,
        BidirectionalSeekableIterator $last
    ) {
        if ($first->distance($last) > 0) {
            $pivot = $this->partition($collection, $first, $last);

            $tmp = clone $pivot;
            if ($first->distance($tmp) > 1) {
                $tmp->previous();
                $this->quickSort($collection, $first, $tmp);
            } else if ($this->compare($pivot, $first)) {
                $collection->swap($pivot, $first);
            }

            $tmp = clone $pivot;
            if ($tmp->distance($last) > 1) {
                $tmp->next();
                $this->quickSort($collection, $tmp, $last);
            } else if (!$this->compare($pivot, $last)) {
                $collection->swap($last, $pivot);
            }
        }
    }

    private function compare(
        BidirectionalSeekableIterator $left,
        BidirectionalSeekableIterator $right
    ) {
        return (bool) ($left->current() < $right->current());
    }

    private function partition(
        SortableCollection $collection,
        BidirectionalSeekableIterator $first,
        BidirectionalSeekableIterator $last
    ) {
        $pivot = clone $first;
        $pivot->seek(ceil($first->distance($last) / 2), BidirectionalSeekableIterator::SEEK_CUR);

        $collection->swap($pivot, $last);

        $wall = clone $first;
        $iterator = clone $first;
        while ($iterator->distance($last) >= 1) {
            if ($this->compare($iterator, $last)) {
                $collection->swap($wall, $iterator);
                $wall->next();
            }
            $iterator->next();
        }
        $collection->swap($wall, $last);

        return $wall;
    }
}
```

For full example, see [sorting example](../examples/sorting.php)

## 

## Interface `BidirectionalSeekableIterator`

See [BidirectionalSeekableIterator.php](../classes/BidirectionalSeekableIterator.php)

Extends `SeekableIterator` 

### Constants

* `SEEK_SET` used to define a seeking position from the beginning of the iterable collection
* `SEEK_CUR` used to define a seeking position from the iterator's current position
* `SEEK_END` used to define a seeking position from the end of the iterable collection

### Method `distance`

Used to determine the distance between 2 iterators. The iterators *MUST* by the way iterate on the same collection.

* Parameter `$friend`, of type `BidirectionalSeekableIterator`
* Returns `integer`

### Method `seek`

Used to seek the iterator, this method already exists in `SeekableIterator`, but its prototypes changes slightly

* Parameter `$position`, of type `integer`
* Parameter `$whence`, of type `integer`, defaults to `BidirectionalSeekableIterator::SEEK_SET`, values between:
  * `BidirectionalSeekableIterator::SEEK_SET`
  * `BidirectionalSeekableIterator::SEEK_CUR`
  * `BidirectionalSeekableIterator::SEEK_END`
* Returns `void`

### Method `previous`

Seeks the iterator one position behind 

* Returns `void`

### Method `next`

Seeks the iterator one position ahead 

* Returns `void`

## Interface `Sortable`

See [BidirectionalSeekableIterator.php](../classes/Sortable.php)

This interface defines no method and cannot be directly implemented in user-space.
It is used internally to mark objects as sortable.

* Extends `Traversable`
* Extends `Countable`

## Interface `Sorter`

This interface defines no method and cannot be directly implemented in user-space.
It is used internally to mark objects as sorters algorithms.

## Interface `SortableCollection`

See [BidirectionalSeekableIterator.php](../classes/SortableCollection.php)

This interface defines how collections that are sortable should behave.
Sorting algorithms then has some ways to change de items orders by swapping
them and some ways to simply get seekable and bi-directional iterators.

* Extends `Sortable`
* Extends `IteratorAggregate`

### Method `swap`

Swaps two values between them in the collection

* Parameter `$leftKey` of type `BidirectionalSeekableIterator`
* Parameter `$rightKey` of type `BidirectionalSeekableIterator`
* Returns `void`

### Method `first`

Returns a new `BidirectionalSeekableIterator`, initialized at the beginning of the collection

* Takes no parameter
* Returns `BidirectionalSeekableIterator`, positioned to the first element

### Method `last`

Returns a new `BidirectionalSeekableIterator`, initialized at the end of the collection

* Takes no parameter
* Returns `BidirectionalSeekableIterator`, positioned to the last element

### Method `getIterator`

Returns a new `BidirectionalSeekableIterator`

* Takes no parameter
* Returns `BidirectionalSeekableIterator`, positioned to the first element

## Interface `CollectionSorter`

See [BidirectionalSeekableIterator.php](../classes/CollectionSorter.php)

This interface defines the base interface a collection sorter should have.
It actually exposes a `sort` method, the worker method and also a `compare`
method, used to compare two positions between them in the collection.

### Method `sort`

This method implements the sorting algorithm.

* Parameter `$collection` of type `SortableCollection`
* Returns `SortableCollection`

### Method `compare`

This method is used to compare two positions in the collection, and returns a boolean :
* `true` when the two items should be swapped
* `false` when no action should be done

* Parameter `$left` of type `BidirectionalSeekableIterator`
* Parameter `$right` of type `BidirectionalSeekableIterator`
* Returns `boolean`

## Interface `SortableAggregate`

* Extends `Sortable`

This interface is used by objects containing a collection and which should need to make
its internal collection sortable, depending on external conditions.

This is intended to avoid the need to use decorator patterns for objects encapsulating a collection.

### Method `sort`

* Parameter `$sorter` of type `Sorter`
* Returns `void`
