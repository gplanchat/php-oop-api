<?php

/**
 * Note: extends Iterator instead of SeekableIterator due to E_STRICT
 * thrown when a 2nd parameter is added to seek()
 */
interface BidirectionalSeekableIterator
    extends /* SeekableIterator*/ Iterator
{
    const SEEK_SET = 0;
    const SEEK_CUR = 1;
    const SEEK_END = 2;

    /**
     * @param BidirectionalSeekableIterator $friend
     * @return int
     */
    public function distance(BidirectionalSeekableIterator $friend);

    /**
     * @param int $position
     * @param int $whence
     * @return void
     */
    public function seek($position, $whence = BidirectionalSeekableIterator::SEEK_SET);

    /**
     * @return void
     */
    public function previous();

    /**
     * @return void
     */
    public function next();

    /**
     * @return integer
     */
    public function index();
}