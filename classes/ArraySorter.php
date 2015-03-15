<?php

namespace Spl;

abstract class ArraySorter
    implements Sorter
{
    /**
     * @param SortableCollection $collection
     * @return SortableCollection
     */
    public function sort(SortableCollection $collection)
    {
        // TODO: Implement sort() method.
    }

    private function quickSort(
        SortableCollection $collection,
        BidirectionalSeekableIterator $first,
        BidirectionalSeekableIterator $last
    ) {
    }

    private function partition(
        SortableCollection $collection,
        BidirectionalSeekableIterator $first,
        BidirectionalSeekableIterator $last
    ) {
    }
}