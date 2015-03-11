<?php

interface Sorter
{
    /**
     * @param SortableCollection $collection
     * @return SortableCollection
     */
    public function sort(SortableCollection $collection);

    /**
     * @param BidirectionalSeekableIterator $left
     * @param BidirectionalSeekableIterator $right
     * @return bool
     */
    public function compare(
        BidirectionalSeekableIterator $left,
        BidirectionalSeekableIterator $right
    );
}