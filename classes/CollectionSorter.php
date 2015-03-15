<?php

namespace Spl;


abstract class CollectionSorter
    implements Sorter
{
    final public function sort(SortableCollection $collection)
    {
        $this->quickSort($collection, $collection->first(), $collection->last());
    }

    final protected function quickSort(
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

    final protected function partition(
        SortableCollection $collection,
        BidirectionalSeekableIterator $first,
        BidirectionalSeekableIterator $last
    ) {
        $pivot = clone $first;
        $pivot->next(ceil($first->distance($last) / 2));

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