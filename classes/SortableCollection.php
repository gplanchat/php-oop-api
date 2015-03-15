<?php

namespace Spl;

interface SortableCollection
    extends \IteratorAggregate, Sortable, \Countable
{
    /**
     * @param BidirectionalSeekableIterator $leftKey
     * @param BidirectionalSeekableIterator $rightKey
     * @return void
     */
    public function swap(BidirectionalSeekableIterator $leftKey, BidirectionalSeekableIterator $rightKey);

    /**
     * @return BidirectionalSeekableIterator
     */
    public function first();

    /**
     * @return BidirectionalSeekableIterator
     */
    public function last();

    /**
     * @return BidirectionalSeekableIterator
     */
    public function getIterator();

    /**
     * @return array
     */
    public function keys();
}
