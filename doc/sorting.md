# PHP 7+ Object-oriented API - Sorting collection data structures

This document decribes a way to make uniform collections/array sorting in an OO-style.

It also suggests some upgrades to the `SeekableIterator` (with BC break) to handle more easily and effectively sortings.

A quicksort (actually very uneffective) could be implemented this way :

```php
<?php

class UserlandQuickSortAlgorithmSorter
   implements CollectionSorter
{
    public function sort(SortableCollection $collection)
    {
        $this->quickSort($collection, $collection->first(), $collection->last());
    }

    private function quickSort(SortableCollection $collection, Iterator $first, Iterator $last)
    {
        $iterator = clone $first;
        if ($iterator < $last) {
            $pivot = $iterator->seek($first->distance($last) / 2, SEEK_CUR);
            $pivot = $this->partition($collection, $first, $last, $pivot);
            
            $this->quickSort($collection, $first, (clone $pivot)->previous());
            $this->quickSort($collection, (clone $pivot)->next(), $last);
        }
    }

    private function compare(Iterator $left, Iterator $right)
    {
        return (bool) $left->current() <= $right->current();
    }

    private function partition(Sortable $collection, Iterator $first, Iterator $last, Iterator $pivot)
    {
        $collection->swap($last, $pivot);

        $tmp = $first;
        $iterator = $collection->getIterator();
        while ($iterator < $end) {
            if ($this->compare($iterator, $last)) {
                $collection->swap($iterator, $tmp);
                $tmp->next();
            }
        }
        $collection->swap($last, $tmp);

        return $tmp;
    }
}
```

## Interface `SeekableIterator`

This interface already exists, but needs some improvements to make possible and easy collection sorting.

### Constants

* `SEEK_SET` used to define a seeking position from the beginning of the iterable collection
* `SEEK_CUR` used to define a seeking position from the iterator's current position
* `SEEK_END` used to define a seeking position from the end of the iterable collection

### Method `distance`

Used to determine the distance between 2 iterators. The iterators *MUST* by the way iterate on the same collection.

* Parameter `$friend`, of type `SeekableIterator`
* Returns `integer`

### Method `seek`

Used to determine seek the iterator, this method already exists, but the prototypes changes

* Parameter `$position`, of type `integer`
* Parameter `$whence`, of type `integer`, between `SEEK_SET`, `SEEK_CUR` or `SEEK_END`
* Returns nothing

### Method `previous`

Seeks the iterator one position behind 

* Returns nothing

### Method `next`

Seeks the iterator one position ahead 

* Returns nothing

## Interface `Sortable`

This interface defines no method and cannot be directly implemented in user-space.

* Extends `Traversable`
* Extends `Countable`

## Class `Sorter`

This interface defines no method and cannot be directly implemented in user-space.

## Class `SortableCollection`

* Extends `Sortable`
* Extends `IteratorAggregate`

### Method `swap`

* Parameter `$leftKey` of type `SeekableIterator`
* Parameter `$rightKey` of type `SeekableIterator`
* Returns nothing

### Method `first`

* Takes no parameter
* Returns `SeekableIterator`, positioned to the first element

### Method `last`

* Takes no parameter
* Returns `SeekableIterator`, positioned to the last element

### Method `getIterator`

* Takes no parameter
* Returns `SeekableIterator`, positioned to the first element

## Class `CollectionSorter`

### Method `sort`

* Parameter `$collection` of type `SortableCollection`
* Returns nothing

## Class `SortableAggregate`

* Extends `Sortable`

### Method `sort`

* Parameter `$sorter` of type `Sorter`
* Returns nothing

## Class `SorterAggregate`

### Method `sort`

* Parameter `$collection` of type `SortableAggregate`
* Returns nothing